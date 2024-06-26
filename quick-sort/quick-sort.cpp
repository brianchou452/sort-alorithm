#include <bits/stdc++.h>
using namespace std;
int partition(int a[], int p, int r);
void quickSort(int a[], int p, int r);

int main() {
  int a[] = {8, 4, 6, 9};
  quickSort(a, 0, 4);
  for (int i = 0; i < 4; i++) {
    cout << a[i] << " ";
  }
}

int partition(int a[], int p, int r) {
  int x = a[p];
  int i = p - 1;
  int j = r + 1;
  while (true) {
    cout << "1 -p=" << p << " r=" << r << endl;
    cout << "1 -i=" << i << " j=" << j << " x=" << x << endl;
    for (int i = 0; i < 9; i++) {
      cout << a[i] << " ";
    }
    cout << endl;

    do {
      i++;
    } while (a[i] < x);
    do {
      j--;
    } while (a[j] > x);
    if (i < j) {
      swap(a[i], a[j]);
    } else {
      return j;
    }
    cout << "p=" << p << " r=" << r << endl;
    cout << "i=" << i << " j=" << j << " x=" << x << endl;
    for (int i = 0; i < 9; i++) {
      cout << a[i] << " ";
    }
    cout << endl << endl;
  }
}
void quickSort(int a[], int p, int r) {
  if (p < r) {
    cout << "partition( p = " << p << " r = " << r << endl;
    int q = partition(a, p, r);
    cout << "quickSort1( p = " << p << " q = " << q << endl;
    quickSort(a, p, q);
    cout << "quickSort2( q+1 = " << q + 1 << " r= " << r << endl;
    quickSort(a, q + 1, r);
  }
}
