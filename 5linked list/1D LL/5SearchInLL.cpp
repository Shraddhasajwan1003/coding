#include <bits/stdc++.h>
using namespace std;

//TC is O(N)
class Node{
public:
int data;
Node* next;

// Node(data1){
//     data=data1;
//     next=nullptr;
// }

//rather than this constructor go for member initiliser list in cpp, same thing 
Node(int val) : data(val), next(nullptr) {}
};
class Solution {
public:
    bool searchElementInLL(Node* head ,int key ){
        Node*temp=head;
        while(temp!=nullptr){
            if(temp->data==key){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }
};

int main() {
    
    Node* head=new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    Solution obj;

    // Search for value
    if (obj.searchElementInLL(head, 20))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    return 0;
}