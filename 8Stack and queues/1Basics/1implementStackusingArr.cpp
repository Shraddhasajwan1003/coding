//stack mtlb last in first out 
//Problem Statement: Implement a Last-In-First-Out (LIFO) stack using an array. The implemented stack should support the following operations: push, pop, peek, and isEmpty.

// Implement the ArrayStack class:

// void push(int x): Pushes element x onto the stack. int pop(): Removes and returns the top element of the stack. int top(): Returns the top element of the stack without removing it. boolean isEmpty(): Returns true if the stack is empty, false otherwise.
// Example 1:
// Input:
  
// ["ArrayStack", "push", "push", "top", "pop", "isEmpty"]  
// [[], [5], [10], [], [], []]  
// Output:
//   [null, null, null, 10, 10, false]  
// Explanation:
//   ArrayStack stack = new ArrayStack();  
// - stack.push(5);  
// - stack.push(10);  
// - stack.top(); // returns 10  
// - stack.pop(); // returns 10  
// - stack.isEmpty(); // returns false  

// Example 2:
// Input:
  
// ["ArrayStack", "isEmpty", "push", "pop", "isEmpty"]  
// [[], [], [1], [], []]  
// Output:
//  [null, true, null, 1, true]  
// Explanation:
//   ArrayStack stack = new ArrayStack();  
// - stack.push(1);  
// - stack.pop(); // returns 1  
// - stack.isEmpty(); // returns true

//TC IS O(1) and SC IS O(1)
#include <bits/stdc++.h>
using namespace std;

class ArrayStack {
private:
    // Array to hold elements
    int* stackArray;
    // Maximum capacity
    int capacity; 
     // Index of top element  
    int topIndex;   

public:
    // Constructor
    ArrayStack(int size = 1000) {
        capacity = size;
        stackArray = new int[capacity];
        // Initialize stack as empty
        topIndex = -1; 
    }

    // Destructor
    ~ArrayStack() {
        delete[] stackArray;
    }

    // Pushes element x 
    void push(int x) {
        if (topIndex >= capacity - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        stackArray[++topIndex] = x;
    }

    // Removes and returns top element
    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            // Return invalid value
            return -1; 
        }
        return stackArray[topIndex--];
    }

    // Returns top element
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; 
        }
        return stackArray[topIndex];
    }

   /* Returns true if the 
   stack is empty, false otherwise*/
    bool isEmpty() {
        return topIndex == -1;
    }
};

// Main Function
int main() {
    ArrayStack stack;
    vector<string> commands = {"ArrayStack", "push", "push", "top", "pop", "isEmpty"};
    vector<vector<int>> inputs = {{}, {5}, {10}, {}, {}, {}};

    for (size_t i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            stack.push(inputs[i][0]);
            cout << "null ";
        } else if (commands[i] == "pop") {
            cout << stack.pop() << " ";
        } else if (commands[i] == "top") {
            cout << stack.top() << " ";
        } else if (commands[i] == "isEmpty") {
            cout << (stack.isEmpty() ? "true" : "false") << " ";
        } else if (commands[i] == "ArrayStack") {
            cout << "null ";
        }
    }

    return 0;
}

