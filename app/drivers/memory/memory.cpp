/**
  ******************************************************************************
  * @file           : memory.cpp
  * @author         : Rusanov M.N.
  ******************************************************************************
  */

#include "memory.h"
#include <algorithm>

memory::memory(const addr start_addr, CRC_HandleTypeDef& hcrc)
  : memory_t()
  , f_start_addr(static_cast<uint32_t>(start_addr))
  , f_hcrc(hcrc) {}

memory::status memory::read_data_from_flash(data_t* full_data) const
{
  read_arr_from_flash(f_start_addr, reinterpret_cast<uint32_t*>(full_data), sizeof(k_default_val));
  const uint32_t crc_read = read_word(f_start_addr + sizeof(k_default_val));

  if (const uint32_t crc_calc = HAL_CRC_Accumulate(&f_hcrc, reinterpret_cast<uint32_t*>(full_data), 
                                                   sizeof(k_default_val) / sizeof(uint32_t)); 
      crc_read != crc_calc)
  {
    const uint32_t end_addr = f_start_addr + sizeof(k_default_val);
#if USE_FLASH
    erase(f_start_addr, end_addr);
#endif
    write_arr_to_flash(f_start_addr, reinterpret_cast<const uint32_t*>(k_default_val), sizeof(k_default_val));
    write_only_one_word(f_start_addr + sizeof(k_default_val), crc_calc);
    std::copy(std::begin(k_default_val), std::end(k_default_val), full_data);
    return status::GET_DEFAULT;
  }
  return status::READ_OK;
}

