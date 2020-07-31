context("Prime factors")

test_that("Create a vector of factors", {
  expect_equal(prime_factors(2), list(2))
  expect_equal(
    prime_factors(c(-1:2, 7:11)),
    list(
      integer(0), integer(0), integer(0), 2L, 7L, c(2L, 2L, 2L),
      c(3L, 3L), c(2L, 5L), 11L
      )
    )
})

context("Ruth-Aaron pairs")

test_that("Compute with _all_ factors", {
  expect_equal(ruth_aaron_pairs(5, 50), list(5:6, 8:9, 15:16))
})

test_that("Compute with distinct factors", {
  expect_equal(ruth_aaron_pairs(5, 50, TRUE), list(5:6, 24:25, 49:50))
})
