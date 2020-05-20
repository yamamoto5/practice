typedef struct {
    int size;
    int *sum;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *array = (NumArray *)malloc(sizeof(NumArray));
    array->size = numsSize;
    array->sum = (int *)malloc(sizeof(int)*numsSize);

    int temp = 0;
    for(int i=0; i<numsSize; i++)
    {
        temp += nums[i];
        array->sum[i] = temp;
    }
    
    return array;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    if(i==0)
        return obj->sum[j];
    return obj->sum[j] - obj->sum[i-1];
}

void numArrayFree(NumArray* obj) {
    free(obj->sum);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 
 * numArrayFree(obj);
*/
