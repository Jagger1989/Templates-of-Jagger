#ifndef TEMPLATE_DEQUE_H
#define TEMPLATE_DEQUE_H
#include "../Utility/common.h"

//vector��deque��������������
//
//��1��deque��������Ԫ�ص�Ч�ʱ�vector�������ܶࣻ
//ԭ������dequeҪ���ڴ�������ʣ���vectorֻ��ʹ��һ���ڴ�飬���ÿ��ڴ�Ĳ�����vector�����൱��һ�����Զ�̬��������顣
//��2���������������ķ���deque��vector��Ч�ʸߺܶࣻ
//deque������һ��С���ڴ�飬Ȼ�����������ڴ����������deque�ڴ������������
//vector������һ����ԭ�ȸ�������ڴ�飬��ԭvector��������ݸ��Ƶ��µĴ��ڴ�����棬Ȼ�󻹵�����ԭ��vector���ڴ�顣���ԣ����������䷽�棬deque��vector��Ч�������ڴ�������Ҳ�ߡ�
//��3��vector������������deque�Զ�������
//vector��֧�ְ�������������С�Ĳ�����С�ڵ�����������κβ�������deque��Ϊ�����кܶ�С�ڴ�����ɵģ������п��е��ڴ��ʱ�������ٿ��е��ڴ�飬������Ӱ��deque�������е����ݡ�
//
//vector��Ĭ��������ǵ��͵�ʹ�����еķ���������deque����ʹ�ò���ɾ��������ʱ����һ�����õ�ѡ��
//deque��vector����������������
//��1��c.push_front(elem) ���� ��ͷ������һ�����ݡ�
//
//��2��c.pop_front() ���� ɾ��ͷ�����ݡ�
//
//deque��vector��������������
//��1��capacity()���� ����vector��ǰ��������
//
//��2��reserve() ���� ��ָ��vector�Ĵ�С��

void testDeque()
{

    // ��vector����ǰ�˲���͵������ڴ������vector��һ����deque���������ڴ�
    std::deque<int> deq;
    deq.push_front(1);
    deq.pop_front();

}

#endif // !TEMPLATE_DEQUE_H