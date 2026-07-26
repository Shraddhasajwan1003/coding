
// reverse words in a string ---> "   welcome to the library   " ----->"library the to wlecome"
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string bruteforce(string s)//TC is O(N), SC is O(N)
    {
        string word = "";     // taken to store one single word
        vector<string> words; // for storing final words
        for (int i = 0; i < s.size(); i++)
        { // traversing the string
            if (s[i] != ' ')
            {                 // not including spaces
                word += s[i]; // only adding char to word
            }
            else if (!word.empty())
            {                          // if we encounter a space thateither  means one word has ended or it was trailing space , if word isnt empty than we have a new word starting after space , or simply means a word has ended
                words.push_back(word); // we will push that word into words vector<string>
                word = "";             // making word empty again to store a new word
            }
        }
        if (!word.empty())
        { // and if any word isnt pushed because the string ended without space at last ,so we need this check
            words.push_back(word);
        }
        reverse(words.begin(), words.end()); // reversing the words
        string result = "";                  // final result that has reversed words
        for (int i = 0; i < words.size(); i++)
        {                       // making all the words as one string
            result += words[i]; // appending word by word
            if (i < words.size() - 1)
            { // if not last word adds a  space
                result += " ";
            }
        }

        return result; // result returned
    }

    string optimalapproach(string s)
    {
        string result="";//isme store krayege hum result ko 
        int i =s.size()-1;//back se iteration h isiliye we took -1 also 
        while(i>=0){//right to left movement 
            while(i>=0 && s[i]==' '){//skip spaces at current position
                i--;
            }
            if(i<0)break;//this will happen if i reaches at 0 and then finds nothing , poiniter is out of bounds 
            int end=i;//store the index where space came , indicates that current word eneded

            while(i>=0 && s[i]!=' '){//move to left until space or start of string is found
                i--;
            }
            string word =s.substr(i+1,end-i);//find the word using substr function
            if(!result.empty()){//if result string is not empty , help s add space after each word
                result+=" ";
            }
            result+=word;//append word in to result
        }
        return result;

    }
    
};

int main()
{
    Solution obj;
    string s = " amazing coding skills ";
    cout << obj.bruteforce(s) << endl;
    cout << obj.optimalapproach(s) << endl;
    return 0;
}