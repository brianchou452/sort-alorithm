#include <bits/stdc++.h>
using namespace std;
void countingSort(int a[], int b[], int size, int k);

int main() {
  int a[] = {4, 1, 3, 2, 11, 9, 10, 5, 8, 7, 6, 12};
  int b[20] = {};
  int size = sizeof(a) / sizeof(int);
  countingSort(a, b, size, 13);
  for (int i = 0; i < size; i++) {
    cout << b[i] << " ";
  }
  cout << endl;
}
void countingSort(int a[], int b[], int size, int k) {
  int c[100] = {};  // TODO wait for rewrite
  for (int i = 0; i <= k; i++) {
    c[i] = 0;
  }

  for (int i = 0; i < size; i++) {
    c[a[i]]++;
  }
  for (int i = 1; i <= k; i++) {
    c[i] = c[i] + c[i - 1];
  }
  for (int i = size - 1; i >= 0; i--) {
    b[c[a[i]] - 1] = a[i];
    c[a[i]]--;
  }
}