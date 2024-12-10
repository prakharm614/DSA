# include <stdio.h>
int main()
/*we have to give 50 for students passed in both subjects and 20 and 30 for pasiing science and maths respectively.*/

{
    int maths,scie;
    printf("Enter your marks in  maths\n");
    scanf("%d",&maths);
    printf("Enter your marks in science\n");
    scanf("%d",&scie);

    if (maths>33 && scie>33)
    {
        printf("Congratulations you are pass!!\n You won Rs.50");
        }
  else if (maths>33)
    {
        printf("congratulations you are pass in maths!!\n You won Rs.30");
    }
     else if (scie>33)
{
    printf("congratulations you are pass in science!!\n You won Rs.20 ");
}
else if(maths<33 && scie<33)
{
    printf("SORRY!! You are fail ! Ja padhle bhosadi ke");
}
   
  }

