#include <bits/stdc++.h>
using namespace std;
int digit(int a, int n, int r) {
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = a % r;
    a /= r;
  }
  return ans;
}
int radixSort(int a[], int link[], int d, int r, int n) {
  /*利用一個d位數、基數r的基數排序法來排序a[1:n]，digit(a[i], j, r)
    回傳a[i]以r為基數的鍵值在第j個位數 (從左邊)。每一個位數的範圍是[0,r)，
    同一個位數內的排序是使用容器排序法 */
  int front[r], rear[r]; /*佇列的開頭和結尾指標*/
  int i, bin, current, first, last;
  first = 1; /*建立一個從first開始的記錄起始鏈*/
  for (i = 1; i < n; i++) link[i] = i + 1;
  link[n] = 0;

  /*根據第i位數來排序*/
  for (i = d - 1; i >= 0; i--) {
    /*將容器初始化成空的佇列*/
    for (bin = 0; bin < r; bin++) {
      front[bin] = 0;
    }

    /*把記錄放到佇列/容器中*/
    for (current = first; current; current = link[current]) {
      bin = digit(a[current], i, r);
      if (front[bin] == 0)
        front[bin] = current;
      else
        link[rear[bin]] = current;
      rear[bin] = current;
    }
    /*找出第一個非空的佇列/容器*/
    for (bin = 0; !front[bin]; bin++) {
      first = front[bin];
      last = rear[bin]; /*連接其餘的佇列*/
    }

    for (bin++; bin < r; bin++)
      if (front[bin]) {
        link[last] = front[bin];
        last = rear[bin];
      }
    link[last] = 0;
  }
  return first;
}

int main() {
  int n = 5;
  // cin >> n;
  int a[] = {10, 14, 46, 79, 12, 54};
  int link[100];
  //   for (int i = 0; i < n; i++) {
  //     cin >> a[i];
  //   }
  radixSort(a, link, 2, 10, n);

  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  return 0;
}