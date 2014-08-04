//һЩ��Ϸ�п����õ��Ľṹ��
//AI�����߿���ѡ����ʹ��

#pragma once
using namespace std;
#include <cmath>
#include <cstdlib>
#include <ctime>
#define PI 3.1415926535898

//��״���ࣨö�����ͣ�
enum shapes{S_Circle,S_Box,S_Beam};



//��
struct Point
{
	double x;
	double y;
};

//Բ��
struct Circle
{
	double x;	//Բ������x
	double y;	//Բ������y
	double r;	//Բ�ΰ뾶
};

//����
struct Box
{
	double x;	//������������x
	double y;	//������������y
	double width;	//���ο�ˮƽ��
	double height;	//���θߣ���ֱ��
};

//�߶�
struct Segment
{
	double x1,y1;
	double x2,y2;
};

//����
struct Beam
{
	//���(x,y)
	double x;
	double y;
	double rotation;	//�Ƕ�

	//�յ�(x,y)
	double ex,ey;
};



//������һЩ���ܻ��õ��ĺ���
//����ȫ���Ժ������ǣ���ʹ���Լ���д�ĺ���
//�ⲿ�ֵĺ�����ʵ����GlobalFunction.cpp��
extern Point myRotate(double,double,double,double,bool);
extern double AngleAdjust(double &);
extern double AnglePlus(double,double);
extern double AngleToRadian(double);
extern double RadianToAngle(double);
extern bool HitTestCirclePoint(const Circle &,const double &,const double y);
extern bool HitTestCircles(const Circle &, const Circle &);
extern bool HitTestBeamCircle(const Beam &,const Circle &);
extern Point GetHitPoint(Beam,Circle);
extern void SetSeed();
extern double Random0_1();
extern int Random(int,int);