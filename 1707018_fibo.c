#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
long int *fibo; 
long int n;
void *runner(void *param)
 {
 long int i;
 float f,kk;
  n = atoi(param);// convert to int
  //f= atof(param);
  
  if(n==0)
  {
  
  pthread_exit(0);
  }
  
  fibo= (long int *)malloc(n* sizeof(long int));// array size fixing
  fibo[0]=0;
  fibo[1]=1;
  if(n>2)
  {
  for (i = 2; i < n; i++)
  {
    fibo[i]= fibo[i-1]+fibo[i-2];// calculating fibonacchi numbers 
  }
  }
  pthread_exit(0);
  }
  
 int main(int argc, char *argv[])
 {
 long int k;
 if (argv[1][0]=='-')
 {
 printf("invalid ");
 return 0;
 }
 
 pthread_t tid; 
 pthread_attr_t attr; 
 pthread_attr_init (&attr);
 
 pthread_create(&tid,&attr,runner,argv[1]);
 
 pthread_join(tid,NULL);// waiting untill finish
 if(n==0)
 {
 printf("invalid ");// checking 0
 }
 else
 {
 for(k=0;k<n;k++)
 {
 printf("%li \n",fibo[k]);
 }
 }
 }
 //export PATH="$PATH:/home/chuti"

 
