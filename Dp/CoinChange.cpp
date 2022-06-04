class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
       int a[amount+1];
        for(int i=0;i<=amount;i++)
            a[i] = amount+1;
        
        a[0]=0;
         
        for(int i=1;i<=amount;i++){
            for(auto j:coins){
              if(i>=j)
                    a[i]= min(a[i],1+a[i-j]);
            }
        }
        if(a[amount]>=amount+1)
            return -1;
        else
            return a[amount];
    }
};