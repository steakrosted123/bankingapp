
#include<stdio.h>
void exist(char *fname)
{
    FILE *fp;
    int f=0;
    if(fp=fopen(fname,"r"))
    {
        fclose(fp);
        f=1;
        return;
    }
    else if(f==0)
    {
      printf("Account not found <<<create it>>>\n");
      long int accno;
      char accname[50];
      int amt;
      printf("NAME:");
      scanf("%s",accname);
      printf("Create your ACCOUNT NUMBER:");
      scanf("%ld",&accno);
      printf("Initial amount you deposit:");
      scanf("%d",&amt);
      fp=fopen(fname,"w");
      fprintf(fp,"%d %ld %s",amt,accno,accname);
      fclose(fp);
    }
}
void deposit(char *fname)
{
    FILE *fp;
    int amt,choice;
    long int accno;
    char accname[50];
    fp=fopen(fname,"r");
    fscanf(fp,"%d %ld %s",&amt,&accno,accname);
    fclose(fp);
    printf("enter the choice 1.TO DEPOSIT 2.TO WITHDRAW");
    scanf("%d",&choice);
    if(choice==1)
    {
        int damt;
        printf("Amount you wish to deposit:");
        scanf("%d",&damt);
        amt=damt+amt;
    }
    else if(choice==2)
    {
        int wamt;
        printf("Amount you wish to withdraw:");
        scanf("%d",&wamt);
        if(wamt>amt)
        {
            printf("ALERT:Due to in sufficient balance you can not withdraw");
            return;
        }
        amt=amt-wamt;
    }
    fp=fopen(fname,"w");
    fprintf(fp,"%d %ld %s",amt,accno,accname);
    fclose(fp);
}
void display(char *fname)
{
    FILE *fp;
    char c;
    printf("\n Balance,account number and name are diplayed:");
    fp=fopen(fname,"r");
    c=fgetc(fp);
    while(c!=EOF)
    {
        printf("%c",c);
        c=fgetc(fp);
    }
    fclose(fp);
    printf("\n");
}
void transfer(char *fname)
{
  FILE *fp;
  FILE *fp1;
  int amt;
  long int accno;
  char accname[50];
  fp=fopen(fname,"r");
  fscanf(fp,"%d %ld %s",&amt,&accno,accname);
  fclose(fp);
  char f2[50];
  printf("Enter the username of the account to transfer");
  scanf("%s",f2);
  int amt2;
  long int accno2;
  char accname2[50];
  fp1=fopen(f2,"r");
  fscanf(fp1,"%d %ld %s",&amt2,&accno2,accname2);
  fclose(fp1);
  int amtt;
  printf("Amount to transfer:");
  scanf("%d",&amtt);
  if(amtt>amt)
  {
      printf("ALERT:Due to insufficient balance  Amount you entered is not possible to transfer");
      return;
  }
  amt2=amtt+amt2;
  amt=amt-amtt;
  fp=fopen(fname,"w");
  fprintf(fp,"%d %ld %s",amt,accno,accname);
  fclose(fp);
  fp1=fopen(f2,"w");
  fprintf(fp1,"%d %ld %s",amt,accno,accname);
  fclose(fp1);
  int t;
  printf("To check your account details press 1 or To exit press any key:");
  scanf("%d",&t);
  if(t==1)
  {
      char c;
      printf("\nYour available Balance,account number and your name are diplayed :");
      fp=fopen(fname,"r");
      c=fgetc(fp);
      while(c!=EOF)
     {
        printf("%c",c);
        c=fgetc(fp);
     }
      fclose(fp);
  }
  else
  {
      return;
  }

}
void close(char *fname)
{
    int f;
    f=remove(fname);
    if(f==0)
    {
        printf("<<<Account deleted sucessfully>>>");
    }
}
void main()
{
    printf("<E-Bank service welcomes you>");
    char fname[50];
    printf("enter the username for E-Bank service:");
    scanf("%s",fname);
    exist(fname);
    int op;
    printf("1=To Deposit or withdrawl\n");
    printf("2=To Display account details\n");
    printf("3=To Transfer\n");
    printf("4=To delete account\n");
    printf("Enter the choice:\n");
    scanf("%d",&op);
    if(op==1)
    {
         deposit(fname);
    }
    else if(op==2)
    {
        display(fname);
    }
   else if(op==3)
   {
        transfer(fname);
   }
   else if(op==4)
   {
       close(fname);   }
}
