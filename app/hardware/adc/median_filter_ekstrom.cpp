/**
  ******************************************************************************
  * @file           : median_filter_ekstrom.cpp
  * @author         : Rusanov M.N.
  ******************************************************************************
  */

#include "median_filter_ekstrom.h"

median_filter_ekstrom::median_filter_ekstrom() = default;

uint16_t median_filter_ekstrom::filter(uint16_t data)
{
  if (data == stopper) 
  {
    data = stopper + 1; /* No stoppers allowed. */
  }

  if ((++f_p_data - f_buffer) >= filter_size) 
  {
    f_p_data = f_buffer; /* Increment and wrap data in pointer.*/
  }

  f_p_data->value = data; /* Copy in new data */
  pair* successor = f_p_data->point; /* Save pointer to old value's successor */
  const pair* median = &f_big; /* Median initially to first in chain */
  pair* scan = &f_big; /* Points to pointer to first (largest) data in chain */

  /* Handle chain-out of first item in chain as special case */
  if (scan->point == f_p_data) 
  {
    scan->point = successor;
  }

  pair* scan_old = scan; /* Save this pointer and */
  scan = scan->point; /* step down chain */

  /* Loop through the chain, normal loop exit via break. */
  for (uint16_t i = 0; i < filter_size; ++i) 
  {
    /* Handle odd-numbered item in chain */
    if (scan->point == f_p_data) 
    {
      scan->point = successor; /* Chain out the old data.*/
    }

    if (scan->value < data) 
    {
      /* If data is larger than scanned value,*/
      f_p_data->point = scan_old->point; /* Chain it in here. */
      scan_old->point = f_p_data; /* Mark it chained in. */
      data = stopper;
    }

    /* Step median pointer down chain after doing odd-numbered element */
    median = median->point; /* Step median pointer. */
    if (scan == &f_small) 
    {
      break; /* Break at end of chain */
    }
    scan_old = scan; /* Save this pointer and */
    scan = scan->point; /* step down chain */

    /* Handle even-numbered item in chain. */
    if (scan->point == f_p_data) 
    {
      scan->point = successor;
    }

    if (scan->value < data) 
    {
      f_p_data->point = scan_old->point;
      scan_old->point = f_p_data;
      data = stopper;
    }

    if (scan == &f_small) 
    {
      break;
    }

    scan_old = scan;
    scan = scan->point;
  }

  return median->value;
}
