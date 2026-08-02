//1. Question Explanation (Problem Statement)
// Aapko integers ka ek array diya gaya hai jo Asteroids ko represent karta hai:

// Absolute value (Magnitude): Asteroid ka size batati hai.

// Sign (+ ya -): Asteroid ki direction batati hai:
// Positive (+): Right direction ---> 
// Negative (-): Left direction <---

// Rules for Collisions:

// Sabhi asteroids same speed se move karte hain.

// Collision tabhi ho sakta hai jab ek Right-moving (+) asteroid aur ek Left-moving (-) asteroid aamne-saamne aate hain.

// Jab 2 asteroids collide hote hain:Smaller size waala asteroid destroy/explode ho jaata hai.Agar dono ka size equal hai, toh dono explode ho jaate hain.


// Same direction waale ya opposite direction mein door jaane waale (- left side mein, + right side mein) asteroids kabhi nahi takraayenge.


// 2. Pattern Intuition


// Key Insight:

// Socho jab aap array ko left to right traverse kar rahe ho:Jo asteroids right (+) ja rahe hain, woh queue/line mein wait karte hain.

// Jaise hi ek left-moving (-) asteroid aata hai, woh apne se theek pehle waale right-moving (+) asteroid se pehle collide karega.


// Agar woh usse jeet gaya (size bada hua), toh woh usse pichhle waale right-moving asteroid se takraayega.

// Notice karo ki yahan LIFO (Last-In, First-Out) order follow ho raha hai! Jo right-moving asteroid sabse last mein add hua tha, sabse pehle collision wahi jhelta hai.


// 👉 Pattern Identified: Stack Data Structure



// 3. Brute Force vs. Optimal Approach

// Is problem ke liye Simulation via Array/Vector Mutation Brute Force ho sakta hai, lekin Stack hi iska sabse natural aur optimal solution hai.

// 🟢 Optimal Solution: 

// Using Stack / VectorIntuition & Algorithm:Ek Stack (ya C++ vector, Java ArrayList) maintain karo jo surviving asteroids ko store karega.


// Array ke har asteroid ko iterate karo:
// Case 1: Positive (+) AsteroidIsse seedha stack mein push kar do kyunki yeh right move kar raha hai aur collision future mein aane waale negative elements se hi ho sakta hai.

// Case 2: Negative (-) AsteroidYeh left ja raha hai, toh jab tak stack ke top par positive (+) asteroid hai aur uska size is current negative asteroid se chhota hai, tab tak stack ke top element ko pop (destroy) karte raho.


// Agar stack ke top par same size ka positive asteroid milta hai, toh dono destroy honge (stack se pop karo aur current asteroid ko push mat karo).

// Agar stack empty ho jaye ya top par koi negative (-) asteroid aa jaye, toh is current negative asteroid ko bhi stack mein push kar do (kyunki yeh survive kar gaya).



//Time Complexity: O(N), since traversing all the asteroids takes O(N) time.

// Space Complexity: O(N), since in the worst case, all asteroids will be stored in the stack if there are no collisions, leading to a space requirement of O(N).

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    /* Function to determine the state of 
    asteroids after all collisions */
    vector<int> asteroidCollision(vector<int> &asteroids){
        
        // Size of the array
        int n = asteroids.size();
        
        // List implementation of stack
        vector<int> st;  
        
        // Traverse all the asteroids
        for(int i=0; i < n; i++) {
            
            /* Push the asteroid in stack if a 
            right moving asteroid is seen */
            if(asteroids[i] > 0) {
                st.push_back(asteroids[i]);
            }
            
            /* Else if the asteroid is moving 
            right, perform the collisions */
            else {
                
                /* Until the right moving asteroids are 
                smaller in size, keep on destroying them */ 
                while(!st.empty() && st.back() > 0 && 
                      st.back() < abs(asteroids[i])) {
                    
                    // Destroy the asteroid
                    st.pop_back();
                }
                
                /* If there is right moving asteroid 
                which is of same size */
                if(!st.empty() && 
                    st.back() == abs(asteroids[i])) {
                    
                    // Destroy both the asteroids
                    st.pop_back();
                }
                
                /* Otherwise, if there is no left
                moving asteroid, the right moving 
                asteroid will not be destroyed */
                else if(st.empty() ||
                        st.back() < 0){
                    
                    // Storing the array in final state
                    st.push_back(asteroids[i]);
                }
            }
        }
        
        // Return the final state of asteroids
        return st;
    }
};

int main() {
    vector<int> arr = {10, 20, -10};
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to determine the state of 
    asteroids after all collisions */
    vector<int> ans = sol.asteroidCollision(arr);
    
    cout << "The state of asteroids after collisions is: ";
    for(int i=0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}


