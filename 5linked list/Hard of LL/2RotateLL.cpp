// Rotate a Linked List

// Problem Statement: Given the head of a singly linked list containing integers, shift the elements of the linked list to the right by k places and return the head of the modified list. Do not change the values of the nodes, only change the links between nodes.

// Examples
// Input : head -> 1 -> 2 -> 3 -> 4 -> 5, k = 2
// Output : head -> 4 -> 5 -> 1 -> 2 -> 3

// Explanation :List after 1 shift to right: head -> 5 -> 1 -> 2 -> 3 -> 4.
// List after 2 shift to right: head -> 4 -> 5 -> 1 -> 2 -> 3.

// eg2:
// Input : head -> 1 -> 2 -> 3 -> 4 -> 5, k = 4
// Output :head -> 2 -> 3 -> 4 -> 5 -> 1
// Explanation :List after 1 shift to right: head -> 5 -> 1 -> 2 -> 3 -> 4.
// List after 2 shift to right: head -> 4 -> 5 -> 1 -> 2 -> 3.
// List after 3 shift to right: head -> 3 -> 4 -> 5 -> 1 -> 2.
// List after 4 shift to right: head -> 2 -> 3 -> 4 -> 5 -> 1.

// Initialize a pointer to traverse the list from head.
// Traverse to the second-last node of the list.
// Store the last node separately.
// Make the second-last node point to null (removing the last node).
// Insert the stored last node at the beginning by:
// Pointing its next to the current head.
// Updating the head to this node.
// Return the new head of the list.

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list node
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    // Time Complexity: O(k * n)
    //  Function to rotate the list to the right by k positions
    ListNode *rotateRight(ListNode *head, int k)
    {
        // If list is empty or has only one node or no rotation needed
        if (!head || !head->next || k == 0)
            return head;

        // Repeat the rotation process k times
        for (int i = 0; i < k; i++)
        {
            // Initialize two pointers to traverse the list
            ListNode *curr = head;
            ListNode *prev = NULL;

            // Traverse to the last node
            while (curr->next)
            {
                prev = curr;
                curr = curr->next;
            }

            // Detach the last node and place it at the beginning
            prev->next = NULL;
            curr->next = head;
            head = curr;
        }

        // Return the rotated head
        return head;
    }



    //OPTIMAL SOLUTION WITH TC O(N)
    // Function to rotate the linked list to the right by k places
    ListNode *rotateRight(ListNode *head, int k)
    {
        // If list is empty or has only one node, or no rotation is needed
        if (!head || !head->next || k == 0)
            return head;

        // Initialize length and tail pointer
        int length = 1;
        ListNode *tail = head;

        // Traverse to find the tail and length
        while (tail->next)
        {
            tail = tail->next;
            length++;
        }

        // Make it a circular linked list
        tail->next = head;

        // Effective rotations needed
        k = k % length;

        // Traverse to the new tail (length - k - 1 steps from head)
        int stepsToNewTail = length - k;
        ListNode *newTail = head;
        for (int i = 1; i < stepsToNewTail; i++)
        {
            newTail = newTail->next;
        }

        // Set the new head
        ListNode *newHead = newTail->next;

        // Break the circle
        newTail->next = NULL;

        return newHead;
    }
};

// Driver code
int main()
{
    // Creating the linked list 1->2->3->4->5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution obj;
    int k = 2;
    ListNode *result = obj.rotateRight(head, k);

    // Printing the rotated list
    while (result)
    {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
