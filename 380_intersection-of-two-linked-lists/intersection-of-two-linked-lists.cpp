/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/intersection-of-two-linked-lists
@Language: C++
@Datetime: 16-08-25 02:32
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
/*
(1) Get the length of list A, say n_a.
(2) Get the length of list B, say n_b.
These two steps will take O(n) time. (n = n_a + n_b)
(3) Set two pointers. Make the pointer of longer list abs(n_a-n_b) steps forward.
(4) Scan the two list until find the intersection, or to the end of list.
This step will take O(n) time.
*/

class Solution {
public:
    /**
     * @param headA: the first list
     * @param headB: the second list
     * @return: a ListNode
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // write your code here
        
        int n1=0;
        int n2=0;
        
        ListNode * a1 = headA;
        ListNode * a2 = headB;
        
        while(a1)
        {
            n1++;
            a1=a1->next;
        }
        
        while(a2)
        {
            n2++;
            a2=a2->next;
        }
        
        a1 = headA;
        a2 = headB;
        
        while(n1>0 && n2>0)
        {
         if(n1>n2)
         {
             n1--;
             a1 = a1->next;
         }
            
         if(n2>n1)
         {
             n2--;
             a2 = a2 ->next;
         }
            
         if(n1 == n2)
         {
             
             if(a1 == a2) return a1;
             else 
             {
                 a1 = a1->next;
                 a2 = a2->next;
                 n1--;
                 n2--;
             }
         }
        }
        return NULL;
    }
};


//O(n) solution :
//http://yucoding.blogspot.com/2014/12/leetcode-question-intersection-of-two.html
