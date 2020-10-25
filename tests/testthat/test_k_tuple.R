context("Twin primes and other k-tuples")

test_that("First twin primes are correct", {
  expect_equal(twin_primes(2,19), list(c(3L,5L),c(5L,7L),c(11L,13L),c(17L,19L)))
})

test_that("Prime triplets are correct", {
  expect_equal(k_tuple(2,19,c(0,2,6)), list(c(5L,7L,11L), c(11L,13L,17L)))
})

test_that("Prime cousins are correct", {
  #  OEIS A023200 and OEIS A046132 via Wikipedia
  expect_equal(
    cousin_primes(0,1000),
    list(
      c(3, 7), c(7, 11), c(13, 17), c(19, 23), c(37, 41), c(43, 47),
      c(67, 71), c(79, 83), c(97, 101), c(103, 107), c(109, 113),
      c(127, 131), c(163, 167), c(193, 197), c(223, 227), c(229, 233),
      c(277, 281), c(307, 311), c(313, 317), c(349, 353), c(379, 383),
      c(397, 401), c(439, 443), c(457, 461), c(463,467), c(487, 491),
      c(499, 503), c(613, 617), c(643, 647), c(673, 677), c(739, 743),
      c(757, 761), c(769, 773), c(823, 827), c(853, 857), c(859, 863),
      c(877, 881), c(883, 887), c(907, 911), c(937, 941), c(967, 971)
    )
  )
})

test_that("Sexy prime triplets are correct", {
  expect_equal(
    sexy_prime_triplets(0,23), # p + 18 must be composite
    list(c(7L, 13L, 19L))
  )
  expect_equal(
    # OEIS A046118, OEIS A046119, and OEIS: A046120 via Wikipedia
    sexy_prime_triplets(0,1000),
    list(
      c(7,13,19), c(17,23,29), c(31,37,43), c(47,53,59), c(67,73,79),
      c(97,103,109), c(101,107,113), c(151,157,163), c(167,173,179),
      c(227,233,239), c(257,263,269), c(271,277,283), c(347,353,359),
      c(367,373,379), c(557,563,569), c(587,593,599), c(607,613,619),
      c(647,653,659), c(727,733,739), c(941,947,953), c(971,977,983)
    )
  )
})
