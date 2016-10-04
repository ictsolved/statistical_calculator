//Statistical Calculator
//header file
#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <math.h>
//About
    void about()
	{
	    printf("\t\t*************************************************");
	    printf("\n\t\t*");printf("\t\tStatistical Calculator");printf("\t\t*");
	    printf("\n\t\t*");printf("\t\t\t\t\t\t*");
	    printf("\n\t\t*");printf("\tCreated By:\t\t\t\t*");
	    printf("\n\t\t*");printf("\t 2. Sarad Gajurel\t\t\t*");
	    printf("\n\t\t*");printf("\t\t\t\t\t\t*");
	    printf("\n\t\t*************************************************\n");
	}
//Choices
void choices()
{
    printf("\n");
    printf("\t#################################################");
    printf("\n\t#");printf("\t\t\t\t\t\t#");
    printf("\n\t#");printf("\t   Enter Your Choice:");printf("\t\t\t#");
    printf("\n\t#");printf("\t    1. Mean\t\t\t\t#");
    printf("\n\t#");printf("\t    2. Median\t\t\t\t#");
    printf("\n\t#");printf("\t    3. Variance\t\t\t\t#");
    printf("\n\t#");printf("\t    4. Standard Deviation\t\t#");
    printf("\n\t#");printf("\t    5. Enter New Data\t\t\t#");
    printf("\n\t#");printf("\t    6. Terminate Programme\t\t#");
    printf("\n\t#");printf("\t\t\t\t\t\t#");
    printf("\n\t#################################################\n");
}
//starting Calculator
	void data_calc()
	{
	    int  i=0,j=0,n=0,swap,choice;
        float x[100],average=0,median=0,std_deviation=0,variance=0,sum1=0,sum=0;
	    clrscr();
	    about();
	    //Taking Data
		printf("\nEnter the no. of data (N): ");
		scanf("%d", &n);
		printf("Enter %d data (X):\n", n);
		for (i=0;i<n;i++)
		    {
			scanf("%f", &x[i]);
		    }
		    clrscr();
		    printf("\nYou entered following data:\n\tN=  %d\n\tX=",n,x[i]);
		    for (i = 0; i < n; i++)
			{
			    printf("  %.2f",x[i]);
			}
	    //Calculating sum
		for (i = 0; i < n; i++)
		    {
			sum = sum + x[i];
		    }
        //selecting choice
		do
		    {
			choices();
			scanf("%d",&choice);
			switch(choice)
			    {
				//Mean
				case 1:
                    clrscr();
                    average = sum / (float)n;
				    printf("\t _______________________________________________");
				    printf("\n\t|");printf("\t\t\t\t\t\t|");
				    printf("\n\t|");printf("\t\t\t\t\t\t|");
				    printf("\n\t|\tThe mean of entered data is %.2f.", average);printf("\t|");
				    printf("\n\t|");printf("\t\t\t\t\t\t|");
				    printf("\n\t|_______________________________________________|\n");
				    average=0;
                break;
				//Median
				case 2:
                    clrscr();
				    //Arranging Data
				    for(i=n-1;i>=0;i--)
					for(j=0;j<=i;j++)
					    if(x[j]>=x[j+1])
						{
						    swap=x[j];
						    x[j]=x[j+1];
						    x[j+1]=swap;
						}
				    //Calculation of median
				    if ( n % 2 == 0)
					median = (x[n/2] + x[n/2+1])/2.0 ;
				    else
					median = x[n/2 + 1];
				    //Printing result
				    printf("Arranging input data in ascending order.\n");
				    for (i = 1 ; i <= n ; i++)
					printf("\t %.2f  ", x[i]);
					printf("\n\t _______________________________________________");
					printf("\n\t|");printf("\t\t\t\t\t\t|");
					printf("\n\t|");printf("\t\t\t\t\t\t|");
					printf("\n\t|\tThe median of entered data is %.2f.", median);printf("\t|");
					printf("\n\t|");printf("\t\t\t\t\t\t|");
					printf("\n\t|_______________________________________________|\n");
					median=0;
                break;
				//Variance
				case 3:
				    clrscr();
                    for (i = 0; i < n; i++)
					{
					    sum1 = sum1 + pow((x[i] - average), 2);
					}
				    variance = sum1 / (float)n;
				    printf("\t _______________________________________________");
				    printf("\n\t|");printf("\t\t\t\t\t\t|");
				    printf("\n\t|");printf("\t\t\t\t\t\t|");
				    printf("\n\t|\tVariance of entered data is %.2f.", variance);printf("\t|");
				    printf("\n\t|");printf("\t\t\t\t\t\t|");
				    printf("\n\t|_______________________________________________|\n");
				    variance=0,sum1 = 0;
                break;
				//Standard Deviation
				case 4:
                    clrscr();
				    for (i = 0; i < n; i++)
					{
					    sum1 = sum1 + pow((x[i] - average), 2);
					}
				    variance = sum1 / (float)n;
				    std_deviation = sqrt(variance);
				    printf("\t _______________________________________________");
				    printf("\n\t|");printf("\t\t\t\t\t\t|");
				    printf("\n\t|");printf("\t\t\t\t\t\t|");
				    printf("\n\t|  Standard deviation of entered data is %.2f.", std_deviation);printf("\t|");
				    printf("\n\t|");printf("\t\t\t\t\t\t|");
				    printf("\n\t|_______________________________________________|\n");
				    sum1=0,std_deviation=0,variance=0;
                break;
				//Enter new data
				case 5:
                    data_calc();
                //Exit
				case 6:
				    exit(0);
				//if wrong input
				default:printf("Invalid Choice.\n");
				break;
			}
		}
	    while(choice!=5);
	}
//main function
int main()
{
    data_calc();
    getch();
    return 0;
}
