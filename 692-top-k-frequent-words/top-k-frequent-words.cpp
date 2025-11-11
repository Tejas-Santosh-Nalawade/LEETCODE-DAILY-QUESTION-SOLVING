class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mpp;
        for(auto &it : words) mpp[it]++;
        vector<pair<string,int>> temp(mpp.begin(), mpp.end());
        auto comp = [](const pair<string,int> x, const pair<string,int> y) 
        {
            if(x.second == y.second) 
                return x.first < y.first;  
            return x.second > y.second;    
        };

        sort(temp.begin(), temp.end(), comp);

        vector<string> res;
        for(int i=0; i<k; i++) 
        {
            res.push_back(temp[i].first);
        }
        return res;
    }
};