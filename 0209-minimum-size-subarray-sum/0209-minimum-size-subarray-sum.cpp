class Solution {
public:
    bool possible(vector<int>& nums, int target, int len){
        int n = nums.size();
        long long sum = 0;
        for(int i=0;i<len;i++){
            sum+=nums[i];
        }if(sum>=target) return true;
        for(int i=len;i<n;i++){
            sum+=nums[i];
            sum-=nums[i-len];
            if (sum>=target){
                return true;
            }
        }
        return false;
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 1;
        int high = nums.size();
        int ans = 0;
        while(low<=high){
            int mid = low+ (high-low)/2;
            if(possible(nums,target,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};