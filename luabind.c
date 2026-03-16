#include "luabind.h"
#include "lua.h"
#include "lauxlib.h"
#include "luajit.h"
#include "request.h"
#include <stdio.h>

int l_init_network_client(lua_State* L) {
   network_client_init();
   printf("Network: Client is Initialized.\n");
   return 0;
}

int l_close_network_client(lua_State* L) {
    network_client_close();
    printf("Network: Client is Closed.\n");
    return 0;
}

int l_send_network_client(lua_State* L) {
    const char* buf = luaL_checkstring(L, 1); // simpler helper
    network_client_send(buf);
    return 0;
}

int l_recv_network_client(lua_State* L) {
    char *buf = network_client_recv();
    lua_pushstring(L, buf);
    return 1;
}

void luabind_openlib(lua_State* L) {
    lua_register(L, "client_init", l_init_network_client);
    lua_register(L, "client_close", l_close_network_client);
    lua_register(L, "client_send", l_send_network_client);
    lua_register(L, "client_recv", l_recv_network_client);
}
