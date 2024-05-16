/**
  ******************************************************************************
  * @file           : median_filter_ekstrom.h
  * @author         : Rusanov M.N.
  * @version        : V1.0.0
  * @date           : 16-May-2024
  * @brief          : Header for median_filter_ekstrom.cpp file.
  *                   This class implements a median filter to filter the values
  *                   of a data stream such as an ADC.
  *
  ******************************************************************************
  */

#pragma once

#include <sys/_stdint.h>

class median_filter_ekstrom
{
public:
  explicit median_filter_ekstrom();
  uint16_t filter(uint16_t data);

private:
  struct pair
  {
    pair* point; /* Pointers forming list linked in sorted order */
    uint16_t value; /* Values to sort */
  };

  static constexpr uint16_t filter_size = 27;
  /* Stopper is smaller than any data */
  static constexpr uint16_t stopper = 0; /* Result will never be equal to stopper */

  pair f_buffer[filter_size] = { { nullptr, 0 } }; /* Buffer of width pairs */
  pair* f_p_data = f_buffer; /* Pointer into circular buffer of data */
  pair f_small = { nullptr, stopper }; /* Chain stopper */
  pair f_big = { &f_small, 0 }; /* Pointer to head (largest) of linked list.*/
};
