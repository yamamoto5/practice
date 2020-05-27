
void moveZeroes(int* nums, int numsSize){
    int i = 0, j = 0;
    
    for(j = 0; j < numsSize; j++)
    {
        if(nums[j] != 0)
        {
            if(j != i)
            {
                nums[i] = nums[j];
                nums[j] = 0;
            }
            i++;
        }
    }
}
/*
void moveZeroes(int* nums, int numsSize){
    int i = 0, j = 0;
    int temp = 0;
    
    for(i = 0; i < numsSize-1; i++)
    {
        for(j = 0; j < numsSize-1-i; j++)
        {
            if(nums[j] == 0 && nums[j+1] != 0)
            {
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
}*/
