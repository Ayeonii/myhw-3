#include <sys/types.h>
#include <limits.h>
#include <stdio.h>
#include "run.h"
#include "util.h"
#define buff 512


void *base = 0;
void *end = 0;

p_meta find_meta(p_meta *last, size_t size) {
  p_meta index = base;
  p_meta result = base;

  if(base == end )
	return -1;

  switch(fit_flag){
    case FIRST_FIT:
    {
      while(index != end)
	{
		if(!index ->next)
		{
			result = index;
			break;
		}
		index = index ->next;
	}
    }
    break;

/////////////////////////best fit

    case BEST_FIT:
    {
      
    }
    break;


//////////////////////////worst fit

    case WORST_FIT:
    {
      
    }
    break;

  }
  return result;
}
////////////////////////////////malloc

void *m_malloc(size_t size) {

	int m1 = size + META_SIZE;
	int m2;

	int new_size = (size/4)*4 + 4;
	p_meta tmp = find_meta(end,size);
	char *p =NULL;

	if(tmp == base)
	{
		p = sbrk(META_SIZE + new_size);
		if(p == -1)
			return NULL;
		
		tmp = p;
		tmp -> next = NULL;

		
		if(base == NULL)
		{
		 base == p;
		 tmp -> prev = NULL;
		 end = base;
		}
		else
		{
		 tmp ->prev = end;
		 p_meta end_tmp =  end;

		end_tmp -> next = tmp;
		end = temp; 
		}
	}
	else
	{

		temp = (NULL, new_size);
		
		if(!temp)
			return NULL;
		base = temp;

	}
	
	
	
}

void m_free(void *ptr) {

	p_meta n_prev = ptr - META_SIZE;
	n_prev -> free = 1;

	if(n_prev-> prev != -1)
	{
	n_prev = n_prev -> prev;

	n_prev ->size = n_prev->size + n_prev->next->size + META_SIZE;
	n_prev ->next = n_prev->next->next;
	}
	else
	{
	n_prev -> size = n_prev->next->size + n_prev->size + n_prev->next + META_SIZE;
	n_prev -> next = n_prev->next->next; 
	}
 
}

void*m_realloc(void* ptr, size_t size)
{
 
 

}
