/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX_NODE 100
typedef struct Stack
{
    int top;
    struct TreeNode *node[MAX_NODE];
} stack;

void push(stack *list, struct TreeNode *node)
{
    if(list->top < MAX_NODE-1)
    {
        list->node[++list->top] = node;
    }
}

struct TreeNode *pop(stack *list)
{
    if(list->top >= 0)
        return list->node[(list->top)--];
    return NULL;
}

int isEmpty(stack *list)
{
    return list->top < 0 ? 1 : 0;
}

struct TreeNode *topNode(stack *list)
{
    return list->node[list->top];
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    stack list = {0};
    int count = 0;
    int top = 0;
    int *array = (int *)malloc(sizeof(int)*(count+1));
    struct TreeNode *temp = NULL;
    struct TreeNode *curr = NULL;
    memset(array, 0x0, sizeof(int));
    
    list.top = -1;
    *returnSize = 0;
    if(!root)
    {
        return array;
    }
    push(&list, root);
    while(!isEmpty(&list))
    {
        curr = topNode(&list);
        if((!curr->left && !curr->right) || (temp && (temp == curr->left || temp == curr->right) ))
        {
            temp = pop(&list);
            array = (int *)realloc(array, sizeof(int)*(count+1));
            array[count++] = curr->val;
            temp = curr;
        }
        else
        {
            if(curr->right)
            {
                push(&list, curr->right);
            }
            if(curr->left)
            {
                push(&list, curr->left);
            }
        }

    }
    *returnSize = count;
    return array;
}
