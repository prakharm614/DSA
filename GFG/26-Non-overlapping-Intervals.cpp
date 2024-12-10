class Solution {
public:
    static bool comparator(const vector<int>& v1, const vector<int>& v2) {
        return v1[1] < v2[1];  
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return 0; 
        sort(intervals.begin(), intervals.end(), comparator);

        int count = 0;  
        int lastEnd = intervals[0][1]; 

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < lastEnd) {  
                // If the current interval overlaps with the previous one
                count++;  
            } else {
                // Update lastEnd to the end of the current non-overlapping interval
                lastEnd = intervals[i][1];
            }
        }

        return count;  
    }
};
