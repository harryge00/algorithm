#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool wayToSort(int i, int j) { return i > j; }

int leastInterval(vector<char>& tasks, int n) {
	int count[26] = {};
	int totalTasks = 0;
	for(int i = 0; i < tasks.size(); i++) {
		count[tasks[i] - 'A']++;
		totalTasks++;
	}
	sort(count, count + 26, wayToSort);
	int idleCount = (count[0] - 1) * n;
	for(int i = 1; i < 26 && count[i] > 0 && idleCount > 0; i++) {
		idleCount -= (count[i] == count[0] ? (count[i] - 1) : count[i]);
	}
	return totalTasks + idleCount;

}

int main ()
{
  cout<<"abxcybaz " << longestPalindromeSubseq("abxcybaz")<<endl;
  cout<< (4||7) <<","<< (5||3) << endl;
  return 0; 
}
