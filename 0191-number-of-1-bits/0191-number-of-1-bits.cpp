class Solution {
public:
    int hammingWeight(int n) {
        int count=0;
        while(n!=0){
            //check last digit
            if(n&1){
                count++;
            }
            n=n>>1;
        }
        return count;
    }
};