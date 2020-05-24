int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i = 0, j = 0;
    bool flag = false;
    int *array = NULL;
    *returnSize = 0;
    for(i = 0; i < numsSize; i++)
    {
        if(flag)
        {
            break;
        }
        for(j = 0; j < numsSize; j++)
        {
            if(i != j)
            {
                if(nums[i] + nums[j] == target)
                {
                    flag = true;
                    break;
                }
            }
        }
    }
    if(flag)
    {
        array = (int *)malloc(sizeof(int)*2);
        memset(array, 0, sizeof(int)*2);
        array[0] = i-1;
        array[1] = j;
        *returnSize = 2;
        return array;
    }
    return NULL;
}
