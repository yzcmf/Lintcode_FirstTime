/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/palindrome-linked-list
@Language: C++
@Datetime: 16-08-24 08:24
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     /**
//      * @param head a ListNode
//      * @return a boolean
//      */
//     bool isPalindrome(ListNode* head) {
//         // Write your code here
        
//         //ListNode* newNode = reverse(head);
        
//         // Using the arrays for the comparsion;
        
//         int length=0;
        
//         ListNode* TailNode = head;
//         ListNode* CurNode = head;
        
//         while(TailNode)
//         {
//           TailNode = TailNode->next;
//           length++; 
//         }
        
        
//         int len=0;
        
//         while(len<length/2)
//         {
//             CurNode = CurNode->next;
//             len++;
//         }
        
//     }
    
//     // ListNode*reverse (ListNode* head)
//     // {
//     //   ListNode* prev =NULL;
       
//     //   while(head)
//     //   {
//     //       ListNode * temp = head->next;
//     //       head->next = prev;
//     //       prev = head;
//     //       head = temp;
//     //   }
        
//     //   return prev;
//     // }
// };


// -- Stardard solution -- Method one(find the):

// class Solution {
// public:
//     /**
//      * @param head a ListNode
//      * @return a boolean
//      */
//     bool isPalindrome(ListNode* head) {
//         // Write your code here
//     if(head == NULL || head->next == NULL) return true;  
     
//     ListNode* fast = head , *slow =head;
//     while (fast && fast->next)
//     {
//         fast = fast->next->next;
//         slow = slow->next;
//     }
     
//     if(fast != NULL)  fast = slow->next; 
//     // If the node is odd, skip the middle node;
//     else 
//       fast=slow;
    
//     slow = head;// now fast is in the middle and slow is the head;
    
//     // reverse the post-half nodes
    
//     ListNode* secHead = NULL;
    
//     while(fast)
//     {
//         ListNode* r = fast->next;
//         fast->next =secHead;
//         secHead = fast;
//         fast =r;
//     }
    
//     //Comparsion the two-parts;
//     fast = secHead;
//     while(fast)
//     {
//         if(fast->val != slow->val) return false;
//         fast=fast->next;
//         slow=slow->next;
//     }
    
//     return true;
//     }
// };


// -- Stardard solution -- Method two(using the stack):

class Solution {
public:
    /**
     * @param head a ListNode
     * @return a boolean
     */
    bool isPalindrome(ListNode* head) {
        // Write your code here
        if(!head || !head->next) return true;
        
        ListNode *slow = head, *fast = head;
        stack <int> s;
        s.push(head->val);
        
        while(fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            s.push(slow->val);
        }
        
        if(!fast->next) s.pop();
        
        while(slow->next)
        {
            slow = slow->next;
            int tmp = s.top();
            s.pop();
            if(tmp!=slow->val) return false;
        }

        return true;
    }
};

//Method one (reverse the second half):
//http://blog.csdn.net/fly_yr/article/details/50159457

//Method two (stack): 
//http://www.cnblogs.com/grandyang/p/4635425.html
