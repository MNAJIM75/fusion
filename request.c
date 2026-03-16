#include "request.h"
#include "zmq.h"
#include <string.h>

#define BUF_LEN 256

void* context;
void* requester;
char buffer[BUF_LEN];

void network_client_init(void) {
    context = (void *)zmq_ctx_new();
    if (!context) {
        fprintf(stderr, "Context creation failed: %s\n", zmq_strerror(errno));
    }
    requester = (void *)zmq_socket(context, ZMQ_REQ);
    if (!requester) {
        fprintf(stderr, "Socket creation failed: %s\n", zmq_strerror(errno));
        zmq_ctx_destroy(context);
    }
    if (zmq_connect(requester, "tcp://localhost:5555") != 0) {
        fprintf(stderr, "Connect failed: %s\n", zmq_strerror(errno));
        zmq_close(requester);
        zmq_ctx_destroy(context);
    }

}

void network_client_close(void) {
    zmq_close(requester);
    zmq_ctx_destroy(context);
}

void network_client_send(const char* msg) {
    int msg_length = strlen(msg);
    if (zmq_send(requester, msg, msg_length, 0) == -1) {
        fprintf(stderr, "Send failed: %s\n", zmq_strerror(errno));
    }
}

char* network_client_recv(void) {
    int size = zmq_recv(requester, buffer, BUF_LEN - 1, 0);
    if (size != -1) {
        buffer[size] = '\0';
        return buffer;
    } else fprintf(stderr, "Receive failed: %s\n", zmq_strerror(errno));
    return "Error!\0";
}




