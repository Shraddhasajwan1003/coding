//we can either store them in set ( unordered or ordered) or we can check the adjacent ones if they are equal or not if not then i++ otherwise leave it and not store it 
//never sort in this question , already sorted 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int remove_duplicates_by_set(vector<int>& nums) {
        // Use a standard 'set' if you want them sorted automatically
        set<int> st;
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {//TC is O(N)+ O(N)
            st.insert(nums[i]);
        }
        
        // Actually modify the original array with the unique elements
        nums.clear();
        for(auto it : st) {
            nums.push_back(it);
        }
        
        return st.size();
    }
};

int main() {
    Solution obj;
    
    // 1. Ask for the number of elements first
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    vector<int> nums;
    cout << "Enter the elements: ";
    
    // 2. Use a standard loop to take inputs
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    
    int uniqueCount = obj.remove_duplicates_by_set(nums);
    
    cout << "No of unique elements: " << uniqueCount << "\n";
    cout << "The modified array: ";
    for (int i = 0; i < uniqueCount; i++) {
        cout << nums[i] << " ";
    }
    
    return 0;
}
//removing via two pointer approach 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int remove_duplicates_via_2pointer(vector<int> &nums){
        // EDGE CASE FIX: If the array is empty, return 0 immediately, not adding this will return 1 for an empty array
        if (nums.empty()) {
            return 0;
        }
        int n = nums.size();
        int j =0;
        for(int i =1;i<n;i++){
            if(nums[i]!=nums[j]){
                j++;
                nums[j]=nums[i]; 
            }
        }
        return j+1;
    }
};

int main() {
    Solution obj;
    int n;cin>>n;
    vector<int>vec;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        vec.push_back(x);
    }
    cout<<"how many unique elements"<<obj.remove_duplicates_via_2pointer(vec);
    return 0;
}