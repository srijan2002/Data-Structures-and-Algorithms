#include<bits/stdc++.h>
using namespace std;
#define sync ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long int lli;
int main(){
    sync;
    lli ans=0;
     lli n,m;cin>>n>>m;
     lli p,q; cin>>p>>q;
     vector<lli> adj[n+1];
     for(lli i=0;i<m;i++){
         lli x,y; cin>>x>>y;
         adj[x].push_back(y);
     }
      queue<vector<lli>> Q;   vector<vector<lli>> V;

      vector<lli> temp; temp.push_back(p); Q.push(temp);
      while(!Q.empty()){
          vector<lli> t = Q.front(); Q.pop();
          lli x = t[t.size()-1];
          if(x==q){
             V.push_back(t);
          }else{
              for(auto i:adj[x]){
                  vector<lli> y = t;
                  y.push_back(i);
                  Q.push(y);
              }
          }
      }
      // PRINT VECTOR V
      for(auto i:V)
      {
          for(auto j:i)
          cout<<j<<" ";

          cout<<endl;
      }
    
    return 0;
}