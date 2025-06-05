class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> chains;
        unordered_set<int> hs;
        for(int &ele: nums)
        {
            hs.insert(ele);
        }
        int max = 0;
        for(int& ele: nums)
        {
            if(hs.contains(ele- 1)) continue;
            if(chains.contains(ele)) continue;
            chains.insert(ele);
            int curr = 1;
            for(int next = ele + 1; hs.contains(next); next++ )
            {
                curr++;
            }
            if(curr > max) max = curr;
        }
        return max;

    }
};