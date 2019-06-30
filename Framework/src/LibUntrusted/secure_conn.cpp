#include "untrusted_util.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct secure_conn_t {

} secure_conn_t;

void untrusted_util::init_secure_connection(secure_connection** connection, const char* server_name, const int server_port) {
}

void untrusted_util::socket_secure_send(secure_connection* connection, const void* buff, size_t len) {

}

void untrusted_util::socket_secure_receive(secure_connection* connection, void* buff, size_t len) {
}

void untrusted_util::close_secure_connection(secure_connection* connection) {

}
