#include <bits/stdc++.h>
using namespace std;

// linked list is store din non contiguous memory location
// uses heap memory , size can be incresed at any moment
// has a node which conatins data and address to the next index
// starting point of LL is head ,
// node has addres to next so a link is created , if node is the last one then memory address it has is nullptr ---> tail of the LL
// used in stack and queues , stack has no fixed size thats why linked list is used
// irl LL is used in websites pages
// we talked about 1D LL right now as it has pointer only in forward diretion
// we need to know about struct and built in data structure ,data type for LL is self-defined  in Cpp

// self defined data type
struct Node
{
public:
    int data;
    Node *next; // memory location of next

public:
    // for these values you need a constructor , here it is public
    //it is nothing but a special type of member function to initialise the objects of the class (self defined objects)
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    //sometimes we see multiple constructors bcz it reduces the need of passing nullptr again n again while initilising the variable Node* y = new Node(arr[0]);
public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }

};

int main()
{
    vector<int> arr = {2, 3, 5, 6, 7};

    // now how initilise values ??
    // similar to int x we can write Node x = Node(2,nullptr) we created a variable of your self defined data type Node
    // we can also create pointer Node* y = &x;

    // so complete initialisation will be
    // Node x = Node(2,nullptr)
    // Node* y = &x;
    // to shorten 2 steps we can write
    // Node* y = new Node (2,nullptr);

    // below Node *y is a pointer and Node y is object
    //  Node *y = new Node(arr[0],nullptr);//"new" keyword gives pointer to the memory loaction to print value by using pointer we need to write cout<<y->next or cout<<y->data
    //  cout<<y;
    Node y = Node(arr[0], nullptr); // object that contains something not a pointer, but for this we need cout<<y.next , cout<<y.data ,to print the data or the next value to it
    cout << y.data << endl;
    cout << y.next;

    return 0;
}

//struct doesnt provide you with OOPS facility , so you can use class keyword also in place of struct

//memory space taken by LL
//memory taken by int is 4 bytes and by pointer it is 8 bytes so total of 12 bytes is taken in a 64bit system


//array to LL
//first make head 

 
#include <bits/stdc++.h> 

Node* converttoLL(vectro<int>arr){
    Node* head= new Node(arr[0]);
    Node* mover=head;
    for(int i =0;i<arr.size();i++){
        Node* temp= new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
int main(){
    vector<int>arr={1,2,3,4,5,8};
    Node*head
}


//Classes in C++:
// As an object-oriented programming language, C++ introduces the fundamental concept of classes, paving the way for features like encapsulation, polymorphism, abstraction, and inheritance.
//A class is a self-defined data type that contains data members and member functions. Data members are the data variables and member functions are the functions used to manipulate these variables. An object, in turn, is an instance of a class, with its behavior defined by the combination of data variables and member functions within the class.
//A class can be defined using the keyword ‘class’ followed by the name of the class. The body of the class is defined inside the curly brackets and closed by a semicolon at the end.
//There are mainly three types of access modifiers: public and private.


// Public: It can accessed in any class of our code.

// Private: It can be accessed only within the class in which it is defined.  

// Protected: It is the same as private, with the only difference being that it can be accessed in any subclass of that class.

//Data Members contain the data variables and can be accessed by the object depending on the access modifier. 

//Member Functions are the different ways to access the data variables. We can define member functions in two ways:
// Inside Class: When it is used within the class in which it is defined.


// Outside Class: When it is used outside the class in which it is defined. One important point to note is that we must use scope resolution:: operator for outside class member functions.
class Solution{
   public:  //access modifier
   int name;  //data members
   int id;  //data members
   void print_function(){
        cout<<name<<" "<<id<<'\n';
    }// member function
};
int main(){
    Solution object; //object
    object.name=1; //accessing data member
    object.id=2; //accessing data member
    object.print_function(); //accessing member function
}

//inside and outside class
class Solution{
   public:  
   int name;  
   int id;
   void outside_class();  //Called Outside class
   void inline_class(){
        cout<<name<<" "<<id<<'\n';  //Print the name 
    }
};
void Solution::outside_class(){  //Solution through outside_class
    cout<<name<<" "<<id<<'\n';
}
int main(){
    Solution object;  //Creating object
    object.name=1;
    object.id=2;
    object.outside_class();
    object.inline_class();
}


//here are two types of special member functions:

// Constructors: These are called by the compiler every time an object of the class is used. There are three types of Constructors: Default Constructor, Parameterized Constructor, and Self Constructor.

//Destructors: It is the opposite of the constructor, called by the compiler after the object's scope ends

//code :1 

class Solution{
    public:
    int name;
    int id;
    Solution(){
        cout<<"Default Constructor"<<'\n';  //Id=0 for default constructor
        id=0;
    }
    Solution(int temp){
        cout<<"Paramterized Constructor"<<'\n';  //Id=temp for Paramterized constructor
        id=temp;
    }
};
int main(){
    Solution first;
    cout<<"num"<<" "<<first.num<<'\n'; //Pirnt the values of first.num
    Solution second(1);
    cout<<"num"<<" "<<second.num<<'\n';  //Print the values of second.num
    return 0;
}

//code 2:

class Solution{
    public:
    Solution(){
        cout<<"Constructor"<<'\n';  //Constructor called
    }
    ~Solution(){
        cout<<"Destructor"<<'\n';  //Destructor called
    }
};
int main(){
    Solution object1;
    Solution object2;
    Solution object3;
}


//Structures in C++
// Structures and classes in C++ differ because classes offer features like inheritance and polymorphism, while structures do not. Structures are used to group several different data types into one type. It also contains data members and member functions just like class and is declared using the keyword ‘struct’.
//An important point to note is that structs are public by default, whereas in the case of a class, objects of a class are private by default. It can be seen with this example that when we try to access using class, it gives a compilation error because it is declared private by default and private members are not accessible outside their domain.

struct Solution{
    int num;
    string name;
};
int main(){
    Solution structure;  //Make object for class
    structure.num=1;
    structure.name="Saksham";
    cout<<structure.num<<" "<<structure.name<<'\n'; //Print the name
}

//eg of class being private by default
class Solution{
    int num;
};
int main(){
    Solution object;
    object.num=1;
    cout<<object.num<<'\n';  
}
//eg of struct being public by default
// When done the same with structures, we do not get a compilation error because it is declared public by default and can be accessed anywhere in the code.

class Solution{
    int num;
};
int main(){
    Solution object;
    object.num=1;
    cout<<object.num<<'\n';  
}


//Let us enumerate all the details between classes and structures to understand them:

// Member functions and data types: Both can store data and perform functions and operations on the data stored.
// Encapsulation: Both can hide or show the data and functions depending on the situation.
// Polymorphism, Inheritance, and Abstraction: are fundamental concepts developed for object-oriented programming that are not supported by structures but are with classes.
// Access Modifier: Even though default structures are defined as public and classes are defined as private, choosing an access specifier according to your need can change the default parameters.
// Constructor and Destructor: Both can use these types of member functions. An example of a constructor and destructor in the case of structures is given below.


struct Solution{
    Solution(){
        cout<<"Constructor"<<'\n';  //Constructor called
    }
    ~Solution(){
        cout<<"Destructor"<<'\n';  //Destructor called
    }
};
int main(){
   Solution structure1;
   Solution structure2;
}

//difference between struct and class
//Structures 	
// The concepts of OOPs cannot be used	
// The keyword ‘struct’ is used to declare a structure	
// Members of structures are public by default
// It is stored in stack memory	
// NULL values are not possible in structures	

//Classes
//The concepts of OOPs can be used
//The keyword ‘class’ is used to declare a class
//Members of the class are private by default
//It is stored in heap memory
//NULL values are possible in class

//create a LL
#include <bits/stdc++.h>
using namespace std;

// Node class represents a node in the linked list
class Node {
public:
    int data;     // Data value
    Node* next;   // Pointer to next node

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

int main() {
    // Create an array
    vector<int> arr = {2, 5, 8, 7};

    // Create first node
    Node* y = new Node(arr[0]);

    // Print memory location of node
    cout << y << '\n';

    // Print data stored in node
    cout << y->data << '\n';

    return 0;
}
// Let's break this example to understand how it works:

// The class has two data types: data which contains the value of the node and a pointer next, which points to the next node in the list.
// There is a constructor which assigns the values to a new node.
// A new keyword is used to dynamically allocate memory to a node with data as arr[0].


//What are pointerrs 
//A pointer is a variable that stores the memory address of another variable. In simpler terms, it "points" to the location in memory where data is stored. This allows you to indirectly access and manipulate data by referring to its memory address.

// Java does not explicitly use pointers or take the address of variables as you do in C++. Instead, we have reference variables. These reference variables do not directly contain memory addresses like pointers in languages such as C or C++. Instead, they hold references to objects in memory.

// Understanding the difference between Node and Node*: A node refers to the structure that contains data and the pointer to the next node. In contrast, Node* (Node pointer) specifically denotes a pointer variable that stores the address of the Node it is pointing to.


//Let’s talk about assuming the data stored is integer. Another main difference between an array and a linked list is the memory used. In the case of an array, we are storing integers that consume 4 Bytes for every int, whereas in a linked list, we are storing data and a pointer at every node, so the memory used up will depend on the configuration of the system.

// 32 Bit System	                   |   64 Bit System
// Int - 4 Bytes	                   |   Int - 4 Bytes
// Pointer - 4 Bytes	               |   Pointer - 8 Bytes
// Overall - 8 Bytes	               |   Overall - 12 Bytes

// Therefore, in the case of a 64 Bit system, it occupies or consumes more space than a 32 Bit system.

//Applications of Linked Lists:
// Creating Data Structures: Linked lists serve as the foundation for building other dynamic data structures, such as stacks and queues.

// Dynamic Memory Allocation: Dynamic memory allocation relies on linked lists to manage and allocate memory blocks efficiently.

// Web Browser is one important application of Linked List.

//Types of Linked Lists:
// Singly Linked Lists: In a singly linked list, each node points to the next node in the sequence. Traversal is straightforward but limited to moving in one direction, from the head to the tail.


//Doubly Linked Lists: In this each node points to both the next node and the previous node, thus allowing it for bidirectional connectivity.
//Circular Linked Lists: In a circular linked list, the last node points back to the head node, forming a closed loop.

