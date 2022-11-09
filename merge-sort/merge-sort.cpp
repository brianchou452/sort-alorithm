#include <bits/stdc++.h>
using namespace std;
void mergeSort(int a[], int p, int q);
void merge(int a[], int p, int r, int q);

int main() {
  int a[] = {10, 8, 6, 9, 12, 4, 3, 1, 7, 5, 2, 11};
  int size = sizeof(a) / sizeof(int);
  mergeSort(a, 0, size - 1);
  for (int i = 0; i < size; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void mergeSort(int a[], int p, int q) {
  if (p < q) {
    int r = (p + q) / 2;
    mergeSort(a, p, r);
    mergeSort(a, r + 1, q);
    merge(a, p, r, q);
  }
}

void merge(int a[], int p, int r, int q) {
  vector<int> left;
  vector<int> right;
  for (int i = p; i <= r; i++) {
    left.push_back(a[i]);
  }
  for (int i = r + 1; i <= q; i++) {
    right.push_back(a[i]);
  }
  int leftIndex = 0;
  int rightIndex = 0;
  for (int i = p; i <= q; i++) {
    if (leftIndex >= left.size()) {
      a[i] = right[rightIndex];
      rightIndex++;
    } else if (rightIndex >= right.size()) {
      a[i] = left[leftIndex];
      leftIndex++;
    } else if (left[leftIndex] <= right[rightIndex]) {
      a[i] = left[leftIndex];
      leftIndex++;
    } else if (right[rightIndex] < left[leftIndex]) {
      a[i] = right[rightIndex];
      rightIndex++;
    }
  }
}