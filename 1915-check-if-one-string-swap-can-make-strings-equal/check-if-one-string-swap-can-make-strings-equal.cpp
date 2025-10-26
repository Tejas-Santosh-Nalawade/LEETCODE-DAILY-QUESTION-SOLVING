class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int>diff_indices;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                diff_indices.push_back(i);
            }
        }
        if(diff_indices.empty()){
            return true;
        }

        if(diff_indices.size() == 2){
            int i = diff_indices[0];
            int j = diff_indices[1];

            if(s1[i] == s2[j] && s1[j] == s2[i]){
                return true;
            }
        }
        return false;

    }
};