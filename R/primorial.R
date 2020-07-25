#' Compute the Primorial
#'
#' Computes the primorial for prime numbers and natural numbers.
#'
#' The `primorial_p` function computes the primorial with respect the the first
#' `n` _prime_ numbers; while the `primorial_n` function computes the primorial
#' with respect the the first `n` _natural_ numbers.
#'
#' Be careful of integer overflow. Currently, R uses signed 32-bit integers, so
#' numbers greater than 2**31 cannot be represented. This means any primorial
#' using prime numbers 29 or greater will fail.
#'
#' @param n an integer indicating the numbers to be used in the computation. See
#'   _Details_ for more information.
#' @name primorial
#' @aliases primorial_p primorial_n
NULL
