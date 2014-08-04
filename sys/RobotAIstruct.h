//--------------------------------------
//������Ĵ��뿴�����У����Ҷ���~~~
//--------------------------------------


#pragma once

#define Info_MaxArsenals 2
#define Info_MaxObstacles 5
#define Info_MaxRobots 2
#define Info_MaxBullets 200




enum weapontypename
{
	WT_Cannon
	,WT_Shotgun
	,WT_RPG
	,WT_Machinegun
	,WT_Prism
	,WT_Tesla
	,WT_PlasmaTorch
	,WT_MissileLauncher
	,WT_ElectricSaw

	//����
	,WT_GrenadeThrower
};

enum enginetypename
{
	ET_Spider
	,ET_Robotman
	,ET_AFV
	,ET_UFO
};

enum bullettypename
{
	BT_Cannonball
	,BT_ShotgunBall
	,BT_RPGBall
	,BT_MachinegunBall
	,BT_Prism_Laser
	,BT_Tesla_Lightning
	,BT_PlasmaBall
	,BT_TrackingMissile
	,BT_ElectricSaw
	
	//�����������Ϸ��ҿɼ�(Ӧ��������ֱ�ӷ����)����
	,BT_Grenade
	


	//�����ǹ����Ե�����
	
	,BT_NULL
};


struct RobotAI_Order
{
	//����RobotAI��Update(..)�����ĶԻ������´�Ĳ�������
	int fire;	//���������������
	int wturn;	//����������ת���
	int run;	//���������֮һ��Ӱ���ٶȣ����幦������ѡ�������
	int eturn;	//���������֮һ��Ӱ����ת�����幦������ѡ�������

	RobotAI_Order(){fire=0;wturn=0;run=0;eturn=0;}
};


//һ�����׵���Ϣ�Ľṹ��
struct RobotAI_RobotInformation
{
	int entityID;	//������ù���

	int id;		//Battlefield.pRobot���±� ��myID���������

	weapontypename weaponTypeName;	//�������ࣨö�����ͣ�
	enginetypename engineTypeName;	//�������ࣨö�����ͣ�

	//���׵�ǰ����Ϣ
	Circle circle;		//�����Բ��(�ṹ��:x,y,radium)
	double engineRotation;	//���浱ǰ�Ƕȣ���x��������н�
	double weaponRotation;	//������ǰ�Ƕȣ���x��������н�
	double vx,vy,vr;	//x��ͶӰ�ٶȣ�y��ͶӰ�ٶȣ���ת���ٶ�
	
	int hp;				//���׵�ǰʣ������ֵ


	int remainingAmmo;		//���׵�ǰʣ�൯ҩ��
	int cooling;			//����������ǰʣ����ȴʱ��

};


//һ���ӵ�����Ϣ�Ľṹ��
struct RobotAI_BulletInformation
{
	int entityID;	//������ù���

	bullettypename type;		//�ӵ����ࣨö�����ͣ�

	Circle circle;		//�ӵ���Բ��(�ṹ�壺x,y,radium)
	double rotation;	//����Ƕ�
	double vx,vy,vr;	//x��ͶӰ�ٶȣ�y��ͶӰ�ٶȣ���ת���ٶ�
};

//һ����������Ϣ�Ľṹ��
struct RobotAI_ArsenalInformation
{
	Circle circle;	//������Բ��(�ṹ�壺x,y,radium)
	int respawning_time;	//��ǰʣ�����¼���ʱ��
};


//ÿ֡��ս������Ϣ�ṹ��
struct RobotAI_BattlefieldInformation
{
	//ʹ�������������洢

	int num_robot;	//���������������Ѿ����˵ģ�

	RobotAI_RobotInformation robotInformation[Info_MaxRobots];


	int num_bullet;	//��ǰ�ӵ�����������ѭ�������ں�ʱ��ֹ��

	RobotAI_BulletInformation bulletInformation[Info_MaxBullets];

	
	int num_obstacle;	//��ͼ�ϵ��ϰ�������������ѭ�������ں�ʱ��ֹ��

	Circle obstacle[Info_MaxObstacles];

	
	int num_arsenal;	//��ͼ�ϵľ��������������ѭ�������ں�ʱ��ֹ��

	RobotAI_ArsenalInformation arsenal[Info_MaxArsenals];


	
	Box boundary;		//ս���߽磬Box�ṹ��
};