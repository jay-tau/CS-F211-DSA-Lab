/*
        Please write your answers alongside the space provided
    a) Pseudo-code:
    SELECTION-SORT(A) // A is 1-indexed
        for i=1 to (A.length-1)
            min = a[i]
            min_index = i;
            for j=(i+1) to A.length
                if a[j] < min
                    min = a[j]
                    min_index = j
            //end for_j: Finds min
            swap(a[i], a[min_index])
        // end for_i
    //end SELECTION-SORT(A)
        b) What loop invariant property does the algorithm have:
    At the start of each iteration of the outer for loop, the subarray
   A[1...i-1] consists of the (i-1) smallest elements originally in A, but in
   sorted order c)i) Best Case runtime complexity: O(n^2) ii) Worst Case runtime
   complexity: O(n^2)

*/

// do not change any of the header files
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  // Start writing your code from here
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  // Selection sort
  for (int i = 0; i < n - 1; i++) {
    int min = a[i], min_index = i;
    for (int j = i + 1; j < n; j++) {
      if (a[j] < min) {
        min = a[j];
        min_index = j;
      }
    } // Find min
    swap(a[i], a[min_index]);
  }
  for (auto x : a)
    cout << x << " ";
  cout << endl;
  return 0;
}