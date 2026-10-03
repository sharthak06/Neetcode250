/*
 * Problem: Hand of Straights (LeetCode 846 / NeetCode 250)
 * Link: https://leetcode.com/problems/hand-of-straights/
 * Difficulty: Medium
 *
 * Approach:
 * - Count card frequencies using an ordered map (std::map) so keys are kept in sorted order.
 * - Greedily find the smallest available card `curr = mp.begin()->first`.
 * - Form a consecutive group of size `groupSize` starting from `curr` up to `curr + groupSize - 1`.
 * - Decrement card count and erase entries once frequency reaches 0.
 * - If any required consecutive card is missing (count == 0), return false.
 *
 * Time Complexity: O(N log N) where N is the total number of cards.
 * Space Complexity: O(N) to store frequencies in the ordered map.
 *
 * Key Takeaways / Pitfalls:
 * - Quick exit check: if `hand.size() % groupSize != 0`, return false immediately.
 * - Using an ordered map ensures we always start groups from the minimum available card.
 */

#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize  != 0){
            return false;
        }
        map<int,int>mp;
        for(int i : hand){
            mp[i]++;
        }

        while(!mp.empty()){
            int curr = mp.begin()-> first;

            for(int i =0; i < groupSize; i++){
                if(mp[curr+i] == 0){
                    return false;
                }
                mp[curr+i]--;
                if(mp[curr+i] == 0){
                    mp.erase(curr+i);
                }

            }
        }
        return true;
    }
};