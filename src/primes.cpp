#include <Rcpp.h>
using namespace Rcpp;

bool is_prime_single(int x) {

  bool output = true;
  if(x <= 3){
    output = (x > 1);
  } else if(x % 2 == 0 || x % 3 == 0){
    output = false;
  } else {
    for(int i = 5; i * i <= x; i += 6) {
      if (x % i == 0 || x % (i + 2) == 0) {
        output = false;
        break;
      }
    }
  }

  return output;
}

//[[Rcpp::export]]
std::vector < bool > is_prime_vector(std::vector < int > x){

  int input_size = x.size();
  std::vector < bool > output(input_size);

  for(int i = 0; i < input_size; i++){
    output[i] = is_prime_single(x[i]);
  }

  return output;
}

//[[Rcpp::export]]
std::vector < int > generate_primes_(int min, int max){

  std::vector < int > output;
  for(int i = min; i <= max; i++){
    if(is_prime_single(i)){
      output.push_back(i);
    }
  }
  return output;
}
