#include <stdio.h>
#include <stdlib.h>

void	print_tree(int *array_int, int size)
{
  int	width;
  int	i;
  int	j;
  int	copy_size;

  copy_size = size;
  i = 0;
  width = array_int[nb_total_floor(size) - 1];
  j = 0;

  while (i < nb_total_floor(size))
    {
      j = (width - array_int[i]) / 2;
      while (j > 0)
	{
	  printf(" ");
	  j--;
	}
      
      while (array_int[i] > 0)
	{
	  printf("*");
	  array_int[i]--;
	}
      
      j = (width - array_int[i]) / 2;
      while (j > 0)
	{
	  printf(" ");
	  j--;
	}
      printf("\n");
      i++;
    }

  i = 0;
  while (i < size)
    {
      j = (width - size) / 2;
      while (j > 0)
	{
	  printf(" ");
	  j--;
	}
      
      if (size % 2 == 0)
	{
	  copy_size = size + 1;
	}
      else
	{
	  copy_size = size;
	}
      while (copy_size > 0)
	{
	  printf("|");
	  copy_size--;
	}
      
      j = (width - size) / 2;
      while (j > 0)
	{
	  printf(" ");
	  j--;
	}
      i++;
      printf("\n");
    }       
}

int	*number_tree(int *array, int size)
{
  int	number;
  int	i;
  int	j;
  int	floor;
  
  number = 1;
  i = 0;
  j = 0;
  
  while (i < size)
    {
      if (j > 0)
	{
	  if (i % 2 == 0)
	    {
	      number -= i;
	    }
	  else
	    {
	      number-= i+1;
	    }
	}
      array[j] = number;
      j++;
      floor = nb_floor(i)-1;
      while (floor > 0)
	{
	  number += 2;
	  array[j] = number;
	  floor--;
	  j++;
	}
      i++;
    }
  return array;
}

int	nb_floor(int size)
{
  int	final;

  final = 4;

  while (size > 0)
    {
      final = final+1;
      size--;
    }
  
  return final;
}

int	nb_total_floor(int size)
{
  int	final;

  final = 0;
  while (size > 0)
    {
      final += nb_floor(size) - 1;
      size--;
    }
  return final;
}

void	sapin(int size)
{
  int *array_int;
  int base;

  if (size <= 0)
    {
      printf("The argument must be positive.\n");
      exit(1);
    }

  base = nb_total_floor(size);
  array_int = malloc(sizeof(int) * base);
  number_tree(array_int, size);
  print_tree(array_int, size);
  free(array_int);
}
  
int	main()
{
  sapin(10);
  return(0);
}
