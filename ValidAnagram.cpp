#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Anagrams must be of the same length
        if (s.length() != t.length()) {
            return false;
        }

        // Sort both strings
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        // Compare sorted strings
        return s == t;
    }
};

int main() {
    Solution solution;
    string s = "cat";
    string t = "rat";
    cout << "Are \"" << s << "\" and \"" << t << "\" anagrams? " 
         << (solution.isAnagram(s, t) ? "Yes" : "No") << endl;
    return 0;
}
