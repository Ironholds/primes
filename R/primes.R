#' @title Functions for Identifying and Generating Prime Numbers
#' @name primes
#' @description Functions to test whether a number is prime and generate the
#'   prime numbers within a specified range. Based on trial division and the
#'   Sieve of Eratosthenes for testing for an integer's primality, depending of
#'   the function used.
#'
#' @useDynLib primes
#' @importFrom Rcpp sourceCpp
#' @docType package
#' @aliases primes primes-package
NULL

#' @title Generate and Test for Prime Numbers
#' @description Generate prime numbers or test whether a sequence of numbers you
#'   have are prime or not.
#'
#' @param x an integer vector containing elements you want to determine the
#'   primality of.
#' @param min the value to generate primes from.
#' @param max the maximum value to generate prime numbers up to.
#'
#' @details \code{is_prime} relies on trial division to test for a number's
#'   primality and \code{generate_primes} uses the Sieve of Eratosthenes.
#'
#' @examples
#' #Test for primality
#' is_prime(1299827)
#' # [1] TRUE
#'
#' generate_primes(max = 12)
#' # [1]  2  3  5  7 11
#' @rdname prime
#' @name prime
#' @export
is_prime <- function(x){
  is_prime_vector(x)
}

#'@rdname prime
#'@export
generate_primes <- function(min = 2L, max){
  generate_primes_(min, max)
}
