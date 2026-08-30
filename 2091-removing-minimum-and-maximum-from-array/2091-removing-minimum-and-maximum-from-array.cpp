class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return 1;
        int mini  = *min_element(nums.begin(),nums.end());
        int minIndex = -1;
        int maxi = *max_element(nums.begin(),nums.end());
        int maxIndex = -1;

        for(int i=0;i<n;i++){
            if(nums[i] == mini){
                minIndex = i;
            }
            if(nums[i] == maxi){
                maxIndex = i;
            }
        }
        int remFrontBack = min(((minIndex+1) + (n - maxIndex)), ((maxIndex + 1) + (n - minIndex)));
        int bothFront = 0;
        if(maxIndex > minIndex){
            bothFront = maxIndex + 1;
        }else{
            bothFront = minIndex + 1;
        }

        int bothBack = 0;
        if(minIndex < maxIndex){
            bothBack = n - minIndex ;
        }else{
            bothBack = n - maxIndex;
        }

        return min(bothBack, min(remFrontBack,bothFront));
    }
};