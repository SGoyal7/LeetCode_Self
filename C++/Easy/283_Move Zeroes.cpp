//SELF Solution1
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = nums.size();
        vector<int> ind;
        
        for(int i = 0; i < l; i++) {
            if(nums[i] == 0) {
                ind.push_back(i);
            }
            else {
                if(!ind.empty()) {
                    swap(nums[ind[0]],nums[i]);
                    ind.erase(ind.begin());
                    ind.push_back(i);
                }
            }
        }
    }
};

//SELF Solution 2
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = nums.size();
        int count = 0;
        for(int x : nums) {
            if(x == 0) {
                count++;
            }
        }
        
        for(int i = 0; i < l;) {
            if(nums[i] == 0 && count > 0) {
                nums.erase(nums.begin() + i);
                nums.push_back(0);
                count--;
            }
            else {
                i++;
            }
            
        }
    }
};