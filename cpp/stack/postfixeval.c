#include<stdio.h>
#include<stdlib.h>

#define max 100

char stack[max];

int top = -1;

void push(int elem) {
    if(top >= max - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = elem;
}

int pop() {
    if(top < 0) {
        printf("Stack is Empty\n");
        return -1;
    }
    int item = stack[top--];
    return item;
}

int operator(char ch) {
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/') {
        return 1;
    }
    return 0;
}

int evaluate(char *exp) {
    int i = 0;
    char ch = exp[i];
    int num1, num2, result;
    while(ch != '\0') {
        if(ch >= )
    }
}