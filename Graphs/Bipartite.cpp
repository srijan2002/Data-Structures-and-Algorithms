#include<bits/stdc++.h>
using namespace std;
#define sync ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long int lli;

bool isBipartite(lli i,bool vis[], vector<lli> adj[],lli col[], lli parent_col){
    vis[i]=true;
    
     if(parent_col==-1)
     col[i]=0;
     else
     col[i]=!parent_col;
     for(auto j:adj[i]){
         if(col[i]==col[j]){
            return false;
         }
         
        if(!vis[j])
        {   
            if(isBipartite(j,vis,adj,col,col[i]))
            return true;
            else return false;
        }
     }
      
    return true;
}
int main(){
    sync;
     lli n,m; cin>>n>>m;
   vector<lli> adj[n];
   for(lli i=0;i<m;i++)
   {
       lli x,y; cin>>x>>y; 
       
       adj[x].push_back(y);
       adj[y].push_back(x);
    
   }
   bool vis[n]={false}; 
   lli col[n];
   for(lli i=0;i<n;i++){
       col[i]=-1;
   }
   bool c = true;  
   for(lli i=0;i<n;i++){
      if(!vis[i]){
          if(isBipartite(i,vis,adj,col,-1))
          c=true;
          else{
              c=false;break;
          }
      }
   }
   if(c)
   cout<<"Bipartite"<<endl;
   else
   cout<<"Not Bipartite"<<endl;
    return 0;
}