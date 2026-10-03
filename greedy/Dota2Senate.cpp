/*
 * Problem: Dota2 Senate (LeetCode 649)
 * Link: https://leetcode.com/problems/dota2-senate/
 * Difficulty: Medium
 *
 * Approaches:
 * 1. Brute Force (Simulation with string erase) - Time: O(N^2), Space: O(1)
 * 2. Greedy Approach (Queue-based) - To be added
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ============================================================================
// Approach 1: Brute Force Simulation
// Time Complexity : O(N^2) due to searching and erasing in string
// Space Complexity: O(1) auxiliary space
// ============================================================================
class Solution {
public:
    bool removeSenator(string &senate, char ch, int idx) {
        bool loopAround = false;
        
        while(true) {
            if(idx == 0) {
                loopAround = true;
            }
            
            if(senate[idx] == ch) {
                senate.erase(begin(senate) + idx);
                break;
            }
            
            idx = (idx + 1) % (senate.length());
        }
        
        return loopAround;
    }
    
    string predictPartyVictory(string senate) {
        int R_Count = count(begin(senate), end(senate), 'R');
        int D_Count = senate.length() - R_Count;
        
        int idx = 0;
        
        while(R_Count > 0 && D_Count > 0) {
            if(senate[idx] == 'R') {
                bool checkRemoval = removeSenator(senate, 'D', (idx + 1) % (senate.length()));
                D_Count--;
                if(checkRemoval) {
                    idx--;
                }
            } else {
                bool checkRemoval = removeSenator(senate, 'R', (idx + 1) % (senate.length()));
                R_Count--;
                if(checkRemoval) {
                    idx--;
                }
            }
            
            idx = (idx + 1) % (senate.length());
        }
        
        return R_Count == 0 ? "Dire" : "Radiant";
    }
};

// ============================================================================
// Approach 2: Greedy (Queue-based)
// [Placeholder: Ready for you to add your greedy solution here]
// ============================================================================
class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>qr,qd;
        int n = senate.size();
        for( int i =0; i < senate.size(); i++){
            if(senate[i] == 'R'){
                qr.push(i);
            }else{
              qd.push(i);
            }
        }
        while(!qr.empty() && !qd.empty()){
            int qr_id = qr.front();
            qr.pop();
            int qd_id = qd.front();
            qd.pop();
            if(qr_id < qd_id){
                qr.push(qr_id + n);
            }else{
                qd.push(qd_id + n);
            }
        }
       return qd.size() > qr.size() ? "Dire" : "Radiant";
        
    }
};