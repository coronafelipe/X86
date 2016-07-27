/*
 	Author		:Felipe Corona
	Date		:November 5, 2014
	Description	:Lab 6 - bubble Sort
*/

#include <stdio.h>
#define n 20

int main()
{
    int array[n];
    int i;
    
    char swapped;
 
    printf("Enter the elements one by one \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    printf("Input array elements \n");
    for (i = 0; i < n ; i++)
    {
        printf("%d\n", array[i]);
    }

    /*  Bubble sorting begins */   
    do
    {
	swapped = 0;
	for (i = 1; i < n; i++)
	{
		//body of the for loop
		//convert this to assembly
/*		if (array[i] < array[i-1])
		{
			//swap a[i] and a[i-1]
			temp = array[i];
			array[i] = array[i-1];
			array[i-1] = temp;
			swapped = 1;
		}	
*/
		asm   volatile("cmp %0, %1;"
				"jg DONE;"
				"xor %0, %1;"
				"xor %1, %0;"
				"xor %0, %1;"
				"mov %2, 1;"
				"DONE:"
				:"+r" (array[i]), "+r" (array[i-1]), "+r" (swapped)
				:
				:"cc"
				);
	}
    } while (swapped);

    printf("Sorted array is...\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", array[i]);
    }

    return 0;
}
