#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/* 
 * Simple program to experiment with the sine wave
 */

int main()
{
    double angle;							/* The Angle of the sine wave */
	int numSteps;							/* Number of Steps */
    double maxAngle = M_PI * 2;				/* The Maximum Angle of the sine wave */
    int i;									/* An intial starting value */
    int j;									/* An intial starting value */
    float sinVal;							/* Value of the Sine wave */
    float numSpaces;						/* Number of spaces to place the * */
    float sinVal2 = 0;						/* The previous value */
    float angle2 = 0;						/* The previous angle */
    float diff;								/* Slope of the sine wave */
    
    do
    {
		printf("Input the number of steps: ", numSteps);
		scanf("%ld",&numSteps);
	}	while (numSteps<2);

    for(i = 0;  i<=numSteps;  i++)
    {	
        angle = (double)i / (double)numSteps * maxAngle;
        sinVal = sin(angle);
		numSpaces = 30 + sinVal * 30;
        printf("%3d: %5.2f", i, angle);
        for(j = 0; j<=numSpaces; j++)
        	{
        		printf(" ");
        	}
        if(i > 1)
        {	
        	if(fabs(sinVal)==1)
			{
				printf("*\n");
			}
        	else if(fabs(sinVal)!=1)
        	{
				diff = (sinVal-sinVal2)/(angle - angle2);
				sinVal2 = sinVal;
				angle2 = angle;
				if(sinVal>0)
				{
					if(diff>0)
					{
						printf("\\\n");
					}
					else if(diff<0)
					{
						printf("/\n");
					}
					else
					{
						printf("/\n");
					}
				}
				else if(sinVal<0)
				{
					if(diff>0)
					{
						printf("\\\n");
					}
					else if(diff<0)
					{
						printf("/\n");
					}
					else
					{
						printf("\\\n");
					}
				}
			}

		}
		else
		{
			printf("\\ \n");
		}

    }
}
