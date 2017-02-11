func getMin(a, b, c int) int {
    if a < b {
        if c < a {
            return c
        } else {
            return a
        }
    } else {
        if c < b {
            return c
        } else {
            return b
        }
    }
}

func maximalSquare(matrix [][]byte) int {
    m := len(matrix)
    n := len(matrix[0])
    var arr [][]int
    for i := 0; i < m; i++ {
        row := make([]int, n)
        arr = append(arr, row)
    }
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if i == 0 || j == 0 {
                if matrix[i][j] == 1 {
                    arr[i][j] = 1
                } else {
                    arr[i][j] = 0
                }
            } else {
                arr[i][j] = getMin(arr[i][j-1], arr[i - 1][j], arr[i - 1][j - 1]) + 1
            }
        }
    }
   
    return arr[m - 1][n - 1]
}