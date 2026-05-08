class Solution {
public:
    // [00:05:35] Static comparator for sorting by END time
    static bool comparator(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n <= 1) return 0;

        // [00:05:30] Step 1: Sort by end time (Greedy Choice)
        // This ensures we finish intervals as early as possible
        sort(intervals.begin(), intervals.end(), comparator);

        // [00:06:24] Step 2: Calculate maximum non-overlapping intervals
        int countKept = 1; // Always keep the first interval
        int lastEnd = intervals[0][1];

        for (int i = 1; i < n; i++) {
            // [00:06:57] If current start >= last end, they don't overlap
            // Note: [1,2] and [2,3] are NOT considered overlapping here
            if (intervals[i][0] >= lastEnd) {
                countKept++;
                lastEnd = intervals[i][1];
            }
        }

        // [00:07:27] Step 3: Minimal removals = Total - Maximum Kept
        return n - countKept;
    }
};