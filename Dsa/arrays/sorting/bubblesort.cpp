#include<iostream>
using namespace std;

int ar[100];
int n;

void sort() {
    int temp;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++ ) {
            if(ar[i] > ar[j]) {
                temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
    }
}

void display() {
    cout<<"Sorted Array:\t";
    for(int i = 0; i < n; i ++) cout<<ar[i]<<"\t";
    cout<<endl;
}

int main() {
    cout<<"Enter the Number of Elements"<<endl;
    cin>>n;
    cout<<"Enter the Elements of Array: ";
    for(int i = 0; i < n; i++) cin>>ar[i];

    sort();
    display();

    return 0;
}