// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include "../inst/include/primes.h"
#include <Rcpp.h>
#include <string>
#include <set>

using namespace Rcpp;

// is_prime
std::vector<bool> is_prime(std::vector<int> x);
RcppExport SEXP _primes_is_prime(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<int> >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(is_prime(x));
    return rcpp_result_gen;
END_RCPP
}
// k_tuple
Rcpp::List k_tuple(int min, int max, std::vector<int> tuple);
RcppExport SEXP _primes_k_tuple(SEXP minSEXP, SEXP maxSEXP, SEXP tupleSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type min(minSEXP);
    Rcpp::traits::input_parameter< int >::type max(maxSEXP);
    Rcpp::traits::input_parameter< std::vector<int> >::type tuple(tupleSEXP);
    rcpp_result_gen = Rcpp::wrap(k_tuple(min, max, tuple));
    return rcpp_result_gen;
END_RCPP
}
// next_prime
Rcpp::IntegerVector next_prime(std::vector<int> x);
RcppExport SEXP _primes_next_prime(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<int> >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(next_prime(x));
    return rcpp_result_gen;
END_RCPP
}
// prev_prime
Rcpp::IntegerVector prev_prime(std::vector<int> x);
RcppExport SEXP _primes_prev_prime(SEXP xSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::vector<int> >::type x(xSEXP);
    rcpp_result_gen = Rcpp::wrap(prev_prime(x));
    return rcpp_result_gen;
END_RCPP
}
// prime_count
int prime_count(int n, bool upper_bound);
RcppExport SEXP _primes_prime_count(SEXP nSEXP, SEXP upper_boundSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< bool >::type upper_bound(upper_boundSEXP);
    rcpp_result_gen = Rcpp::wrap(prime_count(n, upper_bound));
    return rcpp_result_gen;
END_RCPP
}
// primorial_n
int primorial_n(int n);
RcppExport SEXP _primes_primorial_n(SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(primorial_n(n));
    return rcpp_result_gen;
END_RCPP
}
// primorial_p
int primorial_p(int n);
RcppExport SEXP _primes_primorial_p(SEXP nSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    rcpp_result_gen = Rcpp::wrap(primorial_p(n));
    return rcpp_result_gen;
END_RCPP
}
// generate_primes_
std::vector<int> generate_primes_(int min, int max);
RcppExport SEXP _primes_generate_primes_(SEXP minSEXP, SEXP maxSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type min(minSEXP);
    Rcpp::traits::input_parameter< int >::type max(maxSEXP);
    rcpp_result_gen = Rcpp::wrap(generate_primes_(min, max));
    return rcpp_result_gen;
END_RCPP
}

// validate (ensure exported C++ functions exist before calling them)
static int _primes_RcppExport_validate(const char* sig) { 
    static std::set<std::string> signatures;
    if (signatures.empty()) {
    }
    return signatures.find(sig) != signatures.end();
}

// registerCCallable (register entry points for exported C++ functions)
RcppExport SEXP _primes_RcppExport_registerCCallable() { 
    R_RegisterCCallable("primes", "_primes_RcppExport_validate", (DL_FUNC)_primes_RcppExport_validate);
    return R_NilValue;
}

static const R_CallMethodDef CallEntries[] = {
    {"_primes_is_prime", (DL_FUNC) &_primes_is_prime, 1},
    {"_primes_k_tuple", (DL_FUNC) &_primes_k_tuple, 3},
    {"_primes_next_prime", (DL_FUNC) &_primes_next_prime, 1},
    {"_primes_prev_prime", (DL_FUNC) &_primes_prev_prime, 1},
    {"_primes_prime_count", (DL_FUNC) &_primes_prime_count, 2},
    {"_primes_primorial_n", (DL_FUNC) &_primes_primorial_n, 1},
    {"_primes_primorial_p", (DL_FUNC) &_primes_primorial_p, 1},
    {"_primes_generate_primes_", (DL_FUNC) &_primes_generate_primes_, 2},
    {"_primes_RcppExport_registerCCallable", (DL_FUNC) &_primes_RcppExport_registerCCallable, 0},
    {NULL, NULL, 0}
};

RcppExport void R_init_primes(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
