// you can left rotate array by using a auxillary array ---->brute force 
//or you can store first element in a temp variable and shift the elements towards left , then arr[n-1]=temp;---->optimal 
//you can use reverse stl function but that is better to use when we are required to rotate by k places

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void left_rotate_1place_byauxillary_array(vector<int>&nums){//brute forec
        int n = nums.size();//size nikala 
        vector<int>tempvec(n);//temporrary vector bnaya 
        tempvec ={0};//vector ko initialise kia by 0
        for(int i =1;i<n;i++){//1 se n-1 index tak nums se temp me daal dia 
            tempvec[i-1]= nums[i];
        }
        tempvec[n-1]=nums[0];//first element of nums ko ek variable me rakh lia 
        for(int i =0;i<n;i++){
            nums[i]=tempvec[i];//ab vapis nums ke upar overlap kraya temp ko , ye loop uneccessary h isliye likha h bcz kabhi-2 question me you are asked to return nums only not a temp vector
        }
        tempvec.clear();//temp ko clear kia 
        for(int i =0;i<n;i++){//nums ko print kia 
            cout<<"Element"<<i+1<<" :"<<nums[i]<<"\n";
        }
    }


    void left_rotate_by1place_without_temparr(vector<int>&nums, int k){
        int n =nums.size();
        int temp = nums[0];
        for(int i =1;i<n;i++){
            nums[i-1]=nums[i];
        }
        nums[n-1]=temp;
        for(int i=0;i<n;i++){
            cout<<nums[i]<<" ";
        }
    }


    void left_rotate_bykplace_byvector(vector<int>&nums, int k){//brute force
        int n = nums.size();
        k =k%n;            //larger rotations ko chota krne ke liye 
        vector<int>tempvec(k);//temp vector
        tempvec ={0};
        for(int i =0;i<k;i++){   // is baar 0 se k tak chalana h loop for nums 
            tempvec[i]= nums[i];
        }
        tempvec[n-1]=nums[0];
        for(int i =k;i<n;i++){//k se lekar last tk hum nums me aage shift krdenge 
            nums[i-k]=nums[i];
        }
        for (int i =0;i<k;i++){//ab jo humne temp bnaya tha usse hum elements ko k se last tak lga denge in nums
            arr[n-k+1]=tempvec[i];
        }
    }
    // Function to rotate the array to the right by k positions
    void rotateRight_withoutreversefunc_tempsizek(vector<int>&arr,int k){
        int n =arr.size();
        if (n == 0) return;

        // Normalize k if greater than n
        k = k % n;

        // Store last k elements in a temporary array
        vector<int> temp[k];
        for (int i = n - k; i < n; i++) {
            temp[i - n + k] = arr[i];
        }

        // Shift the first n-k elements to the right by k steps
        for (int i = n - k - 1; i >= 0; i--) {
            arr[i + k] = arr[i];
        }

        // Copy back the k elements to the start
        for (int i = 0; i < k; i++) {
            arr[i] = temp[i];
        }
    }
    void reversearray(vector<int>&nums, int i, int j  ){
    
        while(i<j){
            // swap(nums[i],nums[j]);
            int temp = nums[i];//swap without swap function
            nums[i]=nums[j];
            nums[j]=temp;
            i++;//start index 
            j--;//end index
        }
    }
    void leftrotate_kplace_withoutspace(vector<int>&nums, int k ){//TC is O(3N) ~ O(N)
        int n =nums.size();
        k=k%n;
        reverse(nums, nums+k);
        reverse(nums+k,nums+n);
        reverse(nums,nums+n);
        for(int i =0;i<n;i++){
            cout<<nums[i]<<" ";
        }
    }


    void rightrotate_bykplace(vector<int>&nums,int k ){//TC is O(3N) ~ O(N)
        int n =nums.size();
        k=k%n;
        reverse(nums,nums+n);
        reverse(nums, nums+k);
        reverse(nums+k,nums+n);
        for(int i =0;i<n;i++){
            cout<<nums[i]<<" ";
        }

    }
};

int main() {
    Solution obj;
    vector<int>nums;
    int n ;cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    obj.left_rotate_1place_byauxillary_array(nums);
    return 0;
}
