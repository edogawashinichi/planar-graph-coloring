/// notation.h

/// notations for simplification

/// TODO: use C++11 feature typename... Args
/// TODO:   instead of VAR 2VAR 3VAR

#pragma once

#include "global.h"
#include <iostream>
#include <vector>
#include <unordered_set>

namespace PlanarGraphColoring {

/* void type not included */
#define FUNDAMENTAL_TYPE(var) \
( \
typeid(var) == typeid(int) || \
typeid(var) == typeid(short) || \
typeid(var) == typeid(long) || \
typeid(var) == typeid(long long) || \
typeid(var) == typeid(unsigned) || \
typeid(var) == typeid(unsigned short) || \
typeid(var) == typeid(unsigned long) ||\
typeid(var) == typeid(unsigned long long) || \
typeid(var) == typeid(float) || \
typeid(var) == typeid(double) || \
typeid(var) == typeid(long double) || \
typeid(var) == typeid(char) || \
typeid(var) == typeid(unsigned char) || \
typeid(var) == typeid(signed char) || \
typeid(var) == typeid(wchar_t) || \
typeid(var) == typeid(char16_t) || \
typeid(var) == typeid(char32_t) || \
typeid(var) == typeid(bool) \
)

/// singleton pattern

#define SINGLETON_ASSERTION(Class) \
private: \
  inline Class() = default; \
public: \
  inline ~Class() = default; \
  inline Class(const Class&) = delete; \
  inline Class& operator=(const Class&) = delete; \
  inline static Class& getInstance() { \
    static Class instance; \
    return instance; \
  }

/// macro for a class Class with container member mem_

#define CLASS_CONSTRUCTOR_DEFAULT(Class, mem_) \
inline Class() { \
  mem_.clear(); \
}

#define CLASS_CONSTRUCTOR_DELETE(Class, mem_) \
inline Class() = delete;

#define INNER_CLASS_SET_DEEPCOPY(rhs, mem_) \
if (this != &rhs) { \
  mem_ = rhs.mem_; \
}

#define CLASS_SET_DEEPCOPY(Class, mem_) \
inline void set(const Class& rhs) { \
  INNER_CLASS_SET_DEEPCOPY(rhs, mem_) \
}

#define CLASS_CONSTRUCTOR_DEEPCOPY(Class, mem_) \
inline Class(const Class& rhs) { \
  INNER_CLASS_SET_DEEPCOPY(rhs, mem_) \
}

#define CLASS_CONSTRUCTOR_MOVECOPY(Class, mem_) \
inline Class(Class&& rhs) { \
  if (this != &rhs) { \
    std::swap(mem_, rhs.mem_); \
  } \
}

#define CLASS_ASSIGNMENT_DEEPCOPY(Class, mem_) \
inline Class& operator=(const Class& rhs) { \
  if (this != &rhs) { \
    mem_ = rhs.mem_; \
  } \
  return *this; \
}

#define CLASS_ASSIGNMENT_MOVECOPY(Class, mem_) \
inline Class& operator=(Class&& rhs) { \
  if (this != &rhs) { \
    std::swap(mem_, rhs.mem_); \
  } \
  return *this; \
}

#define CLASS_4_FUNCTIONS(Class, mem_) \
CLASS_CONSTRUCTOR_DEEPCOPY(Class, mem_) \
CLASS_SET_DEEPCOPY(Class, mem_) \
CLASS_CONSTRUCTOR_MOVECOPY(Class, mem_) \
CLASS_ASSIGNMENT_DEEPCOPY(Class, mem_) \
CLASS_ASSIGNMENT_MOVECOPY(Class, mem_)

#define CLASS_5_FUNCTIONS(Class, mem_) \
CLASS_CONSTRUCTOR_DEFAULT(Class, mem_) \
CLASS_4_FUNCTIONS(Class, mem_)

/// macro for a derived class Derived from a base class Base

#define DERIVE_CLASS_CONSTRUCTOR_DEFAULT(Derived, Base) \
inline Derived() : Base() {}

#define DERIVE_CLASS_CONSTRUCTOR_DEEPCOPY(Derived, Base) \
inline Derived(const Derived& rhs) { \
  if (this != &rhs) { \
    Base::get() = rhs.getConst(); \
  } \
}

#define DERIVE_CLASS_CONSTRUCTOR_MOVECOPY(Derived, Base) \
inline Derived(Derived&& rhs) { \
  if (this != &rhs) { \
    Base::get().swap(rhs.get()); \
  } \
}

#define DERIVE_CLASS_ASSIGNMENT_DEEPCOPY(Derived, Base) \
inline Derived& operator=(const Derived& rhs) { \
  if (this != &rhs) { \
    Base::get() = rhs.getConst(); \
  } \
  return *this; \
}

#define DERIVE_CLASS_ASSIGNMENT_MOVECOPY(Derived, Base) \
inline Derived& operator=(Derived&& rhs) { \
  if (this != &rhs) { \
    Base::get().swap(rhs.get()); \
  } \
  return *this; \
}

#define DERIVE_CLASS_4_FUNCTIONS(Derived, Base) \
DERIVE_CLASS_CONSTRUCTOR_DEEPCOPY(Derived, Base) \
DERIVE_CLASS_CONSTRUCTOR_MOVECOPY(Derived, Base) \
DERIVE_CLASS_ASSIGNMENT_DEEPCOPY(Derived, Base) \
DERIVE_CLASS_ASSIGNMENT_MOVECOPY(Derived, Base)

#define DERIVE_CLASS_5_FUNCTIONS(Derived, Base) \
DERIVE_CLASS_CONSTRUCTOR_DEFAULT(Derived, Base) \
DERIVE_CLASS_4_FUNCTIONS(Derived, Base)

#define RESET "\033[0m"
#define BLACK "\033[30m"  /* Black */
#define RED "\033[31m"    /* Red */
#define GREEN "\033[32m"  /* Green */
#define YELLOW "\033[33m" /* Yellow */
#define BLUE "\033[34m"   /* Blue */
#define PURPLE "\033[35m" /* Purple */
#define CYAN "\033[36m"   /* Cyan */
#define WHITE "\033[37m"  /* White */

#define TAB "  "

/// WARNING: stack empty
#define CUR_COLOR \
(PGC__COLOR_STACK.empty() ? CYAN : (PGC__COLOR_STACK.top() == 0 ? RED : (PGC__COLOR_STACK.top() == 1 ? GREEN : (PGC__COLOR_STACK.top() == 2 ? BLUE : YELLOW))))

#define PUSH_COLOR \
PGC__COLOR_STACK.push(PGC__PERIODIC_COLOR); \
PGC__PERIODIC_COLOR = (PGC__PERIODIC_COLOR + 1) % 4;

#define POP_COLOR \
PGC__COLOR_STACK.pop();

/*
 * VERBOSE: print all messages
 * DEBUG :  print all key messages
 * INFO :   print all messages of output
*/

#define VERBOSE \
if (PGC__VERBOSE_MODE) \
  std::cout

#define DEBUG \
if (PGC__VERBOSE_MODE || PGC__DEBUG_MODE) \
  std::cout

#define VERBOSE_OBJ(obj) \
if (PGC__VERBOSE_MODE) { \
  std::cout << PGC__STR(obj) << ":\n"; \
  (obj).show(std::cout); \
}

#define DEBUG_OBJ(obj) \
if (PGC__VERBOSE_MODE || PGC__DEBUG_MODE) { \
  std::cout << PGC__STR(obj) << ":\n"; \
  (obj).show(std::cout); \
}

#define DEBUG_FLAG_OBJ(flag, obj) \
if (flag) { \
  DEBUG << PGC__STR(flag) << " ok\n"; \
  DEBUG_OBJ(obj) \
} else { \
  DEBUG << PGC__STR(flag) << " failed\n"; \
}

#define INFO \
if (PGC__VERBOSE_MODE || PGC__DEBUG_MODE || PGC__INFO_MODE) \
  std::cout

#define INFO_OBJ(obj) \
if (PGC__VERBOSE_MODE || PGC__DEBUG_MODE || PGC__INFO_MODE) { \
  std::cout << PGC__STR(obj) << ":\n"; \
  (obj).show(std::cout); \
}

#define INFO_FLAG_OBJ(flag, obj) \
if (flag) { \
  INFO << PGC__STR(flag) << " ok\n"; \
  INFO_OBJ(obj) \
} else { \
  INFO << PGC__STR(flag) << " failed\n"; \
}

#define PGC__STR(s) \
std::string(#s)

#define VERBOSE_START(s) \
if (PGC__VERBOSE_MODE) { \
  PUSH_COLOR \
  std::cout << CUR_COLOR << "start " << RESET << PGC__STR(s) << "\n"; \
}

#define DEBUG_START(s) \
if (PGC__VERBOSE_MODE || PGC__DEBUG_MODE) { \
  PUSH_COLOR \
  std::cout << CUR_COLOR << "start " << RESET << PGC__STR(s) << "\n"; \
}

#define VERBOSE_END(s) \
if (PGC__VERBOSE_MODE) { \
  std::cout << CUR_COLOR << "end " << RESET << PGC__STR(s) << "\n"; \
  POP_COLOR \
}

#define DEBUG_END(s) \
if (PGC__VERBOSE_MODE || PGC__DEBUG_MODE) { \
  std::cout << CUR_COLOR << "end " << RESET << PGC__STR(s) << "\n"; \
  POP_COLOR \
}

#define TEST_VERBOSE \
if (!PGC__VERBOSE_MODE) return;

#define TEST_DEBUG \
if (!PGC__VERBOSE_MODE && !PGC__DEBUG_MODE) return;

#define TEST_INFO \
if (!PGC__VERBOSE_MODE && !PGC__DEBUG_MODE && !PGC__INFO_MODE) return;

#define INFO_START(s) \
if (PGC__VERBOSE_MODE || PGC__DEBUG_MODE || PGC__INFO_MODE) { \
  PUSH_COLOR \
  std::cout << CUR_COLOR << "start " << RESET << PGC__STR(s) << "\n"; \
}

#define INFO_END(s) \
if (PGC__VERBOSE_MODE || PGC__DEBUG_MODE || PGC__INFO_MODE) { \
  std::cout << CUR_COLOR << "end " << RESET << PGC__STR(s) << "\n"; \
  POP_COLOR \
}

#define INFO_VAR(var) \
if (PGC__VERBOSE_MODE || PGC__DEBUG_MODE || PGC__INFO_MODE) { \
  std::cout << PGC__STR(var) << "=" << (var) << "\n"; \
}

#define DEBUG_VAR(var) \
if (PGC__VERBOSE_MODE || PGC__DEBUG_MODE) { \
  std::cout << PGC__STR(var) << "=" << (var) << "\n"; \
} 

#define VERBOSE_VAR(var) \
if (PGC__VERBOSE_MODE) { \
  std::cout << PGC__STR(var) << "=" << (var) << "\n"; \
} 

#define INFO_2VAR(var, war) \
if (PGC__VERBOSE_MODE || PGC__DEBUG_MODE || PGC__INFO_MODE) { \
  std::cout << PGC__STR(var) << "=" << (var) << " " << PGC__STR(war) << "=" << (war) << "\n"; \
}

#define INFO_PAIR(pair) \
INFO << PGC__STR(pair) << "={" << (pair).first << "," << (pair).second << "}\n";

#define DEBUG_2VAR(var, war) \
if (PGC__VERBOSE_MODE || PGC__DEBUG_MODE) { \
  std::cout << PGC__STR(var) << "=" << (var) << " " << PGC__STR(war) << "=" << (war) << "\n"; \
}

#define DEBUG_PAIR(pair) \
DEBUG << PGC__STR(pair) << "={" << (pair).first << "," << (pair).second << "}\n";

#define VERBOSE_2VAR(var, war) \
if (PGC__VERBOSE_MODE) { \
  std::cout << PGC__STR(var) << "=" << (var) << " " << PGC__STR(war) << "=" << (war) << "\n"; \
}

#define VERBOSE_PAIR(pair) \
VERBOSE << PGC__STR(pair) << "={" << (pair).first << "," << (pair).second << "}\n";

#define SHOW_SPACE(k) \
std::cout << std::string(k, ' ');

#define SHOW_ENDL \
std::cout << "\n";

#define SHOW_VAR(var) \
std::cout << PGC__STR(var) << "=" << (var);

#define SHOW_VAR_SPC(var, k) \
SHOW_VAR(var) \
SHOW_SPACE(k)

#define SHOW_VAR_NDL(var) \
SHOW_VAR(var) \
SHOW_ENDL

#define PGC__SHOW_VAR(var) \
std::cout << PGC__STR(var) << "=" << (var) << "\n";

#define PGC__SHOW_2VAR(var, war) \
std::cout << PGC__STR(var) << "=" << (var) << "," << PGC__STR(war) << "=" << (war) << "\n";

#define PGC__SHOW_3VAR(uar, var, war) \
std::cout << PGC__STR(uar) << "=" << (uar) << "," << PGC__STR(var) << "=" << (var) << "," << PGC__STR(war) << "=" << (war) << "\n";

#define PGC__SHOW_4VAR(a, b, c, d) \
SHOW_VAR_SPC(a, 2) \
SHOW_VAR_SPC(b, 2) \
SHOW_VAR_SPC(c, 2) \
SHOW_VAR_NDL(d)

#define INFO_3VAR(uar, var, war) \
if (PGC__VERBOSE_MODE || PGC__DEBUG_MODE || PGC__INFO_MODE ) { \
  PGC__SHOW_3VAR(uar, var, war) \
}

#define DEBUG_3VAR(uar, var, war) \
if (PGC__VERBOSE_MODE || PGC__DEBUG_MODE) { \
  PGC__SHOW_3VAR(uar, var, war) \
}

#define VERBOSE_3VAR(uar, var, war) \
if (PGC__VERBOSE_MODE) { \
  PGC__SHOW_3VAR(uar, var, war) \
}

#define VERBOSE_4VAR(a, b, c, d) \
if (PGC__VERBOSE_MODE) { \
  PGC__SHOW_4VAR(a, b, c, d) \
}

#define LL long long
#define II std::pair<size_t, size_t>
#define VC std::vector<char>
#define VI std::vector<size_t>
#define SI std::unordered_set<size_t>
#define VII std::vector<std::pair<size_t, size_t>>
#define VVI std::vector<std::vector<size_t>>
#define VSI std::vector<std::unordered_set<size_t>>

#define PGC__SHOW_VEC(cout, vec) \
for (const auto& a : vec) { \
  (cout) << a << " "; \
} \
(cout) << "\n";

#define PGC__DEBUG_VEC(cout, vec) \
if (PGC__VERBOSE_MODE || PGC__DEBUG_MODE) { \
  PGC__SHOW_VEC(cout, vec) \
}

#define DEBUG_VEC(vec) PGC__DEBUG_VEC(std::cout, vec)

#define INFO_VEC(vec) \
if (PGC__VERBOSE_MODE || PGC__DEBUG_MODE || PGC__INFO_MODE) { \
  PGC__SHOW_VEC(std::cout, vec) \
}

#define VERBOSE_VEC(vec) \
if (PGC__VERBOSE_MODE) { \
  PGC__SHOW_VEC(std::cout, vec) \
}

#define SHOW_SET(cout, set) \
for (const auto& a : set) { \
  (cout) << a << " "; \
} \
(cout) << "\n";

#define INFO_SET(set) \
if (PGC__VERBOSE_MODE || PGC__DEBUG_MODE || PGC__INFO_MODE) { \
  SHOW_SET(std::cout, set) \
}

#define DEBUG_SET(set) \
if (PGC__VERBOSE_MODE || PGC__DEBUG_MODE) { \
  SHOW_SET(std::cout, set) \
}

#define VERBOSE_SET(set) \
if (PGC__VERBOSE_MODE) { \
  SHOW_SET(std::cout, set) \
}

#define PGC__SHOW_VEC_WITH_ARROW(cout, vec) \
if (!(vec).empty()) { \
for (size_t macro_i = 0; macro_i < (vec).size() - 1; ++macro_i) { \
  (cout) << (vec)[macro_i] << "->"; \
} \
(cout) << (vec).back() << "\n"; \
}

#define SHOW_CHAR_WITH_WHITE(cout, c) \
(cout) << WHITE << (c) << RESET;

#define SHOW_INDEX_WITH_COLOR(cout, i, color_flag) \
if (color_flag) { \
  (cout) << CUR_COLOR << i << RESET << "th: "; \
} else { \
  (cout) << i << "th: "; \
}

#define SHOW_CHAR_WITH_COLOR(cout, c) \
if ('r' == (c) || 'R' == (c)) { \
  (cout) << RED << (c) << RESET; \
} else if ('g' == (c) || 'G' == (c)){ \
  (cout) << GREEN << (c) << RESET; \
} else if ('b' == (c) || 'B' == (c)) { \
  (cout) << BLUE << (c) << RESET; \
} else if ('y' == (c) || 'Y' == (c)) { \
  (cout) << YELLOW << (c) << RESET; \
} else { \
  (cout) << WHITE << (c) << RESET; \
}

#define SHOW_COLORING_WITH_INDEX(cout, coloring, not_white_flag) \
for (size_t i = 0; i < (coloring).size(); ++i) { \
  (cout) << i << ":"; \
  if (not_white_flag) { \
    SHOW_CHAR_WITH_COLOR(cout, (coloring)[i].get()) \
  } else { \
    SHOW_CHAR_WITH_WHITE(cout, (coloring)[i].get()) \
  } \
  (cout) << " "; \
} \
(cout) << "\n";

#define PGC__SHOW_VEC_WITH_INDEX(cout, vec) \
for (size_t i = 0; i < vec.size(); ++i) {\
  (cout) << i << "th:" << vec[i] << " ";\
}\
(cout) << "\n";

#define PGC__SHOW_VII(cout, vii) \
for (const auto& kv : vii) { \
  (cout) << kv.first << "," << kv.second << " "; \
} \
(cout) << "\n";

#define PGC__DEBUG_VII(cout, vii) \
if (PGC__VERBOSE_MODE || PGC__DEBUG_MODE) { \
  PGC__SHOW_VII(cout, vii) \
}

#define DEBUG_VII(vii) \
PGC__DEBUG_VII(std::cout, vii)

#define INFO_VII(vii) \
if (PGC__VERBOSE_MODE || PGC__DEBUG_MODE || PGC__INFO_MODE) { \
  PGC__SHOW_VII(std::cout, vii) \
}

#define PGC__SHOW_VII_WITH_COLOR(cout, vii, COLOR) \
for (const auto& kv : vii) { \
  (cout) << kv.first << ":" << COLOR << kv.second << RESET << " "; \
} \
(cout) << "\n";

#define PGC__SHOW_VII_WITH_COLOR_SEP(cout, vii, k, C0, C1) \
for (size_t i = 0; i < vii.size(); ++i) { \
  const auto& kv = vii[i]; \
  if (i < k) { \
    (cout) << kv.first << ":" << C0 << kv.second << RESET << " "; \
  } else { \
    if (kv.second == static_cast<char>(UNDEF_COLOR + 'a')) { \
      (cout) << kv.first << ":" << RED << kv.second << RESET << " "; \
    } else { \
      (cout) << kv.first << ":" << C1 << kv.second << RESET << " "; \
    } \
  } \
} \
(cout) << "\n";

#define PGC__SHOW_MII(cout, map) \
for (const auto& kv : map) { \
  (cout) << kv.first << ":" << kv.second << " "; \
} \
(cout) << "\n";

#define PGC__SHOW_VVI(cout, vvi) \
for (const auto& vi :(vvi)) { \
  PGC__SHOW_VEC(cout, vi) \
}

#define PGC__SHOW_VVI_WITH_INDEX(cout, vvi) \
for (size_t i = 0; i < vvi.size(); ++i) { \
  (cout) << i << "th: "; \
  PGC__SHOW_VEC(cout, vvi[i]) \
}

#define INFO_VVI_WITH_INDEX(vvi) \
if (PGC__VERBOSE_MODE || PGC__DEBUG_MODE || PGC__INFO_MODE) { \
  PGC__SHOW_VVI_WITH_INDEX(std::cout, vvi) \
}

#define DEBUG_VVI_WITH_INDEX(vvi) \
if (PGC__VERBOSE_MODE || PGC__DEBUG_MODE) { \
  PGC__SHOW_VVI_WITH_INDEX(std::cout, vvi) \
}

#define VERBOSE_VVI_WITH_INDEX(vvi) \
if (PGC__VERBOSE_MODE) { \
  PGC__SHOW_VVI_WITH_INDEX(std::cout, vvi) \
}

#define PGC__DEBUG_VVI(cout, vvi) \
if (PGC__DEBUG_MODE) { \
  for (const auto& vi : vvi) { \
    (cout) << "{ "; \
    for (const auto& i : vi) { \
      (cout) << i << " "; \
    } \
    (cout) << "} "; \
  } \
  (cout) << "\n"; \
}

#define PGC__SHOW_MIVI__(cout, map) \
for (const auto& kv : map) {\
  (cout) << kv.first << ": ";\
  PGC__SHOW_VEC(cout, kv.second) \
}

#define PGC__STR_RED(s) \
std::string(RED) + std::string(s) + std::string(RESET)

#define PGC__STR_GREEN(s) \
std::string(GREEN) + std::string(s) + std::string(RESET)

#define PGC__STR_YELLOW(s) \
std::string(YELLOW) + std::string(s) + std::string(RESET)

#define PGC__STR_BLUE(s) \
std::string(BLUE) + std::string(s) + std::string(RESET)

#define PGC__STR_PURPLE(s) \
std::string(PURPLE) + std::string(s) + std::string(RESET)

#define PGC__STR_CYAN(s) \
std::string(CYAN) + std::string(s) + std::string(RESET)

#define PGC__TEST_FAIL_INFO(i) \
PGC__STR_BLUE(PGC__STR(test_##i)) + " " + PGC__STR_RED("FAILED") + "!"

#define PGC__TEST_PASS_INFO(i) \
PGC__STR_BLUE(PGC__STR(test_##i)) + " " + PGC__STR_GREEN("PASSED") + "!"

#define PGC__TEST_SEPAR(i) \
PGC__STR_YELLOW(std::string(26, '-')) + PGC__STR_BLUE(PGC__STR(test_##i)) + PGC__STR_YELLOW(std::string(26, '-'))

#define PGC__SHOW_ENDL(cout, s) \
(cout) << (s) << "\n";

#define PGC__TEST_RESULT_INFO(res, i) \
if (res) { \
  PGC__SHOW_ENDL(std::cout, PGC__TEST_PASS_INFO(i)) \
} else { \
  PGC__SHOW_ENDL(std::cout, PGC__TEST_FAIL_INFO(i)) \
}

#define CHECK_VERBOSE_MODE \
const std::vector<std::string> verboses = { \
  "verbose", "v", "VERBOSE", "V", "Verbose" \
}; \
if (argc > 1) { \
  for (const auto& verbose : verboses) { \
    if (verbose == std::string(argv[1])) { \
      PGC__VERBOSE_MODE = true; \
      break; \
    } \
  } \
  if (PGC__VERBOSE_MODE) { \
    std::cout << "mode: " << GREEN << "verbose" << RESET << "\n"; \
  } else { \
    std::cout << "verbose mode parameter: "; \
    for (const auto& verbose : verboses) { \
      std::cout << RED << verbose << RESET << " "; \
    } \
    std::cout << "\n"; \
  } \
} else { \
  std::cout << "verbose mode usage:\n"; \
  std::cout << RED << "./_build_xx.sh verbose" << RESET << "\n"; \
}

#define CHECK_DEBUG_MODE \
const std::vector<std::string> debugs = { \
  "debug", "d", "DEBUG", "D", "Debug" \
}; \
if (argc > 1) { \
  for (const auto& debug : debugs) { \
    if (debug == std::string(argv[1])) { \
      PGC__DEBUG_MODE = true; \
      break; \
    } \
  } \
  if (PGC__DEBUG_MODE) { \
    std::cout << "mode: " << GREEN << "debug" << RESET << "\n"; \
  } else { \
    std::cout << "debug mode parameter: "; \
    for (const auto& debug : debugs) { \
      std::cout << RED << debug << RESET << " "; \
    } \
    std::cout << "\n"; \
  } \
} else { \
  std::cout << "debug mode usage:\n"; \
  std::cout << RED << "./_build_xx.sh debug" << RESET << "\n"; \
}

#define CHECK_INFO_MODE \
const std::vector<std::string> infos = { \
  "info", "i", "INFO", "I", "Info" \
}; \
if (argc > 1) { \
  for (const auto& info : infos) { \
    if (info == std::string(argv[1])) { \
      PGC__INFO_MODE = true; \
      break; \
    } \
  } \
  if (PGC__INFO_MODE) { \
    std::cout << "mode: " << GREEN << "info" << RESET << "\n"; \
  } else { \
    std::cout << "info mode parameter: "; \
    for (const auto& info : infos) { \
      std::cout << RED << info << RESET << " "; \
    } \
    std::cout << "\n"; \
  } \
} else { \
  std::cout << "info mode usage:\n"; \
  std::cout << RED << "./_build_xx.sh info" << RESET << "\n"; \
}

#define TEST_START(i) \
void test_##i() { \
  PGC__SHOW_ENDL(std::cout, PGC__TEST_SEPAR(i))

#define TEST_END(i) \
  PGC__TEST_RESULT_INFO(res, i) \
  PGC__SHOW_ENDL(std::cout, PGC__TEST_SEPAR(i)) \
}

#define TEST(i) test_##i();

#define PGC__MAIN_START \
int main(int argc, char* argv[]) { \
  CHECK_VERBOSE_MODE \
  CHECK_DEBUG_MODE \
  CHECK_INFO_MODE \

#define PGC__MAIN_END \
  DEBUG << GREEN << "return from main!\n" << RESET; \
  return 0; \
}

#define INFO_(var) \
if (FUNDAMENTAL_TYPE(var)) { \
  INFO_VAR(var) \
} else { \
  INFO_OBJ(var) \
}

#define DEBUG_(var) \
if (FUNDAMENTAL_TYPE(var)) { \
  DEBUG_VAR(var) \
} else { \
  DEBUG_OBJ(var) \
}

#define VERBOSE_(var) \
if (FUNDAMENTAL_TYPE(var)) { \
  VERBOSE_VAR(var) \
} else { \
  VERBOSE_OBJ(var) \
}

}/// namespace PlanarGraphColoring
