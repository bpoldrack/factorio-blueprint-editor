/*
** $Id: ltable.h,v 2.16 2011/08/17 20:26:47 roberto Exp $
** Lua tables (hash)
** See Copyright Notice in lua.h
*/

#ifndef ltable_h
#define ltable_h

#include "lobject.h"

#define LUA_MAX_SEQUENTIAL_ARRAY_SIZE_BITS 10

#define gnode(t,i)	(&(t)->node[i])
#define gkey(n)		(&(n)->i_key.tvk)
#define gval(n)		(&(n)->i_val)
#define gnext(n)	((n)->i_key.nk.next)

#define invalidateTMcache(t)	((t)->flags = 0)


LUAI_FUNC const TValue *luaH_getint (lua_State* L, Table *t, int key);
LUAI_FUNC void luaH_setint (lua_State *L, Table *t, int key, TValue *value);
LUAI_FUNC void luaH_setlist(lua_State *L, Table *t, unsigned int firstkey, StkId firstval, unsigned int count);
LUAI_FUNC const TValue *luaH_getstr (Table *t, TString *key);
LUAI_FUNC const TValue *luaH_get (lua_State *L, Table *t, const TValue *key);
LUAI_FUNC TValue *luaH_newkey (lua_State *L, Table *t, const TValue *key);
LUAI_FUNC TValue *luaH_set (lua_State *L, Table *t, const TValue *key);
LUAI_FUNC Table *luaH_new (lua_State *L);
LUAI_FUNC void luaH_resize (lua_State *L, Table *t, int nasize, int nhsize);
LUAI_FUNC void luaH_resizearray (lua_State *L, Table *t, int nasize);
LUAI_FUNC void luaH_free (lua_State *L, Table *t);
LUAI_FUNC int luaH_next (lua_State *L, Table *t, StkId key);
LUAI_FUNC int luaH_getn (Table *t);
LUAI_FUNC int luaH_size (Table *t, int fuzzy);


#if defined(LUA_DEBUG)
LUAI_FUNC Node *luaH_mainposition (const Table *t, const TValue *key);
LUAI_FUNC int luaH_isdummy (Node *n);
#endif


#endif
