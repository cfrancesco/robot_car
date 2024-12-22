const unsigned int COMMUNICATION_DELAY;
int DEFAULT_INT_RANGE=500;

unsigned long threeNumberPacking(unsigned int x, unsigned int y, unsigned int z) {
    unsigned long packedValue = 0;
    packedValue = (unsigned long)x << 20;
    packedValue = packedValue | ((unsigned long)y << 10);
    packedValue = packedValue | z;
    return packedValue;
}

void threeNumberUnpacking(unsigned long packedValue, unsigned int &x, unsigned int &y, unsigned int &z) {
    x = (packedValue >> 20) & 0x3FF;
    y = (packedValue >> 10) & 0x3FF;
    z = packedValue & 0x3FF;
}

void twoNumberUnpacking(unsigned long packedValue, unsigned int &x, unsigned int &y) {
    x = packedValue >> 10;
    y = packedValue & 0x3FF;
}

unsigned long twoNumberPacking(unsigned int x, unsigned int y) {
    unsigned long packedValue = 0;
    packedValue = (unsigned long)x << 10;
    packedValue = packedValue | y;
    return packedValue;
}

unsigned int floatToUInt(float f) {
    return static_cast<unsigned int>(f * DEFAULT_INT_RANGE + DEFAULT_INT_RANGE);
}

float uIntToFloat(unsigned int i) {
    return static_cast<float>(i - DEFAULT_INT_RANGE) / DEFAULT_INT_RANGE;
}
