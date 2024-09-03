#include<iostream>
using namespace std;
int n=5;
int circular_queue[5];
int front=-1,rear=-1;
void enqueue(int number){
if(rear!=-1&&(rear+1)%5==front){
cout<<"Do not fill more elements."<<endl;
}
else if (front == -1) {
front = 0;
rear = 0;
} else {
if (rear == n - 1)
rear = 0;
else
rear = rear + 1;
}
circular_queue[rear] = number ;
}
void dequeue(){
if (front==-1){
cout<<"Queue has no elements to dequeue."<<endl;
}
if (front==rear){
front==-1;
rear=-1;
}
else{
if(front==n-1)
front=0;
else
front=front+1;
}
}
void display() {
int f=front,r=rear;
if (front == -1) {
cout<<"Queue is empty"<<endl;
return;
}
cout<<"Queue elements are :\n";
if (f <= r) {
while (f <= r){
cout<<circular_queue[f]<<" ";
f++;
}
} else {
while (f <= n - 1) {
cout<<circular_queue[f]<<" ";
f++;
}
f = 0;
while (f <= rear) {
cout<<circular_queue[f]<<" ";
f++;
}
}
cout<<endl;
}
int main() {
Page 1 of 3File: /home/pvg/Assignment2.cpp
int choice, number;
cout<<"1)Enqueue\n";
cout<<"2)Dequeue\n";
cout<<"3)Display\n";
cout<<"4)Exit\n";
do{
cout<<"Enter choice : "<<endl;
cin>>choice;
switch(choice) {
case 1:
cout<<"Input the elements to be enqueued : "<<endl;
cin>>number;
enqueue(number);
display();
break;
case 2:
dequeue();
display();
for(int i=front;i<=rear;i++){
cout<<circular_queue[i]<<" ";
}
break;
case 3:
display();
for(int i=front;i<=rear;i++){
cout<<circular_queue[i]<<" ";
}
break;
case 4:
cout<<"Exit\n";
break;
default: cout<<"Incorrect!\n";
}
} while(choice!=4);
return 0;}
//Output
//1)Enqueue
//2)Dequeue
//3)Display
//4)Exit
//Enter choice :
//1
//Input the elements to be enqueued :
//56
//Queue elements are :
//56
//Enter choice :
//1
//Input the elements to be enqueued :
//90
//Queue elements are :
//56 90
//Enter choice :
//1
//Input the elements to be enqueued :
//45
//Queue elements are :
//56 90 45
//Enter choice :
//1
//Input the elements to be enqueued :
//78
//Queue elements are :
//56 90 45 78
//Enter choice :
Page 2 of 3File: /home/pvg/Assignment2.cpp
//1
//Input the elements to be enqueued :
//89
//Queue elements are :
//56 90 45 78 89
//Enter choice :
//2
//Queue elements are :
//90 45 78 89
//90 45 78 89 Enter choice :
//1
//Input the elements to be enqueued :
//79
//Queue elements are :
//90 45 78 89 79
//Enter choice :
//3
//Queue elements are :
//90 45 78 89 79
//Enter choice :
//4
//Exit
