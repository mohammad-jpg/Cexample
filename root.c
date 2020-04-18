

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*prototyping functions*/
double func(double a, double b, double c, double d, double x);
void print_start();

double func(double a, double b, double c, double d, double x)/* function to find the f(x) */
{
    double ans;
    ans = a*pow(x,3) + b*x*x + c*x + d;

    return ans;
}
void print_start()
{
    printf("************************************************\n");
    printf("Welcome to the cubic root estimator.\nThis estimates the value of one root of\nf(x)=ax^3+bx^2+cx+d.");
    printf("\n************************************************");

}
int main()
{

    print_start();


    double lim1,lim2 ,x1, x2, r, a, b, c, d, mp,v1,v2;
    char res = 'y';

    while(res == 'y') /* looping tso the user can rerun the program */
    {


        printf("\n\nEnter the coefficients in the form \"a b c d\": ");
        scanf("%lf %lf %lf %lf",&a ,&b, &c, &d );

        v2=1; /* Resetiing value of var1 so that function can be re-used */

        /* to make sure input is valid*/
        if(a==0)
        {
            printf("\nerror, please enter a non zero number for a \n");
        }

        else
        {

            for(lim1 = 1; v2 > 0; lim1++) /* starts at -1 and if it detects that theres no roots than expands  */
            {
                lim2 = lim1*-1;
                x2 = lim1;
                x1 = lim2;


                if((func(a, b, c, d, x1))*func(a, b, c, d, x2) < 0) /* seeing if f(x1)*f(x2)is positive*/
                {

                    for(v1 = 1; v2 > 0; v1++)
                    {
                        mp = (x1 + x2)/2;

                        /*  if the root exists the cinditon will be true*/
                        if(func(a, b, c, d, mp) < 0.001 && func(a, b, c, d, mp) > -0.001 )
                        {
                            r = mp;
                            v2 = -1;

                        }

                        if((func(a, b, c, d, mp))*(func(a, b, c, d, x1)) <= 0)
                        {
                           x2 = mp;
                        }

                        else if(((func(a, b, c, d, mp))*(func(a, b, c, d, x2)) <= 0))
                        {
                            x1=mp;
                        }

                    }
                  }
                }
                /*answer*/
                printf("There is a root at: x = %.3f\n", r);
            }


    printf("Do you wish to try another cubic [y/n]:");
    scanf(" %c", &res);

    }
    return 0;
}



