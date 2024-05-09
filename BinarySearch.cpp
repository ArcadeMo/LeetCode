#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // Initialize a left and right pointer
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right) {
            // Calculate the middle index -- avoids overflow
            int mid = left + (right - left) / 2;

            cout << "Checking middle position at index " << mid << " with value " << nums[mid] << endl;

            // Check if the middle element is in the target
            if (nums[mid] == target) {
                return mid; // Target found 
            } else if (nums[mid] < target) {
                // If the target is greater than mid, ignore the entire left half
                left = mid + 1;
            } else {
                // If the target is smaller than mid, ignore the entire right half
                right = mid - 1;
            }
        }

        // Return -1 if the target is not found in the given array
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 0;
    int index = solution.search(nums, target) + 1;
    cout << "The number " << target << (index != -1 ? " is at position " + to_string(index) : " not found") << "." << endl;
}