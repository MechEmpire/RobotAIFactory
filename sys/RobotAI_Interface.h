#pragma once
#include "struct.h"
#include "RobotAIstruct.h"
#include <string>
using namespace std;





typedef void (*FP_TRACE)(string);
typedef string (*FP_GET_STRING_W)(weapontypename);
typedef int (*FP_GET_INT_W)(weapontypename);
typedef double (*FP_GET_DOUBLE_W)(weapontypename);
typedef string (*FP_GET_STRING_E)(enginetypename);
typedef int (*FP_GET_INT_E)(enginetypename);
typedef double (*FP_GET_DOUBLE_E)(enginetypename);
typedef string (*FP_GET_STRING_B)(bullettypename);
typedef int (*FP_GET_INT_B)(bullettypename);
typedef double (*FP_GET_DOUBLE_B)(bullettypename);

#define TRACE (*trace)


//这里是一些可以获取装备静态信息的做成宏的函数指针
//你可以理解为函数
//调用方法和调用函数看起来一样，比如我希望获得加农炮的弹仓子弹数：
//get_weapon_ammo(WT_Cannon);
#define get_weapon_name (*getWeaponName)
#define get_weapon_ammo (*getWeaponAmmo)
#define get_weapon_coolingTime (*getWeaponCoolingTime)
#define get_weapon_inaccuracy (*getWeaponInaccuracy)
#define get_weapon_rotationSpeed (*getWeaponRotationSpeed)
#define get_engine_name (*getEngineName)
#define get_engine_maxSpeed (*getEngineMaxSpeed)
#define get_engine_maxHp (*getEngineMaxHp)
#define get_engine_rotationSpeed (*getEngineRotationSpeed)
#define get_engine_acceleration (*getEngineAcceleration)
#define get_bullet_name (*getBulletName)
#define get_bullet_speed (*getBulletSpeed)
#define get_bullet_damage (*getBulletDamage)


//接口
class RobotAI_Interface
{
public:
	virtual ~RobotAI_Interface(){};


	//必须完成的方法
	//每个回合（帧）的操纵方法
	virtual void Update(RobotAI_Order& , const RobotAI_BattlefieldInformation&, int)=0;
	//选择装备方法（载入时调用，进入军火库调用）
	virtual void ChooseArmor(weapontypename&,enginetypename&,bool)=0;
	

	virtual string GetName()=0;
	virtual string GetAuthor()=0;

	//颜色样式改变器
	virtual int GetWeaponRed()=0;
	virtual int GetWeaponGreen()=0;
	virtual int GetWeaponBlue()=0;

	virtual int GetEngineRed()=0;
	virtual int GetEngineGreen()=0;
	virtual int GetEngineBlue()=0;
	///////////////////////////////////////


	//输出调试信息，大家可以直接使用cout，不用使用这个方法了
	FP_TRACE trace;					

	//StaticDataGetter
	//weapon
	FP_GET_STRING_W getWeaponName;
	FP_GET_INT_W getWeaponAmmo;
	FP_GET_INT_W getWeaponCoolingTime;
	FP_GET_DOUBLE_W getWeaponInaccuracy;
	FP_GET_DOUBLE_W getWeaponRotationSpeed;
	//engine
	FP_GET_STRING_E getEngineName;
	FP_GET_DOUBLE_E getEngineMaxSpeed;
	FP_GET_INT_E getEngineMaxHp;
	FP_GET_DOUBLE_E getEngineRotationSpeed;
	FP_GET_DOUBLE_E getEngineAcceleration;
	//bullet
	FP_GET_STRING_B getBulletName;
	FP_GET_DOUBLE_B getBulletSpeed;
	FP_GET_INT_B getBulletDamage;
	FP_GET_INT_B getBulletFlyTime;
	/////////////////////////////////////////////


	//Trigger Function
	virtual void onBattleStart(const RobotAI_BattlefieldInformation&,int)=0;		//一场战斗开始时被调用
	virtual void onBattleEnd(const RobotAI_BattlefieldInformation&,int)=0;			//一场战斗结束时被调用

	
	virtual void onSomeoneFire(int)=0;				//有机甲开火时被调用
	virtual void onHit(int,bullettypename)=0;		//被击中时被调用
};