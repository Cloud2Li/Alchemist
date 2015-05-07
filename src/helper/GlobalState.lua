--global state
gs = gs or {}

--[[
    whether play openAnimation
    this state should be set before openScene and be reset after openScene
    if don't set this state then while be last value
]]
local openAnimation = true
gs.setOpenAnimation = function(bool)
    openAnimation = bool
end
gs.getOpenAnimation = function()
    return openAnimation
end
--[[
    whether play closeAnimation
    this state should be set before closeScene and be reset after closeScene
    if don't set this state then while be last value
]]
local closeAnimation = true
gs.setCloseAnimation = function(bool)
    closeAnimation = bool
end

gs.getCloseAnimation = function()
    return closeAnimation
end