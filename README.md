## Prime Number Testing and Generation in R

__Author:__ Oliver Keyes<br/>
__License:__ [MIT](http://opensource.org/licenses/MIT)<br/>
__Status:__ Stable

### Description

`primes` is a simple package that does two things; tests for prime numbers, and generates prime numbers. Testing can be done with `is_prime`, which accepts an integer vector of any length and returns a logical vector of *equal* length containing, for each element, whether it is prime (TRUE) or not (FALSE). `generate_primes` generates every prime number between `min` and `max`, where `min` is 0 by default.

Both functions rely on a C++ implementation of Wilson's theorem for testing primality; in theory this is a very slow test, but in practice, due to the restrictions R places around maximum integer sizes, it's fast enough for our needs.

### Installation

For the development version:

> devtools::install_github("ironholds/primes")
