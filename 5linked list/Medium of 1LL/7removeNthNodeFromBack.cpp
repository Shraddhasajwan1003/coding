//Problem Statement: Given a linked list and an integer N, the task is to delete the Nth node from the end of the linked list and print the updated linked list.
//brute force lenght niaklo and then delete (L-N+1)th node 
//if N=1 then we have to delete tail of LL 
//if N=L we need to delete head fo the LL
// Input:  5->1->2, N=2
// Output: 5->2
// Explanation: The 2nd node from the end of the linked list is 1. Therefore, we get this result after removing 1 from the linked list.

// Input:  1->2->3->4->5, N=3
// Output: 1->2->4->5
// Explanation: The 3rd node from the end is 3, therefore, we remove 3 from the linked list.

#include <bits/stdc++.h>
using namespace std;

// Class representing a node in the linked list
class Node {
public:
    int data;
    Node* next;

    // Constructor for Node with data and next node
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor for Node with only data 
    // (next set to nullptr)
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Class to hold the solution logic
class Solution {
public:
    // Function to print the linked list
    void printLL(Node* head) {
        while (head != NULL) {
            cout << head->data << " ";
            head = head->next;
        }
    }
    // 
    // Function to delete the Nth node from the end
    Node* deleteNthNodeFromEnd(Node* head, int N) {
        // If list is empty, return NULL
        if (head == NULL) {
            return NULL;
        }

        int cnt = 0;
        Node* temp = head;

        // Count the number of nodes in the linked list
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }

        // If N equals the total number of nodes, delete the head
        if (cnt == N) {
            Node* newHead = head->next;
            // free memory
            delete head; 
            return newHead;
        }

        // Calculate the position from start to delete
        int res = cnt - N;
        temp = head;

        // Traverse to the node just before the one to delete
        while (temp != NULL) {
            res--;
            if (res == 0) {
                break;
            }
            temp = temp->next;
        }

        // Delete the target node
        Node* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode; // free memory

        return head;
    }
    //OPTIMAL BY TORTOISE HARE ALGO
    // Function to delete the Nth node from the end 
    // using the optimized two-pointer method
    Node* deleteNthNodeFromEnd(Node* head, int N) {
        // Create a dummy node before head to handle edge cases
        Node* dummy = new Node(0, head);

        // Initialize slow and fast pointers at dummy
        Node* slow = dummy;
        Node* fast = dummy;

        // Move fast pointer N+1 steps ahead to create a gap
        for (int i = 0; i <= N; i++) {
            fast = fast->next;
        }

        // Move both pointers until fast reaches the end
        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        // Slow is now at node before target → delete target node
        slow->next = slow->next->next;

        // Return updated head
        return dummy->next;
    }


};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int N = 3;

    // Creating linked list manually
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);

    Solution sol;
    head = sol.deleteNthNodeFromEnd(head, N);
    sol.printLL(head);
}
  