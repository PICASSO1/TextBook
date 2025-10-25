// pt_ops.c -- pointer operations
#include <stdio.h>
int main(void)
{
  int urn[3] = {100,200,300};
  int * ptr1, * ptr2;

  ptr1 = urn;         // assign an address to a pointer
  ptr2 = &urn[2];     // ditto
                      // dereference a pointer and take
                      // the address of a pointer      
  printf("ptr1 = %p, *ptr1 =%d, &ptr1 = %p\n",
       ptr1, *ptr1, &ptr1);
  ptr1++;            // increment a pointer            
  printf("values after ptr1++\n");
  printf("ptr1 = %p, *ptr1 =%d, &ptr1 = %p\n",
       ptr1, *ptr1, &ptr1);
  printf("ptr2 = %p, *ptr2 =%d, &ptr2 = %p\n",
       ptr2, *ptr2, &ptr2);
  ptr2--;            // decrement a pointer
  printf("values after --ptr2\n");
  printf("ptr2 = %p, *ptr2 = %d, &ptr2 = %p\n",
       ptr2, *ptr2, &ptr2);
  --ptr1;            // restore to original value
  ++ptr2;            // restore to original value    
  printf("ptr2 - ptr1 = %d\n", ptr2 - ptr1);
                     // pointer subtraction       
  return 0;
}
