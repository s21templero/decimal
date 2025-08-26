#ifndef DECIMAL_H
#define DECIMAL_H

#include "./../tpr_types.h"

#define FALSE 0
#define POSITIVE 0
#define TRUE 1
#define NEGATIVE 1
#define MAX_HIGHT_BIT 95
#define MAX_SCALE 28

int tpr_is_less(tpr_decimal num1, tpr_decimal num2);
int tpr_is_equal(tpr_decimal num1, tpr_decimal num2);
int tpr_is_less_or_equal(tpr_decimal num1, tpr_decimal num2);
int tpr_is_greater(tpr_decimal num1, tpr_decimal num2);
int tpr_is_greater_or_equal(tpr_decimal num1, tpr_decimal num2);
int tpr_is_not_equal(tpr_decimal num1, tpr_decimal num2);

void Normalize(tpr_decimal *num1, tpr_decimal *num2);

#define OK 0
#define DECIMAL_SPECIAL_BIT 3
#define DECIMAL_SPECIAL_BIT_SCALE 16
#define START_SCALE_BIT 16
#define LAST_SCALE_BIT 23
#define DECIMAL_MAX_BIT_SIZE 31
#define COUNT_BITS_IN_PART 32
#define MAX_HIGHT_BIT 95
#define tpr_MAX_DEC 2e96 - 1
#define tpr_MIN_DEC -2e96 + 1

int tpr_from_int_to_decimal(int src, tpr_decimal *dst);
int tpr_mul(tpr_decimal value_1, tpr_decimal value_2, tpr_decimal *result);
void tpr_set_power(int *number, int power);
int tpr_get_power(int number);
int tpr_get_sign(int value);
int tpr_get_bit(int number, int index);
void tpr_set_sign(int *value, int sign);
int Simple_Add(tpr_decimal value1, tpr_decimal value2, tpr_decimal *result);
int shift_left(tpr_decimal *number);
void Init_Decimal_Num(tpr_decimal *number);
int tpr_decimal_get_bit(tpr_decimal value, int index);
void tpr_decimal_set_bit(tpr_decimal *number, int bit, int sign);

#endif
