/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/the-smallest-difference
@Language: C++
@Datetime: 16-08-25 02:32
*/

class Solution {
public:
    /**
     * @param A, B: Two integer arrays.
     * @return: Their smallest difference.
     */
    int smallestDifference(vector<int> &A, vector<int> &B) {
        // write your code here
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        
        int p_a=0,p_b=0;
        int la=A.size(), lb=B.size();
        int res=INT_MAX;
        
        if(la == 0 && lb == 0) return 0;
        
        while(la == 0 && lb != 0 && p_b<lb) res = min(res,B[p_b++]);
        while(lb == 0 && la != 0 && p_a<la) res = min(res,A[p_a++]);
        

        while(p_a<la && p_b<lb)
        {
          res=min(res,abs(A[p_a]-B[p_b]));
           
          if(A[p_a]>B[p_b]) p_b++;
          else if (A[p_a]<=B[p_b]) p_a++;
        }  
        
        while(p_a<la)
        {
          res = min(res,abs(A[p_a]-B[lb-1])); 
          p_a++;
        }
        
        while(p_b<lb)
        {
          res = min(res,abs(A[la-1]-B[p_b])); 
          p_b++;
        }
        
        
        
        return res;
    }
    
    
// -- solutions online    
    
//   int smallestDifference(vector<int>& A, vector<int>& B) {
  
//   sort(A.begin(), A.end());
//   sort(B.begin(), B.end());
  
//   int res = INT_MAX;
//   int i = 0, j = 0;
  
//   while(i < A.size() && j < B.size()) {
//     int diff = (A[i] - B[j]);
//     if(diff == 0) return 0;
//     res = min(res, abs(diff));
//     if(diff < 0) i ++;
//     else j++;
//   }
  
//   while(i < A.size()) {
//     res = min(res, abs(A[i] - B[j - 1]));
//     i++;
//   }
  
//   while(j < B.size()) {
//     res = min(res, abs(A[i - 1] - B[j]));
//     j++;
//   }
  
//   return res;
//   }

};
