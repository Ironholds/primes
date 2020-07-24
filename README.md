Prime Number Testing and Generation in R
========================================

**Authors**: Oliver Keyes and Paul Egeler  
**License**: [MIT](http://opensource.org/licenses/MIT)  
**Status**: In development

## Description

This is a simple package that does two things:

<dl>
  <dt>Test for primality of numbers</dt>
    <dd>Testing can be done with <code>is_prime</code>, which accepts an integer
    vector of any length and returns a logical vector of <em>equal</em> length
    containing, for each element, whether it is prime (<code>TRUE</code>) or not
    (<code>FALSE</code>).</dd>
  <dt>Generate ranges of prime numbers</dt>
    <dd>The <code>generate_primes</code> function generates every prime number
    between <code>min</code> and <code>max</code>, where <code>min</code> is
    <code>2L</code> by default.</dd>
</dl>

The `is_prime` function uses trial division, while `generate_primes` uses a
tweaked Sieve of Eratosthenes to create ranges of primes.

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
