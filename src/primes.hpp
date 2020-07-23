#ifndef R_PKG_PRIMES_HPP
#define R_PKG_PRIMES_HPP

#include <vector>
#include <cmath>

// [[Rcpp::interfaces(r, cpp)]]
// [[Rcpp::plugins(cpp11)]]

std::vector<int> generate_primes_(int min, int max);
bool is_prime_single(int x);
std::vector<bool> is_prime_vector(std::vector<int> x);


#endif // R_PKG_PRIMES_HPP
