class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<unordered_set<int>> graph;
        vector<int> indegree(numCourses, 0);
        for(int i = 0; i < numCourses; i++) {
        	unordered_set<int> set;
        	graph.push_back(set);
        }
        for(vector<pair<int, int>>::iterator it = prerequisites.begin(); it != prerequisites.end(); it++) {
        	graph[it->first].insert(it->second);
        	indegree[it->first]++;
        }
        for()
        for(int i = 0; i < )
    }
};