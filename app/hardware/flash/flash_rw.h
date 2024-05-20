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
#if defined(STM32F746xx)
#include "flash_erase_f7.h"
using flash_erase = flash_erase_f7;
#elif defined(STM32L152xC)
#include "flash_erase_l1.h"
using flash_erase = flash_erase_l1;
#endif

class flash_rw
{
protected:
  flash_rw() = default;
  static void erase(uint32_t address_start, uint32_t address_end); // Use before write!
#if defined(STM32F746xx)
  static void write_byte(uint32_t address, uint8_t byte);
#endif
  [[nodiscard]] static uint8_t read_byte(uint32_t address);
  static void check_byte(uint32_t address, uint8_t byte);
  static void write_word(uint32_t address, uint32_t word);
  [[nodiscard]] static uint32_t read_word(uint32_t address);
  static void check_word(uint32_t address, uint32_t word);
  static void write_arr_to_flash(uint32_t address, const uint8_t* arr, size_t size);
  static void read_arr_from_flash(uint32_t address, uint8_t* arr, size_t size);

#if defined(STM32F746xx)
  static void write_str_to_flash(uint32_t address, const char* str);
  static size_t read_str_from_flash(uint32_t address, char* str, size_t max_length);
#endif
};


