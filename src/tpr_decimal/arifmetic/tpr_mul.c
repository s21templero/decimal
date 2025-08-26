#include "tpr_arifmetic.h"

int tpr_mul(tpr_decimal value_1, tpr_decimal value_2, tpr_decimal *result) {
  int error = 0;
  if (result == NULL) {
    error = BIG;
  } else if (!tpr_correct_decimal(value_1) || !tpr_correct_decimal(value_2)) {
    error = BIG;
  } else {
    *result = tpr_decimal_set_zero();
    tpr_big_decimal temp_result = {{0}};
    tpr_decimal tmp = {{0}};
    tpr_decimal zero = {{0}};
    int sign1 = tpr_get_sign(value_1.bits[3]);
    int sign2 = tpr_get_sign(value_2.bits[3]);
    tpr_set_sign(&value_1.bits[3], 0);
    tpr_set_sign(&value_2.bits[3], 0);
    tpr_big_decimal temp_value_1 = tpr_decimal_to_big(&value_1);
    tpr_big_decimal temp_value_2 = tpr_decimal_to_big(&value_2);

    temp_result = tpr_mul_big_size(temp_value_1, temp_value_2);
    error = tpr_big_to_decimal(temp_result, &tmp);

    if (sign1 != sign2) {
      tpr_set_sign(&tmp.bits[3], 1);
    } else {
      tpr_set_sign(&tmp.bits[3], 0);
    }

    if (error == BIG) {
      if (tpr_get_sign(tmp.bits[3]) == 1) {
        error = SMALL;
      }
    }
    if (error == OK && tpr_is_not_equal(value_1, zero) &&
        tpr_is_not_equal(value_2, zero) && tpr_is_equal(tmp, zero)) {
      error = SMALL;
    }
    if (!error) {
      *result = tmp;
    }
  }
  return error;
}
tpr_big_decimal tpr_mul_big_size(tpr_big_decimal big_value_1,
                                 tpr_big_decimal big_value_2) {
  int pow1 = tpr_get_power(big_value_1.bits[7]);
  int pow2 = tpr_get_power(big_value_2.bits[7]);
  big_value_1.bits[7] = 0;
  big_value_2.bits[7] = 0;

  tpr_big_decimal temp_big_value_1 = big_value_1;
  tpr_big_decimal temp_big_value_2 = big_value_2;
  tpr_big_decimal temp_big_result = {{0}};

  for (int i = 0; i < MAX_BIG_BITS; i++) {
    if (tpr_big_decimal_get_bit(temp_big_value_1, i)) {
      temp_big_value_2 = tpr_get_big_move(temp_big_value_2, LEFT, i);
      temp_big_result = tpr_add_big_size(temp_big_value_2, temp_big_result);
    }
    temp_big_value_2 = big_value_2;
  }
  tpr_set_power(&temp_big_result.bits[7], pow1 + pow2);
  return temp_big_result;
}
