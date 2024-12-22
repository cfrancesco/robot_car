#ifndef COMMUNICATION_H
#define COMMUNICATION_H

const unsigned int COMMUNICATION_DELAY = 5;
const unsigned int DEFAULT_INT_RANGE = 500;
unsigned long threeNumberPacking(unsigned int x, unsigned int y, unsigned int z);
unsigned long twoNumberPacking(unsigned int x, unsigned int y);
void threeNumberUnpacking(unsigned long packedValue, unsigned int &x, unsigned int &y, unsigned int &z);
void twoNumberUnpacking(unsigned long packedValue, unsigned int &x, unsigned int &y);
int floatToUInt(float f);
float uIntToFloat(unsigned int i);

#endif