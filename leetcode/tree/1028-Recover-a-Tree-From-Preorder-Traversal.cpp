class Solution {
public:
    TreeNode* solve(string &s,int &idx,int depth)
    {
        int n=s.length();
        int cnt=0;
        int j=idx;
        while(j<n && s[j]=='-')
        {
            cnt++;
            j++;
        }
        if(cnt!=depth)
        {
            return NULL;
        }
        idx=j;
        int num=0;
        while(idx<n && s[idx]!='-')
        {
            num*=10;
            num+=(s[idx]-'0');
            idx++;
        }
        TreeNode* ans=new TreeNode(num);
        ans->left=solve(s,idx,depth+1);
        ans->right=solve(s,idx,depth+1);
        return ans;
    }
    TreeNode* recoverFromPreorder(string traversal)
    {
        int idx=0;
        return solve(traversal,idx,0);
    }
};