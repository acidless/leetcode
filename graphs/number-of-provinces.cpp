// Problem: Number of Provinces
// Link: https://leetcode.com/problems/number-of-provinces
// Approach: DFS, O(V + E)

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int components = 0;
        vector<bool> visited = vector(isConnected.size(), false);

        for(int i = 0; i < isConnected.size(); i++) {
            if(!visited[i]) {
                dfs(isConnected, i, visited);
                components++;
            }
        }

        return components;
    }
private:
    void dfs(vector<vector<int>>& isConnected, int current, vector<bool>& visited) {
        if(visited[current]) {
            return;
        }

        visited[current] = true;
        for(int i = 0; i < isConnected.size(); i++) {
            if(i != current && isConnected[current][i]) {
                dfs(isConnected, i, visited);
            }
        }
    }
};
