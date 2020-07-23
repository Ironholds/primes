#include "primes.hpp"

#define num2index(x) ((x) - 3) / 2
#define index2num(x) ((x) * 2) + 3

// [[Rcpp::export]]
std::vector<int> generate_primes_(int min, int max) {
  std::vector<int> out;
  if (max < 2)
    return out;

  int len = (max + 1)/2 - 1;
  std::vector<bool> a(len, true);
  for (int i=3, stop=sqrt(max); i <= stop; i+=2)
    if (a[num2index(i)] == true)
      for (int p=i*i, inc=i*2; p <= max; p+=inc)
        a[num2index(p)] = false;

  if (min <= 2)
    out.push_back(2);
  for (int i=std::max(0, (min - 2)/2); i < len; i++)
    if (a[i] == true)
      out.push_back(index2num(i));

  return out;
}

#undef num2index
#undef index2num
