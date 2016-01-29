#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
/*
 *This program will compute the amount of tax owed by a taxpayer 
 *based on annual income and amount of tax exemptions.
 */

int main()
{
	double AI; 				/*Annual Income in Dollars ($)*/
	double TO; 				/*Tax owed in Dollars ($)*/
	double FS;				/*Filing status as a number between 1-3*/
	double TD;				/*Tax deduction in Dollars ($)*/
	double ND;				/*Number of Dependants*/
	double TI;				/*Taxable Income in Dollars ($)*/
	double NC;				/*Number of Children*/
	double SD;				/*Standard Deduction in Dollars ($)*/
	double FTAX;			/*Federal Tax in Dollars ($)*/
	bool valid = false;		/*until we know is true*/
	
	printf("Please enter your annual income: $");
	scanf("%lf", &AI);
	printf("You entered %.2f as your current annual income.\n ",AI);
	/* Test to see if the annual income is less than $9350, then the tax owed is $0*/
	if(AI<9350)
	{
		TO = 0;
		printf("Tax owed: $%.2f \n",TO);
		exit(0); /* Exit with success*/
	}
	else
	{
		printf("Specify your filing status as: \n(1) single \n(2) married, filing jointly \n(3) married, filing seperately. \nEnter the number of your current filing status:	");
		scanf("%lf", &FS);
		if(FS == 1 ^ FS == 3)
			{
				ND = 1;					/*Number of dependants is set to 1*/
				SD = 5700;				/*Standard Tax Deduction is at $5700*/
				TD = (ND * 3650) + SD;	/*Total Tax Deduction in Dollars ($)*/
				TI = AI - TD;			/*Taxable Income = Annual Income - Tax Deduction*/
				printf("Current Taxable Income: $%.2f \n", TI);
			}
		else if(FS == 2)
			{
				SD = 11400;				/*Standard Tax Deduction is at $11400*/
				printf("Enter the number of children: ");
				scanf("%lf", &NC);
				ND = (2 + NC);			/*Number of dependants prompted and scanned*/
				TD = ((ND * 3650) + SD);/*Total Tax Deduction in Dollars ($)*/
				TI = AI - TD;			/*Taxable Income = Annual Income - Tax Deduction*/
				printf("Current Taxable Income: $%.2f \n", TI);
			}
		else
			{
				printf("The entered filing status does not exist.\n");
				exit(0);
			}
	}
	
/* This part of the program finds the Federal Income Tax based on the Taxable Income */
	
	double I;				/*Initial*/
	double P;				/*Percentage*/
	double AO;				/*Amount over*/
	
/* First the program checks the boundaries of the Total Income and then sets values for the boolean valid, I, P, and AO*/

	if(0<TI && TI<=16750)
		{	
			valid = true;
			I = 0;
			P = .10;
			AO = 0;
		}
	else if(16750<TI && TI<=68000)
		{
			valid = true;
			I = 1675;
			P = .15;
			AO = 16750;
		}
	else if(68000<TI && TI<=137300)
		{
			valid = true;
			I = 9362.5;
			P = .25;
			AO = 68000;
		}
	else if(137300<TI)
		{
			valid = true;
			I = 26687.5;
			P = .28;
			AO = 137300;
		}
	else
		{
			printf("Clearly something isn't right then");
			exit(0);
		}
	
/* Secondly, once the boundaries of the total income is passed as valid, then it uses the determined variables to solve for the Federal Tax.*/

	if(valid)
		{
			FTAX = I + P * (TI - AO);
			printf("Federal Tax: %.2f \n", FTAX);
			exit(0);
		}
}
