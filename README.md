Prime Numbers in R
==================

[![Travis build status](https://travis-ci.org/pegeler/primes.svg?branch=master)](https://travis-ci.org/pegeler/primes)
[![AppVeyor build status](https://ci.appveyor.com/api/projects/status/github/pegeler/primes?branch=master&svg=true)](https://ci.appveyor.com/project/pegeler/primes)
[![CRAN version](http://www.r-pkg.org/badges/version/primes)](https://cran.r-project.org/package=primes)
[![Number of Downloads](https://cranlogs.r-pkg.org/badges/grand-total/primes)](https://cran.r-project.org/package=primes)


**Authors**: Os Keyes and Paul Egeler  
**License**: [MIT](http://opensource.org/licenses/MIT)  

## Description

This R package has several utility functions for dealing with prime numbers,
such as checking for primality and generating prime numbers.

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
