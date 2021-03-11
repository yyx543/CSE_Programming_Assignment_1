#include "shellPrograms.h"

/*
Count the number of lines in a file 
*/
int shellCountLine_code(char **args)
{

    /** TASK 6  **/
    // ATTENTION: you need to implement this function from scratch and not to utilize other system program to do this
    ssize_t line;
    char* buffer = NULL;
    size_t size = 0;
    int count = 0;
    // 1. Given char** args, open file in READ mode based on the filename given in args[1] using fopen()
    FILE* fp = fopen(args[1], "r");
    // 2. Check if file exists by ensuring that the FILE* fp returned by fopen() is not NULL
    if (fp != NULL){
    // 3. Read the file line by line by using getline(&buffer, &size, fp)
    // 4. Loop, as long as getline() does not return -1, keeps reading and increment the count
        while ((line = getline(&buffer, &size, fp)) != -1){
            count = count + 1;
            //fwrite(buffer, line, 1, stdout);
        }
    }
    // 6. Close the FILE*
    fclose(fp);
    // 7. Print out how many lines are there in this particular filename
    printf("There are %i\n lines", count);
    // 8. Return 1, to exit program

    return 1;
}

int main(int argc, char **args)
{
    return shellCountLine_code(args);
}