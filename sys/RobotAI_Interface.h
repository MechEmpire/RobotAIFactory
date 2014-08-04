#pragma once
#include "struct.h"
#include "RobotAIstruct.h"
#include <string>
using namespace std;


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

#define get_weapon_name (*getWeaponName)
//#define get_weapon_damage (*getWeaponDamage)
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


//�ӿ�
class RobotAI_Interface
{
public:
	virtual ~RobotAI_Interface(){};


	//������ɵķ���
	//ÿ���غϣ�֡���Ĳ��ݷ���
	virtual void Update(RobotAI_Order& , const RobotAI_BattlefieldInformation&, int)=0;
	//ѡ��װ������������ʱ���ã�����������ã�
	virtual void ChooseArmor(weapontypename&,enginetypename&,bool)=0;
	

	virtual string GetName()=0;
	virtual string GetAuthor()=0;

	//��ɫ��ʽ�ı���
	virtual int GetWeaponRed()=0;
	virtual int GetWeaponGreen()=0;
	virtual int GetWeaponBlue()=0;

	virtual int GetEngineRed()=0;
	virtual int GetEngineGreen()=0;
	virtual int GetEngineBlue()=0;
	///////////////////////////////////////


	//�ɹ�ѡ��Ĺ��ܷ���
	//virtual string trace()=0;		//���������Ϣ����(���ַ�ʽ�����㣬��ȡ���ɸ�ʲô����ָ��ɶ��)
	//void (*trace)(string);			//���������Ϣ����ָ��
	FP_TRACE trace;					//���������Ϣ����ָ��
									//����ʱ	(*trace)("info needed to be print")

									//��ֵʱ��ȫ�ֺ���	trace=trace_global;
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
	virtual void onBattleStart(const RobotAI_BattlefieldInformation&,int)=0;		//һ��ս����ʼʱ������
	virtual void onBattleEnd(const RobotAI_BattlefieldInformation&,int)=0;			//һ��ս������ʱ������

	
	virtual void onSomeoneFire(int)=0;
	virtual void onHit(int,bullettypename)=0;		//������ʱ����
};