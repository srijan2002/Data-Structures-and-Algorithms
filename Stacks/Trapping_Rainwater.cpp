class Solution {
public:
    int trap(vector<int>& height) {
       stack<int> S; int ans = 0;
        int n = height.size();
        for(int i=0;i<n;i++){
           while(!S.empty() && height[i]>height[S.top()]){
               int top = S.top();
               S.pop();
               if(S.empty())
                   continue;
               int dist = i - S.top() -1;
               int h = min(height[i],height[S.top()]) - height[top];
               
               // min(height[i],height[S.top()])-> check minimum of the current greater element and the second element of stack. In between lies a block smaller than both(as top element is of decreasing stack and current element is greater than it as it enters the while loop through the condition)
               ans+=dist*h;
               
           }
            S.push(i);
        }
        return ans;
    }
};