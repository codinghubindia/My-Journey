#include<stdio.h>
#include<string.h>

int stack[100];
int top = -1;

void push() {
    int elem;
    printf("Enter the Element to Push\n");
    scanf("%d",&elem);
    stack[++top] = elem;
    return;
}

void pop() {
    if(top == -1) {
        printf("Stack is Empty");
    } else {
        --top;
    }
}

void pallindrome() {
    char ar[100];
    printf("Enter the Numbers: ");
    scanf("%s", ar);
    int i = 0;
    int len = strlen(ar);
    int j = len-1;
    for(i; i < (len-1) / 2 ; i++){
        if(ar[i] != ar[j] ){
            printf("It is not a Pallindrom\n");
            return;
        }
        j--;
    }
    printf("It is a Pallindrome\n");
    return;
}

void display () {
    if(top != -1)
        for(int i = top; i >= 0; i--) printf("%d\t",stack[i]);
    else printf("Stack is Empty\n");
}

int main() {
    while(1) {
        int a;
        printf("Enter from Following\n1 - Push\n2 - Pop\n3 - Display\n4 - Check Pallindrom\n5 - Exit\n");
        scanf("%d", &a);

        if(a == 5) break;

        switch(a) {
            case 1:
                push();
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