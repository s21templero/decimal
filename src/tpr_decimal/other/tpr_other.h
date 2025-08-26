#ifndef SRC_tpr_DECIMAL_OTHER_H_
#define SRC_tpr_DECIMAL_OTHER_H_

#include "../tpr_types.h"

#define OK 0
#define CALCULATION_ERROR 1

int tpr_floor(tpr_decimal value, tpr_decimal *result);
int tpr_round(tpr_decimal value, tpr_decimal *result);
int tpr_truncate(tpr_decimal value, tpr_decimal *result);
int tpr_negate(tpr_decimal value, tpr_decimal *result);

int tpr_correct_decimal(tpr_decimal value);
int tpr_sub(tpr_decimal value_1, tpr_decimal value_2, tpr_decimal *result);
int tpr_add(tpr_decimal value_1, tpr_decimal value_2, tpr_decimal *result);
void tpr_set_power(int *number, int power);
int tpr_get_power(int number);
int tpr_div(tpr_decimal value_1, tpr_decimal value_2, tpr_decimal *result);
int tpr_is_greater(tpr_decimal value_1, tpr_decimal value_2);
int tpr_is_greater_or_equal(tpr_decimal value_1, tpr_decimal value_2);
int tpr_get_sign(int value);
void tpr_set_sign(int *value, int sign);
tpr_big_decimal tpr_decimal_to_big(tpr_decimal *value);
tpr_big_decimal tpr_div_big_size(tpr_big_decimal big_value_1,
                                 tpr_big_decimal big_value_2,
                                 tpr_big_decimal *remainder);
int tpr_big_to_decimal(tpr_big_decimal big_value_1, tpr_decimal *value_2);
tpr_decimal tpr_decimal_set_zero(void);

#endif  // SRC_tpr_DECIMAL_OTHER_H_
