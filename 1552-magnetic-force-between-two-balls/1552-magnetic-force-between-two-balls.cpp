class Solution {
public:
    bool canPlaceBalls(vector<int>& position, int m, int force){
        int balls = 1;
        int last = position[0];
        for(int i=1;i<position.size();i++){
            if (position[i]-last>=force){
                balls++;
                last = position[i];
            }
        }
        return (balls>=m);
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int low = 1, high = position[position.size()-1] - position[0];
        while(low<=high){
            int mid = (low+high)/2;
            if(canPlaceBalls(position,m,mid)){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return high;
    }
};