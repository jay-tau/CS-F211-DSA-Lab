#include <iostream>
using namespace std;

// Node class to represent a node of the linked list.
class Node {
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
};

void Linkedlist::insertNode(int data) { // Function to insert a new node.
  Node *newNode = new Node(data);       // Create the new Node.

  if (head == NULL) { // Assign to head if list is empty
    head = newNode;
    return;
  }
  newNode->next = head;
  head = newNode;
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
  Linkedlist list;

  while (true) {
    int n;
    cin >> n;
    if (n == -1)
      break; // Terminate without inserting when -1 is scanned
    list.insertNode(n);
  }

  list.printList();
  cout << endl;
  return 0;
}
