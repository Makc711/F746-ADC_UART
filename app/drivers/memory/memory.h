/**
  ******************************************************************************
  * @file           : memory.h
  * @author         : Rusanov M.N.
  * @version        : V1.0.0
  * @date           : 17-May-2024
  * @brief          : Header for memory.cpp file.
  *                   This file contains functions for working with internal
  *                   STM32 memory
  *
  ******************************************************************************
  */

#pragma once

#include "main.h"
#if USE_FLASH
#include "flash_rw.h"
#else
#include "eeprom_rw.h"
#endif

struct data_t
{
  enum class idx
  {
    U0_MIN,
    U0_MAX,
    U1_MIN,
    U1_MAX
  };

  idx index;
  uint16_t value;
};

constexpr data_t k_default_val[] = {
  { data_t::idx::U0_MIN, 500  },
  { data_t::idx::U0_MAX, 3000 },
  { data_t::idx::U1_MIN, 700  },
  { data_t::idx::U1_MAX, 3500 }
};
constexpr auto k_default_val_length = sizeof(k_default_val) / sizeof(data_t);

#if USE_FLASH
class memory : public flash_rw
#else
class memory : public eeprom_rw
#endif
{
public:
  enum class status
  {
    READ_OK,
    GET_DEFAULT
  };

  explicit memory(sector_addr start_addr);
  status read_data_from_flash(data_t* full_data) const;

private:
  uint32_t f_start_addr;
};


