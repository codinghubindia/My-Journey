#include<stdio.h>

int stack[100];
int top = -1;

void push(int elem) {
    stack[top++] = elem;
    return;
}

void pop() {
    if(top == -1) {
        printf("Stack is Empty");
    } else {
        top--;
    }
}

void display () {
    for(int i = top; i >= 0; i--) printf("%d",stack[i]);
}

int main() {
    
}