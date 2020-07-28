library(primes)

primes <- generate_n_primes(1000)

usethis::use_data(primes, overwrite = TRUE, compress = "xz")
