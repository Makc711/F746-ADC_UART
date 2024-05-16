/**
  ******************************************************************************
  * @file           : adc_conv.cpp
  * @author         : Rusanov M.N.
  ******************************************************************************
  */

#include "adc_conv.h"

adc_conv::adc_conv() = default;

adc_conv& adc_conv::get_instance()
{
  static adc_conv instance;
  return instance;
}

void adc_conv::init(ADC_HandleTypeDef& hadc)
{
  f_hadc = &hadc;
  start_adc_conv();
}

// ReSharper disable once CppMemberFunctionMayBeConst
void adc_conv::start_adc_conv()
{
  HAL_ADC_Start_DMA(f_hadc, reinterpret_cast<uint32_t*>(f_adc_data), channels_num);
}

uint16_t adc_conv::get_adc_data(const size_t adc_ch_index) const
{
  if (adc_ch_index < channels_num)
  {
#if USE_MEDIAN_FILTER || USE_AVERAGING
    return f_adc_result_data[adc_ch_index];
#else
    return f_adc_data[adc_ch_index];
#endif
  }

  return 0;
}

uint16_t adc_conv::get_adc_data_not_filtered(const size_t adc_ch_index) const
{
  return f_adc_data[adc_ch_index];
}

#if USE_MEDIAN_FILTER || USE_AVERAGING
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
  adc_conv::get_instance().adc_conv_cplt_callback(hadc);
}

void adc_conv::adc_conv_cplt_callback(ADC_HandleTypeDef* hadc)
{
  if (hadc == f_hadc)
  {
    HAL_ADC_Stop_DMA(hadc);

#if USE_AVERAGING
    for (size_t i = 0; i < channels_num; ++i)
    {
      f_adc_sum_data[i] += f_adc_data[i];
    }

    ++f_adc_measurements_cnt;

    if (f_adc_measurements_cnt == measurements_num)
    {

      for (size_t i = 0; i < channels_num; ++i)
      {
        f_adc_result_data[i] = static_cast<uint16_t>(f_adc_sum_data[i] / measurements_num);
        f_adc_sum_data[i] = 0;
#if USE_MEDIAN_FILTER
        f_adc_result_data[i] = f_filter[i].filter(f_adc_result_data[i]);
#endif
      }

      f_adc_measurements_cnt = 0;
    }
#else
    for (size_t i = 0; i < channels_num; ++i)
    {
      f_adc_result_data[i] = f_filter[i].filter(f_adc_data[i]);
    }
#endif

    start_adc_conv();
  }
}
#endif
