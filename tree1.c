#include<stdio.h>
#include<stdlib.h>

int a[100];
int z=0;
struct binarytree
{
   int data;
   struct binarytree *left;
   struct binarytree *right;
};


void insertion(struct binarytree **root,int data)
{
   struct binarytree *newnode=(struct binarytree*)malloc(sizeof(struct binarytree));
   newnode->data=data;
   newnode->left=newnode->right=NULL;
   struct binarytree *temp = *root;
   struct binarytree *y = NULL;
   if(*root==NULL)
   {
      *root=newnode;  
   }
   else
   {
       while(temp!=NULL)
       {
          y=temp;
          if(data<temp->data)
          {
             temp=temp->left;
          }
          else
          {
            temp=temp->right;
          }
       }
       if(data<y->data)
       {
          y->left= newnode;
       }
       else
       {
         y->right=newnode;
       }
   }
}


void inorder(struct binarytree *root)
{
   if(root == NULL)
   {
     printf("i am returning form root == null\n");
     return;
   }
   else
   {
           printf("calling root->left \n");
           inorder(root->left);
           a[z++]=root->data;
           printf("  %d --> \n",root->data);
           printf("calling root->right \n");
           inorder(root->right);
   }
}
int main()
{
   struct binarytree *root=NULL;
   insertion(&root,4);
   insertion(&root,2);
   insertion(&root,3);
   insertion(&root,1);
   insertion(&root,7);
   insertion(&root,6);
   //insertion(&root,80);
   inorder(root);
   for(int i=0;i<z;i++)
   {
     printf("array %d\n",a[i]);
   }
}
