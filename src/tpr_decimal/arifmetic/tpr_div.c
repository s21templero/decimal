#include "tpr_arifmetic.h"

int tpr_div(tpr_decimal value_1, tpr_decimal value_2, tpr_decimal *result) {
  int error = OK;
  tpr_decimal zero = {{0}};
  tpr_decimal temp_result1 = {{0}};

  if (result == NULL) {
    error = BIG;
  } else if ((!tpr_correct_decimal(value_1)) ||
             (!tpr_correct_decimal(value_2))) {
    error = BIG;
  } else if (tpr_is_equal(value_2, zero)) {
    error = ZERO_DIV;
  } else {
    result->bits[0] = result->bits[1] = result->bits[2] = result->bits[3] = 0;
    int sign1 = tpr_get_sign(value_1.bits[3]);
    int sign2 = tpr_get_sign(value_2.bits[3]);
    tpr_set_sign(&value_1.bits[3], 0);
    tpr_set_sign(&value_2.bits[3], 0);

    tpr_big_decimal big_value_1 = tpr_decimal_to_big(&value_1);
    tpr_big_decimal big_value_2 = tpr_decimal_to_big(&value_2);
    tpr_big_decimal remainder = {{0}};
    tpr_big_decimal temp_result = {{0}};
    tpr_big_decimal big_zero = {{0}};

    tpr_big_level(&big_value_1, &big_value_2);

    temp_result = tpr_div_big_size(big_value_1, big_value_2, &remainder);
    if (temp_result.bits[3] != 0 || temp_result.bits[4] != 0 ||
        temp_result.bits[5] != 0 || temp_result.bits[6] != 0) {
      if (sign1 != sign2) {
        error = SMALL;
      } else {
        error = BIG;
      }
    } else {
      if (!tpr_big_is_equal(remainder, big_zero)) {
        temp_result =
            tpr_more_div_big_size(big_value_2, temp_result, remainder);
        if (temp_result.bits[0] == 0 && temp_result.bits[1] == 0 &&
            temp_result.bits[2] == 0 && temp_result.bits[3] == 0 &&
            temp_result.bits[4] == 0 && temp_result.bits[5] == 0 &&
            temp_result.bits[6] == 0) {
          temp_result.bits[7] = 0;
        }
      }
      error = tpr_big_to_decimal(temp_result, &temp_result1);
      if (!error) {
        *result = temp_result1;
        if (sign1 != sign2) {
          tpr_set_sign(&result->bits[3], 1);
        }
      }
      if (error == BIG && (tpr_get_sign(temp_result1.bits[3]) == 1)) {
        error = SMALL;
      }
    }
  }
  return error;
}
tpr_big_decimal tpr_div_big_size(tpr_big_decimal big_value_1,
                                 tpr_big_decimal big_value_2,
                                 tpr_big_decimal *remainder) {
  tpr_big_decimal temp_result = {{0}};
  tpr_big_decimal temp_remainder = {{0}};
  tpr_big_decimal temp_quotient = {{0}};
  tpr_big_decimal temp_mov_divisor = {{0}};
  tpr_big_decimal temp_div = big_value_1;
  tpr_big_decimal big_zero = {{0}};
  tpr_big_decimal big_one = {{1, 0, 0, 0, 0, 0, 0, 0}};
  int flag_sub = 1;

  if (tpr_big_is_equal(big_value_1, big_zero)) {
  } else if (tpr_big_is_less(big_value_1, big_value_2) == 1) {
    temp_remainder = big_value_1;
  } else if (tpr_big_is_equal(big_value_2, big_one)) {
    temp_quotient = big_value_1;
  } else {
    int move1 = tpr_get_big_high_unit(big_value_1);
    int move2 = tpr_get_big_high_unit(big_value_2);
    int move_res = move1 - move2;
    temp_mov_divisor = tpr_get_big_move(big_value_2, LEFT, move_res);
    while (move_res >= 0) {
      if (flag_sub == 1) {
        if (tpr_big_is_greater_or_equal(temp_div, temp_mov_divisor)) {
          temp_remainder = tpr_sub_big_size(temp_div, temp_mov_divisor);
        } else {
          temp_remainder = tpr_sub_big_size(temp_mov_divisor, temp_div);
          tpr_set_sign(&temp_remainder.bits[7], 1);
        }
      } else {
        tpr_set_sign(&temp_div.bits[7], 0);
        if (tpr_big_is_greater_or_equal(temp_mov_divisor, temp_div)) {
          temp_remainder = tpr_sub_big_size(temp_mov_divisor, temp_div);
        } else {
          temp_remainder = tpr_sub_big_size(temp_div, temp_mov_divisor);
          tpr_set_sign(&temp_remainder.bits[7], 1);
        }
      }
      temp_quotient = tpr_get_big_move(temp_quotient, LEFT, 1);
      if (tpr_get_sign(temp_remainder.bits[7]) == 0) {
        flag_sub = 1;
        temp_quotient = tpr_big_decimal_set_bit(temp_quotient, 0);
      } else {
        flag_sub = 0;
      }
      temp_div = tpr_get_big_move(temp_remainder, LEFT, 1);
      --move_res;
    }
    if (tpr_get_sign(temp_remainder.bits[7])) {
      if (tpr_big_is_greater_or_equal(temp_mov_divisor, temp_remainder)) {
        temp_remainder = tpr_sub_big_size(temp_mov_divisor, temp_remainder);
      } else {
        temp_remainder = tpr_sub_big_size(temp_remainder, temp_mov_divisor);
        tpr_set_sign(&temp_remainder.bits[7], 1);
      }
    }
    temp_remainder = tpr_get_big_move(temp_remainder, RIGTH, move1 - move2);
  }
  tpr_set_sign(&temp_remainder.bits[7], 0);
  temp_result = temp_quotient;
  if (remainder != NULL) {
    *remainder = temp_remainder;
  }
  return temp_result;
}
tpr_big_decimal tpr_more_div_big_size(tpr_big_decimal value_1,
                                      tpr_big_decimal temp_result,
                                      tpr_big_decimal remainder) {
  int pow1 = 0, pow2 = 0;
  tpr_big_decimal tmp_res = {{0}};
  tpr_big_decimal zero_point_five = {{5, 0, 0, 0, 0, 0, 0, 0}};
  tpr_set_power(&zero_point_five.bits[7], 1);
  tpr_big_decimal big_zero = {{0}};
  tpr_big_decimal min_value = {{1, 0, 0, 0, 0, 0, 0, 0}};
  tpr_set_power(&min_value.bits[7], 28);

  pow1 = tpr_calc_frac(&temp_result, value_1, &remainder);
  pow2 = tpr_calc_frac(&tmp_res, value_1, &remainder);

  tpr_set_power(&tmp_res.bits[7], pow2);

  if (tpr_big_is_equal(tmp_res, zero_point_five)) {
    if (tpr_big_is_equal(remainder, big_zero)) {
      tmp_res = tpr_add_big_size(tmp_res, min_value);
    }
  }
  temp_result = tpr_big_round_bank(temp_result, tmp_res);
  tpr_set_power(&temp_result.bits[7], pow1);

  return temp_result;
}
int tpr_calc_frac(tpr_big_decimal *big_result, tpr_big_decimal value_2,
                  tpr_big_decimal *remainder) {
  int power1 = 0;
  tpr_big_decimal temp_res = *big_result;
  tpr_big_decimal temp_value = {{0}};
  tpr_big_decimal temp_remainder = *remainder;
  tpr_big_decimal big_ten = {{10, 0, 0, 0, 0, 0, 0, 0}};
  tpr_big_decimal big_zero = {{0}};

  while (!tpr_big_is_equal(temp_remainder, big_zero) && power1 < 28) {
    tpr_big_decimal temp_number = temp_res;
    tpr_big_decimal temp_rem = temp_remainder;

    temp_res = tpr_mul_big_size(temp_res, big_ten);
    temp_remainder = tpr_mul_big_size(temp_remainder, big_ten);
    temp_value = tpr_div_big_size(temp_remainder, value_2, &temp_remainder);
    temp_res = tpr_add_big_size(temp_res, temp_value);

    if (!tpr_correct_big_decimal(temp_res)) {
      temp_res = temp_number;
      temp_remainder = temp_rem;
      break;
    }
    ++power1;
  }
  *big_result = temp_res;
  *remainder = temp_remainder;
  return power1;
}