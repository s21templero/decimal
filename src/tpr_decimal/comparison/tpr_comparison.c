#include "tpr_comparison.h"

int tpr_is_less(tpr_decimal num1, tpr_decimal num2) {
  int res = FALSE;
  int sign_1 = tpr_get_sign(num1.bits[3]);
  int sign_2 = tpr_get_sign(num2.bits[3]);
  Normalize(&num1, &num2);
  if (num1.bits[0] == 0 && num1.bits[1] == 0 && num1.bits[2] == 0 &&
      num2.bits[0] == 0 && num2.bits[1] == 0 && num2.bits[2] == 0) {
    res = FALSE;
  } else if (sign_1 == NEGATIVE && sign_2 == POSITIVE) {
    res = TRUE;
  } else if (sign_1 == POSITIVE && sign_2 == NEGATIVE) {
    res = FALSE;
  } else if (sign_1 == NEGATIVE && sign_2 == NEGATIVE) {
    tpr_set_sign(&num1.bits[3], POSITIVE);
    tpr_set_sign(&num2.bits[3], POSITIVE);

    for (int i = MAX_HIGHT_BIT; i >= 0; i--) {
      if (tpr_decimal_get_bit(num2, i) ^ tpr_decimal_get_bit(num1, i)) {
        res = tpr_decimal_get_bit(num1, i);
        break;
      }
    }
  } else {
    for (int i = MAX_HIGHT_BIT; i >= 0; i--) {
      if (tpr_decimal_get_bit(num1, i) ^ tpr_decimal_get_bit(num2, i)) {
        res = tpr_decimal_get_bit(num2, i);
        break;
      }
    }
  }
  return res;
}

int tpr_is_equal(tpr_decimal num1, tpr_decimal num2) {
  int res = TRUE;
  if (num1.bits[0] == 0 && num1.bits[1] == 0 && num1.bits[2] == 0 &&
      num2.bits[0] == 0 && num2.bits[1] == 0 && num2.bits[2] == 0) {
    res = TRUE;
  } else {
    Normalize(&num1, &num2);
    for (int i = MAX_HIGHT_BIT; i >= 0; i--) {
      if (tpr_decimal_get_bit(num1, i) != tpr_decimal_get_bit(num2, i)) {
        res = FALSE;
        break;
      }
    }
  }
  return res;
}

int tpr_is_less_or_equal(tpr_decimal num1, tpr_decimal num2) {
  return tpr_is_equal(num1, num2) || tpr_is_less(num1, num2);
}

int tpr_is_greater(tpr_decimal num1, tpr_decimal num2) {
  return !tpr_is_less_or_equal(num1, num2);
}

int tpr_is_greater_or_equal(tpr_decimal num1, tpr_decimal num2) {
  return tpr_is_greater(num1, num2) || tpr_is_equal(num1, num2);
}

int tpr_is_not_equal(tpr_decimal num1, tpr_decimal num2) {
  return !tpr_is_equal(num1, num2);
}

void Normalize(tpr_decimal* num1, tpr_decimal* num2) {
  int scale1 = tpr_get_power(num1->bits[3]);
  int scale2 = tpr_get_power(num2->bits[3]);

  int min_scale = (scale1 < scale2) ? scale1 : scale2;
  int max_scale = (scale1 > scale2) ? scale1 : scale2;

  tpr_decimal* min_value = (scale1 < scale2) ? num1 : num2;
  tpr_decimal* max_value = (scale1 > scale2) ? num1 : num2;
  tpr_decimal ten;

  tpr_from_int_to_decimal(10, &ten);

  while (min_scale != max_scale) {
    if (min_scale < MAX_SCALE && !tpr_mul(*min_value, ten, min_value)) {
      min_scale++;

      tpr_set_power(&min_value->bits[3], min_scale);
    }
  }
  tpr_set_power(&min_value->bits[3], min_scale);
  tpr_set_power(&max_value->bits[3], min_scale);
}

int tpr_decimal_get_bit(tpr_decimal value, int index) {
  return ((value.bits[index / 32] >> (index % 32)) & 1u);
}