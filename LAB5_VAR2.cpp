#include <iostream>
#include <math.h>
 
 using namespace std;
 
 int main(){
 	///  Завдання 5.1
 	
 	double sum = 0;
    double product = 1;
 	double m = 5; double n = 10; 
	double l = 8; double k = 1;
    double i = k; double y, p; 
      
 	cout << "Task 5.1" << endl;
  	 for(i = 1; i <= n; i++){
 		sum += (i+2) / ((i+3) *(i+6));
	 }
	
	 for(l = 8; l <= 17; l++){
	 	product *= pow(-1, l) * (pow(l, 2) - 2) / (l + 3);
	 }
	 
	 cout << "Sum:" << sum << endl;
	 cout << "Product:" << product << endl;
	 
	///  Завдання 5.2
	 
    int range; int oddNumber;
  	cout << "Task 5.2" << endl;    
	  for(oddNumber = 1; oddNumber <= 100; oddNumber += 2 ){
	  	range += oddNumber;
	  }
  	cout << range << endl;
  	
  	///  Завдання 5.3
  	
    double x1 = 2.13, dX = 0.4, j = 5;   
  	double x_j, x_jplus1;
  	
  	cout << "Task 5.3" << endl;
  	cout << "Cycle for:" << endl;
  	 for(j = 5; j <= 24; j++){
  	 	x_j = x1 + dX * j;
  	    x_jplus1 = x_j + dX;
  	     sum += (pow(x_jplus1, 2)) / 2 + x_j;
	   } 
    cout << "Sum: " << sum << endl;
	   
   ///  Завдання 5.4
   cout << "Task 5.4" << endl;
   cout << "Cycle while:" << endl;
    while (j <= 24){     
  	    x_j = x1 + dX * j;
  	    x_jplus1 = x_j + dX;
  	 	y = (pow(x_jplus1, 2)) / 2+x_j;
  	 	j++;
	}
	cout << "Sum: " << sum << endl;
    cout << "Cycle do-while:" << endl;
   
    do{	 
        x_j = x1 + dX * j;
  	    x_jplus1 = x_j + dX;
    	sum += (pow(x_jplus1, 2)) / 2+x_j;
    	j++;
	} while(j <= 24);
	cout << "Sum: " << sum << endl;
 	return 0;
 	
 }