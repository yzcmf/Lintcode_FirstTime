/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/sort-integers
@Language: C++
@Datetime: 16-08-26 05:26
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
    void sortIntegers(vector<int>& A) {
        // Write your code here
        for(int i=0;i<A.size();i++)
        {
            for(int j=i+1;j<A.size();j++)
            {
                if(A[i]>A[j])
                swap(A[i],A[j]);
            }
        }
    }
};