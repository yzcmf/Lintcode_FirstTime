/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/evaluate-reverse-polish-notation
@Language: C++
@Datetime: 16-08-26 04:18
*/

/*
逆波兰表达式就是把操作数放前面，把操作符后置的一种写法，我们通过观察可以发现，第一个出现的运算符，其前面必有两个数字，当这个运算符和之前两个数字完成运算后从原数组中删去，把得到一个新的数字插入到原来的位置，继续做相同运算，直至整个数组变为一个数字。
*/

/*
这道题果然应该是栈的完美应用啊，从前往后遍历数组，遇到数字则压入栈中，遇到符号，则把栈顶的两个数字拿出来运算，把结果再压入栈中，直到遍历完整个数组，栈顶数字即为最终答案。
*/

class Solution {
public:
    /**
     * @param tokens The Reverse Polish Notation
     * @return the value
     */
    int evalRPN(vector<string>& tokens) {
        // Write your code here
        if(tokens.size() == 1) return atoi(tokens[0].c_str());
        stack<int> s;
        
        for(int i=0;i<tokens.size();i++)
        {
         if(tokens[i]!="+" && tokens[i]!="-"&& tokens[i]!="*" && tokens[i]!="/")
         s.push(atoi(tokens[i].c_str()));//c_str:make it more compatible;
         else
         {
             int m=s.top();
             s.pop();
             int n=s.top();
             s.pop();
             if(tokens[i]=="+") s.push(n+m);
             if(tokens[i]=="-") s.push(n-m);
             if(tokens[i]=="*") s.push(n*m);
             if(tokens[i]=="/") s.push(n/m);
         }
        }
        
        return s.top();
    }
};

//c_str: http://baike.baidu.com/view/1600698.htm
