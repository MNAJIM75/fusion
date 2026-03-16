#define LUABIND_H
#ifdef LUABIND_H
#include <lua.h>
int l_init_network_client(lua_State*);
int l_close_network_client(lua_State*);
int l_send_network_client(lua_State*);
int l_recv_network_client(lua_State*);
void luabind_openlib(lua_State* L);

#endif
