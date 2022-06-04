class Solution {
public:
    vector<vector<string>> res; vector<string> b;
    
    // for neg diag, r-c is constant, for pos diag, r+c is constant
    set<int> col; set<int> pos; set<int> neg;
    void backtrack(int r, int n){
        //BASE CASE
        if(r==n){
            // vector<string> copy = b;
            res.push_back(b);   // board is complete, add to result
            return;
        }
        for(int i=0;i<n;i++){
            // CHECKING IF VALIF POSITION
            if(col.find(i)!=col.end() || pos.find(r+i)!=pos.end() || neg.find(r-i)!=neg.end())
                continue;
            
            // ADDING THE POSITION OF NEW QUEEN
            b[r][i]='Q';
            col.insert(i); pos.insert(r+i); neg.insert(r-i);
            backtrack(r+1,n);
            
            //CLEANUP
            
            b[r][i]='.';
            col.erase(i); pos.erase(r+i); neg.erase(r-i);
            
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string s="";
        for(int i=0;i<n;i++)
            s+='.';
        for(int i=0;i<n;i++)
            b.push_back(s);
        
      backtrack(0,n);
        return res;
    }
};