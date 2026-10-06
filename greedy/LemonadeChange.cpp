/*
 * Problem: Lemonade Change (LeetCode 860)
 * Link: https://leetcode.com/problems/lemonade-change/
 * Difficulty: Easy
 *
 * Approach:
 * - Greedy Approach: Always try to give the largest denomination of change first.
 * - When given a $20 bill, prefer giving one $10 and one $5 as change, instead of three $5 bills, 
 *   to save $5 bills for $10 changes later.
 * 
 * Time Complexity: O(N) where N is the number of bills.
 * Space Complexity: O(1) as we only use a few counters.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, twenty = 0;
        if (bills[0] != 5) {
            return false;
        }
        five = 1;
        for (int i = 1; i < bills.size(); i++) {
            if (bills[i] == 5) {
                five++;
            } else if (bills[i] == 10) {
                if (five > 0) {
                    five--;
                    ten++;
                } else {
                    return false;
                }
            } else {
                if (ten > 0 && five > 0) {
                    five--;
                    ten--;
                    twenty++;
                } else if (five >= 3) {
                    five -= 3;
                    twenty++;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};
