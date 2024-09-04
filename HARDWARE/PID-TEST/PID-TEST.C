#include "PID-TEST.h"
#include "pid-protocol.h"




/**
  * @brief 设置上位机的值
  * @param cmd：命令
  * @param ch: 曲线通道
  * @param data：参数指针
  * @param num：参数个数
  * @retval 无
  */
void set_computer_value(uint8_t cmd, uint8_t ch, void *data, uint8_t num)
{
	static packet_head_t set_packet;

	uint8_t sum = 0;    // 校验和
	num *= 4;           // 一个参数 4 个字节

	set_packet.head = FRAME_HEADER;     // 包头 0x59485A53
	set_packet.ch   = ch;              // 设置通道
	set_packet.len  = 0x0B + num;      // 包长
	set_packet.cmd  = cmd;             // 设置命令

	sum = check_sum(0, (uint8_t *)&set_packet, sizeof(set_packet));       // 计算包头校验和
	sum = check_sum(sum, (uint8_t *)data, num);                           // 计算参数校验和

	usart1_send((uint8_t *)&set_packet, sizeof(set_packet));    // 发送数据头
	usart1_send((uint8_t *)data, num);                          // 发送参数
	usart1_send((uint8_t *)&sum, sizeof(sum));                  // 发送校验和
}


void usart1_send(u8*data, u8 len)
{
	u8 i;
	for(i=0;i<len;i++)
	{
		while(USART_GetFlagStatus(USART1,USART_FLAG_TC)==RESET); 
		USART_SendData(USART1,data[i]);   
	}
}



//=======================================
//串口1中断服务程序
//=======================================
uint8_t Recv1[128]={0};//串口接收缓存
u8 rx_cnt=0;//接收数据个数计数变量
int sizecopy=128;

void USART1_IRQHandler(void)                	
{
	uint8_t data;//接收数据暂存变量
	uint8_t bufcopy[128];//最多只取前64个数据

	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)  //接收中断
	{
		data = USART_ReceiveData(USART1);   			
		Recv1[rx_cnt++]=data;//接收的数据存入接收数组 
		USART_ClearITPendingBit(USART1,USART_IT_RXNE);
	} 
	
	if(USART_GetITStatus(USART1, USART_IT_IDLE) != RESET)//空闲中断
	{
		data = USART1->SR;//串口空闲中断的中断标志只能通过先读SR寄存器，再读DR寄存器清除！
		data = USART1->DR;
		
		//清空本地接收数组
		memset(bufcopy,0,sizecopy);
		memcpy(bufcopy,Recv1,rx_cnt);//有几个复制几个
		protocol_data_recv(bufcopy, rx_cnt);
		memset(Recv1,0,sizecopy);
		rx_cnt=0;
	}
} 


