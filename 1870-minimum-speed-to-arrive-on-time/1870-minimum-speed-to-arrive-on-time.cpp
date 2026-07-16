class Solution {
public:
    bool totalHours(vector<int>& dist, int speed, double hour ){
        double tH = 0;
        for(int i=0;i<dist.size()-1;i++){
            tH += ceil((double)dist[i]/speed);
        }
        tH += (double)dist.back()/speed;
        return (tH<=hour);
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1, high = 1e7;
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(totalHours(dist,mid,hour)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};