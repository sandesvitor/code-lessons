#include <iostream>

bool isPrime(int num) {
  if(num <= 0 || num == 1) {
    return false;
  }
  
  if(num % 2 == 0){
    if(num == 2){
      return true;
    } else {
      return false;
    }
  }
  if(num % 3 == 0){
    if(num == 3){
      return true;
    } else {
      return false;
    }
  }
  if(num % 5 == 0){
    if(num == 5){
      return true;
    } else {
      return false;
    }
  }
  if(num % 7 == 0){
    if(num == 7){
      return true;
    } else {
      return false;
    }
  }
  
  return true;
}

int main(int argc, char* argv[]) {
    std::cout << isPrime(8424242424242427) << std::endl;
    return 0;
}