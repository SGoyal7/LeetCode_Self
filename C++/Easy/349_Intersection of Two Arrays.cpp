//SELF Solution1

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> freq;
        int l = nums2.size();
        vector<int> res;
        
        for(int x : nums1) {
            freq[x] = 1;
        }
        
        for(int x : nums2) {
            if(freq[x] > 0) {
                freq[x] = 0;
                res.push_back(x);
            }
        }
        return res;
    }

//C++ solution using Binary Search
    vector<int> bSearch(vector<int> a1, vector<int> a2){
        vector<int> res;
        for(int i=0;i<a1.size();i++){
            int s = 0;
            int e = a2.size()-1;
            while(s<=e){
                int mid = s+(e-s)/2;
                if(a2[mid] == a1[i]){
                    if(find(res.begin(),res.end(), a2[mid])!=res.end())
                        break;
                    res.push_back(a2[mid]);
                    break;
                }
                else if(a2[mid]>a1[i])
                    e = mid-1;
                else
                    s = mid+1;
            }
        }
        return res;
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        if(n1<n2)
            return bSearch(nums1,nums2);
        else
            return bSearch(nums2,nums1);
    }