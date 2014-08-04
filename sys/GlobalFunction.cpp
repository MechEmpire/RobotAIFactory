#include "struct.h"


//������һЩ���ܻ��õ��ĺ���
//����ȫ���Ժ������ǣ���ʹ���Լ���д�ĺ���





//��ת����
//˵����������ת��ĵ�
//������x	...	x������
//		y	...	y������
//		s	...Ҫ��ת�Ƕȵ�sinֵ
//		c	...Ҫ��ת�Ƕȵ�cosֵ
//		re	...true=˳ʱ�룬false=��ʱ��
Point myRotate(double x,double y,double s,double c,bool re)
{
	Point result;
	if(re)
	{
		result.x=x*c+y*s;
		result.y=y*c-x*s;
	}
	else
	{
		result.x=x*c-y*s;
		result.y=y*c+x*s;
	}
	return result;
}



//�Ƕȣ�����������
//˵�������ط�Χ��-180~180֮��ĽǶ���
//������c	...	�Ƕ���
double AngleAdjust(double &c)
{
	while(c>180)
	{
		c-=360;
	}
	while(c<=-180)
	{
		c+=360;
	}
	return c;
}


//�Ƕȣ����������
//˵����������ת��ĵ�
double AnglePlus(double a,double b)
{
	//�Ƕ���Ӽ�
	double c=a+b;
	AngleAdjust(c);
	return c;
}

//�Ƕ���ת����������
double AngleToRadian(double angle)
{
	//�Ƕ�ת����
	return angle/180*PI;
}

//������ת�Ƕ�������
double RadianToAngle(double radian)
{
	return radian/PI*180;
}

//��ײ��⣺Բ�����
//������c	...	Բ�Σ��ṹ�壩
//		x	...	x������
//		y	...	y������
bool HitTestCirclePoint(const Circle &c,const double &x,const double &y)
{
	double dx=c.x-x,	dy=c.y-y;

	if(abs(dx)>c.r || abs(dy)>c.r)
	{
		return false;
	}

	double dis2=dx*dx+dy*dy;
	return (c.r*c.r>dis2);
}

//��ײ��⣺Բ����Բ��
//������c1	...	Բ��1���ṹ�壩
//		c2	...	Բ��2���ṹ�壩
bool HitTestCircles(const Circle &c1, const Circle &c2)
{
	double xx=c1.x-c2.x,	yy=c1.y-c2.y;
	double rr=c1.r+c2.r;

	if(abs(xx)>rr || abs(yy)>rr)
	{
		return false;
	}

	double dis2=xx*xx+yy*yy;
	
	return (rr*rr>=dis2);
}

//��ײ��⣺������Բ��
//������b	...	���ߣ��ṹ�壩
//		c	...	Բ�Σ��ṹ�壩
bool HitTestBeamCircle(const Beam &b,const Circle &c)
{
	
	double br=AngleToRadian(b.rotation);
	double k=tan(br);
	double g=k*c.x-c.y-k*b.x+b.y;	//ֱ��һ��ʽ��ֵ
	double d2=g*g/(k*k+1);			//Բ�ĵ�ֱ�߾���ƽ��
	if(c.r*c.r>=d2)
	{
		//ֱ����Բ�Ѿ��ཻ�������жϷ���
		double dy=c.y-b.y;
		double ss=sin(br);
		
		if((ss>0 && dy>0)||(ss<0 && dy<0))
		{
			return true;
		}
	}
	return false;
}




//���������Բ����ײ��
//������b	...	���ߣ��ṹ�壩
//		c	...	Բ�Σ��ṹ�壩
Point GetHitPoint(Beam b,Circle c)
{
	Point p;
	p.x=0;
	p.y=0;
	
	//��δ����rotation=90�����
	double brr=AngleToRadian(b.rotation);
	double k=tan(brr);//ֱ��б��
	double g=k*c.x-c.y-k*b.x+b.y;	//ֱ��һ��ʽ��ֵ
	double d=abs(g)/sqrt(k*k+1);			//Բ�ĵ�ֱ�߾���
	
	double rr=AnglePlus(b.rotation,90);		//���߽Ƕ�
	double rrr=AngleToRadian(rr);
	
	double gap=sqrt(c.r*c.r-d*d);	//�����ϻ�������

	double sign;
	if(g>0)
	{
		//yϵ��Ϊ����g>0Բ����ֱ���·���������
		sign=1;
	}
	else
	{
		sign=-1;
	}


	//��������
	double xc=c.x+sign*d*cos(rrr);
	double yc=c.y+sign*d*sin(rrr);



	if(b.x<xc)
	{
		if(cos(brr)>0)
		{
			p.x=xc-gap*cos(brr);
			p.y=yc-gap*sin(brr);
		}
		else
		{
			p.x=xc+gap*cos(brr);
			p.y=yc+gap*sin(brr);
		}
	}
	else
	{
		if(cos(brr)>0)
		{
			p.x=xc+gap*cos(brr);
			p.y=yc+gap*sin(brr);
		}
		else
		{
			p.x=xc-gap*cos(brr);
			p.y=yc-gap*sin(brr);
		}
	}

	//1.������c��Բ����b�Ĵ�����b�Ľ���
	//2.���ɶ��������һֱ�Ǳ߳���


	return p;
}



//��������֣���ʱ�䣩
void SetSeed()
{
	srand( (unsigned)time( 0 )+7); 
}


//����0-1��������ĺ���
double Random0_1(){
	//����0-1��������ĺ���
	int temp;
	double r;
	temp=rand()%1000;
	r=(double)temp/1000;
	return r;
}



//����[minv,maxv]֮���������������
int Random(int minv,int maxv)
{
	int gap=maxv-minv;
	if(maxv<=minv)
	{
		return 0;
	}
	return (minv+rand()%(gap+1));
	
}