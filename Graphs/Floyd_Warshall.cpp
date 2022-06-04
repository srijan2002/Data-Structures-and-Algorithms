class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int adj[n][n];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)
                    adj[i][j]=0;
                else
                    adj[i][j]=INT32_MAX;
            }
        }
        for(auto i:edges)
            {adj[i[0]][i[1]]=i[2]; adj[i[1]][i[0]]=i[2];}
        
        // for(int i=0;i<n;i++)
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
              for(int j=0;j<n;j++){
                   if(adj[i][k]==INT32_MAX || adj[k][j]==INT32_MAX)
                       continue;
                   else if(adj[i][k]+adj[k][j]<adj[i][j])
                       adj[i][j]= adj[i][k]+adj[k][j];
               }
            }
        }
        int c=0; int m = INT32_MAX; int x =-1;
        for(int i=0;i<n;i++){
            c=0;
            for(int j=0;j<n;j++){
                 if(i!=j && adj[i][j]<=distanceThreshold)
                     c++;
                     
            }
            if(m>=c){
                m=c;
                x=i;
            }
        }
       
         
        
        return x;
        
    }
};