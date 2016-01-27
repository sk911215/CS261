#include "cirListDeque.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
        
	 struct cirListDeque* q=NULL;

	/* Test your linked list in here! */
	printf("Hello from test code!\n");
    q=createCirListDeque();

	printf("\n\nTest cirListDeque....\n");
	printf("\n\nTest addBackCirListDeque\n");
    addBackCirListDeque(q,1);
    addBackCirListDeque(q, 2);
    addBackCirListDeque(q, 3);
    printf("The Linklist's content: [1,2,3]\n");
    printCirListDeque(q);


	printf("\n\nTest addFrontCirListDeque\n");
    addFrontCirListDeque(q,0);
    printf("The Linklist's content: [0,1,2,3]\n");
    printCirListDeque(q);

	printf("\n\nTest  frontCirListDeque\n");
    printf("The Linklist's content: [0,1,2,3]\n");
	printf("The first element of the Deque is:%f\n",frontCirListDeque(q));

	printf("\n\nTest  backCirListDeque\n");
    backCirListDeque(q);
    printf("The Linklist's content: [0,1,2,3]\n");
	printf("The back element of the Deque is:%f\n",backCirListDeque(q));


	printf("\n\nTest  removeFrontCirListDeque \n");
    removeFrontCirListDeque (q);
    printf("The Linklist's content: [1,2,3]\n");
	printf("Remove the first element of the Deque: ");
	 printCirListDeque(q);



	 printf("\n\nTest  removeBackCirListDeque\n");
     removeBackCirListDeque(q);
     printf("The Linklist's content: [1,2]\n");
	 printf("Remove the last element of the Deque: ");
	 printCirListDeque(q);


	 printf("\n\nTest  isEmptyCirListDeque\n");
     printf("The Linklist's content: [1,2]\n");

	 if(isEmptyCirListDeque(q))
	 {
		 printf("The Deque is empty ");
	 }
	 else
	 {
		  printf("The Deque is not empty ");
	 }


	 printf("\n\nTest  reverseCirListDeque\n");
	 addBackCirListDeque(q, 3);
	 addBackCirListDeque(q,4);
	 addBackCirListDeque(q,5);
     reverseCirListDeque(q);
	 printf("The Linklist's content: [5,4,3,2,1]\n");
	 printCirListDeque(q);
    printf("\n");
	 
   // system("pause");
	return 0;
}


