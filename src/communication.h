#ifndef COMMUNICATION_H
#define COMMUNICATION_H

unsigned long threeNumberPacking(unsigned int x, unsigned int y, unsigned int z);
unsigned long twoNumberPacking(unsigned int x, unsigned int y);
void threeNumberUnpacking(unsigned long packedValue, unsigned int &x, unsigned int &y, unsigned int &z);
void twoNumberUnpacking(unsigned long packedValue, unsigned int &x, unsigned int &y);
int floatToUInt(float f, unsigned int range=512);
float uIntToFloat(unsigned int i, unsigned int range=512);
const unsigned int COMMUNICATION_DELAY = 20;
#endif