#pragma once
/* NO_SYS: No RTOS */
#define NO_SYS                         1
#define SYS_LIGHTWEIGHT_PROT           0

/* Features/Protocolls */
#define LWIP_IPV4                      1
#define LWIP_IPV6                      0
#define LWIP_DHCP                      1
#define LWIP_DNS                       1
#define LWIP_ICMP                      1
#define LWIP_TCP                       1
#define LWIP_UDP                       1
#define TCP_MSS                        1460
#define TCP_SND_BUF                    (8 * TCP_MSS)
#define TCP_WND                        (8 * TCP_MSS)

/* Sockets/Netconn off, wenn NO_SYS=1 */
#define LWIP_SOCKET                    0
#define LWIP_NETCONN                   0

/* Memory */
#define MEM_ALIGNMENT                  4
#define PBUF_POOL_SIZE                 16
#define MEMP_NUM_TCP_PCB               5

/* Optional Debug */
// #define LWIP_DEBUG                   1
// #define DHCP_DEBUG                   LWIP_DBG_ON
