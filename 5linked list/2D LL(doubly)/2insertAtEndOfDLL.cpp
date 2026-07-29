//Given a doubly linked list, and a value ‘k’, 
//insert a node having value ‘k’ at the end of the doubly linked list.


//Example 1:
// Input Format:
  
// DLL: 1 <-> 2 <-> 3 <-> 4  
// Value to be Inserted: 6  
// Result:
//   DLL: 1 <-> 2 <-> 3 <-> 4 <-> 6  
// Explanation:
//   A new node with value 6 has been inserted at the end of the doubly linked list after the tail node.

// Example 2:
// Input Format:
  
// DLL: 10 <-> 20 <-> 30  
// Value to be Inserted: 40  
// Result:
//   DLL: 10 <-> 20 <-> 30 <-> 40  
// Explanation:
//   In this case, a new node with value 40 is inserted after 30, which is at the end of the doubly linked list.

//insert krne ke liye we nedd to find prevoius node of given node
//create node jo bhi di h , fir uska prev point krega to prevoius node 
//previous node ka next that point to null will now point to new node 
//then newly added node's pointer will point to null 
//return head
//TC is O(N)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Define a Node class for doubly linked list
class Node {
public:
    int data;   // Data stored in the node
    Node* next; // Pointer to the next node in the list (forward direction)
    Node* back; // Pointer to the previous node in the list (backward direction)

    // Constructor for a Node with both data, next, and back references
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    // Constructor for a Node with only data, no next or back references (end of the list)
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

// Function to convert an array to a doubly linked list
Node* convertArr2DLL(vector<int> arr) {
    // Create the head node with the first element of the array
    Node* head = new Node(arr[0]);
    Node* prev = head; // Initialize 'prev' to the head node

    // Traverse the array to create the doubly linked list
    for (int i = 1; i < arr.size(); i++) {
        // Create a new node with data from the array and set its 'back' pointer to the previous node
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp; // Set 'next' of the previous node to the new node
        prev = temp; // Move 'prev' to the new node
    }
    return head;  // Return the head of the doubly linked list
}

// Function to print the elements of the doubly linked list
void print(Node* head) {
    // Traverse through the list and print each node's data
    while (head != nullptr) {
        cout << head->data << " ";  // Print the data of the current node
        head = head->next;          // Move to the next node
    }
}

// Function to insert a new node with value 'k' at the end of the doubly linked list
Node* insertAtTail(Node* head, int k) {
    // Create a new node with data 'k'
    Node* newNode = new Node(k);

    // If the doubly linked list is empty, return the new node as the head
    if (head == nullptr) {
        return newNode;
    }

    // Traverse to the last node of the doubly linked list
    Node* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }

    // Connect the new node to the last node
    tail->next = newNode;
    newNode->back = tail; // Set the 'back' pointer of the new node to the previous node
    return head;  // Return the head of the modified list
}

int main() {
    // Initialize an array of integers
    vector<int> arr = {12, 5, 8, 7, 4};

    // Convert the array into a doubly linked list
    Node* head = convertArr2DLL(arr);

    // Print the initially created doubly linked list
    cout << "Doubly Linked List Initially: " << endl;
    print(head);

    // Insert a node with value 10 at the end of the doubly linked list
    cout << endl << "Doubly Linked List After Inserting at the tail with value 10: " << endl;
    head = insertAtTail(head, 10);
    print(head);

    return 0;
}

