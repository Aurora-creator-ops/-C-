class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ret=0;
        vector<bool>isFull(baskets.size(),true);
        for(int i=0;i<fruits.size();i++){
            int size=fruits[i];
            for(int j=0;j<baskets.size();j++){
                if(baskets[j]>=size && isFull[j]){
                    isFull[j]=false;
                    ret++;
                    break;
                }
            }
        }
        return fruits.size()-ret;
    }
};