#include <map>
#include <vector>
#include <set>
#include <iostream>
#include <string>

using namespace std;
class TrieNode {
private:
public:
    TrieNode *next[26];
    bool is_word;
    // Initialize your data structure here.
    TrieNode(bool b = false) {
        memset(next, 0, sizeof(next));
        is_word = b;
    }
};

int main() {
	TrieNode* root = new TrieNode(true);
	cout<<root->is_word<<endl;
	cout<<(root->next[0] == NULL)<<endl;
	map<int,int> m;
	m[1] = 2;
	m[2] = 3;
	cout<<m.size()<<","<<m[3]<<endl;
	map<int, vector<int> > m2;
	vector<int> v1(5, 2);
	m2[1] = v1;
	cout<<m2[1].size()<<","<<m2[1][2]<<","<<m2[31].size()<<endl;
	return 0;
}