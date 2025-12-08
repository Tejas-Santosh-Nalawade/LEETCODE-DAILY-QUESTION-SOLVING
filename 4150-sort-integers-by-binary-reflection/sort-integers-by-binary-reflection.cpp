class Solution {
public:
  vector<int> sortByReflection(vector<int>& nums) {
    vector<long> v;
    for(int n: nums){
      long r = 0;
      for(int x = n; x; x>>=1) r = (r<<1) | (x & 1);
      v.push_back((r<<32) | n);
    }

    sort(v.begin(), v.end());
    
    vector<int> ans;
    long mask = (1L<<33) - 1;
    for(int n: v) ans.push_back((int)(n & mask));
    
    return ans;      
  }
};