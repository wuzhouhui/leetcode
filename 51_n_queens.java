import java.util.*;

class Solution {
    private List<String[]> result;
    private boolean[]   occupy;
    private boolean[][] layout;
    public List<String[]> solveNQueens(int n) {
        result = new LinkedList<String[]>();
        if (n <= 0)
            return(result);
        occupy = new boolean[n];
        layout = new boolean[n][n];
        do_nqueen(n, 0);
        return(result);
    }
    private void do_nqueen(int n, int level) {
        int i;

        if ((n - 1) == level) {
            for (i = 0; i < n; i++)
                if (occupy[i] == false)
                    break;
            occupy[i] = true;
            layout[level][i] = true;
            if (avail(n, level))
                add_ans(n);
            occupy[i] = false;
            layout[level][i] = false;
            return;
        }

        for (i = 0; i < n; i++) {
            if (occupy[i] == true)
                continue;
            occupy[i] = true;
            layout[level][i] = true;
            if (avail(n, level))
                do_nqueen(n, level + 1);
            occupy[i] = false;
            layout[level][i] = false;
        }
    }
    private boolean avail(int n, int level) {

        int i, j, k, l;

        for (i = 0; i <= level; i++) {
            for (j = 0; j < n; j++) {
                if (layout[i][j] == false)
                    continue;
                for (k = i + 1, l = j - 1; k <= level && l >= 0; k++, l--)
                    if (layout[k][l] == true)
                        return(false);
                for (k = i + 1, l = j + 1; k <= level && l < n; k++, l++)
                    if (layout[k][l] == true)
                        return(false);
            }
        }
        return(true);
    }
    private void add_ans(int n) {
        char[] chars = new char[n];
        String[] strs = new String[n];
        int i, j;

        for (i = 0; i < n; i++)
            chars[i] = '.';
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                if (layout[i][j] == true) {
                    chars[j] = 'Q';
                    break;
                }

            strs[i] = new String(chars);
            chars[j] = '.';
        }
        result.add(strs);
    }
    public static void main(String[] args) {
        List<String[]> list;
        list = new Solution().solveNQueens(2);

        for (int i = 0; i < list.size(); i++) {
            for (String s : list.get(i))
                System.out.println(s);
        }
    }
}
