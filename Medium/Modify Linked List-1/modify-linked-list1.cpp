//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
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
class Solution{
    public:
    struct Node* modifyTheList(struct Node *head)
    {
         struct Node* t1=head;
        int c=0;
        while(t1!=NULL){
            c++;
            t1=t1->next;
        }
        int arr[c];
        t1=head;int j=0;
        while(t1!=NULL){
            arr[j]=t1->data;
            j++;
            t1=t1->next;
        }
        for(int i=0;i<c/2;i++){
            int temp=arr[i];
            arr[i]=arr[c-1-i]-arr[i];
            arr[c-1-i]=temp;
        }
        t1=head;
        int c1=0;
        while(t1!=NULL){
            t1->data=arr[c1];
            c1++;
            t1=t1->next;
        }
        return head;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends