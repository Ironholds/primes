#include "primes.h"

//' Prime _k_-tuples
//'
//' Use prime _k_-tuples to create lists of twin primes, cousin primes,
//' prime triplets, and so forth.
//'
//' @inheritParams generate_primes
//' @param tuple an integer vector representing the target _k_-tuple pattern.
//'
//' @examples
//' # All twin primes up to 13
//' k_tuple(2, 13, c(0,2))
//' ## [[1]]
//' ## [1] 3 5
//' ##
//' ## [[2]]
//' ## [1] 5 7
//' ##
//' ## [[3]]
//' ## [1] 11 13
//'
//' # Some prime triplets
//' k_tuple(2, 19, c(0,4,6))
//' ## [[1]]
//' ## [1]  7 11 13
//' ##
//' ## [[2]]
//' ## [1] 13 17 19
//'
//' @return A list of vectors of prime numbers satisfying the condition of
//'   `tuple`.
//' @export
// [[Rcpp::export]]
Rcpp::List k_tuple(int min, int max, std::vector<int> tuple) {
  Rcpp::List out;
  auto primes = generate_primes_(min, max);

  if (tuple.size() < 2)
    Rcpp::stop("`tuple` size must be at least 2.");
  if (tuple[0] != 0)
    Rcpp::stop("the first element of `tuple` must be zero.");

  for (auto it = primes.begin(); it != (primes.end() - tuple.size() + 1); ++it) {
    bool match = true;
    for (int j=1; j < tuple.size(); j++) {
      if (*(it + j) - *it != tuple[j]) {
        match = false;
        break;
      }
    }
    if (match) {
      std::vector<int> matching_set(it, it + tuple.size());
      out.push_back(matching_set);
    }
  }

  return out;
}
