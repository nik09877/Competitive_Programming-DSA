class Solution {
public:
    int minimumNumbers(int num, int k) 
    {
        if(num==0)
            return 0;
        for(int i=1;i<=10;i++){
            int x = k*i;
            if(x%10 == num%10){
                if(num-x>=0)
                    return i;
            }
        }
        return -1;
    }
};