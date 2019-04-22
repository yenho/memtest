#ifndef _memtest_h
#define _memtest_h

/*
 * Define DDR_OK pointer value.
 */
#ifndef DDR_OK 
#define DDR_OK  (void *) 0
#endif

/*
 * Set the data bus width.
 */
typedef unsigned long volatile ulv;

/*
 * Function prototypes.
 */
ulv   memTestDataBus(ulv* address);
ulv*  memTestAddressBus(ulv* baseAddress, ulv nBytes);
ulv*  memTestDevice(ulv* baseAddress, ulv nBytes);


/*
 * Set the data bus width.
 */
typedef uint32_t datum;

/*
 * Function prototypes.
 */
datum   sd_memTestDataBus(volatile datum * address);
datum * sd_memTestAddressBus(volatile datum * baseAddress, unsigned long nBytes);
datum * sd_memTestDevice(volatile datum * baseAddress, unsigned long nBytes);

#endif /* _memtest_h */
