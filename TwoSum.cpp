#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;

        for (int i = 0; i < nums.size(); i++) {
            // Calculate the complement of the current element
            int complement = target - nums[i];

            // Check if the complement exists in the map
            if (numMap.find(complement) != numMap.end()) {
                // If it exists, return the pair of indices
                return {numMap[complement], i};
            }

            // Store the current number and its index in the map
            numMap[nums[i]] = i;
        }

        // Return an empty vector if no solution is found
        return {};
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 10, 11, 15};
    int target = 9;
    vector<int> result = solution.twoSum(nums, target);
    if (result.empty()) {
        cout << "No two numbers found that add up to " << target << "." << endl;
    } else {
        cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    }
    return 0;
}
