class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 1, high = num;
        while(low<=high){
            int mid = low + (high-low)/2;
            long long prod = 1LL*mid*1LL*mid;
            if(prod==num){
                return true;
            }else if(prod>num){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return false;
    }
};