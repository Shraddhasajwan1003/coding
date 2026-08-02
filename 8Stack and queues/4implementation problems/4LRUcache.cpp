//Program for Least Recently Used (LRU) Page Replacement Algorithm

// Problem Statement: Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

// Implement the LRUCache class:

// LRUCache(int capacity): Initialize the LRU cache with positive size capacity.
// int get(int key): Return the value of the key if the key exists, otherwise return -1.
// void put(int key, int value): Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

// The functions get and put must each run in O(1) average time complexity.

//Examples
// Input: ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
// [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
// Output: [null, null, null, 1, null, -1, null, -1, 3, 4]
// Explanation: 
// LRUCache lRUCache = new LRUCache(2);
// lRUCache.put(1, 1); // cache is {1=1}
// lRUCache.put(2, 2); // cache is {1=1, 2=2}
// lRUCache.get(1);    // return 1
// lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
// lRUCache.get(2);    // returns -1 (not found)
// lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
// lRUCache.get(1);    // return -1 (not found)
// lRUCache.get(3);    // return 3
// lRUCache.get(4);    // return 4
// Input: ["LRUCache","put","get"]
// [[1],[2,1],[2] 
// Output: [null, null, 1]
// Explanation: 
// LRUCache lRUCache = new LRUCache(1);
// lRUCache.put(2, 1); // cache is {2=1}
// lRUCache.get(2);    // return 1



//Algorithm
// The intuition behind an LRU (Least Recently Used) Cache is that we want to store only a fixed number of items in memory and quickly evict the item that hasn’t been used for the longest time. This is useful when memory is limited and we want to keep the most relevant data available for fast retrieval. The key idea is to maintain quick lookups to check if a value exists in the cache, and also maintain the usage order so we can remove the least recently used item efficiently when the cache is full.

// To implement it efficiently, we combine two data structures: a HashMap for O(1) lookup of keys, and a Doubly Linked List to maintain the order of usage. The most recently used items are kept at one end (head), and the least recently used items at the other end (tail). When we access or insert a key, we move it to the head whereas when the cache is full, we remove the tail node. This combination ensures both O(1) access and O(1) insertion/deletion for LRU operations.
// Use a HashMap to store key-value pairs for direct access to elements in the cache.
// Maintain a Doubly Linked List to track the usage order, with the most recently used node at the head and the least recently used at the tail.
// On a get(key) operation, if the key exists, move the corresponding node to the head and return its value, otherwise, return a cache miss value.
// On a put(key, value) operation, if the key exists, update the value and move it to the head. If it does not exist, create a new node, insert it at the head, and store it in the HashMap.
// If the cache exceeds capacity after an insertion, remove the node at the tail and delete its entry from the HashMap.

//Ye code ek LRU (Least Recently Used) Cache bana raha hai. Iska simple matlab ye hai ki memory (cache) ki capacity limited hoti hai. Toh jab cache full ho jaati hai, toh hum uss element ko hata (evict kar) dete hain jo sabse purana ya sabse kam use hua ho.

// 1. Main Concept aur Idea

// Iss algorithm mein do main data structures ka mix-use (combination) hota hai:

// Doubly Linked List (DLL): Elements ke access/usage ka order track karne ke liye.
//     Head ke paas: Sabse recently used (naya/recently accessed) element.
//     Tail ke paas: Sabse least recently used (purana) element.

// HashMap (unordered_map): Direct $O(1)$ time mein kisi key ko dhoondhne ke liye (key -> Node*).


// Dono milkar O(1) time complexity mein get() aur put() operations complete karte hain.

// 2. Class ke Components
// Node Class: Har node ke paas key, val, prev pointer, aur next pointer hota hai.

// Dummy Nodes (head aur tail): Code ko clean rakhne ke liye dummy head aur tail banaye hain taaki boundary cases manage karne mein aasaani ho.

// addNode(newNode): Direct head ke aage node ko add karta hai (matlab Most Recently Used banata hai).

// deleteNode(delNode): Linked list se kisi bhi node ko remove karta hai.

// 3. Main Functions Kaise Kaam Karte Hain?

// A. get(key) FunctionJab hum kisi key ki value maangte hain:

// Key Map mein milli:Uss node ki value nikalo.Node ko purani jagah se deleteNode() karke addNode() ke zariye Head ke paas le aao (kyunki wo ab recently use ho gaya hai).Map update karo aur value return kar do.

// Key nahi milli: Simply -1 return kar do.

// B. put(key, value) FunctionJab hum new key-value pair daalte hain ya existing ko update karte hain:

// Agar Key Pehle Se Exist Karti Hai:Purana node delete karo aur map se erase karo (update karne ke liye).


// Agar Cache Full Hai (m.size() == cap):Tail ke just pehle wala node (tail->prev) sabse least recently used hai.Usse list se deleteNode() karo aur map se erase karke jagah khali karo.

// New Node Insert Karo:Naya node bana ke addNode() se Head ke paas daal do aur map mein store kar lo.

// Summary / Time Complexity

// get(key) Time: O(1)(HashMap search + Linked list updates)

// put(key, value) Time: O(1) (HashMap operations + Linked list insertion/deletion)

// Space Complexity: O(Capacity) (Cache capacity jitne nodes aur map entries)

//the only approach 
#include <bits/stdc++.h>
using namespace std;

// Class representing the LRU Cache
class LRUCache {
public:
    // Doubly linked list node class
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
        // Constructor to initialize node
        Node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };

    // Head and tail dummy nodes
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    // Capacity of cache
    int cap;
    // Hash map to store key-node mapping
    unordered_map<int, Node*> m;

    // Constructor to initialize LRU cache
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    // Function to add a node right after head
    void addNode(Node* newNode) {
        Node* temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    // Function to remove a given node from list
    void deleteNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    // Function to get value from cache
    int get(int key_) {
        // If key exists in cache
        if (m.find(key_) != m.end()) {
            Node* resNode = m[key_];
            int res = resNode->val;
            // Remove old mapping
            m.erase(key_);
            // Move accessed node to front
            deleteNode(resNode);
            addNode(resNode);
            // Update map
            m[key_] = head->next;
            return res;
        }
        // If not found
        return -1;
    }

    // Function to put key-value into cache
    void put(int key_, int value) {
        // If key already exists
        if (m.find(key_) != m.end()) {
            Node* existingNode = m[key_];
            m.erase(key_);
            deleteNode(existingNode);
        }
        // If capacity reached
        if (m.size() == cap) {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        // Insert new node at front
        addNode(new Node(key_, value));
        m[key_] = head->next;
    }
};

// Driver code
int main() {
    // Create cache with capacity 2
    LRUCache cache(2);

    // Put values in cache
    cache.put(1, 1);
    cache.put(2, 2);

    // Get value for key 1
    cout << cache.get(1) << endl; 

    // Insert another key (evicts key 2)
    cache.put(3, 3);

    // Key 2 should be evicted
    cout << cache.get(2) << endl; 

    // Insert another key (evicts key 1)
    cache.put(4, 4);

    // Key 1 should be evicted
    cout << cache.get(1) << endl; 

    // Key 3 should be present
    cout << cache.get(3) << endl; 

    // Key 4 should be present
    cout << cache.get(4) << endl; 

    return 0;
}