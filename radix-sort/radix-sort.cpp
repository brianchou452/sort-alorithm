#include <bits/stdc++.h>
using namespace std;
void radixSort(int a[], int r, int size);
int getRadix(int a, int n);
void clearArray(vector<int> data[]);
int main() {
  // int a[] = {3, 8, 2, 6, 4, 1, 5, 7, 9};
  int a[] = {13, 28, 32, 46, 74, 71, 75, 67, 59};
  radixSort(a, 2, 9);
  for (int i = 0; i < 9; i++) {
    cout << a[i] << " ";
  }
}
void radixSort(int a[], int r, int size) {
  vector<int> data[10];
  for (int round = 0; round < r; round++) {
    clearArray(data);
    for (int i = 0; i < size; i++) {
      data[getRadix(a[i], round + 1)].push_back(a[i]);
    }
    for (int i = 0, j = 0; i < 10; i++) {
      for (int k = 0; k < data[i].size(); k++) {
        a[j] = data[i][k];
        j++;
      }
    }
  }
}

int getRadix(int a, int n) {
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = a % 10;
    a /= 10;
  }
  return ans;
}

void clearArray(vector<int> data[]) {
  for (int i = 0; i < 10; i++) {
    data[i].clear();
  }
}