#include "primes.h"

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

  for (auto it = primes.begin(); it != primes.end(); ++it) {
    bool match = true;

    for (auto jt = tuple.begin() + 1; jt != tuple.end(); ++jt) {
      if (!binary_search(it, primes.end(), *it + *jt)) {
        match = false;
        break;
      }
    }

    if (match) {
      std::vector<int> matching_set(tuple.begin(), tuple.end());
      for (auto& m : matching_set)
        m += *it;
      out.push_back(matching_set);
    }
  }

  return out;
}
