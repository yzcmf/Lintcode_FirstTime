/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/delete-node-in-the-middle-of-singly-linked-list
@Language: C++
@Datetime: 16-06-20 07:25
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
     * @param node: a node in the list should be deleted
     * @return: nothing
     */
    void deleteNode(ListNode *node) {
        // write your code here
        node->val=node->next->val;// Give node->next's value to node's value;
        node->next=node->next->next;// Delete the node->next; connect node to node->next->next;
    }
};