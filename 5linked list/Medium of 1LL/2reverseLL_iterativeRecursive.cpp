//Reverse a Linked List
//recursive approacj at bottom 
// Problem Statement: Given the head of a singly linked list, write a program to reverse the linked list, and return the head pointer to the reversed list.

#include <bits/stdc++.h>
using namespace std;
class ListNode{
public:
int data;
ListNode* next;
ListNode(int data1,ListNode* next1){
    data=data1;
    next=next1;
}
ListNode(int data1){
    data=data1;
    next=nullptr;
}

};
class Solution {
public:
    //brute h stack use kro , best but space lega 
    //A straightforward approach to reversing a singly linked list is to use an additional data structure such as a stack. As we traverse the list, we push each node’s value onto the stack. Since stacks follow Last-In-First-Out (LIFO) order, popping elements from the stack gives us the values in reverse order. After the stack is filled, we reassign the values to the nodes while traversing the original list again. This effectively reverses the list in terms of values without modifying node links.
//TC and SC is O(n)
    ListNode* reverseList_brute(ListNode* head) {
        stack<int>st;
        ListNode*temp=head;
        while(temp!=NULL){

            st.push(temp->data);
            temp=temp->next;

        }
        temp=head;
        while(temp!=NULL){
            temp->data=st.top();
            st.pop();
            temp=temp->next;
        }
        return head;
    }
//chnage pointers 
    ListNode* reverselist_optimal(ListNode* head){
        //ek pointer lo traverse krne ke liye , ek prev ptr bhi lo and set it to null , traverse the ptr upto it reaches null meanwhile reversing the pointers and at last return the prev ptr as head of LL

        ListNode* prev=NULL;
        ListNode* temp=head;
        while(temp!=NULL){
            ListNode* front=temp->next;
            temp->next=prev;
            prev=temp;
            temp=front;
        }
        return prev;

    }
};

int main() {
    Solution obj;
    // Creating linked list 1 -> 2 -> 3 -> NULL
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    ListNode* brute=head;
    brute=obj.reverseList_brute(head);

    //print LL
    while(brute!=NULL){
        cout<<brute->data<<" ";//yha brute->next lihoge to address print ho jayega so you better not do this blunder
        brute=brute->next;
    }
    return 0;
}

//recursive approach 
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // Recursive function to reverse the linked list
    ListNode* reverseList(ListNode* head) {
        // Base case: if list is empty or has one node
        if (head == NULL || head->next == NULL)
            return head;

        // Recursively reverse the rest of the list
        ListNode* newHead = reverseList(head->next);

        // Store the next node
        ListNode* front = head->next;

        // Make the next node point back to current
        front->next = head;

        // Break the current node's forward link
        head->next = NULL;

        // Return the new head of the reversed list
        return newHead;
    }
};

// Driver code
int main() {
    // Creating linked list 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    ListNode* reversed = sol.reverseList(head);

    // Printing reversed list
    while (reversed != NULL) {
        cout << reversed->val << " ";
        reversed = reversed->next;
    }
    cout << endl;
    return 0;
}























