/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/spiral-matrix
@Language: C++
@Datetime: 16-08-25 00:51
*/

class Solution {
public:
    /**
     * @param matrix a matrix of m x n elements
     * @return an integer array
     */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // Write your code here
        vector<int> res;
        if(matrix.empty()||matrix[0].empty()) return res;
        int m=matrix.size(),n=matrix[0].size();
        int c=m>n ? (n+1)/2 :(m+1)/2;//环数的计算公式是 min(m, n) / 2
        int p=m,q=n;//p，q为当前环的高度和宽度
        
        for(int i=0;i<c;i++,p-=2,q-=2)
        {
            for(int col=i;col<i+q;col++)
               res.push_back(matrix[i][col]);
            for(int row=i+1;row<i+p;row++)
               res.push_back(matrix[row][i+q-1]);
            if(p==1 || q==1) break;
            for(int col=i+q-2;col>=i;col--)
               res.push_back(matrix[i+p-1][col]);
            for(int row=i+p-2;row>i;row--)
               res.push_back(matrix[row][i]);
        }
        
        return res;
    }
};

//Good reference: http://www.cnblogs.com/grandyang/p/4362675.html