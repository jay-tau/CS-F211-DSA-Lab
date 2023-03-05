/*
  Please write your answers alongside the space provided.
  (a) (2 marks) Write the pseudocode for the Search procedure mentioned above.
    search(v, l, r, key)
      if (l == r)
        if (v[l] == key)
          return l
        else
          return -1

      int mid = (l + r) / 2;
      if (key > v[mid])
        rsp = search(v, mid + 1, r, key)
        if (rsp != -1) // If found in RSP
          return rsp
        else
          return -1
      else
        lsp = search(v, l, mid, key);
        if (lsp != -1)
          return lsp
        else
          return -1

  (b) (2 marks) What will be the recurrence equation for the algorithm in
  part(a)? T(n) = 1T(n/2) + \Theta(1) (c) (2 marks) Which condition of the
  Master Theorem can be applied to find the total running time for the
  recurrence in part (b)? What are the values of a and b for the recurrence?

    2nd condition
    a = 1; b = 2
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &v, int l, int r, int key) {
  if (l == r)
    return (v[l] == key) ? l : -1;

  int mid = (l + r) / 2;
  if (key > v[mid]) {
    int rsp = search(v, mid + 1, r, key);
    return (rsp != -1) ? rsp : -1;
  } else {
    int lsp = search(v, l, mid, key);
    return (lsp != -1) ? lsp : -1;
  }
}

int main() {
  int n, key;
  cin >> n >> key;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  cout << search(v, 0, n - 1, key) << endl;
  return 0;
}