//Problem Statement: Given the head of a linked list of integers, delete the middle node of the linked list and return the modified head. However, if the linked list has an even number of nodes, delete the second middle node.

// Input: 1->2->3->4->5 
// Output: 1->2->4->5
// Explanation: Node with value 3 is at the middle node and deleted.
// Input: 1->2->3->4
// Output: 1->2->4
// Explanation: The linked list has an even number of nodes hence we delete the second middle node which is 3.


//brute force , find total no of nodes , then do n/2 , traverse till n/2 by keeping a count , then delete the node 
//O(N + N/2)
#include <bits/stdc++.h>
using namespace std;

// Node class represents a node in a linked list
class Node {
public:
    // Data stored in the node
    int data;  
    
    // Pointer to the next node in the list
    Node* next;     
    
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

// Solution class containing the delete function
class Solution {
public:
    // Function to delete the middle node of a linked list
    Node* deleteMiddle(Node* head) {
        // Initialize a temporary node to traverse the linked list
        Node* temp = head;
        
        // Variable to hold the number of nodes in the linked list
        int n = 0;
        
        // Loop to count the number of nodes in the linked list
        while (temp != NULL) {
            n++;
            temp = temp->next;
        }
        
        // Calculate the index of the middle node
        int res = n / 2;
        
        // Reset the temporary node to the beginning of the linked list
        temp = head;
        
        // Loop to find the middle node to delete
        while (temp != NULL) {
            res--;
            
            // If the middle node is found
            if (res == 0) {
                // Create a pointer to the middle node
                Node* middle = temp->next;
                
                // Adjust pointers to skip the middle node
                temp->next = temp->next->next;
                
                // Free the memory allocated to the middle node
                free(middle);
                
                // Exit the loop after deleting the middle node
                break;
            }
            
            // Move to the next node in the linked list
            temp = temp->next;
        }
        
        // Return the head of the modified linked list
        return head;
    }

    //optimal by tortoise hare 
    // Function to delete the middle node using slow and fast pointer
Node* deleteMiddle(Node* head) {
    // If list has only one node, delete it
    if (head == nullptr || head->next == nullptr) {
        // delete head; dont use this its gives runtime error
        //Deleting head frees the memory prematurely, causing a heap-use-after-free error when the platform's internal cleanup routine tries to access it.
        return nullptr;
    }

    // Initialize slow pointer to head
    Node* slow = head;

    // Initialize fast pointer two steps ahead
    Node* fast = head->next->next;

    // Traverse until fast reaches end
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Pointer to middle node
    Node* middle = slow->next;

    // Bypass the middle node
    slow->next = slow->next->next;

    // Delete middle node
    delete middle;

    // Return head of updated list
    return head;
}
};

// Function to print the linked list
void printLL(Node* head) {
    // Initialize a temporary pointer
    Node* temp = head;
    
    // Traverse the linked list and print data
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    
    // Print a newline after the list
    cout << endl;
}

// Driver function
int main() {
    // Creating a sample linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    
    // Display the original linked list
    cout << "Original Linked List: ";
    printLL(head);

    // Create a Solution object
    Solution obj;
    
    // Deleting the middle node
    head = obj.deleteMiddle(head);

    // Displaying the updated linked list
    cout << "Updated Linked List: ";
    printLL(head);

    return 0;
}

