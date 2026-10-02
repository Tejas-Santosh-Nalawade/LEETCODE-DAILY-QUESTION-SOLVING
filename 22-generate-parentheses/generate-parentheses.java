class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();
        dfs(0, 0, n, new StringBuilder(), res);
        return res;
    }

    private void dfs(int open, int close, int n,
                     StringBuilder s, List<String> res) {

        if (s.length() == 2 * n) {
            res.add(s.toString());
            return;
        }

        if (open < n) {
            s.append('(');
            dfs(open + 1, close, n, s, res);
            s.deleteCharAt(s.length() - 1);
        }

        if (close < open) {
            s.append(')');
            dfs(open, close + 1, n, s, res);
            s.deleteCharAt(s.length() - 1);
        }
    }
}