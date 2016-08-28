/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/number-of-airplanes-in-the-sky
@Language: C++
@Datetime: 16-08-25 03:24
*/

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
/*
将所有区间的start与end放在一起排序，但是要标记其是属性，然后统一排序，
问题就转化成了括号匹配嵌套的问题了(最大有多少层括号嵌套，比如说((()))就是一个3层嵌套，()(()))最大嵌套是2)，这里start相当于左括号，end相当于右括号，
只要用一个cnt来记录，遇到start就加1，遇到end就减1，记录过程中的最大值就是答案。
*/
 
class Solution {
public:
    /**
     * @param intervals: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        // write your code here
        
        vector<pair<int,bool>> v;
        
        for(auto &i : airplanes)
        {
            v.push_back(make_pair(i.start,true));//start相当于左括号
            v.push_back(make_pair(i.end,false));//end相当于右括号
        }
        
        int cnt = 0 ,res = 0;
        
        sort(v.begin(),v.end());
        
        for(auto &i : v)
        {
            if(i.second) cnt++;//遇到start就加1
            else cnt--;//遇到end就减1
            res = max(cnt,res);
        }
        
        return res;
    }
};

//Good reference: http://www.cnblogs.com/easonliu/p/4504647.html