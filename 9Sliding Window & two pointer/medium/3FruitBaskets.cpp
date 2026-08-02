//Fruit Into Baskets

// Problem Statement: There is only one row of fruit trees on the farm, oriented left to right. An integer array called fruits represents the trees, where fruits[i] denotes the kind of fruit produced by the ith tree.
// The goal is to gather as much fruit as possible, adhering to the owner's stringent rules :

// There are two baskets available, and each basket can only contain one kind of fruit. The quantity of fruit each basket can contain is unlimited.
// Start at any tree, but as you proceed to the right, select exactly one fruit from each tree, including the starting tree. One of the baskets must hold the harvested fruits.
// Once reaching a tree with fruit that cannot fit into any basket, stop.
// Return the maximum number of fruits that can be picked.

// Examples
// Input :fruits = [1, 2, 1]
// Output :3
// Explanation : We will start from first tree.
// The first tree produces the fruit of kind '1' and we will put that in the first basket.
// The second tree produces the fruit of kind '2' and we will put that in the second basket.
// The third tree produces the fruit of kind '1' and we have first basket that is already holding fruit of kind '1'. So we will put it in first basket.
// Hence we were able to collect total of 3 fruits.


// Input : fruits = [1, 2, 3, 2, 2]
// Output : 4
// Explanation : we will start from second tree.
// The first basket contains fruits from second , fourth and fifth.
// The second basket will contain fruit from third tree.
// Hence we collected total of 4 fruits.


//Algorithm
// This brute force method checks each possible subarray starting from every index and determines how many fruits can be collected from there. We are allowed to pick fruits from any starting point and move only to the right, using two baskets. Each basket can only hold fruits of one type. To simulate this naively, we start from every index and collect fruits until we either: Reach the end of the array, or Encounter a third unique fruit type that can't go into the two baskets.
// Initialize a variable to track the maximum number of fruits collected.
// Iterate over all possible starting points of the array.
// Use a HashSet (or a frequency map) to keep track of the fruit types in the current window.
// For each start point, move the end pointer to the right while there are at most 2 fruit types.
// Update the maximum fruits collected based on the window length.
// Return the maximum number after checking all starting points.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate maximum fruits collected  
    // with at most two distinct types from any start point 
    int totalFruit(vector<int>& fruits) {

        // Variable to store the maximum fruits collected
        int maxFruits = 0;

        // Loop over each possible starting point
        for (int start = 0; start < fruits.size(); ++start) {

            // Create a map to store the count of fruit types
            unordered_map<int, int> basket;

            // Initialize current count
            int currentCount = 0;

            // Traverse from current start to the end
            for (int end = start; end < fruits.size(); ++end) {

                // Add current fruit to the basket
                basket[fruits[end]]++;

                // If basket has more than 2 types, break
                if (basket.size() > 2) {
                    break;
                }

                // Increase current fruit count
                currentCount++;
            }

            // Update maximum fruits collected
            maxFruits = max(maxFruits, currentCount);
        }

        // Return the result
        return maxFruits;
    }
};

// Driver code
int main() {
    Solution obj;
    vector<int> fruits = {1, 2, 1};
    cout << obj.totalFruit(fruits) << endl; // Output: 3
    return 0;
}


//better approach 
//Algorithm
// In the brute force approach, we checked every possible starting point and extended the subarray as far as possible while satisfying the necessary condition But this was inefficient because we repeatedly recalculated the same things.

// We can do better by applying the sliding window technique. The idea is to maintain a window that contains at most 2 distinct fruit types, and whenever the condition is violated, shrink the window from the left until it's valid again. We use a hash map to track the count of each fruit in the current window. This allows us to scan the array only once from left to right, and adjust the window dynamically in linear time.
// Initialize two pointers for the window: start and end.
// Use a hash map to store the frequency of each fruit type within the current window.
// Iterate through the array using the end pointer.
// Add the current fruit to the map and update its count.
// If the map size exceeds 2 (more than 2 fruit types in window), shrink the window from the start pointer until the map becomes valid (size ≤ 2).
// At each step, track the maximum length of the valid window.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the maximum number of fruits we can collect with at most two fruit types
    int totalFruit(vector<int>& fruits) {
        // Hash map to store frequency of each fruit in the current window
        unordered_map<int, int> basket;
        
        // Variable to store the maximum length of valid window
        int maxFruits = 0;
        
        // Left pointer of the sliding window
        int left = 0;

        // Traverse the fruits array using right pointer
        for (int right = 0; right < fruits.size(); right++) {
            // Include the current fruit in the basket
            basket[fruits[right]]++;

            // Shrink the window if more than 2 types of fruits exist
            while (basket.size() > 2) {
                // Decrease count of fruit at left pointer
                basket[fruits[left]]--;

                // If count becomes zero, remove it from map
                if (basket[fruits[left]] == 0) {
                    basket.erase(fruits[left]);
                }

                // Move the left pointer to shrink the window
                left++;
            }

            // Update the maximum window length found so far
            maxFruits = max(maxFruits, right - left + 1);
        }

        // Return the maximum fruits we can collect in a valid window
        return maxFruits;
    }
};

// Driver code
int main() {
    Solution obj;
    vector<int> fruits = {1, 2, 1, 2, 3};
    cout << obj.totalFruit(fruits) << endl;
    return 0;
}


//optimal

//Algorithm
// In this optimal approach, instead of storing counts of all fruit types using a map, we keep track of just the last two fruit types seen and their last positions. This allows us to avoid using any auxiliary space like a hash map. The idea is simple: we maintain a sliding window that only contains two types of fruits and expand it as long as the new fruit belongs to either of those two types. If a new third type appears, we shrink the window to start right after the last occurrence of the second last fruit type.
// Initialize two variables to store the two recent fruit types seen and their last positions.
// Traverse the array while expanding the window to include current fruits as long as they match the two types.
// If a third fruit type appears, update the window to start just after the last occurrence of one of the older fruit types.
// Track the maximum length of valid windows throughout the traversal.


//Time Complexity: O(n), where n is the total number of elements in the input array.

// Space Complexity: O(1), constant auxiliary space. Only a fixed number of integer variables are maintained.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the maximum number of fruits we can collect
    // with at most two types of fruits in the baskets.
    int totalFruit(vector<int>& fruits) {
        
        // Variable to store the maximum number of fruits collected
        int maxlen = 0;
        
        // Variables to track the last two fruit types and their counts
        int lastfruit = -1, secondlastfruit = -1;
        
        // Count of current window size and the last fruit streak
        int currcount = 0, lastfruitstreak = 0;

        // Traverse through each fruit in the array
        for (int fruit : fruits) {
            
            // If current fruit is same as last or second last, increase window
            if (fruit == lastfruit || fruit == secondlastfruit) {
                currcount++;
            } else {
                // Reset window size to size of last fruit streak + 1 (current fruit)
                currcount = lastfruitstreak + 1;
            }

            // Update streak count
            if (fruit == lastfruit) {
                lastfruitstreak++;
            } else {
                lastfruitstreak = 1;
                secondlastfruit = lastfruit;
                lastfruit = fruit;
            }

            // Update the maximum length
            maxlen = max(maxlen, currcount);
        }

        return maxlen;
    }
};

// Driver code
int main() {
    Solution sol;
    vector<int> fruits = {1,2,1,2,3};
    cout << sol.totalFruit(fruits) << endl;
    return 0;
}

