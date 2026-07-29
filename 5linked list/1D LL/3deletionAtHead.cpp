//Delete Last Node of Linked List
//Problem Statement: Given a Linked List, delete the tail of the list and print the updated list.

// Examples
// Input: 0->1->2
//ouput: 0->1

//Some edge cases to consider is when the list is empty or when there is only one node in the entire list.
// If the list is empty, return immediately as there is nothing to delete.
// If list has only one node, delete the node and return an empty list.
// Traverse the linked list to the second last node and keep track of it using the tail pointer.
// Set the next pointer of the second last node to null. This step effectively disconnects the initial tail node from the list, making second last node as the new tail node.
// Deallocate the memory occupied by the tail node by deleting it.
// Return the head of the doubly linked list as the result.
#include <bits/stdc++.h>
using namespace std;

// Definition for singly linked list
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Solution {
public:
    // Function to delete tail node of linked list
    Node* deleteTail(Node* head) {
        // If list is empty or has one node
        if (head == NULL || head->next == NULL) {
            delete head;
            return NULL;
        }

        // Traverse to the second last node
        Node* curr = head;
        while (curr->next->next != NULL) {
            curr = curr->next;
        }

        // Delete tail node
        delete curr->next;
        curr->next = NULL;

        // Return updated head
        return head;
    }
};

// Driver code
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    Solution obj;
    head = obj.deleteTail(head);

    // Print list after deletion
    Node* temp = head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}


void deleteNodeatanypositiongiven(ListNode* node){
    ListNode* temp=node->next;
    node->val=temp->val;
    node->next=temp->next;
    delete temp;
}
