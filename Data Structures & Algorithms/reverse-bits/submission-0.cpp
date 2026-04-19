class Solution {
   public:
    uint32_t reverseBits(uint32_t n) {
        static uint8_t table[256];  // 2^8 possible byte
        static bool isInitialized = false;

        if (!isInitialized) {
            for (int i = 0; i < 256; i++) {
                uint8_t byte = i;
                uint8_t reversedByte = 0;

                for (int j = 0; j < 8; j++) {
                    if ((byte & 1) == 1) {
                        reversedByte |= (1 << (7 - j));
                    }

                    byte = byte >> 1;
                }

                table[i] = reversedByte;
            }

            isInitialized = true;
        }

        uint32_t result = 0;

        result |= table[n & 0xFF] << 24;         // byte 0 → position 3
        result |= table[(n >> 8) & 0xFF] << 16;  // byte 1 → position 2
        result |= table[(n >> 16) & 0xFF] << 8;  // byte 2 → position 1
        result |= table[(n >> 24) & 0xFF];       // byte 3 → position 0

        return result;
    }
};
