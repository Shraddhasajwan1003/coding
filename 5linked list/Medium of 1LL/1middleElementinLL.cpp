//Find middle element in a Linked List

// Problem Statement: Given the head of a linked list of integers, determine the middle node of the linked list. However, if the linked list has an even number of nodes, return the second middle node.

#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
   
    Node(int data1, Node* next1){
        data=data1;
        next=next1;
        
    }

    Node(int data1){
        data=data1;
        next=nullptr;
       
    }
};
class Solution {
public:
//TC is O(N+N/2)
    Node* middlenodefind_brute(Node* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        int cnt=0;
        Node* temp=head;//head pointer passed on temp
        while(temp!=nullptr){
            cnt++;
            temp=temp->next;
        }
        int mid=cnt/2+1;
        temp=head;//take temp back to head 
        while(temp!=NULL){
            mid =mid-1;//equal to mid--
            if(mid==0){//if mid =0, temp reached middle 
                break;
            }
            temp=temp->next;
        }
        return temp;
    }

    Node* middlenode_optimal(Node* head){
        Node* fast=head;
        Node* slow=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};

int main() {
    Solution obj;
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    //below commented way is not right way to call the function, it will give wrong value bexuase after first functauon call head will point to temp of that function that is 3 in this case , and next function will treat head as 3 and find mid of 3,4, 5 , that gives us 4 
    // Node* head2= head;
    // head= obj.middlenodefind_brute(head);
    // head2= obj.middlenode_optimal(head);

    // cout<<"the middle value is : "<<head->data<<endl;
    // cout<<"the middle value is : "<<head2->data<<endl;

    // Store middle nodes in separate variables without overwriting 'head'
    Node* mid_brute   = obj.middlenodefind_brute(head);
    Node* mid_optimal = obj.middlenode_optimal(head);

    cout << "Brute Force Middle Value: " << mid_brute->data << endl;
    cout << "Optimal Middle Value: " << mid_optimal->data << endl;

    return 0;
}




































































































