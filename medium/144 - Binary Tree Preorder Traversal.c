#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode treeNode;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define MAX_SIZE 10

typedef struct Stack
{
    int top;
    treeNode *data[MAX_SIZE];
} stack;

void  push(stack *list, treeNode *node)
{
    if(list->top >= MAX_SIZE - 1)
    {
        printf("Full");
    }
    else
    {
        list->top++;
        list->data[list->top] = node;
    }
}

treeNode *pop(stack *list)
{
    if(list->top > -1)
    {
		//printf("%d\n", list->data[list->top]->val);
        return list->data[(list->top)--];
    }
    else
    {
        printf("Empty");
    }
    return NULL;
}

int isEmpty(stack list)
{
    return list.top < 0 ? 1 : 0;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int *result = NULL;
    stack list = {0};
    treeNode *node = NULL;
	int count = 0;
    *returnSize = 0;
    if(!root || !returnSize)
    {
		//printf("NULL\n");
        return NULL;
    }
    
    list.top = -1;
    result = (int *)malloc(sizeof(int) * (count+1));
    push(&list, root);
    
	//printf("list[%d], root val = %d\n", list.top, root->val);
    while(!isEmpty(list))
    {
        node = pop(&list);
        result = (int *)realloc(result, sizeof(int) * (count+1));
        result[count++] = node->val;
        if(node->right)
        {
            push(&list, node->right);
        }
        if(node->left)
        {
            push(&list, node->left);
        }
        
    }
	*returnSize = count;
	printf("returnSize = %d\n", *returnSize);
    return result;
}

treeNode *root = NULL;

void insertTreeNode(int data)
{
   treeNode *tempNode = (treeNode*) malloc(sizeof(treeNode));
   treeNode *current;
   treeNode *parent;

   tempNode->val = data;
   tempNode->left = NULL;
   tempNode->right = NULL;

   //if tree is empty
   if(root == NULL) {
      root = tempNode;
	  //printf("root->val = %d\n", root->val);
   } else {
      current = root;
      parent = NULL;

      while(1) { 
         parent = current;
         
         //go to left of the tree
         if(data < parent->val) {
            current = current->left;                
            
            //insert to the left
            if(current == NULL) {
               parent->left = tempNode;
			   //printf("tempNode = %d\n", tempNode->val);
               return;
            }
         }  //go to right of the tree
         else {
            current = current->right;

            //insert to the right
            if(current == NULL) {
               parent->right = tempNode;
			   //printf("tempNode = %d\n", tempNode->val);
               return;
            }
         }
      }            
   }
}

int main()
{
	int i = 0;
	//treeNode *root = NULL;
	int returnSize = 0;
	int *result = NULL;
	int array[7] = { 27, 14, 35, 10, 19, 31, 42 };

    for(i = 0; i < 7; i++)
	{
        insertTreeNode(array[i]);
		//printf("%d\n", array[i]);
	}
	//printf("root = %d\n", root->val);
	result = preorderTraversal(root, &returnSize);
	//printf("returnSize = %d\n", returnSize);
    for(i = 0; i < returnSize; i++)
	{
		printf("%d\n", result[i]);
	}
	return 0;
}
