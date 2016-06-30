/* Program to find the area and perimeter of different geometric shapes using Inheritance. */

#include<iostream>
using namespace std;
#define pi 3.14
class shape {
	public:
		float area(float a, float b, float c) {
			return a*b*c;
		}
		float perimeter(float a, float b, float c) {
		 	return a*(b+c);
		 }
		 
		void print(float x, float y) {
			cout<<"\n\n The Area is "<<x;
			cout<<"\n\n The Perimeter is "<<y;
		}
};
class circle: public shape {
	public:
		float r;
		void read() {
			cout<<"\n\n Enter the radius, r: ";
			cin>>r;
		}		
};
class square: public shape {
	public:
		float a;
		void read() {
			cout<<"\n\n Enter the dimension of an edge, a: ";
			cin>>a;
		}
		
};
class ellipse: public shape {
	public:
		float x, y;
		void read() {
			cout<<"\n\n Enter the dimensions of major axis, a and minor axis, b: ";
			cin>>x>>y;
			
		}
};
class rectangle: public shape {
	public:
		float l, h;
		void read() {
			cout<<"\n\n Enter the length, l and breadth, b: ";
			cin>>l>>h;
		}
};
main() {
	circle c;
	square s;
	ellipse e;
	rectangle re;
	shape sp;
	int ch;
	float ar, peri, r, x, y, a, l, h;
	do {
		cout<<"\n\n\n\n 1. Circle \n 2. Ellipse \n 3. Square \n 4. Rectangle \n 5. Exit";
		cout<<"\n\n Enter your choice: ";
		cin>>ch;
		switch(ch) {
			case 1:
				c.read();
				ar = c.area(pi, c.r, c.r);
				peri = c.perimeter(pi, c.r, c.r);
				c.print(ar, peri);
				break;
			case 2:
				e.read();
				ar = e.area(pi, e.x, e.y);
				peri = e.perimeter(pi, e.x, e.y);
				e.print(ar, peri);
				break;
			case 3:
				s.read();
				ar = s.area(1.0, s.a, s.a);
				peri = s.perimeter(2.0, s.a, s.a);
				s.print(ar, peri);
				break;
			case 4:
				re.read();
				ar = re.area(1.0, re.l, re.h);
				peri = re.perimeter(2.0, re.l, re.h);
				re.print(ar, peri);
				break;
			case 5:
				break;
			default:
				cout<<"\n\n Error: Invalid Choice!";
		}
	}while(ch != 5);
	cout<<"\n";
}	
