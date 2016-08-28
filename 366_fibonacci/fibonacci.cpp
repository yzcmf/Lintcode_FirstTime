/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/fibonacci
@Language: C++
@Datetime: 16-08-24 09:28
*/

class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        // write your code here
        
        if(n<=0) return -1;
        if(n==1) return 0;
        if(n==2) return 1;
        
        vector<int>num;
        num.push_back(0);
        num.push_back(1);
        int i=3;
        
        while(i<=n)
        {
            num.push_back(num[i-2]+num[i-3]);
            i++;
        }
        
        return num[n-1];
    }
};
