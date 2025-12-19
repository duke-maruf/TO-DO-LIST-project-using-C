#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#include "file_handling.h"

struct Task tasks[MAX_TASKS];
int numTasks = 0;

void addTask(char description[]) {
    if (numTasks < MAX_TASKS) {
        strcpy(tasks[numTasks].description, description);
        tasks[numTasks].completed = 0;
        numTasks++;
        printf("Task added successfully!\n");
    } else {
        printf("Sorry, the task list is full.\n");
    }
}

void viewTasks() {
    if (numTasks == 0) {
        printf("No tasks available.\n");
    } else {
        printf("Tasks:\n");
        for (int i = 0; i < numTasks; i++) {
            printf("%d. [%s] %s\n", i + 1, tasks[i].completed ? "Completed" : "Incomplete task", tasks[i].description);
        }
    }
}

void markCompleted(int index) {
    if (index >= 1 && index <= numTasks) {
        tasks[index - 1].completed = 1;
        printf("Task marked as completed.\n");
    } else {
        printf("Invalid task number.\n");
    }
}

void removeTask(int index) {
    if (index >= 1 && index <= numTasks) {
        for (int i = index - 1; i < numTasks - 1; i++) {
            tasks[i] = tasks[i + 1];  // Shift the tasks up
        }
        numTasks--;  // Decrease the task count
        printf("Task removed successfully.\n");
    } else {
        printf("Invalid task number.\n");
    }
}

int main() {
    loadTasksFromFile(FILENAME);

    int choice, index;
    char description[MAX_TASK_LENGTH];

    do {
        printf("\nTodo List Menu:\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Mark Task as Completed\n");
        printf("4. Remove Task\n");  // Added Remove Task option
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task description: ");
                getchar();  // To consume the newline from previous input
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = '\0';  // Remove trailing newline
                addTask(description);
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                printf("Enter task number to mark as completed: ");
                scanf("%d", &index);
                markCompleted(index);
                break;
            case 4:
                printf("Enter task number to remove: ");
                scanf("%d", &index);
                removeTask(index);
                break;
            case 5:
                printf("Saving tasks to file...\n");
                saveTasksToFile(FILENAME);
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
