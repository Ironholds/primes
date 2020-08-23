#include "primes.h"

static inline int num2index(int x) {
  return (x - 3) / 2;
}

static inline int index2num(int x) {
  return (x * 2) + 3;
}

static inline int estimate_output_size(int min, int max) {
  return std::max(100, prime_count(max, true) - prime_count(min, false));
}

// [[Rcpp::export]]
std::vector<int> generate_primes_(int min, int max) {
  if (max < 2 || min > max)
    return {};

  int len = (max + 1)/2 - 1;
  std::vector<bool> a(len, true);
  for (int i=3, stop=sqrt((double) max); i <= stop; i+=2)
    if (a[num2index(i)])
      for (int p=i*i, inc=i*2; p <= max; p+=inc)
        a[num2index(p)] = false;

  std::vector<int> out;
  out.reserve(estimate_output_size(min, max));

  if (min <= 2)
    out.push_back(2);
  for (int i=std::max(0, (min - 2)/2); i < len; i++)
    if (a[i])
      out.push_back(index2num(i));

  return out;
}
