/**
  ******************************************************************************
  * @file           : flash_rw.h
  * @author         : Rusanov M.N.
  * @version        : V1.0.0
  * @date           : 17-May-2024
  * @brief          : Header for flash_rw.cpp file.
  *                   This file contains functions for working with flash memory
  *
  ******************************************************************************
  */

#pragma once

#include "main.h"

class flash_rw
{
public:
  enum class sector_addr
  {
    ADDR_FLASH_SECTOR_0 = static_cast<uint32_t>(0x08000000), /* Base address of Sector 0, 32 Kbytes */
    ADDR_FLASH_SECTOR_1 = static_cast<uint32_t>(0x08008000), /* Base address of Sector 1, 32 Kbytes */
    ADDR_FLASH_SECTOR_2 = static_cast<uint32_t>(0x08010000), /* Base address of Sector 2, 32 Kbytes */
    ADDR_FLASH_SECTOR_3 = static_cast<uint32_t>(0x08018000), /* Base address of Sector 3, 32 Kbytes */
    ADDR_FLASH_SECTOR_4 = static_cast<uint32_t>(0x08020000), /* Base address of Sector 4, 128 Kbytes */
    ADDR_FLASH_SECTOR_5 = static_cast<uint32_t>(0x08040000), /* Base address of Sector 5, 256 Kbytes */
    ADDR_FLASH_SECTOR_6 = static_cast<uint32_t>(0x08080000), /* Base address of Sector 6, 256 Kbytes */
    ADDR_FLASH_SECTOR_7 = static_cast<uint32_t>(0x080C0000)  /* Base address of Sector 7, 256 Kbytes */
  };

protected:
  flash_rw() = default;
  static uint32_t erase_sector(uint32_t address_start, uint32_t address_end); // Use before write!
  static void write_byte(uint32_t address, uint8_t byte);
  [[nodiscard]] static uint8_t read_byte(uint32_t address);
  static void check_byte(uint32_t address, uint8_t byte);
  static void write_arr_to_flash(uint32_t address, const uint8_t* arr, size_t size);
  static void read_arr_from_flash(uint32_t address, uint8_t* arr, size_t size);
  static void write_str_to_flash(uint32_t address, const char* str);
  static size_t read_str_from_flash(uint32_t address, char* str, size_t max_length);

private:
  static uint32_t get_sector(uint32_t address);
};


