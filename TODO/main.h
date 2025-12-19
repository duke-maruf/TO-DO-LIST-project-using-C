#ifndef MAIN_H
#define MAIN_H

#define MAX_TASKS 100
#define MAX_TASK_LENGTH 50
#define FILENAME "tasks.txt"

struct Task {
    char description[MAX_TASK_LENGTH];
    int completed;
};

extern struct Task tasks[MAX_TASKS];
extern int numTasks;

void addTask(char description[]);
void viewTasks();
void markCompleted(int index);
void removeTask(int index);  // Added the prototype for removeTask

#endif
