#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // Create a stack to keep track of brackets
        stack<char> stack;
        // Create a map to store the matching pairs of brackets
        unordered_map<char, char> matchedBrackets = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        // Traverse each character in the string
        for (char c : s) {
            // Check if the the character is a closing bracket
            if (matchedBrackets.count(c)) {
                // Check if the stack is empty or if the top  of the stack is not matching
                if (stack.empty() || stack.top() != matchedBrackets[c]) {
                    return false;
                }
                // Pop the top element from the stack
                stack.pop();
            } else {
                // If it is an open bracket, push it onto the stack
                stack.push(c);
            }
        }

        // If all the opening brackets have been matched, the stack is empty
        return stack.empty();
    }
};

int main() {
    Solution solution;
    string input1 = "()";
    string input2 = "()[]{}";
    string input3 = "(]";

    cout << "Input: " << input1 << " Output: " << (solution.isValid(input1) ? "true" : "false") << endl;
    cout << "Input: " << input2 << " Output: " << (solution.isValid(input2) ? "true" : "false") << endl;
    cout << "Input: " << input3 << " Output: " << (solution.isValid(input3) ? "true" : "false") << endl;
    return 0;
}