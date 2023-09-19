#pragma once

class Offsets
{
private:
Offsets() {
glowEnable = glowEnable + highlightServerContextID;
glowThroughWall = glowThroughWall + highlightServerContextID;
glowColor = glowColor + highlightParams;
glowMode = glowMode + highlightFunctionBits;
breathAngles = viewAngle - 0x10;
}

~Offsets() {}
public:
static Offsets& getInstance() {
static Offsets instance;
return instance;
}

Offsets(const Offsets&) = delete;
Offsets& operator=(const Offsets&) = delete;

ulong region = 0x140000000;

ulong inAttack = 0x07473fb8; //[Buttons] in_attack=0x07872c50

ulong level = 0x16efe10; //Miscellaneous LevelName=0x163a9b0

ulong localPlayer = 0x2225648; //0x1388eb8 //.?AVC_GameMovement@@=0x020c20f0

ulong entityList = 0x1e754c8; //cl_entitylist=0x1d10e18

ulong viewRender = 0x7473a28; //[Miscellaneous] ViewRender=0x7870390
ulong viewMatrix = 0x11A350; //[Miscellaneous] ViewMatrix=0x11a210

ulong lifeState = 0x07d0; //m_lifeState=0x0798
ulong bleedOutState = 0x2790; //m_bleedoutState=0x2740
ulong health = 0x0470; //[RecvTable.DT_Player] m_iHealth=0x043c
ulong maxHealth = 0x05b0; //[RecvTable.DT_Player] m_iMaxHealth=0x0578
ulong shield = 0x01a0; //[RecvTable.DT_TitanSoul] m_shieldHealth=0x0170
ulong maxShield = 0x01a4; //[RecvTable.DT_TitanSoul] m_shieldHealthMax=0x0174
ulong lastVisibleTime = 0x1aa0;
ulong viewAngle = 0x25e4 - 0x14; //m_ammoPoolCapacity - 0x14
ulong weaponPunch = 0x24e8; //m_currentFrameLocalPlayer.m_vecPunchWeapon_Angle=0x24b0
ulong breathAngles = viewAngle - 0x10;
ulong team = 0x0480; //m_iTeamNum=0x044c
ulong localOrigin = 0x0188; //m_localOrigin=0x0158
ulong vecAbsOrigin = 0x017c; //m_vecAbsOrigin=0x014c
ulong vecAbsVelocity = 0x0170; //[RecvTable.DT_BaseEntity] m_vecAbsVelocity
ulong bones = 0x0ec8 + 0x48; //m_bConstrainBetweenEndpoints=0x0f50
ulong studioHdr = 0x1118; //CBaseAnimating!m_pStudioHdr=0x10f0
ulong cameraPosition = 0x1f80; //[Miscellaneous] CPlayer!camera_origin=0x1f48
ulong cameraAngles = 0x1f8c; //[Miscellaneous] CPlayer!camera_angles=0x1f54
ulong name = 0x05c1; //[RecvTable.DT_BaseEntity] m_iName
ulong latestPrimaryWeapons = 0x1a44; //[RecvTable.DT_BaseCombatCharacter] m_latestPrimaryWeapons



ulong highlightServerContextID = 0x03F0; //[RecvTable.DT_HighlightSettings] m_highlightServerContextID + 0x8=0x03c0
ulong glowEnable = 0x3c8 + 0x30;
ulong glowThroughWall = 0x3d0 + 0x30;

ulong highlightParams = 0x01e8; //[RecvTable.DT_HighlightSettings] m_highlightParams=0x01b8
ulong glowColor = 0x1D0 + 0x30;

ulong highlightFunctionBits=0x02f0; // [RecvTable.DT_HighlightSettings] m_highlightFunctionBits=0x02c0
ulong glowMode = 0x2C4 + 0x30;

ulong highlightServerFadeEndTimes = 0x03b0;
ulong glowDistance = 0x3B4 + 0x30; // [RecvTable.DT_HighlightSettings]m_highlightServerFadeEndTimes + 52(0x34);

ulong projectileSpeed = 0x1f6c; //CWeaponX!m_flProjectileSpeed=0x1f18
ulong projectileScale = 0x1f74; //CWeaponX!m_flProjectileScale=0x1f20
ulong ammoInClip = 0x1668;
//[RecvTable.DT_PropSurvival] m_customScriptInt=0x1648

/*


[RecvTable.DT_WeaponX_LocalWeaponData]
m_nNextThinkTick=0x0574
m_lastPrimaryAttackTime=0x1644
m_nextReadyTime=0x1648
m_nextPrimaryAttackTime=0x164c
m_attackTimeThisFrame=0x1650
m_ammoInClip=0x1670
m_ammoInStockpile=0x1674
m_lifetimeShots=0x1678
m_flTimeWeaponIdle=0x167c
m_bInReload=0x1686
*/

};
