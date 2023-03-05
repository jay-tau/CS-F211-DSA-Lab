/*
(a) (2 marks) Two marks if your program follows the right approach. No need to
write the pseudocode.
(b) (4 marks) Four marks for passing the testcases.
*/

// do not change any of the header files
#include <climits>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

void partition_sort(vector<int> &A) {
  int n = A.size();
  int i = -1, j = 0;

  while (j < n) { // Put all 0's in correct position
    if (A[j] < 1) {
      swap(A[++i], A[j]);
    }
    ++j;
  }

  int stop = i;
  i = n, j = n - 1;
  while (j > stop) {
    if (A[j] > 1) {
      swap(A[--i], A[j]);
    }
    --j;
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++)
    cin >> A[i];
  partition_sort(A);
  for (int i = 0; i < n; i++)
    cout << A[i] << " ";
  return 0;
}
