/*
 Course: CS261-002
 Name: Yunfan Li, Kai Shi
 Date: Oct,14th 2014;
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dynamicArray.h"

/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 or false.
   postcondition: if it is a number, num will hold
   the value of the number
*/
int isNumber(char *s, double *num)
{
	char *end;
	double returnNum;

	if(strcmp(s, "0") == 0)
	{
		*num = 0;
		return 1;
	}
	else 
	{
		returnNum = strtod(s, &end);
		/* If there's anythin in end, it's bad */
		if((returnNum != 0.0) && (strcmp(end, "") == 0))
		{
			*num = returnNum;
			return 1;
		}
	}
	return 0;  //if got here, it was not a number
}

int flag = 1;

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their sum is pushed back onto the stack.
*/
void add (struct DynArr *stack)
{
	/* FIXME: You will write this function */
    if (sizeDynArr(stack) >= 2) {
        TYPE firstNum = topDynArr(stack);
        popDynArr(stack);
        TYPE secondNum = topDynArr(stack);
        popDynArr(stack);
        
        TYPE result = firstNum + secondNum;
        pushDynArr(stack, result);
        
        flag = 1;
    }
    else
        flag = 0;
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their difference is pushed back onto the stack.
*/
void subtract (struct DynArr *stack)
{
	/* FIXME: You will write this function */
    if (sizeDynArr(stack)>= 2) {
        TYPE firstNum = topDynArr(stack);
        popDynArr(stack);
        TYPE secondNum = topDynArr(stack);
        popDynArr(stack);
        
        TYPE result = secondNum - firstNum;
        pushDynArr(stack, result);
        
        flag = 1;
    }
    else
        flag = 0;
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their quotient is pushed back onto the stack.
*/
void divide (struct DynArr *stack)
{
	/* FIXME: You will write this function */
    if (sizeDynArr(stack) >= 2) {
        TYPE firstNum = topDynArr(stack);
        popDynArr(stack);
        TYPE secondNum = topDynArr(stack);
        popDynArr(stack);
        
        TYPE result = secondNum / firstNum;
        pushDynArr(stack, result);
        
        flag = 1;
    }
    else
        flag = 0;
}

void time(struct DynArr *stack) {
    if (sizeDynArr(stack) >= 2) {
        TYPE firstNum = topDynArr(stack);
        popDynArr(stack);
        TYPE secondNum = topDynArr(stack);
        popDynArr(stack);
        
        TYPE result = firstNum * secondNum;
        pushDynArr(stack, result);
        
        flag = 1;
    }
    else
        flag = 0;
}

void power(struct DynArr *stack) {
    if (sizeDynArr(stack) >= 2) {
        TYPE firstNum = topDynArr(stack);
        popDynArr(stack);
        TYPE secondNum = topDynArr(stack);
        popDynArr(stack);
        
        TYPE result = pow(secondNum, firstNum);
        pushDynArr(stack, result);
        
        flag = 1;
    }
    else
        flag = 0;
}

void squaring(struct DynArr *stack) {
    if (sizeDynArr(stack) >= 1) {
        TYPE result = pow(topDynArr(stack), 2);
        popDynArr(stack);
        pushDynArr(stack, result);
        
        flag = 1;
    }
    else
        flag = 0;
}

void cubing(struct DynArr *stack) {
    if (sizeDynArr(stack) >= 1) {
        TYPE result = pow(topDynArr(stack), 3);
        popDynArr(stack);
        pushDynArr(stack, result);
        
        flag = 1;
    }
    else
        flag = 0;
}

void myAbs(struct DynArr *stack) {
    if (sizeDynArr(stack) >= 1) {
        TYPE result = topDynArr(stack) > 0 ? topDynArr(stack) : -topDynArr(stack);
        popDynArr(stack);
        pushDynArr(stack, result);
        
        flag = 1;
    }
    else
        flag = 0;
}

void squareRoot(struct DynArr *stack) {
    if (sizeDynArr(stack) >= 1) {
        TYPE result = sqrt(topDynArr(stack));
        popDynArr(stack);
        pushDynArr(stack, result);
        
        flag = 1;
    }
    else
        flag = 0;
}

void exponential(struct DynArr *stack) {
    if (sizeDynArr(stack) >= 1) {
        TYPE result = exp(topDynArr(stack));
        popDynArr(stack);
        pushDynArr(stack, result);
        
        flag = 1;
    }
    else
        flag = 0;
}

void naturalLog(struct DynArr *stack) {
    if (sizeDynArr(stack) >= 1) {
        TYPE result = log(topDynArr(stack));
        popDynArr(stack);
        pushDynArr(stack, result);
        
        flag = 1;
    }
    else
        flag = 0;
}

void baseLog(struct DynArr *stack) {
    if (sizeDynArr(stack) >= 1) {
        TYPE result = log10(topDynArr(stack));
        popDynArr(stack);
        pushDynArr(stack, result);
        
        flag = 1;
    }
    else
        flag = 0;
}

double calculate(int numInputTokens, char **inputString)
{
	int i;
	double result = 0.0;
	char *s;
	struct DynArr *stack;

	//set up the stack
	stack = createDynArr(20);
	// start at 1 to skip the name of the calculator calc
	for(i=1;i < numInputTokens;i++) 
	{
		s = inputString[i];
		// Hint: General algorithm:
		// (1) Check if the string s is in the list of operators.
		//   (1a) If it is, perform corresponding operations.
		//   (1b) Otherwise, check if s is a number.
		//     (1b - I) If s is not a number, produce an error.
		//     (1b - II) If s is a number, push it onto the stack

        if(strcmp(s, "+") == 0)
            add(stack);
        else if(strcmp(s,"-") == 0)
			subtract(stack);
        else if(strcmp(s, "/") == 0)
			divide(stack);
        else if(strcmp(s, "x") == 0)
            time(stack);
        else if(strcmp(s, "^") == 0)
            power(stack);
        else if(strcmp(s, "^2") == 0)
			/* FIXME: replace printf with your own function */
            squaring(stack);
		else if(strcmp(s, "^3") == 0)
			/* FIXME: replace printf with your own function */
            cubing(stack);
		else if(strcmp(s, "abs") == 0)
			/* FIXME: replace printf with your own function */
            myAbs(stack);
		else if(strcmp(s, "sqrt") == 0)
			/* FIXME: replace printf with your own function */
            squareRoot(stack);
		else if(strcmp(s, "exp") == 0)
			/* FIXME: replace printf with your own function */
            exponential(stack);
		else if(strcmp(s, "ln") == 0)
			/* FIXME: replace printf with your own function */
            naturalLog(stack);
		else if(strcmp(s, "log") == 0)
			/* FIXME: replace printf with your own function */
            baseLog(stack);
		else 
		{
			// FIXME: You need to develop the code here (when s is not an operator)
			// Remember to deal with special values ("pi" and "e")
            double *tmp = (double *)malloc(sizeof(double));
            
            if (isNumber(s, tmp))
                pushDynArr(stack, *tmp);
            else if(strcmp(s, "pi") == 0)
                pushDynArr(stack, 3.14159265);
            else if(strcmp(s, "e") == 0)
                pushDynArr(stack, 2.7182818);
            else
                flag = 0;
		}
	}	//end for 

	/* FIXME: You will write this part of the function (2 steps below) 
	 * (1) Check if everything looks OK and produce an error if needed.
	 * (2) Store the final value in result and print it out.
	 */
    if (sizeDynArr(stack) != 1)
        printf("There is an error in your input !\n");
    else {
        if (flag) {
            result = topDynArr(stack);
            popDynArr(stack);
            printf("The result is : %f\n", result);
        }
        else
            printf("There is an error in your input !\n");
    }
    
	return result;
}

int main(int argc , char** argv)
{
	// assume each argument is contained in the argv array
	// argc-1 determines the number of operands + operators
	if (argc == 1)
		return 0;
	calculate(argc,argv);
	return 0;
}
