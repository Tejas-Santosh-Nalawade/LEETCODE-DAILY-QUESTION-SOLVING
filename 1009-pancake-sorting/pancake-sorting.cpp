class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        int n = arr.size();

        for(int curr = n; curr > 1; curr--){
            int idx = find(arr.begin(), arr.end(), curr) - arr.begin();
            if(idx == curr - 1) continue;
            if(idx != 0){
                reverse(arr.begin(), arr.begin() + idx + 1);
                res.push_back(idx + 1);
            }
            reverse(arr.begin(), arr.begin() + curr);
            res.push_back(curr);
        }
        return res;
    }
};