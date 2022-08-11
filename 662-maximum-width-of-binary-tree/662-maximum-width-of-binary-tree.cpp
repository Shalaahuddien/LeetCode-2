class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty())
        {
            int qlen = q.size();
            int mini = q.front().second;
            int last = 0, first = 0;
            for(int i = 0; i < qlen; i++)
            {
                TreeNode* node = q.front().first;
                long currId = q.front().second - mini;
                q.pop();
                if(i == 0)
                    last = currId;
                if(i == qlen-1)
                    first = currId;
                if(node->left)
                    q.push({node->left, 2*currId + 1});
                if(node->right)
                    q.push({node->right, 2*currId + 2});
            }
            ans = max(ans, first - last + 1);
        }
        return ans;
    }
};