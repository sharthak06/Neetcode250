/*
 * Problem: Partition Labels (LeetCode 763 / NeetCode 250)
 * Link: https://leetcode.com/problems/partition-labels/
 * Difficulty: Medium
 *
 * Approaches:
 * 1. HashMap (last occurrence) + Greedy Expansion - Time: O(N), Space: O(1)
 * 2. Array (last occurrence) + Greedy Single Pass - Time: O(N), Space: O(1)
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// ============================================================================
// Approach 1: HashMap (last occurrence) + Greedy Expansion
// Time Complexity : O(N)
// Space Complexity: O(1) — at most 26 chars in the map
// ============================================================================
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
   
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            mp[ch] = i;
        }
       int i =0;
       vector<int>res;
        while(i < s.size()){
            int end = mp[s[i]];
            cout << end << endl;
            int j = i;
            while(j < end){
                end = max(end,mp[s[j]]);
                j++;
            }
            res.push_back(j-i+1);
            i = j+1;

        }
        return res;
     
    }
};

// ============================================================================
// Approach 2: Array (last occurrence) + Greedy Single Pass
// Time Complexity : O(N)
// Space Complexity: O(1) — fixed size array of 26
// ============================================================================
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>mp(26,0);
        for(int i =0; i < s.size(); i++){
         int idx = s[i] - 'a';
         mp[idx] = i;
        }
        int start = 0, i=0;
        int end =0;
        vector<int>res;
        while(i < s.size()){
           end =  max(end,mp[s[i]-'a']);
           if(i == end){
            res.push_back(i-start+1);
             start = end+1;
           }
           i++;

        }
        return res;
        
    }
};
