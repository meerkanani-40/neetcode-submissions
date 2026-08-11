class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxWater = 0;
        int st = 0;
        int end = heights.size()-1;

        while(st < end){
            int water = min(heights[st], heights[end])*(end-st);
            maxWater = max(maxWater, water);

            heights[st] < heights[end] ? st++ : end--;
        }

        return maxWater;
    }
};
