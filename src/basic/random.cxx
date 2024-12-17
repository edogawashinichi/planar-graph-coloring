/// random.cxx

#include "random.h"
#include "global.h"
#include "math.h"
#include <random>
#include <chrono>

#define GET_TIMESTAMP(timestamp) \
auto now = std::chrono::system_clock::now(); \
auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()); \
auto timestamp = static_cast<unsigned int>(ms.count());

#define UPDATE_HISTORY_SEED(adder) \
PGC__HISTORY_SEED += adder;

#define RANDOM_ENVIRONMENT(random_engine) \
std::random_device device; \
unsigned int device_adder = device(); \
UPDATE_HISTORY_SEED(device_adder) \
GET_TIMESTAMP(timestamp) \
UPDATE_HISTORY_SEED(timestamp) \
std::mt19937 random_engine(PGC__HISTORY_SEED); 

#define UNIFORM_DISTRIBUTION(sum, res) \
RANDOM_ENVIRONMENT(engine) \
std::uniform_int_distribution<int> distribution(0, sum - 1); \
const unsigned int res = distribution(engine);

namespace PlanarGraphColoring {

bool bet(const float probability) {
  const unsigned int N = 1000000;
  UNIFORM_DISTRIBUTION(N, res)
  return res < N * probability;
}/// bet

VI randomChoose(const size_t n, const size_t k) {
  RANDOM_ENVIRONMENT(random_engine)
  VI all = id<size_t>(n);
  std::shuffle(all.begin(), all.end(), random_engine);
  return VI(all.begin(), all.begin() + k);
}/// randomChoose

}/// namespace PlanarGraphColoring
