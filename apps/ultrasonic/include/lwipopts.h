/* Grundlegend */
#define NO_SYS                          1     /* <— wichtig: kein RTOS */
#define LWIP_SOCKET                     0
#define LWIP_NETCONN                    0

/* Protokolle */
#define LWIP_IPV4                       1
#define LWIP_IPV6                       0
#define LWIP_ICMP                       1
#define LWIP_DHCP                       1
#define LWIP_DNS                        1
#define LWIP_TCP                        1
#define LWIP_UDP                        1

/* Nützliche Callbacks/Extras */
#define LWIP_NETIF_STATUS_CALLBACK      1
#define LWIP_NETIF_LINK_CALLBACK        1
#define LWIP_NETIF_HOSTNAME             1

/* Ressourcen (konservative Defaults) */
#define MEM_ALIGNMENT                   4
#define PBUF_POOL_SIZE                  16
#define MEMP_NUM_TCP_PCB                5
#define TCP_MSS                         1460
#define TCP_WND                         (4 * TCP_MSS)
#define TCP_SND_BUF                     (4 * TCP_MSS)

/* Debug (optional) */
#define LWIP_STATS                      0
