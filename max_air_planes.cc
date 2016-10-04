# include <iostream>
# include <vector>
#include <cmath>
#include <climits>
using namespace::std;
/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Interval {
public:
  int start, end;
  Interval(int start, int end) {
      this->start = start;
      this->end = end;
  }
};
class Solution {
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        int upperlimit = 0; //, lowerlimit = INT_MAX;
        for(vector<Interval>::iterator it = airplanes.begin();
        it != airplanes.end(); it++) {
            if((*it).end > upperlimit) {
              upperlimit = (*it).end;
            }
        }
        int* planes = new int[upperlimit];
        for(vector<Interval>::iterator it = airplanes.begin();
        it != airplanes.end(); it++) {
          planes[(*it).start]++;
          planes[(*it).end]--;
        }
        int max = 0, cur = 0;
        for(int i = 0; i < upperlimit; i++) {
          cur += planes[i];
          if(cur > max) {
            max = cur;
          }
        }
        return max;
    }
};
// [[1,10],[2,3],[5,8],[4,7]]
int main() {
  Solution s;
  vector<Interval> v{
    Interval{1, 10},
    Interval{2, 3},
    Interval{5, 8},
    Interval{4, 7}
  };
  cout<<s.countOfAirplanes(v)<<endl;
}
