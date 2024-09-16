// Leetcode, Easy, 13. Roman to Integer
// Beatrice Brown-Mulry
// 09/15/24

// I             1
// V             5
// X             10
// L             50
// C             100
// D             500
// M             1000


#include <string.h>
#include <stdio.h>

int romanToInt(char* s) {
    int sum = 0, i = 0;

    while (s[i] != '\0') {
        char currChar = s[i];
        char nextChar = s[i+1]; // this should be '\0' on last it
        

        if (currChar == 'I') {
            // I can be placed before V (5) and X (10) to make 4 and 9.
            if (nextChar == 'V') {
                sum += 4;
                i++;
            } else if (nextChar == 'X') {
                sum += 9;
                i++;
            } else {
                sum += 1;
            }
        } else if (currChar == 'V') {
            sum += 5;
        } else if (currChar == 'X') {
            // X can be placed before L (50) and C (100) to make 40 and 90. 
            if (nextChar == 'L') {
                sum += 40;
                i++;
            } else if (nextChar == 'C') {
                sum += 90;
                i++;
            } else {
                sum += 10;
            }
        } else if (currChar == 'L') {
            sum += 50;
        } else if (currChar == 'C') {
            // C can be placed before D (500) and M (1000) to make 400 and 900.
            if (nextChar == 'D') {
                sum += 400;
                i++;
            } else if (nextChar == 'M') {
                sum += 900;
                i++;
            } else {
                sum += 100;
            }
        } else if (currChar == 'D') {
            sum += 500;
        } else /* must be 'M' */ {
            sum += 1000;
        }
        
        i++;
    }

    return sum;
}

int main() {
    char s[] = "MCMXCIV";
    // printf("%s", s);

    printf("%s -> %d", s, romanToInt(s));

    return 0;
}