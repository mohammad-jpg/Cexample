#include <stdio.h> // standard input, output library
#include <math.h> // library for functions used in the code, round, floor etc etc

#define kmh 851.343239  // defining constant speed

float get_hours(float i);
float get_minutes(float i);
void print_end();
void print_start();

int main()
{
    float upper_limit,lower_limit,size;  //intialising the varibles that user needs to input

    printf("Enter the lower limit on distance in km: ");
    scanf("%f",&lower_limit);
    printf("Enter the upper limit on distance in km: ");
    scanf("%f",&upper_limit);
    printf("Enter the step size in km: ");
    scanf("%f",&size);
    /* taking in the user inputs*/


    if (lower_limit>upper_limit|| size<0|| size > upper_limit-lower_limit || upper_limit <0 ||lower_limit <0) // checking if the lower limit is greater than the upper limit  or if the size is less than 0, checking if the input will produce a result.

    {

        printf("error, please try again\n");
        main (); // running main function again so user doesnt have to


    }
    else {
        print_start(); // function to print the top part of the table
        for (float i = lower_limit; i <= upper_limit; i = i + size) // simple for loop to go through the values from the lower limit to the upper limit with the size value being the increment
        {


            printf("\n|  %8.2f        |%8.0f              |%8.0f         |", i, get_hours(i), get_minutes(i)); // printing the value of i (hours ) and the returned value from the hours and minutes functions below

        }
        print_end(); // function to print the bottom part of the table
    }

}

float get_hours(float i) // function to get hour value
{
    float hours = floor(i /kmh);                       // flooring the value to get a rounded figure
    return hours;

}
float get_minutes(float i) // function to get minute value
{
    float time = i/kmh;
    int hour = floor( time );                   // flooring the time to get a non decimal  value for hour
    float mins = (60.0*(time - hour) );        // converting hours to minutes
    int rounded = round(mins);                // function that rounds up if greater than .5, rounds down if less than .5


    return rounded;                            // return value



}
void print_end()
{
    printf("\n=============================================================");
}
/* function to print start of table */
void print_start()
{

    printf("=============================================================\n"
           "| distance (km)    |      hours           |  minutes        |\n"
           "|===========================================================|");
}
/* function to print end of table */

