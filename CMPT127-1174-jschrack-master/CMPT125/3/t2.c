#include <stdlib.h> 
#include <stdint.h> 
#include <string.h> 
#include <assert.h>
#include <stdio.h>
#include <limits.h>

void overflow(int one)
{
	printf("%i\n", one);

	if (one <= INT_MAX)
	{
		overflow(one + 1);
	}
}


void foo(int n)
{
    int* arr = malloc(100 * sizeof(int));
    assert(arr);
    for(int i=0; i < 100; i++){
        arr[i] = i + n;
    }
    printf("%d\n", arr[99]);
    foo(n+1);    
}

void bar(int n)
{
    int arr[100];
    for(int i=0; i < 100; i++){
        arr[i] = i + n;
    }
    printf("%d\n", arr[99]);    
    bar(n+1);    

}

int main()
{
	int one = 1;

	foo(one);
}