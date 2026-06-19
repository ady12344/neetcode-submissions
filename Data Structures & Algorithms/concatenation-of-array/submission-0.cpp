class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> vect(nums.size() * 2);
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            vect[i] = nums[i];
            vect[i + n] = nums[i];
        }
        return vect;

    }
};