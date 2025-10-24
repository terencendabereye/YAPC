#include <cmath>
#include <fstream>
#include <iostream>
#include <numeric>
#include <ostream>
#include <vector>

bool isPrime(int n) {
  if (n < 2) {
    return false;
  } else {
    for (int i = 2; i < n; i++) {
      if (n % i == 0) {
        return false;
      }
    }
    return true;
  }
}

template <typename T> void printVec(std::vector<T> vec) {
  int lineCount = 0;
  for (int v : vec) {
    std::cout << v << ", ";
    if (lineCount > 5) {
      std::cout << "\n";
    }
  }
  std::cout << std::endl;
}

int main() {
  std::cout << "Starting..." << std::endl;

  int max = 100;
  std::string path = "primes.txt";
  std::ofstream file(path);
  std::vector<int> primeArr;
  primeArr.resize(max, 1);
  int numPrimes = 0;

  for (int i = 0; i < primeArr.size(); i++) {
    if (!isPrime(i)) {
      primeArr[i] = 0;
    }
  }

  for (int v : primeArr) {
    if (isPrime(v)) {
      file << v << "\n";
    }
  }

  numPrimes = std::reduce(primeArr.begin(), primeArr.end());

  // printVec(primeArr);
  std::cout << "Number of Primes: " << numPrimes << std::endl;

  return 0;
}
