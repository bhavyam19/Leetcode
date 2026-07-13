class Solution {
public:
    int division(vector<int>& nums, int divisor){
        int result = 0;
        for(int i=0;i<nums.size();i++){
            result += ceil((double)nums[i]/divisor);
        }
        return result;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = *max_element(nums.begin(),nums.end());
        int low = 1, high = n;
        while(low<=high){
            int mid = (low+high)/2;
            int result = division(nums,mid);
            if(result<=threshold){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};