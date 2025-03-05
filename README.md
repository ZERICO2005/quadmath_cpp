`quadmath_cpp` provides C++ overloads for `__float128` and `<quadmath.h>` functions. This allows you to use `<quadmath.h>` in templated functions. Instead of calling `sinq(x)` or `powq(x, y)`, you can now call `sin(x)` or `pow(x, y)` just like you would with `float` or `double`.

`quadmath_cpp` also includes functions not present in `<quadmath.h>`, such as `islessgreater(x, y)` and `fpclassify(x)` from C++11, in addition to a few C23 functions like `iseqsig(x, y)`.

Include the `quadmath_cpp.h` header in your code to use it. The header should compile fine on GCC from C++98 to C++23

***

If you want to bring `quadmath_cpp` into the `std::` namespace, define `QUADMATH_CPP_NAMESPACE_STD` to non-zero before including the header.
```c++
#define QUADMATH_CPP_NAMESPACE_STD 1
#include "quadmath_cpp.h"
```
This will allow you to call `std::sin(x)` and `std::pow(x, y)`. However, extending the `std::` namespace is undefined behaviour, so take caution with this feature.
