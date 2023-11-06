## Version 1.5.1

### Purpose

This patch release addresses the [clang-UBSan finding](https://www.stats.ox.ac.uk/pub/bdr/memtests/clang-UBSAN/primes/tests/testthat.Rout)
wherein an implicit conversion from `double` to `int` could result in
undefined behavior when the floating point value cannot be represented as an integer, _ie_, the value is `-nan`. The UBSan test output is below.

### Solution

Using the [rocker/r-devel-ubsan-clang](https://hub.docker.com/r/rocker/r-devel-ubsan-clang)
Docker container, I was able to reproduce the bug.

```
# RD -q
> version
               _                                                 
platform       x86_64-pc-linux-gnu                               
arch           x86_64                                            
os             linux-gnu                                         
system         x86_64, linux-gnu                                 
status         Under development (unstable)                      
major          4                                                 
minor          3.0                                               
year           2022                                              
month          09                                                
day            19                                                
svn rev        82882                                             
language       R                                                 
version.string R Under development (unstable) (2022-09-19 r82882)
nickname       Unsuffered Consequences                           
> packageVersion("primes")
[1] ‘1.5.0’
> source("testthat.R")
prime_factors.cpp:13:14: runtime error: -nan is outside the range of representable values of type 'int'
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prime_factors.cpp:13:14 in 
[ FAIL 0 | WARN 0 | SKIP 0 | PASS 62 ]

```

A patch was created to prevent a domain error when calling `std::sqrt`. After
applying the patch, recompiling, and reinstalling, the runtime error is no longer
encountered.

```
# RD -q
> packageVersion("primes")
[1] ‘1.5.1’
> source("testthat.R")
[ FAIL 0 | WARN 0 | SKIP 0 | PASS 62 ]
```

### R CMD check results

0 errors ✔ | 0 warnings ✔ | 0 notes ✔

R CMD check succeeded
