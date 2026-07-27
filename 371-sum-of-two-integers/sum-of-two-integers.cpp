class Solution {
public:
    int getSum(int a, int b) {
        while(b){
            int carry = (a & b) <<1;
            int sum = a ^ b;
            a = sum;
            b = carry;
        }
        return a;
    }
};