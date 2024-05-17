/**
  ******************************************************************************
  * @file           : flash_rw.cpp
  * @author         : Rusanov M.N.
  ******************************************************************************
  */

#include "flash_rw.h"

/**
  * @brief  Gets the sector of a given address
  * @param  address - destination address
  * @retval The sector of a given address
  */
uint32_t flash_rw::get_sector(const uint32_t address)
{
  uint32_t sector;

  if ((address < static_cast<uint32_t>(sector_addr::ADDR_FLASH_SECTOR_1)) && (address >= static_cast<uint32_t>(sector_addr::ADDR_FLASH_SECTOR_0)))
  {
    sector = FLASH_SECTOR_0;
  }
  else if ((address < static_cast<uint32_t>(sector_addr::ADDR_FLASH_SECTOR_2)) && (address >= static_cast<uint32_t>(sector_addr::ADDR_FLASH_SECTOR_1)))
  {
    sector = FLASH_SECTOR_1;
  }
#if (FLASH_SECTOR_TOTAL > 2)
  else if ((address < static_cast<uint32_t>(sector_addr::ADDR_FLASH_SECTOR_3)) && (address >= static_cast<uint32_t>(sector_addr::ADDR_FLASH_SECTOR_2)))
  {
    sector = FLASH_SECTOR_2;
  }
  else if ((address < static_cast<uint32_t>(sector_addr::ADDR_FLASH_SECTOR_4)) && (address >= static_cast<uint32_t>(sector_addr::ADDR_FLASH_SECTOR_3)))
  {
    sector = FLASH_SECTOR_3;
  }
#if (FLASH_SECTOR_TOTAL > 4)
  else if ((address < static_cast<uint32_t>(sector_addr::ADDR_FLASH_SECTOR_5)) && (address >= static_cast<uint32_t>(sector_addr::ADDR_FLASH_SECTOR_4)))
  {
    sector = FLASH_SECTOR_4;
  }
  else if ((address < static_cast<uint32_t>(sector_addr::ADDR_FLASH_SECTOR_6)) && (address >= static_cast<uint32_t>(sector_addr::ADDR_FLASH_SECTOR_5)))
  {
    sector = FLASH_SECTOR_5;
  }
  else if ((address < static_cast<uint32_t>(sector_addr::ADDR_FLASH_SECTOR_7)) && (address >= static_cast<uint32_t>(sector_addr::ADDR_FLASH_SECTOR_6)))
  {
    sector = FLASH_SECTOR_6;
  }
  else /* (address < FLASH_END_ADDR) && (address >= ADDR_FLASH_SECTOR_7) */
  {
    sector = FLASH_SECTOR_7;
  }
#endif
#endif
  return sector;
}

uint32_t flash_rw::erase_sector(const uint32_t address_start, const uint32_t address_end)
{
  HAL_FLASH_Unlock();

  const uint32_t first_sector = get_sector(address_start);
  const uint32_t nb_of_sectors = get_sector(address_end) - first_sector + 1;

  FLASH_EraseInitTypeDef erase_init_struct;
  erase_init_struct.TypeErase     = FLASH_TYPEERASE_SECTORS;
  erase_init_struct.VoltageRange  = FLASH_VOLTAGE_RANGE_3;
  erase_init_struct.Sector        = first_sector;
  erase_init_struct.NbSectors     = nb_of_sectors;

  /* Note: If an erase operation in Flash memory also concerns data in the data or instruction cache,
     you have to make sure that these data are rewritten before they are accessed during code
     execution. If this cannot be done safely, it is recommended to flush the caches by setting the
     DCRST and ICRST bits in the FLASH_CR register. */
  uint32_t index_of_sector_error = 0;
  if (HAL_FLASHEx_Erase(&erase_init_struct, &index_of_sector_error) != HAL_OK)
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

  return index_of_sector_error;
}

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

uint8_t flash_rw::read_byte(const uint32_t address)
{
  return *reinterpret_cast<__IO uint8_t*>(address);
}

void flash_rw::check_byte(const uint32_t address, const uint8_t byte)
{
  if (read_byte(address) != byte)
  {
    Error_Handler();
  }
}

void flash_rw::write_arr_to_flash(const uint32_t address, const uint8_t* arr, const size_t size)
{
  HAL_FLASH_Unlock();

  for (size_t i = 0; i < size; ++i)
  {
    write_byte(address + i, arr[i]);
    check_byte(address + i, arr[i]);
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


