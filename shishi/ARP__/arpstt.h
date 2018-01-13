#ifndef ARPSTT_H_INCLUDED
#define ARPSTT_H_INCLUDED

//14�ֽ���̫���ײ�
struct EthernetHeader
{
    u_char DestMAC[6];    //Ŀ��MAC��ַ 6�ֽ�
    u_char SourMAC[6];   //ԴMAC��ַ 6�ֽ�
    u_short EthType;         //��һ��Э�����ͣ���0x0800������һ����IPЭ�飬0x0806Ϊarp  2�ֽ�
};

//28�ֽ�ARP֡�ṹ
struct ArpHeader
{
    unsigned short hdType;   //Ӳ������
    unsigned short proType;   //Э������
    unsigned char hdSize;   //Ӳ����ַ����
    unsigned char proSize;   //Э���ַ����
    unsigned short op;   //�������ͣ�ARP����1����ARPӦ��2����RARP����3����RARPӦ��4����
    u_char smac[6];   //ԴMAC��ַ
    u_char sip[4];   //ԴIP��ַ
    u_char dmac[6];   //Ŀ��MAC��ַ
    u_char dip[4];   //Ŀ��IP��ַ
};

//��������arp���İ����ܳ���42�ֽ�
struct ArpPacket {
    EthernetHeader ed;
    ArpHeader ah;
};

#endif // ARPSTT_H_INCLUDED
