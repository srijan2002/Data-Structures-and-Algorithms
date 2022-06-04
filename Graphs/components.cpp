#include<bits/stdc++.h>
using namespace std;
#define sync ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long int lli;

lli comp(lli i, vector<lli> adj[], bool vis[]){
   if(vis[i])
   return 0;
   vis[i]=true;
   lli ans =1;
   for(auto j:adj[i]){
      if(!vis[j])
      ans+=comp(j,adj,vis);
   }
   return ans;
}
int main(){
    sync;
      lli n,m; cin>>n>>m;
   vector<lli> adj[n];
   for(lli i=0;i<m;i++)
   {
       lli x,y; cin>>x>>y; 
       
       adj[y].push_back(x);
       adj[x].push_back(y);
    
   }
   bool vis[n]={false};
   vector<lli> components;
   for(lli i=0;i<n;i++){
       if(!vis[i]){
           components.push_back(comp(i,adj,vis));
       }
   }
   for(auto i:components){
       cout<<i<<" ";
   }
   cout<<endl;
    return 0;
}