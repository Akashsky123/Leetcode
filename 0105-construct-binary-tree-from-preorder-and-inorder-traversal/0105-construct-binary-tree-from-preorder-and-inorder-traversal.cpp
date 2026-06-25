/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int find(vector<int>in, int element,int n)
    {
        for(int i=0;i<n;i++)
        {
            if(in[i]==element)
            {
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int>pre,vector<int>in,int &index,int inorderStart,int inorderEnd,int n)
    {
        if(index>=n || inorderStart>inorderEnd)
        {
            return NULL;
        }
        int element=pre[index++];
        TreeNode* root=new TreeNode(element);
        int position=find(in,element,n);
        root->left=solve(pre,in,index,inorderStart,position-1,n);
        root->right=solve(pre,in,index,position+1,inorderEnd,n);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index=0;
        int n=preorder.size();
        int inorderStart=0;
        int inorderEnd=inorder.size()-1;
        return solve(preorder,inorder,index,inorderStart,inorderEnd,n);
        
    }
};