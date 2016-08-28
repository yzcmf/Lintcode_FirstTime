/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/trailing-zeros
@Language: C++
@Datetime: 16-06-19 21:39
*/

class Solution {
 public:
    // param n : description of n
    // return: description of return 
    long long trailingZeros(long long n) {
        
        long long count=0;
        
        while(n>0)
        {
            long long k;
            k=n/5;
            count+=k;
            n=k;
        }
        
        return count;
    }
};
