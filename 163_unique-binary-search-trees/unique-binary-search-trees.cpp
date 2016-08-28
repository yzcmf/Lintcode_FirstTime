/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/unique-binary-search-trees
@Language: C++
@Datetime: 16-08-22 01:23
*/

class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        // write your code here
        vector<int>count(n+1,0);
        count[0]=1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                count[i]+=count[j]*count[i-1-j];
                //Leftsubtrees:count[j];
                //Rightsubtrees:count[i-1-j]; 
            }
        }
        
        return count[n];
    }
};

//http://codinggamestart.blogspot.com/2015/08/lintcode-unique-binary-search-trees.html
//Good reference: http://bangbingsyb.blogspot.com/2014/11/leetcode-unique-binary-search-trees-i-ii.html