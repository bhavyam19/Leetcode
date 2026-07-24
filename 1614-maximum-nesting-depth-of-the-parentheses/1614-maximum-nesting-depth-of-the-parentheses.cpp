class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int ans = 0;
        for(char x : s){
            if(x == '(') cnt++;
            else if(x == ')') cnt--;
            ans = max(ans,cnt);
        }
        return ans;
    }
};