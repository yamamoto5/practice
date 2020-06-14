/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX_NODE 100
typedef struct Stack{
    int top;
    struct TreeNode *node[MAX_NODE];
} stack;

void push(stack *stackNode, struct TreeNode *node)
{
    if(!stackNode || !node || stackNode->top >= MAX_NODE)
    {
        return;
    }
    stackNode->node[++stackNode->top] = node;
}

struct TreeNode *pop(stack *stackNode)
{
    if(!stackNode || stackNode->top <= -1)
    {
        return NULL;
    }
    return stackNode->node[(stackNode->top)--];
}

int isEmpty(stack *stackNode)
{
    return stackNode->top < 0 ? 1 : 0;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int *array = (int *)malloc(sizeof(int));
    stack list = {0};
    int count = 0;
    //struct TreeNode *node = NULL;
    
    list.top = -1;
    *returnSize = 0;
    //push(&list, root);
    while(root || !isEmpty(&list))
    {
        if(root)
        {
            push(&list, root);
            root = root->left;
        }
        else
        {
            root = pop(&list);
            array = realloc(array, sizeof(int)*(count+1));
            array[count++] = root->val;
            //push(&list, root->right);
            root = root->right;
        }
    }
    *returnSize = count;
    return array;
}
