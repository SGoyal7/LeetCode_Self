//SOLUTION 1   SELF
//O(N^2)
vector<string> summaryRanges(vector<int>& nums) {
    int l = nums.size();
    vector<string> res;
    
    if(l == 0) {
        return res;
    }
    
    int s = 0, e = 0;
    for(int i = 0; i < l; ) {
        s = i, e = i;
        int w = 1;
        while(((e+1) < l) && ((nums[e]+1) == nums[e+1])) {
            e++;
            w++;
            //cout <<"e: " <<e << " w: " <<w <<endl;
        }
        if(w > 1) {
            res.push_back(to_string(nums[s]) + "->" + to_string(nums[e])); 
        }
        else {
            res.push_back(to_string(nums[s]));
        }
        i += w;
        
    }
    return res;
}


//Solution 2
//O(N)

 vector<string> summaryRanges(vector<int>& nums) {
        int l = nums.size();
        vector<string> res;
        vector<int> miss;
        
        if(l == 0) {
            return res;
        }
        int s = 0, e = 0;
        
        for(int i = 0; i < l; i++) {
            if(i == l-1 || (nums[i]+1 != nums[i+1])) {
                e = i;
                if(s != i) {
                    res.push_back(to_string(nums[s]) + "->" + to_string(nums[e])); 
                }
                else {
                    res.push_back(to_string(nums[s]));
                }
                if(i != l-1) {
                    s = i + 1;
                }
            }
        }
        
        return res;
    }