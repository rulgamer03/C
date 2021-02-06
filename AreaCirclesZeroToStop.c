#include <stdio.h>

#define Pi 3.14159

/* program to calculate the area of ​​a circle*/
main ()
{
	float radius, area;  /* declaration of variables */
	float process(float radius);  /* function declaration */

	printf("To STOP enter 0 in the radius \n");
	printf("\nRadius = ?");

	while (radius!=0){
		if (radius<0)
		area=0;

		else
		area= process(radius);

		printf("Area = %f\n", area);

		printf("\nRadius= ?");
		scanf("%f", &radius);
	}

}

float process(float r) /* function definition */
{
	float a; /* local variable declaration */

	a=Pi * r * r;
	return(a);
}
