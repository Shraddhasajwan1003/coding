//Remove duplicates from sorted DLL

// Problem Statement: Given the head of a doubly linked list with its values sorted in non-decreasing order. Remove all duplicate occurrences of any value in the list so that only distinct values are present in the list.

// Return the head of the modified linked list.


#include <bits/stdc++.h>
using namespace std;

// Class representing a node in a doubly linked list
class Node {
public:
    int data;       
    Node* prev;     
    Node* next;     

    // Constructor to initialize node with given value
    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

// Solution class containing methods to manipulate the doubly linked list
class Solution {
public:
    Node* head = nullptr;

    // Function to insert a node at the end of the list
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        // If list is empty, set new node as head
        if (!head) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next) {
            current = current->next;
        }

        // Link the new node at the end
        current->next = newNode;
        newNode->prev = current;
    }
    //TC is O(N)
    // Function to remove duplicate values from a sorted doubly linked list
    Node* removeDuplicates() {
        // If the list is empty, return null
        if (!head) return nullptr;

        Node* current = head;

        // Traverse the list until the second last node
        while (current != nullptr && current->next != nullptr) {
            Node* nextDistinct = current->next;

            // Skip and delete all nodes with the same value as current
            while (nextDistinct != nullptr && nextDistinct->data == current->data) {
                Node* duplicateNode = nextDistinct;
                nextDistinct = nextDistinct->next;
                delete duplicateNode; // Free memory of duplicate node
            }

            // Connect current node to the next distinct node
            current->next = nextDistinct;
            if (nextDistinct != nullptr) {
                nextDistinct->prev = current;
            }

            // Move to the next node
            current = current->next;
        }

        // Return the updated head of the list
        return head;
    }

    // Function to print the list
    void printList() {
        Node* current = head;

        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Driver code
int main() {
    Solution sol;

    // Initial list values (with duplicates)
    vector<int> values = {1, 2, 2, 2, 3, 4, 4, 5, 5, 6};

    for (int value : values) {
        sol.insertAtEnd(value);
    }

    // Print the original list
    cout << "Original List: ";
    sol.printList();

    // Remove duplicate nodes (keep only one occurrence)
    sol.removeDuplicates();

    // Print the updated list
    cout << "After Removing Duplicates (keeping 1 occurrence): ";
    sol.printList();

    return 0;
}
