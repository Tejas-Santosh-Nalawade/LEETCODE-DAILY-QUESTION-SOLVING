class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        int countNum=0;
        for(int i=0; i<n; i++){
            if(arr[i]%2==1)
            {
                countNum++;
            }
            else{
                countNum=0;
            }
            if(countNum==3)
            {
            return true;
            }
        }
        return false;
    }
};