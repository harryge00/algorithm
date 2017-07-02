class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        sort(points.begin(), points.end());
        int cur_end = INT_MAX;
        int count = 0;
        for(int i = 0; i < points.size(); i++) {
        	if(cur_end >= points[i]->first) {
        		if(points[i]->second < cur_end) {
        			cur_end = points[i]->second;
        		}
        		continue;
        	}
        	count++;
        	cur_end = points[i]->second;
        }
        return count;
    }
};