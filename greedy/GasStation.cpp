/*
 * Problem: Gas Station (LeetCode 134 / NeetCode 250)
 * Link: https://leetcode.com/problems/gas-station/
 * Difficulty: Medium
 *
 * Approach:
 * - Greedy approach.
 * - First, verify if it's possible to complete the circuit. This is true if the total 
 *   gas is greater than or equal to the total cost. If not, return -1.
 * - Since there is a unique solution (if it exists), we can keep a running sum of `gas[i] - cost[i]`.
 * - If at any point this sum becomes negative, it means we cannot reach the next station 
 *   starting from the current starting point (or any point before it). 
 * - Therefore, we reset the running sum to 0 and set the next station `i + 1` as the new 
 *   potential starting point.
 * 
 * Time Complexity: O(N) where N is the number of stations.
 * Space Complexity: O(1) as we only use a few variables.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalCost = 0;
        int totalGas = 0;
        for(int i = 0; i < gas.size(); i++){
            totalCost += cost[i];
            totalGas += gas[i];
        }
        if(totalCost > totalGas){
            return -1;
        }
        int result = 0;
        int sum = 0;
        for(int i = 0; i < gas.size(); i++){
             sum += gas[i] - cost[i];
             if(sum < 0){
                sum = 0;
                result = i + 1;
             }
        }
        return result;
    }
};
