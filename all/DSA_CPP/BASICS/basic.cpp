// int/int =int , float /int = float , double/int = double, double/float = double, int/float = float, float/double = double
//precision of float is 6 digits after decimal and double is 15 digits after decimal
//precedence of operators : 1. () 2. * / % 3. + - 4. =
//typecasting : converting one data type to another data type
//implicit typecasting : done by compiler
//explicit typecasting : done by programmer
//relational operators : > < >= <= == !=
//logical operators : && || !
//bitwise operators : & | ^ ~ << >>
//range of int : -2^31 to 2^31-1
//range of float : 1.2E-38 to 3.4E+38
//range of double : 2.2E-308 to 1.8E+308
//size of int : 4 bytes
//size of float : 4 bytes   
//size of double : 8 bytes
//negative numbers are stored in 2's complement form
//signed int : -2^31 to 2^31-1
//unsigned int : 0 to 2^32-1
//overflow : when a value exceeds the maximum limit of a data type
//underflow : when a value is less than the minimum limit of a data type
//modulo operator : % , gives the remainder of a division operation
//increment operator : ++ , increases the value of a variable by 1  
//decrement operator : -- , decreases the value of a variable by 1
//ternary operator : ? : , a shorthand for if-else statement
//bitwise operators : & | ^ ~ << >> , used for manipulating bits of a number
//namespace : a declarative region that provides a scope to the identifiers inside it
//std : standard namespace that contains all the standard library functions and objects
//using namespace std : allows us to use the standard library functions and objects without prefixing them with std::
//preprocessor directives : #include , #define , #ifdef , #ifndef , #endif , used for including header files and defining macros
//header files : <iostream> , <bits/stdc++.h> , used for including standard library functions and objects
//main function : the entry point of a C++ program
//return type of main function : int
//cout : used for output
//cin : used for input
//endl : used for new line
//comments : // for single line comments and /* */ for multi line comments
//escape sequences : \n for new line, \t for tab, \\ for backslash, \" for double quote, \' for single quote
//data types : int , float , double , char , bool , void
//variables : a named memory location that stores a value of a specific data type
//constants : a value that cannot be changed during the execution of a program
//operators : symbols that perform operations on operands
//expressions : a combination of variables, constants and operators that evaluates to a value
//statements : a line of code that performs a specific task
//blocks : a group of statements enclosed in curly braces {}
//functions : a block of code that performs a specific task and can be called from other parts  of the program
//parameters : variables that are passed to a function when it is called 
//arguments : values that are passed to a function when it is called
//return type : the data type of the value that a function returns
//void type function : a function that does not return a value
//return type function : a function that returns a value of a specific data type
//function overloading : having multiple functions with the same name but different parameters
//default arguments : arguments that have a default value if not provided by the caller
//recursion : a function that calls itself
//base case : the condition under which a recursive function stops calling itself
//recursive case : the condition under which a recursive function continues to call itself
//iterative approach : using loops to solve a problem instead of recursion
//time complexity : the amount of time taken by an algorithm to run as a function of the input size
//space complexity : the amount of memory used by an algorithm to run as a function of the input size
//big O notation : a mathematical notation used to describe the upper bound of an algorithm's time or space complexity
//asymptotic analysis : the analysis of an algorithm's time or space complexity as the input size approaches infinity
//best case : the scenario in which an algorithm performs the minimum number of operations
//worst case : the scenario in which an algorithm performs the maximum number of operations
//average case : the scenario in which an algorithm performs the average number of operations
//linear search : a search algorithm that checks each element of a list until the desired element is found or the list is exhausted
//binary search : a search algorithm that repeatedly divides a sorted list in half until the desired element is found or the list is exhausted
//selection sort : a sorting algorithm that repeatedly selects the minimum element from the unsorted portion of the list and moves it to the sorted portion of the list
//bubble sort : a sorting algorithm that repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order until the list is sorted
//insertion sort : a sorting algorithm that builds the sorted list one element at a time by repeatedly taking the next element from the unsorted portion of the list and inserting it into the correct position in the sorted portion of the list
//merge sort : a sorting algorithm that divides the list into two halves, sorts each half recursively and then merges the sorted halves back together
//quick sort : a sorting algorithm that selects a pivot element from the list, partitions the other elements into two sublists according to whether they are less than or greater than the pivot, and then recursively sorts the sublists
//heap sort : a sorting algorithm that builds a binary heap from the list, and then repeatedly extracts the maximum element from the heap and rebuilds the heap until it is empty
//counting sort : a sorting algorithm that counts the number of occurrences of each distinct element in the list, and then uses this information to place each element in its correct position in the sorted list
//radix sort : a sorting algorithm that sorts the list by processing individual digits of the numbers from least significant to most significant 
//graph : a data structure that consists of a set of vertices and a set of edges that connect the vertices
//tree : a data structure that consists of a set of nodes connected by edges, where each node has at most one parent and zero or more children
//binary tree : a tree data structure in which each node has at most two children       
//binary search tree : a binary tree in which each node has a value greater than the values of its left subtree and less than the values of its right subtree
//heap : a binary tree that satisfies the heap property, where each parent node is greater than or equal to its children (max heap) or less than or equal to its children (min heap)
//stack : a data structure that follows the Last In First Out (LIFO) principle, where the last element added to the stack is the first one to be removed
//queue : a data structure that follows the First In First Out (FIFO) principle, where the first element added to the queue is the first one to be removed
//deque : a data structure that allows insertion and deletion at both ends  
//linked list : a data structure that consists of a sequence of nodes, where each node contains a value and a pointer to the next node in the sequence
//doubly linked list : a linked list in which each node contains a pointer to both the next and the previous node in the sequence
//circular linked list : a linked list in which the last node points back to the first node in the sequence
//hash table : a data structure that maps keys to values using a hash function to compute an index into an array of buckets or slots, from which the desired value can be found
//stack overflow : when a program tries to use more stack memory than is available 
//heap overflow : when a program tries to use more heap memory than is available
//memory leak : when a program allocates memory but does not deallocate it, leading to a gradual increase in memory usage over time
//pointer : a variable that stores the memory address of another variable   
//reference variable : an alias for another variable, created using the & operator
//dynamic memory allocation : allocating memory at runtime using the new operator and deallocating it using the delete operator
//smart pointers : a class template that provides automatic memory management for dynamically allocated objects, such as    std::unique_ptr, std::shared_ptr and std::weak_ptr
//exception handling : a mechanism for handling runtime errors in a controlled manner using try, catch and throw keywords
//file handling : a mechanism for reading and writing data to files using fstream library   
//input/output manipulators : functions that can be used to manipulate the input and output streams, such as setw, setprecision, fixed, scientific, etc.
#include <bits/stdc++.h>
using namespace std;
int main(){
    int a=10;
    float b=3.14;
    double c=3.14;
    cout<<a/b<<endl; // 3.18471