#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <numeric>
#include <ostream>
#include <string>
#include <thread>
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

int main(int argc, char **argv) {
  std::cout << "Starting..." << std::endl;
  std::vector<char *> args;
  for (int i = 0; i < argc; i++) {
    args.push_back(argv[i]);
  }

  int max = 300000;

  if (argc > 1) {
    max = std::stoi(args[1]);
  }

  std::string path = "primes.txt";
  std::ofstream file(path);
  std::vector<int> primeArr;
  primeArr.resize(max, 0);
  int numPrimes = 0;

  int i = 0;

  std::thread ui{[&i, &primeArr, max, &numPrimes]() {
    while (i < primeArr.size()) {
      std::cout << "\r" << i << "/" << max << "\t"
                << float(i) * 100.0 / float(primeArr.size()) << "% \t"
                << "Primes found: " << numPrimes;
      std::cout.flush();
      std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
    for (int i = 0; i < 100; i++)
      std::cout << " " << std::endl;
  }};

  ui.detach();

  for (i = 0; i < primeArr.size(); i++) {
    if (isPrime(i)) {
      primeArr[i] = 1;
      numPrimes += 1;
    }
  }

  for (int i = 0; i < max; i++) {
    if (primeArr[i]) {
      file << i << "\n";
    }
  }

  numPrimes = std::reduce(primeArr.begin(), primeArr.end());

  // printVec(primeArr);
  std::cout << "\n" << "Number of Primes: " << numPrimes << std::endl;

  return 0;
}
