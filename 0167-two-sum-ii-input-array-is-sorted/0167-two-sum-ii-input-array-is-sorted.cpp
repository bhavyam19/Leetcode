class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size()-1;
        while(i<j) {
            int ans = numbers[i]+numbers[j];
            if (target==ans){
                break;
            }else if(ans<target) {
                i++;
            }else{
                j--;
            }
        }
        return{i+1,j+1};
    }
};