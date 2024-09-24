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

// Function to Display the elements in an array
void display(char ar[],int size) {
    for(int i =0; i < size; i++) printf("%c",ar[i]);  //for loop to Print The elements of Array
    printf("\n");
}

// Function to check the priority of the Operator
int priority(char elem) {
    if(elem == '^') return 3;
    else if(elem == '/' || elem == '*' || elem == '%') return 2;
    else if(elem == '+' || elem == '-') return 1;
    else return 0;
}

// Function to Conver the infix expression to Postfix expression
int infixtopostfix() {
    int i = 0;
    int j = 0;
    while(infix[i] != '\0') {
        if(isalnum(infix[i])) {
            postfix[j++] = infix[i++];
        } else if(infix[i] == '(') {
            push(infix[i++]);
        } else if(infix[i] == ')') {
            while(stack[top] != '(') {
                postfix[j++] = stack[top];
                pop();
            }
            pop();
        } else {
            if(top == -1) {
                push(infix[i++]);
            } else {
                while(priority(stack[top]) >= priority(infix[i])) {
                    postfix[j++] = stack[top];
                    pop();
                }
                push(infix[i++]);
            }
        }
    }

    for(int n = top; n >= 0; n--) {
        postfix[j++] = stack[top];
        pop();
    }

    return j;
}

// Main function
int main() {
    printf("Enter the Infix Expression\n");
    scanf("%s",infix);

    int s = infixtopostfix();
    display(postfix, s);

    return 0;

}