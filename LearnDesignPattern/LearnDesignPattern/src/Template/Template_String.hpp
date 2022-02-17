#ifndef TEMPLATE_STRING_H
#define TEMPLATE_STRING_H
#include "../Utility/common.h"

#include <boost/lexical_cast.hpp>

void testString()
{
    double x = 1.1111111111111111111111f;

    std::string xS = boost::lexical_cast<std::string>(x); // û����
    std::string xT = std::to_string(x); // �����ȣ�Ӧ����float

    std::cout << xS << std::endl;
    std::cout << xT << std::endl;

    std::string str = "2.22212312312312312312";
    double strD = boost::lexical_cast<double>(str);
    std::cout << strD << std::endl;

}

void testChar()
{
    // ��ʼ��char*
    char pp[] = "asas";
    char* p = (char*)malloc(sizeof(char) * 100);
    p = pp;
    //strcpy(p, "asdfasdf");
    //strcpy(p, pp);
    printf("%s\n", p);
    delete p;

    // memset
    // ��p1(char*)��ǰp3(int)���ַ�����Ϊp2(int)
    char* ppp = (char*)malloc(sizeof(char)* 100);
    ppp = pp;
    memset(ppp, 'a', 2);
    printf("%s\n", ppp);
    puts(ppp);
    delete ppp;

    // strcpy
    char* p11 = (char*)malloc(sizeof(char) * 100);
    strcpy(p11, "12345");
    int length = (int)strlen(p11);
    printf("length = %d\n", length);
    delete p11;

    //memcpy();
    //memmove();
    //strcat();
    //strncat();

    //// ��Сд����
    //memcmp();
    //strcmp();
    //strncmp();

    //// ��Сд������
    //strcasecmp();
    //strncasecmp();

    //// �������ѯ
    //strchar();
    //strrchr();
    //strstr();

    //// �ָ��ַ���
    //strtok();
    //strtok_r();

}

#endif // !TEMPLATE_STRING_H