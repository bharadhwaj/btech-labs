/* Program to find the area of different geometric shapes using Function Overloading. */

#include<iostream>
#include<math.h>
using namespace std;
#define pi 3.14
class areas {
	float s;
	public:
		float area(float a, float b, float c);
		float area(float l, float h);
		float area(float r);
};
float areas::area(float a, float b, float c) {
	s = (a + b + c)/2;
	return(sqrt(s*(s-a)*(s-b)*(s-c)));
}
float areas::area(float l, float h) {
	return(l*h);
}
float areas::area(float r) {
	return(pi*r*r);
}
int main() {
	int ch,a,b,c,l,h,r,ar;
	areas obj;
	do {
		cout<<"\n\n \t AREA\n\t******";
		cout<<"\n 1. Triangle. \n 2. Rectangle. \n 3. Circle. \n 4. Exit.";
		cout<<"\n Enter your choice: ";
		cin>>ch;
		switch(ch) {
			case 1:
				cout<<"\n Enter the three dimensions for Triangle: ";
				cin>>a>>b>>c;
				ar = obj.area(a,b,c);
				cout<<"\n The area is "<<ar<<" sq. units.";
				break;
			case 2:
				cout<<"\n Enter the two dimensions for Rectangle: ";
				cin>>l>>h;
				ar = obj.area(l,h);
				cout<<"\n The area is "<<ar<<" sq. units.";
				break;
			case 3:
				cout<<"\n Enter the radius of Circle: ";
				cin>>r;
				ar = obj.area(r);
				cout<<"\n The area is "<<ar<<" sq. units.";
				break;
			case 4:
				break;
			default:
				cout<<"\n\n Sorry, Invalid Choice. Try with numbers 1-4.";
		}
	}while(ch != 4);
	cout<<"\n";
}
