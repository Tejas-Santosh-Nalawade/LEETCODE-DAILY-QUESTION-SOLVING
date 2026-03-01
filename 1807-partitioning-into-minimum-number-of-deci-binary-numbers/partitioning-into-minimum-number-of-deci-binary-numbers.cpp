class Solution {
public:
    int minPartitions(string n) {
        int max_value = 0;

        for(auto c: n){
            int digit = c - '0';
            max_value = max(max_value , digit);
        }
        return max_value;

    }
};