#include<stdio.h>
#include<conio.h>
void insert(int q[],int *f,int *r);
void delete1(int q[],int *f,int *r);
void display(int q[],int *f,int *r);
void modify(int q[],int *f,int *r);

void main()
{
	int ch,front=-1,rear=-1;
	int *f=&front,*r=&rear,q[5];
	
	while(1)
	{
		printf("\n 1.insert");
		printf("\n 2.delete");
		printf("\n 3.display");
		printf("\n 4.exit");
		printf("\n 5.modify");		
		printf("\n enter your choics:-");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: insert(q,f,r); break;
			case 2: delete1(q,f,r); break;
			case 3: display(q,f,r); break;
			case 4: exit(0);
			case 5: modify(q,f,r); break;
		}
	}
	
	getch();
}


void insert(int q[],int *f,int *r)
{
	int n;
	if((*r+1)%5==*f)
	{
		printf("\n queue is overflow...");
	}
	else
	{
		printf("\n enter an element:-");
		scanf("%d",&n);
		if(*r==-1 && *f==-1)
		{
			*f=*r=0;
		}
		else
		{
			*r=(*r+1)%5;
		}
		q[*r]=n;
	}
}
void delete1(int q[],int *f,int *r)
{
	int n;
	if(*f==-1 && *r==-1)
	{
		printf("\n queue is empty...");
	}
	else
	{
		n=q[*f];
		if(*f==*r)		
		{
			*f=*r=-1;
		}
		else
		{
			*f=(*f+1)%5;
		}
		printf("%d is deletd...",n);
	}
}
void display(int q[],int *f,int *r)
{
	int i;
	if(*f==-1 && *r==-1)
	{
		printf("\n queue is empty...");
	}
	else
	{
		for(i=*f;i!=*r;(i=(i+1)%5))
		{
			printf(" %d ",q[i]);
		}
			printf(" %d ",q[i]);
	}
}
void modify(int q[],int *f,int *r)
{
	int i,oldele,newele,found=0;
	if(*f==-1)
	{
		printf("\n queue is empty...");
	}
	else
	{
		printf("\n enter an old element: ");
		scanf("%d",&oldele);
		printf("\n enter an new element: ");
		scanf("%d",&newele);
		for(i=*f;i!=*r;(i=(i+1)%5))
		{
			if(q[i]==oldele)
			{
				q[i]=newele;
				found=1;
				printf("\n new element is modifide...");
			}
		}
		if(q[i]==oldele)
		{
			q[i]=newele;
			found=1;
			printf("\n new element is modifide...");
		}
		if(!found)
		{
			printf("\n element is not found...");
		}
		
	}
}

