#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;  //陣列個數
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int num;  //要找的數字
  cin >> num;

  int left = 0;
  int right = n - 1;
  int mid = 0;
  while (left < right) {
    mid = (left + right) / 2;
    if (num < a[mid]) {
      right = mid + 1;
    } else if (num > a[mid]) {
      left = mid - 1;
    } else if (num == a[mid]) {
      cout << "found at " << mid << endl;
      break;
    }
  }

  return 0;
}