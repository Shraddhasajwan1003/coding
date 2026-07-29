#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    // Node(int data1, Node* next1){ //no need to write 
    //     data=data1;
    //     next=next1;
    // }
    Node(int data1){
        data = data1;
        next=nullptr;
    }
};
class Solution{
    public:
    int lengthOfLL(Node* head){
        int cnt=0;
        Node* temp = head;
        while(temp!=nullptr){//TC is O(N)
        // while(temp->next->next!=NULL){ //better to use upper one 
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
};

int main() {
    Solution obj;
    // Creating a sample linked list
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    // Find and print the length of linked list
    cout << "Length of Linked List: "
         << obj.lengthOfLL(head) << endl;

    return 0;
}