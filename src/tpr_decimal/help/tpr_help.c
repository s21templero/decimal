#include "tpr_help.h"

int tpr_get_bit(int number, int index) { return !!(number & (1U << index)); }
int tpr_set_bit(int number, int index) { return number | (1U << index); }
int tpr_reset_bit(int number, int index) { return number & ~(1U << index); }
tpr_decimal tpr_decimal_set_zero(void) {
  tpr_decimal temp;
  temp.bits[0] = 0;
  temp.bits[1] = 0;
  temp.bits[2] = 0;
  temp.bits[3] = 0;
  return temp;
}

int tpr_correct_decimal(tpr_decimal value) {
  int error = 1;

  decimal_bit3 bits3;
  bits3.i = value.bits[3];

  if (bits3.parts.part1 != 0 || bits3.parts.part2 != 0) {
    error = 0;
  }
  if (bits3.parts.power > 28) {
    error = 0;
  }
  return error;
}
int tpr_correct_big_decimal(tpr_big_decimal value) {
  int error = 1;

  decimal_bit3 bits3;
  bits3.i = value.bits[7];

  if (bits3.parts.part1 != 0 || bits3.parts.part2 != 0) {
    error = 0;
  }
  if (bits3.parts.power > 28) {
    error = 0;
  }
  return error;
}
int tpr_get_sign(int value) {
  decimal_bit3 bits3;
  bits3.i = value;
  return bits3.parts.sign;
}
void tpr_set_sign(int *value, int sign) {
  decimal_bit3 bits3;
  bits3.i = *value;
  bits3.parts.sign = sign;
  *value = bits3.i;
}
tpr_big_decimal tpr_decimal_to_big(tpr_decimal *value) {
  tpr_big_decimal big_value = {{0}};
  for (int i = 0; i < 3; i++) {
    big_value.bits[i] = value->bits[i];
  }
  big_value.bits[7] = value->bits[3];
  return big_value;
}
int tpr_big_to_decimal(tpr_big_decimal big_value_1, tpr_decimal *value_2) {
  int error = OK;
  tpr_decimal temp_result = {{0}};
  tpr_big_decimal big_ten = {{10, 0, 0, 0, 0, 0, 0, 0}};
  tpr_big_decimal remainder = {{0}};
  int power = tpr_get_power(big_value_1.bits[7]);
  tpr_set_power(&big_value_1.bits[7], 0);
  if (big_value_1.bits[3] != 0 || big_value_1.bits[4] != 0 ||
      big_value_1.bits[5] != 0 || big_value_1.bits[6] != 0) {
    if (power == 0) {
      error = BIG;
    } else {
      while (power > 0) {
        big_value_1 = tpr_div_big_size(big_value_1, big_ten, &remainder);
        if (big_value_1.bits[3] == 0 && big_value_1.bits[4] == 0 &&
            big_value_1.bits[5] == 0 && big_value_1.bits[6] == 0) {
          power--;
          break;
        } else {
          power--;
        }
      }
    }
    if (big_value_1.bits[3] != 0 || big_value_1.bits[4] != 0 ||
        big_value_1.bits[5] != 0 || big_value_1.bits[6] != 0) {
      error = BIG;
    }
  }
  if (power > 28) {
    while (power > 28) {
      big_value_1 = tpr_div_big_size(big_value_1, big_ten, &remainder);
      if (big_value_1.bits[0] == 0 && big_value_1.bits[1] == 0 &&
          big_value_1.bits[2] == 0) {
        error = SMALL;
        power--;
        break;
      } else {
        power--;
      }
    }
  }
  if (!error) {
    tpr_set_power(&big_value_1.bits[7], power);
    big_value_1 = tpr_big_round_bank(big_value_1, remainder);
    for (int i = 0; i < 3; i++) {
      temp_result.bits[i] = big_value_1.bits[i];
    }
    temp_result.bits[3] = big_value_1.bits[7];
    *value_2 = temp_result;
  }
  return error;
}
void tpr_set_power(int *number, int power) {
  decimal_bit3 bits3 = {0};
  bits3.i = *number;
  bits3.parts.power = power;
  *number = bits3.i;
}
int tpr_get_power(int number) {
  decimal_bit3 bits3 = {0};
  bits3.i = number;
  int power = bits3.parts.power;
  return power;
}
int tpr_get_big_high_unit(tpr_big_decimal value) {
  int result = -1;
  for (int i = MAX_BIG_BITS - 1; i >= 0; i--) {
    if (tpr_big_decimal_get_bit(value, i)) {
      result = i;
      break;
    }
  }
  return result;
}
int tpr_big_decimal_get_bit(tpr_big_decimal big_value, int index) {
  return tpr_get_bit(big_value.bits[index / MAX_BLOCK_BITS],
                     index % MAX_BLOCK_BITS);
}
tpr_big_decimal tpr_big_decimal_set_bit(tpr_big_decimal value, int index) {
  value.bits[index / MAX_BLOCK_BITS] =
      tpr_set_bit(value.bits[index / MAX_BLOCK_BITS], index % MAX_BLOCK_BITS);
  return value;
}
tpr_big_decimal tpr_big_round_bank(tpr_big_decimal value_1,
                                   tpr_big_decimal value_2) {
  tpr_big_decimal five = {{5, 0, 0, 0, 0, 0, 0, 0}};
  tpr_big_decimal temp_result = {{0}};
  tpr_big_decimal big_one = {{1, 0, 0, 0, 0, 0, 0, 0}};
  tpr_big_decimal big_ten = {{10, 0, 0, 0, 0, 0, 0, 0}};
  int power = tpr_get_power(value_1.bits[7]);
  tpr_set_power(&value_1.bits[7], 0);
  if (!tpr_big_is_less(value_2, big_ten)) {
    while (!tpr_big_is_less(value_2, big_ten)) {
      value_2 = tpr_div_big_size(value_2, big_ten, NULL);
    }
  }

  if (tpr_big_is_equal(value_2, five)) {
    if (tpr_big_parity(value_1)) {
      temp_result = value_1;
    } else {
      temp_result = tpr_add_big_size(value_1, big_one);
    }
  } else if (tpr_big_is_greater(value_2, five)) {
    temp_result = tpr_add_big_size(value_1, big_one);
  } else {
    temp_result = value_1;
  }
  tpr_set_power(&temp_result.bits[7], power);
  return temp_result;
}
tpr_big_decimal tpr_big_rem_zero(tpr_big_decimal big_value) {
  int power = tpr_get_power(big_value.bits[7]);
  int sign = tpr_get_sign(big_value.bits[7]);
  tpr_big_decimal temp_result = big_value;
  tpr_big_decimal temp = big_value;
  tpr_big_decimal ten = {{10, 0, 0, 0, 0, 0, 0, 0}};
  tpr_big_decimal zero = {{0}};

  if (power > 0 && tpr_correct_big_decimal(temp)) {
    tpr_big_decimal remainder = {{0}};
    tpr_big_decimal temp = big_value;
    temp.bits[7] = 0;

    while (power > 0) {
      temp = tpr_div_big_size(temp, ten, &remainder);
      if (tpr_big_is_equal(remainder, zero)) {
        --power;
        temp_result = temp;
      } else {
        break;
      }
    }
    tpr_set_power(&temp_result.bits[7], power);
    tpr_set_sign(&temp_result.bits[7], sign);
  }
  return temp_result;
}
int tpr_big_level(tpr_big_decimal *big_value_1, tpr_big_decimal *big_value_2) {
  int error = OK;
  tpr_big_decimal tmp_value_1 = *big_value_1;
  tpr_big_decimal tmp_value_2 = *big_value_2;
  tpr_big_decimal ten = {{10, 0, 0, 0, 0, 0, 0, 0}};
  int pow1 = tpr_get_power(tmp_value_1.bits[7]);
  int pow2 = tpr_get_power(tmp_value_2.bits[7]);
  tmp_value_1.bits[7] = 0;
  tmp_value_2.bits[7] = 0;
  int res_power = pow1 >= pow2 ? pow1 : pow2;
  if (pow1 > pow2) {
    for (int i = 1; i <= pow1 - pow2; i++) {
      tmp_value_2 = tpr_mul_big_size(tmp_value_2, ten);
    }
  } else if (pow2 > pow1) {
    for (int i = 1; i <= pow2 - pow1; i++) {
      tmp_value_1 = tpr_mul_big_size(tmp_value_1, ten);
    }
  }
  tpr_set_power(&tmp_value_1.bits[7], res_power);
  tpr_set_power(&tmp_value_2.bits[7], res_power);
  *big_value_1 = tmp_value_1;
  *big_value_2 = tmp_value_2;
  return error;
}
tpr_big_decimal tpr_get_big_move(tpr_big_decimal big_value, int vector,
                                 int index) {
  tpr_big_decimal temp_big_value = big_value;
  while (index > 0) {
    if (vector == LEFT) {
      temp_big_value = tpr_big_move_left_one(temp_big_value);
    } else if (vector == RIGTH) {
      temp_big_value = tpr_big_move_rigth_one(temp_big_value);
    }
    index--;
  }
  temp_big_value.bits[7] = big_value.bits[7];
  return temp_big_value;
}
tpr_big_decimal tpr_big_move_left_one(tpr_big_decimal big_value) {
  tpr_big_decimal temp_result = {{0}};

  int a0 = tpr_get_bit(big_value.bits[0], MAX_BLOCK_BITS - 1);
  int a1 = tpr_get_bit(big_value.bits[1], MAX_BLOCK_BITS - 1);
  int a2 = tpr_get_bit(big_value.bits[2], MAX_BLOCK_BITS - 1);
  int a3 = tpr_get_bit(big_value.bits[3], MAX_BLOCK_BITS - 1);
  int a4 = tpr_get_bit(big_value.bits[4], MAX_BLOCK_BITS - 1);
  int a5 = tpr_get_bit(big_value.bits[5], MAX_BLOCK_BITS - 1);
  int a6 = tpr_get_bit(big_value.bits[6], MAX_BLOCK_BITS - 1);

  for (int i = 0; i < 7; i++) {
    unsigned int res = big_value.bits[i];  // unsigned
    res = res << 1;
    temp_result.bits[i] = res;
  }

  if (a0) {
    temp_result.bits[1] = tpr_set_bit(temp_result.bits[1], 0);
  }
  if (a1) {
    temp_result.bits[2] = tpr_set_bit(temp_result.bits[2], 0);
  }
  if (a2) {
    temp_result.bits[3] = tpr_set_bit(temp_result.bits[3], 0);
  }
  if (a3) {
    temp_result.bits[4] = tpr_set_bit(temp_result.bits[4], 0);
  }
  if (a4) {
    temp_result.bits[5] = tpr_set_bit(temp_result.bits[5], 0);
  }
  if (a5) {
    temp_result.bits[6] = tpr_set_bit(temp_result.bits[6], 0);
  }
  if (a6) {
  }
  return temp_result;
}
tpr_big_decimal tpr_big_move_rigth_one(tpr_big_decimal big_value) {
  tpr_big_decimal temp_result = {{0}};

  int a0 = tpr_get_bit(big_value.bits[0], 0);
  int a1 = tpr_get_bit(big_value.bits[1], 0);
  int a2 = tpr_get_bit(big_value.bits[2], 0);
  int a3 = tpr_get_bit(big_value.bits[3], 0);
  int a4 = tpr_get_bit(big_value.bits[4], 0);
  int a5 = tpr_get_bit(big_value.bits[5], 0);
  int a6 = tpr_get_bit(big_value.bits[6], 0);

  for (int i = 6; i >= 0; i--) {
    unsigned int res = big_value.bits[i];
    res = res >> 1;
    temp_result.bits[i] = res;
  }

  if (a0) {
  }
  if (a1) {
    temp_result.bits[0] = tpr_set_bit(temp_result.bits[0], MAX_BLOCK_BITS - 1);
  }
  if (a2) {
    temp_result.bits[1] = tpr_set_bit(temp_result.bits[1], MAX_BLOCK_BITS - 1);
  }
  if (a3) {
    temp_result.bits[2] = tpr_set_bit(temp_result.bits[2], MAX_BLOCK_BITS - 1);
  }
  if (a4) {
    temp_result.bits[3] = tpr_set_bit(temp_result.bits[3], MAX_BLOCK_BITS - 1);
  }
  if (a5) {
    temp_result.bits[4] = tpr_set_bit(temp_result.bits[4], MAX_BLOCK_BITS - 1);
  }
  if (a6) {
    temp_result.bits[5] = tpr_set_bit(temp_result.bits[5], MAX_BLOCK_BITS - 1);
  }
  return temp_result;
}
int tpr_big_parity(tpr_big_decimal big_value) {
  return (big_value.bits[0] & 1) != 1;
}
int tpr_big_is_equal(tpr_big_decimal value_1, tpr_big_decimal value_2) {
  int cod = 1;

  tpr_big_decimal temp1 = tpr_big_rem_zero(value_1);
  tpr_big_decimal temp2 = tpr_big_rem_zero(value_2);

  if (temp1.bits[0] == 0 && temp1.bits[1] == 0 && temp1.bits[2] == 0 &&
      temp1.bits[3] == 0 && temp1.bits[4] == 0 && temp1.bits[5] == 0 &&
      temp1.bits[6] == 0 && temp2.bits[0] == 0 && temp2.bits[1] == 0 &&
      temp2.bits[2] == 0 && temp2.bits[3] == 0 && temp2.bits[4] == 0 &&
      temp2.bits[5] == 0 && temp2.bits[6] == 0) {
    cod = 1;
  } else {
    if (temp1.bits[0] == temp2.bits[0] && temp1.bits[1] == temp2.bits[1] &&
        temp1.bits[2] == temp2.bits[2] && temp1.bits[3] == temp2.bits[3] &&
        temp1.bits[4] == temp2.bits[4] && temp1.bits[5] == temp2.bits[5] &&
        temp1.bits[6] == temp2.bits[6]) {
      cod = 1;
    } else {
      cod = 0;
    }
  }
  return cod;
}
int tpr_big_decimal_compare(tpr_big_decimal big_value_1,
                            tpr_big_decimal big_value_2) {
  int result = 0;

  for (int i = MAX_BIG_BITS - 1; i >= 0; i--) {
    int val_1 = tpr_big_decimal_get_bit(big_value_1, i);
    int val_2 = tpr_big_decimal_get_bit(big_value_2, i);

    if (val_1 == 0 && val_2 != 0) {
      result = -1;
    }

    if (val_1 != 0 && val_2 == 0) {
      result = 1;
    }

    if (result != 0) {
      break;
    }
  }

  return result;
}
int tpr_big_is_greater(tpr_big_decimal big_value_1,
                       tpr_big_decimal big_value_2) {
  return tpr_big_is_less(big_value_2, big_value_1);
}
int tpr_big_is_less(tpr_big_decimal big_value_1, tpr_big_decimal big_value_2) {
  int code = 0;
  int res = 0;
  int sign1 = tpr_get_sign(big_value_1.bits[7]);
  int sign2 = tpr_get_sign(big_value_2.bits[7]);
  tpr_big_decimal zero = {{0}};
  tpr_big_decimal temp_value_1 = big_value_1;
  tpr_big_decimal temp_value_2 = big_value_2;

  if (tpr_big_is_equal(big_value_1, zero) &&
      tpr_big_is_equal(big_value_2, zero)) {
    code = 0;
  } else if (sign1 == 1 && sign2 == 0) {
    code = 1;
  } else if (sign1 == 0 && sign2 == 1) {
    code = 0;
  } else if (sign1 == 1 && sign2 == 1) {
    if (sign1) {
      tpr_set_sign(&temp_value_1.bits[7], 0);
    } else {
      tpr_set_sign(&temp_value_1.bits[7], 1);
    }
    if (sign2) {
      tpr_set_sign(&temp_value_2.bits[7], 0);
    } else {
      tpr_set_sign(&temp_value_2.bits[7], 1);
    }
    tpr_big_level(&temp_value_1, &temp_value_2);
    res = tpr_big_decimal_compare(temp_value_1, temp_value_2);
    if (res == -1) {
      code = 1;
    } else {
      code = 0;
    }
  } else {
    tpr_big_level(&temp_value_1, &temp_value_2);
    res = tpr_big_decimal_compare(temp_value_1, temp_value_2);
    if (res == -1) {
      code = 1;
    } else {
      code = 0;
    }
  }
  return code;
}

int tpr_big_is_greater_or_equal(tpr_big_decimal big_value_1,
                                tpr_big_decimal big_value_2) {
  return (tpr_big_is_greater(big_value_1, big_value_2) ||
          tpr_big_is_equal(big_value_1, big_value_2));
}