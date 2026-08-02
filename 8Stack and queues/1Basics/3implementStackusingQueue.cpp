//Problem Statement: Implement a Last-In-First-Out (LIFO) stack using a single queue. The implemented stack should support the following operations: push, pop, top, and isEmpty.

// Implement the QueueStack class:

// push(int x): Pushes element x onto the stack.
// pop(): Removes and returns the top element of the stack.
// top(): Returns the top element of the stack without removing it.
// isEmpty(): Returns true if the stack is empty, false otherwise.

#include <bits/stdc++.h>
using namespace std;

// Stack implementation using Queue
class QueueStack {
    // Queue
    queue<int> q;

public:
    // Method to push element in the stack
    void push(int x) {
        // Get size 
        int s = q.size(); 
        // Add element
        q.push(x); 

        // Move elements before new element to back
        for (int i = 0; i < s; i++) {
            q.push(q.front()); 
            q.pop(); 
        }
    }

    // Method to pop element from stack
    int pop() {
        // Get front element 
        int n = q.front(); 
        // Remove front element
        q.pop(); 
        // Return removed element
        return n; 
    }

    // Method to return the top of stack
    int top() {
        // Return front element
        return q.front(); 
    }

    // Method to check if the stack is empty
    bool isEmpty() {
        return q.empty(); 
    }
};

int main() {
    QueueStack st;
    
    // List of commands
    vector<string> commands = {"QueueStack", "push", "push", 
                               "pop", "top", "isEmpty"};
    // List of inputs
    vector<vector<int>> inputs = {{}, {4}, {8}, {}, {}, {}};

    for (int i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            st.push(inputs[i][0]);
            cout << "null ";
        } else if (commands[i] == "pop") {
            cout << st.pop() << " ";
        } else if (commands[i] == "top") {
            cout << st.top() << " ";
        } else if (commands[i] == "isEmpty") {
            cout << (st.isEmpty() ? "true" : "false") << " ";
        } else if (commands[i] == "QueueStack") {
            cout << "null ";
        }
    }

    return 0;
}