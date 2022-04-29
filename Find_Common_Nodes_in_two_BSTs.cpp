class Solution
{
    public:
    //Function to find the nodes that are common in both BST. 
    void preOrder(Node *root, set<int> &st){
        
        if(!root) return;
        
        preOrder(root->left, st);
        st.insert(root->data);
        preOrder(root->right, st);
        
    }
    void check(Node *root, set<int> st, vector<int> &v){
        if(!root) return ;
        
        check(root->left, st, v);
        if(st.count(root->data) ) v.push_back(root->data);
        check(root->right, st, v);
        
    }
    vector <int> findCommon(Node *root1, Node *root2)
    {
     //Your code here
        // set<int> st;
        // vector<int> ans;
        // preOrder(root1, st);
        // check(root2, st, ans);
        // return ans;
        
        vector<int>result ;
         stack<Node*>s1;
         stack<Node*>s2;
        while(root1!=NULL)
         {
             s1.push(root1);
             root1 = root1->left;
         }
         while(root2!=NULL)
         {
             s2.push(root2);
             root2 = root2->left;
         }
         while(!s1.empty() && !s2.empty())
         {
             if(s1.top()->data<s2.top()->data)
             {
                 root1 = s1.top()->right;
                 s1.pop();
             }
             else if(s1.top()->data>s2.top()->data)
             {
                 root2 = s2.top()->right;
                 s2.pop();
             }
             else
             {
                 result.push_back(s1.top()->data);
                 
                  root1 = s1.top()->right;
                  s1.pop();
                  root2 = s2.top()->right;
                  s2.pop();
                  
             }
             while(root1!=NULL)
             {
                 s1.push(root1);
                 root1 = root1->left;
             }
             while(root2!=NULL)
             {
                 s2.push(root2);
                 root2 = root2->left;
             }
         }
         return result;
        
    }
};
