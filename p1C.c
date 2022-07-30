#include <stdio.h>

int main(){
    float lenght=0,breadth=0,area=0,parameter=0;
    printf("To find the area and parameter of rectangle, provide the following details:\n");
    printf("Lenght:\n");
    scanf("%f",&lenght);
    printf("Breadth:\n");
    scanf("%f",&breadth);
    printf("Result:\n");
    area = lenght*breadth;
    parameter = (2.0*lenght)+(2.0*breadth);
    printf("Area = %f \nParameter = %f",area,parameter);
}