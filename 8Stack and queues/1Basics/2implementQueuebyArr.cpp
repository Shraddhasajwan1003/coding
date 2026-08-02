//Declare an Array of a Particular Size: Declare an array to store the elements of the queue. The size of this array is determined when the queue is initialized.
// Define Variables:
// start: Tracks the index of the front element.
// end: Tracks the index of the last element.
// size: Keeps the current number of elements in the queue.
// capacity: The maximum number of elements the queue can hold.
// Push Operation (push(int x)):
// Check if the queue is full by comparing size with capacity. If not full:
// Increment the end using modular arithmetic to wrap around if necessary.
// Insert the element at the rear index.
// Increment the size.
// Pop Operation (pop()):
// Check if the queue is empty by comparing size with 0. If not empty:
// Return the element at the front index.
// Increment the start using modular arithmetic to wrap around if necessary.
// Decrement the size.
// Peek Operation (peek()):
// Check if the queue is empty. If not empty, return the element at the front index.
// IsEmpty Operation (isEmpty()):
// Check if size is 0 to determine if the queue is empty.

#include <bits/stdc++.h>
using namespace std;

// Class implementing Queue using Arrays
class ArrayQueue {
    // Array to store queue elements
    int* arr;
    // Indices for start and end of the queue
    int start, end;
    // Current size and maximum size of the queue
    int currSize, maxSize;

public:
    // Constructor
    ArrayQueue() {
        arr = new int[10];
        start = -1;
        end = -1;
        currSize = 0;
        maxSize = 10;
    }

    // Method to push an element into the queue
    void push(int x) {
        // Check if the queue is full
        if (currSize == maxSize) {
            cout << "Queue is full\nExiting..." << endl;
            exit(1);
        }
        
        // If the queue is empty, initialize start and end
        if (end == -1) {
            start = 0;
            end = 0;
        } 
        else {
            // Circular increment of end
            end = (end + 1) % maxSize;
        }
            
        arr[end] = x;
        currSize++;
    }

    // Method to pop an element from the queue
    int pop() {
        // Check if the queue is empty
        if (start == -1) {
            cout << "Queue Empty\nExiting..." << endl;
            exit(1);
        }
        int popped = arr[start];
        
        // If the queue has only one element, reset start and end
        if (currSize == 1) {
            start = -1;
            end = -1;
        }
        else {
            // Circular increment of start
            start = (start + 1) % maxSize;
        }
        
        currSize--;
        return popped;
    }

    // Method to get the front element of the queue
    int peek() {
        // Check if the queue is empty
        if (start == -1) {
            cout << "Queue is Empty" << endl;
            exit(1);
        }
        return arr[start];
    }

    // Method to determine whether the queue is empty
    bool isEmpty() {
        return (currSize == 0);
    }
};

int main() {
    ArrayQueue queue;
    vector<string> commands = {"ArrayQueue", "push", "push", 
                               "peek", "pop", "isEmpty"};
    vector<vector<int>> inputs = {{}, {5}, {10}, {}, {}, {}};

    for (int i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            queue.push(inputs[i][0]);
            cout << "null ";
        } else if (commands[i] == "pop") {
            cout << queue.pop() << " ";
        } else if (commands[i] == "peek") {
            cout << queue.peek() << " ";
        } else if (commands[i] == "isEmpty") {
            cout << (queue.isEmpty() ? "true" : "false") << " ";
        } else if (commands[i] == "ArrayQueue") {
            cout << "null ";
        }
    }

    return 0;
}