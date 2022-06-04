#include<bits/stdc++.h>
using namespace std;
#define sync ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long int lli;

int main(){
    sync;
    lli n,m; cin>>n>>m;

    vector<lli> dist(n+1,INT64_MAX);  vector<lli> dis(n+1,0);
    vector<pair<lli,lli>> graph[n+1];
    for(lli i=0;i<m;i++){
        lli u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w}); graph[v].push_back({u,w});
    }

    lli src; cin>>src;
    dist[src]=0;
    set<pair<lli,lli>> S;
     
    S.insert({0,src});
    while(!S.empty()){
        auto x = *(S.begin());
        S.erase(x);
        for(auto i:graph[x.second]){
            if(dist[i.first]>dist[x.second]+i.second)
            {
                S.erase({dist[i.first],i.first});
                 dist[i.first]= dist[x.second]+i.second;
                 dis[i.first]=dis[x.second]+1;
                  S.insert({dist[i.first],i.first});
            }
        }
    }
    for(lli i =0;i<=n;i++)
    {
        if(dist[i]==INT64_MAX)
        cout<<-1<<" ";
        else
        cout<<dist[i]<<" "<<dis[i]<<endl;
    }
    cout<<endl;
    return 0;

}