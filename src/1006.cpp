/*************************************************************************
	> File Name: 1006.cpp
	> Author: 
	> Mail: 
	> Created Time: 2018年03月29日 星期四 11时04分43秒
 ************************************************************************/

#include<bits/stdc++.h>
#define clr(x) memset(x,0,sizeof(x))
#define mp(x,y) make_pair(x, y)
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        //int temp[numRows];
        //int add[numRows];
        string ans = "";
        //clr(add);
        /*for (int i = 0; i < numRows-1; ++i) {*/
            //temp[i] = i;
            //add[i] = (numRows-i-1)*2;
        //}
        //temp[numRows-1] = numRows-1;
       //[> a<]dd[numRows-1] = add[0];
        //for (int i = 0; i < numRows; ++i) {
            //cout<< add[i] << '\n';
        //}
        if (numRows == 1) {
            return s;
        }
       /* for (int i = 0; i < numRows; ++i) {*/
            //int j = 0;
            //int point = 0;
            //while(point < len) {
                //point = temp[i] + j*add[i];
                ////cout<< point<< " ";
                //j++;
                //if (point >= len)
                    //break;
                //ans += s[point];
            //}
      /*  }*/
        ans = "";
       char h[numRows][len];
        int point = 0;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < len; ++j) {
                h[i][j] = ' ';
            }
        }
        int i = 0, j = 0, t = 1;
        while (point < len) {
            //cout<< "     "<<i<< " "<< j<< " "<< t<< "\n";
            h[i][j] = s[point];
            point++;
            if (t < numRows) {
                i++;
                t++;
            } else if (t < 2*numRows-1) {
                t++;
                i--;
                j++;
            } else {
                i++;
                t = 2;
            }
       }
        ans = "";
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < len; ++j) {
                if (h[i][j] != ' ') {
                    ans += h[i][j];
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout<< s.convert("PAYPALISHIRING", 4)<< "\n";
    return 0;
}
