# include <iostream>
# include <vector>
# include <unordered_set>
using namespace::std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        vector<int> indegree(numCourses, 0);
        for(auto p : prerequisites) {
        	graph[p.second].insert(p.first);
        }
        for(int i = 0; i < numCourses; i++) {
        	for(auto nextPoint : graph[i]) {
        		indegree[nextPoint]++;
        	}
        }
        for(int i = 0; i < numCourses; i++) {
        	int j = 0;
        	for(; j < numCourses; j++) {
        		if(!indegree[j]) break;
        	}
        	if(j == numCourses) return false;
        	indegree[j] = -1;
        	for(auto nextPoint : graph[j]) {
        		indegree[nextPoint]--;
        	}
        }
		return true;        
    }
};

int main() {
    Solution s;
    vector<pair<int, int>> v;
    //10
	// [[5,8],[3,5],[1,9],[4,5],[0,2],[1,9],[7,8],[4,9]]
    v.push_back(pair<int, int>(5, 8));
    v.push_back(pair<int, int>(3, 5));
    v.push_back(pair<int, int>(1, 9));
    v.push_back(pair<int, int>(4, 5));
    v.push_back(pair<int, int>(0, 2));
    v.push_back(pair<int, int>(1, 9));
    v.push_back(pair<int, int>(7, 8));
    v.push_back(pair<int, int>(4, 9));
    cout<<s.canFinish(10, v)<<endl;

}