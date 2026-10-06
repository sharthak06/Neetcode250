/*
 * Problem: Jump Game (LeetCode 55 / NeetCode 250)
 * Link: https://leetcode.com/problems/jump-game/
 * Difficulty: Medium
 *
 * Approach:
 * - Greedy approach: Keep track of the maximum reachable index `maxdistance`.
 * - Iterate through each index `i`.
 * - If the current index `i` is greater than the `maxdistance` we can reach, it means 
 *   we cannot move forward anymore. Return false.
 * - Otherwise, update `maxdistance` with `max(maxdistance, i + nums[i])`.
 * - If we successfully check all indices, we can reach the end. Return true.
 * 
 * Time Complexity: O(N) where N is the length of the array.
 * Space Complexity: O(1) as we only use a single variable.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxdistance = 0;
        for(int i = 0; i < nums.size(); i++){
             if(i > maxdistance){
                return false;
            }
            maxdistance = max(maxdistance, i + nums[i]);
           
        }
        return true;
    }
};
