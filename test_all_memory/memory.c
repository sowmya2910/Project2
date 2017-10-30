/*This program is for manipulation of data in the memory location*/

/*Author Sowmya Ramakrishnan, Vinayak Srivatsan Kovalam Mohan*/


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "memory.h"


/*memory move function*/
uint8_t *my_memmove(uint8_t *src, uint8_t *dst, size_t length)
{

    size_t i;
    uint8_t *temp;
    if (! src )
    {
    return NULL;
    }

    temp = (uint8_t*) malloc(length * sizeof(uint8_t));
    for(i=0;i<length;i++)
    {
        *(temp+i)=*(src+i);
    }

    for(i=0;i<length;i++)
    {
        *(dst+i)=*(temp+i);
    }
   free(temp);

    return dst;
}



/*memory copy function*/
uint8_t *my_memcpy(uint8_t *src,uint8_t *dst,size_t length)
{
int i;
if (! src )
    {
    return NULL;
    }

for(i=0;i<length;i++)
    {
      *(dst+i)= *(src+i);
    }
return dst;
}


int8_t *my_memset(uint8_t *src,size_t length, uint8_t value)
{
uint8_t i;
for(i=0;i<length;i++)
   {
     *(src+i)=value;
   }
return(int8_t*)src;
}


/*Function to set all memory locations to Zero*/

uint8_t *my_memzero(uint8_t *src, size_t length)
{
uint8_t i;
if (! src )
    {
    return NULL;
    }

for(i=0;i<length;i++)
   {
     *(src+i)=0;
   }
return src;
}


/*Funtion for Reversing*/

uint8_t *my_reverse(uint8_t *src,size_t length)
{
int i=0;
int j=0;			       
  uint8_t temp;
  j=length-1;
  if (! src )
    {
    return NULL;
    }
 				
       while(i <j)				
       {
         temp= *(src+i);
         *(src+i) = *(src+j);
         *(src+j)=temp;
         i++;
         j--;
       }
       return src;

}


/*Function for reserving of memory for words*/
int32_t *reserve_words(size_t length)
{
int32_t *ptr;
ptr = (int32_t*) malloc(length * sizeof(int32_t));
return ptr;
}


/*Function to free memory locations*/
void free_words(int32_t *src)
{
if(src!=NULL)
{
free(src);
}
}

