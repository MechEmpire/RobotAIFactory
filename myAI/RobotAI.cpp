#include "RobotAI.h"

RobotAI::RobotAI()
{

}


RobotAI::~RobotAI()
{

}


//-----------------------------------------------------
//1.������ɵ�ս������
//-----------------------------------------------------


void RobotAI::Update(RobotAI_Order& order,const RobotAI_BattlefieldInformation& info,int myID)
{
	//֡���ݺ���
	//���ܣ���ÿһ֡�����ã������Ļ�������һ֡�Ķ�������
	//������order	...	���ײ���ָ����ں������и�����ֵ�Բ��ݻ�������һ֡����Ϊ
	//		info	...	ս����Ϣ
	//		myID	... �Լ�������info��robot�����Ӧ���±�
	//		(�⼸����������ϸ˵���ڿ����ֲ�����ҵ�����Ҳ������RobotAIstruct.h��ֱ���ҵ����ǵĴ���)
	

}



void RobotAI::ChooseArmor(weapontypename& weapon,enginetypename& engine,bool a)
{
	//��ѡװ������
	//���ܣ���ս����ʼʱΪ��Ļ���ѡ����ʵ����������������ؾ�
	//������weapon	...	������ѡ����������ں������и�����ֵ
	//		engine	...	������ѡ������棬�ں������и�����ֵ
	//tip:	������Ĳ�����ö������ weapontypename �� enginetypename
	//		�����ĵ�������ϸ˵������Ҳ������RobotAIstruct.h��ֱ���ҵ����ǵĴ���
	//tip:	���һ��bool��û�õġ�������һ���˻�������

	weapon=WT_Cannon;	//�����Ұ���ũ��
	engine=ET_Spider;	//�����Ұ�С֩��
}











//-----------------------------------------------------
//2.������Ϣ
//-----------------------------------------------------


string RobotAI::GetName()
{
	//������Ļ��׵�����
	return "���۵�֩��";
}

string RobotAI::GetAuthor()
{
	//���ػ��������˻��Ŷӵ�����
	return "��ѧ��";
}




//����һ��(-255,255)֮��Ļ���������������ɫƫ��ֵ���졢�̡�����
//�������flash�ͻ��˵Ĳ���Ԥ����Ԥ����ɫ�����Ч��
int RobotAI::GetWeaponRed()
{
	//����һ��-255-255֮�������,����������ɫ��ƫ��ֵ
	return -50;
}
int RobotAI::GetWeaponGreen()
{
	//����һ��-255-255֮�������,����������ɫ��ƫ��ֵ
	return -50;
}
int RobotAI::GetWeaponBlue()
{
	//����һ��-255-255֮�������,����������ɫ��ƫ��ֵ
	return -50;
}



//����һ��(-255,255)֮��Ļ��������ؾߵ���ɫƫ��ֵ���졢�̡�����
//�������flash�ͻ��˵Ĳ���Ԥ����Ԥ����ɫ�����Ч��
int RobotAI::GetEngineRed()
{
	//����һ��-255-255֮�����,�����ؾߺ�ɫ��ƫ��ֵ
	return -50;
}
int RobotAI::GetEngineGreen()
{
	//����һ��-255-255֮�������,�����ؾ���ɫ��ƫ��ֵ
	return -50;
}
int RobotAI::GetEngineBlue()
{
	//����һ��-255-255֮�������,�����ؾ���ɫ��ƫ��ֵ
	return -50;
}









//-----------------------------------------------------
//3.�ò�������Ĵ�������
//-----------------------------------------------------


void RobotAI::onBattleStart(const RobotAI_BattlefieldInformation& info,int myID)
{
	//һ��ս����ʼʱ�����ã����ܿ���������ʼ��
	//������info	...	ս����Ϣ
	//		myID	... �Լ�������info��robot�����Ӧ���±�

}

void RobotAI::onBattleEnd(const RobotAI_BattlefieldInformation& info,int myID)
{
	//һ��ս������ʱ�����ã����ܿ������������㶯̬������ڴ�ռ䣨��������˵Ļ���
	//������info	...	ս����Ϣ
	//		myID	... �Լ�������info��robot�����Ӧ���±�
}


void RobotAI::onSomeoneFire(int fireID)
{
	//�л��׿���ʱ������
	//������fireID	... ����Ļ����±�
}


void RobotAI::onHit(int launcherID,bullettypename btn)
{
	//���ӵ�����ʱ������
	//������btn	...	��������ӵ����ࣨö�����ͣ�
}



//TODO:�������ʵ�����Լ��ĺ���