#include <vector>
#include <iostream>

using namespace std; 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Initialize the min price to a very high value 
        int minPrice = INT_MAX; //Ironic

        // Initialize the max profit; set to zero just in case there were no transaction done)
        int maxProfit = 0;

        // Loop through all prices in the array
        for (int price : prices) {
            // Update the min price to the current lowest price in the array
            if (price < minPrice) {
                minPrice = price;
            }
            // Using the lowest profit found so far, calculate the profit if you are selling on the current day at the current price
            else if (price - minPrice > maxProfit) {
                maxProfit = price - minPrice;
            }
        }
        // Return the max profit found; if no profit can be made, it will return zero.
        return maxProfit;
    }
};

int main() {
    Solution solution;
    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Maximum profit for prices {7,1,5,3,6,4}: " << solution.maxProfit(prices1) << endl;
    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << "Maximum profit for prices {7,6,4,3,1}: " << solution.maxProfit(prices2) << endl;
    return 0;
}