#include <dev/nicrtl.h>
#include <sys/confnet.h>
#include "log.h"
#include <time.h>
#include <arpa/inet.h>

#define LOG_MODULE LOG_MAIN_MODULE
#define ETH0_BASE 0xC300
#define ETH0_IRQ 5
#define OK 1
#define NOK 0


void ethernetInit(void);
void showEthernetDetails(void);
