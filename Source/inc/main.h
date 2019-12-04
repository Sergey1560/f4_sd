#include "stm32f4xx.h"
#include <stdlib.h>
#include "stdio.h"
#include "strings.h"
#include "rcc.h"
#include "sdio.h"
#include "ff.h"
#include "log.h"


#define DATA_SIZE 70*1024
#define WRITE_COUNT 255


