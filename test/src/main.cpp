/*
**	Author: zerico2005 (2024)
**	Project: quadmath_cpp
**	License: MIT License
**	A copy of the MIT License should be included with
**	this project. If not, see https://opensource.org/license/MIT
*/

#include "../../quadmath_cpp.h"

#include <cstdio>

int main(void) {
	__float128 val_0 = 1.234q;
	__float128 val_1 = 5.678q;
	__float128 result = pow(val_0, val_1);

	char buf_0[256];
	char buf_1[256];
	char buf_result[256];

	quadmath_snprintf(buf_0, sizeof(buf_0), "%.3Qf", val_0);
	quadmath_snprintf(buf_1, sizeof(buf_1), "%.3Qf", val_1);
	quadmath_snprintf(buf_result, sizeof(buf_result), "%.*Qf", FLT128_DIG, result);

	printf("pow(%s, %s) = %s\n", buf_0, buf_1, buf_result);

	return 0;
}
