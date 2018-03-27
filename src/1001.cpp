/*************************************************************************
	> File Name: 1001.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月26日 星期一 00时01分18秒
 ************************************************************************/
#include<bits/stdc++.h>
#define mp(x, y) make_pair(x, y)
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> temp;
        unordered_map<int, int>::iterator it;
        for (int i = 0; i < (int) nums.size(); ++i) {
            it = temp.find(target-nums[i]);
            if (it != temp.end()) {
                ans.push_back(it->second);
                ans.push_back(i); 
                return ans;
            } else {
                temp.insert(mp(nums[i], i));
            }
        }
        //for (int i = 0; i < int (nums.size()-1); ++i) {
            //for (int j = i+1; j < int (nums.size()); ++j) {
                ////cout<< nums[i] << " "<< nums[j]<< "\n";
                //if (nums[i] + nums[j] == target) {
                    ////cout<< i<< " "<< j<< "\n";
                    //ans.push_back(i);
                    //ans.push_back(j);
                    //return ans;
                //}
            //}
        //}
        //return nums;
    }
};

int main() {
    vector<int> v;
    v.push_back(2);
    v.push_back(7);
    v.push_back(11);
    v.push_back(15);
    Solution s = Solution();
    vector<int> ans = s.twoSum(v, 9);
    for (int i = 0; i < int(ans.size()); ++i) {
        cout<< ans[i]<< " ";
    }
    cout<< "\n";
    return 0;
}
