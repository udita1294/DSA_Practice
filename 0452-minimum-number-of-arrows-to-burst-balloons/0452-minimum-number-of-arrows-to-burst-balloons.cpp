class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end());
        vector<int>prev = points[0];
        int count = 1;
        for(int i=1;i<n;i++){
            int currentstartpoint = points[i][0];
            int currentendpoint = points[i][1];
            int prevstartpoint = prev[0];
            int prevendpoint = prev[1];

            if(currentstartpoint > prevendpoint){
                count++;
                prev = points[i];
            }else{
                prev[0] = max(prevendpoint,currentstartpoint);
                prev[1] = min(currentendpoint,prevendpoint);
            }
        }
        return count;
    }
};