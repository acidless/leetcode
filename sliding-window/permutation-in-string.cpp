// Problem: Permutation in String
// Link: https://leetcode.com/problems/permutation-in-string
// Approach: Sliding window, O(n)


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        std::vector<int> freq(26, 0);
        std::vector<int> freqSearch(26, 0);
        for(char c : s1) {
            freq[c - 'a']++;
        }

        int l = 0, r = s1.size() - 1;
        while(r < s2.size()) {
            if(l != 0) {
                freqSearch[s2[l - 1] - 'a']--;
                freqSearch[s2[r] - 'a']++;
            } else {
                for(int i = l; i <= r; i++) {
                    freqSearch[s2[i] - 'a']++;
                }
            }
            
            if(freqSearch == freq) {
                return true;
            }

            l++;
            r++;
        }

        return false;
    }

};
