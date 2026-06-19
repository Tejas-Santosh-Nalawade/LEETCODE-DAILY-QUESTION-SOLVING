class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr = 0;
        int high = curr;

        for(int al:gain){
            curr+=al;
            high = max(high,curr);
        }
        return high;
    }
};