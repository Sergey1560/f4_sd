#include "main.h"

FRESULT result;
volatile FATFS FATFS_Obj;
volatile FIL file;
unsigned int nWritten;

char file_name[200];

uint8_t data[DATA_SIZE];
uint8_t indata[DATA_SIZE];

int main(void){

	RCC_init();
	memset((uint8_t *)data,0xAA,DATA_SIZE);

	result = f_mount((FATFS *)&FATFS_Obj, "0", 1);
	if(result != FR_OK){
		while(1);
	}

	sprintf(file_name,"test_file.bin");
	result = f_open((FIL*)&file, (char *)file_name, FA_CREATE_ALWAYS | FA_WRITE );
	if(result != FR_OK) {
		while(1);
	}
	
	for(uint32_t i=0; i<320; i++){
		result=f_write((FIL*)&file, (uint8_t *)data, DATA_SIZE, &nWritten);	
		if(result != FR_OK) {
			while(1);
		};
		result=f_sync((FIL*)&file);
		if(result != FR_OK) {
			while(1);
		};
	};
	
	f_close((FIL*)&file);
	
	result = f_open((FIL*)&file, (char *)file_name, FA_READ);
	if(result != FR_OK) {
		while(1);
	}

	for(uint32_t i=0; i<320; i++){
	
		memset((uint8_t *)indata,0x00,DATA_SIZE);
		result=f_read((FIL*)&file, (uint8_t *)indata, DATA_SIZE, &nWritten);	
		
		if(memcmp((uint8_t*)data,(uint8_t *)indata,DATA_SIZE)){
			while(1);
		}

		if(result != FR_OK) {
			while(1);
		};
	};



	while(1){
		memset((uint8_t *)data,0xAA,DATA_SIZE);
	};

}
