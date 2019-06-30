#include <unistd.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

// includes from framework
#include "definitions.h"
#include "outside_util.h"
#include "trusted_crypto.h"
#include "trusted_util.h"
#include "extern_lib.h" // defines the functions we implement here

using namespace std;

void extern_lib::process_message(uint8_t** out, size_t* out_len, const uint8_t* in, const size_t in_len) {
    // pass pointer without op char to processing functions
    uint8_t* input = ((uint8_t*)in) + sizeof(unsigned char);
    const size_t input_len = in_len - sizeof(unsigned char);

    //debug_printbuf((uint8_t*)in, in_len);

    *out_len = 0;
    *out = NULL;

    switch (((unsigned char*)in)[0]) {
        case OP_IEE_INIT: {
            outside_util::printf("Init repository!\n");

            *out_len = 1;
            unsigned char* ret = (unsigned char*)malloc(sizeof(unsigned char));
            ret[0] = 'x';
            *out = ret;

            break;
        }
        default: {
            outside_util::printf("Unrecognised op: %02x\n", ((unsigned char*)in)[0]);
            break;
        }
    }
}

void extern_lib::init() {
    outside_util::printf("init function!\n");
}
