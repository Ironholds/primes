#include <Rcpp.h>
#include <algorithm>
#include <vector>

#include "primes.h"

// [[Rcpp::interfaces(r, cpp)]]

static std::vector<int>::iterator
forward_search(std::vector<int>::iterator first,
               std::vector<int>::iterator last,
               int val) {
  for (; first != last && *first <= val; ++first)
    if (*first == val)
      return first;
  return last;
}

static std::vector<int>::iterator
match_tuple(std::vector<int>::iterator first,
            std::vector<int>::iterator last,
            const std::vector<int> &tuple) {
  int offset = *first;
  for (auto it = tuple.begin() + 1; it != tuple.end() && first != last; ++it)
    first = forward_search(first + 1, last, offset + *it);
  return first;
}

//' @rdname k_tuple
//' @export
// [[Rcpp::export]]
Rcpp::List k_tuple(int min, int max, std::vector<int> tuple) {
  Rcpp::List out;
  auto primes = generate_primes_(min, max);

  if (tuple.size() < 2)
    Rcpp::stop("`tuple` size must be at least 2.");
  if (tuple[0] != 0)
    Rcpp::stop("the first element of `tuple` must be zero.");
  if (!std::is_sorted(tuple.begin(), tuple.end()))
    Rcpp::stop("the elements of `tuple` must be in ascending order.");

  for (auto it = primes.begin();
       it != primes.end() && *it <= max - tuple.back(); ++it)
    if (match_tuple(it, primes.end(), tuple) != primes.end()) {
      std::vector<int> matching_set(tuple.begin(), tuple.end());
      for (auto &m : matching_set)
        m += *it;
      out.push_back(matching_set);
    }

  return out;
}

// Because sexy prime triplets stipulate that p + 18 is composite...
//' @rdname k_tuple
//' @export
// [[Rcpp::export]]
Rcpp::List sexy_prime_triplets(int min, int max) {
  Rcpp::List out;
  auto primes = generate_primes_(min, max + 6);
  std::vector<int> tuple = {0, 6, 12};

  for (auto it = primes.begin(); it != primes.end() && *it <= max - 12; ++it) {
    std::vector<int>::iterator tmp;
    if ((tmp = match_tuple(it, primes.end(), tuple)) != primes.end() &&
        forward_search(tmp + 1, primes.end(), *it + 18) == primes.end()) {
      std::vector<int> matching_set(tuple.begin(), tuple.end());
      for (auto &m : matching_set)
        m += *it;
      out.push_back(matching_set);
    }
  }

  return out;
}
