# STM32F429, SDIO 4-bit

Пример работы с SD картой через SDIO 4-bit интерфейс и бибилиотеку FATFs.
Чтение и запись происходят через DMA.
Результат теста:
NFO RCC_init:32   [591]:SystemCoreClock 180000000
INFO main:59   [7389]:Write to file done in 18278400 bytes in 6773 ms, speed 2698 Kbyte/sec
INFO main:96   [10817]:Read from file done in 18278400 bytes in 3426 ms, speed 5335 Kbyte/sec
