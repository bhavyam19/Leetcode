class Solution {
public:  
    bool canDivide(vector<int>& candies, long long k, long long group){

        long long sum = 0;

        for(int i=0;i<candies.size();i++){
            sum+=(candies[i]/group);
        }
        return (sum>=k);
    }
    int maximumCandies(vector<int>& candies, long long k) {

        if (accumulate(candies.begin(),candies.end(),0LL)<k) return 0;

        long long low = 1;
        long long high = *max_element(candies.begin(),candies.end());

        while(low<=high){

            long long mid = low + (high-low)/2;

            if(canDivide(candies,k,mid)){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return high;
    }
};