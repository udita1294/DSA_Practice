class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalEarning = accumulate(gas.begin(),gas.end(),0);
        int spend = accumulate(cost.begin(),cost.end(),0);
        if(totalEarning < spend) return -1;

        int total = 0;
        int resIndex = 0;

        for(int i=0;i<gas.size();i++){
            total = total + gas[i] - cost[i];
            if(total < 0){
                total = 0;
                resIndex = i+1;
            }
        }
        return resIndex;
    }
};