public class Increment_submatrices_2536 {
    public static int[][] rangeAddQueries(int n, int[][] queries) {
        int[][] res = new int[n][n];
        int[][] diff = new int[n + 1][n + 1];

        for (int i = 0; i < queries.length; i++) {
            int r1 = queries[i][0];
            int c1 = queries[i][1];
            int r2 = queries[i][2];
            int c2 = queries[i][3];

            diff[r1][c1] += 1;
            diff[r1][c2 + 1] -= 1;
            diff[r2 + 1][c1] -= 1;
            diff[r2 + 1][c2 + 1] += 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] += diff[i][j];

                if (i - 1 >= 0) {
                    res[i][j] += res[i - 1][j];
                }

                if (j - 1 >= 0) {
                    res[i][j] += res[i][j - 1];
                }

                if (i - 1 >= 0 && j - 1 >= 0) {
                    res[i][j] -= res[i - 1][j - 1];
                }
            }
        }

        return res;
    }

    public static void main(String[] args) {
        int[][] queries = {{1,1,2,2}, {0,0,1,1}};
        int n = 3;

        int[][] res = rangeAddQueries(n, queries);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(res[i][j] + " ");
            }
            System.out.println();
        }
    }
}
