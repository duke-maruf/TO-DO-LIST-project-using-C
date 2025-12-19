#include <stdio.h>
#include "file_handling.h"
#include "main.h"

void saveTasksToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "[\n");
    for (int i = 0; i < numTasks; i++) {
        fprintf(file, "  {\n");
        fprintf(file, "    \"description\": \"%s\",\n", tasks[i].description);
        fprintf(file, "    \"completed\": %s\n", tasks[i].completed ? "true" : "false");
        fprintf(file, "  }%s\n", i < numTasks - 1 ? "," : "");
    }
    fprintf(file, "]\n");

    fclose(file);
}

void loadTasksFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("No existing tasks file found.\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        // Future parsing logic can be added here
    }

    fclose(file);
}
