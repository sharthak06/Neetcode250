/*
 * Problem: Valid Parenthesis String (LeetCode 678 / NeetCode 250)
 * Link: https://leetcode.com/problems/valid-parenthesis-string/
 * Difficulty: Medium
 *
 * Approaches:
 * 1. Two Stacks (Greedy Matching with Indices) - Time: O(N), Space: O(N)
 * 2. Greedy Range Counting (Optimal) - Time: O(N), Space: O(1)
 *
 * Key Takeaways / Pitfalls:
 * - We store indices instead of characters to verify relative order: a '*' can
 *   only match a '(' if it appears AFTER the '(' in the string (st2.top() > st1.top()).
 * - When encountering ')', greedily match with a '(' first to preserve wildcards '*'
 *   for unmatched '(' that may appear earlier.
 */

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

// ============================================================================
// Approach 1: Two Stacks (Greedy Matching of Indices)
// Time Complexity : O(N) where N is the length of string s
// Space Complexity: O(N) to store indices in stacks
// ============================================================================
class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st1; // Stores indices of '('
        stack<int> st2; // Stores indices of '*'
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st1.push(i);
            } else if (s[i] == '*') {
                st2.push(i);
            } else {
                if (!st1.empty()) {
                    st1.pop();
                } else if (!st2.empty()) {
                    st2.pop();
                } else {
                    return false;
                }
            }
        }

        while (!st1.empty() && !st2.empty()) {
            if (st1.top() > st2.top()) {
                return false;
            }
            st1.pop();
            st2.pop();
        }
        
        if (!st1.empty()) {
            return false;
        }
        return true;
    }
};

// ============================================================================
// Approach 2: Greedy Range (Optimal O(1) Space)
// Time Complexity : O(N)
// Space Complexity: O(1)
// ============================================================================

class Solution {
public:
    bool checkValidString(string s) {
        int cmin = 0, cmax = 0; // Range of possible count of open '('
        
        for (char ch : s) {
            if (ch == '(') {
                cmin++;
                cmax++;
            } else if (ch == ')') {
                cmin = max(cmin - 1, 0);
                cmax--;
            } else if (ch == '*') {
                cmin = max(cmin - 1, 0); // '*' treated as ')'
                cmax++;                 // '*' treated as '('
            }
            
            if (cmax < 0) return false;
        }
        
        return cmin == 0;
    }
};

