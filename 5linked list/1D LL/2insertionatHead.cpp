#include <bits/stdc++.h>
using namespace std;
//class node to represent each node in LL
class Node {
public:
    int data;
    Node* next;
    Node(int data1, NOde* next1){
        data = data1;
        next=mext1;
    }
    Node(int data1){
        data=data1;
        next =nullptr;
    }
};

// Solution class to handle linked list operations
class Solution {
public:
    // Function to insert a new node at the head , iske liye we need head and new node ka data tbhi to new node bnegi and them head pe point kregi 
    Node* insertAtHead(Node* head, int newData) {
        // Create a new node whose next points to current head
        Node* newNode = new Node(newData, head);
        // Return the new node as the head
        return newNode;
    }
    //LL ko print krane ke liye bs head hi kafi h 
    // Function to print the linked list
    void printList(Node* head) {
        Node* temp = head;//ek temp pointer bnana h , usme head pass krna h and then use iterate krna h in whole LL
        while (temp != nullptr) {
            cout << temp->data << " ";//temp ka data print krao(head ka , bcz temp points to head) and then temp ke next ka 
            temp = temp->next;//ab temp yha increment hogya h maanlo
        }
        cout << endl;
    }
};

int main() {
    Solution sol;

    // Creating a sample linked list: 2 -> 3
    Node* head = new Node(2);//new node jiska naam head h , head of LL
    head->next = new Node(3);//head ke next wali node

    cout << "Original List: ";
    sol.printList(head);

    // Inserting new node at head
    head = sol.insertAtHead(head, 1);//head and new data pass kia h in argument of function

    cout << "After Insertion at Head: ";
    sol.printList(head);

    return 0;
}