/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/kth-largest-element
@Language: C++
@Datetime: 16-07-11 01:11
*/

//Method one: Time:O[n*log(n)] Space:O[1]

// class Solution {
// public:
//     /*
//      * param k : description of k
//      * param nums : description of array and index 0 ~ n-1
//      * return: description of return
//      */

//     int kthLargestElement(int k, vector<int> nums) {
       
//       sort(nums.begin(),nums.end());
       
//       return nums[nums.size()-k];
       
//     }
// };


// //Method two: priority queue
// class Solution {
// public:
//     /*
//      * param k : description of k
//      * param nums : description of array and index 0 ~ n-1
//      * return: description of return
//      */

// int kthLargestElement(int k, vector<int> nums) {
       
//   struct compare  
//   {  
//   bool operator()(const int& l, const int& r)  
//   {  
//       return l > r;//  front -> end : large -> small
//   }  
//   }; 
   
//   priority_queue<int,vector<int>,compare>queue;
       
//   for(int i=0;i<nums.size();i++)
//   {
//       if(queue.size()<k) queue.push(nums[i]);//when less than k members
//       else if(queue.top()<nums[i])
//       {
//           queue.pop();
//           queue.push(nums[i]);
//       }
//   }
    
//   return queue.top();
       
//   }
// };


// //Method three: recurision
// class Solution {
// public:
//     /*
//      * param k : description of k
//      * param nums : description of array and index 0 ~ n-1
//      * return: description of return
//      */

// int kthLargestElement(int k, vector<int> nums) {
      
//     return quickSelect(nums, 0, nums.size() - 1, k);
// }
 
// private:
//     int quickSelect(vector<int> &nums, int left, int right, int k) {
//         int pivot = right;
//         int i = left;
        
//         for (int j = left; j < right; j++) {
//             if (nums[j] > nums[pivot]) {
//                 swap(nums[i++], nums[j]);
//             }
//         }
        
//         swap(nums[pivot], nums[i]);
        
//         // 递归基
//         if (i - left + 1 == k) {
//             return nums[i];
//         }
        
//         if (i - left + 1 > k) {
//             return quickSelect(nums, left, i - 1, k);
//         } else if (i - left + 1 < k) {
//             return quickSelect(nums, i + 1, right, k - (i - left + 1));
//         } 
//     } 
  
// };

//Method three: recurision
class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */

int kthLargestElement(int k, vector<int> nums) {
      
    return quickselect(nums,0,nums.size()-1,k);
}
 
private:

int quickselect(vector<int> nums, int left,int right, int k)
{
    int pivot=right;
    int i=left;
    
    for(int j=left;j<right;j++)
    {
        
        if(nums[j]>nums[pivot])
        {
        swap(nums[i],nums[j]);
        i++;
        }
    }
    
    if(nums[i]<nums[pivot]) swap(nums[i],nums[pivot]);
    
    if(i-left+1==k) return nums[i];
    
    if (i-left+1<k)  return quickselect(nums,i+1,right,k-(i-left+1));
    
    if (i-left+1>k)  return quickselect(nums,left,i-1,k);
    
}
  
};


