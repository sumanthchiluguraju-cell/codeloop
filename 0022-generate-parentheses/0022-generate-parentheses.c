#include <stdlib.h>
#include <string.h>

void backtrack(char **result, int *returnSize, char *current,
               int open, int close, int n) {

    if (strlen(current) == 2 * n) {
        result[*returnSize] = (char *)malloc((2 * n + 1) * sizeof(char));
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }

    int len = strlen(current);

    if (open < n) {
        current[len] = '(';
        current[len + 1] = '\0';
        backtrack(result, returnSize, current, open + 1, close, n);
        current[len] = '\0';      // Backtrack
    }

    if (close < open) {
        current[len] = ')';
        current[len + 1] = '\0';
        backtrack(result, returnSize, current, open, close + 1, n);
        current[len] = '\0';      // Backtrack
    }
}

char** generateParenthesis(int n, int* returnSize) {

    *returnSize = 0;

    int capacity = 1500;
    char **result = (char **)malloc(capacity * sizeof(char *));

    char current[20] = "";

    backtrack(result, returnSize, current, 0, 0, n);

    return result;
}