#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;
ysq

int main() {
	vector<string> words{"practice", "makes", "perfect", "coding", "makes"};

	WordDistance w(words);
	w.print();
	cout<<w.shortest("coding", "practice") << endl;
	cout<<w.shortest("makes", "coding") << endl;

}
//[186,419,83,408]
// 6249