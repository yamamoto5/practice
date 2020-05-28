int missingNumber(int* nums, int numsSize){
    int max = numsSize*(numsSize+1)/2;
    int i = 0;
    while(i < numsSize)
    {
        max -= nums[i++];
    }
    return max;
}
