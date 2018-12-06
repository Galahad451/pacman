--
-- created with TexturePacker - https://www.codeandweb.com/texturepacker
--
-- $TexturePacker:SmartUpdate:3ac792ea46bdcb7ba766d12fc034f422:cf4796ff7173e3a338110c5378d73f43:f8f6c97dee13c65b710ad6069bbcb4dd$
--
-- local sheetInfo = require("mysheet")
-- local myImageSheet = graphics.newImageSheet( "mysheet.png", sheetInfo:getSheet() )
-- local sprite = display.newSprite( myImageSheet , {frames={sheetInfo:getFrameIndex("sprite")}} )
--

local SheetInfo = {}

SheetInfo.sheet =
{
    frames = {
    
        {
            -- pacMan01
            x=1,
            y=1,
            width=128,
            height=128,

        },
        {
            -- pacMan02
            x=131,
            y=1,
            width=128,
            height=128,

        },
        {
            -- pacMan03
            x=261,
            y=1,
            width=128,
            height=128,

        },
        {
            -- pacMan04
            x=391,
            y=1,
            width=128,
            height=128,

        },
        {
            -- pacMan05
            x=521,
            y=1,
            width=128,
            height=128,

        },
        {
            -- pacMan06
            x=651,
            y=1,
            width=128,
            height=128,

        },
    },

    sheetContentWidth = 780,
    sheetContentHeight = 130
}

SheetInfo.frameIndex =
{

    ["pacMan01"] = 1,
    ["pacMan02"] = 2,
    ["pacMan03"] = 3,
    ["pacMan04"] = 4,
    ["pacMan05"] = 5,
    ["pacMan06"] = 6,
}

function SheetInfo:getSheet()
    return self.sheet;
end

function SheetInfo:getFrameIndex(name)
    return self.frameIndex[name];
end

return SheetInfo
