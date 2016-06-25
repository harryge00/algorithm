# include <iostream>
# include <vector>
using namespace::std;
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct Interval {
   int start;
   int end;
   Interval() : start(0), end(0) {}
   Interval(int s, int e) : start(s), end(e) {}
};
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        bool toBeContinued = false;
        vector<Interval> ret;
        for(vector<Interval>::iterator it = intervals.begin(); it != intervals.end(); it++ )
        {
            // if(newInterval.end < it->start) {
            //     ret.push_back(newInterval);
            // } else if(newInterval.end >=)
            if(toBeContinued) {
                if(newInterval.end < it->start) {
                    intervals.emplace(it, newInterval);
                    // toBeContinued = false;
                    return intervals;
                } else if(newInterval.end <= it->end){
                    it->start = newInterval.start;
                    // toBeContinued =false;
                    return intervals;
                } else {
                    intervals.erase(it);
                }
            }
            if(newInterval.start < it->start) {
                if(newInterval.end < it->start) {
                    intervals.emplace(it, newInterval);
                    return intervals;
                } else if(newInterval.end <= it->end) {
                    it->start = newInterval.start;
                    return intervals;
                } else {
                    toBeContinued = true;
                    intervals.erase(it);
                }
            } else if (newInterval.start <= it->end) {
                newInterval.start = it->start;
                if(newInterval.end <= it->end) {
                    return intervals;
                } 
                // intervals.erase(it);
                toBeContinued = true;
                
            }
        }
        intervals.push_back(newInterval);
        return intervals;
    }
};

int main() {
    Solution s;
    //[1,2],[3,5],[6,7],[8,10],[12,16]
    std::vector<Interval> v;
    // v.push_back(Interval(1, 2));
    // v.push_back(Interval(3, 5));
    // v.push_back(Interval(6, 7));
    // v.push_back(Interval(8, 10));
    // v.push_back(Interval(12, 16));
    v.push_back(Interval(1, 5));

    s.insert(v, Interval(0, 6));
    for(Interval ni : v) {
        cout<<ni.start <<","<<ni.end<<endl;
    }
}