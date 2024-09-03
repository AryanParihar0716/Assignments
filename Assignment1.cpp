#include <iostream>
using namespace std;
struct Student{ //declared struct Student
int Roll_Number;
string Name;
float SGPA;
};
void bsort(struct Student[],int);
void inSort(struct Student[],int);
void qSort(struct Student[],int,int);
int partition(struct Student[],int,int);
void gpasearch(struct Student[],int);
int namesearch(struct Student[],int,int);
void print(struct Student[],int);
//declared all required fucntions
int main(){
struct Student se_it[15]={{3043,"X",8.77},{3098,"P",9.54},{3013,"Q",6.22},{3014,"W",
7.55},{3005,"E",9.23},
{3016,"C",7.40},{3070,"T",9.77},{3030,"Y",9.68},{3036,"U",9.18},{3025,"I",7.89},
{3011,"B",8.90},{3089,"A",8.25},{3060,"S",8.04},{3040,"D",7.79},{3002,"F",9.33}};
int length = sizeof(se_it)/sizeof(se_it[0]);
bsort(se_it,length-1);
inSort(se_it,length-1);
cout<<"Sorted alphabetically"<<endl;
print(se_it,length);
qSort(se_it,0,length-1);
cout<<"10 toppers in classroom are"<<endl;
for(int i=14;i>4;i--){
cout<<se_it[i].Roll_Number<<" "<<se_it[i].Name<<" "<<se_it[i].SGPA<<endl;
}
cout<<endl;
gpasearch(se_it,length);
int result = namesearch(se_it,length-1,0);
(result==-1)?cout<<"Given name is not in array"<<endl: cout<<"Given name is present at
array having roll number "<<se_it[result].Roll_Number<<endl;
return 0;
}
void print(Student arr[],int length){
for(int i=0;i<length;i++){
cout<<arr[i].Roll_Number<<" "<<arr[i].Name<<" "<<arr[i].SGPA;
cout<<"\n";
}
cout<<endl;
}
void bsort(Student arr[],int length){
int temp;
string tmp;
float t;
for(int i =0;i<length;i++){
for(int j=0;j<length;j++){
if(arr[j].Roll_Number>arr[j+1].Roll_Number){
swap(arr[j+1],arr[j]);
}
}
}
cout<<"List sorted by roll number is"<<endl;
print(arr,length+1);
}
void inSort(struct Student arr[],int length)
{
int j;
for(int i=1;i<length;i++){
Student key=arr[i];
j=i-1;
while(j>=0){
if(arr[j].Name<key.Name){
break;
}else{
arr[j+1].Name=arr[j].Name;
arr[j].Name=key.Name;
arr[j+1].Roll_Number=arr[j].Roll_Number;
arr[j].Roll_Number=key.Roll_Number;
arr[j+1].SGPA=arr[j].SGPA;
arr[j].SGPA=key.SGPA;
j--;
}
}
}
}
int partition(Student arr[],int low,int high){
float pivot = arr[high].SGPA;
int i = low-1;
for(int j = low;j<high;j++){
if(arr[j].SGPA<=pivot){
i++;
swap(arr[i],arr[j]);
}
}
swap(arr[i+1],arr[high]);
return (i+1);
}
void qSort(struct Student arr[],int low,int high){
if (low < high) {
int pi = partition(arr, low, high);
qSort(arr, low, pi - 1);
qSort(arr, pi + 1, high);
}
}
void gpasearch(Student arr[],int length){
float target;
int counter=-1;
cout<<"Enter CGPA of student to be found ";
cin>>target;
for(int i=0;i<length;i++){
if(target==arr[i].SGPA){

cout<<"Student having CGPA "<<target<<" is "<<arr[i].Name<<" and their roll no
is "<<arr[i].Roll_Number<<endl;
counter++;
}
}
if(counter<0){
cout<<"No student having CGPA "<<target<<" found"<<endl;
}
}
int namesearch(Student arr[],int high,int low){
inSort(arr,high);
string target;
cout<<"Enter name to be found"<<endl;
cin>>target;
while (low <= high) {
int mid = low + (high - low) / 2;
if (arr[mid].Name == target){
return mid;
}
else if(arr[mid].Name < target){
low = mid + 1;
}else{
high = mid - 1;}
}
return -1;
}
