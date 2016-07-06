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

/**
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    	vector<Interval> res;
    	bool expandNew = false; // newInterval is added?
    	bool isNewIntervalAdded = false;
    	for(vector<Interval>::iterator it = intervals.begin(); it != intervals.end(); it++) {
    		if(it->end < newInterval.start || it->start > newInterval.end) {
    			if(expandNew) {
    				res.push_back(newInterval);
    				isNewIntervalAdded = true;
    				expandNew = false;
    			}
    			res.push_back(*it);
    		} else {
    			if(!expandNew) {
    				expandNew = true;
    			}
    			if(it->start < newInterval.start) {
    				newInterval.start = it->start;
    			}
    			if(it->end > newInterval.end) {
    				newInterval.end = it->end;
    			}
    		}
    	}
    	if(!isNewIntervalAdded) {
			res.push_back(newInterval);
			isNewIntervalAdded = true;
		}
		return res;
    }
};

int main() {
    Solution s;
    //[1,2],[3,5],[6,7],[8,10],[12,16]
    std::vector<Interval> v;
    v.push_back(Interval(1, 2));
    v.push_back(Interval(3, 5));
    v.push_back(Interval(6, 7));
    v.push_back(Interval(8, 10));
    v.push_back(Interval(12, 16));
    // v.push_back(Interval(1, 5));

    // s.insert(v, Interval(0, 6));
    vector<Interval> vv = s.insert(v, Interval(4, 9));
    for(Interval ni : vv) {
        cout<<ni.start <<","<<ni.end<<endl;
    }

}