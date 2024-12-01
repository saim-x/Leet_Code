
class Solution {
public:
    bool isPowerOfFour(int n) { 
        int i = 0;
        if(n<1){
            return false;
        }
        while(pow(4, i)<=n){
            if(pow(4, i) == n){
                return true;
            }
            i++;
        }
        return false;
     }

};