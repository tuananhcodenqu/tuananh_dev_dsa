#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
};
Node* insertNode(Node* node, int data){
    if(node == NULL){
        node = new Node;
        node->data=data;
        node->left = NULL;
        node->right=NULL;
    }else if(data < node->data){
        node->left=insertNode(node->left,data);
    }else{
        node->right=insertNode(node->right,data);
    }
    return node;
}
// DUYỆT CÂY THEO LNR : đệ quy
void LNR(Node* node){
    if(node !=NULL){
        LNR(node->left);
        cout << node->data << " ";
        LNR(node->right);
    }
}
//NLR
void NLR(Node* node){
    if(node!=NULL){
        cout << node->data << " ";
        NLR(node->left);
        NLR(node->right);
    }
}
//LRN
void LRN(Node* node){
    if(node!=NULL){
        LRN(node->left);
        LRN(node->right);
        cout << node->data << " ";
    }
}
// node trên cây có duy nhất 1 node con
void printOneChildNodes(Node* node){
    if(node!=NULL){
        if((node->left != NULL && node->right ==NULL) || (node->right != NULL && node->left ==NULL)){
            cout << node->data << " ";
        }
        printOneChildNodes(node->left);
        printOneChildNodes(node->right);
    }
}
// đếm số nút lá trên cây, nút lá: k có nút con nào
int countLeafNodes(Node* node){
    if(node == NULL) return 0;
    if(node->left ==NULL && node->right == NULL) return 1;
    return countLeafNodes(node->left) + countLeafNodes(node->right);
}
// in các node ở mức k được chấp nhận từ bàn phím
void printLevelK(Node *node, int k){
    if(node == NULL) return;
    if(k==0) cout << node->data << " ";
    else{
        printLevelK(node->left,k-1);
        printLevelK(node->right,k-1);
    }
}
// Xóa node có giá trị nhỏ nhất
Node* DeleteMinNode(Node* node){
    if(node==NULL) return node;
    else if(node->left!=NULL)
        node->left=DeleteMinNode(node->left);
    else{
        Node*temp=node;
        node=node->right;
        delete temp;
    }
    return node;
}
// Tìm giá trị node lớn nhất trên cây
int FindMaxNode(Node* root){
    while(root!=NULL &&root->right!=NULL){
        root=root->right;
    }
    return root ? root->data : -1;
}
// Hàm kiểm tra số đặc biệt (vd n=59, 59=(5*9) + (5+9))
bool isSpecial(int n){
    int sum=0,product=1,m=n; // sum là tổng, product là tích
    while(m>0){
        int digit = m%10;
        sum+=digit;
        product*=digit;
        m/=10;
    }
    if(sum+product==n) return true;
    return false;
}
int CountSpeNums(Node *root){
    if(!root) return 0;
    int count = isSpecial(root->data) ? 1:0;
    count+=CountSpeNums(root->left);
    count+=CountSpeNums(root->right);
    return count;
}
int main(){
    Node* root =NULL;
    int n; cout << "Enter the number of nodes: "; cin >> n;
    cout << "Enter value of each node: ";
    for(int i=0;i<n;i++){
        int data;cin>>data;
        root=insertNode(root,data);
    }
    cout << "LNR: "; LNR(root);cout<<endl;
    cout << "NLR: "; NLR(root);cout<<endl;
    cout << "LRN: "; LRN(root);cout<<endl;
    cout << "Node with only one child: ";printOneChildNodes(root);cout << endl;
    cout << "Number of leaf nodes: " << countLeafNodes(root) << endl;
    int k;
    cout << "Enter the level k to print: "; cin >> k;
    printLevelK(root,k); cout << endl;
    root = DeleteMinNode(root);
    cout << "Max value in tree: " << FindMaxNode(root) << endl;
    cout << "Number of special numbers in tree: " << CountSpeNums(root);
    return 0;
}
