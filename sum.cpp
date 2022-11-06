#include <iostream>
//using namespace std;

#define _start main // this is a macro, it replaces _start with main

struct vector {
    int *data;
    int size;
};

int _start() 
{
    float sum;

    FILE * fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("numbers.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE); // exit if file not found
    
    while (
        (read = getline(&line, &len, fp)) != -1) {
        struct vector digits = {0, 0};
        sum = 0;
        digits.data = (int *) malloc(sizeof(int) * 100);

        // first number
        char *token = strtok(line, " ");
        digits.data[digits.size] = atoi(token);
        digits.size++;

        while (token != NULL) {
            token = strtok(NULL, " ");
            if (token != NULL) {
                digits.data[digits.size] = atoi(token);
                digits.size++;
            }
        }

        for (int i = 0; i < digits.size; i++) {
            sum += digits.data[i];
        }

        std::cout << "Sum: " << (int) sum << std::endl;
        free(digits.data);
    }

    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}

// Language: cpp
// Path: numbers.txt
// compile with: g++ sum.cpp -o sum
// run with: ./sum

