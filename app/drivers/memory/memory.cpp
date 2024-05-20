/**
  ******************************************************************************
  * @file           : memory.cpp
  * @author         : Rusanov M.N.
  ******************************************************************************
  */

#include "memory.h"
#include <algorithm>

memory::memory(const sector_addr start_addr) :
#if USE_FLASH
  flash_rw(),
#else
  eeprom_rw(),
#endif
  f_start_addr(static_cast<uint32_t>(start_addr)) {}

memory::status memory::read_data_from_flash(data_t* full_data) const
{
  read_arr_from_flash(f_start_addr, reinterpret_cast<uint8_t*>(full_data), sizeof(k_default_val));

  for (size_t i = 0; i < sizeof(k_default_val); i++) 
  {
    if (reinterpret_cast<uint8_t*>(full_data)[i] != reinterpret_cast<const uint8_t*>(k_default_val)[i]) 
    {
      const uint32_t end_addr = f_start_addr + sizeof(k_default_val);
      erase_sector(f_start_addr, end_addr);
      write_arr_to_flash(f_start_addr, reinterpret_cast<const uint8_t*>(k_default_val), sizeof(k_default_val));
      std::copy(std::begin(k_default_val), std::end(k_default_val), full_data);
      return status::GET_DEFAULT;
    }
  }
  return status::READ_OK;
}

