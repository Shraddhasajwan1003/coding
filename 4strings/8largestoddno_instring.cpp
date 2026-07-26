// explaination :we move from back , check for first odd , store its index(idx =i) in var, then we also check if any zero are present at last(means first index ) if yess then we do i++ , then return the substr(i,idx-i+1)  
//TC is O(N), SC is O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largest_odd_no_in_string(string &s)
    {
        int idx = -1; // index taken
        int i;
        for (int i = s.length() - 1; i >= 0; i--)
        { // loop to check from backwards that if any number exists at last and nearest to check for largest string
            if ((s[i] - '0') % 2 == 1)//check if it is odd or not 
            {
                idx = i;//if found odd then store its index for finding substr
                break;//loop from backwards stopped , bcz odd is found , we only need the nearest odd to find the largest one, as we cannot rearrange the string 
            }
        }

        i = 0;
        while (i <= idx && s[i] == '0')//idx must be smaller than i bcz other wise no odd is there
            i++; // skip the zeroes jab tak odd digit hai

        return s.substr(i, idx - i + 1);
    }
};

int main()
{
    Solution obj;
    string str="3456278";
    cout<<obj.largest_odd_no_in_string(str);
    return 0;
}