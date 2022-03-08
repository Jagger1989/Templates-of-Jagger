#pragma once
#include<cmath>

//Բ����
const double PI = 3.1415926535897932;
//�Ƕȵ����ȵ�ת��
double DegreeToRad(double degree)
{
    return PI * ((double)degree / (double)180);
}
//���ȵ��Ƕȵ�ת��
double RadToDegree(double rad)
{
    return (180 * rad) / PI;
}

class MercatorProj
{
public:
    MercatorProj();

    void SetAB(double& a, double& b);
    void SetB0(double b0);
    void SetL0(double l0);
    int FromProj(double X, double Y, double& B, double& L);
    int ToProj(double B, double L, double &X, double &Y);

    ~MercatorProj();

private:
    int __IterativeTimes;      //����ת�������еĵ�������
    double __IterativeValue;  //����ת�������еĵ�����ʼֵ
    double __A;    //�����峤����,��
    double __B;    //������̰���,��
    double __B0; //��׼γ��,����
    double __L0; //ԭ�㾭��,����

};


//���캯���и������Ĭ��ֵ
MercatorProj::MercatorProj() :__IterativeTimes(15), __IterativeValue(0), __A(0), __B(0), __B0(0), __L0(0)
{
}
//�趨__A��__B
void MercatorProj::SetAB(double& a, double& b)//ԭ����Ĳ���д��double a, double b
{
    if (a <= 0 || b <= 0)
    {
        return;
    }
    __A = a;
    __B = b;
}
//�趨__B0
void MercatorProj::SetB0(double b0)
{
    if (b0<-PI / 2 || b0>PI / 2)
    {
        return;
    }
    __B0 = b0;//�趨��׼γ�ȣ���׼γ���ߺ�ԭ�㾭���ߵĽ��������ͶӰ���ƽ�������ԭ��
}
//�趨__L0
void MercatorProj::SetL0(double l0)
{
    if (l0<-PI || l0>PI)
    {
        return;
    }
    __L0 = l0;//�趨ԭ�㾭��
}


/*******************************************
ͶӰ����ת������
double B: ά��,����
double L: ����,����
double& X:     ����ֱ������
double& Y:      ����ֱ������
*******************************************/
int MercatorProj::ToProj(double B, double L, double &X, double &Y)
{
    double f/*����*/, e/*��һƫ����*/, e_/*�ڶ�ƫ����*/, NB0/*î��Ȧ���ʰ뾶*/, K, dtemp;
    double E = exp(1);
    if (L<-PI || L>PI || B<-PI / 2 || B>PI / 2)
    {
        return 1;
    }

    if (__A <= 0 || __B <= 0)
    {
        return 1;
    }

    f = (__A - __B) / __A;

    dtemp = 1 - (__B / __A)*(__B / __A);
    if (dtemp < 0)
    {
        return 1;
    }
    e = sqrt(dtemp);

    dtemp = (__A / __B)*(__A / __B) - 1;
    if (dtemp < 0)
    {
        return 1;
    }
    e_ = sqrt(dtemp);

    NB0 = ((__A*__A) / __B) / sqrt(1 + e_ * e_*cos(__B0)*cos(__B0)); //NB0=N, ���߳�������ز���ѧ�������ڶ����103ҳ����109��110ҳ��

    K = NB0 * cos(__B0);//ƽ��Ȧ�뾶

    Y = K * (L - __L0);

    X = K * log(tan(PI / 4 + B / 2)*pow((1 - e * sin(B)) / (1 + e * sin(B)), e / 2));

    return 0;
}
/*******************************************
ͶӰ����ת������
double X: ����ֱ������
double Y: ����ֱ������
double& B:     ά��,����
double& L:     ����,����
*******************************************/
int MercatorProj::FromProj(double X, double Y, double& B, double& L)
{
    double f/*����*/, e/*��һƫ����*/, e_/*�ڶ�ƫ����*/, NB0/*î��Ȧ���ʰ뾶*/, K, dtemp;
    double E = exp(1);

    if (__A <= 0 || __B <= 0)
    {
        return 1;
    }

    f = (__A - __B) / __A;

    dtemp = 1 - (__B / __A)*(__B / __A);
    if (dtemp < 0)
    {
        return 1;
    }
    e = sqrt(dtemp);

    dtemp = (__A / __B)*(__A / __B) - 1;
    if (dtemp < 0)
    {
        return 1;
    }
    e_ = sqrt(dtemp);

    NB0 = ((__A*__A) / __B) / sqrt(1 + e_ * e_*cos(__B0)*cos(__B0));

    K = NB0 * cos(__B0);

    L = Y / K + __L0;
    B = __IterativeValue;
    for (int i = 0; i < __IterativeTimes; i++)
    {
        B = PI / 2 - 2 * atan(pow(E, (-X / K))*pow(E, (e / 2)*log((1 - e * sin(B)) / (1 + e * sin(B)))));
    }


    return 0;
}

MercatorProj::~MercatorProj()
{
}