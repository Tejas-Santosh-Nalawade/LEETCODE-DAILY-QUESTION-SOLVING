class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digit = "123456789";

        vector<int>res;

        int n = to_string(low).size();
        int m = to_string(high).size();

        for(int len = n; len<=m; len++){
            for(int i=0; i<10 - len; i++){
                int num = stoi(digit.substr(i,len));

                if(low <= num && num<= high){
                    res.push_back(num);
                }
            }
        }
        return res;
    }
};