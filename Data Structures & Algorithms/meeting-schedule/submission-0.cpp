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
    bool canAttendMeetings(vector<Interval>& intervals) {

        std::sort(intervals.begin(), intervals.end(),  [](const Interval &s, const Interval &e) {
           if (s.start != e.start) {  return s.start < e.start; } 
           return s.end < e.end;
        });

        for (int i=1; i < intervals.size(); ++i)
        {
            // Check that the previous interval's end time doesn't exceed the next interval's start time
            if (intervals[i-1].end > intervals[i].start)
            {
                std::cout << intervals[i-1].end  << ">" << intervals[i].start << std::endl;
                return false;
            }
            std::cout << intervals[i-1].end  << "<" << intervals[i].start << std::endl;
        }

        return true;
    }
};
