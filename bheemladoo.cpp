class Solution{

    public:
    Node *findtarget(Node* root,int home){
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node *p=q.front();
            q.pop();
            if(p->data==home)return p;
            if(p->left!=NULL)q.push(p->left);
            if(p->right!=NULL)q.push(p->right);
        }
        return NULL;
    }
    void markParents(Node* root,unordered_map<Node*,Node*>&parents, Node* target,int home){
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            Node *curr=q.front();
            q.pop();
            if(curr->left!=NULL){
                parents[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                parents[curr->right]=curr;
                q.push(curr->right);
            }
        }
    }
    int ladoos(Node* root, int home, int k)
    {
        int res=0;
        unordered_map<Node*,Node*>parent;
        Node *target=findtarget(root,home);
        markParents(root,parent,target,home); 
        unordered_map<Node*,bool>vis; 
        queue<Node*>q;
        q.push(target);
        vis[target]=true;
        int level=0;
        while(!q.empty()){
            int n=q.size();
            if(level++>k)break;
            for(int i=0;i<n;i++){
                Node *curr=q.front();
                q.pop();
                res+=curr->data;
                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left]=true;
                }
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right]=true;
                }
                if(parent[curr] && !vis[parent[curr]]){
                    q.push(parent[curr]);
                    vis[parent[curr]]=true;
                }
            }
        }
        return res;
    }


};
