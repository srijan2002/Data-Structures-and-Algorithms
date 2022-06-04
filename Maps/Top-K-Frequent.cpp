class Solution {
public:

// TO SORT USING COMPARATOR FUNCTION
  static  bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    // if frequencies of two elements are same
    // then the larger number should come first
    if (p1.second == p2.second)
        return p1.first > p2.first;
  
    // sort on the basis of decreasing order
    // of frequencies
    return p1.second > p2.second;
}
    vector<int> topKFrequent(vector<int>& nums, int k) {
          vector<int> res;
        int n = nums.size(); unordered_map<int,int> M;
        for(int i=0;i<n;i++)
            M[nums[i]]++;
              
         vector<pair<int,int>> V(M.begin(),M.end());
              sort(V.begin(),V.end(),cmp); // sort using comparator function
              
           for(int i = 0;i<k;i++)
              res.push_back(V[i].first);  // first element of the pair i.e the number
              
              return res;
    }  
};