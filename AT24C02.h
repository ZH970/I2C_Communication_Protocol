#ifnedf _AT24C02_H_
#define _AT24C02_H_

void AT24C02_WriteByte(unsigned char Add, unsigned char Byte);
unsigned char AT24C02_ReceiveByte(unsigned char Add);

#endif

