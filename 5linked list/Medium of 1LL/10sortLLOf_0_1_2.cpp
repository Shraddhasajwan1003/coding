//Problem Statement: Given a linked list containing only 0's, 1's, and 2's, sort the linked list by rearranging the links (not by changing the data values).
//Input: 1 -> 2 -> 0 -> 1 -> 0 -> 2 -> NULL
// Output: 0 -> 0 -> 1 -> 1 -> 2 -> 2 -> NULL
// Input: 2 -> 1 -> 2 -> 0 -> 0 -> 1 -> NULL
// Output: 0 -> 0 -> 1 -> 1 -> 2 -> 2 -> NULL
#include <bits/stdc++.h>
using namespace std;

// Node class representing each element of the linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor to initialize node with a value
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// LinkedList class to manage list operations
class LinkedList {
public:
    Node* head;

    // Constructor to initialize an empty list
    LinkedList() {
        head = nullptr;
    }

    // Function to insert a new node at the end
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode; 
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    // Function to print the entire linked list
    void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << " -> NULL\n";
    }
};

// Solution class containing logic for sorting the list
class Solution {
public:
    // Function to sort linked list of 0s, 1s, and 2s by rearranging the links
    void sortZeroOneTwo(LinkedList& ll) {
        // Create dummy nodes for three lists: 0s, 1s, and 2s
        Node* zeroDummy = new Node(-1);
        Node* oneDummy = new Node(-1);
        Node* twoDummy = new Node(-1);

        // Tail pointers to build each of the lists
        Node* zeroTail = zeroDummy;
        Node* oneTail = oneDummy;
        Node* twoTail = twoDummy;

        // Traverse original list and distribute nodes into 0s, 1s, or 2s list
        Node* curr = ll.head;
        while (curr) {
            if (curr->data == 0) {
                zeroTail->next = curr;
                zeroTail = zeroTail->next;
            } else if (curr->data == 1) {
                oneTail->next = curr;
                oneTail = oneTail->next;
            } else {
                twoTail->next = curr;
                twoTail = twoTail->next;
            }
            curr = curr->next;
        }

        // Connect the three lists:
        // zeroTail -> oneDummy.next -> twoDummy.next
        // Handle edge cases if 0s or 1s list is empty
        zeroTail->next = oneDummy->next ? oneDummy->next : twoDummy->next;
        oneTail->next = twoDummy->next;
        twoTail->next = nullptr;  // end the list

        // Update head to new sorted list
        ll.head = zeroDummy->next;

        // Delete dummy nodes (they were placeholders)
        delete zeroDummy;
        delete oneDummy;
        delete twoDummy;
    }
};

// Driver code to demonstrate usage
int main() {
    LinkedList ll;
    Solution sol;

    // Insert nodes into the list
    ll.insert(1);
    ll.insert(2);
    ll.insert(0);
    ll.insert(1);
    ll.insert(2);
    ll.insert(0);

    cout << "Original List:\n";
    ll.print();

    // Sort the list using rearrangement of links
    sol.sortZeroOneTwo(ll);

    cout << "Sorted List:\n";
    ll.print();

    return 0;
}





























