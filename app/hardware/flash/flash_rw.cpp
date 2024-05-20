/**
  ******************************************************************************
  * @file           : flash_rw.cpp
  * @author         : Rusanov M.N.
  ******************************************************************************
  */

#include "flash_rw.h"

void flash_rw::erase(const uint32_t address_start, const uint32_t address_end)
{
  HAL_FLASH_Unlock();

  FLASH_EraseInitTypeDef erase_init_struct;
  flash_erase::init_erase_struct(erase_init_struct, address_start, address_end);

  /* Note: If an erase operation in Flash memory also concerns data in the data or instruction cache,
     you have to make sure that these data are rewritten before they are accessed during code
     execution. If this cannot be done safely, it is recommended to flush the caches by setting the
     DCRST and ICRST bits in the FLASH_CR register. */
  
  if (uint32_t index_of_sector_error = 0; 
      HAL_FLASHEx_Erase(&erase_init_struct, &index_of_sector_error) != HAL_OK)
  {
    /*
      Error occurred while sector erase.
      User can add here some code to deal with this error.
      SECTORError will contain the faulty sector and then to know the code error on this sector,
      user can call function 'HAL_FLASH_GetError()'
    */
    Error_Handler();
  }

  HAL_FLASH_Lock();
}

#if defined(STM32F746xx)
void flash_rw::write_byte(const uint32_t address, const uint8_t byte)
{

  if (const HAL_StatusTypeDef status = HAL_FLASH_Program(FLASH_TYPEPROGRAM_BYTE, address, byte); 
      status != HAL_OK) 
  {
    /* Error occurred while writing data in Flash memory.
       User can add here some code to deal with this error */
    Error_Handler();
  }
}
#endif

uint8_t flash_rw::read_byte(const uint32_t address)
{
  return *reinterpret_cast<__IO uint8_t*>(address);  // NOLINT(performance-no-int-to-ptr)
}

void flash_rw::check_byte(const uint32_t address, const uint8_t byte)
{
  if (read_byte(address) != byte)
  {
    Error_Handler();
  }
}

inline void flash_rw::write_word(const uint32_t address, const uint32_t word)
{
  if (const HAL_StatusTypeDef status = HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, address, word); 
      status != HAL_OK) 
  {
    /* Error occurred while writing data in Flash memory.
       User can add here some code to deal with this error */
    Error_Handler();
  }
}

uint32_t flash_rw::read_word(const uint32_t address)
{
  return *reinterpret_cast<__IO uint32_t*>(address);  // NOLINT(performance-no-int-to-ptr)
}

void flash_rw::check_word(const uint32_t address, const uint32_t word)
{
  if (read_word(address) != word)
  {
    Error_Handler();
  }
}

void flash_rw::write_arr_to_flash(const uint32_t address, const uint8_t* arr, const size_t size)
{
  HAL_FLASH_Unlock();

  for (size_t i = 0; i < size; i += 4)
  {
    write_word(address + i, arr[i]);
    check_word(address + i, arr[i]);
  }

  HAL_FLASH_Lock();
}

void flash_rw::read_arr_from_flash(const uint32_t address, uint8_t* arr, const size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    arr[i] = read_byte(address + i);
  }
}

#if defined(STM32F746xx)
void flash_rw::write_str_to_flash(const uint32_t address, const char* str)
{
  HAL_FLASH_Unlock();

  size_t i = 0;
  do
  {
    write_byte(address + i, str[i]);
    check_byte(address + i, str[i]);
  } while (str[i++] != '\0');

  HAL_FLASH_Lock();
}

size_t flash_rw::read_str_from_flash(const uint32_t address, char* str, const size_t max_length)
{
  size_t length = 0;
  do
  {
    str[length] = static_cast<char>(read_byte(address + length));
  } while ((str[length] != '\0') && (length++ < max_length));
  return length;
}
#endif

