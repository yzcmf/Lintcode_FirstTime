/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/remove-linked-list-elements
@Language: C++
@Datetime: 16-08-26 05:23
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head a ListNode
     * @param val an integer
     * @return a ListNode
     */
    ListNode *removeElements(ListNode *head, int val) {
        
        // write your code here
        if (!head) return NULL;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;
        
        while (dummy->next){
            if (dummy->next->val == val){
                dummy->next = dummy->next->next;
            }else{
                dummy = dummy->next;
            }
        }
        
        return head->next;
    }
};
