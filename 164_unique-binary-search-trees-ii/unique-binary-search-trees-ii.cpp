/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/unique-binary-search-trees-ii
@Language: C++
@Datetime: 16-08-22 01:05
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: A list of root
     */
    vector<TreeNode *> generateTrees(int n) {
        // write your code here
        return genBST(1,n);
    }
    
     vector<TreeNode *> genBST(int min,int max)
     {
         vector<TreeNode *> ret;
         if(min>max)
         {
             ret.push_back(NULL);
             return ret;
         }
         
         for(int i=min;i<=max;i++)
         {
          vector<TreeNode *> leftSubTree = genBST(min,i-1);
          vector<TreeNode *> rightSubTree = genBST(i+1,max);  
          
          for(int j=0;j<leftSubTree.size();j++)
          {
              for(int k=0;k<rightSubTree.size();k++)
              {
                TreeNode *root = new TreeNode(i);  
                root->left = leftSubTree[j];
                root->right = rightSubTree[k];  
                ret.push_back(root);  
              }
          }
         }
         return ret;
     }
};

//The good reference: http://bangbingsyb.blogspot.com/2014/11/leetcode-unique-binary-search-trees-i-ii.html