#include <REGX52.H>
#include "I2C.h"

#define AT24C02_Address  0xA0

void AT24C02_WriteByte(unsigned char Add, unsigned char Byte) {
  I2C_Start();
  I2C_SendByte(AT24C02_Address);       //SLAVE ADDRESS+W
  I2C_ReceiveAck();
  I2C_SendByte(Add);
  I2C_ReceiveAck();
  I2C_SendByte(Byte);
  I2C_ReceiveAck();
  I2C_Stop();
}

unsigned char AT24C02_ReceiveByte(unsigned char Add) {
  unsigned char Data;
  I2C_Start();
  I2C_SendByte(AT24C02_Address);//SLAVE ADDRESS+W
  I2C_ReceiveAck();
  I2C_SendByte(Add);
  I2C_ReceiveAck();
  I2C_Start();
  I2C_SendByte(AT24C02_Address|0x01);
  I2C_ReceiveAck();
  Data = I2C_ReceiveByte();
  I2C_SendAck(1);
  I2C_Stop();
  return Data;
}