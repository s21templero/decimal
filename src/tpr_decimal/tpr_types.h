#ifndef SRC_tpr_DECIMAL_TYPES_H_
#define SRC_tpr_DECIMAL_TYPES_H_

#include <limits.h>
#include <math.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tpr_decimal {
  int bits[4];
} tpr_decimal;

typedef union decimal_bit3 {
  int i;
  struct {
    uint32_t part2 : 16;
    uint32_t power : 8;
    uint32_t part1 : 7;
    uint32_t sign : 1;
  } parts;
} decimal_bit3;

typedef struct tpr_big_decimal {
  int bits[8];
} tpr_big_decimal;

#endif
