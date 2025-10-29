// Problem: Number of Islands
// Link: https://leetcode.com/problems/number-of-islands
// Approach: DFS, O(N * M)

/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function(grid) {
    const visited = Array.from({ length: grid.length }, () =>
        new Array(grid[0].length).fill(false)
    );

    let islands = 0;

    for(let i = 0; i < grid.length; i++) {
        for(let j = 0; j < grid[0].length; j++) {
            if(grid[i][j] !== "0" && !visited[i][j]) {
                islands++;
                dfs(i, j, grid, visited);
            }
        }
    }

    return islands;
};

function dfs(x, y, grid, visited) {
    if(x < 0 || y < 0 || x >= grid.length
     || y >= grid[0].length || grid[x][y] === "0" || visited[x][y]) {
        return;
    }

    visited[x][y] = true;
    dfs(x - 1, y, grid, visited);
    dfs(x + 1, y, grid, visited);
    dfs(x, y - 1, grid, visited);
    dfs(x, y + 1, grid, visited);
}
