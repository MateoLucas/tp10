#ifndef PORTABD_H
#define PORTABD_H

int bitSet(int n,char port);
int bitClr(int n,char port);
int bitGet(int n,char port);
int bitToggle(int n,char port);
int maskOn (uint16_t msk,char port);
int maskOff (uint16_t msk, char port);
int maskToggle (uint16_t msk,char port);



#endif
