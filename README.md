# F746-ADC_UART


**Тестовый стенд:** плата STM32F746G-DISCOVERY.

**Задача:** Написать программу для микроконтроллера STM32F746NG. 

Программа должна получать данные с АЦП микроконтроллера с портов PF8 и PF9. 

Далее, эти данные должны быть нормализованы с использованием задаваемых переменных, хранящихся во встроенной FLASH (**у STM32F746NG нет EEPROM**): нулевая точка и точка максимума. Предполагаем, что диапазон калибровки для обоих каналов одинаковый и составляет от 0,00 до 100,00%.

Далее, нормализованные данные микроконтроллер выдаёт в последовательный порт в формате «PF8: xxx.xx%; PF9: yyy.yy%[CR]». По желанию, вместо выдачи данных в последовательный порт, можно выдать их на LCD-дисплей платы в сокращённом виде.

**Тулчейн:** на усмотрение исполнителя, желательно использование свободного ПО.
