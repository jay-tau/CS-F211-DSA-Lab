// do not change any of the header files
#include <climits>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &v, int l, int mid, int r) {
  int l_len = (mid - l) + 1, r_len = (r - (mid + 1)) + 1;
  // v will be destroyed, so we need to make copies of data into LSP and RSP
  vector<int> LSP(l_len + 1), RSP(r_len + 1);
  LSP[l_len] = INT_MAX,
  RSP[r_len] = INT_MAX; // Ensure that infinity is never copied if all elements
                        // in the SP are exhausted

  for (int i = 0; i < l_len; i++) {
    LSP[i] = v[l + i];
  }
  for (int i = 0; i < r_len; i++) {
    RSP[i] = v[mid + 1 + i];
  }
  //
  // cout << "Recursion:" << endl;
  // for (int i = 0; i < l_len; i++) {
  //   cout << LSP[i] << " ";
  // }
  // cout << endl;
  // for (int i = 0; i < r_len; i++) {
  //   cout << RSP[i] << " ";
  // }
  // merge LSP and RSP into v in their correct positions
  int l_ptr = 0, r_ptr = 0;
  for (int i = 0; i < (l_len + r_len); i++) {
    if (LSP[l_ptr] <= RSP[r_ptr])
      v[l + i] = LSP[l_ptr++];
    else
      v[l + i] = RSP[r_ptr++];
  }
}

void merge_sort(vector<int> &v, int l, int r) {
  if (l < r) {
    int mid = (l + r) / 2;
    merge_sort(v, l, mid);
    merge_sort(v, mid + 1, r);
    merge(v, l, mid, r);
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  merge_sort(v, 0, n - 1);
  for (int i = 0; i < n; i++) {
    cout << v[i] << " ";
  }
  return 0;
}