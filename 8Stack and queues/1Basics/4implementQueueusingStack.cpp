//Implement Queue using Stack

// Problem Statement: Implement a First-In-First-Out (FIFO) queue using two stacks. The implemented queue should support the following operations: push, pop, peek, and isEmpty.

// Implement the StackQueue class:

// void push(int x): Adds element x to the end of the queue.
// int pop(): Removes and returns the front element of the queue.
// int peek(): Returns the front element of the queue without removing it.
// boolean isEmpty(): Returns true if the queue is empty, false otherwise.


//Using two Stacks where push operation is O(N)
//Time Complexity: O(n) for push operation, O(1) for pop and peek operations.

// Space Complexity: O(n) for storing elements in the stacks.
#include <bits/stdc++.h>
using namespace std;

// Queue implementation using stack
class StackQueue {
private:
    stack <int> st1, st2;

public: 
    // Empty Constructor
    StackQueue () {
        
    }
    
    // Method to push elements in the queue
    void push(int x) {
        /* Pop out elements from the first stack 
        and push on top of the second stack */
        while (!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }
        
        // Insert the desired element
        st1.push(x);
        
        /* Pop out elements from the second stack 
        and push back on top of the first stack */
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    // Method to pop element from the queue
    int pop() {
        // Edge case
        if (st1.empty()) {
            cout << "Stack is empty";
            return -1; // Representing empty stack
        }
        
        // Get the top element
        int topElement = st1.top();
        st1.pop(); // Perform the pop operation
        
        return topElement; // Return the popped value
    }
    
    // Method to get the front element from the queue 
    int peek() {
        // Edge case
        if (st1.empty()) {
            cout << "Stack is empty";
            return -1; // Representing empty stack
        }
        
        // Return the top element
        return st1.top();
    }
    
    // Method to find whether the queue is empty
    bool isEmpty() {
        return st1.empty();
    }
};

int main() {
    StackQueue q;
    
    // List of commands
    vector<string> commands = {"StackQueue", "push", "push", 
                               "pop", "peek", "isEmpty"};
    // List of inputs
    vector<vector<int>> inputs = {{}, {4}, {8}, {}, {}, {}};

    for (int i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            q.push(inputs[i][0]);
            cout << "null ";
        } else if (commands[i] == "pop") {
            cout << q.pop() << " ";
        } else if (commands[i] == "peek") {
            cout << q.peek() << " ";
        } else if (commands[i] == "isEmpty") {
            cout << (q.isEmpty() ? "true" : "false") << " ";
        } else if (commands[i] == "StackQueue") {
            cout << "null ";
        }
    }
    
    return 0;
}



//Use Two Stacks: Maintain two stacks, inputStack and outputStack.
// Push Operation:
// Add the element to inputStack. This operation is efficient and always takes O(1) time.
// Pop Operation:
// If the outputStack is empty, move all elements from inputStack to outputStack. This reversal of order ensures that the oldest element is on top of the outputStack.
// Remove and return the top element from outputStack. This represents the oldest element in the queue.
// Top Operation:
// If the outputStack is empty, move all elements from inputStack to outputStack to access the oldest element.
// Return the top element of outputStack without removing it. This gives the element that has been in the queue the longest.
// Size Operation:
// Return the sum of the sizes of both stacks. This total gives the number of elements currently in the queue.
#include <bits/stdc++.h>
using namespace std;

class StackQueue {
  public:
    stack<int> input, output;

    // Initialize your data structure here
    StackQueue() {}

    // Push element x to the back of queue
    void push(int x) {
        input.push(x);
    }

    // Removes the element from in front of queue and returns that element
    int pop() {
        // Shift input to output if output is empty
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        // If queue is still empty, return -1 (or throw an error if preferred)
        if (output.empty()) {
            cout << "Queue is empty, cannot pop." << endl;
            return -1;
        }

        int x = output.top();
        output.pop();
        return x;
    }

    // Get the front element
    int peek() {
        // Shift input to output if output is empty
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        // If queue is still empty, return -1 (or throw an error if preferred)
        if (output.empty()) {
            cout << "Queue is empty, cannot peek." << endl;
            return -1;
        }

        return output.top();
    }

    // Returns true if the queue is empty, false otherwise
    bool isEmpty() {
        return input.empty() && output.empty();
    }
};

int main() {
    StackQueue q;
    q.push(3);
    q.push(4);
    cout << "The element popped is " << q.pop() << endl;
    q.push(5);
    cout << "The front of the queue is " << q.peek() << endl;
    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    cout << "The element popped is " << q.pop() << endl;
    cout << "The element popped is " << q.pop() << endl;
    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}




 