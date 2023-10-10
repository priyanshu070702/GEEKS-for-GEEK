//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution
{
private:

public:
    // fun to get the parent of all node
    void storeparent(Node *root , int target , unordered_map<Node* , Node*> &parent , Node* &temp){
        // base case
        
        if(root == NULL) return;
        if(root ->data == target && temp == NULL) temp =root;
        if(root ->left != NULL){
            parent[root->left] = root;
            storeparent(root->left,target , parent, temp);
        }
        if(root ->right != NULL){
            parent[root -> right] = root;
            storeparent(root ->right , target , parent ,temp);
        }
    }

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        // return the sorted vector of all nodes at k dist
        // map to store the parent
        unordered_map<Node* , Node*> parent;
        Node* temp = NULL;
        // to get the parent of all node and store the target node 
        storeparent(root , target ,parent , temp);
        // visited map for the BFS traversal
        
        unordered_map<Node* , bool> vis;
        vis[temp] = true;
        // to stroe the answer
        vector<int> ans;
        // target node is pushed
        queue<pair<Node* , int>>q;
        q.push(make_pair(temp,k));
        
        // until queue become empty
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            
            if(front.second == 0){
                ans.push_back(front.first->data);
            }
            // target ka right
            Node * r = front.first;
            if(r->right != NULL and vis.find(r->right) == vis.end()){
                q.push(make_pair( r->right , front.second-1 ));
                vis[parent[r->right]] = true;
            }
            // target ka left
            if(r->left != NULL and vis.find(r->left) == vis.end()){
                q.push(make_pair( r->left , front.second-1 ));
                vis[parent[r->left]] = true;
            }
            // above the target node
            if(parent.find(r) != parent.end() and vis.find(parent[r]) == vis.end()){
                q.push(make_pair(parent[r] , front.second -1 ));
                vis[parent[r]] = true;
            }
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    getchar();
    
    Solution x = Solution();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* head = buildTree(s);
        
        int target, k;
        cin>> target >> k;
        getchar();
        
        vector <int> res = x.KDistanceNodes(head, target, k);
        
        for( int i=0; i<res.size(); i++ )
            cout<< res[i] << " ";
        cout<<endl;
    }
    return 0;
}

// } Driver Code Ends