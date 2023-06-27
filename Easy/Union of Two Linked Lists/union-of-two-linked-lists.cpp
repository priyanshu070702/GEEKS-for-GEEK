//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};


// } Driver Code Ends
/*
// structure of the node is as follows

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

*/
class Solution
{
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        // int mn=INT_MAX;
        // int mx=INT_MIN;
        // Node *h1=head1;
        // Node *h2=head2;
        // // while(h1!=NULL && h2!=NULL){
        // //     mx=max(mx,max(h1->data,h2->data));
        // //     mn=min(mn,max(h1->data,h2->data));
        // //     h1=h1->next;
        // //     h2=h2->next;
        // // }
        // set<Node *>s;
        // while(h1!=NULL && h2!=NULL){
        //     s.insert(h1);
        //     s.insert(h2);
        //     h1=h1->next;
        //     h2=h2->next;
        // }
        // Node *st=s.begin();
        // Node *head=new Node(st->data);
        // Node *p=head;
        // for(auto it:s){
        //     Node *st=it;
        //     Node *q=new Node(it->data);
        //     p->next=q;
        //     p=q;
        // }
        // return head;
         set<int>s;
        while(head1){
        s.insert(head1->data);
       head1=head1->next;
       }
       while(head2){
       s.insert(head2->data);
       head2=head2->next;
       }
       vector<int>v;
       for(auto it:s){
       v.push_back(it);
       }
       Node* temp=new Node(v[0]);
       Node* cur;
       cur = temp;
       for(int i=1;i<v.size();i++){
       cur->next = new Node(v[i]);
       cur = cur->next;
       
       }
       return temp;
    }
};


//{ Driver Code Starts.

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution obj;
        Node* head = obj.makeUnion(first,second);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends