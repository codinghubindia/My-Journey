#include<stdio.h>
#include<ctype.h>

//global variables
char stack[100],infix[100],postfix[100];  //array to manupulate data
int top = -1; //indicating stack has no element

// Function to push an element in stack
void push(char elem) {
    stack[++top] = elem;
}

// Function to Pop an element in stack
void pop() {
    if(top == -1) printf("Stack is Empty");
    else  top--;
}

// Function to Evaluate the Expression
void eval() {
    int i = 0;
    int j = 0;
    int elem1,elem2;
    while(postfix[i] != '\0') {
        if(isalnum(postfix[i])) {
            push(postfix[i]);
        } else {
            elem1 = stack[top];
            pop();
            elem2 = stack[top];
            pop();
            int ch = postfix[i];
            int ex = elem1 ch elem2;
            push(ch);
        }
    }
}


