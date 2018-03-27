# leetcode
Do practise

## 1005 最长回文串

​	最长回文串即一个一个字符串无论从左往右还是从右往左读都是一样的，那么显然这个字符串是左右对称的，这样的话我们就可以通过小串找大串。

​	如abbcbba与abbbba，这两个串，我们先以abbcbba为例，很明显它是以c为对称轴左右对称的，因此只要我们找到bcb这个字串，再同时向左右扩展，即可找到全部的所有的回文字串。再看abbbba这个串，显示其是以第2位与第3位之间的间隔为对称轴的（从0开始计数），这样只要我们找到bb(第2和第三位上的)，在左右同步扩张即可找到全部的回文字串。

​	大家可能会感到奇怪，为什么要举两个一样的例子，这其中当然是有原因的。我们稍微观察一下就该发现，所有的回文字串（我认为只有以为的如ab串中的字串a不能被称为回文字串）必然可以由2位的回文字串或者3位的回文字串左右扩张组成。这是显而易见的结论，也是我们上面用了一个由2位回文字串扩张而来的例子和由三位回文字串扩张而来的两个例子。

​	拥有上面的结论之后，这道题就迎刃而解了，只要我们遍历两遍原串，一遍找由2为回文字串扩张来的，一遍找一位回文字串扩张来的，找到其中的最大的回文字串即可。



``` c++

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
};

```



