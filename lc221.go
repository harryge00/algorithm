func maximalSquare(matrix [][]byte) int {
    m := len(matrix)
    n := len(matrix[0])
    var p [m][n]int
    for(i := 0; i < m; i++) {
	    for(j := 0; j < n; j++) {
	        if(i == 0 || j == 0) {
	        	if(matrix[i][j] == 1) {
			        row[j] = 1
	        	} else {
			        row[j] = 0
	        	}
	        }
	    }
    }
}