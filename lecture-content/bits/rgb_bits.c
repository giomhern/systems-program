#include <stdio.h>
#include <stdlib.h>

struct rgb{
    unsigned char r, g, b; // the range from 0 - 255  -- 8 bits 
    // unsigned short 0 - 65535 --> 0 - 1023 
};

struct rgb10{
    unsigned short r, g, b; // the range from 0 - 1023 -- 16 bits 
};

//  0    0    0  0 | _ _ _ _
// 128   64   32 16 8 4 2 1

// red: 5: 01111
// green: 10: 01010
// blue: 3: 00011

// --> glued together: 01111 01010 00011 and can use the unsigned short to store this value
// bc you will only use 15 bits of the 16 bits available

// red: RRRRR
// green: GGGGG
// blue: BBBBB 

// stitch them --> RRRRR GGGGG BBBBB
struct rgb10* image;

