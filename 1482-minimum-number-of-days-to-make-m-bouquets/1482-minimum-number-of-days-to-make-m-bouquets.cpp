class Solution {
public:
    bool stack(vector<int>& bloomDay, int m, int k, int days){
        int cnt = 0;
        int ans = 0;
        for(int i=0;i<bloomDay.size();i++){
            if(days>=bloomDay[i]){
                cnt++;
            }else{
                ans+=(cnt/k);
                cnt = 0;
            }
        }
        ans+=(cnt/k);
        return ans>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long result = m*1LL*k*1LL;
        if(result > bloomDay.size()) return -1;
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid = (low+high)/2;
            if(stack(bloomDay,m,k,mid)){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};