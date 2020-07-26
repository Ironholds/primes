#include "primes.h"

//' Perform Prime Factorization on a Vector
//'
//' Compute the prime factors of elements of an integer vector.
//'
//' @param x an integer vector.
//'
//' @examples
//' prime_factor(c(1, 5:7, 99))
//' ## [[1]]
//' ## integer(0)
//' ##
//' ## [[2]]
//' ## [1] 5
//' ##
//' ## [[3]]
//' ## [1] 2 3
//' ##
//' ## [[4]]
//' ## [1] 7
//' ##
//' ## [[5]]
//' ## [1]  3  3 11
//'
//' @return A list of integer vectors reflecting the prime factorizations of
//'   each element of the input vector.
//' @author Paul Egeler, MS
//' @export
// [[Rcpp::export]]
Rcpp::List prime_factor(std::vector<int> x) {
  Rcpp::List out(x.size());
  auto it = out.begin();
  auto primes = generate_primes_(2, *std::max_element(x.begin(), x.end()));

  for (auto n : x) {
    std::vector<int> factors;
    auto p = primes.begin();
    while (n > 1) {
      while (n % *p == 0) {
        factors.push_back(*p);
        n /= *p;
      }
      p++;
    }
    *(it++) = factors;
  }

  return out;
}
