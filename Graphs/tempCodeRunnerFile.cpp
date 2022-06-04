  lli x = adj[i][0];
       lli y = adj[i][1];
       lli a = find_set(x,parent); lli b = find_set(y,parent);
       if(a==b){
           cycle=true; break;
       }
       else{
           union_sets(a,b,parent,size);
       }
