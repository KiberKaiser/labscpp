#include <iostream>
#include <math.h>

using namespace std;

int main(){	
	/// Завдання 4.1	
	float y; float x1; float x2;
	float n;
	cout << "Task 4.1" << endl;
	cout << "Example A:" << endl;
	cout << "Enter the number of x: " << endl;
	cin >> x1;	
	while(0.1 <= x1 && x1 <= 1.2)
	{
		y = (tan(0.5 * x1)) / (pow(x1, 3) + 7.5);
		x1 += 0.1;
		cout << "y: " << y << "\t x: " << x1 << endl;
	
	}
	cout << "Example B:" << endl;
	cout << "Enter the number of x: " << endl;
	cin >> x2;
	
	for(float n = 0; n <= 8; n++)
	{
		y = (tan(0.5 * x2)) / (pow(x2, 3) + 7.5);	
		x2 += 0.05;
		cout << "y: "<< y <<  "\t x: "<< x2 << endl;	
	}
	
	/// Завдання 4.2
	float x, v; 
	cout << "Task 4.2" << endl;
	cout << "Enter the number of v: " << endl;
	cin >> v;	
    while(v >= 0 && v <= 4){
    	if(v >= 0 && v < 1){
    		x = pow(1.26, v) + v;		
		} 
		else {
			x = atan(v + 0.4);	
		}
    	cout << "x: " << x << "\t v: " << v << endl;
    	v += 0.1;
	}
	
	
	/// Завдання 4.3	
	float z; float y0;
	cout << "Task 4.3" << endl;
	cout << "Enter the number of x: " << endl;
	cin >> x;
	cout << "Enter the number of y: " << endl;
	cin >> y0;
      while(x >= 2 && x <= 6){	   
      y = y0;
 	    while (y >= -2 && y <= 10){
 	    	z = cbrt(pow(x,2) + 3 * y); 	    			 
 	    	cout << "z: " << z << "\t x: " << x << "\t y: " << y <<endl; 
		    y += 1;	  
		   
		 }
		 	x += 0.2;
	}		         
	return 0;
}
	

