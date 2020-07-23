Prime Number Testing and Generation in R
========================================

__Authors:__ Oliver Keyes and Paul Egeler  
__License:__ [MIT](http://opensource.org/licenses/MIT)  
__Status:__ In development

## Description

This is a simple package that does two things: 1) tests for prime numbers,
and 2) generates ranges of prime numbers. 

- Testing can be done with `is_prime`, which accepts an integer vector of any
  length and returns a logical vector of *equal* length containing, for each
  element, whether it is prime (`TRUE`) or not (`FALSE`).
- `generate_primes` generates every prime number between `min` and `max`, where
  `min` is `2L` by default.

The `is_prime` function uses trial division, while `generate_primes` uses the
Sieve of Eratosthenes to create ranges of primes.

## Installation

For the development version:

    devtools::install_github("ironholds/primes")
