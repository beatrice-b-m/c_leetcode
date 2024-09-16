// Leetcode, Easy, 9. Palindrome Number
// Beatrice Brown-Mulry
// 09/15/24

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    // init evalStr to the max  length for a 32-bit int
    char evalStr[12];

    // use snprintf to format the string and calculate its length
    int length = snprintf(evalStr, sizeof(evalStr), "%d", x);

    // cast the int to the evalStr char arr
    sprintf(evalStr, "%d", x);

    bool strIsPalindrome = true;
    for (int i = 0; i < (length / 2); i++) {
        if (evalStr[i] != evalStr[length - 1 - i]) {
            strIsPalindrome = false;
            break;
        }
    }

    return strIsPalindrome;
}

int main() {
    int testArr[4] = {121, -121, 10, 94449};
    for (int i = 0; i < 4; i++) {
        printf("Is %d a palindrome?", testArr[i]);

        bool strIsPalindrome = isPalindrome(testArr[i]);
        printf(" %d\n", strIsPalindrome);
    }

    return 0;
} 