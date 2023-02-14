/*
    Please write your answers alongside the space provided.
    (a) (2 marks) Write the pseudocode for the Divide-and-conquer algorithm
   described above: f(a, start, end) min_max_dc(array a[1...n], start, end, n)
        Initialise an array ans[1..2] // Stores {min, max}
        ans[1] = INT_MAX; // Min
        ans[2] = INT_MIN; // Max
        if (start > n)
            return ans
        if (start == end)
            ans[1] = a[start];
            ans[2] = a[start];
            return ans;

        int mid = (start + end) / 2;
        ans[1] = min(min_max_dc(a, start, mid, n)[1], min_max_dc(a, mid + 1,
   end, n)[1]); ans[2] = max(min_max_dc(a, start, mid, n)[2], min_max_dc(a, mid
   + 1, end, n)[2]); return ans;

    (b) (2 marks) What will be the recurrence equation for the algorithm in
   part(a): T(n) = 2T(n/2) + \Theta(1)

    (c) (2 marks) Solve the recurrence equation in part (b) to find the running
   time of the algorithm using theta-notation. (You can write Theta(n^3) as the
   solution if you wish. Do not use any other asymptotic notations.) \Theta(n)

*/

// do not change any of the header files
#include <climits>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> dp;

vector<int> min_max_dc(vector<int> &a, int start, int end, int n) {
  // cout << start << " " << end << endl;
  vector<int> ans(2);
  ans[0] = INT_MAX; // Min
  ans[1] = INT_MIN; // Max
  if (start > end || start > n) {
    return ans;
  }
  if (start == end) {
    ans[0] = a[start];
    ans[1] = a[start];
    return ans;
  }
  int mid = (start + end) / 2;
  vector<int> lsp = min_max_dc(a, start, mid, n),
              rsp = min_max_dc(a, mid + 1, end, n);
  ans[0] = min(lsp[0], rsp[0]);
  ans[1] = max(lsp[1], rsp[1]);
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<int> v(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> v[i];
  }
  vector<int> answer = min_max_dc(v, 1, n, n);
  cout << answer[0] << " " << answer[1] << endl;
  return 0;
}