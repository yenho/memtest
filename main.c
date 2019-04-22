#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "memtest.h"

#define DEBUG_STOP	1
int memtest(volatile ulv *addr, ulv size) {
    ulv *fail_addr;

    printf("test size : 0x%lx\n\n", size);
    if (memTestDataBus(addr)) {
        printf("     * Data bus FAIL\r\n");
#ifdef DEBUG_STOP
        while (1) {
        }
#endif//DEBUG_STOP
        return 1;
    }
    printf("     * Data bus OK\r\n");

    fail_addr = memTestAddressBus(addr, size);
    if (fail_addr) {
        printf("     * Address bus (0x%ln) FAIL\r\n", fail_addr);
#ifdef DEBUG_STOP
        while (1) {
        }
#endif//DEBUG_STOP
        return 2;
    }
    printf("     * Address bus OK\r\n");

    fail_addr = memTestDevice(addr, size);
    if (fail_addr) {
        printf("     * Device (0x%ln) FAIL\r\n", fail_addr);
#ifdef DEBUG_STOP
        while (1) {
        }
#endif//DEBUG_STOP
        return 3;
    }
    printf("\n");
    printf("     * Device OK\r\n");

    return 0;
}
void main()
{
  int ret;
  int *dynArr;

  // 指定空間大小
  int arrLen1 = 1024;
  int arrLen2 = (512*128);

  printf("\nstart mem test .");
  dynArr = malloc( arrLen1 * arrLen2 * sizeof(int) );
  printf(".");

  memset(dynArr, 0, arrLen1 * arrLen2 * sizeof(int));
  printf(".\n");

  if( dynArr == NULL ) {
    fprintf(stderr, "Error: unable to allocate required memory\n");
    return;
  }

  int i, j;
  for (i = 0; i < arrLen1; ++i) {
    for (j = 0; j < arrLen2; ++j) {
      int index = i * arrLen2 + j;
      dynArr[index] = index;
      // printf("%d ", dynArr[index]);
    }
  }
  printf("\n");
  ret = memtest((volatile long unsigned int *)dynArr, (ulv) (arrLen1 * arrLen2 * sizeof(int)));

  if (ret == 0)
  		printf("\n --> memtest PASSING!\n");
  else
  		printf("\n --> memtest FAILED!\n");

  // 釋放記憶體空間
  free(dynArr);
	
}
