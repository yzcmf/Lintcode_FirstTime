/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/remove-element
@Language: C++
@Datetime: 16-06-20 04:51
*/

class Solution {
public:
    /** 
     *@param A: A list of integers
     *@param elem: An integer
     *@return: The new length after remove
     */
    int removeElement(vector<int> &A, int elem) {
        // write your code here
        
        if (A.size() == 0) return 0;

        int len = A.size();
        int newIndex = 0;
        
        for (int i = 0; i< len; i++) {
            
            if(A[i] != elem)
            {
                A[newIndex++] = A[i];// not equal, duplicate.
            }
            
            
        }

        return newIndex;
    }
};

