// Problem: String Compression
// Link: https://leetcode.com/problems/string-compression
// Approach: O(n)


class Solution {
public:
    int compress(vector<char>& chars) {
        int writeIdx = 0;
        int size = chars.size();

        for(int readIdx = 0, nextIdx = 0; readIdx < size; ) {
            while(nextIdx < size && chars[readIdx] == chars[nextIdx]) {
                nextIdx++;
            }
            
            chars[writeIdx++] = chars[readIdx];

            int groupSize = nextIdx - readIdx;
            if(groupSize > 1) {
                auto strGroup = to_string(groupSize);
                for(char c : strGroup) {
                    chars[writeIdx++] = c;
                }
            }

            readIdx = nextIdx;
        }

        return writeIdx;
    }
};
