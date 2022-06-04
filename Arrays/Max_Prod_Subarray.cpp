class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a=1,b=1;
        int mx = INT32_MIN;
       if(nums[0]>0)
       {
           a=a*nums[0]; b=b*nums[0];
           mx=max(mx,a);
       }
        else if(nums[0]<0){
              a=a*nums[0]; b=b*nums[0];
           mx=max(mx,a);
        }
        else {
            mx=0;
        }
        for(int i=1;i<nums.size();i++){
            
            if(nums[i]>0)
           {
         a=max(a*nums[i],max(b*nums[i],nums[i])); 
           mx=max(mx,a);
            if(b<0)
                b=b*nums[i];
           }
            else if(nums[i]<0){
                int x = a;
                a=max(a*nums[i],max(b*nums[i],nums[i])); 
                mx=max(mx,a); 
               b=min(x*nums[i],min(b*nums[i],nums[i]));
                // cout<<mx<<" "<<b<<endl;
            }
            else{
                a=1; b=1; mx=max(0,mx);
            }
            
        }
        return mx;
        
    }
};