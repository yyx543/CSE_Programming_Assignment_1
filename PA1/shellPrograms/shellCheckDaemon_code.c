#include "shellPrograms.h"

/*  A program that prints how many summoned daemons are currently alive */
int shellCheckDaemon_code() {
    /* TASK 8 */
    //Create a command that trawl through output of ps -efj and contains "summond"
    char* command = malloc(sizeof(char) * 256);
    sprintf(command, "ps -efj | grep summond  | grep -v grep > output.txt");

    // TODO: Execute the command using system(command) and check its return value
    if (system(command) == -1) {
        return EXIT_FAILURE;
    }

    free(command);

    int live_daemons = 0;
    // TODO: Analyse the file output.txt, wherever you set it to be. You can reuse your code for countline program
    // 1. Open the file
    // 2. Fetch line by line using getline()
    // 3. Increase the daemon count whenever we encounter a line
    // 4. Close the file
    // 5. print your result

    // Copy from Task 6
    ssize_t line;
    char* buffer = NULL;
    size_t size = 0;
    // 1. Given char** args, open file in READ mode based on the filename given in args[1] using fopen()
    FILE* fp = fopen("output.txt", "r");
    // 2. Check if file exists by ensuring that the FILE* fp returned by fopen() is not NULL
    if (fp != NULL) {
        // 3. Read the file line by line by using getline(&buffer, &size, fp)
        // 4. Loop, as long as getline() does not return -1, keeps reading and increment the live_daemons
        while ((line = getline(&buffer, &size, fp)) != -1) {
            live_daemons++;
            //fwrite(buffer, line, 1, stdout);
        }
    }
    // 6. Close the FILE*
    fclose(fp);

    if (live_daemons == 0)
        printf("No daemon is alive right now\n");
    else {
        printf("There are in total of %d live daemons \n", live_daemons);
    }

    // TODO: close any file pointers and free any statically allocated memory

    return 1;
}

int main(int argc, char** args) {
    return shellCheckDaemon_code();
}