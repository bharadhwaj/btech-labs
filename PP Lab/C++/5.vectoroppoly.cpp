/* Program to implement arithmetic operation on both real and complex vectors using polymorphism. */

#include<iostream>
using namespace std;
class vectors {
	public:
		virtual float read(float a) {
			cin>>a;
			return a;
		}
		
};
class complex: public vectors {
	public:
		float read(float a) {
			cin>>a;
			return a;
		}
		void addition(float a, float b, float x, float y) {
			float p = a + x;
			float q = b + y;
			cout<<p<<"+"<<q<<"i";
		}
		void subtraction(float a, float b, float x, float y) {
			float p = a - x;
			float q = b - y;
			if(q >= 0) 
				cout<<p<<"+"<<q<<"i";
			else
				cout<<p<<"-"<<-1*q<<"i";
		}
		float multiplicationr(float a, float b, float x, float y) {
			return (a*x - b*y);
			
		}
		float multiplicationi(float a, float b, float x, float y) {
			return (a*y + b*x);
			
		}
};
class real: public vectors {
	public:
		void addition(float a, float b) {
			cout<<a+b;
		}
		float subtraction(float a, float b) {
			return a-b;
		}
		float multiplication(float a, float b) {
			return a*b;
		}
};
main() {
	complex c;
	real r;
	vectors *vr;
	vr = &r;
	int ch;
	float a, b, co, d, u, v, x, y, i, j;
	do {
	cout<<"\n\n 1. Complex Vectors. \n 2. Real Vectors. \n 3. Exit.";
	cout<<"\n\n Enter your choice: ";
	cin>>ch;
	switch(ch) {
		case 1:
			cout<<"\n\n Enter the i'th component(complex vector[a+ib]) of first vector: ";
			a = vr->read(a);
			b = vr->read(b);
			cout<<"\n\n Enter the j'th component(complex vector[c+id]) of first vector: ";
			co = vr->read(co);
			d = vr->read(d);
			cout<<"\n\n Enter the i'th component(complex vector[u+iv]) of second vector: ";
			u = vr->read(u);
			v = vr->read(v);
			cout<<"\n\n Enter the j'th component(complex vector[x+iy]) of second vector: ";
			x = vr->read(x);
			y = vr->read(y);
			cout<<"\n\n The sum is: ";
			cout<<"(";c.addition(a,b,u,v);cout<<")i^+(";c.addition(co,d,x,y);cout<<")j^ \n\n";
			
			cout<<"The difference is: ";
			cout<<"(";c.subtraction(a,b,u,v);cout<<")i^+(";c.subtraction(co,d,x,y);cout<<")j^ \n\n";
			cout<<"The product is: ";
			c.addition(c.multiplicationr(a,b,u,v),c.multiplicationi(a,b,u,v),c.multiplicationr(co,d,x,y),c.multiplicationi(co,d,x,y));
			break;
		case 2:
			cout<<"\n\n Enter the i'th component of first vector: ";
			a = r.read(a);
			cout<<"\n\n Enter the j'th component of first vector: ";
			b = r.read(b);
			cout<<"\n\n Enter the i'th component of second vector: ";
			co = r.read(co);
			cout<<"\n\n Enter the j'th component of second vector: ";
			d = r.read(d);
			cout<<"\n\n The sum is: ";
			r.addition(a,co);cout<<"i^+";r.addition(b,d);cout<<"j^ \n\n";
			cout<<"The difference is: ";
			i = r.subtraction(a,co);
			j = r.subtraction(b,d);
			if(r.subtraction(b,d) >= 0)
				cout<<i<<"i^+"<<j<<"j^ \n\n";
			else
				cout<<i<<"i^-"<<-1*j<<"j^ \n\n";
			cout<<"The product is: ";
			r.addition(r.multiplication(a,co),r.multiplication(b,d));
			break;
		case 3:
			break;
		default:
			cout<<"Error: Invalid input!";
	}
	}while(ch != 3);
}
