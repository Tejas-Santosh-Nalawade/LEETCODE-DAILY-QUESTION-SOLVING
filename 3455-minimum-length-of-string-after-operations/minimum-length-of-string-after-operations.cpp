class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>charfreq;
        for(char currentchar:s ){
            charfreq[currentchar]++;
        }
        int deleteCount=0;
        for(auto& pair: charfreq){
            int freq=pair.second;
            if(freq%2==1){
                deleteCount+=freq-1;
            }
            else{
                deleteCount+=freq-2;
            }
        }
        return s.length()-deleteCount;
    }
};