// Problem Statement: You are given a stack of integers. Your task is to sort the stack in descending order using recursion, such that the top of the stack contains the greatest element. You are not allowed to use any loop-based sorting methods (e.g., quicksort, mergesort). You may only use recursive operations and the standard stack operations (push, pop, peek/top, and isEmpty)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //     Time Complexity: O(n^2), where n is the number of elements in the stack.

    // Space Complexity: O(n), due to the recursion stack.
    void insertInStack(stack<int>& s, int temp)
    {
        // temp is used for comparing and sorting
        //  if stack is empty and temp is greater than top
        if (s.empty() || s.top() <= temp)
        {
            s.push(temp); // push krdo temp ko
            return;
        }

        // agr upar wali condition nhi h to pop the top element and recursively insert
        int val = s.top();
        s.pop();
        insertInStack(s, temp);

        s.push(val); // nikale hue ko dobara dalo do stack me
    }
    void sortstack(stack<int> &st)
    {
        if (!st.empty())
        {
            int temp = st.top();
            st.pop();
            sortstack(st);
            insertInStack(st, temp);
        }
    }
};

int main()
{
    Solution obj;
    stack<int> s;
    s.push(4);
    s.push(1);
    s.push(3);
    s.push(2);

    obj.sortstack(s);

    // Print the sorted stack
    cout << "Sorted stack (descending order): ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
    return 0;
}