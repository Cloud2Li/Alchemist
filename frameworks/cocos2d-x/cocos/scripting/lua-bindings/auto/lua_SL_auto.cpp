#include "lua_SL_auto.hpp"
#include "SL.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"



int lua_SL_SL_removeFile(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SL* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.SL",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SL*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_SL_SL_removeFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.SL:removeFile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_SL_SL_removeFile'", nullptr);
            return 0;
        }
        bool ret = cobj->removeFile(arg0);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.SL:removeFile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_SL_SL_removeFile'.",&tolua_err);
#endif

    return 0;
}
int lua_SL_SL_LoadFromFile(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SL* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.SL",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SL*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_SL_SL_LoadFromFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.SL:LoadFromFile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_SL_SL_LoadFromFile'", nullptr);
            return 0;
        }
        std::string ret = cobj->LoadFromFile(arg0);
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.SL:LoadFromFile",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_SL_SL_LoadFromFile'.",&tolua_err);
#endif

    return 0;
}
int lua_SL_SL_saveToFile(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::SL* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.SL",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::SL*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_SL_SL_saveToFile'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        std::string arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "cc.SL:saveToFile");

        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "cc.SL:saveToFile");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_SL_SL_saveToFile'", nullptr);
            return 0;
        }
        bool ret = cobj->saveToFile(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.SL:saveToFile",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_SL_SL_saveToFile'.",&tolua_err);
#endif

    return 0;
}
int lua_SL_SL_destroyInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.SL",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_SL_SL_destroyInstance'", nullptr);
            return 0;
        }
        cocos2d::SL::destroyInstance();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.SL:destroyInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_SL_SL_destroyInstance'.",&tolua_err);
#endif
    return 0;
}
int lua_SL_SL_setDelegate(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.SL",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        cocos2d::SL* arg0;
        ok &= luaval_to_object<cocos2d::SL>(tolua_S, 2, "cc.SL",&arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_SL_SL_setDelegate'", nullptr);
            return 0;
        }
        cocos2d::SL::setDelegate(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.SL:setDelegate",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_SL_SL_setDelegate'.",&tolua_err);
#endif
    return 0;
}
int lua_SL_SL_getInstance(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"cc.SL",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_SL_SL_getInstance'", nullptr);
            return 0;
        }
        cocos2d::SL* ret = cocos2d::SL::getInstance();
        object_to_luaval<cocos2d::SL>(tolua_S, "cc.SL",(cocos2d::SL*)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "cc.SL:getInstance",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_SL_SL_getInstance'.",&tolua_err);
#endif
    return 0;
}
static int lua_SL_SL_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (SL)");
    return 0;
}

int lua_register_SL_SL(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"cc.SL");
    tolua_cclass(tolua_S,"SL","cc.SL","",nullptr);

    tolua_beginmodule(tolua_S,"SL");
        tolua_function(tolua_S,"removeFile",lua_SL_SL_removeFile);
        tolua_function(tolua_S,"LoadFromFile",lua_SL_SL_LoadFromFile);
        tolua_function(tolua_S,"saveToFile",lua_SL_SL_saveToFile);
        tolua_function(tolua_S,"destroyInstance", lua_SL_SL_destroyInstance);
        tolua_function(tolua_S,"setDelegate", lua_SL_SL_setDelegate);
        tolua_function(tolua_S,"getInstance", lua_SL_SL_getInstance);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(cocos2d::SL).name();
    g_luaType[typeName] = "cc.SL";
    g_typeCast["SL"] = "cc.SL";
    return 1;
}
TOLUA_API int register_all_SL(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"cc",0);
	tolua_beginmodule(tolua_S,"cc");

	lua_register_SL_SL(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

