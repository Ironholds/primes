% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/RcppExports.R, R/sieve.R
\name{generate_n_primes}
\alias{generate_n_primes}
\alias{generate_primes}
\title{Generate a Sequence of Prime Numbers}
\usage{
generate_n_primes(n)

generate_primes(min = 2L, max)
}
\arguments{
\item{n}{the number of primes to generate.}

\item{min}{the lower bound of the sequence.}

\item{max}{the upper bound of the sequence.}
}
\value{
An integer vector of prime numbers.
}
\description{
Generate a sequence of prime numbers from \code{min} to \code{max} or generate a vector
of the first \code{n} primes. Both functions use a fast implementation of the
Sieve of Eratosthenes.
}
\examples{
generate_primes(max = 12)
## [1]  2  3  5  7 11

generate_n_primes(5)
## [1]  2  3  5  7 11
}
\author{
Paul Egeler, MS
}
