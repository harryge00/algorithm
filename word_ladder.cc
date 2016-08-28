#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
private:
	int min;
	bool foundPath = false;
	string ew;
public:
	bool isAdjacent(string a, string b) {
		int diffCount = 0;
		for(int i = 0; i < a.length(); i++) {
			if(a[i] != b[i]) {
				if(++diffCount > 1) return false;
			}
		}
		return diffCount == 1;
	}
	void bfs(unordered_set<string> visited, unordered_set<string> unvisited, string curword, int level) {
		visited.insert(curword);
		cout<<level<<","<<curword<<endl;
		if(isAdjacent(curword, ew)) {
			cout<<"reached:"<<level + 1 <<endl;
			if(level + 1 < min) {
				min = level + 1;
			}
			if(!foundPath) foundPath = true;
			return;
		}
		if(unvisited.size() == 0) return;
		for(string str : unvisited) {
			if(isAdjacent(str, curword)) {
				cout<<" "<<str<<endl;
				unvisited.erase(str);
				bfs(visited, unvisited, str, level + 1);
				unvisited.insert(str);
			}

		}
	}
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    	ew = endWord;
        min = wordList.size() + 2;
        unordered_set<string> visited;
        bfs(visited, wordList, beginWord, 1);
        if(!foundPath) return 0;
        return min;
    }
};

int main() {
	unordered_set<string> wl = {"hot","dot","dog","lot","log"};
	Solution s;
	cout<<s.ladderLength("hit", "cog", wl)<<endl;
}