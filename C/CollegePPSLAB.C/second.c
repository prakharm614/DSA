#include <stdio.h>
void main ()
{
    float a,b,c,d,e,f,sum,per,max;
     
printf("Enter maximum total full marks:-  ");
scanf("%f",&max);
printf("Enter marks of subject 1:-  ");
scanf("%f",&a);
printf("enter marks of subject 2:-  ");
scanf("%f",&b);
printf("enter mrks of subject 3:-  ");
scanf("%f",&c);
printf("enter marks of subject 4:-  ");
scanf("%f",&d);
printf("enter marks of subject 5:-  ");
scanf("%f",&e);
printf("enter marks of subject 6:-  ");
scanf("%f",&f);

sum=a+b+c+d+e+f;
per=(sum*100)/(max);

printf("Total marks obtained=%.2f",sum);
printf("\n Percentage marks obtained=.%.2f",per);


}
