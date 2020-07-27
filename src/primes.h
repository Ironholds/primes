#ifndef R_PKG_PRIMES_H
#define R_PKG_PRIMES_H

#include <Rcpp.h>
#include <vector>
#include <cmath>
#include <algorithm>

// [[Rcpp::interfaces(r, cpp)]]
// [[Rcpp::plugins(cpp11)]]

std::vector<int> generate_primes_(int min, int max);
std::vector<int> generate_n_primes(int n);
int nth_prime(int n);
bool is_prime_(int x);
std::vector<bool> is_prime(std::vector<int> x);
Rcpp::IntegerVector next_prime(std::vector<int> x);
Rcpp::IntegerVector prev_prime(std::vector<int> x);
int prime_count(int n, bool upper_bound);
int nth_prime_estimate(int n, bool upper_bound);
Rcpp::List k_tuple(int min, int max, std::vector<int> tuple);
Rcpp::List prime_factors(std::vector<int> x);

#endif // R_PKG_PRIMES_H
