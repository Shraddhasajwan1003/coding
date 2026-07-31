//check if your LL is a palindrome or not 
//Problem Statement: Given the head of a singly linked list representing a positive integer number. Each node of the linked list represents a digit of the number, with the 1st node containing the leftmost digit of the number and so on. Check whether the linked list values form a palindrome or not. Return true if it forms a palindrome, otherwise, return false. .

//brute me stack use krege , first put all the node data in stack and then pop one by one simulateously matching with the LL started from head , if everything matches return true otherwise return false

#include <bits/stdc++.h>
using namespace std;

// Node class represents a node in a linked list
class Node {
public:
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node in the list

    // Constructor with both data and next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a parameter, sets next to nullptr
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};
//brute 
// Function to check if the linked list is a palindrome
bool isPalindrome(Node* head) {
    // Create an empty stack to store values
    stack<int> st;

    // Initialize a temporary pointer to the head of the linked list
    Node* temp = head;

    // Traverse the linked list and push values onto the stack
    while (temp != NULL) {
        st.push(temp->data); // Push the data from the current node onto the stack
        temp = temp->next;   // Move to the next node
    }

    // Reset the temporary pointer back to the head of the linked list
    temp = head;

    // Compare values by popping from the stack and checking against linked list nodes
    while (temp != NULL) {
        if (temp->data != st.top()) {
            // If values don't match, it's not a palindrome
            return false;
        }
        st.pop();           // Pop the value from the stack
        temp = temp->next;  // Move to the next node in the linked list
    }

    // If all values match, it's a palindrome
    return true;
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " "; // Print the current node's data
        temp = temp->next;         // Move to the next node
    }
    cout << endl;
}




//OPTIMAL SOLUTION 
// Function to reverse a linked list using the recursive approach
Node* reverseLinkedList(Node* head) {
    // Check if the list is empty or has only one node
    if (head == NULL || head->next == NULL) {
        return head;  // No change is needed; return the current head
    }

    // Recursive step: Reverse the remaining part of the list and get the new head
    Node* newHead = reverseLinkedList(head->next);

    // Store the next node in 'front' to reverse the link
    Node* front = head->next;

    // Update the 'next' pointer of 'front' to point to the current head
    front->next = head;

    // Set the 'next' pointer of the current head to null to break the original link
    head->next = NULL;

    // Return the new head obtained from the recursion
    return newHead;
}

// Function to check if the linked list is a palindrome
bool isPalindrome(Node* head) {
    // Check if the linked list is empty or has only one node
    if (head == NULL || head->next == NULL) {
        return true;  // It's a palindrome by definition
    }

    // Initialize two pointers, slow and fast, to find the middle of the linked list
    Node* slow = head;
    Node* fast = head;

    // Traverse the linked list to find the middle using slow and fast pointers
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;       // Move slow pointer one step at a time
        fast = fast->next->next; // Move fast pointer two steps at a time
    }

    // Reverse the second half of the linked list starting from the middle
    Node* newHead = reverseLinkedList(slow->next);

    // Pointer to the first half
    Node* first = head;

    // Pointer to the reversed second half
    Node* second = newHead;

    // Compare data values of nodes from both halves
    while (second != NULL) {
        if (first->data != second->data) {
            // If values do not match, the list is not a palindrome
            reverseLinkedList(newHead);  // Reverse the second half back to its original state
            return false;
        }

        first = first->next;  // Move the first pointer
        second = second->next; // Move the second pointer
    }

    // Reverse the second half back to its original state
    reverseLinkedList(newHead);

    // The linked list is a palindrome
    return true;
}
// Driver function
int main() {
    // Create a linked list with values 1, 5, 2, 5, and 1 (15251, a palindrome)
    Node* head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(1);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Check if the linked list is a palindrome
    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}

