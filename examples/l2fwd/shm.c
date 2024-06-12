#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <sys/types.h>       // for ftruncate
#include <unistd.h>
#include "shm.h"

shm_table_t* init_shm(uint32_t init_mode)
{
	uint32_t size = sizeof(shm_table_t);
	int shm_fd = shm_open("l2fwd", init_mode, 0777);
  ftruncate(shm_fd, size);
  shm_table_t* shm_table_ptr = (shm_table_t*)mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
  if (shm_table_ptr->magic != 0x01020304) {
    memset(shm_table_ptr, 0, size);
    shm_table_ptr->magic = 0x01020304;
  }
	return shm_table_ptr;
}