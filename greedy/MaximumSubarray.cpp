/*
 * Problem: Maximum Subarray (LeetCode 53 / NeetCode 250)
 * Link: https://leetcode.com/problems/maximum-subarray/
 * Difficulty: Medium
 *
 * Approach:
 * - Kadane's Algorithm (Greedy/Dynamic Programming).
 * - Keep a running sum. If the sum drops below zero, reset it to zero (since a negative prefix 
 *   will only decrease the sum of any future subarray).
 * - Keep track of the maximum sum seen so far.
 * 
 * Time Complexity: O(N) where N is the length of the array.
 * Space Complexity: O(1) as we only use a few variables.
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
           
            if (sum > maxSum) {
                maxSum = sum;
            }
            if (sum < 0) {
                sum = 0;
            }
        }
        return maxSum;
    }
};
