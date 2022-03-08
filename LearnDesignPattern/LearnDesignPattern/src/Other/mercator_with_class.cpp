#include"mercator_with_class.h"
#include<iostream>
using namespace std;




//������������
int test_mercator_with_class()
{
    MercatorProj m_mp;
    double b0, l0;
    double latS, lgtS, latD, lgtD;

    b0 = 30;
    //b0 = 0;
    l0 = 0;

    latS = 60;//�������ݣ�γ��60��
    lgtS = 120;//�������ݣ�����120��
    double a = 6378137;//������
    double b = 6356752.3142;//�̰���
    m_mp.SetAB(a, b); // WGS 84
    m_mp.SetB0(DegreeToRad(b0));
    m_mp.SetL0(DegreeToRad(l0));

    m_mp.ToProj(DegreeToRad(latS), DegreeToRad(lgtS), latD, lgtD);

    cout << "X=" << latD << "	" << "Y=" << lgtD << endl;
    // 7248377.351067:11578353.630128

    latS = 123456;//��������
    lgtS = 654321;//��������

    m_mp.FromProj(latS, lgtS, latD, lgtD);
    latD = RadToDegree(latD);
    lgtD = RadToDegree(lgtD);

    cout << "B=" << latD << "	" << "L=" << lgtD << endl;
    // 1.288032: 6.781493
    system("pause");
    return 0;
}