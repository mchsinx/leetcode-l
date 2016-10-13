## zigzag-conversion
 
 
Total Accepted: 65019 Total Submissions: 292477 Difficulty: Easy
 
 
> The string `"PAYPALISHIRING"` is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
```
P   A   H   N
A P L S I I G
Y   I   R
```
> And then read line by line: `"PAHNAPLSIIGYIR"`
Write the code that will take a string and make this conversion given a number of rows:
```cpp
string convert(string text, int nRows);
```
> `convert("PAYPALISHIRING", 3)` should return `"PAHNAPLSIIGYIR"`.
Subscribe to see which companies asked this question
 
 
## 思路
大概思路都类似，我这个比较直接。
总数为2(numRows-1),除第一和最后一行外下面两个都是顺序加2(numRows-i-1)和2(numRows-1)-2(numRows-i-1)。
更好的可以参考
http://bangbingsyb.blogspot.jp/2014/11/leetcode-zigzag-conversion.html
http://www.cnblogs.com/yuzhangcmu/p/4116668.html
http://boylee.me/development/2014/12/23/leetcode-zigzag-conversion/
 
 
 
 
## Code
 
 
```cpp
#include <iostream>
using namespace std;
#include <string>
 
class Solution {
public:
    string convert(string s, int numRows) {
        string ret;
        if (numRows <= 1 ) return s;
        for (int i = 0; i < numRows && i < s.size(); ++i)
        {
            ret.push_back(s[i]);
            for (int j = 2 * (numRows - 1 - i) + i; j < s.size(); j += 2 * (numRows - 1))
            {
                if (2 * (numRows - 1 - i))
                {
                    ret.push_back(s[j]);
                }
                if (2 * i && j+2*i<s.size())
                {
                    ret.push_back(s[j + 2 * i]);
                }
            }
        }
        return ret;
    }
};
 
int main()
{
    Solution x;
    //std::cout << x.convert("PAYPALISHIRING", 3) << endl;
    std::cout << x.convert("123456789ABCD", 3) << endl;
    std::cout << x.convert("123456789ABCD", 1) << endl;
    std::cout << x.convert("A", 2) << endl;
    system("pause");
    return 0;
 
}
```
 
 
## 总结
* 需要注意当numRows==1的这种情况。
* 特别注意`("A",2)`这种情况，不能进入for语句执行ret.push_back(s[i]),所以需要在for中限制&& i < s.size().
* 注意size函数返回的是一个无符号整型数。
* c++最好引入cstring

## 更优的
来源:http://boylee.me/development/2014/12/23/leetcode-zigzag-conversion/
题意要求给定一个ZigZag形式的字符串，然后以行的形式重新遍历一遍。整个看来主要就是找规律，str代表字串，row代表要求的行数：
* 第一行或最后一行：前一个数和后一个数之差为(row-1)*2
* 其他行，行数为：除了满足上一条之外，在这两个数中间还有一个数，和前一个数的差为(row-i-1)*2
规律找出来的就是逻辑实现了，外层循环遍历row边，内层循环直到到达字符串尾：代码如下：
```
class Solution {
public:
     string convert(string s, int nRows) {
         string res = "";
         if (nRows == 1) return s;
         for (int i = 0; i < nRows; ++i)
         {
             int j = i;
             while (j < s.length())
             {
                 res += s[j];
                 if (i != 0 && i != nRows - 1 && j + (nRows - i) * 2 - 2 < s.length())
                     res += s[j + (nRows - i) * 2 - 2];
                 j += (nRows - 1) * 2;
             }
         }
         return res;
     }
};
```
