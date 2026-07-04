class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int refillA = 0;
        int refillB = 0;
        int i = 0;
        int j = plants.size()-1;
        int capacityA1 = capacityA;
        int capacityB1 = capacityB;
        while(i<j) {
            if (plants[i]<=capacityA1 && plants[j]<=capacityB1) {
                capacityA1-=plants[i];
                capacityB1-=plants[j];
                i++;
                j--;
            }else if (plants[i]>capacityA1 && plants[j]>capacityB1){
                refillA+=1;
                refillB+=1;
                capacityA1 = capacityA;
                capacityB1 = capacityB;
                capacityA1-=plants[i];
                capacityB1-=plants[j];
                i++;
                j--;
            }else if (plants[i]>capacityA1 && plants[j]<=capacityB1){
                refillA+=1;
                capacityA1 = capacityA;
                capacityA1-=plants[i];
                capacityB1-=plants[j];
                i++;
                j--;
            }else if (plants[i]<=capacityA1 && plants[j]>capacityB1){
                refillB+=1;
                capacityB1 = capacityB;
                capacityB1-=plants[j];
                capacityA1-=plants[i];
                i++;
                j--;
            }
        }
        if (i==j) {
            if (capacityA1>=capacityB1){
                if (capacityA1<plants[i]){
                    refillA+=1;
                }
            }else{
                if (capacityB1<plants[j]){
                    refillB+=1;
                }
            }
        }
        return refillA+refillB;
    }
};