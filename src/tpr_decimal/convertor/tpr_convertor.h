#ifndef SRC_tpr_DECIMAL_CONVERTOR_H_
#define SRC_tpr_DECIMAL_CONVERTOR_H_

#include "./../tpr_types.h"

#define MAX_DEC 2e96 - 1
#define MIN_DEC -2e96 + 1
#define MAX_INT 2147483647
#define MIN_INT -2147483648

#define CONVERTER_ERROR 1
#define OK 0
#define MINUS 0x80000000
#define tpr_NAN 0. / 0.

//--------------------------------
#define MAX_BLOCK_NUMBER 96
#define MAX_FLOAT_TO_CONVERT 79228157791897854723898736640.0f
#define MIN_FLOAT_TO_CONVERT \
  0.00000000000000000000000000010000000031710768509710513471352647538147514756461109f
//---------------------------------------------
int tpr_add(tpr_decimal value_1, tpr_decimal value_2, tpr_decimal *result);
int tpr_sub(tpr_decimal value_1, tpr_decimal value_2, tpr_decimal *result);
int tpr_floor(tpr_decimal value, tpr_decimal *result);
int tpr_is_less(tpr_decimal num1, tpr_decimal num2);
int tpr_is_greater(tpr_decimal num1, tpr_decimal num2);
int tpr_round(tpr_decimal value, tpr_decimal *result);
int tpr_get_power(int number);
int tpr_mul(tpr_decimal value_1, tpr_decimal value_2, tpr_decimal *result);
void tpr_set_power(int *number, int power);
void tpr_set_sign(int *value, int sign);
tpr_big_decimal tpr_div_big_size(tpr_big_decimal big_value_1,
                                 tpr_big_decimal big_value_2,
                                 tpr_big_decimal *remainder);
tpr_big_decimal tpr_decimal_to_big(tpr_decimal *value_2);
int tpr_big_to_decimal(tpr_big_decimal big_value_1, tpr_decimal *value_2);
int tpr_truncate(tpr_decimal value, tpr_decimal *result);
int tpr_get_sign(int value);
int tpr_get_power_str(char *str);
int tpr_decimal_get_bit(tpr_decimal value, int index);
int tpr_from_int_to_decimal(int src, tpr_decimal *dst);
int tpr_from_decimal_to_int(tpr_decimal src, int *dst);
int tpr_from_float_to_decimal(float src, tpr_decimal *dst);
int tpr_from_decimal_to_float(tpr_decimal src, float *dst);
#endif
