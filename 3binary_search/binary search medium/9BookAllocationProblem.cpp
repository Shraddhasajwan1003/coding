//Problem Statement: Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages in the ‘i-th’ book. There are a ‘m’ number of students, and the task is to allocate all the books to the students.
// Allocate books in such a way that:

// Each student gets at least one book.
// Each book should be allocated to only one student.
// Book allocation should be in a contiguous manner.
// You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum. If the allocation of books is not possible. return -1
 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //this  is the classic function to find minimum remember it 
    // Function to count the minimum number of students required
    // if each student can read at most 'pages' pages.
    int countStudents(vector<int> &arr, int pages) {
        // Initially assign books to the first student.
        int students = 1;

        // Stores pages allocated to the current student.
        int pagesStudent = 0;

        // Traverse all books.
        for (int book : arr) {

            // If the current book can be assigned to the current student.
            if (pagesStudent + book <= pages) {
                pagesStudent += book;
            }

            // Otherwise, assign the book to the next student.
            else {
                students++;
                pagesStudent = book;
            }
        }

        // Return the number of students required.
        return students;
    } 
// m is no of students , n is size of array, that is no of total books 
     // Function to find the minimum possible maximum pages.
    int findPages(vector<int> &arr, int n, int m) {

        // If students are more than books, allocation is impossible.
        if (m > n) return -1;

        // Minimum possible answer is the largest book.
        int low = *max_element(arr.begin(), arr.end());

        // Maximum possible answer is the sum of all pages.
        int high = accumulate(arr.begin(), arr.end(), 0);

        // Check every possible answer from low to high.
        for (int pages = low; pages <= high; pages++) {

            // If exactly m students are required, return the answer.
            if (countStudents(arr, pages) == m)
                return pages;
        }

        // Fallback (should never occur for valid inputs).
        return -1;
    }


    //binary search part 
    int findPages_optimal(vector<int> &nums, int n, int m) {
        if(m>n)return -1;
        int low= *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0);

        while(low<=high){
            int mid=low+(high-low)/2;
            int student=countStudents(nums,mid);
            if(student>m){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;//we need smaller element so go for lowest one 
    }
};

int main() {
    Solution obj;
    vector<int>arr={25, 46, 28, 49, 24};
    int n =5;
    int m =4;
    cout<<obj.findPages_optimal(arr,n,m);
    return 0;
}