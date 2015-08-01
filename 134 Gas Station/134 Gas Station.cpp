//
//  134 Gas Station.cpp
//  
//
//  Created by Apple on 15/8/1.
//
//

class Solution {
public:
    //If car starts at A and can not reach B. Any station between A and B can not reach B.(B is the first station that A can not reach.)
    //If the total number of gas is bigger than the total number of cost. There must be a solution.
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start(0), total(0), sum(0);
        for(int i = 0; i < gas.size() ; i++){
            if((sum = sum+gas[i]-cost[i])< 0){
                total += sum;
                start = i+1;
                sum = 0;
            }
        }
        return total+sum>=0 ? start : -1;
    }
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = gas.size()-1;
        int end = 0;
        int sum = gas[start] - cost[start];
        while (start > end) {
            if (sum >= 0) {
                sum += gas[end] - cost[end];
                ++end;
            }
            else {
                --start;
                sum += gas[start] - cost[start];
            }
        }
        return sum >= 0 ? start : -1;
    }
};