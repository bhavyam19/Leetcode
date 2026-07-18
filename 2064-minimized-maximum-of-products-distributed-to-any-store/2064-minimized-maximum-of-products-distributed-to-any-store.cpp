class Solution {
public:
    bool storesRequired(int n, vector<int>& quantities, int ways ){
        int ans = 0;
        for(int i=0;i<quantities.size();i++){
            ans+=ceil((double)quantities[i]/ways);
        }
        return (ans<=n);
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1, high = 1e6;
        while(low<=high){
            int mid = (low+high)/2;
            if(storesRequired(n,quantities,mid)){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};