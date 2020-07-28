#' Prime-counting Functions and Estimating the Value of the n-th Prime
#'
#' Functions for estimating \eqn{\pi(n)}{pi(n)}---the number of primes less than
#' or equal to \eqn{n}{n}---and for estimating the value of \eqn{p_n}, the n-th
#' prime number.
#'
#' The `prime_count` function estimates the number of primes \eqn{\le n}{<= n}.
#' When `upper_bound = FALSE`, it is guaranteed to under-estimate for all
#' \eqn{n \ge 17}{n >= 17}.
#' When `upper_bound = TRUE`, it holds for all positive \eqn{n}.
#'
#' The `nth_prime_estimate` function brackets upper and lower bound values of
#' the nth prime. It is valid for \eqn{n \ge 6}{n >= 6}.
#'
#' The methods of estimation used here are a few of many alternatives. For
#' further information, the reader is directed to the _References_ section.
#'
#' @param n an integer. See _Details_ for more information.
#' @param upper_bound a logical indicating whether to estimate the lower- or
#'   upper bound.
#' @author Paul Egeler, MS
#' @references
#' "Prime-counting function" (2020) _Wikipedia_. \url{https://en.wikipedia.org/wiki/Prime-counting_function#Inequalities} (Accessed 26 Jul 2020).
#' @name prime_count
NULL
