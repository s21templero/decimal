#include "tpr_convertor.h"

#include "../arifmetic/tpr_arifmetic.h"
#define MAX_FLOAT_TO_CONVERT 79228157791897854723898736640.0f
#define MIN_FLOAT_TO_CONVERT \
  0.00000000000000000000000000010000000031710768509710513471352647538147514756461109f

int tpr_from_int_to_decimal(int src, tpr_decimal *dst) {
  int result = 0;
  if (!dst) {
    result = 1;
  } else {
    if ((src >= MAX_DEC) || (src <= MIN_DEC)) {
      result = 1;
    } else if (src == 0)
      dst->bits[0] = 0;
    else {
      for (int i = 0; i < 4; i++) dst->bits[i] = 0;
      if (src < 0) {
        src *= -1;
        dst->bits[3] = 1 << 31;
      }
      dst->bits[0] = src;
    }
  }
  return result;
}

int tpr_from_decimal_to_int(tpr_decimal src, int *dst) {
  int result = 0;
  if (!dst)
    result = 1;
  else {
    tpr_truncate(src, &src);
    if (src.bits[2] != 0 || src.bits[1] != 0)
      result = 1;
    else if (src.bits[0] > INT_MAX)
      result = 1;
    else {
      *dst = src.bits[0];
      if (tpr_decimal_get_bit(src, 127) == 1) *dst *= -1;
    }
  }
  return result;
}

int tpr_from_float_to_decimal(float src, tpr_decimal *dst) {
  int error = OK;
  int sign = 0;
  int sign_exp = 0;
  int power = 0;
  int fl = 0, fl1 = 0;
  tpr_decimal temp_res = {0};
  if (!dst) {
    error = CONVERTER_ERROR;
  } else if (src == 0.0) {
    *dst = tpr_decimal_set_zero();
  } else if (isinf(src) || isnan(src)) {
    error = CONVERTER_ERROR;
    *dst = tpr_decimal_set_zero();
  } else if (fabsf(src) > MAX_FLOAT_TO_CONVERT) {
    error = CONVERTER_ERROR;
    *dst = tpr_decimal_set_zero();
  } else if (fabsf(src) < MIN_FLOAT_TO_CONVERT) {
    error = CONVERTER_ERROR;
    *dst = tpr_decimal_set_zero();
  } else {
    *dst = tpr_decimal_set_zero();
    char buffer[16] = {0};
    tpr_decimal ten = {{10, 0, 0, 0}};
    if (src < 0) {
      src = -src;
      sign = 1;
    }
    snprintf(buffer, sizeof(buffer), "%.6e", src);
    power = tpr_get_power_str(buffer);
    int temp_power = power + 28;
    if (power <= -23) {
      for (int i = 0; i < (int)sizeof(buffer); i++) {
        buffer[i] = '\0';
      }
      snprintf(buffer, sizeof(buffer), "%.*e", temp_power, src);
      fl1 = 1;
    }
    power = 0;
    for (int i = 0; buffer[i]; i++) {
      if (buffer[i] != '.' && buffer[i] != 'e') {
        temp_res.bits[0] = temp_res.bits[0] * 10 + (buffer[i] - '0');
      } else if (buffer[i] == 'e') {
        i++;
        if (buffer[i] == '-') {
          sign_exp = 1;
        }
        i++;
        if (buffer[i] >= '0' && buffer[i] <= '9') {
          power = power * 10 + (buffer[i] - '0');
          i++;
        }
        if (buffer[i] >= '0' && buffer[i] <= '9') {
          power = power * 10 + (buffer[i] - '0');
          i++;
        }
      }
    }
    if (sign_exp) {
      power = -power;
    }
    if (fl1) {
      power = power - 6 + (6 - temp_power);
    } else {
      power = power - 6;
    }
    while (power > 0 && error == 0) {
      error = tpr_mul(temp_res, ten, &temp_res);
      --power;
    }

    tpr_big_decimal temp_big_remainder = {0};
    tpr_big_decimal temp_big_res = {0};
    tpr_big_decimal big_ten = {{10, 0, 0, 0, 0, 0, 0, 0}};
    tpr_big_decimal big_src = {0};

    big_src = tpr_decimal_to_big(&temp_res);
    temp_big_res = big_src;
    tpr_div_big_size(big_src, big_ten, &temp_big_remainder);
    while (power <= 0 && temp_big_remainder.bits[0] == 0) {
      temp_big_res = big_src;
      big_src = tpr_div_big_size(big_src, big_ten, &temp_big_remainder);
      power++;
      fl = 1;
    }
    error = tpr_big_to_decimal(temp_big_res, &temp_res);
    if (fl) {
      power--;
    }
  }
  if (power > 28 || power < -28) {
    error = CONVERTER_ERROR;
  }
  if (!error) {
    if (power < 0) {
      power = -power;
    }
    tpr_set_power(&temp_res.bits[3], power);
    tpr_set_sign(&temp_res.bits[3], sign);
    *dst = temp_res;
  }
  return error;
}

int tpr_from_decimal_to_float(tpr_decimal src, float *dst) {
  int res = CONVERTER_ERROR;
  double temp_result = 0.0;
  int power = 0;
  if (dst) {
    for (int i = 0; i < 96; i++) {
      if ((src.bits[i / 32] & (1 << i % 32)) != 0) {
        temp_result += pow(2, i);
      }
    }
    if ((power = tpr_get_power(src.bits[3])) > 0) {
      for (int i = power; i > 0; i--, temp_result /= 10.0) {
        ;
      }
    }

    *dst = (float)temp_result;
    if (tpr_get_sign(src.bits[3])) {
      *dst *= -1;
    }
    res = OK;
  }
  return res;
}

int tpr_get_power_str(char *str) {
  int result = 0;
  char *ptr = str;
  while (*ptr) {
    if (*ptr == 'e') {
      ++ptr;
      result = strtol(ptr, NULL, 10);
      break;
    }
    ++ptr;
  }
  return result;
}
