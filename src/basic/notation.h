/// notation.h

/// notations for simplification

#pragma once

#include <iostream>

namespace PlanarGraphColoring {

#define PGC__SHOW_VEC__(vec) \
for (const auto& a : vec) {\
  std::cout << a << " ";\
}\
std::cout << "\n";

#define PGC__SHOW_VEC_WITH_INDEX__(vec) \
for (size_t i = 0; i < vec.size(); ++i) {\
  std::cout << i << "th:" << vec[i] << " ";\
}\
std::cout << "\n";

#define RESET "\033[0m"
#define BLACK "\033[30m"  /* Black */
#define RED "\033[31m"    /* Red */
#define GREEN "\033[32m"  /* Green */
#define YELLOW "\033[33m" /* Yellow */
#define BLUE "\033[34m"   /* Blue */
#define PURPLE "\033[35m" /* Purple */
#define CYAN "\033[36m"   /* Cyan */
#define WHITE "\033[37m"  /* White */

#define PGC__SHOW_VII_WITH_COLOR(vii, COLOR) \
for (const auto& kv : vii) { \
  std::cout << kv.first << ":" << COLOR << kv.second << RESET << " "; \
} \
std::cout << "\n";

#define PGC__SHOW_VII_WITH_COLOR_SEP(vii, k, C0, C1) \
for (size_t i = 0; i < vii.size(); ++i) { \
  const auto& kv = vii[i]; \
  if (i < k) { \
    std::cout << kv.first << ":" << C0 << kv.second << RESET << " "; \
  } else { \
    std::cout << kv.first << ":" << C1 << kv.second << RESET << " "; \
  } \
} \
std::cout << "\n";

#define PGC__SHOW_MII(map) \
for (const auto& kv : map) { \
  std::cout << kv.first << ":" << kv.second << " "; \
} \
std::cout << "\n";

#define PGC__SHOW_MIVI__(map) \
for (const auto& kv : map) {\
  std::cout << kv.first << ": ";\
  PGC__SHOW_VEC__(kv.second) \
}

#define PGC__STR(s) \
std::string(#s)

#define PGC__STR_RED(s) \
std::string("\033[31m") + std::string(s) + std::string("\033[0m")

#define PGC__STR_GREEN(s) \
std::string("\033[32m") + std::string(s) + std::string("\033[0m")

#define PGC__STR_YELLOW(s) \
std::string("\033[33m") + std::string(s) + std::string("\033[0m")

#define PGC__STR_BLUE(s) \
std::string("\033[34m") + std::string(s) + std::string("\033[0m")

#define PGC__STR_VIOLET(s) \
std::string("\033[35m") + std::string(s) + std::string("\033[0m")

#define PGC__TEST_FAIL_INFO(i) \
PGC__STR_BLUE(PGC__STR(test_##i)) + " " + PGC__STR_RED("FAILED") + "!"

#define PGC__TEST_PASS_INFO(i) \
PGC__STR_BLUE(PGC__STR(test_##i)) + " " + PGC__STR_GREEN("PASSED") + "!"

#define PGC__TEST_SEPAR(i) \
PGC__STR_YELLOW(std::string(32, '-')) + PGC__STR_BLUE(PGC__STR(test_##i)) + PGC__STR_YELLOW(std::string(32, '-'))

#define PGC__SHOW_ENDL(s) \
std::cout << (s) << "\n";

#define PGC__TEST_RESULT_INFO(res, i) \
if (res) { \
  PGC__SHOW_ENDL(PGC__TEST_PASS_INFO(i)) \
} else { \
  PGC__SHOW_ENDL(PGC__TEST_FAIL_INFO(i)) \
}

}/// namespace PlanarGraphColoring
