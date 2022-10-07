/*
// find the character with the maximum number of occurences in the string
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    string str;
    cin >> str;
    unordered_map<int, int> umap;
    char value;
    int count = 0;
    for (auto i : str)
    {
        umap[i]++;
        if (umap[i] > count)
        {
            count = umap[i];
            value = i;
        }
    }
    cout << "the letter with the maximum occurence is: " << value << "\nthe letter occurs " << count << " times. " << endl;
    return 0;
}
*/
/*
// reverse words in a string
Input: s = "the sky is blue"
Output: "blue is sky the"
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Solution
{
public:
    string reversewords(string s)
    {
        stack<string> words;
        string ans = "";
        for (int i = 0; i < s.length(); i++)
        {
            string temp = "";
            while (i < s.length() && s[i] != ' ')
            {
                temp += s[i];
                i++;
            }
            words.push(temp);
        }
        while (!words.empty())
        {
            ans += words.top();
            words.pop();
            if (!words.empty())
                ans += " ";
        }
        return ans;
    }
};
int main()
{
    string s = "";
    getline(cin, s);
    Solution obj;
    string ans = obj.reversewords(s);
    cout << ans << endl;
    return 0;
}
*/
/*URLify a string
example:
input: hello world
output: hello@40world
#include <iostream>
#include <string>
#define max_len 100
using namespace std;
void replaceSpaces(string &str)
{
    string ans = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            ans.push_back('@');
            ans.push_back('4');
            ans.push_back('0');
        }
        else
        {
            ans.push_back(str[i]);
        }
    }
    cout << ans << endl;
}
int main()
{
    string str;
    getline(cin, str);
    replaceSpaces(str);
    return 0;
}
*/
/*
// URLify a string O(1) space solution
#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    string urlify(string s)
    {
        int size = s.length();
        string del = " ";
        int i = 0;
        while (i < size)
        {
            if (s[i] == ' ')
            {
                s.erase(s.find(del), del.size());
                s.insert(i, "@40");
                i++;
            }
            i++;
        }
        return s;
    }
};
int main()
{
    Solution obj;
    string s = "";
    getline(cin, s);
    string ans = obj.urlify(s);
    cout << "the urlified string is : " << ans << endl;
    return 0;
}
*/
/*
// count the number of occurences of each character in the string
#include <iostream>
using namespace std;
class Solution
{
public:
    void getfreq(string s)
    {
        int letterfreq[26] = {0};
        for (int i = 0; i < s.length(); i++)
        {
            int index = s[i] - 'a';
            letterfreq[index]++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (letterfreq[i] > 0)
                cout << char('a' + i) << " -> " << letterfreq[i] << endl;
        }
    }
};
int main()
{
    Solution obj;
    string s = "";
    getline(cin, s);
    cout << "the frequency of each letter in the input string is : " << endl;
    obj.getfreq(s);
    return 0;
}
*/
/*
// remove outer parantheses leetcode 1021 wrong soln
class Solution {
public:
    string removeOuterParentheses(string s) {
        string valid = "()";
        stack<string> ans_stack;
        // for (int i = 0; i < s.length(); i++)
        // {
            // if (s.find(valid))
            // {
                // ans_stack.push(valid);
                // s.erase(s.find(valid), s.find(valid) + 1);
            // }
        // }
        // string ans = "";
        // while (!ans_stack.empty())
        // {
            // ans += ans_stack.top();
            // ans_stack.pop();
        // }
        return ans;
    }
};
*/
