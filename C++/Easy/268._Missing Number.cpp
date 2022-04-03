//SELF Solution1
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int l = nums.size();
        int n = 0, res = 0;
        
        for(int x : nums) {
            if(n == x) {
                n++;
            }
            else {
                return n;
            }
        }
        return l;
    }
};

//APPROACH 2
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int x1=0;int x2=0;
        for(int i=0;i<n;i++){
            x1=x1^nums[i]; // let say array is 3,0,1 then x1 will store  3^0^1 
            x2=x2^(i+1);     // here x2 will store 1^2^3
        }
        return x1^x2;//  a^a=0 ,so the number present both in x1 and x2 will cancel out(become zero ) and the element which is not present in x1 . i.e 2 will be returned by the function.
    }
};

//APPROACH 3

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
       int sum1 = accumulate(nums.begin(), nums.end(), 0);
        int sum2 = 0;
        
        int n = nums.size();
        
        sum2 = n*(n+1)/2;
        return sum2 - sum1;
    }
};