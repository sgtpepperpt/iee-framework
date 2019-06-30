#include "Client.h"

#include "untrusted_util.h"
#include "definitions.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <getopt.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <sodium.h>
#include <random>
#include <stdint.h>
#include <assert.h>
#include <string.h>

using namespace std;

int main(int argc, char** argv) {
    // static params
    const char* server_name = IEE_HOSTNAME;
    const int server_port = IEE_PORT;

    // parse terminal arguments
    int c;
    while ((c = getopt(argc, argv, "hk:b:")) != -1) {
        switch (c) {
            case 'k':

                break;
            case 'h':
                printf("Usage: ./Client [-b nr_docs] [-k nr_clusters]\n");
                exit(0);
            case '?':
                if (optopt == 'c')
                    fprintf(stderr, "-%c requires an argument.\n", optopt);
                else if (isprint(optopt))
                    fprintf(stderr, "Unknown option `-%c'.\n", optopt);
                else
                    fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
                exit(1);
            default:
                exit(-1);
        }
    }

    int socket = untrusted_util::socket_connect(server_name, server_port);

    const char* msg = "op";
    const size_t in_len = strlen(msg);

    untrusted_util::socket_send(socket, &in_len, sizeof(size_t));
    untrusted_util::socket_send(socket, msg, in_len);

    size_t out_len;

    untrusted_util::socket_receive(socket, &out_len, sizeof(size_t));
    uint8_t* out = (uint8_t*)malloc(out_len);
    untrusted_util::socket_receive(socket, out, out_len);

    // close ssl connection
    untrusted_util::socket_close(socket);

    return 0;
}
