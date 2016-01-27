#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main(int argc, char* argv[]) {
        

	/* Test your linked list in here! */
	 struct linkedList* linkL;
	 TYPE i;

    linkL=createLinkedList();	
	printf("Hello from test code!\n");

	printf("\n\nTest Deque....\n");
	
	printf("\n\nTest addBackList\n");
    addBackList(linkL,1);
    addBackList(linkL, 2);
    addBackList(linkL, 3);
    printf("The Linklist's content: [1,2,3]\n");
     _printList(linkL);

	printf("\n\nTest addFrontList\n");
	 addFrontList(linkL,0);
	 printf("The Linklist's content: [0,1,2,3]\n");
	  _printList(linkL);
	   
	  printf("\n\nTest  frontList \n"); 
	  i=frontList(linkL);
	  printf("The Linklist's content: [0,1,2,3]\n");
	  printf("The front element is:%d\n",i);

	printf("\n\nTest backList \n"); 
	  i=backList(linkL);
	  printf("The Linklist's content: [0,1,2,3]\n");
	  printf("The back element is:%d\n",i);

	   printf("\n\nTest removeFrontList \n"); 
	  removeFrontList(linkL);
	  printf("The Linklist's content: [1,2,3]\n");
	  _printList(linkL);

	  printf("\n\nTest removeBackList \n"); 
	  removeBackList(linkL);
	  printf("The Linklist's content: [1,2]\n");
	  _printList(linkL);


	  printf("\n\nTest Stack....\n");
	  printf("\n\nTest addList\n"); 
	  addList(linkL,0);
	  printf("The Linklist's content:  top----> [0,1,2]\n");
	   _printList(linkL);

	  printf("\n\nTest containsList\n"); 
	  printf("The Linklist's content:  top----> [0,1,2]\n");
      printf("Find 1\n"); 
	  if(containsList(linkL,1))
		  printf("Have the element 1\n"); 
	  else
		   printf("Don't have the element 1\n"); 
	  printf("Find 5\n"); 
	  if(containsList(linkL,5))
		  printf("Have the element 5\n"); 
	  else
		   printf("Desn't have the element 5\n");

	   printf("\n\nTest removeList \n"); 
	   printf("The Linklist's content:  top----> [0,1,2]\n");
	   printf("Remove 1\n");
	   removeList (linkL,1);
	   _printList(linkL);
	  
	  





	system("pause");
	return 0;
}


