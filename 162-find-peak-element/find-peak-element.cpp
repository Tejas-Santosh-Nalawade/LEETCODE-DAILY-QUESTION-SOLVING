class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int start = 1;
        int end = arr.size() - 2;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1]) {
                return mid;
            }
            if (arr[mid] < arr[mid + 1]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

       
        if (arr.size() == 1 || arr[0] > arr[1]) return 0;
        if (arr[arr.size() - 1] > arr[arr.size() - 2]) return arr.size() - 1;

        return -1;
    }
};