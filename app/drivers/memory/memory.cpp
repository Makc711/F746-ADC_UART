/**
  ******************************************************************************
  * @file           : memory.cpp
  * @author         : Rusanov M.N.
  ******************************************************************************
  */

#include "memory.h"

memory::memory(const addr start_addr, CRC_HandleTypeDef& hcrc)
  : memory_t()
  , f_start_addr(static_cast<uint32_t>(start_addr))
  , f_hcrc(hcrc) {}

memory::status memory::read_data_from_flash(data_t* full_data) const
{
  read_arr_from_flash(f_start_addr, reinterpret_cast<uint32_t*>(full_data), sizeof(k_default_val));
  const uint32_t end_addr = f_start_addr + sizeof(k_default_val);
  const uint32_t crc_read = read_word(end_addr);

  if (const uint32_t crc_calc = HAL_CRC_Calculate(&f_hcrc,
      reinterpret_cast<uint32_t*>(full_data),
      sizeof(k_default_val) / sizeof(uint32_t));
      crc_read != crc_calc)
  {
#if USE_FLASH
    erase(f_start_addr, end_addr);
#endif
    write_arr_to_flash(f_start_addr, reinterpret_cast<const uint32_t*>(k_default_val), sizeof(k_default_val));
    read_arr_from_flash(f_start_addr, reinterpret_cast<uint32_t*>(full_data), sizeof(k_default_val));
    const uint32_t crc = HAL_CRC_Calculate(&f_hcrc,
      reinterpret_cast<uint32_t*>(full_data),
      sizeof(k_default_val) / sizeof(uint32_t));
    write_only_one_word(end_addr, crc);
    return status::GET_DEFAULT;
  }
  return status::READ_OK;
}

