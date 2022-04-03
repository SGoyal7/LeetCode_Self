//SELF Solution 1

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> freq;
        vector<int> res;
        
        
        for(int x : nums1) {
            freq[x]++;
        }
        
        for(int x : nums2) {
            if(freq[x] > 0) {
                res.push_back(x);
                freq[x]--;
            }
        }
        return res;
    }
};

//SOLUTION 2
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> res;
        int l1 = nums1.size();
        int l2 = nums2.size();
        
        int j = 0, i = 0;
        
        while( i < l1 && j < l2) {
            if(nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j]) {
                i++;
            }
            else if(nums1[i] > nums2[j]) {
                j++;
            }
        }
        return res;
    }
};