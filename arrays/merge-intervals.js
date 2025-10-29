// Problem: Merge Intervals
// Link: https://leetcode.com/problems/merge-intervals
// Approach: Sorting, O(nlogn)

/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function(intervals) {
    const sorted = [...intervals].sort((a,b) => {
        if(a[0] > b[0]) {
            return 1;
        } else if(a[0] < b[0]) {
            return -1;
        } else {
            return a[1] > b[1];
        }
    });

    const result = [];
    let current = null;
    for(let i = 0; i < sorted.length; i++) {
        if(!current) {
            current = [...sorted[i]];
        } else if(current[1] >= sorted[i][0] && current[1] <= sorted[i][1]) {
            current[1] = sorted[i][1];
        } 
        else if(sorted[i][0] < current[0] || sorted[i][1] > current[1]) {
            result.push(current);
            current = [...sorted[i]];
        }
    }

    if(current) {
        result.push(current);
    }

    return result;
};
