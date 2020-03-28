class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        /*
			Given input matrix =
			[
			  [ 5, 1, 9,11],
			  [ 2, 4, 8,10],
			  [13, 3, 6, 7],
			  [15,14,12,16]
			], 

			rotate the input matrix in-place such that it becomes:
			[
			  [15,13, 2, 5],
			  [14, 3, 4, 1],
			  [12, 6, 8, 9],
			  [16, 7,10,11]
			]

			1, 2, 3,4,5
			6, 7, 8,9,10
			11,12,13,14,15
			16
			21

			21 16 11 6 1
						2
						3
						4
						5




			i,	j

			j,  n - i - 1

			[1,1] [1, 2] 2,2 2,1  1, n - n 

			n - 1 - (n - i - 1)


			i, j

			j, n - i - 1

			n - i -1,  n - j - 1

			n - j - 1, i
			[[7,8,1],[6,5,4],[9,2,3]]
			7 8 1
			6 5 4
			9 2 3

			1,2,3
			4,5,6
			7,8,9


			0,1,2,3,4
			0,1,2,3,4
			0,1,2,3,4
			0,1,2,3,4
			0,1,2,3,4
		

			1,0



        */
        int n = matrix.size();
        for(int i = 0; i < ( 1 + n) / 2; i++) {
        	for(int j = 0; j < ( 1 + n) / 2; j++) {
        		int tmp = matrix[i][j];
        		matrix[i][j] = matrix[n - j - 1][i];
        		matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
        		matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
        		matrix[j][n - i - 1] = tmp;

        	}
        }
    }
};