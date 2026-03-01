class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        int freq[101] ={0};

        for(int num:nums){
            freq[num]++;
        }

        vector<int>values;

        for(int i=0; i<=100; i++){
            if(freq[i] > 0){
                values.push_back(i);
            }
        }

        if(values.size() < 2) return {-1,-1};

        for(int i=0; i<values.size() - 1; i++){
            int x = values[i];
            int fx = freq[x];

            for(int j=i+1; j<values.size(); j++){
                int y = values[j];
                if(freq[y] != fx){
                    return {x,y};
                }
            }
        }
        return{-1,-1};


    }
};