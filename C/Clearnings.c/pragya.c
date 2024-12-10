
#include<stdio.h> 
void main() 
{ 
 int hindi, english, science,math,computer,LAA,sum ; 
 float per; 
 printf("Enter marks of electronics="); 
 scanf("%d",&hindi); 
 printf("Enter marks of np="); 
 scanf("%d",&english); 
 printf("Enter marks of ecepractical="); 
 scanf("%d",&science); 
 printf("Enter marks of NA="); 
 scanf("%d",&math); 
 printf("Enter marks of LPP="); 
 scanf("%d",&computer); 
 printf("Enter marks of LAA="); 
 scanf("%d",&LAA); 
 
 sum=hindi+english+science+math+computer+LAA; 
 printf("\nSum of marks=%d",sum); 
 
 
 per=(float)sum/6; 
 printf("\nPercentage of marks=%f",per); 
 
 if(per>=90&&per<=100) 
 { 
 printf("\nGrade A"); 
 } 
 else if(per>=80&&per<90) 
 { 
 printf("\nGrade B"); 
 } 
 else if(per>=60&&per<80) 
 { 
 printf("\nGrade C"); 
 } 
 else if(per<60) 
 { 
 printf("\nGrade D"); 
 }        

}