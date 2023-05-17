#include <iostream>
using namespace std;

class Node { // Node class to represent a node of the linked list.
public:
  int data;
  Node *next;

  Node() { // Default constructor
    data = 0;
    next = NULL;
  }

  Node(int data) { // Parameterised Constructor
    this->data = data;
    this->next = NULL;
  }
};

class Linkedlist { // Linked list class to implement a linked list.
public:
  Node *head;

  Linkedlist() { // Default constructor
    head = NULL;
  }

  void
  insertNode(int); // Function to insert a node at the end of the linked list.

  void printList(); // Function to print the linked list.

  int removeElement(); // Function to pop element at head
};

void Linkedlist::insertNode(int data) { // Function to insert a new node.
  Node *newNode = new Node(data);       // Create the new Node.

  if (head == NULL) { // Assign to head
    head = newNode;
    return;
  }
  newNode->next = head;
  head = newNode;
}

int Linkedlist::removeElement() { // Function to pop element at head
  if (head == NULL) {             // Return -1 if list is empty
    // cout << "List empty" << endl;
    return -1;
  }

  int return_data = head->data;
  head = head->next; // Move the head one pointer forward
  return return_data;
}

void Linkedlist::printList() { // Function to print the nodes of the linked
                               // list.
  Node *temp = head;

  if (head == NULL) { // Check for empty list.
    cout << "List empty" << endl;
    return;
  }

  while (temp != NULL) { // Traverse the list.
    cout << temp->data << " ";
    temp = temp->next;
  }
}

// Driver Code
int main() {
  Linkedlist num1, num2, sum;

  while (true) { // Take num1 input
    int n;
    cin >> n;
    if (n == -1)
      break;
    num1.insertNode(n);
  }
  while (true) { // Take num2 input
    int n;
    cin >> n;
    if (n == -1)
      break;
    num2.insertNode(n);
  }
  // cout << "num1: ";
  // num1.printList();
  // cout << endl;
  // cout << "num2: ";
  // num2.printList();
  // cout << endl;

  int carry = 0;

  while (true) {
    int num1_digit = num1.removeElement();
    int num2_digit = num2.removeElement();

    if ((num1_digit == -1) &&
        (num2_digit == -1)) // If both lists are empty, break.
      break;

    // If either list is empty, set its digit as 0
    num1_digit = max(0, num1_digit);
    num2_digit = max(0, num2_digit);

    int temp_sum = num1_digit + num2_digit + carry;
    carry = (temp_sum / 10);
    int sum_digit = temp_sum % 10;
    sum.insertNode(sum_digit);
  }
  if (carry > 0) // If carry is present, insert it into the sum
    sum.insertNode(carry);

  // cout << "sum: ";
  sum.printList();
  cout << endl;
  return 0;
}
