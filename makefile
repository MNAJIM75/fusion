CFLAGS := -O2 -s
LDFLAGS := -O2 -s -lm
CFLAGS += -Iraylib-lua/luajit/src -Iraylib-lua/raylib/src -Iraylib-lua/raygui/src -Iraylib-lua/physac/src
LDFLAGS += raylib-lua/libraylua.a raylib-lua/luajit/src/libluajit.a raylib-lua/raylib/src/libraylib.a 

AR ?= ar
LUA ?= raylib-lua/luajit/src/luajit

LDFLAGS += -lopengl32 -lgdi32 -lwinmm -lzmq

fusion: fusion.c request.c luabind.c
	gcc -o $@ $(CFLAGS) $^ $(LDFLAGS)
