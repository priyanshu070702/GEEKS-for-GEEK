//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

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
/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */


// bool isLeaf(Node *p){
//     if(p->left==NULL && p->right==NULL)return 1;
//     return 0;
// }
// void leftSide(Node *root, vector<int>&res){
//     Node *p=root;
//     // while(p!=NULL){
//     //     if(!isLeaf(p))res.push_back(p->data);
//     //     if(p->left!=NULL)p=p->left;
//     //     else p=p->right;
//     // }
//     if(!isLeaf(p))res.push_back(p->data);
//     if(p->left!=NULL)leftSide(root->left,res);
//     if(p->right!=NULL)leftSide(root->right,res);
// }

// void rightSide(Node *root, vector<int>&res){
//     Node *p=root;
//     stack<int>st;
//     // while(p!=NULL){
//     //     if(!isLeaf(p))st.push(p->data);
//     //     if(p->right!=NULL)p=p->right;
//     //     else p=p->left;
//     // }
//     if(!isLeaf(p))res.push_back(p->data);
//     if(p->right!=NULL)rightSide(root->right,res);
//     if(p->left!=NULL)rightSide(root->left,res);
    
//     while(!st.empty()){
//         res.push_back(st.top());
//         st.pop();
//     }
// }

// void leaves(Node *p, vector<int>&res){
//     if(isLeaf(p)){
//         res.push_back(p->data);
//         return;
//     }
//     if(p->left)leaves(p->left,res);
//     if(p->right)leaves(p->right,res);
// }

// class Solution {
// public:
//     vector <int> boundary(Node *root)
//     {
//         vector<int>ans;
//         if(root==NULL)return ans;
//         if(!isLeaf(root))ans.push_back(root->data);
//         leftSide(root->left,ans);
//         leaves(root->right,ans);
//         rightSide(root,ans);
//         return ans;
//     }
// };

bool isLeaf(Node *p) {
    if (p->left == NULL && p->right == NULL) return true;
    return false;
}

void leftSide(Node *root, vector<int>& res) {
    Node *p = root;
    while (p != NULL) {
        if (!isLeaf(p)) res.push_back(p->data);
        if (p->left != NULL) p = p->left;
        else p = p->right;
    }
}

void rightSide(Node *root, vector<int>& res) {
    Node *p = root;
    stack<int> st;
    while (p != NULL) {
        if (!isLeaf(p)) st.push(p->data);
        if (p->right != NULL) p = p->right;
        else p = p->left;
    }
    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
}

void leaves(Node *p, vector<int>& res) {
    if (isLeaf(p)) {
        res.push_back(p->data);
        return;
    }
    if (p->left) leaves(p->left, res);
    if (p->right) leaves(p->right, res);
}

class Solution {
public:
    vector<int> boundary(Node *root) {
        vector<int> ans;
        if (root == NULL) return ans;
        if (!isLeaf(root)) ans.push_back(root->data);
        leftSide(root->left, ans);
        leaves(root, ans);
        rightSide(root->right, ans);
        return ans;
    }
};


//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends