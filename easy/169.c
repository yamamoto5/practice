int majorityElement(int* nums, int numsSize){
    int i = 0;
    int temp = 0;
    int count = 0;
    
    for(i = 0; i < numsSize; i++)
    {
        if(count == 0)
        {
            temp = nums[i];
            count++;
        }
        else
        {
            if(temp == nums[i])
            {
                count++;
            }
            else
            {
                count--;
            }
        }
    }
    return temp;
}
/*int majorityElement(int* nums, int numsSize){
    int i = 0, j = 0;;
    int temp = 0;
    
    for(i = 0; i < numsSize - 1; i++)
    {
        for(j = 0; j < numsSize-1-i; j++)
        {
            if(nums[j] > nums[j+1])
            {
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
        
    }
    return nums[numsSize/2];
}*/
