//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    Node* reverse(Node* head){
            Node* pre=NULL,*curr=head,*fut=NULL;
            while(curr){
                fut=curr->next;
                curr->next=pre;
                pre=curr;
                curr=fut;
            }
            return pre;
        }
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        if(!head->next)return head;
        Node* t=reverse(head);
        Node* temp=t;
        int big=t->data;
        Node* crawl=t;
        while(crawl->next){
            if(crawl->next->data<big)crawl->next=crawl->next->next;
            else{
                crawl=crawl->next;
                big=crawl->data;
            }
        }
        head=reverse(t);
        return head;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends