#ifndef _SHM_H_
#define _SHM_H_
#include <stdint.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */

#define SHM_INIT O_CREAT | O_RDWR
#define SHM_ATTACH O_RDWR

struct local_port_info {
	uint32_t ip_addr;
};

typedef struct shm_table {
	struct local_port_info port_info[2];
	uint32_t magic;
} shm_table_t;


shm_table_t* init_shm(uint32_t init_mode);

#endif 