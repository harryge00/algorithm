#include <vector>
#include <iostream>
using namespace std;

bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
    bool result = false;
    vector<vector<int> > graph;
    int n = prerequisites.size();
    for(int i = 0; i < n; i++) {
    	vector<int> row(n, 0);
    	graph.push_back(row);
    }
    for(int i = 0; i < n; i++) {
    	pair<int,int> pr = prerequisites[i];
    	graph[pr.first][pr.second] = 1;
    }
    for(int i = 0; i < n; i++) {
    	for(int j=0;j<n;j++){
    		cout<<graph[i][j]<<",";
    	}
    	cout<<endl;
    }
	return false;
}
int main() {
	vector<pair<int, int> > pre;
	pre.push_back(pair<int, int>(1, 2));
	pre.push_back(pair<int, int>(0, 2));
	pre.push_back(pair<int, int>(1, 4));
	pre.push_back(pair<int, int>(0, 3));
	pre.push_back(pair<int, int>(3, 5));
	pre.push_back(pair<int, int>(5, 4));
	canFinish(6, pre);
	return 0;
}
