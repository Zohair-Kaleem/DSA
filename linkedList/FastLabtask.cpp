#include<iostream>
using namespace std;
class Node{
public:
    Node* next;
    int val;
    Node(){
        next=NULL;
    }
};
class LinkedList{
    Node *head;
    Node*tail;
public:
    LinkedList(){
        tail=head=NULL;
    }
    void push_back(int val){  
        Node *newnode=new Node();
        newnode->val=val;
        newnode->next=NULL;
        if(head==NULL){
           tail= newnode;
           head=newnode;
        }else{ 
            tail->next=newnode;
            tail=newnode;
        }
        
    }
    void push_front(int val){
        Node*  newnode=new Node();
        newnode->val=val;
        newnode->next=NULL;
        if(!head){
            head=newnode;
            tail=head;
        }else{
            newnode->next=head;
            head=newnode;
        }
    }
    void print(){
        Node*temp=head;
        while (temp)
        {
            cout<<temp->val;
            if(temp->next){
                cout<<"->";
            }
            temp=temp->next;
        }
        cout<<'\n';
    }
    void insertAtPos(int val,int pos){
        int i=1;
        if(pos==1){
            push_front(val);
            return;
        }
        Node*temp=head;
        while(temp){
            if(i+1==pos){
                Node *newnode=new Node();
                newnode->val=val;
                Node*next=temp->next;
                temp->next=newnode;
                newnode->next=next;
                return;
            }
            temp=temp->next;
            i++;
        }
        if(!temp){
            cout<<"insufficient position"<<endl;
        }
   
        
    }
    void deleteNode(int pos){
        Node*temp=head;
        int i=1;
        while (head)
        {
            if (i==pos)
            {
                temp->val=temp->next->val;
                temp->next=temp->next->next;
                return;
            }

            temp=temp->next;
            i++;
        }
        
    }
    void reverse(){
        Node*prev=NULL;
        Node*current=head;
        Node* nextNode=current->next;
        while(current ){
            current->next=prev;
            prev=current;
            current=nextNode;
            if(nextNode)
            nextNode=nextNode->next;
        }
        head=prev;
    }
    void ConvertArrayToLL(int arr[],int n){
        for(int i=0;i<n;i++){
            push_back(arr[i]);    
        }
    }
    int Size(){
        if(!head)return 0;
        Node*slow=head;
        Node*fast=head;
        int size=1;
        while(fast->next and fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
            size++;
        }
        if(!fast->next){
            return size+size-1;
        }
            return size+size;
        

    }
    void Move(){
        int n;
        cout<<"Enter the number of nodes to move: ";
        cin>>n;
        Node*temp=head;
        n%=Size();
        //1 2 3 4 5 
        Node*targetNode=head;
        for(int i=1;i<n and temp;i++){
            targetNode=targetNode->next;
        }
        head=targetNode->next;
        targetNode->next=NULL;
        tail->next=temp;
        tail=targetNode;

    }
    //1 2 3 4 5
    void partitionEvenAndOdd(){
        Node*temp=head;
        while(temp and temp->val%2==0){
            temp=temp->next;
        }
        Node*firstOdd=temp;
        Node* lastEven=NULL;
        while(temp){
            if(temp->next and temp->next->val%2==0){
                Node*EvenNode=temp->next;
                temp->next=temp->next->next;
                if(!lastEven){
                    EvenNode->next=firstOdd;
                    lastEven=EvenNode;
                    head=lastEven;

                }else{
                    lastEven->next=EvenNode;
                    EvenNode->next=firstOdd;
                    lastEven=EvenNode;
                }
                
            }
            else
            {
                temp=temp->next;
            }
        }
        tail=temp;

    }
};
LinkedList ConvertArrayToLL(int arr[],int n){
    LinkedList ll;
    ll.ConvertArrayToLL(arr,n);
    return ll;

}
int main(){
    LinkedList ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(2);
    // ll.push_back(4);
    // ll.push_back(5);
    // ll.push_back(6);
    // ll.push_back(7);
    // ll.push_back(8);
    // ll.push_back(5);
    cout<<ll.Size()<<endl;
    ll.print();
    // ll.Move();
    ll.partitionEvenAndOdd();
    ll.print();
    

           
           
           
return 0;
}