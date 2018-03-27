/*************************************************************************
	> File Name: 1005.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月26日 星期一 15时32分21秒
 ************************************************************************/

#include<bits/stdc++.h>
#define clr(x) memset(x,0,sizeof(x))
#define mp(x,y) make_pair(x, y)
using namespace std;

class Solution {
public:
    bool judge(string s) {
        int len = s.length()-1;
        if (len == 0) 
            return true;
        for (int i = 0; i < len; ++i) {
            //cout<< s[i]<< " "<< s[len-i]<< "\n";
            if (s[i] == s[len-i]) {
                if (i == len/2 || (i == len/2 -1 && len % 2 == 0)) {
                    //cout<< s;
                    return true;
                }
            } else {
                return false;
            }
        }
        return false;
    }

    string longestPalindrome(string s) {
        string ans = "";
        string temp = "";
        int maxm = 0;
        int i, j;
        for (i = 0; i < (int)s.length()-1; ++i) {
            temp = "";
            for (j = 0; j < 2; ++j) {
                temp += s[i+j];
            }
            int p = i;
            cout<< "temp: "<< temp<< "\n";
            if (judge(temp)) {
                int q = i+j-1;
                cout<< p<< " "<< q<< "\n";
                if (maxm < 2) {
                    maxm = 2;
                    ans = temp;
                }
                while(true) {
                    if (p-1>=0 && q+1 < (int)s.length()){
                        cout<< s[p-1]<< " "<< s[q+1]<< "\n";
                        if (s[p-1] == s[q+1]) {
                            p--;
                            q++;
                            temp = s[p] + temp+s[q];
                            if (q-p+1 > maxm) {
                                maxm = q-p+1;
                                ans = temp;
                            }
                        } else
                            break;
                    } else {
                        break;
                    }
                }
            }
            cout<< maxm<<"\n";
        }

        for (i = 0; i < (int)s.length()-2; ++i) {
            temp = "";
            for (j = 0; j < 3; ++j) {
                temp += s[i+j];
            }
            int p = i;
            cout<< "temp: "<< temp<< "\n";
            if (judge(temp)) {
                int q = i+j-1;
                cout<< p<< " "<< q<< "\n";
                if (maxm < 3) {
                    maxm = 3;
                    ans = temp;
                }
                while(true) {
                    if (p-1>=0 && q+1 < (int)s.length()){
                        cout<< s[p-1]<< " "<< s[q+1]<< "\n";
                        if (s[p-1] == s[q+1]) {
                            p--;
                            q++;
                            temp = s[p] + temp+s[q];
                            if (q-p+1 > maxm) {
                                maxm = q-p+1;
                                ans = temp;
                            }
                        } else
                            break;
                    } else {
                        break;
                    }
                }
            }
            cout<< maxm<<"\n";
        }
       
        if (maxm == 0)
            ans = s[0];
        return ans;
    }

    /*string longestPalindrome(string s) {*/
        //int len = s.length();
        //int mid = s.length();
        //string ans = "";
        //if (mid == 1) {
            //return  s;
        //} else {
            //mid ++;
            //while (mid--) {
                //cout<< mid<< "\n";
                //for (int i = 0; i < len-mid+1; ++i) {
                    //string temp = "";
                    //for (int j = 0; j < mid; ++j) {
                        //temp += s[i+j];
                    //}
                    //cout<< "    "<< temp<< "\n";
                    //if (judge(temp)) {
                        //ans = temp;
                        //return ans;
                        //break;
                    //}
                //}
            //}
        //}
        //return(ans);
    /*}*/
};

int main() {
    Solution s;
    cout<< s.longestPalindrome("bbbbb")<< "\n";
    //if (s.judge("bab")) {
        //cout<< "yes\n";
    //} else {
        //cout<< "false\n";
    //}
    return 0;
}
