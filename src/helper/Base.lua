cc = cc or {}

cc.log = function(...)
    print(...);
end

cc.zTopOrder = 4
cc.zMiddleOrder = 3
cc.zFloorOrder = 2
cc.zBottomOrder = 1

cc.tFileType = 0
cc.tCustomType = 1
cc.tSLType = 3

cc.split = function(s, delim)
    if type(delim) ~= "string" or string.len(delim) <= 0 then
        return
    end

    local start = 1
    local t = {}
    while true do
    local pos = string.find (s, delim, start, true) -- plain find
        if not pos then
          break
        end

        table.insert (t, string.sub (s, start, pos - 1))
        start = pos + string.len (delim)
    end
    table.insert (t, string.sub (s, start))

    return t
end

cc.convertNum = function(num)
    if type(num) ~= "number" then
        return nil
    end

    local unit = {'', 'K', 'M', 'G', 'T', 'P', 'E', 'B'}

    local str = string.formatnumberthousands(string.format("%.0f", num))
    local temp = cc.split(str, ',')
    return temp[1]..unit[table.maxn(temp)]
    --[[if num >= 10000 then
        return string.format("%.0f", num/1000)..K
    else
        return string.format("%.0f", num)
    end]]
end

umsocial = umsocial or {}

-- 新浪微博
umsocial.SINA = 0
-- 微信
umsocial.WEIXIN = 1
-- 微信朋友圈
umsocial.WEIXIN_CIRCLE = 2
-- QQ
umsocial.QQ = 3
 -- QQ空间
umsocial.QZONE = 4
-- 人人网
umsocial.RENREN = 5
-- 豆瓣
umsocial.DOUBAN = 6
-- 来往
umsocial.LAIWANG = 7
-- 来往动态
umsocial.LAIWANG_CIRCLE = 8
-- 易信
umsocial.YIXIN = 9
-- 易信朋友圈
umsocial.YIXIN_CIRCLE = 10
-- facebook
umsocial.FACEBOOK = 11
-- twitter
umsocial.TWITTER = 12
-- instagram
umsocial.INSTAGRAM = 13
-- 短信
umsocial.SMS = 14
-- 邮件
umsocial.EMAIL = 15
-- 腾讯微博
umsocial.TENCENT_WEIBO = 16
