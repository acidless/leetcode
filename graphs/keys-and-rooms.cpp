// Problem: Keys and Rooms
// Link: https://leetcode.com/problems/keys-and-rooms
// Approach: DFS, O(V + E)


class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited = vector(rooms.size(), false);
        int visitedCount = 0;

        dfs(rooms, 0, visited, visitedCount);

        return visitedCount == rooms.size();
    }
private:
    void dfs(vector<vector<int>>& rooms, int curr, vector<bool>& visited, int& visCount) {
        if(visited[curr]) {
            return;
        }

        visited[curr] = true;
        visCount++;

        for(int shared : rooms[curr]) {
            dfs(rooms, shared, visited, visCount);
        }
    }
};
