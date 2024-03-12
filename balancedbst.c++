#include "bits/stdc++.h"

using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

void printpreorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }
    std::cout<<root->data<<" ";
    printpreorder(root->left);
    printpreorder(root->right);
}


Node* insertBST(Node* root, int val)
{
    if(root==NULL)
    {
        return new Node(val);
    }
    if(val<root->data)
    {
        root->left=insertBST(root->left,val);
    }
    else
    {
        root->right=insertBST(root->right,val);
    }
    return root;
}

Node* sortedarray(int arr[],int start, int end)
{
    if(start>end)
    {
        return NULL;
    }
    int mid=(start+end)/2;
    Node* root= new Node(arr[mid]);

    root->left=sortedarray(arr,start,mid-1);
    root->right=sortedarray(arr,mid+1,end);
    return root;
}

int main()
{
    int arr[]={10,20,30,40,50};
    Node* root=sortedarray(arr,0,4);
    printpreorder(root);
    cout<<endl;
    return 0;
}

