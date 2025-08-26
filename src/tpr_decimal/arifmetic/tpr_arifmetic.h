#ifndef SRC_tpr_DECIMAL_ARITHMETIC_ARITHMETIC_H_
#define SRC_tpr_DECIMAL_ARITHMETIC_ARITHMETIC_H_

#include "./../tpr_types.h"

#define OK 0
#define BIG 1
#define SMALL 2
#define ZERO_DIV 3
#define ERROR 1

#define MAX_BIG_BITS 224
#define MAX_BLOCK_BITS 32

#define LEFT -1
#define RIGTH 1

int tpr_div(tpr_decimal value_1, tpr_decimal value_2, tpr_decimal *result);
tpr_big_decimal tpr_div_big_size(tpr_big_decimal big_value_1,
                                 tpr_big_decimal big_value_2,
                                 tpr_big_decimal *remainder);
tpr_big_decimal tpr_more_div_big_size(tpr_big_decimal value_1,
                                      tpr_big_decimal temp_result,
                                      tpr_big_decimal remainder);
int tpr_calc_frac(tpr_big_decimal *big_result, tpr_big_decimal value_2,
                  tpr_big_decimal *remainder);
int tpr_is_equal(tpr_decimal num1, tpr_decimal num2);
int tpr_is_not_equal(tpr_decimal num1, tpr_decimal num2);
int tpr_big_is_equal(tpr_big_decimal value_1, tpr_big_decimal value_2);

int tpr_big_is_less(tpr_big_decimal big_value_1, tpr_big_decimal big_value_2);
int tpr_get_big_high_unit(tpr_big_decimal value);
tpr_big_decimal tpr_get_big_move(tpr_big_decimal big_value, int vector,
                                 int index);
int tpr_big_decimal_get_bit(tpr_big_decimal big_value, int index);
tpr_big_decimal tpr_big_decimal_set_bit(tpr_big_decimal value, int index);
tpr_big_decimal tpr_big_round_bank(tpr_big_decimal value_1,
                                   tpr_big_decimal value_2);
int tpr_correct_big_decimal(tpr_big_decimal value);

int tpr_add(tpr_decimal value_1, tpr_decimal value_2, tpr_decimal *result);
tpr_big_decimal tpr_add_big_size(tpr_big_decimal big_value_1,
                                 tpr_big_decimal big_value_2);
tpr_big_decimal tpr_decimal_to_big(tpr_decimal *value_2);
tpr_decimal tpr_decimal_set_zero(void);
int tpr_correct_decimal(tpr_decimal value);
int tpr_get_sign(int value);
void tpr_set_sign(int *value, int sign);
int tpr_big_to_decimal(tpr_big_decimal big_value_1, tpr_decimal *value_2);
int tpr_get_power(int number);
int tpr_big_level(tpr_big_decimal *big_value_1, tpr_big_decimal *big_value_2);
int tpr_get_bit(int number, int index);
int tpr_set_bit(int number, int index);
int tpr_reset_bit(int number, int index);
void tpr_set_power(int *number, int power);
int tpr_negate(tpr_decimal value, tpr_decimal *result);

int tpr_mul(tpr_decimal value_1, tpr_decimal value_2, tpr_decimal *result);
tpr_big_decimal tpr_mul_big_size(tpr_big_decimal big_value_1,
                                 tpr_big_decimal big_value_2);

int tpr_sub(tpr_decimal value_1, tpr_decimal value_2, tpr_decimal *result);
tpr_big_decimal tpr_sub_big_size(tpr_big_decimal big_value_1,
                                 tpr_big_decimal big_value_2);
int tpr_is_greater_or_equal(tpr_decimal num1, tpr_decimal num2);
int tpr_big_is_greater_or_equal(tpr_big_decimal big_value_1,
                                tpr_big_decimal big_value_2);

#endif
