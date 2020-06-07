

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void merge(int *array, int front, int mid, int end)
{
    int i = 0, j = 0, k = 0;
    int a1_len = mid-front+1, a2_len = end-mid;
    int a1[mid-front+1];
    int a2[end-mid];
    
    for(i = 0; i<a1_len; i++)
    {
        a1[i] = array[front+i];
    }
    for(j = 0; j<a2_len; j++)
    {
        a2[j] = array[mid+j+1];
    }
    
    i = 0;
    j = 0;
    k = front;
    while(i<a1_len && j<a2_len)
    {
        if(a1[i] < a2[j])
        {
            array[k++] = a1[i++];
        }
        else
        {
            array[k++] = a2[j++];
        }
    }
    
    while(i < a1_len)
    {
        array[k++] = a1[i++];
    }
    
    while(j < a2_len)
    {
        array[k++] = a2[j++];
    }
}

void mergeSort(int *array, int front, int end)
{
    int mid = 0;
    if(front < end)
    {
        mid = (front+end)/2;
        mergeSort(array, front, mid);
        mergeSort(array, mid+1, end);
        merge(array, front, mid, end);
    }
}

int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    mergeSort(nums, 0, numsSize-1);
    return nums;
}
