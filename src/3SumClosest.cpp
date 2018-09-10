#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 99999999;
        int len = nums.size();
        for (int i = 0; i < len-2; i++) {
            int j = i + 1;
            int k = len - 1;
            while (j < k) {
//                cout<< "    "<<nums[i]<< "   "<< nums[j]<< "   "<< nums[k]<< "\n";
                int dec = nums[i] + nums[j] + nums[k] - target;
//                cout<< dec<< "  "<<ans-target<<"      " << ans<< "\n";
                if (abs(dec) < abs(ans-target))
                    ans = dec+target;
                if (dec == 0) {
                    return ans;
                } else if (dec < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return ans;
    }

};

int main() {
    Solution solution = Solution();
//    vector<int> vec = {-1, 1, -2, -3, 4, 5, 0, 0, 0, -1, 2, 3, -4, -4, 1, -1, -6, 6, 6, -7, 8};
    vector<int> vec = {0,2,1,-3};

    int ans = solution.threeSumClosest(vec, 1);

    cout << ans << "\n";
    return 0;
}
