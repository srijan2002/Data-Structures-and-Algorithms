class Solution {
public:
    typedef priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> MinHeap;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<int> dist(n+1,INT32_MAX);  
    vector<int> stops(n+1,INT32_MAX);      
    vector<pair<int,int>> graph[n+1];
        MinHeap minheap;
        for(auto i:flights){
            graph[i[0]].push_back({i[1],i[2]});
        }
        dist[src]=0; stops[src]=0;
     
    minheap.push({0,src,0});
    while(!minheap.empty()){
        auto x = (minheap.top());
        minheap.pop();
        if(get<1>(x) == dst)
            return get<0>(x);
        if(get<2>(x)==k+1)
            continue;
        
        for(auto i:graph[get<1>(x)]){
            int nextstops = get<2>(x)+1;
            int nextdist = get<0>(x)+i.second;
            if(dist[i.first]>nextdist)
            {
                
                
                 dist[i.first]= nextdist;
                 stops[i.first] = nextstops; 
                  minheap.push({nextdist,i.first,nextstops});
            }
            else if(nextstops<stops[i.first]){
                stops[i.first] = nextstops;
                
                minheap.push({nextdist,i.first,nextstops});
            }
        }
    }
         
       return -1; 
    }
};