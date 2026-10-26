#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* output = malloc(2 * sizeof(int));
    
    for (int i = 0; i < numsSize; i++) {
        int goal = target - nums[i];
        
        for (int j = 0; j < i; j++) {
            if (nums[j] == goal) {
                output[0] = j;
                output[1] = i;
                *returnSize = 2;
                return output;  
            }
        }
    }

    *returnSize = 0;
    free(output);
    return NULL;
}