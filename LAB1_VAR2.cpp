#include <iostream>
#include <math.h>

using namespace std;
int main(){
   
   /// Завдання 1.1
   double y = -1;
   double z = 0;
   double n = 2;
	y = ((cbrt(n - 1) * log(pow(2,n)) - tan(n+1)/pow(n,3))) / (acos(0.85) + log(n)) + 2.75;
    cout << y << endl;

   /// Завдання 1.2
    double secondy, secondz;
    secondy = -1; secondz = 0;

    if(secondy>5 && -0.5 <= secondz <= 2*secondz){
    cout << true << endl;
    } 
    else{
    cout << false << endl;
    }
   /// Завдання 1.3
    double thirdx = 2.9 * 10 * pow(10, -39);
    double thirdy = -10.88 * pow(10, 12);
    
    cout << thirdx << endl;
    cout << thirdy << endl;
   /// Завдання 1.4
   double fourthx = 30; double fourthy; 
   double A = 3; double B = 8;
   double C = 6; double D = 2;
   
   fourthy = (A * sin(fourthx) + B * cos(fourthx) ) * ( (A*B)/pow(C, D+4.8));
   cout << fourthy;
}