#include <stdlib.h>
#include <string.h>
#include "onesttropbg.h"
  
// Defining comparator function as per the requirement
static int myCompare(const void* a, const void* b)
{
  
    // setting up rules for comparison
    return my_strcmp(*(const char**)a, *(const char**)b);
}
  
// Function to sort the array
void sort(const char* arr[], int n)
{
    // calling qsort function to sort the array
    // with the help of Comparator
    qsort(arr, n, sizeof(const char*), myCompare);
}
  
int main()
{
  
    // Get the array of names to be sorted
    const char* arr[]
        = { "geeksforgeeks", "geeksquiz", "clanguage" };
  
    int n = sizeof(arr) / sizeof(arr[0]);
    int i;
    sort(arr, n);
    // Print the sorted names
    for (i = 0; i < n; i++)
        {my_putstr("arr[i]");
        my_putchar('\n');}
  
    return 0;
}