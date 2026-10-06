/*
 * Problem: Maximum Sum Circular Subarray (LeetCode 918)
 * Link: https://leetcode.com/problems/maximum-sum-circular-subarray/
 * Difficulty: Medium
 *
 * Approach:
 * - Compute the standard Maximum Subarray Sum (Kadane's).
 * - Compute the Minimum Subarray Sum (Kadane's for minimum).
 * - Compute the total sum of the array.
 * - The maximum circular subarray sum is `totalSum - minSubarraySum`.
 * - Edge case: If all numbers are negative, `totalSum == minSubarraySum` and `maxSubarraySum < 0`, 
 *   so we should just return `maxSubarraySum` instead of `0`.
 * 
 * Time Complexity: O(N) where N is the length of the array.
 * Space Complexity: O(1) as we only use a few variables.
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int maxsum = INT_MIN, currmax = 0;
        int minisum = INT_MAX, currmin = 0;
        for (int x : nums) {
            currmax = max(currmax + x, x);
            maxsum = max(currmax, maxsum);

            currmin = min(currmin + x, x);
            minisum = min(currmin, minisum);
            total += x;
        }
        if (maxsum > 0) {
            return max(maxsum, total - minisum);
        }
        return maxsum;
    }
};
