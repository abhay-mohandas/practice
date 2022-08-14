// Program to do basic maths in C

#include<stdio.h>
#include <math.h>

float add(float a, float b){
    return (a+b);
}


float sub(float a, float b){
    return (a-b);
}


float mul(float a, float b){
    return (a*b);
}


float div(float a, float b){
    return (a/b);
}

float exponents(float a, int b){
    int i=0;
    float result=1;
    //return result;
    for(i=0;i<b;i++){
        result=result*a;
    }
    return result;
}

float modulus(float a, float b){
    if(b==a)
        return 0.0;
    if(b>a)
        return a;
    int temp=0;
    while ((temp+b)<=a) {
        temp += b;
        printf("%d\n",temp);
    }
    return a-temp;
}

int main(){    
    float a=0,b=0,ans=0;
    int choice=1;
    printf("Enter first number:\n");
    scanf("%f", &a);
    printf("Enter second number:\n");
    scanf("%f",&b);
    int condition = 1;
    while (condition) {
        printf("Enter option number of the given options:\n 1)Addition (+)\n 2)Subtraction (-)\n 3)Multiplicaton (*)\n 4)Division (/)\n 5)Exponents (**)\n 6)Modulus (%%)\n >>");
        scanf("%d",&choice);
        switch (choice) {
            case 1: printf("%f + %f = %f",a,b,add(a, b));
                    condition=0;
                    break;
            case 2: printf("%f - %f = %f",a,b,sub(a, b));
                    condition=0;
                    break;
            case 3: printf("%f * %f = %f",a,b,mul(a, b));
                    condition=0;
                    break;
            case 4: printf("%f / %f = %f",a,b,div(a, b));
                    condition=0;
                    break;
            case 5: printf("%f ** %f = %f",a,b,exponents(a, b));
                    condition=0;
                    break;
            case 6: printf("%f %% %f = %f",a,b,modulus(a, b));
                    condition=0;
                    break;
            default:printf("Invalid Input! Try Again...\n");
                    break;
        }
    }
}