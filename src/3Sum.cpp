#include "bits/stdc++.h"

using namespace std;

class Solution {
public:

    bool static compare(int a, int b) {
        if (abs(a) < abs(b))
            return true;
        else if (abs(a) == abs(b))
            return a < b;
        else
            return false;
    }

    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> answer;
        set<multiset<int>> ans;
        int len = nums.size();
        if (len < 3) {
            return answer;
        }
        vector<int> temp;
        set<int> reputation;
        sort(nums.begin(), nums.end(), compare);

        int z = nums[0];
        temp.push_back(z);
        for (int i = 1; i < len; ++i) {
            if (nums[i] != z) {
                temp.push_back(nums[i]);
                z = nums[i];
            } else {
                if (z != 0)
                    reputation.insert(z);
            }
//            cout << nums[i] << " ";
        }


//        for (auto n : temp) {
//            cout << n << " ";
//        }
//        cout << "   \n";
//
//        for (auto n : reputation) {
//            cout << n << " ";
//        }
//        cout << " \n";

        int count = 0;
        while (nums[count++] == 0);
//        cout<< count<<" \n";
        if (count >= 4) {
            ans.insert({0, 0, 0});
        }

        int t = 0;
        if (temp[0] == 0) {
            t++;
        }

//        cout<< "\n";
        len = temp.size();
        temp.push_back(0);
        for (int i = t; i < len; ++i) {
            for (auto var : reputation) {
                if (var * 2 == -temp[i]) {
                    ans.insert({var, var, temp[i]});
                }
            }
            if (t != 0 && temp[i] + temp[i + 1] == 0) {
                ans.insert({min(temp[i], temp[i + 1]), 0, max(temp[i], temp[i + 1])});
            }
            if (temp[i + 1] > 0) {
                for (int m = t, n = i; m < n;) {
                    while (temp[m] > 0 && m < n) {
                        m++;
                    }
                    while (temp[n] > 0 && m < n) {
                        n--;
                    }
                    if (m >= n)
                        break;
//                    cout << temp[m] << "     " << temp[n] << "    " << temp[i + 1] << " \n";
                    if (temp[m] + temp[n] == -temp[i + 1]) {
                        ans.insert({temp[m], temp[n], temp[i + 1]});
                        ++m;
                        --n;
                    } else if (temp[m] + temp[n] > -temp[i + 1]) {
                        ++m;
                    } else {
                        --n;
                    }
                }
            } else {
                for (int m = t, n = i; m < n;) {
//                        cout<< temp[m]<< "     " << temp[n]<< "    " << temp[i+1]<<" \n";
                    while (temp[m] < 0 && m < n) {
                        m++;
                    }
                    while (temp[n] < 0 && m < n) {
                        n--;
                    }
                    if (m >= n)
                        break;
//                        cout<< temp[m]<< "     " << temp[n]<< "    " << temp[i+1]<<" \n";
                    if (temp[m] + temp[n] == -temp[i + 1]) {
                        ans.insert({temp[m], temp[n], temp[i + 1]});
                        --n;
                        ++m;
                    } else if (temp[m] + temp[n] < -temp[i + 1]) {
                        ++m;
                    } else {
                        --n;
                    }
                }
            }

        }

        for (auto n : ans) {
            vector<int> ok;
            for (auto nn: n)
                ok.push_back(nn);
            answer.push_back(ok);
        }

        return answer;
    }


};

int main() {
    Solution solution = Solution();
//    vector<int> vec = {-1, 1, -2, -3, 4, 5, 0,0,0, -1, 2, 3, -4, -4, 1, -1, -6, 6, 6, -7, 8};
    vector<int> vec = {-1,-1,2};

    vector<vector<int> > ans = solution.threeSum(vec);


    for (auto n : ans) {
        cout << "\n";
        for (auto t : n) {
            cout << t << " ";
        }
    }
    return 0;
}
