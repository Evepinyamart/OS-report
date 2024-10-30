#include <stdio.h>
#include <stdlib.h>

// Global variables
int a, b, c;

int func(int round)
{
  if (round <= 0)
  {
    return 0;
  }
  int local_var = round; // เพิ่มตัวแปร local ใน stack
  printf("Address stack round %d: %p\n", 4 - round, &round);
  printf("Address local_var %d: %p\n", 4 - round, &local_var);
  return func(round - 1);
}

int main(void)
{
  int *ptr1;
  int *ptr2;
  int *ptr3;
  int main_stack_var;

  // Malloc 3 times and check for success
  ptr1 = malloc(sizeof(int));
  ptr2 = malloc(sizeof(int));
  ptr3 = malloc(sizeof(int));

  // Print addresses
  printf("Address ptr1 = %p\n", ptr1);
  printf("Address ptr2 = %p\n", ptr2);
  printf("Address ptr3 = %p\n", ptr3);
  printf("Address Global: %p %p %p\n", &a, &b, &c);
  printf("Address main_stack_var: %p\n", &main_stack_var);

  // Call recursive function
  func(3);

  // Free allocated memory
  free(ptr1);
  free(ptr2);
  free(ptr3);

  return 0;
}
