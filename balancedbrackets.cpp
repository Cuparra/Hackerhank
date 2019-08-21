#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();

// Complete the isBalanced function below.

// Please either make the string static or allocate on the heap. For example,
// static char str[] = "hello world";
// return str;
//
// OR
//
// char* str = "hello world";
// return str;
//

int isMatch(char a, char b){

    if(b == ']' && a == '[')
        return 1;
    if(b == '}' && a == '{')
        return 1;
    if(b == ')' && a == '(')
        return 1;

    return 0;
}


char* isBalanced(char* s) {
    
    int sizeOfStack = 0;
    size_t n        = strlen(s);
    char *stack     = (char *)malloc(n*sizeof(char));
    
    char *no = "NO\0";
    char *yes = "YES\0";
    
    for(int j=0; j < n;j++){

        if(s[j] == '(' || s[j] == '{' || s[j] == '[')
            stack[sizeOfStack++] = s[j];

        else if(s[j] == ')' || s[j] == '}' || s[j] == ']'){

            if(sizeOfStack == 0)
                return no;

            else if(!isMatch(stack[--sizeOfStack], s[j]))
                return no;
        }
    }

    if(sizeOfStack == 0)
        return yes;
    
    return no;
}

int main() {
    int t; 
    scanf("%i", &t);
    for(int a0 = 0; a0 < t; a0++){
        char* s = (char *)malloc(512000 * sizeof(char));
        scanf("%s", s);
        int result_size;
        char* result = isBalanced(s);
        printf("%s\n", result);
    }
    return 0;
}
