context("Primorials")

test_that("n#",{
  expect_error(primorial_n(-1))
  expect_equal(primorial_n(0), 1)
  expect_equal(primorial_n(1), 1)
  expect_equal(primorial_n(2), 2)
  expect_equal(primorial_n(10), 210)
})

test_that("p_n#", {
  expect_error(primorial_p(-1))
  expect_equal(primorial_p(0), 1)
  expect_equal(primorial_p(1), 2)
  expect_equal(primorial_p(2), 6)
  expect_equal(primorial_p(10), 6469693230)
})
