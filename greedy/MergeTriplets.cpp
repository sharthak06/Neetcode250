/*
 * Problem: Merge Triplets to Form Target Triplet (LeetCode 1899 / NeetCode 250)
 * Link: https://leetcode.com/problems/merge-triplets-to-form-target-triplet/
 * Difficulty: Medium
 *
 * Approach:
 * - Greedy approach.
 * - We can only use a triplet if ALL of its elements are less than or equal to the 
 *   corresponding elements in the target triplet. If any element strictly exceeds 
 *   the target, merging it would permanently ruin our chances of matching the target.
 * - We iterate through all valid triplets and keep track of the maximum values we 
 *   can achieve for the first, second, and third positions.
 * - If at any point our achieved maximums match the target, we return true.
 * 
 * Time Complexity: O(N) where N is the number of triplets.
 * Space Complexity: O(1) as we only use three variables to track the max values.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int first = 0, second = 0, third = 0;
        
        for(int i = 0; i < triplets.size(); i++){
            if(target[0] >= triplets[i][0] && target[1] >= triplets[i][1] && target[2] >= triplets[i][2]){
                 first = max(first, triplets[i][0]);
                 second = max(second, triplets[i][1]);
                 third = max(third, triplets[i][2]);
            }
            
            if(first == target[0] && second == target[1] && third == target[2]){
                return true;
            }
        }
        return false;
    }
};
