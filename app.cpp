#include <iostream>
using namespace std;


struct value {
    int x;
    value* next;
};

value * front = NULL;
value * rear = NULL;

void insert(){
    value * newValue = new value;
    
    cout << "Enter a number: ";
    cin >> newValue->x;

    newValue->next = NULL;

    if (front == NULL) {
        front = newValue;
        rear = newValue;
    }  else
    {
        while (rear->next != NULL)
        {
            rear = rear->next;
        }
        rear->next = newValue;
        rear = newValue;
    }
    
    cout << newValue->x << " added to the queue." << endl;
}


void summition(){
    int sum = 0;
    value * current = front;

    while (current != NULL) {
        sum += current->x;
        current = current->next;
    }

    cout << "The sum of the numbers in the queue is: " << sum << endl;
}


void display(){
    value * current = front;

    if (current == NULL) {
        cout << "The queue is empty." << endl;
        return;
    }

    cout << "The numbers in the queue are: ";
    while (current != NULL) {
        cout << current->x << " ";
        current = current->next;
    }
    cout << endl;


    summition();
}




void select()
{
    int choice;
    cout << "\n1. Add number" << endl;
    cout << "2. display numbers and the sum" << endl;

    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        insert();
        select();
        break;
    case 2:
        display();
        select();
        break;

    case 3:
        exit(0);
    default:
        cout << "\nInvalid choice. Please try again." << endl;
    }
}




int main() {



    select();


    return 0;
}