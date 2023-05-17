/* (a) (3 marks) Write the pseudocode for Heap-Decrease-Key procedure:
    MAX-HEAP-DECREASE-KEY (A, x, k)
        if k > x
            error "new key is greater than current key"
        A[x] = k
        MAX-HEAPIFY(A, x)
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int parent(int i) { return i / 2; }

int left(int i) { return 2 * i; }

int right(int i) { return 2 * i + 1; }

void max_heapify(vector<int> &A, int i) {
  int heap_size = A.size() - 1; // 1-indexed
  int l = left(i), r = right(i);
  int largest;
  if (l <= heap_size && A[l] > A[i])
    largest = l;
  else
    largest = i;
  if (r <= heap_size && A[r] > A[largest])
    largest = r;

  if (largest != i) {
    swap(A[i], A[largest]);
    max_heapify(A, largest);
  }
}

void max_heap_increase_key(vector<int> &A, int x, int k) {
  if (k < A[x])
    cout << "Error: new key is smaller than current key" << endl;
  A[x] = k;
  while ((x > 1) && (A[parent(x)] < A[x])) {
    swap(A[x], A[parent(x)]);
    x = parent(x);
  }
}

void max_heap_decrease_key(vector<int> &A, int x, int k) {
  if (k > A[x])
    cout << "Error: new key is larger than current key" << endl;
  int heap_size = A.size() - 1; // 1-indexed
  A[x] = k;
  max_heapify(A, x);
}

void max_heap_update_key(vector<int> &A, int x, int k) {
  if (k > A[x])
    max_heap_increase_key(A, x, k);
  else
    max_heap_decrease_key(A, x, k);
}

int main() {
  int n;
  cin >> n;
  // 1-indexed vectors
  vector<int> a(n + 1);
  vector<int> b(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++)
    cin >> b[i];

  for (int i = 1; i <= n; i++) {
    max_heap_update_key(a, i, b[i]);
  }
  for (int i = 1; i <= n; i++)
    cout << a[i] << ' ';
  cout << endl;
  // for (int i = 1; i <= n; i++)
  //   cout << b[i] << ' ';
  // cout << endl;
}
