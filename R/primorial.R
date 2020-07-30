#' Compute the Primorial
#'
#' Computes the primorial for prime numbers and natural numbers.
#'
#' The `primorial_p` function computes the primorial with respect the the first
#' `n` _prime_ numbers; while the `primorial_n` function computes the primorial
#' with respect the the first `n` _natural_ numbers.
#'
#' @param n an integer indicating the numbers to be used in the computation. See
#'   _Details_ for more information.
#'
#' @return A numeric vector of length 1.
#' @name primorial
#' @author Paul Egeler, MS
NULL

#' @rdname primorial
#' @export
primorial_n <- function(n) {
  if (n < 0)
    stop("'n' must be >= zero")

  prod(generate_primes(2L, n))
}

#' @rdname primorial
#' @export
primorial_p <- function(n) {
  if (n < 0)
    stop("'n' must be >= zero")

  prod(generate_n_primes(n))
}
