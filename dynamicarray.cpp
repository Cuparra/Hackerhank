#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

/*
 * Complete the dynamicArray function below.
 */

/*
 * Please store the size of the integer array to be returned in result_count pointer. For example,
 * int a[3] = {1, 2, 3};
 *
 * *result_count = 3;
 *
 * return a;
 *
 */

typedef struct{
    int *list;
    int size;
}Seq;

int* dynamicArray(int n, int queries_rows, int queries_columns, int** queries, int* result_count){

    int z=0;
    int lastAnswer = 0;
    
    Seq *seq = (Seq*)malloc(n*sizeof(Seq));
    
    for(int i=0;i<n;i++){
        
        seq[i].list = NULL;
        seq[i].size = 0;
    }
    
    int *result = (int*)malloc(queries_rows*sizeof(int));
    
    for(int i=0;i<queries_rows;i++){
        
        int a = queries[i][0];
        int x = queries[i][1];
        int y = queries[i][2];
        
        if(a == 1){
            
            int pos                 = (x ^ lastAnswer) % n;
            int size                = seq[pos].size;
            seq[pos].list           = (int*)realloc(seq[pos].list,(size+1)*sizeof(int));
            seq[pos].list[size]     = y;
            ++seq[pos].size;
            
        }else{
            
            int pos             = (x ^ lastAnswer) % n;
            lastAnswer          = seq[pos].list[y % seq[pos].size];
            result[z++]         = lastAnswer;
        }
    }
    
    *result_count = z;
    
    return result;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** nq = split_string(readline());

    char* n_endptr;
    char* n_str = nq[0];
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

    char* q_endptr;
    char* q_str = nq[1];
    int q = strtol(q_str, &q_endptr, 10);
    int queries_rows, queries_columns;
    
    
    if (q_endptr == q_str || *q_endptr != '\0') { exit(EXIT_FAILURE); }

    int** queries = malloc(q * sizeof(int*));

    for (int queries_row_itr = 0; queries_row_itr < q; queries_row_itr++) {
        queries[queries_row_itr] = malloc(3 * (sizeof(int)));
        queries_rows = queries_row_itr;

        char** queries_item_temp = split_string(readline());

        for (int queries_column_itr = 0; queries_column_itr < 3; queries_column_itr++) {
            char* queries_item_endptr;
            char* queries_item_str = queries_item_temp[queries_column_itr];
            int queries_item = strtol(queries_item_str, &queries_item_endptr, 10);
            queries_columns = queries_column_itr;
            
            if (queries_item_endptr == queries_item_str || *queries_item_endptr != '\0') { exit(EXIT_FAILURE); }

            queries[queries_row_itr][queries_column_itr] = queries_item;
        }
    }

    int result_count;
    int* result = dynamicArray(n, queries_rows+1, queries_columns, queries, &result_count);

    for (int result_itr = 0; result_itr < result_count; result_itr++) {
        fprintf(fptr, "%d", result[result_itr]);

        if (result_itr != result_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}

