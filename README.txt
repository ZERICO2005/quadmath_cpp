quadmath_cpp provides C++ overloads for __float128 and quadmath.h. This allows you to use quadmath.h in templated functions. Instead of calling sinq(x) or powq(x, y), you can now call sin(x) or pow(x, y) just like you would with float or double.

quadmath_cpp also includes C++11 <cmath> functions not present in quadmath.h, such as islessgreater(x, y) and fpclassify(x)

Include the quadmath_cpp.h header in your code to use it. The header should compile fine on GCC from C++98 to C++23
