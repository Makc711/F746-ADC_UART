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
#if defined(STM32L152xC)
  enum class sector_addr
  {
    ADDR_FLASH_PAGE_0    = static_cast<uint32_t>(0x08000000), /* Base @ of Page 0, 256 bytes */
    ADDR_FLASH_PAGE_1    = static_cast<uint32_t>(0x08000100), /* Base @ of Page 1, 256 bytes */
    ADDR_FLASH_PAGE_2    = static_cast<uint32_t>(0x08000200), /* Base @ of Page 2, 256 bytes */
    ADDR_FLASH_PAGE_3    = static_cast<uint32_t>(0x08000300), /* Base @ of Page 3, 256 bytes */
    ADDR_FLASH_PAGE_4    = static_cast<uint32_t>(0x08000400), /* Base @ of Page 4, 256 bytes */
    ADDR_FLASH_PAGE_5    = static_cast<uint32_t>(0x08000500), /* Base @ of Page 5, 256 bytes */
    ADDR_FLASH_PAGE_6    = static_cast<uint32_t>(0x08000600), /* Base @ of Page 6, 256 bytes */
    ADDR_FLASH_PAGE_7    = static_cast<uint32_t>(0x08000700), /* Base @ of Page 7, 256 bytes */
    ADDR_FLASH_PAGE_8    = static_cast<uint32_t>(0x08000800), /* Base @ of Page 8, 256 bytes */
    ADDR_FLASH_PAGE_9    = static_cast<uint32_t>(0x08000900), /* Base @ of Page 9, 256 bytes */
    ADDR_FLASH_PAGE_10   = static_cast<uint32_t>(0x08000A00), /* Base @ of Page 10, 256 bytes */
    ADDR_FLASH_PAGE_11   = static_cast<uint32_t>(0x08000B00), /* Base @ of Page 11, 256 bytes */
    ADDR_FLASH_PAGE_12   = static_cast<uint32_t>(0x08000C00), /* Base @ of Page 12, 256 bytes */
    ADDR_FLASH_PAGE_13   = static_cast<uint32_t>(0x08000D00), /* Base @ of Page 13, 256 bytes */
    ADDR_FLASH_PAGE_14   = static_cast<uint32_t>(0x08000E00), /* Base @ of Page 14, 256 bytes */
    ADDR_FLASH_PAGE_15   = static_cast<uint32_t>(0x08000F00), /* Base @ of Page 15, 256 bytes */
    ADDR_FLASH_PAGE_16   = static_cast<uint32_t>(0x08001000), /* Base @ of Page 16, 256 bytes */
    ADDR_FLASH_PAGE_17   = static_cast<uint32_t>(0x08001100), /* Base @ of Page 17, 256 bytes */
    ADDR_FLASH_PAGE_18   = static_cast<uint32_t>(0x08001200), /* Base @ of Page 18, 256 bytes */
    ADDR_FLASH_PAGE_19   = static_cast<uint32_t>(0x08001300), /* Base @ of Page 19, 256 bytes */
    ADDR_FLASH_PAGE_20   = static_cast<uint32_t>(0x08001400), /* Base @ of Page 20, 256 bytes */
    ADDR_FLASH_PAGE_21   = static_cast<uint32_t>(0x08001500), /* Base @ of Page 21, 256 bytes */
    ADDR_FLASH_PAGE_22   = static_cast<uint32_t>(0x08001600), /* Base @ of Page 22, 256 bytes */
    ADDR_FLASH_PAGE_23   = static_cast<uint32_t>(0x08001700), /* Base @ of Page 23, 256 bytes */
    ADDR_FLASH_PAGE_24   = static_cast<uint32_t>(0x08001800), /* Base @ of Page 24, 256 bytes */
    ADDR_FLASH_PAGE_25   = static_cast<uint32_t>(0x08001900), /* Base @ of Page 25, 256 bytes */
    ADDR_FLASH_PAGE_26   = static_cast<uint32_t>(0x08001A00), /* Base @ of Page 26, 256 bytes */
    ADDR_FLASH_PAGE_27   = static_cast<uint32_t>(0x08001B00), /* Base @ of Page 27, 256 bytes */
    ADDR_FLASH_PAGE_28   = static_cast<uint32_t>(0x08001C00), /* Base @ of Page 28, 256 bytes */
    ADDR_FLASH_PAGE_29   = static_cast<uint32_t>(0x08001D00), /* Base @ of Page 29, 256 bytes */
    ADDR_FLASH_PAGE_30   = static_cast<uint32_t>(0x08001E00), /* Base @ of Page 30, 256 bytes */
    ADDR_FLASH_PAGE_31   = static_cast<uint32_t>(0x08001F00), /* Base @ of Page 31, 256 bytes */
    ADDR_FLASH_PAGE_32   = static_cast<uint32_t>(0x08002000), /* Base @ of Page 32, 256 bytes */
    ADDR_FLASH_PAGE_33   = static_cast<uint32_t>(0x08002100), /* Base @ of Page 33, 256 bytes */
    ADDR_FLASH_PAGE_34   = static_cast<uint32_t>(0x08002200), /* Base @ of Page 34, 256 bytes */
    ADDR_FLASH_PAGE_35   = static_cast<uint32_t>(0x08002300), /* Base @ of Page 35, 256 bytes */
    ADDR_FLASH_PAGE_36   = static_cast<uint32_t>(0x08002400), /* Base @ of Page 36, 256 bytes */
    ADDR_FLASH_PAGE_37   = static_cast<uint32_t>(0x08002500), /* Base @ of Page 37, 256 bytes */
    ADDR_FLASH_PAGE_38   = static_cast<uint32_t>(0x08002600), /* Base @ of Page 38, 256 bytes */
    ADDR_FLASH_PAGE_39   = static_cast<uint32_t>(0x08002700), /* Base @ of Page 39, 256 bytes */
    ADDR_FLASH_PAGE_40   = static_cast<uint32_t>(0x08002800), /* Base @ of Page 40, 256 bytes */
    ADDR_FLASH_PAGE_41   = static_cast<uint32_t>(0x08002900), /* Base @ of Page 41, 256 bytes */
    ADDR_FLASH_PAGE_42   = static_cast<uint32_t>(0x08002A00), /* Base @ of Page 42, 256 bytes */
    ADDR_FLASH_PAGE_43   = static_cast<uint32_t>(0x08002B00), /* Base @ of Page 43, 256 bytes */
    ADDR_FLASH_PAGE_44   = static_cast<uint32_t>(0x08002C00), /* Base @ of Page 44, 256 bytes */
    ADDR_FLASH_PAGE_45   = static_cast<uint32_t>(0x08002D00), /* Base @ of Page 45, 256 bytes */
    ADDR_FLASH_PAGE_46   = static_cast<uint32_t>(0x08002E00), /* Base @ of Page 46, 256 bytes */
    ADDR_FLASH_PAGE_47   = static_cast<uint32_t>(0x08002F00), /* Base @ of Page 47, 256 bytes */
    ADDR_FLASH_PAGE_48   = static_cast<uint32_t>(0x08003000), /* Base @ of Page 48, 256 bytes */
    ADDR_FLASH_PAGE_49   = static_cast<uint32_t>(0x08003100), /* Base @ of Page 49, 256 bytes */
    ADDR_FLASH_PAGE_50   = static_cast<uint32_t>(0x08003200), /* Base @ of Page 50, 256 bytes */
    ADDR_FLASH_PAGE_51   = static_cast<uint32_t>(0x08003300), /* Base @ of Page 51, 256 bytes */
    ADDR_FLASH_PAGE_52   = static_cast<uint32_t>(0x08003400), /* Base @ of Page 52, 256 bytes */
    ADDR_FLASH_PAGE_53   = static_cast<uint32_t>(0x08003500), /* Base @ of Page 53, 256 bytes */
    ADDR_FLASH_PAGE_54   = static_cast<uint32_t>(0x08003600), /* Base @ of Page 54, 256 bytes */
    ADDR_FLASH_PAGE_55   = static_cast<uint32_t>(0x08003700), /* Base @ of Page 55, 256 bytes */
    ADDR_FLASH_PAGE_56   = static_cast<uint32_t>(0x08003800), /* Base @ of Page 56, 256 bytes */
    ADDR_FLASH_PAGE_57   = static_cast<uint32_t>(0x08003900), /* Base @ of Page 57, 256 bytes */
    ADDR_FLASH_PAGE_58   = static_cast<uint32_t>(0x08003A00), /* Base @ of Page 58, 256 bytes */
    ADDR_FLASH_PAGE_59   = static_cast<uint32_t>(0x08003B00), /* Base @ of Page 59, 256 bytes */
    ADDR_FLASH_PAGE_60   = static_cast<uint32_t>(0x08003C00), /* Base @ of Page 60, 256 bytes */
    ADDR_FLASH_PAGE_61   = static_cast<uint32_t>(0x08003D00), /* Base @ of Page 61, 256 bytes */
    ADDR_FLASH_PAGE_62   = static_cast<uint32_t>(0x08003E00), /* Base @ of Page 62, 256 bytes */
    ADDR_FLASH_PAGE_63   = static_cast<uint32_t>(0x08003F00), /* Base @ of Page 63, 256 bytes */
    ADDR_FLASH_PAGE_64   = static_cast<uint32_t>(0x08004000), /* Base @ of Page 64, 256 bytes */
    ADDR_FLASH_PAGE_65   = static_cast<uint32_t>(0x08004100), /* Base @ of Page 65, 256 bytes */
    ADDR_FLASH_PAGE_66   = static_cast<uint32_t>(0x08004200), /* Base @ of Page 66, 256 bytes */
    ADDR_FLASH_PAGE_67   = static_cast<uint32_t>(0x08004300), /* Base @ of Page 67, 256 bytes */
    ADDR_FLASH_PAGE_68   = static_cast<uint32_t>(0x08004400), /* Base @ of Page 68, 256 bytes */
    ADDR_FLASH_PAGE_69   = static_cast<uint32_t>(0x08004500), /* Base @ of Page 69, 256 bytes */
    ADDR_FLASH_PAGE_70   = static_cast<uint32_t>(0x08004600), /* Base @ of Page 70, 256 bytes */
    ADDR_FLASH_PAGE_71   = static_cast<uint32_t>(0x08004700), /* Base @ of Page 71, 256 bytes */
    ADDR_FLASH_PAGE_72   = static_cast<uint32_t>(0x08004800), /* Base @ of Page 72, 256 bytes */
    ADDR_FLASH_PAGE_73   = static_cast<uint32_t>(0x08004900), /* Base @ of Page 73, 256 bytes */
    ADDR_FLASH_PAGE_74   = static_cast<uint32_t>(0x08004A00), /* Base @ of Page 74, 256 bytes */
    ADDR_FLASH_PAGE_75   = static_cast<uint32_t>(0x08004B00), /* Base @ of Page 75, 256 bytes */
    ADDR_FLASH_PAGE_76   = static_cast<uint32_t>(0x08004C00), /* Base @ of Page 76, 256 bytes */
    ADDR_FLASH_PAGE_77   = static_cast<uint32_t>(0x08004D00), /* Base @ of Page 77, 256 bytes */
    ADDR_FLASH_PAGE_78   = static_cast<uint32_t>(0x08004E00), /* Base @ of Page 78, 256 bytes */
    ADDR_FLASH_PAGE_79   = static_cast<uint32_t>(0x08004F00), /* Base @ of Page 79, 256 bytes */
    ADDR_FLASH_PAGE_80   = static_cast<uint32_t>(0x08005000), /* Base @ of Page 80, 256 bytes */
    ADDR_FLASH_PAGE_81   = static_cast<uint32_t>(0x08005100), /* Base @ of Page 81, 256 bytes */
    ADDR_FLASH_PAGE_82   = static_cast<uint32_t>(0x08005200), /* Base @ of Page 82, 256 bytes */
    ADDR_FLASH_PAGE_83   = static_cast<uint32_t>(0x08005300), /* Base @ of Page 83, 256 bytes */
    ADDR_FLASH_PAGE_84   = static_cast<uint32_t>(0x08005400), /* Base @ of Page 84, 256 bytes */
    ADDR_FLASH_PAGE_85   = static_cast<uint32_t>(0x08005500), /* Base @ of Page 85, 256 bytes */
    ADDR_FLASH_PAGE_86   = static_cast<uint32_t>(0x08005600), /* Base @ of Page 86, 256 bytes */
    ADDR_FLASH_PAGE_87   = static_cast<uint32_t>(0x08005700), /* Base @ of Page 87, 256 bytes */
    ADDR_FLASH_PAGE_88   = static_cast<uint32_t>(0x08005800), /* Base @ of Page 88, 256 bytes */
    ADDR_FLASH_PAGE_89   = static_cast<uint32_t>(0x08005900), /* Base @ of Page 89, 256 bytes */
    ADDR_FLASH_PAGE_90   = static_cast<uint32_t>(0x08005A00), /* Base @ of Page 90, 256 bytes */
    ADDR_FLASH_PAGE_91   = static_cast<uint32_t>(0x08005B00), /* Base @ of Page 91, 256 bytes */
    ADDR_FLASH_PAGE_92   = static_cast<uint32_t>(0x08005C00), /* Base @ of Page 92, 256 bytes */
    ADDR_FLASH_PAGE_93   = static_cast<uint32_t>(0x08005D00), /* Base @ of Page 93, 256 bytes */
    ADDR_FLASH_PAGE_94   = static_cast<uint32_t>(0x08005E00), /* Base @ of Page 94, 256 bytes */
    ADDR_FLASH_PAGE_95   = static_cast<uint32_t>(0x08005F00), /* Base @ of Page 95, 256 bytes */
    ADDR_FLASH_PAGE_96   = static_cast<uint32_t>(0x08006000), /* Base @ of Page 96, 256 bytes */
    ADDR_FLASH_PAGE_97   = static_cast<uint32_t>(0x08006100), /* Base @ of Page 97, 256 bytes */
    ADDR_FLASH_PAGE_98   = static_cast<uint32_t>(0x08006200), /* Base @ of Page 98, 256 bytes */
    ADDR_FLASH_PAGE_99   = static_cast<uint32_t>(0x08006300), /* Base @ of Page 99, 256 bytes */
    ADDR_FLASH_PAGE_100  = static_cast<uint32_t>(0x08006400), /* Base @ of Page 100, 256 bytes */
    ADDR_FLASH_PAGE_101  = static_cast<uint32_t>(0x08006500), /* Base @ of Page 101, 256 bytes */
    ADDR_FLASH_PAGE_102  = static_cast<uint32_t>(0x08006600), /* Base @ of Page 102, 256 bytes */
    ADDR_FLASH_PAGE_103  = static_cast<uint32_t>(0x08006700), /* Base @ of Page 103, 256 bytes */
    ADDR_FLASH_PAGE_104  = static_cast<uint32_t>(0x08006800), /* Base @ of Page 104, 256 bytes */
    ADDR_FLASH_PAGE_105  = static_cast<uint32_t>(0x08006900), /* Base @ of Page 105, 256 bytes */
    ADDR_FLASH_PAGE_106  = static_cast<uint32_t>(0x08006A00), /* Base @ of Page 106, 256 bytes */
    ADDR_FLASH_PAGE_107  = static_cast<uint32_t>(0x08006B00), /* Base @ of Page 107, 256 bytes */
    ADDR_FLASH_PAGE_108  = static_cast<uint32_t>(0x08006C00), /* Base @ of Page 108, 256 bytes */
    ADDR_FLASH_PAGE_109  = static_cast<uint32_t>(0x08006D00), /* Base @ of Page 109, 256 bytes */
    ADDR_FLASH_PAGE_110  = static_cast<uint32_t>(0x08006E00), /* Base @ of Page 110, 256 bytes */
    ADDR_FLASH_PAGE_111  = static_cast<uint32_t>(0x08006F00), /* Base @ of Page 111, 256 bytes */
    ADDR_FLASH_PAGE_112  = static_cast<uint32_t>(0x08007000), /* Base @ of Page 112, 256 bytes */
    ADDR_FLASH_PAGE_113  = static_cast<uint32_t>(0x08007100), /* Base @ of Page 113, 256 bytes */
    ADDR_FLASH_PAGE_114  = static_cast<uint32_t>(0x08007200), /* Base @ of Page 114, 256 bytes */
    ADDR_FLASH_PAGE_115  = static_cast<uint32_t>(0x08007300), /* Base @ of Page 115, 256 bytes */
    ADDR_FLASH_PAGE_116  = static_cast<uint32_t>(0x08007400), /* Base @ of Page 116, 256 bytes */
    ADDR_FLASH_PAGE_117  = static_cast<uint32_t>(0x08007500), /* Base @ of Page 117, 256 bytes */
    ADDR_FLASH_PAGE_118  = static_cast<uint32_t>(0x08007600), /* Base @ of Page 118, 256 bytes */
    ADDR_FLASH_PAGE_119  = static_cast<uint32_t>(0x08007700), /* Base @ of Page 119, 256 bytes */
    ADDR_FLASH_PAGE_120  = static_cast<uint32_t>(0x08007800), /* Base @ of Page 120, 256 bytes */
    ADDR_FLASH_PAGE_121  = static_cast<uint32_t>(0x08007900), /* Base @ of Page 121, 256 bytes */
    ADDR_FLASH_PAGE_122  = static_cast<uint32_t>(0x08007A00), /* Base @ of Page 122, 256 bytes */
    ADDR_FLASH_PAGE_123  = static_cast<uint32_t>(0x08007B00), /* Base @ of Page 123, 256 bytes */
    ADDR_FLASH_PAGE_124  = static_cast<uint32_t>(0x08007C00), /* Base @ of Page 124, 256 bytes */
    ADDR_FLASH_PAGE_125  = static_cast<uint32_t>(0x08007D00), /* Base @ of Page 125, 256 bytes */
    ADDR_FLASH_PAGE_126  = static_cast<uint32_t>(0x08007E00), /* Base @ of Page 126, 256 bytes */
    ADDR_FLASH_PAGE_127  = static_cast<uint32_t>(0x08007F00)  /* Base @ of Page 127, 256 bytes */
  };
#elif defined(STM32F746xx)
    enum class sector_addr
  {
    ADDR_FLASH_SECTOR_0 = static_cast<uint32_t>(0x08000000),
    /* Base address of Sector 0, 32 Kbytes */
    ADDR_FLASH_SECTOR_1 = static_cast<uint32_t>(0x08008000),
    /* Base address of Sector 1, 32 Kbytes */
    ADDR_FLASH_SECTOR_2 = static_cast<uint32_t>(0x08010000),
    /* Base address of Sector 2, 32 Kbytes */
    ADDR_FLASH_SECTOR_3 = static_cast<uint32_t>(0x08018000),
    /* Base address of Sector 3, 32 Kbytes */
    ADDR_FLASH_SECTOR_4 = static_cast<uint32_t>(0x08020000),
    /* Base address of Sector 4, 128 Kbytes */
    ADDR_FLASH_SECTOR_5 = static_cast<uint32_t>(0x08040000),
    /* Base address of Sector 5, 256 Kbytes */
    ADDR_FLASH_SECTOR_6 = static_cast<uint32_t>(0x08080000),
    /* Base address of Sector 6, 256 Kbytes */
    ADDR_FLASH_SECTOR_7 = static_cast<uint32_t>(0x080C0000)  /* Base address of Sector 7, 256 Kbytes */
  };
#endif
  

protected:
  flash_rw() = default;
  static uint32_t erase_sector(uint32_t address_start, uint32_t address_end); // Use before write!
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

private:
  static uint32_t get_sector(uint32_t address);
#endif
};


