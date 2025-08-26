#ifndef SRC_tpr_DECIMAL_ARITHMETIC_ARITHMETIC_H_
#define SRC_tpr_DECIMAL_ARITHMETIC_ARITHMETIC_H_

#include "./../tpr_types.h"

#define OK 0
#define BIG 1
#define SMALL 2
#define ZERO_DIV 3
#define ERROR 4

#define MAX_BIG_BITS 224
#define MAX_BLOCK_BITS 32

#define LEFT -1
#define RIGTH 1

int tpr_get_bit(int number, int index);
int tpr_set_bit(int number, int index);
int tpr_reset_bit(int number, int index);
tpr_decimal tpr_decimal_set_zero(void);
tpr_big_decimal tpr_big_decimal_set_zero(void);
int tpr_correct_decimal(tpr_decimal value);
int tpr_correct_big_decimal(tpr_big_decimal value);
int tpr_get_sign(int value);
void tpr_set_sign(int *value, int sign);
tpr_big_decimal tpr_decimal_to_big(tpr_decimal *value);
int tpr_big_to_decimal(tpr_big_decimal big_value_1, tpr_decimal *value_2);
void tpr_set_power(int *number, int power);
int tpr_get_power(int number);
int tpr_get_big_high_unit(tpr_big_decimal value);
int tpr_big_decimal_get_bit(tpr_big_decimal big_value, int index);
tpr_big_decimal tpr_big_decimal_set_bit(tpr_big_decimal value, int index);
tpr_big_decimal tpr_big_round_bank(tpr_big_decimal value_1,
                                   tpr_big_decimal value_2);
tpr_big_decimal tpr_big_rem_zero(tpr_big_decimal big_value);
int tpr_big_level(tpr_big_decimal *big_value_1, tpr_big_decimal *big_value_2);
tpr_big_decimal tpr_get_big_move(tpr_big_decimal big_value, int vector,
                                 int index);
tpr_big_decimal tpr_big_move_left_one(tpr_big_decimal big_value);
tpr_big_decimal tpr_big_move_rigth_one(tpr_big_decimal big_value);
tpr_decimal tpr_decimal_zero(void);
int tpr_big_parity(tpr_big_decimal big_value);
int tpr_big_is_equal(tpr_big_decimal value_1, tpr_big_decimal value_2);
int tpr_big_decimal_compare(tpr_big_decimal big_value_1,
                            tpr_big_decimal big_value_2);
int tpr_big_is_greater(tpr_big_decimal big_value_1,
                       tpr_big_decimal big_value_2);
int tpr_big_is_less(tpr_big_decimal big_value_1, tpr_big_decimal big_value_2);

tpr_big_decimal tpr_div_big_size(tpr_big_decimal big_value_1,
                                 tpr_big_decimal big_value_2,
                                 tpr_big_decimal *remainder);
tpr_big_decimal tpr_add_big_size(tpr_big_decimal big_value_1,
                                 tpr_big_decimal big_value_2);
tpr_big_decimal tpr_mul_big_size(tpr_big_decimal big_value_1,
                                 tpr_big_decimal big_value_2);

#endif
