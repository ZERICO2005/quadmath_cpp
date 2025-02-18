/*
**	Author: zerico2005 (2024 - 2025)
**	Project: quadmath_cpp
**	License: MIT License
**	A copy of the MIT License should be included with
**	this project. If not, see https://opensource.org/license/MIT
*/

#include <cassert>
#include <cstdio>
#include <limits>

#if __cplusplus >= 201103L
	#include <cfenv>
	#include <cmath>
#endif

#include <quadmath.h>

#include "../../quadmath_cpp.h"

void basic_test() {
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
}

#if __cplusplus >= 201103L
void quiet_comparison_test() {
	__float128 x = std::numeric_limits<__float128>::signaling_NaN();
	__float128 y = 100.0q;
	
	assert(isnan(x));
	assert(issignaling(x));
	
	std::feclearexcept(FE_ALL_EXCEPT);
	
	bool signaling_less_than = (x < y);
	assert(signaling_less_than == false);
	assert(std::fetestexcept(FE_INVALID) == true);
	
	std::feclearexcept(FE_ALL_EXCEPT);
	
	bool quiet_less_than = isless(x, y);
	assert(quiet_less_than == false);
	assert(std::fetestexcept(FE_INVALID) == false);
	
	std::feclearexcept(FE_ALL_EXCEPT);
	
	bool subnormal_test = issubnormal(x);
	assert(subnormal_test == false);
	assert(std::fetestexcept(FE_INVALID) == false);
	
	printf("Passed the quiet comparison test\n");
}
#else
void quiet_comparison_test() { return; }
#endif

int main(void) {
	basic_test();
	quiet_comparison_test();
	return 0;
}
