class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int n = nums.size();
        int maxLen = 0;
        for(int i = 0; i < n; i++){
            int x = nums[i];
            if(s.find(x-1) != s.end()){
                continue;
            }

            int len = 1;
            while(s.find(x+1) != s.end()){
                x = x+1;
                len++;
            }

            maxLen = max(maxLen, len);
        }

        return maxLen;
    }
};
