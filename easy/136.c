int singleNumber(int* nums, int numsSize){
    int i = 0, j = 0;
    for(i = 0; i < numsSize; i++)
    {
        j ^= nums[i];
    }
    return j;
}
/*
int singleNumber(int* nums, int numsSize){
    int i = 0, j = 0;
    int flag = 0;
    for(i = 0; i < numsSize; i++)
    {
        j = 0;
        flag = 0;
        for(j = 0; j < numsSize; j++)
        {
            if(j != i)
            {
                if(nums[i] == nums[j])
                {
                    flag = 1;
                    break;
                }
            }
        }
        if(flag == 0)
        {
            break;
        }
    }
    return nums[i];
}
*/
