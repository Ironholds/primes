# is_prime ----------------------------------------------------------------
context("Test actual prime numbers are determined to be prime")

test_that("actual prime numbers are determined to be prime",{
  expect_true(is_prime(5))
  expect_true(is_prime(9587))
  expect_true(is_prime(1299827))
})

test_that("Non-primes are determined to be not-prime", {
  expect_false(is_prime(4))
  expect_false(is_prime(9586))
  expect_false(is_prime(1299824))
})

# generate_primes ---------------------------------------------------------

context("Test prime numbers can be generated")

test_that("Prime numbers can be generated, full stop", {
  expect_equal(generate_primes(max=12), c(2,3,5,7,11))
})

test_that("'min' is respected", {
  expect_equal(generate_primes(4, 12), c(5,7,11))
  expect_equal(generate_primes(5, 12), c(5,7,11))
})

# next_prime/prev_prime ---------------------------------------------------

context("Test for next and previous")

test_that("Search for next prime works", {
  expect_equal(next_prime(-1:7), c(2L, 2L, 2L, 3L, 5L, 5L, 7L, 7L, 11L))
})

test_that("Search for previous also works", {
  expect_equal(prev_prime(-1:7), c(NA, NA, NA, NA, 2L, 3L, 3L, 5L, 5L))
})

# k_tuple -----------------------------------------------------------------

context("Test k-tuple function")

test_that("First twin primes are correct", {
  expect_equal(k_tuple(2,19,c(0,2)), list(c(3L,5L),c(5L,7L),c(11L,13L),c(17L,19L)))
})

test_that("Prime triplets are correct", {
  expect_equal(k_tuple(2,19,c(0,2,6)), list(c(5L,7L,11L), c(11L,13L,17L)))
})

# Prime Factors -----------------------------------------------------------

context("Test we can generate prime factors")

test_that("Create a vector of factors", {
  expect_equal(
    prime_factors(c(-1:2, 7:11)),
    list(
      integer(0), integer(0), integer(0), 2L, 7L, c(2L, 2L, 2L),
      c(3L, 3L), c(2L, 5L), 11L
      )
    )
})

# Ruth-Aaron Pairs --------------------------------------------------------

context("Test Ruth-Aaron pairs")

test_that("Compute with _all_ factors", {
  expect_equal(ruth_aaron_pairs(5, 50), list(5:6, 8:9, 15:16))
})

test_that("Compute with distinct factors", {
  expect_equal(ruth_aaron_pairs(5, 50, TRUE), list(5:6, 24:25, 49:50))
})
