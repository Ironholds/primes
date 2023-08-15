context("Prime factors")

test_that("Create a vector of factors", {
  expect_equal(prime_factors(2), list(2))
  expect_equal(
    prime_factors(c(-1:2, 7:11)),
    list(
      integer(0),     # -1
      integer(0),     #  0
      integer(0),     #  1
      2L,             #  2
      7L,             #  7
      c(2L, 2L, 2L),  #  8
      c(3L, 3L),      #  9
      c(2L, 5L),      # 10
      11L             # 11
      )
    )
})

test_that("Vectors of length == 0 handled correctly", {
  expect_equal(prime_factors(integer(0)), list())
})

test_that("NAs are handled properly", {
  expect_equal(
    prime_factors(c(NA, 1, 3)),
    list(as.integer(NA), integer(0), 3L)
  )
})

context("Ruth-Aaron pairs")

test_that("Compute with _all_ factors", {
  expect_equal(ruth_aaron_pairs(5, 50), list(5:6, 8:9, 15:16))
})

test_that("Compute with distinct factors", {
  expect_equal(ruth_aaron_pairs(5, 50, TRUE), list(5:6, 24:25, 49:50))
})
