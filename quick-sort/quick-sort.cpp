#include <bits/stdc++.h>
using namespace std;
int partition(int a[], int p, int r);
void quickSort(int a[], int p, int r);

int main() {
  int a[] = {3, 8, 2, 6, 4, 1, 5, 7};
  quickSort(a, 0, 8);
  for (int i = 0; i < 8; i++) {
    cout << a[i] << " ";
  }
}

int partition(int a[], int p, int r) {
  int x = a[p];
  int i = p - 1;
  int j = r + 1;
  while (true) {
    do {
      j--;
    } while (a[j] > x);
    do {
      i++;
    } while (a[i] < x);
    if (i < j) {
      swap(a[i], a[j]);
    } else {
      return j;
    }
  }
}
void quickSort(int a[], int p, int r) {
  if (p < r) {
    int q = partition(a, p, r);
    quickSort(a, p, q);
    quickSort(a, q + 1, r);
  }
}
