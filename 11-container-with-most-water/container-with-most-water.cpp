class Solution {
public:
    int maxArea(vector<int>& height) {  
        int n = height.size();
        int low = 0, high = n - 1;

        int maxHeight = 0;
        while(low  < high){
            int width = high - low;
            int minHeight = min (height[low],height[high]);
            int currwater  = width  * minHeight;
            maxHeight = max(currwater, maxHeight);
            if(height[low] < height[high]){
                low++;
            }
            else{
                high--;
            }
        }
        return maxHeight;
    }
};