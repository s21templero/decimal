#include "tpr_other.h"

int tpr_floor(tpr_decimal value, tpr_decimal *result) {
  int error = OK;
  if (result == NULL || !tpr_correct_decimal(value)) {
    error = CALCULATION_ERROR;
  } else {
    tpr_decimal whole_part = {{0}};
    tpr_decimal fractional_part = {{0}};
    tpr_decimal zero_number = {{0}};
    tpr_decimal one_number = {{1, 0, 0, 0}};

    *result = tpr_decimal_set_zero();
    int sign = tpr_get_sign(value.bits[3]);
    tpr_set_sign(&value.bits[3], 0);
    tpr_truncate(value, &whole_part);
    error = tpr_sub(value, whole_part, &fractional_part);
    if (sign && tpr_is_greater(fractional_part, zero_number) && !error) {
      error = tpr_add(whole_part, one_number, &whole_part);
    }
    if (!error) {
      tpr_set_sign(&whole_part.bits[3], sign);
      *result = whole_part;
    } else {
      error = CALCULATION_ERROR;
    }
  }
  return error;
}

int tpr_round(tpr_decimal value, tpr_decimal *result) {
  if (result == NULL || !tpr_correct_decimal(value)) {
    return CALCULATION_ERROR;
  }

  tpr_decimal whole_part = {{0}};
  tpr_decimal fractional_part = {{0}};
  tpr_decimal half_number = {{0}};
  tpr_decimal one_number = {{0}};

  one_number.bits[0] = 1;
  half_number.bits[0] = 5;
  tpr_set_power(&half_number.bits[3], 1);
  tpr_truncate(value, &whole_part);
  tpr_sub(value, whole_part, &fractional_part);
  if (value.bits[3] >> 31) {
    tpr_negate(fractional_part, &fractional_part);
    if (tpr_is_greater_or_equal(fractional_part, half_number)) {
      tpr_sub(whole_part, one_number, &whole_part);
    }
  } else {
    if (tpr_is_greater_or_equal(fractional_part, half_number)) {
      tpr_add(whole_part, one_number, &whole_part);
    }
  }
  *result = whole_part;
  return OK;
}

int tpr_truncate(tpr_decimal value, tpr_decimal *result) {
  int error = OK;
  int sign = 0;
  if (result == NULL || !tpr_correct_decimal(value)) {
    error = CALCULATION_ERROR;
  } else {
    int pow_number = 0;
    tpr_decimal t_var = {{0}};
    tpr_big_decimal ten_number = {{10, 0, 0, 0}};
    sign = tpr_get_sign(value.bits[3]);
    tpr_set_sign(&value.bits[3], 0);

    pow_number = tpr_get_power(value.bits[3]);
    tpr_set_power(&value.bits[3], 0);
    tpr_big_decimal big_value = tpr_decimal_to_big(&value);
    while (pow_number > 0) {
      big_value = tpr_div_big_size(big_value, ten_number, NULL);
      pow_number--;
    }
    error = tpr_big_to_decimal(big_value, &t_var);
    if (sign == 1) {
      tpr_negate(t_var, &t_var);
    }
    if (!error) {
      *result = t_var;
    }
  }
  return error;
}

int tpr_negate(tpr_decimal value, tpr_decimal *result) {
  if (result == NULL || !tpr_correct_decimal(value)) {
    return CALCULATION_ERROR;
  }
  value.bits[3] ^= 1 << 31;
  *result = value;
  return OK;
}
