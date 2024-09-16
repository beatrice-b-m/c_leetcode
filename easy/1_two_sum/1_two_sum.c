// Leetcode, Easy, 1. Two Sum
// Beatrice Brown-Mulry
// 09/14/24

//  Note: The returned array must be malloced, assume caller calls free().
// actual main header for leetcode:
// int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

#include <stdlib.h>
#include <stdio.h>

#define NUMSSIZE 4

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *outArr = (int*)malloc(2 * sizeof(int));

    // check if malloc succeeded
    if (outArr == NULL) {
        return NULL;
    }

    // use outArr to store our incrementors so we don't need to make
    // separate variables for them
    for (outArr[0] = 0; outArr[0] < numsSize; outArr[0]++) {
        for (outArr[1] = outArr[0] + 1; outArr[1] < numsSize; outArr[1]++) {
            if (nums[outArr[0]] + nums[outArr[1]] == target) {
                *returnSize = 2;
                return outArr;
            }
        }
    }

    // if no sol was found return NULL
    return NULL;
}

int main() {
    int nums[NUMSSIZE] = {2, 7, 11, 15};
    int target = 9;
    int returnSize = 2;

    int* answerArr = twoSum(nums, NUMSSIZE, target, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", answerArr[i]);
    }
    
    return 0;
}