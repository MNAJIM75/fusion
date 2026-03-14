#include <stdio.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

int luaopen_raylua(lua_State* L);
int test_compiler(int argc, const char** argv); 
int build_compiler(int argc, const char** argv); 

int main(int argc, const char** argv) {
	return test_compiler(argc, argv);
}

int test_compiler(int argc, const char** argv) {
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	luaopen_raylua(L);
	if (luaL_dofile(L, "test.lua") != LUA_OK) {
		fprintf(stderr, "Lua error: %s\n", lua_tostring(L, -1));
	}
	lua_close(L);
	return 0;
}

int build_compiler(int argc, const char** argv) {
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	lua_newtable(L);
	int i = 0;
	while (argc != i) {
	  lua_pushstring(L, argv[i]);
	  lua_rawseti(L, -2, i);
	  i++;
	}
	lua_setglobal(L, "arg");
	luaopen_raylua(L);
	// if (luaL_dofile(L, "test.lua") != LUA_OK) {
	// 	fprintf(stderr, "Lua error: %s\n", lua_tostring(L, -1));
	// }
	lua_close(L);
	return 0;
}
