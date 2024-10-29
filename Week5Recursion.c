#include<stdio.h>

int fact(int);
int fib(int);
void toh(int,char,char,char);

int ch,n,fibo,f;

void main(){
    while(1){
        printf("\n1.Factorial\n2.Fibonnaci\n3.Tower of Hanoi\n4.Exit\n");
        printf("");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        printf("");
        switch(ch){
            case 1:printf("Enter the no to find factorial of: ");
            scanf("%d",&n);
            printf("");
            f=fact(n);
            printf("The factorial is: %d ",f);
            printf("");
            break;
            case 2:printf("Enter the number of terms: ");
            scanf("%d",&n);
            printf("FIBONNACCI SEQUENCE: ");
            for(int i=0;i<=n;i++){
                fibo=fib(i);
                printf(" %d ",fibo);
            }
            printf("");
            break;
            case 3:printf("Enter the no of discs: ");
            scanf("%d",&n);
            toh(n,'s','t','d');
            break;
            printf("");
            case 4:exit(0);
        }
    }
}

int fact(int n){
    if(n==1){
        return(1);
    }
    else{
        return(n*fact(n-1));
    }
}

int fib(int n){
    printf("");

    if(n<=1){
        return(n);
    }
    else{
        return(fib(n-1)+fib(n-2));
    }
}

void toh(int n, char s, char t, char d){
    printf("");
    if(n==1){
        printf("move disc %d from %c -> %c\n",n,'s','d');
        return;
    }
    else{
        toh(n-1,'s','d','t');
        printf("move disc %d from %c -> %c\n",n,s,d);
        toh(n-1,'t','s','d');
    }
}
