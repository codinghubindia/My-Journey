#include<stdio.h>
#include<string.h>

int stack[100];
int top = -1;

void push(int elem) {
    stack[++top] = elem;
}

void pop() {
    if (top == -1) {
        printf("Stack is Empty\n");
    } else {
        --top;
    }
}

void pallindrome() {
    char num[100];
    printf("Enter the Numbers: \n");
    scanf("%s", num);
    
    int i = 0;
    top = -1;  // Reset stack

    // Push characters to stack
    while (num[i] != '\0') {
        push(num[i]);
        i++;
    }

    // Displaying stack (for debugging purposes)
    printf("Stack contents: ");
    for (i = 0; i <= top; i++) {
        printf("%c\t", stack[i]);
    }
    printf("\n");

    // Check if the number is a palindrome
    int j = 0;
    for (i = top; i > j; i--, j++) {
        if (stack[i] != stack[j]) {
            printf("%s is Not a Palindrome\n", num);
            return;
        }
    }

    printf("%s is a Palindrome\n", num);
}

void display() {
    if (top != -1) {
        printf("Stack contents: ");
        for (int i = top; i >= 0; i--) {
            printf("%c\t", stack[i]);
        }
        printf("\n");
    } else {
        printf("Stack is Empty\n");
    }
}

int main() {
    while (1) {
        int a, elem;
        printf("Enter from Following:\n1 - Push\n2 - Pop\n3 - Display\n4 - Check Palindrome\n5 - Exit\n");
        scanf("%d", &a);

        if (a == 5) break;

        switch (a) {
            case 1:
                printf("Enter the Element to Push: \n");
                scanf("%d", &elem);
                push(elem);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                pallindrome();
                break;
            default:
                printf("Invalid Option\n");
        }
    }
    return 0;
}
