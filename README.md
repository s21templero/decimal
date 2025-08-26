# tpr_decimal Library in C

[🇷🇺RU](README_RUS.md) | [🇺🇸EN](README.md)

## About the Library

- The library is developed in C language following the `C11` standard;
- Targets the `POSIX.1-2017` standard for language and library usage;
- Code style adheres to Google Style guidelines;
- The project builds into a static library named `tpr_decimal.a` (with the header file `tpr_decimal.h`);
- Developed following the principles of structured programming;
- Unit tests for the library functions, written using the Check library, are located in the `src/tpr_test` directory;
- Unit tests achieve over 95% coverage for each function;
- A Makefile is provided for building the library and tests (with targets `all`, `clean`, `test`, `tpr_decimal.a`, `gcov_report`);
- The `gcov_report` target generates a gcov report as an HTML page;
- The decimal implementation is based on a binary representation using a signed integer array (`bits`);
- The library is implemented without using the `__int128` type.
- The defined type supports numbers from `-79,228,162,514,264,337,593,543,950,335` to `+79,228,162,514,264,337,593,543,950,335`.

## Building

The library is built using the GCC compiler. The following dependencies are required for successful building of all targets (including Unit tests and gcov report):
`libmath, libsubunit, check, lcov`.

---
To build the main library:

```bash
make # or make all
```
- creates the library named tpr_decimal.a in the src directory

To build the tests:
```bash
# Ensure 'check' is installed on the system beforehand (if missing)
apt install check

make test
```
- creates the executable test in the src directory

To generate the test coverage report:

```bash
# Ensure 'lcov' is installed on the system beforehand (if missing)
make gcov_report
```
- Generates the report; open html/index.html for graphical visualization

To clean all built and temporary files:

```bash
make clean
```

## Docker

The Dockerfile is located in the src directory of the repository.

1. Build the Docker Image

```bash
sudo docker build -t decimal-project .
```

2. To Run Tests

```bash
sudo docker run --rm decimal-project make test
```

3. To Build the Project

```bash
sudo docker run --rm decimal-project make all
```

4. To Generate the Coverage Report

```bash
sudo docker run --rm decimal-project make gcov_report
```

5. To Start an Interactive Session as the `root` User

```bash
sudo docker run -it --rm decimal-project /bin/bash
```

## Implemented Functions, Library Usage

In the current implementation, Decimal is represented as a four-element array of 32-bit signed integers (`int bits[4];`).

`bits[0], bits[1], bits[2]` contain the low, middle, and high 32 bits of the 96-bit integer number, respectively.
`bits[3]` contains the scale factor and sign and consists of the following parts:

`Bits 0 to 15` - the low word, unused and must be zero;
`Bits 16 to 23` - contain an exponent between 0 and 28, indicating the power of 10 to divide the integer number;
`Bits 24 to 30` - unused and must be zero;
`Bit 31` - contains the sign: 0 means positive, 1 means negative.


### Arithmetic Operators

| Operator name | Operator  | Function                                                                            | 
| ------ | ------ |------------------------------------------------------------------------------------|
| Addition | + | int tpr_add(tpr_decimal value_1, tpr_decimal value_2, tpr_decimal *result)         |
| Subtraction | - | int tpr_sub(tpr_decimal value_1, tpr_decimal value_2, tpr_decimal *result)         |
| Multiplication | * | int tpr_mul(tpr_decimal value_1, tpr_decimal value_2, tpr_decimal *result) | 
| Division | / | int tpr_div(tpr_decimal value_1, tpr_decimal value_2, tpr_decimal *result) |

Functions return an error code:

- 0 — OK;

- 1 — number is too large or equals infinity;

- 2 — number is too small or equals negative infinity;

- 3 — division by 0.

Clarification on numbers exceeding the mantissa:

When numbers obtained during arithmetic operations do not fit the mantissa, bank rounding is used (e.g., `79,228,162,514,264,337,593,543,950,335 — 0.6 = 79,228,162,514,264,337,593,543,950,334`).

### Comparison Operators

| Operator Name | Operator  | Function | 
| ------ | ------ | ------ |
| Less than  | < | int tpr_is_less(tpr_decimal, tpr_decimal) |
| Less than or equal to | <= | int tpr_is_less_or_equal(tpr_decimal, tpr_decimal) | 
| Greater than | \> |  int tpr_is_greater(tpr_decimal, tpr_decimal) |
| Greater than or equal to | \>= | int tpr_is_greater_or_equal(tpr_decimal, tpr_decimal) | 
| Equal to | == |  int tpr_is_equal(tpr_decimal, tpr_decimal) |
| Not equal to | != |  int tpr_is_not_equal(tpr_decimal, tpr_decimal) |

Return value:
- 0 — FALSE;
- 1 — TRUE.

### Converters

| Converter | Function | 
| ------ | ------ |
| From int | int s21_from_int_to_decimal(int src, s21_decimal *dst) |
| From float  | int s21_from_float_to_decimal(float src, s21_decimal *dst) |
| To int  | int s21_from_decimal_to_int(s21_decimal src, int *dst) |
| To float  | int s21_from_decimal_to_float(s21_decimal src, float *dst) |

Return value — error code:

- 0 — OK;

- 1 — conversion error.

Clarification on converting from float:

- If numbers are too small (`0 < |x| < 1e-28`), an error is returned and the value is set to `0`.

- If numbers are too large (`|x| > 79,228,162,514,264,337,593,543,950,335`) or equal to infinity, an error is returned.

- When processing a float number, all significant decimal digits it contains are converted. If there are more than `7 such digits`, the value is rounded to the nearest number with no more than `7 significant digits`.

Clarification on converting from decimal to int:

- If the decimal number has a fractional part, it is discarded (e.g., `0.9 becomes 0`).

### Other Functions

| Description | Function                                                  | 
| ------ |----------------------------------------------------------|
| Rounds a specified Decimal number to the closest integer toward negative infinity. | int s21_floor(s21_decimal value, s21_decimal *result)    |	
| Rounds a decimal value to the nearest integer. | int s21_round(s21_decimal value, s21_decimal *result)    |
| Returns the integral digits of the specified Decimal; any fractional digits are discarded, including trailing zeros. | int s21_truncate(s21_decimal value, s21_decimal *result) |
| Returns the result of multiplying the specified Decimal by -1. | int s21_negate(s21_decimal value, s21_decimal *result)   |

Return value — error code:
 - 0 — OK;
 - 1 — calculation error.