#include <iostream>
#include <vector>
#include <cmath>

void merge(std::vector<int>& v, int l, int r, int mid) {
  int i = l;
  int j = mid+1;
  std::vector<int> sorted;

  while (sorted.size() < r-l+1) {
    if (i > mid) {
      sorted.push_back(v[j]);
      j++;
    } else if (j > r) {
      sorted.push_back(v[i]);
      i++; 
    }
    else if (v[i] <= v[j]) {
      sorted.push_back(v[i]);
      i++; 
    } else {
      sorted.push_back(v[j]);
      j++;
    }
  }

  for (int k = 0; k < sorted.size(); k++) {
    v[l+k] = sorted[k];
  }
}

void mergeSort(std::vector<int>& v, int l, int r) {
  if (l >= r)
    return;

  int mid = l+(r-l)/2;
  mergeSort(v, l, mid);
  mergeSort(v, mid+1, r);
  merge(v, l, r, mid);
}