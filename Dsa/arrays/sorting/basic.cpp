#include<iostream>
using namespace std;

//Basic Array function demonstration
// Features: 
// 1 Display
// 2 Search
// 3 Insert the element at the specified index
// 4 Delete the element at the specified index

// Function to Dispaly the Elements of the Array

void display(int ar[], int size) {
    cout<<"The Elements of the Array is : ";
    for(int i = 0; i < size; i++) {
        cout<<ar[i]<<"\t";
    }
    cout<<endl;
}

// Function to Search and Element 
int searchElem(int ar[], int size, int key, int *locn) {
    for(int i = 0; i < size; i++) {
        if(ar[i] == key) {
            *locn = i;
            return 1;
        }
    }

    return 0;
}

// Function to Insert An Element in an Array
// case 1: If the index is pointing Outside of the Array => Print an Error Message
// case 2: If the index is pointing within the Array => Use for Loop to shift the elements and insert the Element at desired Index

int insertElem(int ar[], int size, int elem, int locn) {
    if(size <= locn) {
        cout<<"Invalid Index"<<endl;
        return size;
    } else {
        for(int i = size-1; i >= locn; i--) {
            ar[i+1] = ar[i];
        }
        ar[locn] = elem;
        cout<<"Success: The Element "<<elem<<"Is inserted at the Index "<<locn<<endl;
        return ++size;
    }
}

// Function to Delement an Element in An Array
// case 1: If the index is pointing Outside of the Array => Display and error Message
// case 2: If the index is pointin within the Array size => Use for Loop to shift the elements from the deleted elements

int deleteElem(int ar[], int size, int locn) {
    if(size <= locn) {
        cout<<"Error: Invalid Index"<<endl;
        return size;
    } else {
        int elem = ar[locn];
        for(int i = locn; i < size; i++) {
            ar[i] = ar[i+1];
        }
        cout<<"Success: The Element "<<elem<<"Is Deleted at the Index "<<locn<<endl;
        return --size;
    }
}


// Entry Point
int main() {
    int ar[100];
    int size;
    cout<<"Enter the Size of the Array: ";
    cin>>size;
    cout<<"Enter the Elements of the Array"<<endl;
    for(int i = 0; i < size; i++) cin>>ar[i];
    while(1) {
        int a,elem,locn,key;
        cout<<"Enter From the Following: "<<endl;
        cout<<"1 - Insert\n2 - Delete\n3 - Search\n4 - Display\n5 - Quit\n";
        cin>>a;

        if(a == 5) break;

        switch (a)
        {
        case 1:
            cout<<"Enter the Element You Want To Insert: ";
            cin>>elem;
            cout<<"Enter the Index Where You Want to Insert This Element: ";
            cin>>locn;
            size = insertElem(ar, size, elem, locn);
            cout<<size<<endl;
            break;

        case 2:
            cout<<"Enter the Index Where You Want to Delete the Element: ";
            cin>>locn;
            size = deleteElem(ar, size, locn);
            break;

        case 3:
            cout<<"Enter the Element You Want To Search: ";
            cin>>key;
            if(searchElem(ar, size, key, &locn)) {
                cout<<"Entered Element is found At the location: "<<locn<<endl;
            } else {
                cout<<"Element Not Found"<<endl;
            }
            break;

        case 4:
            display(ar, size);
            break;
        
        default:
            cout<<"Invalid Option";
            break;
        }
    }
    return 0;
}