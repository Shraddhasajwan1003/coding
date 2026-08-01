//Delete all occurrences of a key in DLL

// Problem Statement: Given the head of a doubly linked list and an integer target. Delete all nodes in the linked list with the value target and return the head of the modified linked list.

// Examples
// Input: head -> 1 <-> 2 <-> 3 <-> 1 <-> 4, target = 1

// Output: head -> 2 <-> 3 <-> 4
// Input: head -> 2 <-> 3 <-> -1 <-> 4 <-> 2, target = 2

// Output: head -> 3 <-> -1 <-> 4

//algo 
//Start from the head of the doubly linked list and traverse until you reach the end.
// For each node, if the node's value is equal to the target:
// If there is a previous node, connect the previous node to the next node.
// If there is a next node, connect the next node to the previous node.
// If the node is the head of the list, update the head to the next node.
// Delete the current node and move to the next node in the list.
// Return the updated head of the list.

#include <bits/stdc++.h>
using namespace std;

// Node class for the doubly linked list
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    // Constructor to initialize node with a value
    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

// Solution class containing all operations on the doubly linked list
class Solution {
public:
    // Inserts a new node with the given value at the end of the list
    void insertAtEnd(Node*& head, int val) {
        // Create the new node
        Node* newNode = new Node(val);

        // If list is empty, set new node as head
        if (!head) {
            head = newNode;
            return;
        }

        // Traverse to the last node
        Node* temp = head;
        while (temp->next)
            temp = temp->next;

        // Link the new node at the end
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Prints the entire linked list from head to tail
    void printList(Node* head) {
        // Start from the head node
        Node* temp = head;

        // Traverse and print each node's data
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " <-> ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Deletes all nodes that have the specified target value
    Node* deleteTargetNodes(Node* head, int target) {
        // Start from the head node
        Node* current = head;

        // Traverse the entire list
        while (current != nullptr) {
            // Store next node before possibly deleting current
            Node* nextNode = current->next;

            // If current node matches the target value
            if (current->data == target) {
                // If not the head, link previous node to next
                if (current->prev)
                    current->prev->next = current->next;
                else
                    // If it's the head, move head forward
                    head = current->next; 

                // If not the tail, link next node to previous
                if (current->next)
                    current->next->prev = current->prev;

                // Delete the current node
                delete current;
            }

            // Move to the next node
            current = nextNode;
        }

        // Return updated head
        return head;
    }
};

// Main function to test the linked list operations
int main() {
    Solution sol;
    Node* head = nullptr;

    // Insert values into the doubly linked list
    sol.insertAtEnd(head, 1);
    sol.insertAtEnd(head, 2);
    sol.insertAtEnd(head, 3);
    sol.insertAtEnd(head, 2);
    sol.insertAtEnd(head, 4);
    sol.insertAtEnd(head, 2);
    sol.insertAtEnd(head, 5);

    // Print the list before deletion
    cout << "Original List:\n";
    sol.printList(head);

    // Define the target value to be deleted
    int target = 2;

    // Delete all nodes with the target value
    head = sol.deleteTargetNodes(head, target);

    // Print the list after deletion
    cout << "\nList after deleting value " << target << ":\n";
    sol.printList(head);

    return 0;
}

