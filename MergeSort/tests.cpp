#include <iostream>
#include <vector>
#include <cstdlib>  // For rand()
#include <ctime>    // For time()

#include "mergesort.h"

void printVector(const std::vector<int>& v) {
  for (int num : v) {
      std::cout << num << " ";
  }
  std::cout << std::endl;
}

std::vector<int> generateRandomVector(int length, int min, int max) {
  std::vector<int> vec;
  for (int i = 0; i < length; ++i) {
      vec.push_back(rand() % (max - min + 1) + min);
  }
  return vec;
}

bool fuzzTest(int n, int len_max, int len_min) {
  srand(static_cast<unsigned int>(time(0)));

  // Test n random vectors
  for (int i = 0; i < n; i++) {
    std::vector<int> v = generateRandomVector((rand() % (len_max-len_min+1)+len_min), -1000, 1000);
    std::vector<int> v2(v);
    mergeSort(v, 0, v.size());

    // verify result
    for (int j = 0; j < v.size()-1; j++) {
      if (v[j] > v[j+1]) {
        std::cout << "TEST " << i << "/" << n << "FAILED!\nPre-sort: ";
        printVector(v2);
        std::cout << "Post-sort: ";
        printVector(v);
        return false;
      }
    }
  }

  std::cout << n << " random tests passed." << std::endl;
  return true;
}

int main()
{
  fuzzTest(100, 20, 30);
  return 0;
}