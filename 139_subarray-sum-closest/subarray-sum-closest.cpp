/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/subarray-sum-closest
@Language: C++
@Datetime: 16-08-21 06:03
*/

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number 
     *          and the index of the last number
     */
    vector<int> subarraySumClosest(vector<int> nums){
        // write your code here
        vector<pair<int,int>>acc;
        acc.push_back(make_pair(0,-1));
        int sum=0;
        
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            acc.push_back(make_pair(sum,i));
        }
        
        sort(acc.begin(),acc.end());//In order to find the minium Sum;
        
        int min_abs=INT_MAX,a,b,tmp;
        for(int i=1;i<acc.size();i++)
        {
            tmp=abs(acc[i].first-acc[i-1].first);
            if(min_abs>=tmp)
            {
                min_abs=tmp;
                a=acc[i-1].second;
                b=acc[i].second;
            }
        }
        vector<int>res;
        res.push_back(min(a,b)+1);
        res.push_back(max(a,b));
        return res;
    }
};

/*
题目的意思是在一个数组中找一段连续的区间，使得这段区间的和的绝对值最小。做法就是利用前缀和，先用一个数组acc[i]来保存从nums[0]到nums[i]的和，同时还要记录下标，所以这里我用pair<int, int>来保存。那么，我们想要得到nums[i]到nums[j]的和，只要用acc[j] - acc[i-1]就可以了。但是这里有一点要注意要加一个辅助的节点，那就是[0, -1]，这样就可以确保可以找到以nums[0]开始的区间了。剩下的工作就是对acc数组排序，找到排序后相邻的差的绝对值最小的那一对节点。
*/