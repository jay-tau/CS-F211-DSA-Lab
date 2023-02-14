// do not edit the header files
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  } // End input

  int right_ptr = n - 1;
  for (int i = 0; i < n; i++) {
    int current_element = a[i];
    int goal = a[n - 1] - current_element;
    int right_element = a[right_ptr];

    while (right_element > goal) {
      right_ptr--;
      right_element = a[right_ptr];
    }

    if ((right_element == goal) && (right_element >= current_element))
      cout << current_element << " " << right_element << endl;
  }
  return 0;
}