/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/linked-list-cycle-ii
@Language: C++
@Datetime: 16-08-17 21:25
*/

/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        // write your code here
        
        ListNode* ptr1,* ptr2;
        if(head == NULL) return NULL;
        ptr1 = head;
        ptr2 = head;

        while(ptr2->next != NULL && ptr2->next->next != NULL)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
            if(ptr1 == ptr2)
            {
                ptr1 = head;
                while(ptr1 != ptr2)
                {
                    ptr2 = ptr2->next;
                    ptr1 = ptr1->next;
                }
                return ptr1;
            }

        }
        return NULL;
    }
};

//A good refer : http://fisherlei.blogspot.com/2013/11/leetcode-linked-list-cycle-ii-solution.html


