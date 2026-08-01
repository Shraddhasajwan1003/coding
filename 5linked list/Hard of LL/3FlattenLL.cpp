//Flattening a Linked List

// Problem Statement: Given a linked list containing ‘N’ head nodes where every node in the linked list contains two pointers:

// ‘Next’ points to the next node in the list
// ‘Child’ pointer to a linked list where the current node is the head

// Each of these child linked lists is in sorted order and connected by a 'child' pointer. Your task is to flatten this linked list such that all nodes appear in a single layer or level in a 'sorted order'.


//Look at the picture in the folder for reference , also we have to make a special LINKED LIST structure for this thing 
// brute force we can store all the data of nodes in an array and sort it , then put it in a LL
#include <bits/stdc++.h>
using namespace std;

// Definition of special linked list:
struct ListNode {
    int val;
    ListNode *next;
    ListNode *child;
    ListNode() {
        val = 0;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1) {
        val = data1;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* next2) {
        val = data1;
        next = next1;
        child = next1;
    }
};

class Solution {
private:

//Time Complexity: O(N x M) + O(N x M log(N x M)) + O(N x M), where N is the number of nodes along the next pointers and M is the number of nodes along the child pointers.
// O(N x M) because we traverse through all the nodes, iterating through N nodes along the next pointers and M nodes along the child pointers.
// O(N x M log(N x M)) because we sort the array containing N x M total elements.
// O(N x M) because we reconstruct the linked list from the sorted array by iterating over the N x M elements.

// Space Complexity: O(N x M) + O(N x M), where N is the number of nodes along the next pointers and M is the number of nodes along the child pointers.
// O(N x M) for storing all the elements in an additional array for sorting.
// O(N x M) to reconstruct the linked list from the array after sorting.
    // Function to convert a vector to a linked list
    ListNode* convertArrToLinkedList(vector<int>& arr) {
        /* Create a dummy node to serve as
         the head of the linked list */
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        /* Iterate through the vector and
         create nodes with vector elements */
        for (int i=0; i < arr.size(); i++) {
            // Create a new node with the vector element
            temp->child = new ListNode(arr[i]);
            
            // Update the temporary pointer
            temp = temp->child;
        }
        
        /* Return the linked list starting
         from the next of the dummy node */
        return dummyNode->child;
    }

public:
    // Function to flatten a linked list with child pointers 
    ListNode* flattenLinkedList(ListNode* head) {
        vector<int> arr;

        // Traverse through the linked list
        while (head != nullptr) {
            /* Traverse through the child
             nodes of each head node */
            ListNode* t2 = head;
            
            while (t2 != nullptr) {
                // Store each node's data in the array
                arr.push_back(t2->val);
                
                // Move to the next child node
                t2 = t2->child;
            }
            // Move to the next head node
            head = head->next;
        }

        // Sort the array containing node values
        sort(arr.begin(), arr.end());

        // Convert the sorted array back to a linked list
        return convertArrToLinkedList(arr);
    }
};

// Function to print the linked list
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->child;
    }
    cout << endl;
}

// Function to print the linked list in a grid-like structure
void printOriginalLinkedList(ListNode* head, int depth) {
    while (head != nullptr) {
        cout << head->val;

        /* If child exists, recursively
         print it with indentation */
        if (head->child) {
            cout << " -> ";
            printOriginalLinkedList(head->child, depth + 1);
        }

        // Add vertical bars for each level in the grid
        if (head->next) {
            cout << endl;
            for (int i = 0; i < depth; ++i) {
                cout << "| ";
            }
        }
        head = head->next;
    }
}

int main() {
    // Create a linked list with child pointers
    ListNode* head = new ListNode(5);
    head->child = new ListNode(14);

    head->next = new ListNode(10);
    head->next->child = new ListNode(4);

    head->next->next = new ListNode(12);
    head->next->next->child = new ListNode(20);
    head->next->next->child->child = new ListNode(13);

    head->next->next->next = new ListNode(7);
    head->next->next->next->child = new ListNode(17);

    // Print the original linked list structure
    cout << "Original linked list:" << endl;
    printOriginalLinkedList(head, 0);

    // Creating an instance of Solution class
    Solution sol;
    
    // Function call to flatten the linked list
    ListNode* flattened = sol.flattenLinkedList(head);
    
    // Printing the flattened linked list
    cout << "\nFlattened linked list: ";
    printLinkedList(flattened);

    return 0;
}





Algorithm
Establish base case conditions by checking if the head is null or has no next pointer. If either condition is met, return the head, as there is no further flattening or merging required.
Recursively initiate the flattening process by calling flattenLinkedList on the next node (head -> next). The result of this recursive call will be the head of the flattened and merged linked list.
Within the recursive call, perform merge operations by calling a merge function. This function merges the current list with the already flattened and merged list based on their data values. The merged list is then updated in the head and returned as the result of the flattening process.
//finction 
class Solution {
private:
    /* Merge the two linked lists in a particular
     order based on the data value */
    ListNode* merge(ListNode* list1, ListNode* list2){
        /* Create a dummy node as a 
        placeholder for the result */
        ListNode* dummyNode = new ListNode(-1);
        ListNode* res = dummyNode;
    
        // Merge the lists based on data values
        while(list1 != NULL && list2 != NULL){
            if(list1->val < list2->val){
                res->child = list1;
                res = list1;
                list1 = list1->child;
            }
            else{
                res->child = list2;
                res = list2;
                list2 = list2->child;
            }
            res->next = NULL;
        }
    
        // Connect the remaining elements if any
        if(list1){
            res->child = list1;
        } else {
            res->child = list2;
        }
    
        // Break the last node's link to prevent cycles
        if(dummyNode->child){
            dummyNode->child->next = NULL;
        }
        
        return dummyNode->child;
    }

public:
    // Function to flatten a linked list with child pointers 
    ListNode* flattenLinkedList(ListNode* head) {
        // If head is null or there is no next node
        if(head == NULL || head->next == NULL){
            return head; // Return head
        }
    
        // Recursively flatten the rest of the linked list
        ListNode* mergedHead = flattenLinkedList(head->next);
        
        // Merge the lists
        head = merge(head, mergedHead);
        return head;
    }
};

// Function to print the linked list
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->child;
    }
    cout << endl;
}

// Function to print the linked list in a grid-like structure
void printOriginalLinkedList(ListNode* head, int depth) {
    while (head != nullptr) {
        cout << head->val;

        /* If child exists, recursively
         print it with indentation */
        if (head->child) {
            cout << " -> ";
            printOriginalLinkedList(head->child, depth + 1);
        }

        // Add vertical bars for each level in the grid
        if (head->next) {
            cout << endl;
            for (int i = 0; i < depth; ++i) {
                cout << "| ";
            }
        }
        head = head->next;
    }
}






























