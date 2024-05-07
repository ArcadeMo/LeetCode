#include <iostream>
#include <string>

using namespace std; 

class Solution {
public:
    bool isPalindrome(string s) {
        // Initialize two pointers
        int leftPointer = 0;
        int rightPointer = s.size() - 1;

        // Utilize the pointers to check from both ends to the center of the string
        while (leftPointer < rightPointer) {
            // Check if the characters at the current pointer do not match
            if (s[leftPointer] != s[rightPointer]) {
                // If the characters are not identical, return false
                return false;
            }
            // If the characters are identical, move the pointers by 1
            leftPointer++;
            rightPointer--;
        }
        // If the pointers meet, return true
        return true;
    }
};

int main() {
    Solution solution;
    string input = "racecar";
    bool result = solution.isPalindrome(input);
    cout << (result ? "true" : "false") << endl;
    return 0;
}