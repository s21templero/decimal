#include "tpr_arifmetic.h"

int tpr_sub(tpr_decimal value_1, tpr_decimal value_2, tpr_decimal *result) {
  int error = OK;
  tpr_decimal temp_result = {{0}};
  tpr_big_decimal temp_value_1 = {{0}};
  tpr_big_decimal temp_value_2 = {{0}};
  tpr_big_decimal temp_big_result = {{0}};
  int sign1 = 0, sign2 = 0;

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
    temp_value_1 = tpr_decimal_to_big(&value_1);
    temp_value_2 = tpr_decimal_to_big(&value_2);
    if (sign1 == 0 && sign2 == 0) {
      if (tpr_is_greater_or_equal(value_1, value_2)) {
        temp_big_result = tpr_sub_big_size(temp_value_1, temp_value_2);
        error = tpr_big_to_decimal(temp_big_result, &temp_result);
      } else {
        temp_big_result = tpr_sub_big_size(temp_value_2, temp_value_1);
        error = tpr_big_to_decimal(temp_big_result, &temp_result);
        tpr_negate(temp_result, &temp_result);
      }
    } else if (sign1 == 1 && sign2 == 0) {
      temp_big_result = tpr_add_big_size(temp_value_1, temp_value_2);
      error = tpr_big_to_decimal(temp_big_result, &temp_result);
      tpr_negate(temp_result, &temp_result);
    } else if (sign1 == 0 && sign2 == 1) {
      temp_big_result = tpr_add_big_size(temp_value_1, temp_value_2);
      error = tpr_big_to_decimal(temp_big_result, &temp_result);
    } else if (sign1 == 1 && sign2 == 1) {
      if (tpr_big_is_greater_or_equal(temp_value_1,
                                      temp_value_2)) {
        temp_big_result = tpr_sub_big_size(temp_value_1, temp_value_2);
        error = tpr_big_to_decimal(temp_big_result, &temp_result);
        tpr_negate(temp_result, &temp_result);
      } else {
        temp_big_result = tpr_sub_big_size(temp_value_2, temp_value_1);
        error = tpr_big_to_decimal(temp_big_result, &temp_result);
      }
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

tpr_big_decimal tpr_sub_big_size(tpr_big_decimal big_value_1,
                                 tpr_big_decimal big_value_2) {
  tpr_big_decimal temp_result = {{0}};
  int loan = 0, sub_bit = 0;
  tpr_big_level(&big_value_1, &big_value_2);

  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 32; j++) {
      sub_bit = tpr_get_bit(big_value_1.bits[i], j) -
                tpr_get_bit(big_value_2.bits[i], j) - loan;
      if (sub_bit < 0) {
        loan = 1;
      } else {
        loan = 0;
      }
      if (sub_bit % 2) {
        temp_result.bits[i] = tpr_set_bit(temp_result.bits[i], j);
      } else {
        temp_result.bits[i] = tpr_reset_bit(temp_result.bits[i], j);
      }
    }
  }
  temp_result.bits[7] = big_value_1.bits[7];
  return temp_result;
}
