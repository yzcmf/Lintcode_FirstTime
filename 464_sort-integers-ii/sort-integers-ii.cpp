/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/sort-integers-ii
@Language: C++
@Datetime: 16-06-26 03:49
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return void
     */
void QuickSort(vector<int>& A, int start ,int end)
     {
         int l=start, r=end, mid=A[(l+r)/2];
         
         while(l<=r)
         {
             while(l<=r && A[r]>mid) r--;
             while(l<=r && A[l]<mid) l++;
             if(l<=r)
             {
                 swap(A[r],A[l]);
                 r--;
                 l++;
             }
         }
    
         if(start<r)
         QuickSort(A,start,r);
         
         if(l<end)
         QuickSort(A,l,end);
         
     }
    
//     void QuickSort(vector<int>& arr, int left, int right) {
//       int i = left, j = right;
//       int tmp;
//       int pivot = arr[(left + right) / 2];
 
//       /* partition */
//       while (i <= j) {
//             while (arr[i] < pivot)
//                   i++;
//             while (arr[j] > pivot)
//                   j--;
//             if (i <= j) {
//                   tmp = arr[i];
//                   arr[i] = arr[j];
//                   arr[j] = tmp;
//                   i++;
//                   j--;
//             }
//       };
 
//       /* recursion */
//       if (left < j)
//             quickSort(arr, left, j);
//       if (i < right)
//             quickSort(arr, i, right);
// }
     
    void sortIntegers2(vector<int>& A) {
        // Write your code here
        if(A.empty()) return;
        QuickSort(A,0,A.size()-1);
    }
};

