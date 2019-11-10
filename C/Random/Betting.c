#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
Test Variables:
-Month
-Year
-Amount to Bet
-Balance
:1000 base start
All test Variables are used from an input file in a straight line with a space separating each other
In the end you will have the simulation of a month of small/large betting in a casino
*/
//EX:10 2018 2 1000
float Probability(float randomValue)
{
  float randomNew = (float)(rand()%1000)/1000;
  if(randomValue == randomNew)
    return Probability(randomValue);
  else
    return randomValue;
}
int powe(int betAmount,int power,int originalBetAmount)
{
  if(power > 1)
    return powe(betAmount*originalBetAmount,power-1,originalBetAmount);
  else
    return betAmount;
}
int bet(int x,float randomValue,int betAmount,int *binary){
    randomValue = (float)(rand()%100)/100;
    randomValue = Probability(randomValue);
    //printf("%.2f\n",randomValue);
    int power = *binary;
    int originalBetAmount = betAmount;
    int value = powe(betAmount,power,originalBetAmount);
    if (randomValue <= 0.49)
    {
      x = x - value;
      power++;
    }
    else if (randomValue >= 0.51)
    {
      x = x + value;
      power = 1;
    }
    else if (randomValue < 0.51 && randomValue > 0.49)
    {
      x = x - value;
      power++;
    }
    *binary = power;
    return x;
}

int main(void)
{
  srand((unsigned int)time(NULL));
  int balance,month,year,betAmount,finalBalance,market;
  float randomValue;
  int *binary = malloc(sizeof(binary));
  *binary = 1;
  market = 0;

  FILE *filein = fopen("betting.txt","r");
  FILE *fileout = fopen("statistics.txt","a");
  fscanf(filein,"%d %d %d %d",&month,&year,&betAmount,&balance);

  fprintf(fileout,"Month: %d Year: %d Amount Betted: %d\n",month,year,betAmount);
  if(month == 12)
  {
    month = 1;
    year++;
  }
  else
    month++;
  fprintf(fileout,"Start: %d",balance);
  for(int i = 0; i<22;i++)
  {
    //if(i!=0)
    //printf("Initial Balance:%d\n",balance);
    finalBalance = balance;
    for (;;)
    {
      if(finalBalance > 40+balance)
        break;
      else
        finalBalance = bet(finalBalance,randomValue,betAmount,binary);
      if(finalBalance < 0)
        break;
    }
    market = market + (finalBalance-balance);
    //printf("Final Balance:%d\n",finalBalance);
    balance = finalBalance;
  }
  fprintf(fileout," Current: %d Earnings: %d\n",finalBalance,market);

  fclose(filein);
  fclose(fileout);
  FILE *filewrite = fopen("betting.txt","w");
  if(finalBalance<0)
    fprintf(filewrite,"%d %d %d %d",month,year,betAmount,1000);
  else
    fprintf(filewrite,"%d %d %d %d",month,year,betAmount,balance);
  fclose(filewrite);
  return 0;
}
/*
End Variables:
-Month
-Year
-Amount Betted
-Start of month Balance
-End of month Balance
-Earnings or losses in the month
*/

