
cc.FileUtils:getInstance():addSearchPath("src")
cc.FileUtils:getInstance():addSearchPath("res")
cc.FileUtils:getInstance():addSearchPath("src/ccs")
-- CC_USE_DEPRECATED_API = true
require "cocos.init"

-- cclog
local cclog = function(...)
    print(string.format(...))
end

-- for CCLuaEngine traceback
function __G__TRACKBACK__(msg)
    cclog("----------------------------------------")
    cclog("LUA ERROR: " .. tostring(msg) .. "\n")
    cclog(debug.traceback())
    cclog("----------------------------------------")
    return msg
end

local function main()
    collectgarbage("collect")
    -- avoid memory leak
    collectgarbage("setpause", 100)
    collectgarbage("setstepmul", 5000)

    -- initialize director
    local director = cc.Director:getInstance()

    --turn on display FPS
    director:setDisplayStats(false)

    --set FPS. the default value is 1.0/60 if you don't call this
    director:setAnimationInterval(1.0 / 60)
    
    cc.Director:getInstance():getOpenGLView():setDesignResolutionSize(720, 1280, 0)
    
    math.randomseed(os.time()) 
    --create scene 

    loadscene = require "LoadScene"
    
    if cc.Director:getInstance():getRunningScene() then
        cc.Director:getInstance():replaceScene(loadscene)
    else
        cc.Director:getInstance():runWithScene(loadscene)
    end
end


local status, msg = xpcall(main, __G__TRACKBACK__)
if not status then
    error(msg)
end
