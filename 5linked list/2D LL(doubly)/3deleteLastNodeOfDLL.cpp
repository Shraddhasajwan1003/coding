//Delete Last Node of a Doubly Linked List
//Problem Statement: Given a Doubly Linked List, delete the last node of the Doubly Linked List.

//To delete the tail of a doubly linked list, we update the linkage between its last node and its second last node. Since a doubly linked list is bidirectional, we set the second last node's next pointer and the last node's back pointer to null. Then, we can return the head of the doubly linked list as the result.

#include <bits/stdc++.h>
using namespace std;

// Node structure for DLL
struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class Solution {
public:
    // Function to delete tail of DLL
    Node* deleteTail(Node* head) {
        // If list is empty
        if (head == NULL) return NULL;

        // If only one node present
        if (head->next == NULL) {
            delete head;
            return NULL;
        }

        // Traverse to the last node
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        // Update second last node's next to NULL
        temp->prev->next = NULL;

        // Delete tail node
        delete temp;

        // Return head
        return head;
    }
};

int main() {
    // Create a sample DLL: 1 <-> 2 <-> 3
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    Solution obj;
    head = obj.deleteTail(head);

    // Print list after deletion
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    return 0;
}
