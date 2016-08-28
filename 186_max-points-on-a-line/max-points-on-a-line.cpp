/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/max-points-on-a-line
@Language: C++
@Datetime: 16-08-23 18:56
*/

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.empty())
            return 0;
        int size = points.size();

        if (size < 3)
            return size;

        //记录最后在同一直线上的最多点数
        int maxNum = 0;
        //记录每条直线上的点数
        map<float, int> line;
        //固定一点，求其余另外所有点数构成的直线斜率
        for (int i = 0; i < size; ++i)
        {
            line.clear();
            line[INT_MIN] = 0;
            //记录与当前节点的相同节点数
            int common = 1;
            for (int j = 0; j < size; ++j)
            {
                if (j == i)
                    continue;
                //相同的两个点
                else if (points[i].x == points[j].x && points[i].y == points[j].y)
                {
                    ++common;
                    continue;
                }
                else{
                    float k = (points[i].x == points[j].x) ? INT_MAX : (float)(points[i].y - points[j].y) / (points[i].x - points[j].x);
                    ++line[k];
                }//else         
            }//for
            map<float, int>::iterator iter = line.begin();
            for (; iter != line.end(); iter++)
            {
                if ((iter->second + common) > maxNum)
                    maxNum = iter->second + common;
            }//for
        }//for
        return maxNum;
    }
};

//http://blog.csdn.net/fly_yr/article/details/49737337