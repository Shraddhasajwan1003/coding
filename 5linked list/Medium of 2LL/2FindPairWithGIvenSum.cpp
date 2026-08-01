//Find pairs with given sum in doubly linked list
// Given a sorted doubly linked list of positive distinct elements, the task is to find pairs in a doubly-linked list whose sum is equal to the given value x in sorted order.

// C++ program to find a pair with given sum x, Naive approach
// using map
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Function to find pairs in the doubly linked list
// whose sum equals the given value x
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
    vector<pair<int, int>> ans;
    unordered_map<int, Node *> visited;
    Node *currNode = head;

    // Traverse the doubly linked list
    while (currNode != nullptr) {
      
        int x = target - currNode->data;

        // Check if the target exists in the map
        if (visited.find(x) != visited.end()) {
          
            // Pair found
            ans.push_back({x, currNode->data});
        }

        // Store the current node's value in the map
        visited[currNode->data] = currNode;
        currNode = currNode->next;
    }

    sort(ans.begin(), ans.end());

    return ans;
}

int main() {
  
    // Create a doubly linked list: 1 <-> 2 <-> 4 <-> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);

    int target = 7;
    vector<pair<int, int>> pairs = findPairsWithGivenSum(head, target);

    if (pairs.empty()) {
        cout << "No pairs found." << endl;
    }
    else {
        for (auto &pair : pairs) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    return 0;
}


//two sum approach , two pointer approach 
// C++ program to find a pair with given sum target.
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next, *prev;

    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

// Function to find pairs in the doubly
// linked list whose sum equals the given value x
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {

    vector<pair<int, int>> res;

    // Set two pointers, first to the beginning of DLL
    // and second to the end of DLL.
    Node *first = head;
    Node *second = head;

    // Move second to the end of the DLL
    while (second->next != nullptr)
        second = second->next;

    // To track if we find a pair or not
    bool found = false;

    // The loop terminates when two pointers
    // cross each other (second->next == first),
    // or they become the same (first == second)
    while (first != second && second->next != first) {

        // If the sum of the two nodes is equal to x, print the pair
        if ((first->data + second->data) == target) {
            found = true;
            res.push_back({first->data, second->data});

            // Move first in forward direction
            first = first->next;

            // Move second in backward direction
            second = second->prev;
        }
        else {
            if ((first->data + second->data) < target)
                first = first->next;
            else
                second = second->prev;
        }
    }

    // If no pair is found
    return res;
}

int main() {

    // Create a doubly linked list: 1 <-> 2 <-> 4 <-> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(4);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(5);
    head->next->next->next->prev = head->next->next;

    int target = 7;
    vector<pair<int, int>> pairs = findPairsWithGivenSum(head, target);

    if (pairs.empty()) {
        cout << "No pairs found." << endl;
    }
    else {
        for (auto &pair : pairs) {
            cout << pair.first << " " << pair.second << endl;
        }
    }
    return 0;
}