/* Program to do operations on two complex numbers. */

#include<iostream>
using namespace std; 
class complex {
	public:
		float x,y;
		complex operator+(complex obj);
		complex operator-(complex obj);
		void input() {
			cin>>x>>y;
		}
		void output() {
			if(y >= 0)
				cout<<"The result is "<<x<<"+"<<y<<"i.";
			else
				cout<<"The result is "<<x<<y<<"i.";
		}
};
complex complex::operator+(complex obj) { 
	obj.x = x + obj.x;
	obj.y = y + obj.y;
	return obj; 
}
complex complex::operator-(complex obj) {
	obj.x = x - obj.x;
	obj.y = y - obj.y;
	return obj;
}

int main() {
	complex obj, c1, c2, result;
	int ch;
	do {
			cout<<"\n\n \t  OPERATIONS: \n\t ************* ";
			cout<<"\n 1. Addition. \n 2. Subtraction. \n 3. Exit.";
			cout<<"\n Enter your choice: ";
			cin>>ch;
			switch(ch) {
					case 1:
						cout<<"\n Enter the real and imaginary part of first complex number: ";
						c1.input();
						cout<<"\n Enter the real and imaginary part of second complex number: ";
						c2.input();
						result = c1 + c2;
						result.output();
						break;
					case 2:
						cout<<"\n Enter the real and imaginary part of first complex number: ";
						c1.input();
						cout<<"\n Enter the real and imaginary part of second complex number: ";
						c2.input();
						result = c1 - c2;
						result.output();
						break;
					case 3:
						break;
					default:
						cout<<"\n Error: Invalid Choice. Try with numbers 1-3.";
			}
		}while(ch != 3);
		cout<<"\n";
}
