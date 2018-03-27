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
        //判断是否是回文字串
        int len = s.length()-1;
        if (len == 0) 
            return true;
        for (int i = 0; i < len; ++i) {
            //cout<< s[i]<< " "<< s[len-i]<< "\n";
            if (s[i] == s[len-i]) {
                if (i == len/2 || (i == len/2 -1 && len % 2 == 0)) {
                    //此处因为串的长度可能有奇偶之分，判断复杂，逻辑不清晰
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
        string temp = "";   //记录的中间串
        int maxm = 0;
        int i, j;
        for (i = 0; i < (int)s.length()-1; ++i) {
            // 注意此处是 i < s.length()-1 而不是 -2
            temp = "";
            // 获取一个两位的子串
            for (j = 0; j < 2; ++j) {
                temp += s[i+j];
            }
            int p = i;
            cout<< "temp: "<< temp<< "\n";
            // 判断其是否是回文字串,p q 存的是当前串头和串尾的位置
            if (judge(temp)) {
                int q = i+j-1;
                cout<< p<< " "<< q<< "\n";
                // 此处比较是为了判断当前的maxm是不是0,如果<2那么显然是0，
                // 需要将ans替换成现在的temp，并更新maxm的值
                if (maxm < 2) {
                    maxm = 2;
                    ans = temp;
                }
                // 通过向左右同时扩张寻找更大的回文字串
                while(true) {
                    // 如果超出了字符串的边界就停止寻找 
                    if (p-1>=0 && q+1 < (int)s.length()){
                        cout<< s[p-1]<< " "<< s[q+1]<< "\n";
                        if (s[p-1] == s[q+1]) {
                            p--;
                            q++;
                            temp = s[p] + temp+s[q];
                            // 没找到一次就更新，r全找完了再更新可能会快一点
                            /*if (q-p+1 > maxm) {*/
                                //maxm = q-p+1;
                                //ans = temp;
                            /*}*/
                        } else
                            break;
                    } else {
                        break;
                    }
                }
                if (q-p+1 > maxm) {
                                maxm = q-p+1;
                                ans = temp;
                            }
            }
            cout<< maxm<<"\n";
        }
        
        // 原理同上，恕不赘述
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
                            /*if (q-p+1 > maxm) {*/
                                //maxm = q-p+1;
                                //ans = temp;
                           /* }*/
                        } else
                            break;
                    } else {
                        break;
                    }
                }
                if (q-p+1 > maxm) {
                                maxm = q-p+1;
                                ans = temp;
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
    cout<< s.longestPalindrome("aaaaaaa")<< "\n";
    //if (s.judge("bab")) {
        //cout<< "yes\n";
    //} else {
        //cout<< "false\n";
    //}
    return 0;
}
