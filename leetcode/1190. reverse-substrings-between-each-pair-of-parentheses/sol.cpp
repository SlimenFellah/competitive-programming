#include <string>
#include <stack>
using namespace std;


class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> stk;
        
        for (char c : s) {
            if (c == ')') {
                // Pop characters until we find '('
                string tmp;
                while (!stk.empty() && stk.top() != '(') {
                    tmp += stk.top();
                    stk.pop();
                }
                // Pop the '('
                if (!stk.empty()) stk.pop();
                
                // Push reversed substring back into the stack
                for (char ch : tmp) {
                    stk.push(ch);
                }
            } else {
                // Push normal characters onto the stack
                stk.push(c);
            }
        }
        
        // Construct the final string from the stack
        string result;
        while (!stk.empty()) {
            result = stk.top() + result;
            stk.pop();
        }
        
        return result;
    }
};