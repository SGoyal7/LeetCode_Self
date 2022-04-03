
//SELF SOLUTION 1
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = letters.size();
        char res;
        
        if(letters[l-1] <= target) {
            return letters[0];
        }
        
        for(char c : letters) {
            if(c > target) {
                res = c;
                break;
            }
        }
        return res;
    }
};