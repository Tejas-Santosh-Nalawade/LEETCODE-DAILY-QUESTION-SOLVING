class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        vector<int> result;

        for(int i=0; i<order.size(); i++){
            if(binary_search(friends.begin(), friends.end(), order[i])){
                result.push_back(order[i]);
            }
        }

        return result;
    }
};