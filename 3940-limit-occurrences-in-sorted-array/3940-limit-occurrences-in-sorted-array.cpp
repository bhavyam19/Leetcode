class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        int counter = 0;
        vector<int> ans;
        int el = nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]==el){
                counter++;
            }else{
                el = nums[i];
                counter = 1;
            }
            if (counter<=k){
                ans.push_back(nums[i]);
            }
        }
        return ans;    
    }
};