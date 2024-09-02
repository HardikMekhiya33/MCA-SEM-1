#include<stdio.h>
#include<conio.h>
void insert(int [],int *,int *);
void delete(int [],int *,int *);
void display(int [],int *,int *);
void modify(int [],int *,int *);
void main()
{
	int front=-1,rear=-1,ch,q[5];
	int *f=&front,*r=&rear;
	while(1)
	{
	
	printf("\n 1.insert");
	printf("\n 2.delete");
	printf("\n 3.modify");
	printf("\n 4.display");
	printf("\n 5.exit");
	printf("\n enter your choics:-");
	scanf("%d",&ch);
	
		switch(ch)
		{
			case 1: insert(q,f,r); break;
			case 2: delete(q,f,r); break;
			case 3: modify(q,f,r); break;
			case 4: display(q,f,r); break;
			case 5: exit(0);
		}
	}
	
	getch();
}
void insert(int q[],int *f,int *r)
{
	int n;
	if(*r==4)
	{
		printf("\n -----------------");
		printf("\n queue is overflow");
		printf("\n -----------------");
	}
	else
	{
		if(*f==-1 && *r==-1)
		{
			*f=*r=0;
			printf("\n enter first element an queue:-");
			scanf("%d",&n);
			q[*r]=n;
		}
		else
		{
			printf("\n enter element an queue:-");
			scanf("%d",&n);
			(*r)++;
			q[*r]=n;
			
		}
	}
	
}
void delete(int q[],int *f,int *r)
{
	if(*r==-1)
	{
		printf("\n ---------------------");
		printf("\n queue is underflow...");
		printf("\n ---------------------");
	}
	else
	{
		printf("\n ---------------------");
		printf("\n %d is deleted..",q[*f]);
		printf("\n ---------------------");
		(*f)++;
		if(*f>*r)
		{
			*f=*r=-1;
		}
		display(q,f,r);
	}
}
void display(int q[],int *f,int *r)
{
	int i;
	if(*r==-1)
	{
		printf("\n ---------------------");
		printf("\n queue is underflow...");
		printf("\n ---------------------");
	}
	else
	{
		printf("\n -------------------------\n");
		for(i=*f;i<=*r;i++)
		{
			printf("  %d ",q[i]);
		}
		printf("\n -------------------------");
	}
	
}
void modify(int q[],int *f,int *r)
{
	int i,oldele,newele,found=0;
	
	if(*f==-1)
	{
		printf("\n ---------------");
		printf("\n queue is emty..");
		printf("\n ---------------");
	}
	else
	{
		display(q,f,r);
		printf("\n enter an element to modify: ");
		scanf("%d",&oldele);
		
		printf("\n enter an new element: ");
		scanf("%d",&newele);
		
		for(i=*f;i<=*r;i++)
		{
			if(q[i]==oldele)
			{
				q[i]=newele;
				found=1;
				printf("\n -------------------------------");
				printf("\n %d element is modifide with %d",oldele,newele);
				printf("\n -------------------------------");
				display(q,f,r);
				
			}
			
		}
		if(!found)
		{
			printf("\n -----------------------------------");
			printf("\n %d element is not found in queue...",oldele);
			printf("\n -----------------------------------");
		}
		
		
	}
}
