#define REQUEST_H

#ifdef REQUEST_H

void network_client_init(void);
void network_client_close(void);
void network_client_send(const char* msg);
char* network_client_recv(void);
#endif
