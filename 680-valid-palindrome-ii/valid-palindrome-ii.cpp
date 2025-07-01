class Solution {
public:
    bool isPalindrome(string s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int st = 0, e = s.size() - 1;

        while (st < e) {
            if (s[st] != s[e]) {
                return isPalindrome(s, st + 1, e) || isPalindrome(s, st, e - 1);
            }
            st++;
            e--;
        }
        return true;
    }
};