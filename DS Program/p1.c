#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void add(int arr[], int *ele);
void delete1(int arr[], int *ele);
void modify(int arr[],int *ele);
void display(int arr[],int *ele);
void sort(int arr[],int *ele);
void simple_search(int arr[],int *ele);
void binary_search(int arr[],int *ele);

int main() 
{
    int e = 0;
    int *ele = &e, ch;
    int arr[MAX];

    while (1) 
	{
		printf("\n --------------");
        printf("\n 1. Add element");
        printf("\n --------------");
        printf("\n 2. delete element");
        printf("\n -----------------");
        printf("\n 3. modify element");
        printf("\n -----------------");
        printf("\n 4. sort an array");
		printf("\n ----------------"); 
        printf("\n 5. simple search");
		printf("\n ----------------"); 
		printf("\n 6. binary search");
		printf("\n ----------------"); 
		printf("\n 7. display");
		printf("\n ----------");
        printf("\n 8. Exit");
        printf("\n -------");
        printf("\n Enter your choice:-");
        scanf("%d", &ch);

        switch (ch) 
		{
            case 1:	add(arr, ele);	break; 
            case 2: delete1(arr, ele);	break;
            case 3: modify(arr,ele);	break;
            case 4: sort(arr,ele);	break;
            case 5:	simple_search(arr,ele);	break;
            case 6:	binary_search(arr,ele);	break;
            case 7: display(arr,ele); break;
            case 8: exit(0);
            
            default:
            	printf("\n ---------------------------------");
            	printf("\n Invalid choice. Please try again.");
            	printf("\n ---------------------------------");
        }
    }
    return 0;
}

void add(int arr[], int *ele) 
{
    int n;
    if (*ele < MAX) 
	{
        printf("\n Enter an element: ");
        scanf("%d", &n);
        arr[*ele] = n;
        (*ele)++;
        printf("\n -------------------");
        printf("\n %d is inserted...",n);
        printf("\n -------------------");
    } 
	else 
	{
		printf("\n ----------------");
        printf("\n Array is full...");
        printf("\n ----------------");
    }
}

void delete1(int arr[], int *ele) 
{
    int n, i, j, found = 0;
    if (*ele == 0) 
	{
		printf("\n -----------------");
        printf("\n Array is empty...");
        printf("\n -----------------");
    }
	else
	{
        printf("\n Enter the element to delete: ");
        scanf("%d", &n);
        for (i = 0; i < *ele; i++) 
		{
            if (arr[i] == n) 
			{
                found = 1;
                for (j = i; j < *ele - 1; j++) 
				{
                    arr[j] = arr[j + 1];
                }
                (*ele)--;
                printf("\n -----------------------------");
                printf("\n %d deleted from the array.", n);
                printf("\n -----------------------------");
                break;
            }
        }
        if (!found) 
		{
			printf("\n -----------------------------");
            printf("\n %d not found in the array.", n);
            printf("\n -----------------------------");
        }
    }
}
void modify(int arr[], int *ele) 
{
    int old_value, new_value, i, found = 0;

    if (*ele == 0) 
	{
		printf("\n -----------------");
        printf("\n Array is empty...");
        printf("\n -----------------");
    } 
	else 
	{
		display(arr,ele);
        printf("\n Enter the element to modify: ");
        scanf("%d", &old_value);
        for (i = 0; i < *ele; i++) 
		{
            if (arr[i] == old_value) 
			{
                found = 1;
                printf("\n Enter the new value: ");
                scanf("%d", &new_value);
                arr[i] = new_value;
                
                printf("\n Element modified. \n");
                display(arr,ele);
                break;
            }
        }
        if (!found) 
		{
			printf("\n --------------------");
            printf("\n Element not found...");
            printf("\n --------------------");
        }
    }
} 
void display(int arr[],int *ele)
{
	int i;
	
	if(*ele==0)
	{
		printf("\n -------------------");
		printf("\n array is empty...");
		printf("\n -------------------");
	}
	else
	{
		for(i=0;i<*ele;i++)
		{
			printf("\n %d ",arr[i]);
		}
	}
}
void sort(int arr[], int *ele) 
{
    int i, j, temp;
    if (*ele == 0) 
	{
		printf("\n -----------------");
        printf("\n Array is empty...");
        printf("\n -----------------");
    } 
	else 
	{
        for (i = 0; i < *ele - 1; i++) 
		{
            for (j = 0; j < *ele - 1 - i; j++) 
			{
                if (arr[j] > arr[j + 1]) 
				{
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        
        printf("\n ---------------");
        printf("\n Array sorted.\n");
        printf("\n ---------------");
        display(arr,ele);
    }
}
void simple_search(int arr[],int *ele)
{
	int se,i,found=0;
	if(*ele==0)
	{
		printf("\n -----------------");
		printf("\n array is empty...");
		printf("\n -----------------");
	}
	else
	{
		printf("\n enter an search element:-");
		scanf("%d",&se);
		for(i=0;i<*ele;i++)
		{
			if(arr[i]==se)
			{
				found=1;
				printf("\n --------------------------");
				printf("\n %d is found is array...",se);
				printf("\n --------------------------");
				break;
			}
		}
		if(!found)
		{
			printf("\n -------------------");
			printf("%d is not founded..",se);
			printf("\n -------------------");
		}
	}
}

void binary_search(int arr[], int *ele) 
{
    int se, low = 0, high = *ele - 1, mid, found = 0;
    if (*ele == 0)
	{
		printf("\n -----------------");
        printf("\n Array is empty...");
        printf("\n -----------------");
    } 
	else 
	{
        printf("\n Enter the element to search: ");
        scanf("%d", &se);

        while (low <= high && !found) 
		{
            mid = (low + high) / 2;
            if (se == arr[mid]) 
			{
				printf("\n -----------------------------------------");
                printf("\n %d element is found at index %d.", se, mid);
                printf("\n -----------------------------------------");
                found = 1;
            } 
			else 
			{
                if (se > arr[mid]) 
				{
                    low = mid + 1;
                } else 
				{
                    high = mid - 1;
                }
            }
        }
        if (!found) 
		{
			printf("\n ----------------------------");
            printf("\n %d element is not found.", se);
            printf("\n ----------------------------");
        }
    }
}

