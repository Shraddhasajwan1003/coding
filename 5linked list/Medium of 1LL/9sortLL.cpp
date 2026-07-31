//brute approach 
#include <bits/stdc++.h> 
using namespace std;

// Node class represents a linked list node
class Node {
public:
    // Data stored in the node
    int data;

    // Pointer to the next node
    Node* next;

    // Constructor with data and next pointer
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data
    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Solution class to hold sorting function
class Solution {
public:
    // Function to sort the linked list
    Node* sortLL(Node* head) {
        // Vector to store node values
        vector<int> arr;

        // Pointer to traverse the list
        Node* temp = head;

        // Traverse and push values into vector
        while (temp != nullptr) {
            arr.push_back(temp->data);
            temp = temp->next;
        }

        // Sort the vector
        sort(arr.begin(), arr.end());

        // Reassign sorted values to list nodes
        temp = head;
        for (int i = 0; i < arr.size(); i++) {
            temp->data = arr[i];
            temp = temp->next;
        }

        // Return head of sorted list
        return head;
    }

    //optimal 
    //Instead of using an external array to store node values, we can try to implement similar sorting techniques for linked lists as well. In order to sort the linked list, we can try to implement a modified version of Merge Sort Algorithm. This algorithm would divide the linked list into halves recursively until single nodes remain. These sorted halves of the linked list are merged back together in a sorted order.

    //If the linked list is empty or has only one node, it is already sorted, thus we can return the head directly.
    // Use the slow and fast pointer technique to find the middle of the linked list, where slow moves one step and fast moves two steps at a time.
    // Split the linked list into two halves at the midpoint by pointing middle to null, where the left half starts from the head and the right half starts from the node after the middle.
    // Recursively apply merge sort on both halves of the linked list until each part is broken down into single nodes or empty lists.
    // Merge the two sorted halves using a helper function that compares node values from both halves, attaches the smaller one to the result list, and continues until all nodes from both halves are merged.
    // Return the head of the merged and fully sorted linked list, which will represent the final sorted list.


//merge sort technique

       // Function to merge two sorted linked lists
    Node* mergeTwoSortedLinkedLists(Node* list1, Node* list2) {
        // Create a dummy node
        Node* dummyNode = new Node(-1);
        
        // Temp pointer to build merged list
        Node* temp = dummyNode;

        // Traverse both lists
        while (list1 != nullptr && list2 != nullptr) {
            // Choose smaller node
            if (list1->data <= list2->data) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            // Move temp pointer
            temp = temp->next;
        }

        // Attach remaining nodes
        if (list1 != nullptr) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }

        // Return head of merged list
        return dummyNode->next;
    }

    // Function to find middle of linked list
    Node* findMiddle(Node* head) {
        // If list empty or single node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Slow and fast pointers
        Node* slow = head;
        Node* fast = head->next;

        // Move fast twice as fast as slow
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Return middle node
        return slow;
    }

    // Function to perform merge sort
    Node* sortLL(Node* head) {
        // Base case: empty or single node
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // Find middle node
        Node* middle = findMiddle(head);

        // Split into two halves
        Node* right = middle->next;
        middle->next = nullptr;
        Node* left = head;

        // Recursively sort both halves
        left = sortLL(left);
        right = sortLL(right);

        // Merge sorted halves
        return mergeTwoSortedLinkedLists(left, right);
    }
};

// Function to print linked list
void printLinkedList(Node* head) {
    // Temp pointer to traverse
    Node* temp = head;

    // Traverse and print nodes
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
};

// Function to print linked list
void printLinkedList(Node* head) {
    // Pointer to traverse list
    Node* temp = head;

    // Traverse and print values
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create linked list: 3 -> 2 -> 5 -> 4 -> 1
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(5);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(1);

    // Print original list
    cout << "Original Linked List: ";
    printLinkedList(head);

    // Create Solution object
    Solution obj;

    // Sort the linked list
    head = obj.sortLL(head);

    // Print sorted list
    cout << "Sorted Linked List: ";
    printLinkedList(head);

    return 0;
}


