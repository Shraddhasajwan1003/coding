//Detect a cycle in a LL
//brute force says to hash the LL , mark visited ones 
//Traverse the entire linked list using a temporary pointer.
// While traversing, keep a track of the visited nodes in the map data structure.
// If a previously visited node is encountered again, that proves that there is a loop in the linked list hence return true.
// If the traversal is completed, and we reach the last point of the list which is null, it means there was no loop, hence we return false.
// Storing the entire node in the map is essential to distinguish between nodes with identical values but different positions in the list. This ensures accurate loop detection and not just duplicate value checks.
//brute force TC is O(NlogN), amp ki worst complexity is logN
#include <bits/stdc++.h>
using namespace std;

// Node class represents a linked list node
class Node {
public:
    // Data stored in the node
    int data;

    // Pointer to the next node
    Node* next;

    // Constructor with data and next
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

// Solution class contains the loop detection method
class Solution {
public:
    // Function to detect a loop in the linked list
    bool detectLoop(Node* head) {
        // Initialize a pointer at head
        Node* temp = head;

        // Create a map to keep track of visited nodes
        unordered_map<Node*, int> nodeMap;

        // Traverse the linked list
        while (temp != nullptr) {
            // If node already exists in map, loop detected
            if (nodeMap.find(temp) != nodeMap.end()) {
                return true;
            }
            // Store the current node in the map
            nodeMap[temp] = 1;

            // Move to the next node
            temp = temp->next;
        }

        // If traversal completes, no loop detected
        return false;
    }
    //Tc  is O(N)
    // Tortoise and Hare Algorithm (Floyd’s Cycle Detection).
    // Function to detect a loop in a linked
    // list using the Tortoise and Hare Algorithm
    bool hasCycle(ListNode *head) {
        // Initialize two pointers, slow and fast,
        // to the head of the linked list
        ListNode *slow = head;
        ListNode *fast = head;

        // Step 2: Traverse the linked list with
        // the slow and fast pointers
        while (fast != nullptr && fast->next != nullptr) {
            // Move slow one step
            slow = slow->next;
            // Move fast two steps
            fast = fast->next->next;

            // Check if slow and fast pointers meet
            if (slow == fast) {
                return true;  // Loop detected
            }
        }

        // If fast reaches the end of the list,
        // there is no loop
        return false;
    }
};

// Driver function
int main() {
    // Create sample linked list nodes
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    // Link the nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Create a loop for testing
    fifth->next = third;

    // Create a Solution object
    Solution obj;

    // Check if loop exists
    if (obj.detectLoop(head)) {
        cout << "Loop detected in the linked list." << endl;
    } else {
        cout << "No loop detected in the linked list." << endl;
    }

    // Free allocated memory
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;

    return 0;
}























































































