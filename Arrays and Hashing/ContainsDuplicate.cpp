#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        
        for (int num : nums) {
            // Checking if the current element 'num' is already in the set 's'.
            if (s.find(num) != s.end()) {
                // If 'num' is found in the set, return true since that means duplicate is found
                return true;
            }
            // Insert the current element 'num' into the set 's' if it is not already present.
            s.insert(num);
        }
        
        // Return false if no duplicates are found after checking all elements.
        return false;
    }
};

int main() {
    Solution solution;
    
    // Test case 1: No duplicates
    vector<int> nums1 = {1, 2, 3, 4, 5};
    cout << "Test Case 1: " << (solution.containsDuplicate(nums1) ? "Duplicates Found" : "No Duplicates") << endl;
    
    // Test case 2: Contains duplicates
    vector<int> nums2 = {1, 2, 3, 2};
    cout << "Test Case 2: " << (solution.containsDuplicate(nums2) ? "Duplicates Found" : "No Duplicates") << endl;
    
    // Test case 3: Empty vector
    vector<int> nums3 = {};
    cout << "Test Case 3: " << (solution.containsDuplicate(nums3) ? "Duplicates Found" : "No Duplicates") << endl;

    return 0;
}
