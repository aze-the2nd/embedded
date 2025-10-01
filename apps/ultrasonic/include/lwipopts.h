

#ifndef LWIPOPTS_H
#define LWIPOPTS_H


#define NO_SYS                          1     /* <— wichtig: kein RTOS */
#define LWIP_SOCKET                     0
#define LWIP_NETCONN                    0

// protocolls
#define LWIP_IPV4                       1
#define LWIP_IPV6                       0
#define LWIP_ICMP                       1
#define LWIP_DHCP                       1
#define LWIP_DNS                        1
#define LWIP_TCP                        1
#define LWIP_UDP                        1

// usefull extras/callbacks
#define LWIP_NETIF_STATUS_CALLBACK      1
#define LWIP_NETIF_LINK_CALLBACK        1
#define LWIP_NETIF_HOSTNAME             1

// ressources/ conservative defaults
#define MEM_ALIGNMENT                   4
#define PBUF_POOL_SIZE                  16
#define MEMP_NUM_TCP_PCB                5
#define TCP_MSS                         1460
#define TCP_WND                         (4 * TCP_MSS)
#define TCP_SND_BUF                     (4 * TCP_MSS)

// performance -> in development 1
#define LWIP_CHECKSUM_CTRL_PER_NETIF   1

// Debug (optional) ´
#define LWIP_STATS                      0

// Debug 
#define LWIP_DEBUG                     0

// MIB2 (interface-name etc.) optional 
#define MIB2_STATS                     0


#endif /* LWIPOPTS_H */
