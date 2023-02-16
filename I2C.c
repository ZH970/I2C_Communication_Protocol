#include <REGX52.H>

sbit I2C_SCL = P2^1;
sbit I2C_SDA = P2^0;
int i;

void I2C_Start() {
  I2C_SDA = 1;
  I2C_SCL = 1;
  I2C_SDA = 0;
  I2C_SCL = 0;
}

void I2C_Stop() {
  I2C_SDA = 0;
  I2C_SCL = 1;
  I2C_SDA = 1;
}

void I2C_SendByte(unsigned char byte) {
  for (i=0;i<8;i++) {
    I2C_SDA = byte&(0x80>>i);
    I2C_SCL = 1;
    I2C_SCL = 0;
  }
}

unsigned char I2C_ReceiveByte() {
  unsigned char byte = 0x00;
  I2C_SDA = 1;
  for (i=0;i<8;i++) {
    I2C_SCL = 1;
    if (I2C_SDA) {byte|=(0x80>>i);}
    I2C_SCL = 0;
  }
  return byte;
}

void I2C_SendAck(unsigned char AckBit) {
  I2C_SDA = AckBit;
  I2C_SCL = 1;
  I2C_SCL = 0;
}

unsigned char I2C_ReceiveAck() {
  unsigned char AckBit;
  I2C_SDA = 1;
  I2C_SCL = 1;
  AckBit = I2C_SDA;
  I2C_SCL = 0;
  return AckBit;
}