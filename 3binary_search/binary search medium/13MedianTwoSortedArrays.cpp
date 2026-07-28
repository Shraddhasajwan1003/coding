//nhi aya smjh bhai dubara padhlio plsssss
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Create a merged vector to store sorted elements
        vector<int> merged;
        
        // Initialize two pointers
        int i = 0, j = 0;
        
        // Merge both arrays in sorted order
        while (i < nums1.size() && j < nums2.size()) {
            // Push the smaller element into merged
            if (nums1[i] < nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            } else {
                merged.push_back(nums2[j]);
                j++;
            }
        }
        
        // Add remaining elements from nums1
        while (i < nums1.size()) {
            merged.push_back(nums1[i]);
            i++;
        }

        // Add remaining elements from nums2
        while (j < nums2.size()) {
            merged.push_back(nums2[j]);
            j++;
        }

        // Find median based on size
        int n = merged.size();
        if (n % 2 == 1)
            return merged[n / 2];
        else
            return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
    }
    //we realised that we dont need whole array to get sorted its better we just use a varaible named idx to look after the median keeping the two pointer logic same as only extra space was the issue 
    // Function to find the median of two sorted arrays
double median(vector<int>& a, vector<int>& b) {

    // Get sizes of both arrays
    int n1 = a.size(), n2 = b.size();

    // Calculate total size
    int n = n1 + n2;

    // Calculate the middle indices
    int ind2 = n / 2;
    int ind1 = ind2 - 1;

    // Initialize pointers and counters
    int cnt = 0, i = 0, j = 0;
    int ind1el = -1, ind2el = -1;

    // Traverse both arrays like merge step of merge sort
    while (i < n1 && j < n2) {

        // Check which element is smaller and pick it
        if (a[i] < b[j]) {
            if (cnt == ind1) ind1el = a[i];
            if (cnt == ind2) ind2el = a[i];
            i++;
        } else {
            if (cnt == ind1) ind1el = b[j];
            if (cnt == ind2) ind2el = b[j];
            j++;
        }
        cnt++;
    }

    // Copy remaining elements from first array if any
    while (i < n1) {
        if (cnt == ind1) ind1el = a[i];
        if (cnt == ind2) ind2el = a[i];
        cnt++;
        i++;
    }

    // Copy remaining elements from second array if any
    while (j < n2) {
        if (cnt == ind1) ind1el = b[j];
        if (cnt == ind2) ind2el = b[j];
        cnt++;
        j++;
    }

    // Return median depending on even or odd size
    if (n % 2 == 1) return (double)ind2el;
    return (ind1el + ind2el) / 2.0;
}


    //using binarry search 
    //To find the median of two sorted arrays efficiently, we use binary search on the smaller array to minimize time complexity. The key idea is to partition both arrays such that the left half contains the smaller elements and the right half contains the larger elements. This way, the median lies at the boundary between the two halves.
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        // Ensure a is the smaller array to minimize binary search scope
        if (a.size() > b.size()) return findMedianSortedArrays(b, a);

        int n1 = a.size(), n2 = b.size();
        int low = 0, high = n1;

        // Binary search on the smaller array
        while (low <= high) {
            // Calculate the cut positions for both arrays
            int cut1 = (low + high) / 2;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            // Handle boundary elements using INT_MIN and INT_MAX
            int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
            int r1 = (cut1 == n1) ? INT_MAX : a[cut1];
            int r2 = (cut2 == n2) ? INT_MAX : b[cut2];

            // If correct partition is found
            if (l1 <= r2 && l2 <= r1) {
                // Total even => average of max left and min right
                if ((n1 + n2) % 2 == 0)
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                else
                    // Total odd => max of left half
                    return max(l1, l2);
            }
            else if (l1 > r2) {
                // Shift left in a
                high = cut1 - 1;
            }
            else {
                // Shift right in a
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};

int main() {
    Solution obj;

    return 0;
}