#include<stdio.h>
#include<conio.h>

void push(int [],int *);
void pop(int [],int *);
void display(int [],int *);
void peep(int [],int *);
void modify(int [],int *);
int main()
{
	int t=-1;
	int s[5],*top=&t;
	int ch;
	while(1)
	{	
		printf("\n 1.push ");
		printf("\n 2.pop");
		printf("\n 3.display");
		printf("\n 4.peep");
		printf("\n 5.exit");
		printf("\n 6.modify");
		printf("\n enter your choics:-");
		scanf("%d",&ch);
	
		switch(ch)
		{
			case 1:
				push(s,top);
				break;
				
			case 2:
				pop(s,top);
				break;
				
			case 3:
				display(s,top);
				break;
				
			case 4:
				peep(s,top);
				break;
				
			case 5:
				exit(0);
				
			case 6:
				modify(s,top);
				break;
		}
		
	}
return 0;
}
void push(int s[],int *top)
{
	int n;
	if(*top==4)
	{
		printf("\n---------------------");
		printf("\n stack is overflow...");
		printf("\n---------------------");
	}
	else
	{
		printf("\n enter an element:-");
		scanf("%d",&n);
		(*top)++;
		s[*top]=n;
	}
}
void pop(int s[],int *top)
{
	if(*top==-1)
	{
		printf("\n-----------------");
		printf("\n stack is empty..");
		printf("\n-----------------");
	}
	else
	{
		printf("\n-------------------------");
		printf("\n %d is removed...",s[*top]);
		printf("\n-------------------------");
		(*top)--;	
	}
	
}
void display(int s[],int *top)
{
	int i;
	if(*top==-1)
	{
		printf("\n-----------------");
		printf("\n stack is empty..");
		printf("\n-----------------");
	}
	else
	{
		for(i=*top;i>=0;i--)
		{
			printf(" %d ",s[i]);
		}
		
	}
}
void peep(int s[],int *top)
{
	if(*top==-1)
	{
		printf("\n-----------------");
		printf("\n stack is empty..");
		printf("\n-----------------");
	}
	else
	{
		printf("\n-----------------------------");
		printf("\n current element is:-%d",s[*top]);
		printf("\n-----------------------------");
	}
}

void modify(int s[], int *top)
{
    int oldElement, newElement, i;
    
    if(*top == -1)
    {
    	printf("\n------------------");
        printf("\n Stack is empty...");
        printf("\n------------------");
    }
    else
    {
    	display(s,top);
        printf("\n Enter element to modify: ");
        scanf("%d", &oldElement);
        
        printf("\n Enter new value: ");
        scanf("%d", &newElement);
        
        for(i = 0; i <= *top; i++)
        {
            if(s[i] == oldElement)
            {
                s[i] = newElement;
                printf("\n----------------------------");
                printf("\n Element %d modified to %d", oldElement, newElement);
                printf("\n----------------------------\n ");
                display(s,top);
                return;
            }
        }
        printf("\n-----------------------------------");
        printf("\n Element %d not found in the stack.", oldElement);
        printf("\n-----------------------------------");
    }
}


