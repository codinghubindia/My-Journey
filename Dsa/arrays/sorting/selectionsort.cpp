#include<iostream>
using namespace std;

int ar[100];
int size, index, temp;

void sort() {
    int smallest;
    for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
            if(ar[i] > ar[j]){
                smallest = ar[j];
                index = j;
            }
        }
        temp = ar[i];
        ar[i] = smallest;
        ar[index] = temp;
    }
}

void display() {
    cout<<"Sorted Array:\t";
    for(int i = 0; i < size; i ++) cout<<ar[i]<<"\t";
    cout<<endl;
}

int main() {
    cout<<"Enter the Number of Elements"<<endl;
    cin>>size;
    cout<<"Enter the Elements of Array: ";
    for(int i = 0; i < size; i++) cin>>ar[i];

    sort();
    display();

    return 0;
}