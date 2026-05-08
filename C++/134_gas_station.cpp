#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> 
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int i = 0;

        while (i < n) {
            int gas_rest = 0;
            int cnt = 0;

            while (cnt < n) {
                int now_pos = (i + cnt) % n;

                gas_rest += gas[now_pos];
                gas_rest -= cost[now_pos];

                if (gas_rest < 0) {
                    break;
                }

                cnt++;
            }

            if (cnt == n) {
                return i;
            } else {
                i = i + cnt + 1;
            }
        }

        return -1;
    }
};