/*
	A student is studying rotational motion in physics. He is unable to solve a problem which states that two fans each with a
	single blade are rotating one above the other about the same axis of rotation and both blades have the same lengths. Fans can
	rotate in either clockwise or anticlockwise direction, there is a dot marked on both the blades and the dot is marked at the
	same distance from the centre of rotation. Clockwise direction is assumed to be positive speed and anticlockwise direction is
	assumed to be negative speed. Help the students to find the number of distict points the dots will coincide on the circumfurence
	of rotation.
	Input will be two numbers S1 and S2. S1 is the speed of first fan and S2 is the speed of second fan and the output will be the
	number of distict points the dots will coincide.
*/
#include<stdio.h>
int gcd(int a, int b){
	if(a % b == 0)
		return b;
	else
		return gcd(b, a%b);
}

void main(){
	int s1, s2, s1_temp, s2_temp, _gcd_, no_coinci;
	printf("Enter the speed of fan 1 = ");
	scanf("%d", &s1);
	printf("Enter the speed of fan 2 = ");
	scanf("%d", &s2);


	if (s1 < 0 ){
		s1_temp = -s1;
	} else{
		s1_temp = s1;
	}

	if (s2 < 0){
		s2_temp = -s2;
	} else{
		s2_temp = s2;
	}

	_gcd_ = gcd(s1_temp, s2_temp);
	if((s1 > 0 && s2 < 0) || (s1 < 0 && s2 > 0)){
		no_coinci = (s1_temp + s2_temp) / _gcd_;
	} else {
		if(s1_temp > s2_temp){
			no_coinci = (s1_temp - s2_temp) / _gcd_;
		} else {
			no_coinci = (s2_temp - s1_temp) / _gcd_;
		}
	}

	printf("Total number of coincidence per unit time = %d", no_coinci);
}


