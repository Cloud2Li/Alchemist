--region LayerAni.lua
--Author : lhm
--Date   : 2015/5/5

LayerAni = {}

LayerAni.NONE = 0
LayerAni.UP2DOWN_1 = 1
LayerAni.DOWN2UP_1 = 2
LayerAni.RIGHT2LEFT_1 = 3
LayerAni.LEFT2RIGHT_1 = 4

function LayerAni.addOpenAni(parent, node, id, arg)
    if id == nil then
        id = node._aniID
    end

    cc.log("addOpenAni")
    parent:addChild(node, node.ZORDER)
    node:setVisible(true)
    node:onEnter(arg)

    if id ==LayerAni.UP2DOWN_1 then
        
    else
        node:onStart(arg)
    end
end

function LayerAni.addCloseAni(node, id, arg)
    if id == nil then
        id = node._aniID
    end
    
    node:onEnd(arg)

    if id == LayerAni.UP2DOWN_1 then

    else
        node:removeFromParent()
        node:setVisible(false)
        node:onExit(arg)
    end
end

--endregion
