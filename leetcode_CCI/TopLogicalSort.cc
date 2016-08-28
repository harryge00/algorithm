#include <map>
#include <vector>
#include <set>
#include <iostream>
#include <stack>
using namespace std;
bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
    int n = prerequisites.size();
    map<int, vector<int> > m;
    map<int, bool> visited;
    for(int i = 0; i < n; i++) {
    	pair<int, int> p = prerequisites[i];
        if(m.find(p.second) == m.end()) {
        	vector<int> nextCourses;
        	nextCourses.push_back(p.first);
        	m[p.second] = nextCourses;
        } else {
        	vector<int> nextCourses = m[p.second];
        	nextCourses.push_back(p.first);
        	m[p.second] = nextCourses;
        }
    }
    // for(map<int,vector<int> >::iterator it = m.begin(); it!=m.end();it++) {
    // 	vector<int> next = it->second;
    // 	for(int j=0;j<next.size();j++) {
    // 		cout<<it->first<<","<<next[j]<<endl;
    // 	}
    // }
    stack<int> st;
    for(map<int,vector<int> >::iterator it = m.begin(); it!=m.end();it++) {
        int begin = it->first;
        st.push(begin);
        vector<int> curPos (numCourses, 0);
        visited[begin] = true;
        while(!st.empty()) {
            int top = st.top();
            if(curPos[top] >= m[top].size()) {
                visited[top] = false;
                st.pop();
            } else {
                int nextCourse = m[top][curPos[top]++];
                if(visited[nextCourse]) {
                    // cout<<nextCourse<<" already done before"<<endl;
                    return false;
                }
                // cout<<top<<","<<nextCourse<<endl;
                visited[nextCourse] = true;
                st.push(nextCourse);
            }
        }
    }
    return true;
}
int main() {
	vector<pair<int, int> > courses;
	courses.push_back(pair<int,int>(0,1));
	courses.push_back(pair<int,int>(0,2));
	courses.push_back(pair<int,int>(0,3));
	courses.push_back(pair<int,int>(1,2));
	courses.push_back(pair<int,int>(2,3));
	cout<<canFinish(4, courses)<<endl;
    vector<pair<int, int> > pre;
    pre.push_back(pair<int, int>(1, 2));
    pre.push_back(pair<int, int>(0, 2));
    pre.push_back(pair<int, int>(1, 4));
    pre.push_back(pair<int, int>(0, 3));
    pre.push_back(pair<int, int>(3, 5));
    pre.push_back(pair<int, int>(5, 4));
    cout<<canFinish(6, pre)<<endl;
    pre.push_back(pair<int, int>(4, 3));
    cout<<canFinish(6, pre)<<endl;
	return 0;
}