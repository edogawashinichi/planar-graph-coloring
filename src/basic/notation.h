/// notation.h

/// notations for simplification

#pragma once

#include "global.h"
#include <iostream>
#include <vector>

namespace PlanarGraphColoring {

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

#define CUR_COLOR \
(PGC__COLOR_STACK.top() == 0 ? RED : (PGC__COLOR_STACK.top() == 1 ? GREEN : (PGC__COLOR_STACK.top() == 2 ? BLUE : YELLOW)))

#define PUSH_COLOR \
PGC__COLOR_STACK.push(PGC__PERIODIC_COLOR); \
PGC__PERIODIC_COLOR = (PGC__PERIODIC_COLOR + 1) % 4;

#define POP_COLOR \
PGC__COLOR_STACK.pop();

#define DEBUG \
if (PGC__DEBUG_MODE) \
  std::cout

#define INFO \
if (PGC__DEBUG_MODE || PGC__INFO_MODE) \
  std::cout

#define PGC__STR(s) \
std::string(#s)

#define DEBUG_START(s) \
if (PGC__DEBUG_MODE) { \
  PUSH_COLOR \
  std::cout << CUR_COLOR << "start " << RESET << PGC__STR(s) << "\n"; \
}

#define DEBUG_END(s) \
if (PGC__DEBUG_MODE) { \
  std::cout << CUR_COLOR << "end " << RESET << PGC__STR(s) << "\n"; \
  POP_COLOR \
}

#define TEST_DEBUG \
if (!PGC__DEBUG_MODE) return;

#define TEST_INFO \
if (!PGC__DEBUG_MODE && !PGC__INFO_MODE) return;

#define INFO_START(s) \
if (PGC__DEBUG_MODE || PGC__INFO_MODE) { \
  PUSH_COLOR \
  std::cout << CUR_COLOR << "start " << RESET << PGC__STR(s) << "\n"; \
}

#define INFO_END(s) \
if (PGC__DEBUG_MODE || PGC__INFO_MODE) { \
  std::cout << CUR_COLOR << "end " << RESET << PGC__STR(s) << "\n"; \
  POP_COLOR \
}

#define INFO_VAR(var) \
if (PGC__DEBUG_MODE || PGC__INFO_MODE) { \
  std::cout << PGC__STR(var) << "=" << (var) << "\n"; \
}

#define DEBUG_VAR(var) \
if (PGC__DEBUG_MODE) { \
  std::cout << PGC__STR(var) << "=" << (var) << "\n"; \
} 

#define INFO_2VAR(var, war) \
if (PGC__DEBUG_MODE || PGC__INFO_MODE) { \
  std::cout << PGC__STR(var) << "=" << (var) << " " << PGC__STR(war) << "=" << (war) << "\n"; \
}

#define DEBUG_2VAR(var, war) \
if (PGC__DEBUG_MODE) { \
  std::cout << PGC__STR(var) << "=" << (var) << " " << PGC__STR(war) << "=" << (war) << "\n"; \
}

#define PGC__SHOW_VAR(var) \
std::cout << PGC__STR(var) << "=" << (var) << "\n";

#define PGC__SHOW_2VAR(var, war) \
std::cout << PGC__STR(var) << "=" << (var) << "," << PGC__STR(war) << "=" << (war) << "\n";

#define PGC__SHOW_3VAR(uar, var, war) \
std::cout << PGC__STR(uar) << "=" << (uar) << "," << PGC__STR(var) << "=" << (var) << "," << PGC__STR(war) << "=" << (war) << "\n";

#define PGC__SHOW_VEC(vec) \
for (const auto& a : vec) {\
  std::cout << a << " ";\
}\
std::cout << "\n";

#define PGC__SHOW_VEC_WITH_ARROW(vec) \
if (!(vec).empty()) { \
for (size_t macro_i = 0; macro_i < (vec).size() - 1; ++macro_i) { \
  std::cout << (vec)[macro_i] << "->"; \
} \
std::cout << (vec).back() << "\n"; \
}

#define PGC__SHOW_VEC_WITH_INDEX(vec) \
for (size_t i = 0; i < vec.size(); ++i) {\
  std::cout << i << "th:" << vec[i] << " ";\
}\
std::cout << "\n";

#define PGC__SHOW_VII(vii) \
for (const auto& kv : vii) { \
  std::cout << kv.first << "," << kv.second << " "; \
} \
std::cout << "\n";

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
    if (kv.second == UNDEF_COLOR) { \
      std::cout << kv.first << ":" << RED << kv.second << RESET << " "; \
    } else { \
      std::cout << kv.first << ":" << C1 << kv.second << RESET << " "; \
    } \
  } \
} \
std::cout << "\n";

#define PGC__SHOW_MII(map) \
for (const auto& kv : map) { \
  std::cout << kv.first << ":" << kv.second << " "; \
} \
std::cout << "\n";

#define PGC__SHOW_VVI_WITH_INDEX(vvi) \
for (size_t i = 0; i < vvi.size(); ++i) { \
  std::cout << i << "th: "; \
  PGC__SHOW_VEC(vvi[i]) \
}

#define PGC__SHOW_MIVI__(map) \
for (const auto& kv : map) {\
  std::cout << kv.first << ": ";\
  PGC__SHOW_VEC(kv.second) \
}

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
PGC__STR_YELLOW(std::string(26, '-')) + PGC__STR_BLUE(PGC__STR(test_##i)) + PGC__STR_YELLOW(std::string(26, '-'))

#define PGC__SHOW_ENDL(s) \
std::cout << (s) << "\n";

#define PGC__TEST_RESULT_INFO(res, i) \
if (res) { \
  PGC__SHOW_ENDL(PGC__TEST_PASS_INFO(i)) \
} else { \
  PGC__SHOW_ENDL(PGC__TEST_FAIL_INFO(i)) \
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

#define PGC__MAIN_START \
int main(int argc, char* argv[]) { \
  CHECK_DEBUG_MODE \
  CHECK_INFO_MODE \

#define PGC__MAIN_END \
  DEBUG << GREEN << "return from main!\n" << RESET; \
  return 0; \
}

}/// namespace PlanarGraphColoring
