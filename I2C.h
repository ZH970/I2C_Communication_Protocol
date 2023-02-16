#ifnedf _I2C_H_
#define _I2C_H_

void I2C_Start();
void I2C_Stop();
void I2C_SendByte(unsigned char byte);
unsigned char I2C_ReceiveByte();
void I2C_SendAck(unsigned char AckBit);
unsigned char I2C_ReceiveAck();

#endif

