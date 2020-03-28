#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void print2dVector(vector<vector<T>> &v) {
	for(int i = 0; i < v.size(); i++) {
		for(int j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

template <typename T>
void printVector(vector<T> &v) {
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}


int main() {
	int dimension = 4;
	vector<vector<int>> A(dimension, vector<int>(dimension));
	print2dVector<int>(A);
	vector<vector<int>> myvect = { {10,20,30,40}, {50,60,70,80} };
	print2dVector<int>(myvect);

	vector<vector<int>> myvect2{ vector<int>{10,20,30,40}, vector<int>{50,60,70,80} };
	print2dVector<int>(myvect2);

    vector<vector<bool>> d2(5, vector<bool>(6));
	print2dVector<bool>(d2);
	vector<int> emptyv;
	sort(emptyv.begin(),emptyv.end());
	cout << emptyv.size();
}

/*

1	2	3	4	5	6	7	8	9
2	4	6	8	10	12	14	16	18
3	6	9	12	15	18	21	24	27

m * n
min(x/i, n)
*/