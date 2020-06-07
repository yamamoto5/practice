

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int count = 0;
    int lo = 0, hi = numbersSize-1;
    *returnSize = 2;
    int *array = (int *)malloc(sizeof(int)**returnSize);
    
    for(;;)
    {
        if(numbers[lo] + numbers[hi] < target)
            lo++;
        else if(numbers[lo] + numbers[hi] > target)
            hi--;
        else
        {
            array[0] = lo+1;
            array[1] = hi+1;
            return array;
        }
        count++;
        if(count >= numbersSize-1)
            break;
    }
    return NULL;
}
