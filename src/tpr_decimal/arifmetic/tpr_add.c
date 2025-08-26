#include "tpr_arifmetic.h"

int tpr_add(tpr_decimal value_1, tpr_decimal value_2, tpr_decimal *result) {
  int error = OK;
  tpr_decimal temp_result = {{0}};
  tpr_big_decimal temp_value_1 = tpr_decimal_to_big(&value_1);
  tpr_big_decimal temp_value_2 = tpr_decimal_to_big(&value_2);
  tpr_big_decimal temp_big_result = {{0}};
  int sign1 = 0;

  int sign2 = 0;

  if (result == NULL) {
    error = BIG;
  } else if ((!tpr_correct_decimal(value_1)) ||
             (!tpr_correct_decimal(value_2))) {
    error = BIG;
  } else {
    *result = tpr_decimal_set_zero();
    sign1 = tpr_get_sign(value_1.bits[3]);
    sign2 = tpr_get_sign(value_2.bits[3]);
    tpr_set_sign(&value_1.bits[3], 0);
    tpr_set_sign(&value_2.bits[3], 0);
    if (sign1 == 0 && sign2 == 0) {
      temp_big_result = tpr_add_big_size(temp_value_1, temp_value_2);
      error = tpr_big_to_decimal(temp_big_result, &temp_result);
    } else if (sign1 == 0 && sign2 == 1) {
      if (tpr_is_greater_or_equal(value_1, value_2)) {
        temp_big_result = tpr_sub_big_size(temp_value_1, temp_value_2);
        error = tpr_big_to_decimal(temp_big_result, &temp_result);
      } else {
        temp_big_result = tpr_sub_big_size(temp_value_2, temp_value_1);
        error = tpr_big_to_decimal(temp_big_result, &temp_result);
        tpr_negate(temp_result, &temp_result);
      }
    } else if (sign1 == 1 && sign2 == 0) {
      if (tpr_is_greater_or_equal(value_1, value_2)) {
        temp_big_result = tpr_sub_big_size(temp_value_1, temp_value_2);
        error = tpr_big_to_decimal(temp_big_result, &temp_result);
        tpr_negate(temp_result, &temp_result);
      } else {
        temp_big_result = tpr_sub_big_size(temp_value_2, temp_value_1);
        error = tpr_big_to_decimal(temp_big_result, &temp_result);
      }
    } else if (sign1 == 1 && sign2 == 1) {
      temp_big_result = tpr_add_big_size(temp_value_1, temp_value_2);
      error = tpr_big_to_decimal(temp_big_result, &temp_result);
      tpr_negate(temp_result, &temp_result);
    }
    if (tpr_get_sign(temp_result.bits[3]) && error == BIG) {
      error = SMALL;
    }
    if (!error) {
      *result = temp_result;
    }
  }
  return error;
}

tpr_big_decimal tpr_add_big_size(tpr_big_decimal big_value_1,
                                 tpr_big_decimal big_value_2) {
  tpr_big_decimal temp_result = {{0}};
  int pow1 = 0, pow2 = 0, res_pow = 0;
  int tmp_bit = 0;

  pow1 = tpr_get_power(big_value_1.bits[7]);
  pow2 = tpr_get_power(big_value_2.bits[7]);
  res_pow = pow1;
  if (pow2 > pow1) {
    res_pow = pow2;
  }
  tpr_big_level(&big_value_1, &big_value_2);

  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 32; j++) {
      int sum_bit = tpr_get_bit(big_value_1.bits[i], j) +
                    tpr_get_bit(big_value_2.bits[i], j);
      if (sum_bit + tmp_bit == 0) {
        temp_result.bits[i] = tpr_reset_bit(temp_result.bits[i], j);
        tmp_bit = 0;
      } else if (sum_bit + tmp_bit == 1) {
        temp_result.bits[i] = tpr_set_bit(temp_result.bits[i], j);
        tmp_bit = 0;
      } else if (sum_bit + tmp_bit == 2) {
        temp_result.bits[i] = tpr_reset_bit(temp_result.bits[i], j);
        tmp_bit = 1;
      } else if (sum_bit + tmp_bit == 3) {
        temp_result.bits[i] = tpr_set_bit(temp_result.bits[i], j);
        tmp_bit = 1;
      }
    }
  }
  tpr_set_power(&temp_result.bits[7], res_pow);

  return temp_result;
}
