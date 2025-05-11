class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        for(int i=1; i<=n-2; i++){
            if(arr[i]%2==1 && arr[i+1]%2==1 && arr[i-1]%2==1){
                return true;
            }
        }
        return false;
    }

};