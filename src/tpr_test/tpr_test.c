#include <check.h>
#include <stdio.h>

#include "./../tpr_decimal.h"

START_TEST(sub_0) {
  tpr_decimal val1 = {{10, 0, 0, ~(UINT_MAX / 2)}};

  tpr_decimal val2 = {{10, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_1) {
  tpr_decimal val1 = {{10, 0, 0, 0}};
  tpr_decimal val2 = {{10, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_2) {
  tpr_decimal val1 = {{20, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{20, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_3) {
  tpr_decimal val1 = {{20, 0, 0, 0}};
  tpr_decimal val2 = {{20, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_4) {
  tpr_decimal val1 = {{80, 0, 0, 0}};
  tpr_decimal val2 = {{20, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_5) {
  tpr_decimal val1 = {{20, 0, 0, 0}};
  tpr_decimal val2 = {{80, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_6) {
  tpr_decimal val1 = {{80, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{20, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_7) {
  tpr_decimal val1 = {{20, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{80, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_8) {
  tpr_decimal val1 = {{20, 0, 0, 0}};
  tpr_decimal val2 = {{80, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_9) {
  tpr_decimal val1 = {{80, 0, 0, 0}};
  tpr_decimal val2 = {{20, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_10) {
  tpr_decimal val1 = {{80, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_11) {
  tpr_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{4, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(2, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_12) {
  tpr_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  tpr_decimal val2 = {{4, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_13) {
  tpr_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_14) {
  tpr_decimal val1 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(2, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_15) {
  tpr_decimal val1 = {{4, 0, 0, 0}};
  tpr_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_16) {
  tpr_decimal val1 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_17) {
  tpr_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  tpr_decimal val2 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(1, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_18) {
  tpr_decimal val1 = {{4, 0, 0, 0}};
  tpr_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(1, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_19) {
  tpr_decimal val1 = {{4, 0, 0, 0}};
  tpr_decimal val2 = {{4, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_20) {
  tpr_decimal dec1 = {{0}};
  tpr_decimal dec2 = {{0}};
  int tmp1 = 100;
  int tmp2 = 99999;
  int res_s21 = 0;
  int res = -99899;
  tpr_decimal res1 = {{0}};
  tpr_from_int_to_decimal(tmp1, &dec1);
  tpr_from_int_to_decimal(tmp2, &dec2);
  tpr_sub(dec1, dec2, &res1);
  tpr_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(sub_21) {
  tpr_decimal dec1 = {{0}};
  tpr_decimal dec2 = {{0}};
  int tmp1 = -100;
  int tmp2 = -99999;
  int res_s21 = 0;
  tpr_decimal res1 = {{0}};
  int res = 99899;
  tpr_from_int_to_decimal(tmp1, &dec1);
  tpr_from_int_to_decimal(tmp2, &dec2);
  tpr_sub(dec1, dec2, &res1);
  tpr_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(sub_22) {
  tpr_decimal val1 = {{0, 0, 0, 1000000000}};
  tpr_decimal val2 = {{0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(1, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_23) {
  tpr_decimal val1 = {{1, 0, 0, 0x1C0001}};
  tpr_decimal val2 = {{0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(1, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_24) {
  tpr_decimal val1 = {{1, 0, 0, 0x11C0000}};
  tpr_decimal val2 = {{0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(1, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_25) {
  tpr_decimal val1 = {{0, 0, 0, 1000000000}};
  tpr_decimal val2 = {{0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(1, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(sub_26) {
  tpr_decimal val1 = {{0}};
  tpr_decimal val2 = {{0}};
  ck_assert_int_eq(1, tpr_sub(val1, val2, NULL));
}
END_TEST

START_TEST(add_0) {
  tpr_decimal val1 = {{15, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{2, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(add_1) {
  tpr_decimal val1 = {{15, 0, 0, 0}};
  tpr_decimal val2 = {{15, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(add_2) {
  tpr_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  tpr_decimal val2 = {{1, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(1, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(add_3) {
  tpr_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(2, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(add_4) {
  tpr_decimal val1 = {{8, 0, 0, 0}};
  tpr_decimal val2 = {{2, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(add_5) {
  tpr_decimal val1 = {{2, 0, 0, 0}};
  tpr_decimal val2 = {{8, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(add_6) {
  tpr_decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{2, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(add_7) {
  tpr_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{8, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(add_8) {
  tpr_decimal val1 = {{0}};
  tpr_decimal val2 = {{0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(add_9) {
  tpr_decimal val1 = {{4, 0, 0, 0}};
  tpr_decimal val2 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(add_10) {
  tpr_decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(add_11) {
  tpr_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{4, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(add_12) {
  tpr_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(2, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(add_13) {
  tpr_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  tpr_decimal val2 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(add_14) {
  tpr_decimal val1 = {{4, 0, 0, 0}};
  tpr_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(add_15) {
  tpr_decimal val1 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(add_16) {
  tpr_decimal val1 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(2, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(add_17) {
  tpr_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  tpr_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  tpr_set_power(&val1.bits[3], 5);
  tpr_set_power(&val2.bits[3], 3);
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(add_18) {
  tpr_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  tpr_set_power(&val1.bits[3], 5);
  tpr_set_power(&val2.bits[3], 3);
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(add_19) {
  tpr_decimal val1 = {{0, 0, 0, 1000000000}};
  tpr_decimal val2 = {{0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(1, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(add_20) {
  tpr_decimal val1 = {{1, 0, 0, 0x1C0001}};
  tpr_decimal val2 = {{0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(1, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(add_21) {
  tpr_decimal val1 = {{1, 0, 0, 0x11C0000}};
  tpr_decimal val2 = {{0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(1, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(add_22) {
  tpr_decimal val1 = {{0, 0, 0, 1000000000}};
  tpr_decimal val2 = {{0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(1, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(add_23) {
  tpr_decimal val1 = {{0}};
  tpr_decimal val2 = {{0}};
  ck_assert_int_eq(1, tpr_add(val1, val2, NULL));
}
END_TEST

START_TEST(mul_0) {
  tpr_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{2, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_1) {
  tpr_decimal val1 = {{2, 0, 0, 0}};
  tpr_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_2) {
  tpr_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_3) {
  tpr_decimal val1 = {{2, 0, 0, 0}};
  tpr_decimal val2 = {{2, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_4) {
  tpr_decimal val1 = {{8, 0, 0, 0}};
  tpr_decimal val2 = {{2, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_5) {
  tpr_decimal val1 = {{2, 0, 0, 0}};
  tpr_decimal val2 = {{8, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_6) {
  tpr_decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{2, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_7) {
  tpr_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{8, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_8) {
  tpr_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(1, tpr_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_9) {
  tpr_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{2, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(2, tpr_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_10) {
  tpr_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  tpr_decimal val2 = {{2, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(1, tpr_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_11) {
  tpr_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{0, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_12) {
  tpr_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{2, 0, 0, 0}};
  tpr_decimal res = {{0}};
  tpr_set_power(&val1.bits[3], 1);
  ck_assert_int_eq(0, tpr_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_13) {
  tpr_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  tpr_decimal val2 = {{200, 0, 0, 0}};
  tpr_decimal res = {{0}};
  tpr_set_power(&val2.bits[3], 3);
  ck_assert_int_eq(0, tpr_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_14) {
  tpr_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  tpr_decimal val1 = {{20, 0, 0, 0}};
  tpr_decimal res = {{0}};
  tpr_set_power(&val2.bits[3], 2);
  ck_assert_int_eq(0, tpr_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_15) {
  tpr_decimal val1 = {{0, 0, 0, 1000000000}};
  tpr_decimal val2 = {{0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(1, tpr_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_16) {
  tpr_decimal val1 = {{1, 0, 0, 0x1C0001}};
  tpr_decimal val2 = {{0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(1, tpr_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_17) {
  tpr_decimal val1 = {{1, 0, 0, 0x11C0000}};
  tpr_decimal val2 = {{0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(1, tpr_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_18) {
  tpr_decimal val1 = {{0, 0, 0, 1000000000}};
  tpr_decimal val2 = {{0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(1, tpr_mul(val1, val2, &res));
}
END_TEST

START_TEST(mul_19) {
  tpr_decimal val1 = {{0}};
  tpr_decimal val2 = {{0}};
  ck_assert_int_eq(1, tpr_mul(val1, val2, NULL));
}
END_TEST

START_TEST(div_0) {
  tpr_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{2, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_div(val1, val2, &res));
}
END_TEST

START_TEST(div_1) {
  tpr_decimal val1 = {{2, 0, 0, 0}};
  tpr_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_div(val1, val2, &res));
}
END_TEST

START_TEST(div_2) {
  tpr_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_div(val1, val2, &res));
}
END_TEST

START_TEST(div_3) {
  tpr_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{0, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(3, tpr_div(val1, val2, &res));
}
END_TEST

START_TEST(div_4) {
  tpr_decimal val1 = {{2, 0, 0, 0}};
  tpr_decimal val2 = {{0, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(3, tpr_div(val1, val2, &res));
}
END_TEST

START_TEST(div_5) {
  tpr_decimal val1 = {{1000, 0, 0, 0}};
  tpr_decimal val2 = {{10, 0, 0, 0}};
  tpr_decimal res = {{0}};
  int r = 0;
  tpr_div(val1, val2, &res);
  tpr_from_decimal_to_int(res, &r);
  ck_assert_int_eq(100, r);
}
END_TEST

START_TEST(div_6) {
  tpr_decimal val1 = {{3, 0, 0, 0}};
  tpr_decimal val2 = {{2, 0, 0, 0}};
  tpr_decimal res = {{0}};
  float fl = 0.0;
  tpr_div(val1, val2, &res);
  tpr_from_decimal_to_float(res, &fl);
  ck_assert_int_eq(1.5, fl);
}
END_TEST

START_TEST(div_7) {
  tpr_decimal val1 = {{0, 0, 0, 0}};
  tpr_decimal val2 = {{0, 0, 0, 0}};
  tpr_decimal res = {{0}};
  float fl1 = 81.5;
  float fl2 = 25.0;
  float flres = 0.0;
  tpr_from_float_to_decimal(fl1, &val1);
  tpr_from_float_to_decimal(fl2, &val2);
  tpr_div(val1, val2, &res);
  tpr_from_decimal_to_float(res, &flres);
  ck_assert_int_eq(3.26, flres);
}
END_TEST

START_TEST(div_8) {
  tpr_decimal val1 = {{0, 0, 0, 1000000000}};
  tpr_decimal val2 = {{0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(1, tpr_div(val1, val2, &res));
}
END_TEST

START_TEST(div_9) {
  tpr_decimal val1 = {{1, 0, 0, 0x1C0001}};
  tpr_decimal val2 = {{0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(1, tpr_div(val1, val2, &res));
}
END_TEST

START_TEST(div_10) {
  tpr_decimal val1 = {{1, 0, 0, 0x11C0000}};
  tpr_decimal val2 = {{0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(1, tpr_div(val1, val2, &res));
}
END_TEST

START_TEST(div_11) {
  tpr_decimal val1 = {{0, 0, 0, 1000000000}};
  tpr_decimal val2 = {{0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(1, tpr_div(val1, val2, &res));
}
END_TEST

START_TEST(div_12) {
  tpr_decimal val1 = {{0}};
  tpr_decimal val2 = {{0}};
  ck_assert_int_eq(1, tpr_div(val1, val2, NULL));
}
END_TEST

START_TEST(big_to_dec_0) {
  tpr_big_decimal val1 = {{2147483647, 0, 0, 0, 0, 0, 0, 0}};
  tpr_decimal val2 = {{0, 0, 0, 0}};
  tpr_set_power(&val1.bits[7], 30);
  tpr_big_to_decimal(val1, &val2);
  int r = val2.bits[0];
  ck_assert_int_eq(21474836, r);
}
END_TEST

START_TEST(big_to_dec_1) {
  tpr_big_decimal val1 = {{2147483647, 0, 0, 0, 0, 0, 0, 0}};
  tpr_decimal val2 = {{0, 0, 0, 0}};
  tpr_set_power(&val1.bits[7], 30);
  tpr_big_to_decimal(val1, &val2);
  int r = tpr_get_power(val2.bits[3]);
  ck_assert_int_eq(28, r);
}
END_TEST

START_TEST(big_to_dec_2) {
  tpr_big_decimal val1 = {{10, 0, 0, 0, 0, 0, 0, 0}};
  tpr_decimal val2 = {{0, 0, 0, 0}};
  tpr_set_power(&val1.bits[7], 30);
  int error = tpr_big_to_decimal(val1, &val2);
  ck_assert_int_eq(2, error);
}
END_TEST

START_TEST(big_to_dec_3) {
  tpr_big_decimal val1 = {{1, 0, 0, 100, 0, 0, 0, 0}};
  tpr_decimal val2 = {{0, 0, 0, 0}};
  tpr_set_power(&val1.bits[7], 28);
  tpr_big_to_decimal(val1, &val2);
  int r = tpr_get_power(val2.bits[3]);
  ck_assert_int_eq(25, r);
}
END_TEST

START_TEST(big_to_dec_4) {
  tpr_big_decimal val1 = {{1, 0, 0, 100, 0, 0, 0, 0}};
  tpr_decimal val2 = {{0, 0, 0, 0}};
  tpr_set_power(&val1.bits[7], 2);
  int error = tpr_big_to_decimal(val1, &val2);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(big_to_dec_5) {
  tpr_big_decimal val1 = {{1, 0, 0, 1, 0, 0, 0, 0}};
  tpr_decimal val2 = {{0, 0, 0, 0}};
  int error = tpr_big_to_decimal(val1, &val2);
  ck_assert_int_eq(1, error);
}
END_TEST

START_TEST(round_bank_0) {
  tpr_big_decimal val1 = {{10, 0, 0, 0, 0, 0, 0, 0}};
  tpr_big_decimal val2 = {{6, 0, 0, 0, 0, 0, 0, 0}};
  val1 = tpr_big_round_bank(val1, val2);
  ck_assert_int_eq(11, val1.bits[0]);
}
END_TEST

START_TEST(round_bank_1) {
  tpr_big_decimal val1 = {{10, 0, 0, 0, 0, 0, 0, 0}};
  tpr_big_decimal val2 = {{5, 0, 0, 0, 0, 0, 0, 0}};
  val1 = tpr_big_round_bank(val1, val2);
  ck_assert_int_eq(10, val1.bits[0]);
}
END_TEST

START_TEST(round_bank_2) {
  tpr_big_decimal val1 = {{11, 0, 0, 0, 0, 0, 0, 0}};
  tpr_big_decimal val2 = {{5, 0, 0, 0, 0, 0, 0, 0}};
  val1 = tpr_big_round_bank(val1, val2);
  ck_assert_int_eq(12, val1.bits[0]);
}
END_TEST

START_TEST(round_bank_3) {
  tpr_big_decimal val1 = {{10, 0, 0, 0, 0, 0, 0, 0}};
  tpr_big_decimal val2 = {{4, 0, 0, 0, 0, 0, 0, 0}};
  val1 = tpr_big_round_bank(val1, val2);
  ck_assert_int_eq(10, val1.bits[0]);
}
END_TEST

START_TEST(round_bank_4) {
  tpr_big_decimal val1 = {{10, 0, 0, 0, 0, 0, 0, 0}};
  tpr_big_decimal val2 = {{50, 0, 0, 0, 0, 0, 0, 0}};
  val1 = tpr_big_round_bank(val1, val2);
  ck_assert_int_eq(10, val1.bits[0]);
}
END_TEST

START_TEST(round_bank_5) {
  tpr_big_decimal val1 = {{10, 0, 0, 0, 0, 0, 0, 0}};
  tpr_big_decimal val2 = {{60, 0, 0, 0, 0, 0, 0, 0}};
  val1 = tpr_big_round_bank(val1, val2);
  ck_assert_int_eq(11, val1.bits[0]);
}
END_TEST

START_TEST(round_bank_6) {
  tpr_big_decimal val1 = {{10, 0, 0, 0, 0, 0, 0, 0}};
  tpr_big_decimal val2 = {{10, 0, 0, 0, 0, 0, 0, 0}};
  val1 = tpr_big_round_bank(val1, val2);
  ck_assert_int_eq(10, val1.bits[0]);
}
END_TEST

START_TEST(round_bank_7) {
  tpr_big_decimal val1 = {{10, 0, 0, 0, 0, 0, 0, 0}};
  tpr_big_decimal val2 = {{100, 0, 0, 0, 0, 0, 0, 0}};
  val1 = tpr_big_round_bank(val1, val2);
  ck_assert_int_eq(10, val1.bits[0]);
}
END_TEST

START_TEST(round_bank_8) {
  tpr_big_decimal val1 = {{10, 0, 0, 0, 0, 0, 0, 0}};
  tpr_big_decimal val2 = {{600, 0, 0, 0, 0, 0, 0, 0}};
  val1 = tpr_big_round_bank(val1, val2);
  ck_assert_int_eq(11, val1.bits[0]);
}
END_TEST

START_TEST(round_bank_9) {
  tpr_big_decimal val1 = {{10, 0, 0, 0, 0, 0, 0, 0}};
  tpr_big_decimal val2 = {{500, 0, 0, 0, 0, 0, 0, 0}};
  val1 = tpr_big_round_bank(val1, val2);
  ck_assert_int_eq(10, val1.bits[0]);
}
END_TEST

START_TEST(round_bank_10) {
  tpr_big_decimal val1 = {{11, 0, 0, 0, 0, 0, 0, 0}};
  tpr_big_decimal val2 = {{500, 0, 0, 0, 0, 0, 0, 0}};
  val1 = tpr_big_round_bank(val1, val2);
  ck_assert_int_eq(12, val1.bits[0]);
}
END_TEST

START_TEST(truncate_0) {
  tpr_decimal val = {{7, 7, 7, 0}};
  tpr_decimal res = {0};
  ck_assert_int_eq(0, tpr_truncate(val, &res));
  float fres = 0;
  tpr_from_decimal_to_float(res, &fres);
  float need = 129127208515966861312.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(truncate_1) {
  tpr_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res = {0};
  ck_assert_int_eq(0, tpr_truncate(val, &res));
  float fres = 0;
  tpr_from_decimal_to_float(res, &fres);
  float need = -2.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(truncate_2) {
  tpr_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res = {0};
  ck_assert_int_eq(0, tpr_truncate(val, &res));
  float fres = 0;
  tpr_from_decimal_to_float(res, &fres);
  float need = -2.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(truncate_3) {
  tpr_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res = {0};
  tpr_set_power(&val.bits[3], 5);
  ck_assert_int_eq(0, tpr_truncate(val, &res));
  float fres = 0;
  tpr_from_decimal_to_float(res, &fres);
  float need = -0.0;
  ck_assert_float_eq(need, fres);
}

START_TEST(truncate_4) {
  tpr_decimal val = {{128, 0, 0, 0}};
  tpr_decimal res = {0};
  tpr_set_power(&val.bits[3], 1);
  ck_assert_int_eq(0, tpr_truncate(val, &res));
  float fres = 0;
  tpr_from_decimal_to_float(res, &fres);
  float need = 12;
  ck_assert_float_eq(need, fres);
}

START_TEST(truncate_5) {
  tpr_decimal val1 = {{0, 0, 0, 1000000000}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(1, tpr_truncate(val1, &res));
}
END_TEST

START_TEST(truncate_6) {
  tpr_decimal val1 = {{0}};
  ck_assert_int_eq(1, tpr_truncate(val1, NULL));
}
END_TEST

START_TEST(negate_0) {
  tpr_decimal val = {{2, 0, 0, 0}};
  tpr_decimal res = {{0}};
  int sign_before = tpr_get_sign(val.bits[3]);
  tpr_negate(val, &res);
  int sign_after = tpr_get_sign(res.bits[3]);

  ck_assert_int_ne(sign_before, sign_after);
}
END_TEST

START_TEST(negate_1) {
  tpr_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res = {{0}};
  int sign_before = tpr_get_sign(val.bits[3]);
  tpr_negate(val, &res);
  int sign_after = tpr_get_sign(res.bits[3]);
  ck_assert_int_ne(sign_before, sign_after);
}
END_TEST

START_TEST(negate_2) {
  tpr_decimal val = {{0, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res = {{0}};
  int sign_before = tpr_get_sign(val.bits[3]);
  tpr_negate(val, &res);
  int sign_after = tpr_get_sign(res.bits[3]);
  ck_assert_int_ne(sign_before, sign_after);
}
END_TEST

START_TEST(negate_3) {
  tpr_decimal val = {{0}};
  tpr_decimal res = {{0}};
  int sign_before = tpr_get_sign(val.bits[3]);
  tpr_negate(val, &res);
  int sign_after = tpr_get_sign(res.bits[3]);
  ck_assert_int_ne(sign_before, sign_after);
}
END_TEST

START_TEST(negate_4) {
  tpr_decimal val1 = {{0, 0, 0, 1000000000}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(1, tpr_negate(val1, &res));
}
END_TEST

START_TEST(negate_5) {
  tpr_decimal val1 = {{0}};
  ck_assert_int_eq(1, tpr_negate(val1, NULL));
}
END_TEST

START_TEST(floor_0) {
  tpr_decimal val = {{2, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_floor(val, &res));
}
END_TEST

START_TEST(floor_1) {
  tpr_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res = {0};
  tpr_floor(val, &res);
  float fres = 0;
  tpr_from_decimal_to_float(res, &fres);
  ck_assert_float_eq(-2, fres);
}
END_TEST

START_TEST(floor_2) {
  tpr_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res = {{0}};
  tpr_set_power(&val.bits[3], 5);
  tpr_floor(val, &res);
  float fres = 0;
  tpr_from_decimal_to_float(res, &fres);
  ck_assert_float_eq(-1, fres);
}
END_TEST

START_TEST(floor_3) {
  tpr_decimal val = {{2, 0, 0, 0}};
  tpr_decimal res = {{0}};
  tpr_set_power(&val.bits[3], 5);
  tpr_floor(val, &res);
  float fres = 0;
  tpr_from_decimal_to_float(res, &fres);
  ck_assert_float_eq(0, fres);
}
END_TEST

START_TEST(floor_4) {
  tpr_decimal val1 = {{0, 0, 0, 1000000000}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(1, tpr_floor(val1, &res));
}
END_TEST

START_TEST(floor_5) {
  tpr_decimal val1 = {{0}};
  ck_assert_int_eq(1, tpr_floor(val1, NULL));
}
END_TEST

START_TEST(round_0) {
  tpr_decimal val = {{7, 7, 7, 0}};
  tpr_decimal res = {{0}};
  tpr_round(val, &res);
  float fres = 0;
  tpr_from_decimal_to_float(res, &fres);
  float need = 129127208515966861312.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(round_1) {
  tpr_decimal val = {{3, 3, 3, ~(UINT_MAX / 2)}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_round(val, &res));
}
END_TEST

START_TEST(round_2) {
  tpr_decimal val = {{3, 3, 3, 0}};
  tpr_decimal res = {{0}};
  tpr_set_power(&val.bits[3], 5);
  ck_assert_int_eq(0, tpr_round(val, &res));
}
END_TEST

START_TEST(round_3) {
  tpr_decimal val = {{7, 7, 7, ~(UINT_MAX / 2)}};
  tpr_decimal res = {{0}};
  tpr_set_power(&val.bits[3], 5);
  ck_assert_int_eq(0, tpr_round(val, &res));
}
END_TEST

START_TEST(round_4) {
  tpr_decimal val = {{25, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res = {{0}};
  tpr_set_power(&val.bits[3], 1);
  ck_assert_int_eq(0, tpr_round(val, &res));
}
END_TEST

START_TEST(round_5) {
  tpr_decimal val = {{26, 0, 0, 0}};
  tpr_decimal res = {{0}};
  tpr_set_power(&val.bits[3], 1);
  ck_assert_int_eq(0, tpr_round(val, &res));
}
END_TEST

START_TEST(round_6) {
  tpr_decimal val = {{115, 0, 0, 0}};
  tpr_decimal res = {{0}};
  tpr_set_power(&val.bits[3], 1);
  ck_assert_int_eq(0, tpr_round(val, &res));
}
END_TEST

START_TEST(round_7) {
  tpr_decimal val = {{118, 0, 0, 0}};
  tpr_decimal res = {{0}};
  tpr_set_power(&val.bits[3], 1);
  ck_assert_int_eq(0, tpr_round(val, &res));
}
END_TEST

START_TEST(round_8) {
  tpr_decimal val = {{125, 0, 0, 0}};
  tpr_decimal res = {{0}};
  tpr_set_power(&val.bits[3], 1);
  ck_assert_int_eq(0, tpr_round(val, &res));
}
END_TEST

START_TEST(round_9) {
  tpr_decimal val = {{128, 0, 0, 0}};
  tpr_decimal res = {{0}};
  tpr_set_power(&val.bits[3], 1);
  tpr_round(val, &res);
  float fres = 0;
  tpr_from_decimal_to_float(res, &fres);
  float need = 13;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(round_10) {
  tpr_decimal val1 = {{0, 0, 0, 1000000000}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(1, tpr_round(val1, &res));
}
END_TEST

START_TEST(round_11) {
  tpr_decimal val1 = {{0}};
  ck_assert_int_eq(1, tpr_round(val1, NULL));
}
END_TEST

START_TEST(from_decimal_to_float_0) {
  tpr_decimal val = {{123456789, 0, 0, 0}};
  tpr_set_power(&val.bits[3], 5);
  float res = 1234.56789;
  float tmp = 0.;
  float *dst = &tmp;
  tpr_from_decimal_to_float(val, dst);
  ck_assert_float_eq(*dst, res);
}
END_TEST

START_TEST(from_decimal_to_float_1) {
  tpr_decimal val = {{123456789, 0, 0, 0}};
  tpr_set_sign(&val.bits[3], 1);
  tpr_set_power(&val.bits[3], 5);
  float res = -1234.56789;
  float tmp = 0.;
  float *dst = &tmp;
  tpr_from_decimal_to_float(val, dst);
  ck_assert_float_eq(*dst, res);
}
END_TEST

START_TEST(from_decimal_to_int_0) {
  tpr_decimal val = {{123456789, 0, 0, 0}};
  tpr_set_power(&val.bits[3], 5);
  int res = 1234;
  int dst = 0;
  tpr_from_decimal_to_int(val, &dst);
  ck_assert_int_eq(dst, res);
}
END_TEST

START_TEST(from_decimal_to_int_1) {
  tpr_decimal val = {{123456789, 0, 0, 0}};
  tpr_set_sign(&val.bits[3], 1);
  tpr_set_power(&val.bits[3], 5);
  int res = -1234;
  int dst = 0;
  tpr_from_decimal_to_int(val, &dst);
  ck_assert_int_eq(dst, res);
}
END_TEST

START_TEST(from_decimal_to_int_2) {
  tpr_decimal val = {{INT_MAX, 0, 0, 0}};
  int res = 2147483647;
  int dst = 0;
  int error = tpr_from_decimal_to_int(val, &dst);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(dst, res);
}
END_TEST

START_TEST(from_decimal_to_int_3) {
  tpr_decimal val = {{2147483648, 0, 0, 0}};
  int res = -2147483648;
  int dst = 0;
  int error = tpr_from_decimal_to_int(val, &dst);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(dst, res);
}
END_TEST

START_TEST(from_decimal_to_int_4) {
  tpr_decimal val = {{INT_MAX, 0, 0, 0}};
  int error = tpr_from_decimal_to_int(val, NULL);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(from_decimal_to_int_5) {
  tpr_decimal val = {{0, 1, 0, 0}};
  int dst = 0;
  int error = tpr_from_decimal_to_int(val, &dst);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(from_decimal_to_int_6) {
  tpr_decimal val = {{INT_MAX, 1, 0, 0}};
  tpr_set_power(&val.bits[3], 7);
  int res = 644;
  int dst = 0;
  int error = tpr_from_decimal_to_int(val, &dst);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(dst, res);
}
END_TEST

START_TEST(from_int_to_decimal_0) {
  tpr_decimal val = {{0, 0, 0, 0}};
  int res = 0;
  int tmp = 123456789;
  tpr_from_int_to_decimal(tmp, &val);
  tpr_from_decimal_to_int(val, &res);
  ck_assert_int_eq(res, tmp);
}
END_TEST

START_TEST(from_int_to_decimal_1) {
  tpr_decimal val = {{0, 0, 0, 0}};
  int res = 0;
  int tmp = -123456789;
  tpr_from_int_to_decimal(tmp, &val);
  tpr_from_decimal_to_int(val, &res);
  ck_assert_int_eq(res, tmp);
}
END_TEST

START_TEST(from_int_to_decimal_2) {
  int tmp = 1;
  int error = tpr_from_int_to_decimal(tmp, NULL);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(test_convertors_positive_int) {
  int value = 15;
  tpr_decimal decimal = {{0}};
  int res = 0;
  ck_assert(tpr_from_int_to_decimal(value, &decimal) == 0);
  ck_assert(tpr_from_decimal_to_int(decimal, &res) == 0);
  ck_assert_int_eq(value, res);
}
END_TEST

START_TEST(test_convertors_negatives_int) {
  int value = -15;
  tpr_decimal decimal = {{0}};
  int res = 0;
  ck_assert(tpr_from_int_to_decimal(value, &decimal) == 0);
  ck_assert(tpr_from_decimal_to_int(decimal, &res) == 0);
  ck_assert_int_eq(value, res);
}
END_TEST

START_TEST(test_convertors_positive_float) {
  float value = 15.25;
  tpr_decimal decimal = {{0}};
  float res = 0;
  ck_assert(tpr_from_float_to_decimal(value, &decimal) == 0);
  ck_assert(tpr_from_decimal_to_float(decimal, &res) == 0);
  ck_assert_ldouble_eq_tol(value, res, 1e-6);
}
END_TEST

START_TEST(test_convertors_negatives_float) {
  float value = -15.25;
  tpr_decimal decimal = {{0}};
  float res = 0;
  ck_assert(tpr_from_float_to_decimal(value, &decimal) == 0);
  ck_assert(tpr_from_decimal_to_float(decimal, &res) == 0);
  ck_assert_ldouble_eq_tol(value, res, 1e-6);
}
END_TEST

START_TEST(test_convertors_positives_float_to_int) {
  float value = 15.25;
  tpr_decimal decimal = {{0}};
  int res = value;
  int dec_res = 0;
  ck_assert(tpr_from_float_to_decimal(value, &decimal) == 0);
  ck_assert(tpr_from_decimal_to_int(decimal, &dec_res) == 0);
  ck_assert_int_eq(res, dec_res);
}
END_TEST

START_TEST(test_convertors_negatives_float_to_int) {
  float value = -15.25;
  tpr_decimal decimal = {{0}};
  int res = value;
  int dec_res = 0;
  ck_assert(tpr_from_float_to_decimal(value, &decimal) == 0);
  ck_assert(tpr_from_decimal_to_int(decimal, &dec_res) == 0);
  ck_assert_int_eq(res, dec_res);
}

START_TEST(test_convertors_zero_int) {
  int value = 0, res = 0;
  tpr_decimal decimal = {{0}};
  ck_assert(tpr_from_int_to_decimal(value, &decimal) == 0);
  ck_assert(tpr_from_decimal_to_int(decimal, &res) == 0);
  ck_assert_int_eq(res, value);
}
END_TEST

START_TEST(test_convertors_zero_float) {
  float value = 0.0, res = 0.0;
  tpr_decimal decimal = {{0}};
  ck_assert(tpr_from_float_to_decimal(value, &decimal) == 0);
  ck_assert(tpr_from_decimal_to_float(decimal, &res) == 0);
  ck_assert_ldouble_eq(res, value);
}
END_TEST

START_TEST(test_convertors_nan) {
  float value = tpr_NAN;
  tpr_decimal decimal = {{0}};
  ck_assert(tpr_from_float_to_decimal(value, &decimal) == 1);
}
END_TEST

START_TEST(test_convertors_max) {
  float value = MAX_DEC;
  tpr_decimal decimal = {{0}};
  ck_assert(tpr_from_float_to_decimal(value, &decimal) == 1);
}
END_TEST

START_TEST(test_convertors_min) {
  float value = MIN_DEC;
  tpr_decimal decimal = {{0}};
  ck_assert(tpr_from_float_to_decimal(value, &decimal) == 1);
}
END_TEST

START_TEST(test_convertors_zero_scale) {
  float value = 10.0, res = 0.0;
  tpr_decimal decimal = {{0}};
  ck_assert(tpr_from_float_to_decimal(value, &decimal) == 0);
  ck_assert(tpr_from_decimal_to_float(decimal, &res) == 0);
  ck_assert_ldouble_eq(value, res);
}
END_TEST

START_TEST(test_convertors_int_max) {
  int value = 0;
  tpr_decimal decimal = {{123, 1, 0, 0}};
  ck_assert(tpr_from_decimal_to_int(decimal, &value) == 1);
}
END_TEST

START_TEST(test_convertors_int_max_2) {
  int value = 0;
  tpr_decimal decimal = {{123, 0, 1, 0}};
  ck_assert(tpr_from_decimal_to_int(decimal, &value) == 1);
}
END_TEST

START_TEST(test_convertors_int_max_3) {
  int value = 0;
  tpr_decimal decimal = {{123, 1, 1, 0}};
  ck_assert(tpr_from_decimal_to_int(decimal, &value) == 1);
}
END_TEST

START_TEST(test_convertors_int_max_4) {
  int value = 0;
  tpr_decimal decimal = {{2147483655, 1, 0, 0}};
  ck_assert(tpr_from_decimal_to_int(decimal, &value) == 1);
}
END_TEST

START_TEST(test_convertors_int_max_5) {
  int value = 0;
  tpr_decimal decimal = {{2147483655, 1, 0, 1 << 31}};
  ck_assert(tpr_from_decimal_to_int(decimal, &value) == 1);
}
END_TEST

START_TEST(test_convertors_int_max_6) {
  int value = 0;
  tpr_decimal decimal = {{2147483655, 0, 0, 4 << 16}};
  ck_assert(tpr_from_decimal_to_int(decimal, &value) == 0);
}
END_TEST

START_TEST(test_convertors_int_max_7) {
  int value = 0;
  tpr_decimal decimal = {{2147483655, 0, 0, (1 << 31) + (4 << 16)}};
  ck_assert(tpr_from_decimal_to_int(decimal, &value) == 0);
}
END_TEST

START_TEST(test_convertors_zero) {
  float value = 0.0, res = 0.0;
  tpr_decimal decimal = {{0}};
  ck_assert(tpr_from_float_to_decimal(value, &decimal) == 0);
  ck_assert(tpr_from_decimal_to_float(decimal, &res) == 0);
  ck_assert_ldouble_eq(res, value);
}
END_TEST

START_TEST(test_convertors_max_8) {
  tpr_decimal decimal = {{4294967295, 100, 0, 1 << 16}};
  int res = 0;
  ck_assert(tpr_from_decimal_to_int(decimal, &res) == 1);
}
END_TEST

START_TEST(test_tpr_is_less_1) {
  tpr_decimal val1 = {.bits = {1, 2, 3, 655360}};  // 5534023222.9718589441
  tpr_decimal val2 = {
      .bits = {3, 2, 1, -2146828288}};  // -1844674408.2299486211
  int result = tpr_is_less(val1, val2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_tpr_is_less_2) {
  tpr_decimal val1 = {
      .bits = {1, 2, 3, -2146828288}};  // -5534023222.9718589441
  tpr_decimal val2 = {
      .bits = {3, 2, 1, -2146828288}};  // -1844674408.2299486211
  int result = tpr_is_less(val1, val2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_tpr_is_less_3) {
  tpr_decimal val1 = {
      .bits = {1, 2, 3, -2146566144}};  // -553402.32229718589441
  tpr_decimal val2 = {
      .bits = {3, 2, 1, -2146959360}};  // -184467440822.99486211
  int result = tpr_is_less(val1, val2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_tpr_is_less_4) {
  tpr_decimal val1 = {
      .bits = {10, 2, 3, -2146566144}};            // -553402.32229718589450
  tpr_decimal val2 = {.bits = {3, 2, 1, 524288}};  // 184467440822.99486211
  int result = tpr_is_less(val1, val2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_tpr_is_less_5) {
  tpr_decimal val1 = {.bits = {1, 2, 3, 917504}};  // 553402.32229718589441
  tpr_decimal val2 = {.bits = {1, 2, 3, 917504}};  // 553402.32229718589441
  int result = tpr_is_less(val1, val2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_tpr_is_less_6) {
  tpr_decimal val1 = {.bits = {0, 0, 0, 0}};
  tpr_decimal val2 = {.bits = {0, 0, 0, 0}};
  int result = tpr_is_less(val1, val2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_tpr_is_less_7) {
  tpr_decimal val1 = {.bits = {0, 0, 0, 0}};
  tpr_decimal val2 = {.bits = {0, 0, 0, 2147483648}};
  int result = tpr_is_less(val1, val2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_tpr_is_less_or_equal_1) {
  tpr_decimal val1 = {.bits = {1, 2, 3, 655360}};  // 5534023222.9718589441
  tpr_decimal val2 = {
      .bits = {3, 2, 1, -2146828288}};  // -1844674408.2299486211
  int result = tpr_is_less_or_equal(val1, val2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_tpr_is_less_or_equal_2) {
  tpr_decimal val1 = {
      .bits = {1, 2, 3, -2146828288}};  // -5534023222.9718589441
  tpr_decimal val2 = {
      .bits = {3, 2, 1, -2146828288}};  // -1844674408.2299486211
  int result = tpr_is_less_or_equal(val1, val2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_tpr_is_less_or_equal_3) {
  tpr_decimal val1 = {
      .bits = {1, 2, 3, -2146566144}};  // -553402.32229718589441
  tpr_decimal val2 = {
      .bits = {3, 2, 1, -2146959360}};  // -184467440822.99486211
  int result = tpr_is_less_or_equal(val1, val2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_tpr_is_less_or_equal_4) {
  tpr_decimal val1 = {
      .bits = {10, 2, 3, -2146566144}};            // -553402.32229718589450
  tpr_decimal val2 = {.bits = {3, 2, 1, 524288}};  // 184467440822.99486211
  int result = tpr_is_less_or_equal(val1, val2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_tpr_is_less_or_equal_5) {
  tpr_decimal val1 = {.bits = {1, 2, 3, 917504}};  // 553402.32229718589441
  tpr_decimal val2 = {.bits = {1, 2, 3, 917504}};  // 553402.32229718589441
  int result = tpr_is_less_or_equal(val1, val2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_tpr_is_less_or_equal_6) {
  tpr_decimal val1 = {.bits = {0, 0, 0, 0}};
  tpr_decimal val2 = {.bits = {0, 0, 0, 0}};
  int result = tpr_is_less_or_equal(val1, val2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_tpr_is_less_or_equal_7) {
  tpr_decimal val1 = {.bits = {0, 0, 0, 0}};
  tpr_decimal val2 = {.bits = {0, 0, 0, 2147483648}};
  int result = tpr_is_less_or_equal(val1, val2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_tpr_is_greater_1) {
  tpr_decimal val1 = {.bits = {1, 2, 3, 655360}};  // 5534023222.9718589441
  tpr_decimal val2 = {
      .bits = {3, 2, 1, -2146828288}};  // -1844674408.2299486211
  int result = tpr_is_greater(val1, val2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_tpr_is_greater_2) {
  tpr_decimal val1 = {
      .bits = {1, 2, 3, -2146828288}};  // -5534023222.9718589441
  tpr_decimal val2 = {
      .bits = {3, 2, 1, -2146828288}};  // -1844674408.2299486211
  int result = tpr_is_greater(val1, val2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_tpr_is_greater_3) {
  tpr_decimal val1 = {
      .bits = {1, 2, 3, -2146566144}};  // -553402.32229718589441
  tpr_decimal val2 = {
      .bits = {3, 2, 1, -2146959360}};  // -184467440822.99486211
  int result = tpr_is_greater(val1, val2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_tpr_is_greater_4) {
  tpr_decimal val1 = {
      .bits = {10, 2, 3, -2146566144}};            // -553402.32229718589450
  tpr_decimal val2 = {.bits = {3, 2, 1, 524288}};  // 184467440822.99486211
  int result = tpr_is_greater(val1, val2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_tpr_is_greater_5) {
  tpr_decimal val1 = {.bits = {1, 2, 3, 917504}};  // 553402.32229718589441
  tpr_decimal val2 = {.bits = {1, 2, 3, 917504}};  // 553402.32229718589441
  int result = tpr_is_greater(val1, val2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_tpr_is_greater_6) {
  tpr_decimal val1 = {.bits = {0, 0, 0, 0}};
  tpr_decimal val2 = {.bits = {0, 0, 0, 0}};
  int result = tpr_is_greater(val1, val2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_tpr_is_greater_7) {
  tpr_decimal val1 = {.bits = {0, 0, 0, 0}};
  tpr_decimal val2 = {.bits = {0, 0, 0, 2147483648}};
  int result = tpr_is_greater(val1, val2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_tpr_is_greater_or_equal_1) {
  tpr_decimal val1 = {.bits = {1, 2, 3, 655360}};  // 5534023222.9718589441
  tpr_decimal val2 = {
      .bits = {3, 2, 1, -2146828288}};  // -1844674408.2299486211
  int result = tpr_is_greater_or_equal(val1, val2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_tpr_is_greater_or_equal_2) {
  tpr_decimal val1 = {
      .bits = {1, 2, 3, -2146828288}};  // -5534023222.9718589441
  tpr_decimal val2 = {
      .bits = {3, 2, 1, -2146828288}};  // -1844674408.2299486211
  int result = tpr_is_greater_or_equal(val1, val2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_tpr_is_greater_or_equal_3) {
  tpr_decimal val1 = {
      .bits = {1, 2, 3, -2146566144}};  // -553402.32229718589441
  tpr_decimal val2 = {
      .bits = {3, 2, 1, -2146959360}};  // -184467440822.99486211
  int result = tpr_is_greater_or_equal(val1, val2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_tpr_is_greater_or_equal_4) {
  tpr_decimal val1 = {
      .bits = {10, 2, 3, -2146566144}};            // -553402.32229718589450
  tpr_decimal val2 = {.bits = {3, 2, 1, 524288}};  // 184467440822.99486211
  int result = tpr_is_greater_or_equal(val1, val2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_tpr_is_greater_or_equal_5) {
  tpr_decimal val1 = {.bits = {1, 2, 3, 917504}};  // 553402.32229718589441
  tpr_decimal val2 = {.bits = {1, 2, 3, 917504}};  // 553402.32229718589441
  int result = tpr_is_greater_or_equal(val1, val2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_tpr_is_greater_or_equal_6) {
  tpr_decimal val1 = {.bits = {0, 0, 0, 0}};
  tpr_decimal val2 = {.bits = {0, 0, 0, 0}};
  int result = tpr_is_greater_or_equal(val1, val2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_tpr_is_greater_or_equal_7) {
  tpr_decimal val1 = {.bits = {0, 0, 0, 0}};
  tpr_decimal val2 = {.bits = {0, 0, 0, 2147483648}};
  int result = tpr_is_greater_or_equal(val1, val2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_tpr_is_equal_1) {
  tpr_decimal val1 = {.bits = {1, 2, 3, 655360}};  // 5534023222.9718589441
  tpr_decimal val2 = {
      .bits = {3, 2, 1, -2146828288}};  // -1844674408.2299486211
  int result = tpr_is_equal(val1, val2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_tpr_is_equal_2) {
  tpr_decimal val1 = {
      .bits = {1, 2, 3, -2146828288}};  // -5534023222.9718589441
  tpr_decimal val2 = {
      .bits = {3, 2, 1, -2146828288}};  // -1844674408.2299486211
  int result = tpr_is_equal(val1, val2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_tpr_is_equal_3) {
  tpr_decimal val1 = {
      .bits = {1, 2, 3, -2146566144}};  // -553402.32229718589441
  tpr_decimal val2 = {
      .bits = {3, 2, 1, -2146959360}};  // -184467440822.99486211
  int result = tpr_is_equal(val1, val2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_tpr_is_equal_4) {
  tpr_decimal val1 = {
      .bits = {10, 2, 3, -2146566144}};            // -553402.32229718589450
  tpr_decimal val2 = {.bits = {3, 2, 1, 524288}};  // 184467440822.99486211
  int result = tpr_is_equal(val1, val2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_tpr_is_equal_5) {
  tpr_decimal val1 = {.bits = {1, 2, 3, 917504}};  // 553402.32229718589441
  tpr_decimal val2 = {.bits = {1, 2, 3, 917504}};  // 553402.32229718589441
  int result = tpr_is_equal(val1, val2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_tpr_is_equal_6) {
  tpr_decimal val1 = {.bits = {0, 0, 0, 0}};
  tpr_decimal val2 = {.bits = {0, 0, 0, 0}};
  int result = tpr_is_equal(val1, val2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_tpr_is_equal_7) {
  tpr_decimal val1 = {.bits = {0, 0, 0, 0}};
  tpr_decimal val2 = {.bits = {0, 0, 0, 2147483648}};
  int result = tpr_is_equal(val1, val2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_tpr_is_not_equal_1) {
  tpr_decimal val1 = {.bits = {1, 2, 3, 655360}};  // 5534023222.9718589441
  tpr_decimal val2 = {
      .bits = {3, 2, 1, -2146828288}};  // -1844674408.2299486211
  int result = tpr_is_not_equal(val1, val2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_tpr_is_not_equal_2) {
  tpr_decimal val1 = {
      .bits = {1, 2, 3, -2146828288}};  // -5534023222.9718589441
  tpr_decimal val2 = {
      .bits = {3, 2, 1, -2146828288}};  // -1844674408.2299486211
  int result = tpr_is_not_equal(val1, val2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_tpr_is_not_equal_3) {
  tpr_decimal val1 = {
      .bits = {1, 2, 3, -2146566144}};  // -553402.32229718589441
  tpr_decimal val2 = {
      .bits = {3, 2, 1, -2146959360}};  // -184467440822.99486211
  int result = tpr_is_not_equal(val1, val2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_tpr_is_not_equal_4) {
  tpr_decimal val1 = {
      .bits = {10, 2, 3, -2146566144}};            // -553402.32229718589450
  tpr_decimal val2 = {.bits = {3, 2, 1, 524288}};  // 184467440822.99486211
  int result = tpr_is_not_equal(val1, val2);
  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_tpr_is_not_equal_5) {
  tpr_decimal val1 = {.bits = {1, 2, 3, 917504}};  // 553402.32229718589441
  tpr_decimal val2 = {.bits = {1, 2, 3, 917504}};  // 553402.32229718589441
  int result = tpr_is_not_equal(val1, val2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_tpr_is_not_equal_6) {
  tpr_decimal val1 = {.bits = {0, 0, 0, 0}};
  tpr_decimal val2 = {.bits = {0, 0, 0, 0}};
  int result = tpr_is_not_equal(val1, val2);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_tpr_is_not_equal_7) {
  tpr_decimal val1 = {.bits = {0, 0, 0, 0}};
  tpr_decimal val2 = {.bits = {0, 0, 0, 2147483648}};
  int result = tpr_is_not_equal(val1, val2);
  ck_assert_int_eq(result, 0);
}
END_TEST

/////////////////////////////////////////////////////

// add

START_TEST(test_arith_add_1) {
  tpr_decimal value_1 = {{21, 0, 0, 0}}, value_2 = {{8, 0, 0, 0}},
              expected = {{29, 0, 0, 0}}, result;
  tpr_set_power(&value_1.bits[3], 5);
  tpr_set_power(&value_2.bits[3], 5);
  tpr_set_power(&expected.bits[3], 5);

  tpr_add(value_1, value_2, &result);
  ck_assert_int_eq(tpr_is_equal(result, expected), 1);
}
END_TEST

START_TEST(test_arith_add_2) {
  tpr_decimal value_1 = {{123, 0, 0, 0}}, value_2 = {{456, 0, 0, 0}},
              expected = {{333, 0, 0, 0}}, result;
  tpr_set_power(&value_1.bits[3], 5);
  tpr_set_power(&value_2.bits[3], 5);
  tpr_set_power(&expected.bits[3], 5);
  tpr_set_sign(&value_1.bits[3], 1);

  tpr_add(value_1, value_2, &result);
  ck_assert_int_eq(tpr_is_equal(result, expected), 1);
}
END_TEST

START_TEST(test_arith_add_3) {
  tpr_decimal value_1 = {{555, 0, 0, 0}}, value_2 = {{456, 0, 0, 0}},
              expected = {{99, 0, 0, 0}}, result;
  tpr_set_power(&value_1.bits[3], 5);
  tpr_set_power(&value_2.bits[3], 5);
  tpr_set_power(&expected.bits[3], 5);
  tpr_set_sign(&value_1.bits[3], 1);
  tpr_set_sign(&expected.bits[3], 1);

  tpr_add(value_1, value_2, &result);
  ck_assert_int_eq(tpr_is_equal(result, expected), 1);
}
END_TEST

START_TEST(test_arith_add_4) {
  tpr_decimal value_1 = {{123, 0, 0, 0}}, value_2 = {{456, 0, 0, 0}},
              expected = {{333, 0, 0, 0}}, result;
  tpr_set_power(&value_1.bits[3], 5);
  tpr_set_power(&value_2.bits[3], 5);
  tpr_set_power(&expected.bits[3], 5);
  tpr_set_sign(&value_2.bits[3], 1);
  tpr_set_sign(&expected.bits[3], 1);

  tpr_add(value_1, value_2, &result);
  ck_assert_int_eq(tpr_is_equal(result, expected), 1);
}
END_TEST

START_TEST(test_arith_add_5) {
  tpr_decimal value_1 = {{555, 0, 0, 0}}, value_2 = {{456, 0, 0, 0}},
              expected = {{99, 0, 0, 0}}, result;
  tpr_set_power(&value_1.bits[3], 5);
  tpr_set_power(&value_2.bits[3], 5);
  tpr_set_power(&expected.bits[3], 5);
  tpr_set_sign(&value_2.bits[3], 1);

  tpr_add(value_1, value_2, &result);
  ck_assert_int_eq(tpr_is_equal(result, expected), 1);
}
END_TEST

START_TEST(test_arith_add_6) {
  tpr_decimal value_1 = {{100, 0, 0, 0}}, value_2 = {{200, 0, 0, 0}},
              expected = {{300, 0, 0, 0}}, result;
  tpr_set_power(&value_1.bits[3], 0);
  tpr_set_power(&value_2.bits[3], 0);
  tpr_set_power(&expected.bits[3], 0);

  tpr_add(value_1, value_2, &result);
  ck_assert_int_eq(tpr_is_equal(result, expected), 1);
}
END_TEST

START_TEST(test_arith_add_7) {
  tpr_decimal value_1 = {{100, 0, 0, 0}}, value_2 = {{200, 0, 0, 0}},
              expected = {{2100, 0, 0, 0}}, result;
  tpr_set_power(&value_1.bits[3], 2);
  tpr_set_power(&value_2.bits[3], 1);
  tpr_set_power(&expected.bits[3], 2);

  tpr_add(value_1, value_2, &result);
  ck_assert_int_eq(tpr_is_equal(result, expected), 1);
}
END_TEST

START_TEST(test_arith_add_8) {
  tpr_decimal value_1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}},
              value_2 = {{1, 0, 0, 0}}, result;

  int code = tpr_add(value_1, value_2, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_arith_add_9) {
  tpr_decimal value_1 = {{0, 0, 0, 0}}, value_2 = {{0, 0, 0, 0}},
              expected = {{0, 0, 0, 0}}, result;

  tpr_add(value_1, value_2, &result);
  ck_assert_int_eq(tpr_is_equal(result, expected), 1);
}
END_TEST

START_TEST(test_arith_add_10) {
  tpr_decimal value_1 = {{5, 0, 0, 0}}, value_2 = {{5, 0, 0, 0}},
              expected = {{1, 0, 0, 0}};
  tpr_set_power(&value_1.bits[3], 1);
  tpr_set_power(&value_2.bits[3], 1);
  tpr_decimal result;

  int code = tpr_add(value_1, value_2, &result);

  ck_assert_int_eq(code, OK);
  ck_assert_int_eq(tpr_is_equal(result, expected), 1);
}

START_TEST(test_arith_add_11) {
  tpr_decimal value_1 = {{123, 0, 0, 0}}, value_2 = {{456, 0, 0, 0}},
              expected = {{333, 0, 0, 0}}, result;
  tpr_set_power(&value_1.bits[3], 5);
  tpr_set_power(&value_2.bits[3], 5);
  tpr_set_power(&expected.bits[3], 5);
  tpr_set_sign(&value_1.bits[3], 1);
  tpr_set_sign(&value_2.bits[3], 0);

  tpr_add(value_1, value_2, &result);
  ck_assert_int_eq(tpr_is_equal(result, expected), 1);
}
END_TEST

START_TEST(test_arith_add_12) {
  tpr_decimal value_1 = {{0, 0, 0, 0}}, value_2 = {{1, 0, 0, 0}},
              expected = {{1, 0, 0, 0}}, result;

  tpr_add(value_1, value_2, &result);
  ck_assert_int_eq(tpr_is_equal(result, expected), 1);
}
END_TEST

START_TEST(test_arith_add_13) {
  tpr_decimal value_1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}},
              value_2 = {{1, 0, 0, 0}}, result;

  int code = tpr_add(value_1, value_2, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_arith_add_14) {
  tpr_decimal value_1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}},
              value_2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}}, result;

  int code = tpr_add(value_1, value_2, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_arith_add_15) {
  tpr_decimal value_1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}},
              value_2 = {{1, 0, 0, 0}}, result;

  int code = tpr_add(value_1, value_2, &result);
  ck_assert_int_eq(code, 1);
}
END_TEST

START_TEST(test_arith_add_16) {
  tpr_decimal value_1 = {{1, 0, 0, 0}}, value_2 = {{1, 0, 0, 0}},
              expected = {{2, 0, 0, 0}}, result;

  tpr_add(value_1, value_2, &result);
  ck_assert_int_eq(tpr_is_equal(result, expected), 1);
}
END_TEST

START_TEST(test_arith_add_17) {
  tpr_decimal value_1 = {{0, 0, 0, 0}}, value_2 = {{0, 0, 0, 0}},
              expected = {{0, 0, 0, 0}}, result;

  tpr_add(value_1, value_2, &result);
  ck_assert_int_eq(tpr_is_equal(result, expected), 1);
}
END_TEST

START_TEST(test_arith_add_18) {
  tpr_decimal value_1 = {{1, 0, 0, 0}}, value_2 = {{0, 0, 0, 0}},
              expected = {{1, 0, 0, 0}}, result;

  tpr_add(value_1, value_2, &result);
  ck_assert_int_eq(tpr_is_equal(result, expected), 1);
}
END_TEST

START_TEST(test_arith_add_19) {
  tpr_decimal value_1 = {{0, 0, 0, 0}}, value_2 = {{1, 0, 0, 0}},
              expected = {{1, 0, 0, 0}}, result;

  tpr_add(value_1, value_2, &result);
  ck_assert_int_eq(tpr_is_equal(result, expected), 1);
}
END_TEST

START_TEST(test_arith_add_20) {
  tpr_decimal value_1 = {{1, 0, 0, 0}}, value_2 = {{1, 0, 0, 0}},
              expected = {{2, 0, 0, 0}}, result;

  tpr_add(value_1, value_2, &result);
  ck_assert_int_eq(tpr_is_equal(result, expected), 1);
}
END_TEST

START_TEST(test_arith_add_21) {
  tpr_decimal value_1 = {{1, 0, 0, 0}}, value_2 = {{2, 0, 0, 0}},
              expected = {{3, 0, 0, 0}}, result;

  tpr_add(value_1, value_2, &result);
  ck_assert_int_eq(tpr_is_equal(result, expected), 1);
}
END_TEST

START_TEST(test_arith_add_22) {
  tpr_decimal value_1 = {{0, 0, 0, 0}}, value_2 = {{1, 0, 0, 0}},
              expected = {{1, 0, 0, 0}}, result;

  tpr_add(value_1, value_2, &result);
  ck_assert_int_eq(tpr_is_equal(result, expected), 1);
}
END_TEST

// sub

START_TEST(test_arith_sub_1) {
  tpr_decimal value_1 = {{0, 0, 0, 0x80000000}};
  tpr_decimal value_2 = {{0, 0, 0, 0}};
  tpr_decimal result = {0};
  int return_value = tpr_sub(value_1, value_2, &result), x = 0;
  tpr_from_decimal_to_int(result, &x);
  ck_assert_int_eq(x, 0);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(test_arith_sub_2) {
  tpr_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  tpr_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  tpr_decimal result = {0};
  int return_value = tpr_sub(value_1, value_2, &result);
  ck_assert_int_eq(
      result.bits[0] + result.bits[1] + result.bits[2] + result.bits[3], 0);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(test_arith_sub_3) {
  tpr_decimal value_1 = {0};
  tpr_decimal value_2 = {0};
  tpr_decimal result = {0};
  tpr_from_int_to_decimal(-888, &value_1);
  tpr_from_int_to_decimal(-21, &value_2);
  int err = tpr_sub(value_1, value_2, &result);
  int int_res = 0;
  tpr_from_decimal_to_int(result, &int_res);
  ck_assert_int_eq(int_res, -867);
  ck_assert_int_eq(err, 0);
}
END_TEST

START_TEST(test_arith_sub_4) {
  tpr_decimal value_1 = {0};
  tpr_decimal value_2 = {0};
  tpr_decimal result = {0};
  tpr_from_int_to_decimal(-100, &value_1);
  tpr_from_int_to_decimal(-500, &value_2);
  int err = tpr_sub(value_1, value_2, &result);
  int int_res = 0;
  tpr_from_decimal_to_int(result, &int_res);
  ck_assert_int_eq(int_res, 400);
  ck_assert_int_eq(err, 0);
}
END_TEST

START_TEST(test_arith_sub_5) {
  tpr_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  tpr_decimal value_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  tpr_decimal result = {0};
  int return_value = tpr_sub(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0] + result.bits[1] + result.bits[2], 0);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(test_arith_sub_6) {
  tpr_decimal value_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  tpr_decimal value_2 = {{1, 1, 1, 0}};
  tpr_decimal result = {0};
  int return_value = tpr_sub(value_1, value_2, &result);
  ck_assert_int_eq(return_value, 2);
}
END_TEST

START_TEST(test_arith_sub_7) {
  tpr_decimal value_1 = {{100, 0, 0, 0}}, value_2 = {{200, 0, 0, 0}},
              expected = {{1900, 0, 0, 0}}, result;
  tpr_set_power(&value_1.bits[3], 2);
  tpr_set_power(&value_2.bits[3], 1);
  tpr_set_power(&expected.bits[3], 2);

  tpr_sub(value_2, value_1, &result);
  ck_assert_int_eq(tpr_is_equal(result, expected), 1);
}
END_TEST

START_TEST(test_arith_sub_8) {
  tpr_decimal a = {{123, 0, 0, 0}}, b = {{456, 0, 0, 0}}, c = {{579, 0, 0, 0}},
              result;
  tpr_set_power(&a.bits[3], 5);
  tpr_set_power(&b.bits[3], 5);
  tpr_set_power(&c.bits[3], 5);
  tpr_set_sign(&b.bits[3], 1);

  tpr_sub(a, b, &result);
  ck_assert_int_eq(tpr_is_equal(result, c), 1);
}
END_TEST

START_TEST(test_arith_sub_9) {
  tpr_decimal value_1 = {0};
  tpr_decimal value_2 = {0};
  tpr_decimal ans;
  value_1.bits[0] = 532167;
  value_1.bits[3] = 196608;

  value_2.bits[0] = 1236;
  value_2.bits[3] = 983040;

  tpr_decimal true_ans = {0};
  true_ans.bits[0] = 607087404;
  true_ans.bits[1] = 123904785;
  true_ans.bits[3] = 983040;
  int result = tpr_sub(value_1, value_2, &ans);
  ck_assert_int_eq(ans.bits[0], true_ans.bits[0]);
  ck_assert_int_eq(ans.bits[1], true_ans.bits[1]);
  ck_assert_int_eq(ans.bits[2], true_ans.bits[2]);
  ck_assert_int_eq(ans.bits[3], true_ans.bits[3]);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(test_arith_sub_10) {
  tpr_decimal value_1 = {{200, 0, 0, 0}}, value_2 = {{100, 0, 0, 0}},
              expected = {{100, 0, 0, 0}}, result;
  tpr_set_power(&value_1.bits[3], 0);
  tpr_set_power(&value_2.bits[3], 0);
  tpr_set_power(&expected.bits[3], 0);

  tpr_sub(value_1, value_2, &result);
  ck_assert_int_eq(tpr_is_equal(result, expected), 1);
}
END_TEST

// mul

START_TEST(test_arith_mul_1) {
  tpr_decimal a = {
      {-1, -1, -1, -2147483648}};     // -79228162514264337593543950335
  tpr_decimal b = {{-1, -1, -1, 0}};  // 79228162514264337593543950335
  tpr_decimal res_bits = {{0, 0, 0, 0}};

  int res = tpr_mul(a, b, &res_bits);

  ck_assert_int_eq(res, 2);
  tpr_decimal check = {{0, 0, 0, 0}};
  ck_assert_int_eq(res_bits.bits[0], check.bits[0]);
  ck_assert_int_eq(res_bits.bits[1], check.bits[1]);
  ck_assert_int_eq(res_bits.bits[2], check.bits[2]);
  ck_assert_int_eq(res_bits.bits[3], check.bits[3]);
  ck_assert_int_eq(tpr_is_equal(res_bits, check), 1);
}
END_TEST

START_TEST(test_arith_mul_2) {
  tpr_decimal value_1, value_2, origin, result;
  int value_type_result, value_type_origin;
  // value_1 = 2;
  // value_2 = 3;
  value_1.bits[0] = 0b00000000000000000000000000000010;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  value_2.bits[0] = 0b00000000000000000000000000000011;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = tpr_mul(value_1, value_2, &result);
  value_type_origin = 0;
  origin.bits[0] = 0b00000000000000000000000000000110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(test_arith_mul_3) {
  tpr_decimal value_1 = {{5, 0, 0, 0}};
  tpr_decimal value_2 = {{1, 0, 0, 0}};
  tpr_decimal result = {0};

  tpr_set_power(&value_1.bits[3], 30);

  int err = tpr_mul(value_1, value_2, &result);

  ck_assert_int_eq(err, 1);
}
END_TEST

START_TEST(test_arith_mul_4) {
  tpr_decimal value_1 = {{2, 0, 0, 0}};
  tpr_decimal value_2 = {{-1, -1, -1, 0}};
  tpr_decimal result = {0};

  tpr_set_power(&value_1.bits[3], 2);

  int err = tpr_mul(value_1, value_2, &result);

  ck_assert_int_eq(err, 0);
}
END_TEST

START_TEST(test_arith_mul_11) {
  tpr_decimal src1, src2;
  int value_type_result, value_type_origin;
  src1.bits[0] = 0b11111111111111111111111111111111;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;
  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b10000000000000000000000000000000;
  value_type_result = tpr_mul(src1, src2, NULL);
  value_type_origin = 1;
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(test_arith_mul_5) {
  tpr_decimal value_1 = {0}, value_2 = {0}, origin = {0}, result = {0};
  int value_type_result = 0, value_type_origin = 0;

  value_1.bits[0] = 0b00010100010100100100001010001010;
  value_1.bits[1] = 0b00000001110010010010111111110100;
  value_1.bits[2] = 0b00101010001000010010010000000001;
  value_1.bits[3] = 0b00000000000000000000000000000000;

  value_2.bits[0] = 0b00000000000000000000000000000000;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = tpr_mul(value_1, value_2, &result);
  value_type_origin = 0;

  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(test_arith_mul_6) {
  tpr_decimal value_1 = {0}, value_2 = {0}, origin = {0}, result = {0};
  int value_type_result = 0, value_type_origin = 0;
  //
  value_1.bits[0] = 0b00000100100011000100101100000000;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000001001001001000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  //
  value_2.bits[0] = 0b00000000000000000000000000000000;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = tpr_mul(value_1, value_2, &result);
  value_type_origin = 0;
  //
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(test_arith_mul_7) {
  tpr_decimal value_1, value_2, result;
  int value_type_result, value_type_origin;
  value_1.bits[0] = 0b11111111111111111111111111111111;
  value_1.bits[1] = 0b11111111111111111111111111111111;
  value_1.bits[2] = 0b11111111111111111111111111111111;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  value_2.bits[0] = 0b11111111111111111111111111111111;
  value_2.bits[1] = 0b11111111111111111111111111111111;
  value_2.bits[2] = 0b11111111111111111111111111111111;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = tpr_mul(value_1, value_2, &result);
  value_type_origin = 1;
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(test_arith_mul_8) {
  tpr_decimal value_1 = {{8, 0, 0, 0}};
  tpr_decimal value_2 = {{2, 0, 0, 0}};
  tpr_decimal result = {{0}};
  ck_assert_int_eq(0, tpr_mul(value_1, value_2, &result));
}
END_TEST

START_TEST(test_arith_mul_9) {
  tpr_decimal value_1 = {0}, value_2 = {0}, origin = {0}, result = {0};
  int value_type_result = 0, value_type_origin = 0;
  // 27
  value_1.bits[0] = 0b00000000000000000000000000011011;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  // 19
  value_2.bits[0] = 0b00000000000000000000000000010011;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = tpr_mul(value_1, value_2, &result);
  value_type_origin = 0;
  // 513
  origin.bits[0] = 0b00000000000000000000001000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(test_arith_mul_10) {
  tpr_decimal value_1 = {0}, value_2 = {0}, origin = {0}, result = {0};
  int value_type_result = 0, value_type_origin = 0;
  // 2668745618745983003
  value_1.bits[0] = 0b00101001001111000000000000011011;
  value_1.bits[1] = 0b00100101000010010100101000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  // 275
  value_2.bits[0] = 0b00000000000000000000000100010011;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  value_type_result = tpr_mul(value_1, value_2, &result);
  value_type_origin = 0;
  // 733905045155145325825
  origin.bits[0] = 0b01001011011101000001110100000001;
  origin.bits[1] = 0b11001000111110100111111000101100;
  origin.bits[2] = 0b00000000000000000000000000100111;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

// div

START_TEST(test_arith_div_1) {
  tpr_decimal value_1 = {{2, 0, 0, 0}};
  tpr_decimal value_2 = {{0, 0, 0, 0}};
  tpr_decimal result = {{0}};
  ck_assert_int_eq(3, tpr_div(value_1, value_2, &result));
}
END_TEST

START_TEST(test_arith_div_2) {
  tpr_decimal value_1 = {{15, 0, 0, 0}};
  tpr_decimal value_2 = {{0, 0, 0, 0}};
  tpr_decimal result = {{0, 0, 0, 0}};
  tpr_decimal check = {{0, 0, 0, 0}};
  int return_value = tpr_div(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
  ck_assert_int_eq(return_value, 3);
}
END_TEST

START_TEST(test_arith_div_3) {
  tpr_decimal value_1 = {0}, value_2 = {0}, result = {0};
  int value_type_result = 0, value_type_origin = 0;
  float a = 65224, b = 23512;
  tpr_from_float_to_decimal(a, &value_1);
  tpr_from_float_to_decimal(b, &value_2);
  float res = 0, origin_res = a / b;
  value_type_result = tpr_div(value_1, value_2, &result);
  value_type_origin = 0;
  tpr_from_decimal_to_float(result, &res);
  ck_assert_float_eq(res, origin_res);
  ck_assert_int_eq(value_type_result, value_type_origin);
}
END_TEST

START_TEST(test_arith_div_4) {
  tpr_decimal value_1, value_2, result, origin;

  value_1.bits[0] = 0b00000000000000000000000000000000;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  value_2.bits[0] = 0b00000000000000000000000000001111;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000110000000000000000;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = tpr_div(value_1, value_2, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
}
END_TEST

START_TEST(test_arith_div_5) {
  tpr_decimal value_1, value_2, result;

  value_1.bits[0] = 0b00000000000000000000000000000011;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  value_2.bits[0] = 0b00000000000000000000000000000010;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;
  int check = tpr_div(value_1, value_2, &result);
  int check_origin = 0;
  ck_assert_int_eq(check_origin, check);
}
END_TEST

START_TEST(test_arith_div_6) {
  tpr_decimal value_1, value_2, result;

  value_1.bits[0] = 0b00000000000000000000000000000001;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  value_2.bits[0] = 0b00000000000000000000000000000000;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000000000000000000000;

  int check = tpr_div(value_1, value_2, &result);
  int check_origin = 3;
  ck_assert_int_eq(check, check_origin);
}
END_TEST

START_TEST(test_arith_div_7) {
  tpr_decimal value_1, value_2, result, origin;

  value_1.bits[0] = 0b00000000000000000000000000000000;
  value_1.bits[1] = 0b00000000000000000000000000000000;
  value_1.bits[2] = 0b00000000000000000000000000000000;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  value_2.bits[0] = 0b00000111100000000000000000001111;
  value_2.bits[1] = 0b00000001100000000000000000100000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000000110000000000000000;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int check = tpr_div(value_1, value_2, &result);
  int check_origin = 0;
  ck_assert_int_eq(check, check_origin);
  ck_assert_int_eq(result.bits[3], origin.bits[3]);
  ck_assert_int_eq(result.bits[2], origin.bits[2]);
  ck_assert_int_eq(result.bits[1], origin.bits[1]);
  ck_assert_int_eq(result.bits[0], origin.bits[0]);
}
END_TEST

START_TEST(test_arith_div_8) {
  tpr_decimal value_1, value_2, result = {0};
  float a = -115.2;
  float b = 0.0;
  tpr_from_float_to_decimal(a, &value_1);
  tpr_from_float_to_decimal(b, &value_2);
  int check = tpr_div(value_1, value_2, &result);
  int check_origin = 3;
  ck_assert_int_eq(check_origin, check);
  ck_assert_int_eq(result.bits[3], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[0], 0);
}
END_TEST

START_TEST(test_arith_div_9) {
  tpr_decimal value_1 = {{1, 0, 0, 0}};
  tpr_decimal value_2 = {{0, 0, 2147483648, 0}};
  tpr_set_sign(&value_1.bits[3], 1);

  tpr_decimal result = {{0, 0, 0, 0}};

  int return_value = tpr_div(value_1, value_2, &result);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(test_arith_div_11) {
  tpr_decimal value_1, value_2, result = {{0}};
  value_1.bits[0] = 0b11111111111111111111111111111111;
  value_1.bits[1] = 0b11111111111111111111111111111111;
  value_1.bits[2] = 0b11111111111111111111111111111111;
  value_1.bits[3] = 0b00000000000000000000000000000000;
  value_2.bits[0] = 0b00000000000000000000000000000001;
  value_2.bits[1] = 0b00000000000000000000000000000000;
  value_2.bits[2] = 0b00000000000000000000000000000000;
  value_2.bits[3] = 0b00000000000111000000000000000000;
  int check = tpr_div(value_1, value_2, &result);
  int check_origin = 1;
  ck_assert_int_eq(check, check_origin);
  ck_assert_int_eq(result.bits[3], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[0], 0);
}
END_TEST

START_TEST(test_arith_div_10) {
  tpr_decimal value_1 = {{0, 0, 0, 0}};
  tpr_decimal value_2 = {{0, 0, 0, 0}};
  tpr_decimal result = {{0}};
  ck_assert_int_eq(3, tpr_div(value_1, value_2, &result));
}
END_TEST

START_TEST(test_arith_div_13) {
  tpr_decimal src1, src2, result = {0};
  float a = -2147483648;
  float b = 0.0;
  tpr_from_float_to_decimal(a, &src1);
  tpr_from_float_to_decimal(b, &src2);
  int check = tpr_div(src1, src2, &result);
  int check_origin = 3;
  ck_assert_int_eq(check_origin, check);
  ck_assert_int_eq(result.bits[3], 0);
  ck_assert_int_eq(result.bits[2], 0);
  ck_assert_int_eq(result.bits[1], 0);
  ck_assert_int_eq(result.bits[0], 0);
}
END_TEST

// float to decimal

START_TEST(test_convertors_6) {
  float num = 821821;
  tpr_decimal res_bits = {{0, 0, 0, 0}};

  int result = tpr_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq((int)result, 0);
  ck_assert_int_eq((int)res_bits.bits[0], 821821);
  ck_assert_int_eq((int)res_bits.bits[1], 0);
  ck_assert_int_eq((int)res_bits.bits[2], 0);
  ck_assert_int_eq((int)res_bits.bits[3], 0);
}
END_TEST

START_TEST(test_convertors_7) {
  float num = 912479.2;

  int result = tpr_from_float_to_decimal(num, NULL);

  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_convertors_8) {
  float num = 1e-29;
  tpr_decimal res_bits = {{0, 0, 0, 0}};

  int result = tpr_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq(result, 1);
}
END_TEST

START_TEST(test_convertors_9) {
  float num = 0;
  tpr_decimal res_bits = {{0, 0, 0, 0}};

  int res = tpr_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq((int)res, 0);
  ck_assert_int_eq((int)res_bits.bits[0], 0);
  ck_assert_int_eq((int)res_bits.bits[1], 0);
  ck_assert_int_eq((int)res_bits.bits[2], 0);
  ck_assert_int_eq((int)res_bits.bits[3], 0);
}
END_TEST

START_TEST(test_convertors_10) {
  float num = -821821;
  tpr_decimal res_bits = {{0, 0, 0, 0}};

  int res = tpr_from_float_to_decimal(num, &res_bits);

  ck_assert_int_eq((int)res, 0);
  ck_assert_int_eq((int)res_bits.bits[0], 821821);
  ck_assert_int_eq((int)res_bits.bits[1], 0);
  ck_assert_int_eq((int)res_bits.bits[2], 0);
  ck_assert_int_eq(res_bits.bits[3] & 0x80000000, 0x80000000);
}
END_TEST

// tpr_floor

START_TEST(other_functions_1) {
  float num;
  float *pnum = &num;
  tpr_decimal value = {{257, 0, 0, 0}};
  tpr_decimal result = {0};
  tpr_set_power(&value.bits[3], 1);
  tpr_floor(value, &result);
  tpr_from_decimal_to_float(result, pnum);
  ck_assert_float_eq(25, num);
}
END_TEST

START_TEST(other_functions_2) {
  tpr_decimal value = {{0, 12345, 6789, 0}}, result = {{0, 12345, 6789, 0}};
  tpr_decimal floor_value = {0};

  tpr_floor(value, &floor_value);
  ck_assert_int_eq(tpr_is_equal(floor_value, result), 1);
}
END_TEST

START_TEST(other_functions_3) {
  tpr_decimal value = {{2147483648, 12345, 6789, 0}},
              result = {{2147483648, 12345, 6789, 0}};
  tpr_decimal floor_value = {0};

  tpr_floor(value, &floor_value);
  ck_assert_int_eq(tpr_is_equal(floor_value, result), 1);
}
END_TEST

START_TEST(other_functions_4) {
  float num;
  float *pnum = &num;
  tpr_decimal value = {{257, 0, 0, 0}};
  tpr_decimal result = {0};
  tpr_set_power(&value.bits[3], 1);
  tpr_floor(value, &result);
  tpr_from_decimal_to_float(result, pnum);
  ck_assert_float_eq(25, num);
}
END_TEST

START_TEST(other_functions_5) {
  float num;
  float *pnum = &num;
  tpr_decimal value = {{1000, 0, 0, 0}};
  tpr_decimal result = {0};
  tpr_set_sign(&value.bits[3], 1);
  tpr_set_power(&value.bits[3], 2);
  tpr_floor(value, &result);
  tpr_from_decimal_to_float(result, pnum);
  ck_assert_float_eq(-10, num);
}
END_TEST

// tpr_round

START_TEST(other_functions_6) {
  tpr_decimal value = {{115, 0, 0, 0}};
  tpr_decimal result = {{0}};
  tpr_set_power(&value.bits[3], 1);
  ck_assert_int_eq(0, tpr_round(value, &result));
}
END_TEST

START_TEST(other_functions_7) {
  tpr_decimal value = {{2147483648, 12345, 6789, 0}},
              result = {{2147483648, 12345, 6789, 0}};
  tpr_decimal round_value = {0};

  tpr_round(value, &round_value);
  ck_assert_int_eq(tpr_is_equal(round_value, result), 1);
}
END_TEST

START_TEST(other_functions_8) {
  float num;
  float *pnum = &num;
  tpr_decimal value = {{8888, 0, 0, 0}};
  tpr_decimal result = {0};
  tpr_set_sign(&value.bits[3], 1);
  tpr_set_power(&value.bits[3], 1);
  tpr_round(value, &result);
  tpr_from_decimal_to_float(result, pnum);
  ck_assert_float_eq(-889, num);
}
END_TEST

START_TEST(other_functions_9) {
  float num;
  float *pnum = &num;
  tpr_decimal value = {{1000, 0, 0, 0}};
  tpr_decimal result = {0};
  tpr_set_sign(&value.bits[3], 1);
  tpr_set_power(&value.bits[3], 2);
  tpr_round(value, &result);
  tpr_from_decimal_to_float(result, pnum);
  ck_assert_float_eq(-10, num);
}
END_TEST

START_TEST(other_functions_10) {
  tpr_decimal value = {{21, 0, 0, 0}};
  tpr_decimal result = {{0}};
  tpr_set_power(&value.bits[3], 1);
  ck_assert_int_eq(0, tpr_round(value, &result));
}
END_TEST

// tpr_truncate

START_TEST(other_functions_11) {
  float num;
  float *pnum = &num;
  tpr_decimal value = {{1000, 0, 0, 0}};
  tpr_decimal result = {0};
  tpr_set_sign(&value.bits[3], 1);
  tpr_set_power(&value.bits[3], 0);
  tpr_truncate(value, &result);
  tpr_from_decimal_to_float(result, pnum);
  ck_assert_float_eq(-1000, num);
}
END_TEST

START_TEST(other_functions_12) {
  float num;
  float *pnum = &num;
  tpr_decimal value = {{0, 0, 0, 0}};
  tpr_decimal result = {0};
  tpr_set_power(&value.bits[3], 2);
  tpr_truncate(value, &result);
  tpr_from_decimal_to_float(result, pnum);
  ck_assert_float_eq(0, num);
}
END_TEST

START_TEST(other_functions_13) {
  float num;
  float *pnum = &num;
  tpr_decimal value = {{88888888, 0, 0, 0}};
  tpr_decimal result = {0};
  tpr_set_power(&value.bits[3], 4);
  tpr_truncate(value, &result);
  tpr_from_decimal_to_float(result, pnum);
  ck_assert_float_eq(8888, num);
}
END_TEST

START_TEST(other_functions_14) {
  float num;
  float *pnum = &num;
  tpr_decimal value = {{255, 0, 0, 0}};
  tpr_decimal result = {0};
  tpr_set_power(&value.bits[3], 2);
  tpr_truncate(value, &result);
  tpr_from_decimal_to_float(result, pnum);
  ck_assert_float_eq(2, num);
}
END_TEST

START_TEST(other_functions_15) {
  float num;
  float *pnum = &num;
  tpr_decimal value = {{2555, 0, 0, 0}};
  tpr_decimal result = {0};
  tpr_set_sign(&value.bits[3], 1);
  tpr_set_power(&value.bits[3], 1);
  tpr_truncate(value, &result);
  tpr_from_decimal_to_float(result, pnum);
  ck_assert_float_eq(-255, num);
}
END_TEST

//////////////////////////////////////////

START_TEST(tsub_0) {
  tpr_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{2, 0, 0, 0}};
  tpr_decimal res;
  ck_assert_int_eq(0, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(tsub_1) {
  tpr_decimal val1 = {{2, 0, 0, 0}};
  tpr_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res;
  ck_assert_int_eq(0, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(tsub_2) {
  tpr_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res;
  ck_assert_int_eq(0, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(tsub_3) {
  tpr_decimal val1 = {{2, 0, 0, 0}};
  tpr_decimal val2 = {{2, 0, 0, 0}};
  tpr_decimal res;
  ck_assert_int_eq(0, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(tsub_4) {
  tpr_decimal val1 = {{8, 0, 0, 0}};
  tpr_decimal val2 = {{2, 0, 0, 0}};
  tpr_decimal res;
  ck_assert_int_eq(0, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(tsub_5) {
  tpr_decimal val1 = {{2, 0, 0, 0}};
  tpr_decimal val2 = {{8, 0, 0, 0}};
  tpr_decimal res;
  ck_assert_int_eq(0, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(tsub_6) {
  tpr_decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{2, 0, 0, 0}};
  tpr_decimal res;
  ck_assert_int_eq(0, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(tsub_7) {
  tpr_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{8, 0, 0, 0}};
  tpr_decimal res;
  ck_assert_int_eq(0, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(tsub_8) {
  tpr_decimal val1 = {{2, 0, 0, 0}};
  tpr_decimal val2 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res;
  ck_assert_int_eq(0, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(tsub_9) {
  tpr_decimal val1 = {{8, 0, 0, 0}};
  tpr_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res;
  ck_assert_int_eq(0, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(tsub_10) {
  tpr_decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{0}};
  tpr_decimal res;
  ck_assert_int_eq(0, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(tsub_11) {
  tpr_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{4, 0, 0, 0}};
  tpr_decimal res;
  ck_assert_int_eq(2, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(tsub_12) {
  tpr_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  tpr_decimal val2 = {{4, 0, 0, 0}};
  tpr_decimal res;
  ck_assert_int_eq(0, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(tsub_13) {
  tpr_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res;
  ck_assert_int_eq(0, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(tsub_14) {
  tpr_decimal val1 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  tpr_decimal res;
  ck_assert_int_eq(2, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(tsub_15) {
  tpr_decimal val1 = {{4, 0, 0, 0}};
  tpr_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  tpr_decimal res;
  ck_assert_int_eq(0, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(tsub_16) {
  tpr_decimal val1 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  tpr_decimal res;
  ck_assert_int_eq(0, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(tsub_17) {
  int true_res = 0;
  tpr_decimal val1 = {{890373317, 1664736595, 2742755499U, 2148204544U}};
  tpr_decimal val2 = {{3230206353U, 3918853780U, 4043671449U, 2147483648U}};
  tpr_decimal val3 = {{189631616, 3801053329U, 4043671449U, 0x00000000}};
  tpr_decimal output;
  int tpr_res = tpr_sub(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(output.bits[i], val3.bits[i]);
  ck_assert_int_eq(tpr_res, true_res);
}
END_TEST

START_TEST(tsub_18) {
  int true_res = 0;
  tpr_decimal val1 = {{900961119, 2623149003U, 2341027622U, 2148597760U}};
  tpr_decimal val2 = {{2096648231, 1368807658, 3501119840U, 1179648}};
  tpr_decimal result = {{251632483, 2760029769U, 2691139606U, 2148597760U}};
  tpr_decimal output = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  int tpr_res = tpr_sub(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(tpr_res, true_res);
}
END_TEST

START_TEST(tsub_19) {
  tpr_decimal val1 = {{4, 0, 0, 0}};
  tpr_decimal val2 = {{4, 0, 0, 0}};
  tpr_decimal res;
  ck_assert_int_eq(0, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(tsub_20) {
  tpr_decimal dec1;
  tpr_decimal dec2;
  int tmp1 = 100;
  int tmp2 = 99999;
  int res_s21 = 0;
  int res = -99899;
  tpr_decimal res1;
  tpr_from_int_to_decimal(tmp1, &dec1);
  tpr_from_int_to_decimal(tmp2, &dec2);
  tpr_sub(dec1, dec2, &res1);
  tpr_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(tsub_21) {
  tpr_decimal dec1;
  tpr_decimal dec2;
  int tmp1 = -100;
  int tmp2 = -99999;
  int res_s21 = 0;
  tpr_decimal res1;
  int res = 99899;
  tpr_from_int_to_decimal(tmp1, &dec1);
  tpr_from_int_to_decimal(tmp2, &dec2);
  tpr_sub(dec1, dec2, &res1);
  tpr_from_decimal_to_int(res1, &res_s21);
  ck_assert_int_eq(res_s21, res);
}
END_TEST

START_TEST(tsub_22) {
  tpr_decimal val1 = {{2, 0, 0, 0}};
  tpr_decimal val2 = {{0, 0, 0, 0}};
  tpr_decimal res = {{0}};
  val2.bits[3] = 0xFFFFFFFF;
  ck_assert_int_eq(ERROR, tpr_sub(val1, val2, &res));
}
END_TEST

START_TEST(tsub_23) {
  tpr_decimal val1 = {{2, 0, 0, 0}};
  tpr_decimal val2 = {{0, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(OK, tpr_sub(val1, val2, &res));
  ck_assert_int_eq(val1.bits[0], res.bits[0]);
}
END_TEST

START_TEST(tadd_0) {
  tpr_decimal val1 = {{15, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{2, 0, 0, 0}};
  tpr_decimal res;
  ck_assert_int_eq(0, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(tadd_1) {
  tpr_decimal val1 = {{15, 0, 0, 0}};
  tpr_decimal val2 = {{15, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res;
  ck_assert_int_eq(0, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(tadd_2) {
  tpr_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  tpr_decimal val2 = {{1, 0, 0, 0}};
  tpr_decimal res;
  ck_assert_int_eq(1, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(tadd_4) {
  tpr_decimal val1 = {{8, 0, 0, 0}};
  tpr_decimal val2 = {{2, 0, 0, 0}};
  tpr_decimal res;
  ck_assert_int_eq(0, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(tadd_5) {
  tpr_decimal val1 = {{2, 0, 0, 0}};
  tpr_decimal val2 = {{8, 0, 0, 0}};
  tpr_decimal res;
  ck_assert_int_eq(0, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(tadd_6) {
  tpr_decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{2, 0, 0, 0}};
  tpr_decimal res;
  ck_assert_int_eq(0, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(tadd_7) {
  tpr_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{8, 0, 0, 0}};
  tpr_decimal res;
  ck_assert_int_eq(0, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(tadd_8) {
  tpr_decimal val1 = {{0}};
  tpr_decimal val2 = {{0}};
  tpr_decimal res;
  ck_assert_int_eq(0, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(tadd_9) {
  tpr_decimal val1 = {{4, 0, 0, 0}};
  tpr_decimal val2 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res;
  ck_assert_int_eq(0, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(tadd_10) {
  tpr_decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{0}};
  tpr_decimal res;
  ck_assert_int_eq(0, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(tadd_11) {
  tpr_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{4, 0, 0, 0}};
  tpr_decimal res;
  ck_assert_int_eq(0, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(tadd_13) {
  tpr_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  tpr_decimal val2 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res;
  ck_assert_int_eq(0, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(tadd_14) {
  tpr_decimal val1 = {{4, 0, 0, 0}};
  tpr_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  tpr_decimal res;
  ck_assert_int_eq(0, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(tadd_15) {
  tpr_decimal val1 = {{4, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  tpr_decimal res;
  ck_assert_int_eq(0, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(tadd_17) {
  tpr_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  tpr_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  tpr_set_power(&val1.bits[3], 5);
  tpr_set_power(&val2.bits[3], 3);
  tpr_decimal res;
  ck_assert_int_eq(0, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(tadd_18) {
  tpr_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  tpr_set_power(&val1.bits[3], 5);
  tpr_set_power(&val2.bits[3], 3);
  tpr_decimal res;
  ck_assert_int_eq(0, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(tadd_19) {
  tpr_decimal val1 = {{2, 0, 0, 0}};
  tpr_decimal val2 = {{0, 0, 0, 0}};
  tpr_decimal res = {{0}};
  val2.bits[3] = 0xFFFFFFFF;
  ck_assert_int_eq(ERROR, tpr_add(val1, val2, &res));
}
END_TEST

START_TEST(tadd_20) {
  tpr_decimal val1 = {{2, 0, 0, 0}};
  tpr_decimal val2 = {{0, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(OK, tpr_add(val1, val2, &res));
  ck_assert_int_eq(val1.bits[0], res.bits[0]);
}
END_TEST

START_TEST(tmul_0) {
  tpr_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{2, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_mul(val1, val2, &res));
}
END_TEST

START_TEST(tmul_1) {
  tpr_decimal val1 = {{2, 0, 0, 0}};
  tpr_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_mul(val1, val2, &res));
}
END_TEST

START_TEST(tmul_2) {
  tpr_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_mul(val1, val2, &res));
}
END_TEST

START_TEST(tmul_3) {
  tpr_decimal val1 = {{2, 0, 0, 0}};
  tpr_decimal val2 = {{2, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_mul(val1, val2, &res));
}
END_TEST

START_TEST(tmul_4) {
  tpr_decimal val1 = {{8, 0, 0, 0}};
  tpr_decimal val2 = {{2, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_mul(val1, val2, &res));
}
END_TEST

START_TEST(tmul_5) {
  tpr_decimal val1 = {{2, 0, 0, 0}};
  tpr_decimal val2 = {{8, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_mul(val1, val2, &res));
}
END_TEST

START_TEST(tmul_6) {
  tpr_decimal val1 = {{8, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{2, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_mul(val1, val2, &res));
}
END_TEST

START_TEST(tmul_7) {
  tpr_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{8, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_mul(val1, val2, &res));
}
END_TEST

START_TEST(tmul_8) {
  tpr_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(1, tpr_mul(val1, val2, &res));
}
END_TEST

START_TEST(tmul_9) {
  tpr_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{2, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(2, tpr_mul(val1, val2, &res));
}
END_TEST

START_TEST(tmul_10) {
  tpr_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  tpr_decimal val2 = {{2, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(1, tpr_mul(val1, val2, &res));
}
END_TEST

START_TEST(tmul_11) {
  tpr_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{0, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_mul(val1, val2, &res));
}
END_TEST

START_TEST(tmul_12) {
  tpr_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{2, 0, 0, 0}};
  tpr_decimal res = {{0}};
  tpr_set_power(&val1.bits[3], 1);
  ck_assert_int_eq(0, tpr_mul(val1, val2, &res));
}
END_TEST

START_TEST(tmul_13) {
  int true_res = 0;
  tpr_decimal val1 = {{100, 0, 0, 0}};
  tpr_decimal val2 = {{10, 0, 0, 0}};
  tpr_decimal output;
  tpr_decimal result = {{1000, 0, 0, 0}};
  int tpr_res = tpr_mul(val1, val2, &output);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(result.bits[i], output.bits[i]);
  ck_assert_int_eq(tpr_res, true_res);
}
END_TEST

START_TEST(tmul_14) {
  tpr_decimal val2 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  tpr_decimal val1 = {{20, 0, 0, 0}};
  tpr_decimal res = {{0}};
  tpr_set_power(&val2.bits[3], 1);
  tpr_set_power(&val2.bits[3], 2);
  ck_assert_int_eq(0, tpr_mul(val1, val2, &res));
}
END_TEST

START_TEST(tmul_15) {
  tpr_decimal val1 = {{2, 0, 0, 0}};
  tpr_decimal val2 = {{0, 0, 0, 0}};
  tpr_decimal res = {{0}};
  val2.bits[3] = 0xFFFFFFFF;
  ck_assert_int_eq(ERROR, tpr_mul(val1, val2, &res));
}
END_TEST

START_TEST(tmul_16) {
  tpr_decimal val1 = {{2, 0, 0, 0}};
  tpr_decimal val2 = {{0, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(OK, tpr_mul(val1, val2, &res));
  ck_assert_int_eq(0, res.bits[0]);
}
END_TEST

START_TEST(tdiv_0) {
  tpr_decimal val1 = {{2, 0, 0, 0}};
  tpr_decimal val2 = {{2, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_div(val1, val2, &res));
}
END_TEST

START_TEST(tdiv_1) {
  tpr_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{2, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_div(val1, val2, &res));
}
END_TEST

START_TEST(tdiv_2) {
  tpr_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_div(val1, val2, &res));
}
END_TEST

START_TEST(tdiv_3) {
  tpr_decimal val1 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal val2 = {{0, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(3, tpr_div(val1, val2, &res));
}
END_TEST

START_TEST(tdiv_4) {
  tpr_decimal val1 = {{2, 0, 0, 0}};
  tpr_decimal val2 = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(0, tpr_div(val1, val2, &res));
}
END_TEST

START_TEST(tdiv_5) {
  tpr_decimal val1 = {{5, 0, 0, 0}};
  tpr_decimal val2 = {{5, 0, 0, 0}};
  tpr_decimal res = {{0}};
  tpr_decimal expected = {{1, 0, 0, 0}};
  ck_assert_int_eq(0, tpr_div(val1, val2, &res));
  ck_assert_int_eq(res.bits[0], expected.bits[0]);
  ck_assert_int_eq(res.bits[1], expected.bits[1]);
  ck_assert_int_eq(res.bits[2], expected.bits[2]);
  ck_assert_int_eq(res.bits[3], expected.bits[3]);
}
END_TEST

START_TEST(tdiv_6) {
  tpr_decimal val1 = {{2, 0, 0, 0}};
  tpr_decimal val2 = {{0, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(3, tpr_div(val1, val2, &res));
}
END_TEST

START_TEST(tdiv_7) {
  tpr_decimal val1 = {{UINT_MAX, 0, 0, 0}};
  tpr_decimal val2 = {{5, 0, 0, 0x80000000}};
  tpr_decimal res = {{0}};
  tpr_decimal expected = {{UINT_MAX / 5, 0, 0, 0x80000000}};
  ck_assert_int_eq(0, tpr_div(val1, val2, &res));
  ck_assert_uint_eq(expected.bits[0], res.bits[0]);
  ck_assert_uint_eq(expected.bits[1], res.bits[1]);
  ck_assert_uint_eq(expected.bits[2], res.bits[2]);
  ck_assert_uint_eq(expected.bits[3], res.bits[3]);
}
END_TEST

START_TEST(tdiv_8) {
  ck_assert_int_eq(0, 0);
}
END_TEST

START_TEST(tdiv_9) {
  tpr_decimal val1 = {{UINT_MAX, UINT_MAX, UINT_MAX, 0}};
  tpr_decimal val2 = {{1, 0, 0, 0x80000000}};
  tpr_decimal res = {{0}};
  tpr_decimal expected = {{UINT_MAX, UINT_MAX, UINT_MAX, 0x80000000}};
  ck_assert_int_eq(0, tpr_div(val1, val2, &res));

  ck_assert_uint_eq(expected.bits[0], res.bits[0]);
  ck_assert_uint_eq(expected.bits[1], res.bits[1]);
  ck_assert_uint_eq(expected.bits[2], res.bits[2]);
  ck_assert_uint_eq(expected.bits[3], res.bits[3]);
}
END_TEST

START_TEST(tdiv_10) {
  tpr_decimal val1 = {{2, 0, 0, 0}};
  tpr_decimal val2 = {{0, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(3, tpr_div(val1, val2, &res));
}
END_TEST

START_TEST(tdiv_11) {
  tpr_decimal val1 = {{2, 0, 0, 0}};
  tpr_decimal val2 = {{0, 0, 0, 0}};
  tpr_decimal res = {{0}};
  val2.bits[3] = 0xFFFFFFFF;
  ck_assert_int_eq(ERROR, tpr_div(val1, val2, &res));
}
END_TEST

START_TEST(tdiv_12) {
  tpr_decimal val1 = {{2, 0, 0, 0}};
  tpr_decimal val2 = {{1, 0, 0, 0}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(OK, tpr_div(val1, val2, &res));
  ck_assert_int_eq(val1.bits[0], res.bits[0]);
}
END_TEST

START_TEST(tdiv_13) {
  tpr_decimal val1 = {{2, 0, 0, 0}};
  tpr_decimal val2 = {{2, 0, 0, 0x80000000}};
  tpr_decimal res = {{0}};
  ck_assert_int_eq(OK, tpr_div(val1, val2, &res));
  ck_assert_int_eq(1, res.bits[0]);
  ck_assert_int_eq(val2.bits[3], res.bits[3]);
}
END_TEST

START_TEST(tdiv_14) {
  tpr_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  tpr_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  tpr_decimal res = {{0}};
  int code = tpr_div(decimal1, decimal2, &res);
  ck_assert_int_eq(code, OK);
  ck_assert_int_eq(res.bits[0], 1);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
}
END_TEST

START_TEST(truncate_zero) {
  tpr_decimal val = {{0, 0, 0, 0}};
  tpr_decimal res = {0};
  ck_assert_int_eq(0, tpr_truncate(val, &res));
  float fres = 0;
  tpr_from_decimal_to_float(res, &fres);
  float need = 0.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(truncate_small_int) {
  tpr_decimal val = {{12345678, 0, 0, 0}};
  tpr_decimal res = {0};
  ck_assert_int_eq(0, tpr_truncate(val, &res));
  float fres = 0;
  tpr_from_decimal_to_float(res, &fres);
  float need = 12345678.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(truncate_large_negative) {
  tpr_decimal val = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  tpr_decimal res = {0};
  ck_assert_int_eq(0, tpr_truncate(val, &res));
  float fres = 0;
  tpr_from_decimal_to_float(res, &fres);
  float need = -79228162514264337593543950335.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(truncate_negative_with_scale) {
  tpr_decimal val = {{987654321, 0, 0, 0x80090000}};
  tpr_decimal res = {0};
  ck_assert_int_eq(0, tpr_truncate(val, &res));
  float fres = 0;
  tpr_from_decimal_to_float(res, &fres);
  float need = 0.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(truncate_with_scale) {
  tpr_decimal val = {{987654321, 0, 0, 0x00090000}};
  tpr_decimal res = {0};
  ck_assert_int_eq(0, tpr_truncate(val, &res));
  float fres = 0;
  tpr_from_decimal_to_float(res, &fres);
  float need = 0.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(truncate_fraction_large_scale) {
  tpr_decimal val = {{123456789, 0, 0, 0x00180000}};
  tpr_decimal res = {0};
  ck_assert_int_eq(0, tpr_truncate(val, &res));
  float fres = 0;
  tpr_from_decimal_to_float(res, &fres);
  float need = 0.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(truncate_positive_fraction) {
  tpr_decimal val = {{987654321, 0, 0, 0x00050000}};
  tpr_decimal res = {0};
  ck_assert_int_eq(0, tpr_truncate(val, &res));
  float fres = 0;
  tpr_from_decimal_to_float(res, &fres);
  float need = 9876.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(truncate_min_positive_fraction) {
  tpr_decimal val = {{1, 0, 0, 0x001C0000}};
  tpr_decimal res = {0};
  ck_assert_int_eq(0, tpr_truncate(val, &res));
  float fres = 0;
  tpr_from_decimal_to_float(res, &fres);
  float need = 0.0;
  ck_assert_float_eq(need, fres);
}
END_TEST

START_TEST(tfloor_0) {
  tpr_decimal val = {{2, 0, 0, 0}};
  tpr_decimal res = {0};
  ck_assert_int_eq(0, tpr_floor(val, &res));
}
END_TEST

START_TEST(tfloor_1) {
  tpr_decimal val = {{2, 0, 0, ~(UINT_MAX / 2)}};
  tpr_decimal res = {0};
  tpr_set_power(&val.bits[3], 5);
  tpr_floor(val, &res);
  float fres = 0;
  tpr_from_decimal_to_float(res, &fres);
  ck_assert_float_eq(-1, fres);
}
END_TEST

START_TEST(tfloor_2) {
  tpr_decimal val = {{2, 0, 0, 0}};
  tpr_decimal res = {0};
  tpr_set_power(&val.bits[3], 5);
  tpr_floor(val, &res);
  float fres = 0;
  tpr_from_decimal_to_float(res, &fres);
  ck_assert_float_eq(0, fres);
}
END_TEST

START_TEST(tfloor_3) {
  tpr_decimal val = {{15, 0, 0, 0}};
  tpr_decimal res = {0};
  tpr_set_power(&val.bits[3], 1);
  tpr_floor(val, &res);
  float fres = 0;
  tpr_from_decimal_to_float(res, &fres);
  ck_assert_float_eq(1, fres);
}
END_TEST

START_TEST(tfloor_4) {
  tpr_decimal val = {{157, 0, 0, 0}};
  tpr_decimal res = {0};
  tpr_set_power(&val.bits[3], 2);
  tpr_floor(val, &res);
  float fres = 0;
  tpr_from_decimal_to_float(res, &fres);
  ck_assert_float_eq(1, fres);
}
END_TEST

START_TEST(tfloor_5) {
  tpr_decimal val = {{35, 0, 0, 0}};
  tpr_decimal res = {0};
  tpr_set_power(&val.bits[3], 1);
  tpr_set_sign(&val.bits[3], 1);
  tpr_floor(val, &res);
  float fres = 0;
  tpr_from_decimal_to_float(res, &fres);
  ck_assert_float_eq(-4, fres);
}
END_TEST

START_TEST(tfloor_6) {
  tpr_decimal val = {{823, 0, 0, 0}};
  tpr_decimal res = {0};
  tpr_set_power(&val.bits[3], 2);
  tpr_set_sign(&val.bits[3], 1);
  tpr_floor(val, &res);
  float fres = 0;
  tpr_from_decimal_to_float(res, &fres);
  ck_assert_float_eq(-9, fres);
}
END_TEST

START_TEST(tfloor_7) {
  tpr_decimal val = {{100, 0, 0, 0}};
  tpr_decimal res = {0};
  tpr_set_power(&val.bits[3], 0);
  tpr_floor(val, &res);
  float fres = 0;
  tpr_from_decimal_to_float(res, &fres);
  ck_assert_float_eq(100, fres);
}
END_TEST

START_TEST(round_positive_fraction_less_than_half) {
  tpr_decimal val = {{123, 0, 0, 0}};
  tpr_decimal res = {0};
  tpr_set_power(&val.bits[3], 2);
  ck_assert_int_eq(0, tpr_round(val, &res));
  ck_assert_int_eq(1, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
}
END_TEST

START_TEST(round_positive_half) {
  tpr_decimal val = {{500, 0, 0, 0}};
  tpr_decimal res = {0};
  tpr_set_power(&val.bits[3], 3);
  ck_assert_int_eq(0, tpr_round(val, &res));
  ck_assert_int_eq(1, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
}
END_TEST

START_TEST(round_negative_less_than_half) {
  tpr_decimal val = {{500, 0, 0, 0}};
  tpr_decimal res = {0};
  tpr_set_power(&val.bits[3], 3);
  ck_assert_int_eq(0, tpr_round(val, &res));
  ck_assert_int_eq(1, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
}
END_TEST

START_TEST(round_positive_fraction_greater_than_half) {
  tpr_decimal val = {{750, 0, 0, 0}};
  tpr_decimal res = {0};
  tpr_set_power(&val.bits[3], 3);
  ck_assert_int_eq(0, tpr_round(val, &res));
  ck_assert_int_eq(1, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
}
END_TEST

START_TEST(round_negative_greater_than_half) {
  tpr_decimal val = {{999999999, 0, 0, 0}};
  tpr_decimal res = {0};
  tpr_set_power(&val.bits[3], 9);
  ck_assert_int_eq(0, tpr_round(val, &res));
  ck_assert_int_eq(1, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
}
END_TEST

START_TEST(round_integer) {
  tpr_decimal val = {{12345, 0, 0, 0}};
  tpr_decimal res = {0};
  tpr_set_power(&val.bits[3], 0);
  ck_assert_int_eq(0, tpr_round(val, &res));
  ck_assert_int_eq(12345, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
}
END_TEST

START_TEST(round_zero_fraction) {
  tpr_decimal val = {{1000, 0, 0, 0}};
  tpr_decimal res = {0};
  tpr_set_power(&val.bits[3], 3);
  ck_assert_int_eq(0, tpr_round(val, &res));
  ck_assert_int_eq(1, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
}
END_TEST

START_TEST(round_large_fraction) {
  tpr_decimal val = {{999999999, 0, 0, 0}};
  tpr_decimal res = {0};
  tpr_set_power(&val.bits[3], 9);
  ck_assert_int_eq(0, tpr_round(val, &res));
  ck_assert_int_eq(1, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
}
END_TEST

START_TEST(round_small_fraction_to_zero) {
  tpr_decimal val = {{1, 0, 0, 0}};
  tpr_decimal res = {0};
  tpr_set_power(&val.bits[3], 2);
  ck_assert_int_eq(0, tpr_round(val, &res));
  ck_assert_int_eq(0, res.bits[0]);
  ck_assert_int_eq(0, res.bits[1]);
  ck_assert_int_eq(0, res.bits[2]);
}
END_TEST

START_TEST(from_float_to_decimal_0) {
  float inp = 1. / 0.;
  tpr_decimal out;
  int error = tpr_from_float_to_decimal(inp, &out);
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], 0);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(from_float_to_decimal_1) {
  float inp = 0.004;
  tpr_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = tpr_from_float_to_decimal(inp, &out);
  tpr_decimal res = {{0x00000004, 0, 0, 0x00030000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(from_float_to_decimal_2) {
  float inp = 0.004;
  tpr_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = tpr_from_float_to_decimal(inp, &out);
  tpr_decimal res = {{0x00000004, 0, 0, 0x00030000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}

START_TEST(from_float_to_decimal_3) {
  float inp = 0.00000000000000000000000000013929383838292;
  tpr_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = tpr_from_float_to_decimal(inp, &out);
  tpr_decimal res = {{1, 0, 0, 1835008}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(from_float_to_decimal_4) {
  float inp = 79215000000000000000000000000.365656;
  tpr_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = tpr_from_float_to_decimal(inp, &out);
  tpr_decimal res = {{3472883712U, 2886053469U, 4294253754U, 0}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(from_float_to_decimal_5) {
  float inp = 79215000000000000000000000000.365656;
  tpr_decimal out = {{32131, 1231435, 2311, 3121441}};
  int error = tpr_from_float_to_decimal(inp, &out);
  tpr_decimal res = {{3472883712U, 2886053469U, 4294253754U, 0}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(from_float_to_decimal_6) {
  float inp = 79215000000000000000000000000.365656;
  tpr_decimal out = {{0, 0, 0, 0}};
  int error = tpr_from_float_to_decimal(inp, &out);
  tpr_decimal res = {{3472883712U, 2886053469U, 4294253754U, 0}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(from_float_to_decimal_7) {
  float inp = -79215000000000000000000000000.365656;
  tpr_decimal out = {{0, 0, 0, 0}};
  int error = tpr_from_float_to_decimal(inp, &out);
  tpr_decimal res = {{3472883712U, 2886053469U, 4294253754U, 0x80000000}};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(out.bits[i], res.bits[i]);
  ck_assert_int_eq(error, 0);
}
END_TEST

START_TEST(from_float_to_decimal_8) {
  float inp = INFINITY;
  tpr_decimal out = {{0, 0, 0, 0}};
  int error = tpr_from_float_to_decimal(inp, &out);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(from_float_to_decimal_9) {
  float inp = -INFINITY;
  tpr_decimal out = {{0, 0, 0, 0}};
  int error = tpr_from_float_to_decimal(inp, &out);
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(from_float_to_decimal_10) {
  float inp = NAN;
  tpr_decimal out = {{0, 0, 0, 0}};
  int error = tpr_from_float_to_decimal(inp, &out);
  ck_assert_int_eq(error, 1);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  tcase_add_test(tc1_1, sub_0);  // tpr_sub
  tcase_add_test(tc1_1, sub_1);
  tcase_add_test(tc1_1, sub_2);
  tcase_add_test(tc1_1, sub_3);
  tcase_add_test(tc1_1, sub_4);
  tcase_add_test(tc1_1, sub_5);
  tcase_add_test(tc1_1, sub_6);
  tcase_add_test(tc1_1, sub_7);
  tcase_add_test(tc1_1, sub_8);
  tcase_add_test(tc1_1, sub_9);
  tcase_add_test(tc1_1, sub_10);
  tcase_add_test(tc1_1, sub_11);
  tcase_add_test(tc1_1, sub_12);
  tcase_add_test(tc1_1, sub_13);
  tcase_add_test(tc1_1, sub_14);
  tcase_add_test(tc1_1, sub_15);
  tcase_add_test(tc1_1, sub_16);
  tcase_add_test(tc1_1, sub_17);
  tcase_add_test(tc1_1, sub_18);
  tcase_add_test(tc1_1, sub_19);
  tcase_add_test(tc1_1, sub_20);
  tcase_add_test(tc1_1, sub_21);
  tcase_add_test(tc1_1, sub_22);
  tcase_add_test(tc1_1, sub_23);
  tcase_add_test(tc1_1, sub_24);
  tcase_add_test(tc1_1, sub_25);
  tcase_add_test(tc1_1, sub_26);
  tcase_add_test(tc1_1, add_0);  // tpr_add
  tcase_add_test(tc1_1, add_1);
  tcase_add_test(tc1_1, add_2);
  tcase_add_test(tc1_1, add_3);
  tcase_add_test(tc1_1, add_4);
  tcase_add_test(tc1_1, add_5);
  tcase_add_test(tc1_1, add_6);
  tcase_add_test(tc1_1, add_7);
  tcase_add_test(tc1_1, add_8);
  tcase_add_test(tc1_1, add_9);
  tcase_add_test(tc1_1, add_10);
  tcase_add_test(tc1_1, add_11);
  tcase_add_test(tc1_1, add_12);
  tcase_add_test(tc1_1, add_13);
  tcase_add_test(tc1_1, add_14);
  tcase_add_test(tc1_1, add_15);
  tcase_add_test(tc1_1, add_16);
  tcase_add_test(tc1_1, add_17);
  tcase_add_test(tc1_1, add_18);
  tcase_add_test(tc1_1, add_19);
  tcase_add_test(tc1_1, add_20);
  tcase_add_test(tc1_1, add_21);
  tcase_add_test(tc1_1, add_22);
  tcase_add_test(tc1_1, add_23);
  tcase_add_test(tc1_1, mul_0);  // tpr_mul
  tcase_add_test(tc1_1, mul_1);
  tcase_add_test(tc1_1, mul_2);
  tcase_add_test(tc1_1, mul_3);
  tcase_add_test(tc1_1, mul_4);
  tcase_add_test(tc1_1, mul_5);
  tcase_add_test(tc1_1, mul_6);
  tcase_add_test(tc1_1, mul_7);
  tcase_add_test(tc1_1, mul_8);
  tcase_add_test(tc1_1, mul_9);
  tcase_add_test(tc1_1, mul_10);
  tcase_add_test(tc1_1, mul_11);
  tcase_add_test(tc1_1, mul_12);
  tcase_add_test(tc1_1, mul_13);
  tcase_add_test(tc1_1, mul_14);
  tcase_add_test(tc1_1, mul_15);
  tcase_add_test(tc1_1, mul_16);
  tcase_add_test(tc1_1, mul_17);
  tcase_add_test(tc1_1, mul_18);
  tcase_add_test(tc1_1, mul_19);
  tcase_add_test(tc1_1, div_0);  // tpr_div
  tcase_add_test(tc1_1, div_1);
  tcase_add_test(tc1_1, div_2);
  tcase_add_test(tc1_1, div_3);
  tcase_add_test(tc1_1, div_4);
  tcase_add_test(tc1_1, div_5);
  tcase_add_test(tc1_1, div_6);
  tcase_add_test(tc1_1, div_7);
  tcase_add_test(tc1_1, div_8);
  tcase_add_test(tc1_1, div_9);
  tcase_add_test(tc1_1, div_10);
  tcase_add_test(tc1_1, div_11);
  tcase_add_test(tc1_1, div_12);
  tcase_add_test(tc1_1, big_to_dec_0);  // big_to_decimal
  tcase_add_test(tc1_1, big_to_dec_1);
  tcase_add_test(tc1_1, big_to_dec_2);
  tcase_add_test(tc1_1, big_to_dec_3);
  tcase_add_test(tc1_1, big_to_dec_4);
  tcase_add_test(tc1_1, big_to_dec_5);
  tcase_add_test(tc1_1, round_bank_0);  // round_bank
  tcase_add_test(tc1_1, round_bank_1);
  tcase_add_test(tc1_1, round_bank_2);
  tcase_add_test(tc1_1, round_bank_3);
  tcase_add_test(tc1_1, round_bank_4);
  tcase_add_test(tc1_1, round_bank_5);
  tcase_add_test(tc1_1, round_bank_6);
  tcase_add_test(tc1_1, round_bank_7);
  tcase_add_test(tc1_1, round_bank_8);
  tcase_add_test(tc1_1, round_bank_9);
  tcase_add_test(tc1_1, round_bank_10);
  tcase_add_test(tc1_1, negate_0);  // negate
  tcase_add_test(tc1_1, negate_1);
  tcase_add_test(tc1_1, negate_2);
  tcase_add_test(tc1_1, negate_3);
  tcase_add_test(tc1_1, negate_4);
  tcase_add_test(tc1_1, negate_5);
  tcase_add_test(tc1_1, round_0);  // round
  tcase_add_test(tc1_1, round_1);
  tcase_add_test(tc1_1, round_2);
  tcase_add_test(tc1_1, round_3);
  tcase_add_test(tc1_1, round_4);
  tcase_add_test(tc1_1, round_5);
  tcase_add_test(tc1_1, round_6);
  tcase_add_test(tc1_1, round_7);
  tcase_add_test(tc1_1, round_8);
  tcase_add_test(tc1_1, round_9);
  tcase_add_test(tc1_1, round_10);
  tcase_add_test(tc1_1, round_11);
  tcase_add_test(tc1_1, truncate_0);  // truncate
  tcase_add_test(tc1_1, truncate_1);
  tcase_add_test(tc1_1, truncate_2);
  tcase_add_test(tc1_1, truncate_3);
  tcase_add_test(tc1_1, truncate_4);
  tcase_add_test(tc1_1, truncate_5);
  tcase_add_test(tc1_1, truncate_6);
  tcase_add_test(tc1_1, floor_0);  // floor
  tcase_add_test(tc1_1, floor_1);
  tcase_add_test(tc1_1, floor_2);
  tcase_add_test(tc1_1, floor_3);
  tcase_add_test(tc1_1, floor_4);
  tcase_add_test(tc1_1, floor_5);
  tcase_add_test(tc1_1, from_decimal_to_float_0);  // from_decimal_to_float
  tcase_add_test(tc1_1, from_decimal_to_float_1);
  tcase_add_test(tc1_1, from_decimal_to_int_0);  // from_decimal_to_int
  tcase_add_test(tc1_1, from_decimal_to_int_1);
  tcase_add_test(tc1_1, from_decimal_to_int_2);
  tcase_add_test(tc1_1, from_decimal_to_int_3);
  tcase_add_test(tc1_1, from_decimal_to_int_4);
  tcase_add_test(tc1_1, from_decimal_to_int_5);
  tcase_add_test(tc1_1, from_decimal_to_int_6);
  tcase_add_test(tc1_1, from_int_to_decimal_0);  // from_int_to_decimal
  tcase_add_test(tc1_1, from_int_to_decimal_1);
  tcase_add_test(tc1_1, from_int_to_decimal_2);
  tcase_add_test(tc1_1, test_convertors_positive_int);
  tcase_add_test(tc1_1, test_convertors_negatives_int);
  tcase_add_test(tc1_1, test_convertors_positive_float);
  tcase_add_test(tc1_1, test_convertors_negatives_float);
  tcase_add_test(tc1_1, test_convertors_positives_float_to_int);
  tcase_add_test(tc1_1, test_convertors_negatives_float_to_int);
  tcase_add_test(tc1_1, test_convertors_zero_int);
  tcase_add_test(tc1_1, test_convertors_zero_float);
  tcase_add_test(tc1_1, test_convertors_nan);
  tcase_add_test(tc1_1, test_convertors_max);
  tcase_add_test(tc1_1, test_convertors_min);
  tcase_add_test(tc1_1, test_convertors_zero_scale);
  tcase_add_test(tc1_1, test_convertors_int_max);
  tcase_add_test(tc1_1, test_convertors_int_max_2);
  tcase_add_test(tc1_1, test_convertors_int_max_3);
  tcase_add_test(tc1_1, test_convertors_int_max_4);
  tcase_add_test(tc1_1, test_convertors_int_max_5);
  tcase_add_test(tc1_1, test_convertors_int_max_6);
  tcase_add_test(tc1_1, test_convertors_int_max_7);
  tcase_add_test(tc1_1, test_convertors_zero);
  tcase_add_test(tc1_1, test_convertors_max_8);

  tcase_add_test(tc1_1, test_tpr_is_less_1);  // tpr_is_less
  tcase_add_test(tc1_1, test_tpr_is_less_2);
  tcase_add_test(tc1_1, test_tpr_is_less_3);
  tcase_add_test(tc1_1, test_tpr_is_less_4);
  tcase_add_test(tc1_1, test_tpr_is_less_5);
  tcase_add_test(tc1_1, test_tpr_is_less_6);
  tcase_add_test(tc1_1, test_tpr_is_less_7);
  tcase_add_test(tc1_1, test_tpr_is_less_or_equal_1);  // tpr_is_less_or_equal
  tcase_add_test(tc1_1, test_tpr_is_less_or_equal_2);
  tcase_add_test(tc1_1, test_tpr_is_less_or_equal_3);
  tcase_add_test(tc1_1, test_tpr_is_less_or_equal_4);
  tcase_add_test(tc1_1, test_tpr_is_less_or_equal_5);
  tcase_add_test(tc1_1, test_tpr_is_less_or_equal_6);
  tcase_add_test(tc1_1, test_tpr_is_less_or_equal_7);
  tcase_add_test(tc1_1, test_tpr_is_greater_1);  // tpr_is_greater
  tcase_add_test(tc1_1, test_tpr_is_greater_2);
  tcase_add_test(tc1_1, test_tpr_is_greater_3);
  tcase_add_test(tc1_1, test_tpr_is_greater_4);
  tcase_add_test(tc1_1, test_tpr_is_greater_5);
  tcase_add_test(tc1_1, test_tpr_is_greater_6);
  tcase_add_test(tc1_1, test_tpr_is_greater_7);
  tcase_add_test(tc1_1,
                 test_tpr_is_greater_or_equal_1);  // tpr_is_greater_or_equal
  tcase_add_test(tc1_1, test_tpr_is_greater_or_equal_2);
  tcase_add_test(tc1_1, test_tpr_is_greater_or_equal_3);
  tcase_add_test(tc1_1, test_tpr_is_greater_or_equal_4);
  tcase_add_test(tc1_1, test_tpr_is_greater_or_equal_5);
  tcase_add_test(tc1_1, test_tpr_is_greater_or_equal_6);
  tcase_add_test(tc1_1, test_tpr_is_greater_or_equal_7);
  tcase_add_test(tc1_1, test_tpr_is_equal_1);  // tpr_is_equal
  tcase_add_test(tc1_1, test_tpr_is_equal_2);
  tcase_add_test(tc1_1, test_tpr_is_equal_3);
  tcase_add_test(tc1_1, test_tpr_is_equal_4);
  tcase_add_test(tc1_1, test_tpr_is_equal_5);
  tcase_add_test(tc1_1, test_tpr_is_equal_6);
  tcase_add_test(tc1_1, test_tpr_is_equal_7);
  tcase_add_test(tc1_1, test_tpr_is_not_equal_1);  // tpr_is_not_equal
  tcase_add_test(tc1_1, test_tpr_is_not_equal_2);
  tcase_add_test(tc1_1, test_tpr_is_not_equal_3);
  tcase_add_test(tc1_1, test_tpr_is_not_equal_4);
  tcase_add_test(tc1_1, test_tpr_is_not_equal_5);
  tcase_add_test(tc1_1, test_tpr_is_not_equal_6);
  tcase_add_test(tc1_1, test_tpr_is_not_equal_7);

  ///////////////////////////////////////////////

  tcase_add_test(tc1_1, test_arith_add_1);
  tcase_add_test(tc1_1, test_arith_add_2);
  tcase_add_test(tc1_1, test_arith_add_3);
  tcase_add_test(tc1_1, test_arith_add_4);
  tcase_add_test(tc1_1, test_arith_add_5);
  tcase_add_test(tc1_1, test_arith_add_6);
  tcase_add_test(tc1_1, test_arith_add_7);
  tcase_add_test(tc1_1, test_arith_add_8);
  tcase_add_test(tc1_1, test_arith_add_9);
  tcase_add_test(tc1_1, test_arith_add_10);
  tcase_add_test(tc1_1, test_arith_add_11);
  tcase_add_test(tc1_1, test_arith_add_12);
  tcase_add_test(tc1_1, test_arith_add_13);
  tcase_add_test(tc1_1, test_arith_add_14);
  tcase_add_test(tc1_1, test_arith_add_15);
  tcase_add_test(tc1_1, test_arith_add_16);
  tcase_add_test(tc1_1, test_arith_add_17);
  tcase_add_test(tc1_1, test_arith_add_18);
  tcase_add_test(tc1_1, test_arith_add_19);
  tcase_add_test(tc1_1, test_arith_add_20);
  tcase_add_test(tc1_1, test_arith_add_21);
  tcase_add_test(tc1_1, test_arith_add_22);
  tcase_add_test(tc1_1, test_arith_sub_1);
  tcase_add_test(tc1_1, test_arith_sub_2);
  tcase_add_test(tc1_1, test_arith_sub_3);
  tcase_add_test(tc1_1, test_arith_sub_4);
  tcase_add_test(tc1_1, test_arith_sub_5);
  tcase_add_test(tc1_1, test_arith_sub_6);
  tcase_add_test(tc1_1, test_arith_sub_7);
  tcase_add_test(tc1_1, test_arith_sub_8);
  tcase_add_test(tc1_1, test_arith_sub_9);
  tcase_add_test(tc1_1, test_arith_sub_10);
  tcase_add_test(tc1_1, test_arith_mul_1);
  tcase_add_test(tc1_1, test_arith_mul_2);
  tcase_add_test(tc1_1, test_arith_mul_3);
  tcase_add_test(tc1_1, test_arith_mul_4);
  tcase_add_test(tc1_1, test_arith_mul_5);
  tcase_add_test(tc1_1, test_arith_mul_6);
  tcase_add_test(tc1_1, test_arith_mul_7);
  tcase_add_test(tc1_1, test_arith_mul_8);
  tcase_add_test(tc1_1, test_arith_mul_9);
  tcase_add_test(tc1_1, test_arith_mul_10);
  tcase_add_test(tc1_1, test_arith_mul_11);
  tcase_add_test(tc1_1, test_arith_div_1);
  tcase_add_test(tc1_1, test_arith_div_2);
  tcase_add_test(tc1_1, test_arith_div_3);
  tcase_add_test(tc1_1, test_arith_div_4);
  tcase_add_test(tc1_1, test_arith_div_5);
  tcase_add_test(tc1_1, test_arith_div_6);
  tcase_add_test(tc1_1, test_arith_div_7);
  tcase_add_test(tc1_1, test_arith_div_8);
  tcase_add_test(tc1_1, test_arith_div_9);
  tcase_add_test(tc1_1, test_arith_div_10);
  tcase_add_test(tc1_1, test_arith_div_11);
  tcase_add_test(tc1_1, test_arith_div_13);
  tcase_add_test(tc1_1, test_convertors_6);
  tcase_add_test(tc1_1, test_convertors_7);
  tcase_add_test(tc1_1, test_convertors_8);
  tcase_add_test(tc1_1, test_convertors_9);
  tcase_add_test(tc1_1, test_convertors_10);
  tcase_add_test(tc1_1, other_functions_1);
  tcase_add_test(tc1_1, other_functions_2);
  tcase_add_test(tc1_1, other_functions_3);
  tcase_add_test(tc1_1, other_functions_4);
  tcase_add_test(tc1_1, other_functions_5);
  tcase_add_test(tc1_1, other_functions_6);
  tcase_add_test(tc1_1, other_functions_7);
  tcase_add_test(tc1_1, other_functions_8);
  tcase_add_test(tc1_1, other_functions_9);
  tcase_add_test(tc1_1, other_functions_10);
  tcase_add_test(tc1_1, other_functions_11);
  tcase_add_test(tc1_1, other_functions_12);
  tcase_add_test(tc1_1, other_functions_13);
  tcase_add_test(tc1_1, other_functions_14);
  tcase_add_test(tc1_1, other_functions_15);

  //////////////////////////////////////////

  tcase_add_test(tc1_1, tsub_0);
  tcase_add_test(tc1_1, tsub_1);
  tcase_add_test(tc1_1, tsub_2);
  tcase_add_test(tc1_1, tsub_3);
  tcase_add_test(tc1_1, tsub_4);
  tcase_add_test(tc1_1, tsub_5);
  tcase_add_test(tc1_1, tsub_6);
  tcase_add_test(tc1_1, tsub_7);
  tcase_add_test(tc1_1, tsub_8);
  tcase_add_test(tc1_1, tsub_9);
  tcase_add_test(tc1_1, tsub_10);
  tcase_add_test(tc1_1, tsub_11);
  tcase_add_test(tc1_1, tsub_12);
  tcase_add_test(tc1_1, tsub_13);
  tcase_add_test(tc1_1, tsub_14);
  tcase_add_test(tc1_1, tsub_15);
  tcase_add_test(tc1_1, tsub_16);
  tcase_add_test(tc1_1, tsub_17);
  tcase_add_test(tc1_1, tsub_18);
  tcase_add_test(tc1_1, tsub_19);
  tcase_add_test(tc1_1, tsub_20);
  tcase_add_test(tc1_1, tsub_21);
  tcase_add_test(tc1_1, tsub_22);
  tcase_add_test(tc1_1, tsub_23);

  tcase_add_test(tc1_1, tadd_0);
  tcase_add_test(tc1_1, tadd_1);
  tcase_add_test(tc1_1, tadd_2);
  tcase_add_test(tc1_1, tadd_4);
  tcase_add_test(tc1_1, tadd_5);
  tcase_add_test(tc1_1, tadd_6);
  tcase_add_test(tc1_1, tadd_7);
  tcase_add_test(tc1_1, tadd_8);
  tcase_add_test(tc1_1, tadd_9);
  tcase_add_test(tc1_1, tadd_10);
  tcase_add_test(tc1_1, tadd_11);
  tcase_add_test(tc1_1, tadd_13);
  tcase_add_test(tc1_1, tadd_14);
  tcase_add_test(tc1_1, tadd_15);
  tcase_add_test(tc1_1, tadd_17);
  tcase_add_test(tc1_1, tadd_18);
  tcase_add_test(tc1_1, tadd_19);
  tcase_add_test(tc1_1, tadd_20);

  tcase_add_test(tc1_1, tmul_0);
  tcase_add_test(tc1_1, tmul_1);
  tcase_add_test(tc1_1, tmul_2);
  tcase_add_test(tc1_1, tmul_3);
  tcase_add_test(tc1_1, tmul_4);
  tcase_add_test(tc1_1, tmul_5);
  tcase_add_test(tc1_1, tmul_6);
  tcase_add_test(tc1_1, tmul_7);
  tcase_add_test(tc1_1, tmul_8);
  tcase_add_test(tc1_1, tmul_9);
  tcase_add_test(tc1_1, tmul_10);
  tcase_add_test(tc1_1, tmul_11);
  tcase_add_test(tc1_1, tmul_12);
  tcase_add_test(tc1_1, tmul_13);
  tcase_add_test(tc1_1, tmul_14);
  tcase_add_test(tc1_1, tmul_15);
  tcase_add_test(tc1_1, tmul_16);

  tcase_add_test(tc1_1, tdiv_0);
  tcase_add_test(tc1_1, tdiv_1);
  tcase_add_test(tc1_1, tdiv_2);
  tcase_add_test(tc1_1, tdiv_3);
  tcase_add_test(tc1_1, tdiv_4);
  tcase_add_test(tc1_1, tdiv_5);
  tcase_add_test(tc1_1, tdiv_6);
  tcase_add_test(tc1_1, tdiv_7);
  tcase_add_test(tc1_1, tdiv_8);
  tcase_add_test(tc1_1, tdiv_9);
  tcase_add_test(tc1_1, tdiv_10);
  tcase_add_test(tc1_1, tdiv_11);
  tcase_add_test(tc1_1, tdiv_12);
  tcase_add_test(tc1_1, tdiv_13);
  tcase_add_test(tc1_1, tdiv_14);

  tcase_add_test(tc1_1, truncate_zero);
  tcase_add_test(tc1_1, truncate_small_int);
  tcase_add_test(tc1_1, truncate_large_negative);
  tcase_add_test(tc1_1, truncate_negative_with_scale);
  tcase_add_test(tc1_1, truncate_with_scale);
  tcase_add_test(tc1_1, truncate_fraction_large_scale);
  tcase_add_test(tc1_1, truncate_positive_fraction);
  tcase_add_test(tc1_1, truncate_min_positive_fraction);

  tcase_add_test(tc1_1, tfloor_0);
  tcase_add_test(tc1_1, tfloor_1);
  tcase_add_test(tc1_1, tfloor_2);
  tcase_add_test(tc1_1, tfloor_3);
  tcase_add_test(tc1_1, tfloor_4);
  tcase_add_test(tc1_1, tfloor_5);
  tcase_add_test(tc1_1, tfloor_6);
  tcase_add_test(tc1_1, tfloor_7);

  tcase_add_test(tc1_1, round_positive_fraction_less_than_half);
  tcase_add_test(tc1_1, round_positive_half);
  tcase_add_test(tc1_1, round_negative_less_than_half);
  tcase_add_test(tc1_1, round_positive_fraction_greater_than_half);
  tcase_add_test(tc1_1, round_negative_greater_than_half);
  tcase_add_test(tc1_1, round_integer);
  tcase_add_test(tc1_1, round_zero_fraction);
  tcase_add_test(tc1_1, round_large_fraction);
  tcase_add_test(tc1_1, round_small_fraction_to_zero);

  tcase_add_test(tc1_1, from_float_to_decimal_0);
  tcase_add_test(tc1_1, from_float_to_decimal_1);
  tcase_add_test(tc1_1, from_float_to_decimal_2);
  tcase_add_test(tc1_1, from_float_to_decimal_3);
  tcase_add_test(tc1_1, from_float_to_decimal_4);
  tcase_add_test(tc1_1, from_float_to_decimal_5);
  tcase_add_test(tc1_1, from_float_to_decimal_6);
  tcase_add_test(tc1_1, from_float_to_decimal_7);
  tcase_add_test(tc1_1, from_float_to_decimal_8);
  tcase_add_test(tc1_1, from_float_to_decimal_9);
  tcase_add_test(tc1_1, from_float_to_decimal_10);

  suite_add_tcase(s1, tc1_1);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
