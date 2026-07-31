// Problem Statement: Given the head of a linked list that may contain a cycle, return the starting point of that cycle. If there is no cycle in the linked list return null.
// brute force sya swe need to mark the nodes as visited or unvivited , if visted twice then it is then starting point , but if temp reaches null then LL has no loop
// we use map
#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

class Solution
{
public:
    // TC is O(N) , SC is O(N)
    //  Function to detect start of loop using Hash Map
    ListNode *detectCycle(ListNode *head)
    {
        // Create a map to store visited nodes
        unordered_set<ListNode *> visited;

        // Start traversing from head
        while (head != NULL)
        {
            // If current node is already in set, it's the start of loop
            if (visited.find(head) != visited.end())
            { // found the starting node just returning it
                return head;
            }

            // Otherwise, insert current node into set
            visited.insert(head); // here we are storing ptr , not the number as value can be same(which also stored ) but address is always unique

            // Move to the next node
            head = head->next;
        }

        // If loop not found, return NULL
        return NULL;
    }

    // optimal approach (tortoise hare algo is used here )
    // first use fast and slow ptr , keep them at head , then when they both meet it means there is a cycle , if fast reaches null then no cycle
    // now both ptr met , put slow at head and start moving both again , now the point where they meet will be the starting point of loop
    // logic : If slow has travelled distance L1 then fast has travelled 2 x L1. Now that slow and fast have entered the loop, the distance fast will have to cover to catch up to slow is the total length of loop minus L1. Let this distance be d. Distance travelled by slow = L1 Distance travelled by fast = 2 * L1 Total length of loop = L1 + d

    // In this configuration, the fast pointer advances toward the slow pointer with two jumps per step, while the slow pointer moves away with one jump per step. As a result, the gap between them decreases by 1 with each step. Given that the initial gap is d, it takes exactly d steps for them to meet.
    //  Total length of loop = L1 + d Distance between slow and fast = d

    // TC is O(N)
    ListNode *detectcycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                slow = head;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // yha slow inside loop return hoga bcz cycle nhi hoga to null return loop ke baad hoga return
            }
        }
        return NULL;
    }
};

// Driver code
int main()
{
    // Creating nodes
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Creating a cycle (tail connects to node index 1)
    head->next->next->next->next = head->next;

    Solution obj;
    ListNode *startNode = obj.detectCycle(head);

    if (startNode)
        cout << "Cycle starts at node with value: " << startNode->val << endl;
    else
        cout << "No cycle found." << endl;

    return 0;
}



//LENGTH OF LOOP IN LL
//Problem Statement: Given the head of a linked list, determine the length of a loop present in the linked list. If there's no loop present, return 0.
//While traversing the linked list, employ a timer against each node to keep track of the number of nodes you've visited before it. Once a previously visited node is encountered again, the length of the loop can be determined by subtracting the timer values at the two instances of visiting that particular node.
#include <bits/stdc++.h>
using namespace std;

// Node class represents a node in a linked list
class Node {
public:
    // Data stored in the node
    int data;

    // Pointer to the next node
    Node* next;

    // Constructor with both data and next node
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

// Solution class containing the loop length function
//brute one has TC and SC is O(N)
class Solution {
public:
    // Function to return the length of loop using hashing
    int lengthOfLoop(Node* head) {
        // Hashmap to store visited nodes and their timer values
        unordered_map<Node*, int> visitedNodes;

        // Pointer to traverse the linked list
        Node* temp = head;

        // Timer to track visited nodes
        int timer = 0;

        // Traverse the linked list till temp reaches nullptr
        while (temp != NULL) {
            // If revisiting a node, return the difference of timer values
            if (visitedNodes.find(temp) != visitedNodes.end()) {
                // Calculate the length of the loop
                int loopLength = timer - visitedNodes[temp];

                // Return the length of the loop
                return loopLength;
            }

            // Store the current node and its timer value
            visitedNodes[temp] = timer;

            // Move to the next node
            temp = temp->next;

            // Increment the timer
            timer++;
        }

        // If traversal is completed and we reach the end of the list
        // means there is no loop
        return 0;
    }

    //again use tortoise and hare algo 
    //we go for fast and slow to meet up , where they meet we keep slow there fixed 
    //then we take a counter from there and do cnt++ , this traversal is done by fast pointer and when they meet again , return cnt ( this is the length of loop) 
    // Function to count loop length
    int countLoopLength(Node* meetingPoint) {
        // Start from meeting point
        Node* temp = meetingPoint;
        int length = 1;

        // Move until we meet again
        while (temp->next != meetingPoint) {
            temp = temp->next;
            length++;
        }
        return length;
    }
    int lengthOfLoop(Node* head) {
        // Initialize slow and fast pointers
        Node* slow = head;
        Node* fast = head;

        // Loop until fast and slow meet
        while (fast != NULL && fast->next != NULL) {
            // Move slow by one step
            slow = slow->next;

            // Move fast by two steps
            fast = fast->next->next;

            // If slow and fast meet, loop detected
            if (slow == fast) {
                // Count the length of the loop
                return countLoopLength(slow);
            }
        }

        // No loop found
        return 0;
    }

};

// Main driver function
int main() {
    // Creating a sample linked list with a loop
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    // Linking the nodes
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Creating a loop from fifth to second
    fifth->next = second;

    // Creating a Solution object
    Solution obj;

    // Getting the loop length
    int loopLength = obj.lengthOfLoop(head);

    // Printing the result
    if (loopLength > 0) {
        cout << "Length of the loop: "
             << loopLength << endl;
    } else {
        cout << "No loop found in the linked list."
             << endl;
    }

    return 0;
}
























































































































