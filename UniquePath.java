public class UniquePath {
    /*public int uniquePaths(int m, int n) {
        if(m > n)
            return (int) (permutation(m + n, n)/permutation(n, 1));
        else
            return (int) (permutation(m + n, m)/permutation(m, 1));
    }
    public long permutation(int n, int k ) {
        int i = n;
        long res = 1;
        while(i > k) {
            res *= i;
            System.out.println(i+" "+res);
            i--;
        }
        return res;
    }*/
    public int uniquePaths(int m, int n) {
        return Helper(0, 0, 0, m, n);
    }
    public int Helper(int paths, int x, int y, int m, int n) {
        if(y < n - 1) paths = Helper(paths, x, y + 1, m, n);
        if(x < m - 1) paths = Helper(paths, x + 1, y, m, n);
        if(x == m - 1 && y == n - 1) return paths + 1;
        return paths;
    }
    public static void main(String[] args) {
        UniquePath a = new UniquePath();
        System.out.println(a.uniquePaths(13,12));
        int [][] test = new int[3][4];
        System.out.println(test[2][1]);

    }
}
