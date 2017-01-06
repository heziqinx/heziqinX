#include <common.h>
#include <errno.h>
#include <asm/io.h>
#include <serial.h>


#define GPIOA_OUTEN (0x0000000)
#define GPIOA_OUTDAT (0x000000)

#define TEST_LED_GPIO (19)


#ifdef CONFIG_SPL_BUILD

static void pll_delay(unsigned long loops)
{
        __asm__ volatile ("1:\n"
          "subs %0, %1, #1\n"
          "bne 1b" : "=r" (loops) : "0" (loops));
}


void board_init_f(ulong bootflag)
{
	writel(0x5555, 0x56000050);
	writel(0xff, 0x56000058);
	while(1) {
		writel(0xff, 0x56000054);
		pll_delay(4000000);
		writel(0x00, 0x56000054);
		pll_delay(4000000);
	}
}

#endif
