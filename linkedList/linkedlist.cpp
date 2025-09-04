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
    ll.push_back(3);
    ll.push_front(9);
    ll.print();
    ll.reverse();
    int arr[]={1,3,5,7};
    LinkedList ll2=ConvertArrayToLL(arr,4);
    ll2.print();

           
           
           
return 0;
}