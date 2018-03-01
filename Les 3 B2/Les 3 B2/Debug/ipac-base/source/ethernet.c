#include "ethernet.h"
#include <dev/nicrtl.h>
#include <sys/confnet.h>
#include "log.h"
#include <time.h>
#include <arpa/inet.h>
#include <dev/board.h>
#include <sys/timer.h>

#define LOG_MODULE LOG_MAIN_MODULE
#define ETH0_BASE 0xC300
#define ETH0_IRQ 5
#define OK 1
#define NOK 0

int result = OK;

void ethernetInit(){
    if(NutRegisterDevice(&DEV_ETHER,ETH0_BASE,ETH0_IRQ)){
        LogMsg_P(LOG_ERR,PSTR("Error: >> NutRegisterDevice()"));
        result = NOK;
    }

    static char eth0IfName[9] = "eth0";
    uint8_t mac_addr[6] = {0x00,0x07,0x67,0x40,0x04,0x02};
    if(NutDhcpIfConfig(eth0IfName,NULL,10000)){
        LogMsg_P(LOG_ERR,PSTR("Error: no stored Macaddress"));
        if(NutDhcpIfConfig(eth0IfName,mac_addr,0)){
            LogMsg_P(LOG_ERR,PSTR("Error NutDhcpIfConfig()"));
            result = NOK;
        }
    }
LogMsg_P(LOG_INFO,PSTR("Ethernet Ready to Use"));    
}

void showEthernetDetails(){
    LogMsg_P(LOG_INFO,PSTR("if_name: %s"),confnet.cd_name);
    LogMsg_P(LOG_INFO,PSTR("if_addr: %s"),inet_ntoa(confnet.cdn_ip_addr));
    LogMsg_P(LOG_INFO,PSTR("if_mask: %s"),inet_ntoa(confnet.cdn_ip_mask));
    LogMsg_P(LOG_INFO,PSTR("if_gateway: %s"),inet_ntoa(confnet.cdn_gateway));
}






