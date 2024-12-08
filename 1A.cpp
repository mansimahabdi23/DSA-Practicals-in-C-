
#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;
    node(int d){
        this->data=d;                    
        this->left=NULL;
        this->right=NULL;
    }
};
//1.inserting nodes
node* buildTree(node* root){
    int data;
    cout <<"Enter the data:"<<endl;
    cin>>data;
    root=new node(data);
    if(data==-1){
    return NULL;
    }

    cout<<"Enter data for left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter data for right of "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
    
}

//2.traversal of the tree
void leverOrderTraversal(node* root){
    if (root==NULL)
    {
        return;
    }
    
    queue<node*> q;
    q.push(root);
    
   while(!q.empty()){

    node* temp = q.front();
    cout<<temp->data<<" ";
    q.pop();

    if(temp -> left){

        q.push(temp->left);
    }
    if(temp->right){

        q.push(temp->right);
    }
   }
    
    


}

//3.to find the dept of the tree
int findDepth(node* root){
    if (root == NULL) {
        return 0;
    }

    int left_depth = findDepth(root->left);
    int right_depth = findDepth(root->right);
    
    return max(left_depth, right_depth) + 1;
}

//4.display leaf nodes

void displayLeafNodes(node* root){
    if(root==NULL){
        return;
    }
    //leaf node:
    if(root->left==NULL && root->right==NULL){
        cout<<root->data<<endl;
    }
    displayLeafNodes(root->left);
    displayLeafNodes(root->right);
    
}

//5.Creating a copy of tree
node* copyTree(node* root){
if(root==NULL){
    return NULL;
}
node* newNode = new node(root->data);
newNode->left = copyTree(root->left);
newNode->right = copyTree(root->right);
return newNode;
}
int main(){
    node* root=NULL;
    root=buildTree(root);
    
    cout<<"Printing Level Order Traversal"<<endl;
    leverOrderTraversal(root);
    
    int depth = findDepth(root);
    cout << "The depth of the tree is: " << depth << endl;
    
    cout<<"Displaying the leaf node of the tree:"<<endl;
    displayLeafNodes(root);
    
    node* copied_tree = copyTree(root);
    cout<<"Displaying the copied tree using level order traversal:"<<endl;
    leverOrderTraversal(copied_tree);
    
    
    return 0;
}
//1 3 7 -1 -1 2 9 -1 -1 -1 5 12 -1 -1 -1