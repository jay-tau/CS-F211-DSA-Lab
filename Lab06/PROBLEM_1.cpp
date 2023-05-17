// Please do not modify the header files.
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

// Stack implementation
template <typename T> class stack {
  vector<T> data;
  int top;

public:
  int size;
  stack(int size) {
    this->size = size;
    data.resize(size);
    top = -1;
  }
  void push(T value) {
    if (top == size - 1)
      cout << "Stack is full" << endl;
    else
      data[++top] = value;
  }
  T pop() {
    if (top == -1) {
      cout << "Stack is empty" << endl;
      return -1;
    } else
      return data[top--];
  }
  T peek() {
    if (top == -1) {
      cout << "Stack is empty" << endl;
      return -1;
    } else
      return data[top];
  }
  bool isEmpty() { return (top == -1); }
};

int maxSumThreeStacks(stack<int> &s1, stack<int> &s2, stack<int> &s3) {
  int sum1 = 0, sum2 = 0, sum3 = 0;
  stack<int> s1_copy(s1.size), s2_copy(s2.size), s3_copy(s3.size);
  // Find initial sum of stacks
  while (!s1.isEmpty()) {
    s1_copy.push(s1.pop());
    sum1 += s1_copy.peek();
  }
  while (!s2.isEmpty()) {
    s2_copy.push(s2.pop());
    sum2 += s2_copy.peek();
  }
  while (!s3.isEmpty()) {
    s3_copy.push(s3.pop());
    sum3 += s3_copy.peek();
  }
  // Find max sum
  while (true) {
    if (s1_copy.isEmpty() || s2_copy.isEmpty() || s3_copy.isEmpty())
      return 0;
    if (sum1 == sum2 && sum2 == sum3)
      return sum1;
    if (sum1 >= sum2 && sum1 >= sum3)
      sum1 -= s1_copy.pop();
    else if (sum2 >= sum1 && sum2 >= sum3)
      sum2 -= s2_copy.pop();
    else if (sum3 >= sum1 && sum3 >= sum2)
      sum3 -= s3_copy.pop();
  }
}

int main() {
  int n1, n2, n3;
  cin >> n1 >> n2 >> n3;
  stack<int> s1(n1), s2(n2), s3(n3);
  int x;
  for (int i = 0; i < n1; i++) {
    cin >> x;
    s1.push(x);
  }
  for (int i = 0; i < n2; i++) {
    cin >> x;
    s2.push(x);
  }
  for (int i = 0; i < n3; i++) {
    cin >> x;
    s3.push(x);
  }
  cout << maxSumThreeStacks(s1, s2, s3) << endl;
}
