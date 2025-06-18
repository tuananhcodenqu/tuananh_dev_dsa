#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* createnode(int data){
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void pushfront(Node*& head, int x){
    Node* temp = createnode(x);
    temp->next = head;
    head = temp;
}
void pushback(Node*& head, int x){
    if(head == NULL){
        pushfront(head,x);
    }else{
        Node* last = createnode(x);
        Node* temp = head;
        while(temp->next !=NULL){
            temp=temp->next;
        }
        temp->next = last;
    }
}
void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
Node* Reverse(Node* head){
    Node*curr = head;
    Node* prev = NULL;
    while(curr !=NULL){
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
void reArrange(Node*& head){
   Node* slow = head, *fast = head->next;
   while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
   }
   Node* head1 = head;
   Node* head2 = slow->next;
   slow->next = NULL; //tách
   head2 = Reverse(head2);
   head = createnode(0);
   Node* curr = head;
   while(head1 || head2){
        if(head1){
            curr->next=head1;
            curr=curr->next;
            head1=head1->next;
        }
        if(head2){
            curr->next=head2;
            curr=curr->next;
            head2=head2->next;
        }
   }
   head = head->next;
}
int main(){
    Node*head =NULL;
    int n;cin>>n;
    int*a = new int[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
        pushback(head,a[i]);
    }
    reArrange(head);
    print(head);
}
