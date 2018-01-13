#ifndef ARPSTT_H_INCLUDED
#define ARPSTT_H_INCLUDED

//14字节以太网首部
struct EthernetHeader
{
    u_char DestMAC[6];    //目的MAC地址 6字节
    u_char SourMAC[6];   //源MAC地址 6字节
    u_short EthType;         //上一层协议类型，如0x0800代表上一层是IP协议，0x0806为arp  2字节
};

//28字节ARP帧结构
struct ArpHeader
{
    unsigned short hdType;   //硬件类型
    unsigned short proType;   //协议类型
    unsigned char hdSize;   //硬件地址长度
    unsigned char proSize;   //协议地址长度
    unsigned short op;   //操作类型，ARP请求（1），ARP应答（2），RARP请求（3），RARP应答（4）。
    u_char smac[6];   //源MAC地址
    u_char sip[4];   //源IP地址
    u_char dmac[6];   //目的MAC地址
    u_char dip[4];   //目的IP地址
};

//定义整个arp报文包，总长度42字节
struct ArpPacket {
    EthernetHeader ed;
    ArpHeader ah;
};

#endif // ARPSTT_H_INCLUDED
