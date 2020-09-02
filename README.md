Fast Functions for Prime Numbers in R
=====================================

[![CRAN version](https://www.r-pkg.org/badges/version/primes)](https://cran.r-project.org/package=primes)
[![Number of Downloads](https://cranlogs.r-pkg.org/badges/grand-total/primes)](https://cran.r-project.org/package=primes)

**Authors**: Os Keyes and Paul Egeler  
**License**: [MIT](https://opensource.org/licenses/MIT)  

## Description

This R package has several utility functions for dealing with prime numbers,
such as checking for primality and generating prime numbers. Additional
functions include:

- finding prime factors and Ruth-Aaron pairs
- finding next and previous prime numbers in the series
- finding or estimating the n<sup>th</sup> prime
- estimating the number of primes less than or equal to an arbitrary number
- computing primorials
- finding prime k-tuples (e.g., twin primes)
- finding the greatest common divisor and smallest (least) common multiple
- testing whether two numbers are coprime
- computing Euler's totient (phi)

The package also provides an R dataset containing the first one thousand primes.

## Installation

You can install the released version of primes from [CRAN](https://CRAN.R-project.org) with:

```r
install.packages("primes")
```

And the development version from [GitHub](https://github.com/) with:

```r
# install.packages("devtools")
devtools::install_github("ironholds/primes")
```

## Example

This checks which of the first twenty natural numbers are prime:

```r
library(primes)

is_prime(1:20)
## [1] FALSE  TRUE  TRUE FALSE  TRUE FALSE  TRUE FALSE FALSE FALSE  TRUE FALSE  TRUE FALSE
## [15] FALSE FALSE  TRUE FALSE  TRUE FALSE
```

You can also generate all the prime numbers between 101 and 199 with the following:

```r
generate_primes(101, 199)
## [1] 101 103 107 109 113 127 131 137 139 149 151 157 163 167 173 179 181 191 193 197 199
```
