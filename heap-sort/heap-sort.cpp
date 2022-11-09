#include <bits/stdc++.h>
using namespace std;
void heapify(int a[], int size, int i);
void buildHeap(int a[], int size);
void heapSort(int a[], int size);
int main() {
  int a[] = {10, 8, 6, 9, 12, 4, 3, 1, 7, 5, 2, 11};
  int size = sizeof(a) / sizeof(int);
  heapSort(a, size);
  for (int i = 0; i < size; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void heapify(int a[], int size, int i) {
  int l = 2 * (i + 1) - 1;  // 陣列從零開始
  int r = 2 * (i + 1) + 1 - 1;
  int max = 0;
  if (l < size and a[l] > a[i]) {
    max = l;
  } else {
    max = i;
  }
  if (r < size and a[r] > a[max]) {
    max = r;
  }
  if (max != i) {
    swap(a[i], a[max]);
    heapify(a, size, max);
  }
}

void buildHeap(int a[], int size) {
  for (int i = size / 2; i >= 0; i--) {
    heapify(a, size, i);
  }
}

void heapSort(int a[], int size) {
  buildHeap(a, size);
  for (int i = size - 1; i > 0; i--) {
    swap(a[0], a[i]);
    size--;
    heapify(a, size, 0);
    cout << endl;
    for (int i = 0; i < size; i++) {
      cout << a[i] << " ";
    }
  }
}
