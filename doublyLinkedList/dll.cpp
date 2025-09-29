#include<iostream>
using namespace std;
class Node{
public:
    Node*next;
    Node*prev;
    int val;
    Node(){
        next=prev=nullptr;   
    }
    Node(int val){
        next=prev=nullptr;   
        this->val=val;
    }
};
class DLL{
private:
    Node* head;
    Node* tail;
public:
    DLL(){
        head=nullptr;
    }

    void addNodeToBeginning(int val){
        Node* newnode=new Node(val);
        if(!head){
            tail=newnode;
            head=newnode;
            head->next=nullptr;
        }else{
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
        }
    }

    void addToEnd(int val){
        if(!(head||tail)){
            addNodeToBeginning(val);
        }
        Node* newnode=new Node(val);
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
    void printReverse(){
        Node*temp=tail;
        while(temp){
            cout<<temp->val;
            if(temp->prev){
                cout<<"->";
            }
            temp=temp->prev;
        }
        cout<<endl;
    }
    void insertAtPosition(int val,int idx){
        if(idx<=0){
            cout<<"Enter a valid index"<<endl;
        }
        if(idx==1){
            addNodeToBeginning(val);
            return;
        }
        int curr=1;
        Node*temp=head;
        while(temp){
            if(curr+1==idx){
                Node* newnode=new Node(val);
                newnode->next=temp->next;
                temp->next=newnode;
                if(newnode->next){
                    newnode->next->prev=newnode;
                }
                newnode->prev=temp;
                return;
            }
            curr++;
            temp=temp->next;
        }
        cout<<"idx out of bounds"<<endl;
    }
    void deleteFromFront(){
        Node*temp=head;
        head=temp->next;
        head->prev=NULL;
        delete temp;
    }
    void deleteFromBack(){
        Node*temp=head;
        while (temp->next->next)
        {
            temp=temp->next;
        }
        temp->next->prev=nullptr;
        delete temp->next;
        temp->next=nullptr;
        tail=temp;
        
    }
    void deleteAtPosition(int position){
        if(position<=0){
            cout<<"please enter a valid position"<<endl;
        }
        if(position==1){
            deleteFromFront();
            return;
        }
        int idx=1;
        Node*temp=head;
        while(temp->next){
            if(idx+1==position){
                Node* toDelete=temp->next;
                temp->next=toDelete->next;
                if(toDelete->next){
                    toDelete->next->prev=toDelete->prev;
                }else{
                    tail=temp;
                }
                delete toDelete;
                return;
            }
            idx++;
            temp=temp->next;
        }
        cout<<"Please enter a valid position"<<endl;
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
        cout<<endl;
    }
    void reverse(){
        Node*temp=head;
        while (temp)
        {
            swap(temp->next,temp->prev);
            temp=temp->prev;
        }
        swap(head,tail);
        
    }
    void mergeTwoDLLs(DLL *list2 ){
        tail->next=list2->head;
        list2->head->prev=tail;
        tail=list2->tail;
    }

};
int main(){
    DLL dll;
    dll.addNodeToBeginning(3);
    dll.addNodeToBeginning(2);
    dll.addNodeToBeginning(1);
    dll.addNodeToBeginning(0);
    dll.insertAtPosition(-10,3);
    dll.print();
   DLL dll2;
   dll2.addNodeToBeginning(1);
   dll2.addNodeToBeginning(-12);
   dll2.addNodeToBeginning(2);
   dll2.addNodeToBeginning(3);
   dll2.addNodeToBeginning(5);
   dll.mergeTwoDLLs(&dll2);
   dll2.print();
   dll.print();
   dll.reverse();
   dll.print(); 


return 0;
}