#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int left(int i) { return ((3 * i) - 1); }

int mid(int i) { return (3 * i); }

int right(int i) { return ((3 * i) + 1); }

void max_heapify(vector<int> &A, int i) {
  int largest;
  int heap_size = A.size();
  int l = left(i), m = mid(i), r = right(i);

  if ((l < heap_size) && (A[l] > A[i])) // l
    largest = l;
  else
    largest = i;
  if ((m < heap_size) && (A[m] > A[largest]))
    largest = m; // m
  if ((r < heap_size) && (A[r] > A[largest]))
    largest = r; // r

  if (largest != i) {
    swap(A[i], A[largest]);
    max_heapify(A, largest);
  }
}

void build_max_heap(vector<int> &A) {
  for (int i = (A.size() / 2); i >= 1; i--)
    max_heapify(A, i);
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n + 1); // 1-based indexing
  for (int i = 1; i <= n; i++)
    cin >> v[i];
  build_max_heap(v);
  for (int i = 1; i <= n; i++)
    cout << v[i] << " ";
  cout << endl;
  return 0;
}
