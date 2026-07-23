class Solution {
public:
    bool canMakeTrips(vector<int>& time, int totalTrips, long long reqTime ){
        long long trips = 0;
        for (int i=0;i<time.size();i++){
            trips+=(reqTime/time[i]);
        }
        return (trips>=totalTrips);
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 1;
        long long high = 1e14;
        while(low<=high){
            long long mid = low + (high-low)/2;
            if(canMakeTrips(time,totalTrips,mid)){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};