#include <iostream>
#include <string>
#include <cctype>

using namespace std; 

class Solution {
public:
    bool isPalindrome(string s) {

        // Initialize an empty string to hold an alphanumeric input
        string alphanumeric;

        // Iterate through the string
        for (char c : s) {
            // Check if the char is alphanumeric 
            if (isalnum(c)) {
                // Convert all uppercase characters to lowercase and add to the string
                alphanumeric += tolower(c);
            }
        }

        // Initialize two pointers
        int leftPointer = 0;
        int rightPointer = alphanumeric.size() - 1;

        // Utilize the pointers to check from both ends to the center of the string
        while (leftPointer < rightPointer) {
            // Check if the characters at the current pointer do not match
            if (alphanumeric[leftPointer] != alphanumeric[rightPointer]) {
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
    string input = "A man, a plan, a canal: Panama";
    bool result = solution.isPalindrome(input);
    cout << (result ? "true" : "false") << endl;
    return 0;
}