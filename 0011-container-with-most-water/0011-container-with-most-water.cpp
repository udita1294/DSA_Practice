class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i  = 0;
        int j = n-1;
        int maxArea = INT_MIN;

        while(i < j){
            int base = j - i;
            int Area =  min(height[i],height[j])*base;
            maxArea = max(maxArea,Area);

            if(height[i] < height[j]){
                i++;
            }else{
                j--;
            }
        }
        return maxArea;
    }
};