/**
  ******************************************************************************
  * @file           : adc_conv.h
  * @author         : Rusanov M.N.
  * @version        : V1.0.0
  * @date           : 16-May-2024
  * @brief          : Header for adc_conv.cpp file.
  *                   This file contains functions for working with adc.
  *
  ******************************************************************************
  */

#pragma once

#include "main.h"

#define USE_MEDIAN_FILTER 1
#define USE_AVERAGING     1

#if USE_MEDIAN_FILTER
#include "median_filter_ekstrom.h"
#endif

class adc_conv
{
public:
  static constexpr size_t channels_num = 2;

  [[nodiscard]] static adc_conv& get_instance();
  void init(ADC_HandleTypeDef& hadc);
  [[nodiscard]] uint16_t get_adc_data(size_t adc_ch_index) const;
  [[nodiscard]] uint16_t get_adc_data_not_filtered(size_t adc_ch_index) const;

#if USE_MEDIAN_FILTER || USE_AVERAGING
  void adc_conv_cplt_callback(ADC_HandleTypeDef* hadc);
#endif

private:
  explicit adc_conv();
  void start_adc_conv();

private:
  ADC_HandleTypeDef* f_hadc = nullptr;
  uint16_t f_adc_data[channels_num] = { 0 };

#if USE_MEDIAN_FILTER
  median_filter_ekstrom f_filter[channels_num];
#endif

#if USE_AVERAGING
  static constexpr size_t measurements_num = 40;
  uint32_t f_adc_sum_data[channels_num] = { 0 };
  size_t f_adc_measurements_cnt = 0;
#endif

#if USE_MEDIAN_FILTER || USE_AVERAGING
  uint16_t f_adc_result_data[channels_num] = { 0 };
#endif
};