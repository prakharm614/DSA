#include <stdio.h>
#include <math.h>
int main()



{
    float z,r,Xl,Xc,PF,I,Vr,Vl,Vc,C,R,L;
    printf("\nenter the valur of Vr : ");
    scanf("%f",&Vr);
    printf("\nenter the value of corresponding I : ");
    scanf("%f",&I);
    printf("\n Enter the value of Vl : ");
    scanf("%f",&Vl);
    printf("\n Enter the value of Vc : ");
    scanf("%f",&Vc);

    r=Vr/I;
    printf("\n The corresponding value of resistance is :%0.3f",r);

    Xl=Vl/I;
    printf("\nThe corresponding value of Xl is :%0.4f",Xl);

    Xc=Vc/I;
    printf("\n The corresponding value of Xc is : %0.4f",Xc);

    L=Xl/314;
    printf("\n The corresponding value of L is : %0.6f",L);

    C=Xc/314;
    printf("\n the correspong value of C is : %0.6f",C);
    
    z=sqrt((r*r)+(Xl-Xc)*(Xl-Xc));

    printf("\n The value of corresponding impedence is :%0.5f",z);

    PF=r/z;

    printf("\nThe value of corresponding power factor is :%0.5f",PF);

    return 0;
}