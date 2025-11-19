#include<iostream>
using namespace std;



int main(){
	int arr[100]={0};
	int n;
	cout<<"Enter number of elements of the stack : ";
	cin>>n;
	int top = n-1;
	cout<<"Enter elements of the stack :";
	for(int i = 0; i<n ; i++){
		cin>>arr[i];
	}
	int choice;
	cout << "\nAvailable choices : \n";
	cout << "1. push()\n";
	cout << "2. pop()\n";
	cout << "3. isEmpty()\n";
	cout << "4. isFull()\n";
	cout << "5. display()\n";
	cout << "6. peek()\n";
	cout << "7. EXIT\n";
	cout << "Enter your choice : ";
	cin>>choice;
	cout<<endl;
	while(choice != 7){
		switch(choice){
			case 1:{
				if(top==99){
					cout<<"OVERFLOW!!!\n";
				}
				else{
					top++;
					int ele;
					cout<<"Enter element to push : ";
					cin>>ele;
					arr[top] = ele;
					cout<<endl;
				}
				break;
			}
			case 2:{
				if(top == 0){
					cout<<"UNDERFLOW!!!\n";
				}
				else{
					cout<<arr[top]<<endl;
					top--;
				}
				break;
			}
			case 3:{
				if(top == 0){
					cout<<"Empty\n";
				}
				else{
					cout<<"Not Empty\n";
				}
				break;
			}
			case 4:{
				if(top == 99){
					cout<<"Full\n";
				}
				else{
					cout<<"Not Full\n";
				}
				break;
			}
			case 5:{
				cout<<"Stack :\n";
				for(int i =0 ; i<=top ;i++){
					cout<<arr[i]<<" ";
				}
				cout<<endl;
				break;
			}
			case 6:{
				cout<<arr[top]<<endl;
				break;
			}
			default:{
				cout<<"Enter valid choice!!!\n";
				break;
			}
		}
		cout << "Enter your choice : ";
		cin>>choice;
		cout<<endl;
	}
	
	
	
	
	
	return 0;
}
