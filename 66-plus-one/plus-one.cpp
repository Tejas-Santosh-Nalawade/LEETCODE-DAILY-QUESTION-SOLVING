class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        int sum=0;
        int N=digits.size();
        for(int i=N-1; i>=0; i--){
            sum=digits[i] + carry;
            digits[i]=sum % 10;
            carry=sum/10;
        }
        if(carry!=0){
            digits.insert(digits.begin(),1);
            return digits;
        }
        return digits;
    }
};