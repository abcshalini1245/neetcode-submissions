/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) return 0;

        vector<int> start, end;

        for (auto &i : intervals) {
            start.push_back(i.start);
            end.push_back(i.end);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int rooms = 0, maxRooms = 0;
        int i = 0, j = 0;

        while (i < start.size()) {
            if (start[i] < end[j]) {
                rooms++;                // need new room
                maxRooms = max(maxRooms, rooms);
                i++;
            } else {
                rooms--;                // meeting ended
                j++;
            }
        }

        return maxRooms;
    }
};

