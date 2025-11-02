/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left=0,right=n;
        while(left<=right){
            long mid=(1LL+left+right)/2;
            int a=guess(mid);
            if(a==0) return mid;
            else if(a==1) left=mid+1;
            else right=mid-1;
        }
        return 0;
    }
};