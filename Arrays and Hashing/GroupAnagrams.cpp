#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Hash map to store the groups of anagrams
        unordered_map<string, vector<string>> anagramGroups;
        
        // Iterate through each string in the input array
        for (string s : strs) {
            // Sort the characters in the string to form the key
            string sortedStr = s;
            sort(sortedStr.begin(), sortedStr.end());
            
            // Add the original string to the group corresponding to the sorted key
            anagramGroups[sortedStr].push_back(s);
        }
        
        // Collect the groups of anagrams from the hash map
        vector<vector<string>> result;
        for (auto& entry : anagramGroups) {
            result.push_back(entry.second);
        }
        
        return result;
    }
};

// Helper function to print the result
void printGroupedAnagrams(Solution& solution, vector<string>& strs) {
    vector<vector<string>> result = solution.groupAnagrams(strs);
    for (const auto& group : result) {
        cout << "[";
        for (const string& str : group) {
            cout << "\"" << str << "\", ";
        }
        cout << "], ";
    }
    cout << endl;
}

int main() {
    Solution solution;

    // Example 1
    vector<string> strs1 = {"act", "pots", "tops", "cat", "stop", "hat"};
    cout << "Example 1: ";
    printGroupedAnagrams(solution, strs1);

    // Example 2
    vector<string> strs2 = {"x"};
    cout << "Example 2: ";
    printGroupedAnagrams(solution, strs2);

    // Example 3
    vector<string> strs3 = {""};
    cout << "Example 3: ";
    printGroupedAnagrams(solution, strs3);

    return 0;
}
