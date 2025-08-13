class Solution {
public:
    bool isPowerOfFour(int n) {
        return n>=1 && floor(log2(n))==ceil(log2(n)) && (int)log2(n)%2==0;
    }
};