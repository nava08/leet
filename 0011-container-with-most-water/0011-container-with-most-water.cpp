class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_water = 0;
        int left = 0;
        int right = height.size() - 1;
        
        while (left < right) {
            // Calculate the current width
            int width = right - left;
            
            // Calculate the area with the limiting shorter line
            int current_water = min(height[left], height[right]) * width;
            
            // Keep track of the maximum area found so far
            max_water = max(max_water, current_water);
            
            // Move the pointer that points to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return max_water;
    }
};