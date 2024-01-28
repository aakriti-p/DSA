#include <bits/stdc++.h>
using namespace std;

#define size 5

int arr[size];
int front = -1;
int rear = -1;

bool isEmpty()
{
    if (front == -1 && rear == -1)
        return true;
    else
        return false;
}

void enqueue(int value)
{
    if ((front == 0 && rear == size - 1) || ((rear + 1) % size == front))
    {
        cout << "Queue is full." << endl;
    }
    else
    {
        if (front == -1 && rear == -1)
        { // first element
            front = rear = 0;
            arr[rear] = value;
        }
        else if ((rear == size - 1) && (front != 0))
        { // when some elements have already been dequeued and rear is at last
            rear = 0;
            arr[rear] = value;
        }
        else
        { // normal condition when queue isnt full, neither empty
            rear++;
            arr[rear] = value;
        }
    }
}

void dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty." << endl;
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == size - 1)
        front = 0;
    else
        front++;
}

void showfront()
{
    if (isEmpty())
        cout << "Queue is empty\n";
    else
        cout << "element at front is:" << arr[front] << "\n";
}

// function to display elements of the queue
void displayQueue()
{
    if (isEmpty())
        cout << "Queue is empty\n";
    else if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    else
    {
        for (int i = front; i < size; i++)
            cout<<arr[i]<<" ";
        cout<<endl;

        for (int i = 0; i <= rear; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
}

int main()
{
    // inserting elements in queue
    cout << "Inserting elements in queue\n";
    enqueue(2);
    displayQueue();
    enqueue(3);
    displayQueue();
    enqueue(5);
    displayQueue();
    enqueue(7);
    displayQueue();
    enqueue(8);

    displayQueue();
    // queue is full
    enqueue(9);
    // show element at front
    showfront();

    cout << "Removing elements from queue\n";
    // removing elements from the queue
    dequeue();
    displayQueue();
    dequeue();
    displayQueue();
    dequeue();
    displayQueue();
    dequeue();
    displayQueue();
    dequeue();

    return 0;
}
