#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


int main (int argc, const char * argv[])
{
    char cmd = ' ';
    DynArr* mainList = createDynArr(10);
    
    char filename[100], desc[TASK_DESC_SIZE];
    char *sptr = (char *)malloc(sizeof(char));
    int priority = 0;
	TaskP v;
	FILE *fp;

	printf("\n\n** TO-DO LIST APPLICATION **\n\n");

	do
    {
		printf("Press:\n"
             "'l' to load to-do list from a file (will add to current open list)\n"
             "'s' to save to-do list to a file\n"
             "'a' to add a new task\n"
             "'g' to get the first task\n"
             "'r' to remove the first task\n"
             "'p' to print the list\n"
             "'e' to exit the program\n"
             );
		/* get input command (from the keyboard) */
		cmd = getchar();
		/* clear the trailing newline character */
		while (getchar() != '\n');
		/* Fixed */
		switch(cmd)
		{
            case 'l':
                printf("Please enter the filename:");
                if (fgets(filename, sizeof(filename), stdin) != NULL) {
                    sptr = strchr(filename, '\n');
                    if (sptr)
                        *sptr = '\0';
                }
                fp = fopen(filename, "r");
                if (fp == NULL) {
                    printf("Cannot open %s\n\n", filename);
                    break;
                }
                loadList(mainList, fp);
                fclose(fp);
                printf("The list has been loaded from file successfully!\n\n");
                break;
            case 's':
                if (sizeDynArr(mainList) > 0) {
                    if (fgets(filename, sizeof(filename), stdin) != NULL) {
                        sptr = strchr(filename, '\n');
                        if (sptr)
                            *sptr = '\0';
                    }
                    fp = fopen(filename, "w");
                    if (fp == NULL) {
                        printf("Cannot open %s\n\n", filename);
                        break;
                    }
                    saveList(mainList, fp);
                    fclose(fp);
                    printf("The list has been saved into the file successfully!\n\n");
                }
                else
                    printf("Your list is empty!\n\n");
                break;
            case 'a':
                printf("Please enter a desription of your task:");
                if(fgets(desc, sizeof(desc), stdin) != NULL) {
                    sptr = strchr(desc, '\n'); // remove Newline
                    if(sptr)
                        *sptr = '\0';
                }
                do{
                    printf("Please enter the priority of your new task(0-999):");
                    scanf("%d", &priority);
                }while(!(priority >= 0 && priority <= 999));
                while(getchar() != '\n'); // clear buffer
                v = createTask(priority, desc);
                addHeap(mainList, v, compare);
                printf("The task '%s' has been added to your list. \n\n", desc);
                break;
            case 'g':
                if(sizeDynArr(mainList) > 0) {
                    v = (TaskP)getMinHeap(mainList);
                    printf("Your first task is '%s'.\n\n", v->description);
                }
                else
                    printf("Your list is empty\n\n");
                break;
            case 'r':
                if(sizeDynArr(mainList) > 0) {
                    v = (TaskP)getMinHeap(mainList);
                    removeMinHeap(mainList, compare);
                    printf("Task '%s' has been removed.\n\n", v->description);
                    free(v); // free the memory so newTask can be pointed elsewhere
                }
                else
                    printf("Your list is empty\n\n");
                break;
            case 'p':
                if (sizeDynArr(mainList) > 0)
                    printList(mainList);
                else
                    printf("Your list is empty!\n\n");
                break;
        }
	}while(cmd != 'e');
	/* delete the list */
	deleteDynArr(mainList);
	return (0);
}