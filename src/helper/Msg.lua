Msg = Msg or {}

--msg key
Msg.M2V_MSG = 0x00
Msg.V2M_MSG = 0x10
Msg.V2V_MSG = 0x20
Msg.M2M_MSG = 0x30
--msg mainhead

--m2v
Msg.M2V_EQUIP = 0x00
Msg.M2V_BATTLE = 0x01
Msg.M2V_ROLE = 0x02

--v2m
Msg.V2M_EQUIP = 0x10
Msg.V2M_BATTLE = 0x11

--v2v
Msg.V2V_BACK = 0x20

--m2m
Msg.M2M_EQUIP = 0x30
Msg.M2M_ARTIFACT = 0x31
--msg secondid

--BACK
Msg.BACK_MAINSCENE = 0x00

--EQUIP
Msg.EQUIP_EQUIP = 0x00
Msg.EQUIP_GETNEW = 0x01
Msg.EQUIP_SALL = 0x02
Msg.EQUIP_UPDATE = 0x03

--BATTLE
Msg.BATTLE_UPDATE = 0x00
Msg.BATTLE_ATTACK = 0x01
Msg.BATTLE_NEWENEMY = 0x01

--ROLE
Msg.ROLE_ADDTOTEAM = 0x00

--ARTIFACT
Msg.ARTIFACT_GETNEW = 0x00