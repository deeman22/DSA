/*
 Given A, generate all structurally unique BST’s (binary search trees) that store values 1…A.

Input Format:

The first and the only argument of input contains the integer, A.
Output Format:

Return a list of tree nodes representing the generated BST's.
Constraints:

1 <= A <= 15
Example:

Input 1:
    A = 3

Output 1:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

vector<TreeNode*> generate(int st, int ed)
    {
        vector<TreeNode*> v;

        if(st > ed)
        {
            v.push_back(NULL);
            return v;
        }

        if(st == ed)
        {
            v.push_back(new TreeNode(st));
            return v;
        }

        for(auto i=st; i<=ed; i++)
        {
            vector<TreeNode *> lft = generate(st, i-1);
            vector<TreeNode *> rgt = generate(i+1, ed);

            for(auto l : lft)
            {
                for(auto r : rgt)
                {
                    TreeNode *root = new TreeNode(i);

                    root->left = l;
                    root->right = r;

                    v.push_back(root);
                }
            }
        }
        return v;
    }

vector<TreeNode*> Solution::generateTrees(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    if(A == 0)
            return vector<TreeNode*>();
    else 
        return generate(1, A);
    
}
