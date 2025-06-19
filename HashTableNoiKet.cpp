#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* createNode(int data){
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
Node* Insert(int x, int M, vector<Node*>&Hash){
    int k = x%M;
    Node* temp = createNode(x);
    if(Hash[k]==NULL) Hash[k]=temp;
    else{
        Node* q = Hash[k];
        while(q->next){
            q=q->next;
        }
        q->next=temp;
    }
}
int timKhoa(int x, int M, vector<Node*>Hash){
    int dem=1;
    int k = x%M;
    Node* temp = Hash[k];
    while(temp){
        if(x==temp->data){
            return dem;
        }
        dem++;
        temp=temp->next;
    }
    return 0;
}
Node* Delete(int x, int M, vector<Node*>&Hash){
    int k = x%M;
    Node* curr = Hash[k];
    Node* prev = NULL;
    while(curr){
        if(curr->data == x){
            if(prev==NULL){
                Hash[k] =  curr->next;
                delete curr;
                return Hash[k];
            }else{
                Node* temp = curr;
                prev->next=temp->next;
                delete temp;
            }
        }
        prev=curr;
        curr=curr->next;
    }
    return Hash[k];
}
int main(){
    int M,N;
    float LOAD;
    cin>>M>>LOAD>>N;
    vector<Node*>Hash(M,NULL);
    vector<int>vt;
    for(int i=0;i<N;i++){
        int key;cin >> key;
        vt.push_back(key);
    }
    for(int i=0;i<min(N,(int)(M*LOAD));i++){
        Insert(vt[i],M,Hash);
    }
    int N2; cin >> N2;
    for(int i=0;i<N2;i++){
        int key; cin >> key;
        int pos = timKhoa(key, M, Hash);
        if (pos != 0)
            cout << pos << endl;
        else
            cout << "KHONG\n";
    }
}
