#include "main.h"
using namespace std;
//�������
void printDividerStar() {
	cout <<"************************************************************";
}
//�����
void printShortStar() {
	cout <<"*****************";
}
//�����
void printLongStar() {
	cout << "**********************";
}
//���^������
void printItemDot() {
	cout << "\t^";
}
//���������
void printMainMenu() {
	printLongStar();
	cout << "��ӭ�����佫ϵͳ";
	printLongStar();
	cout << endl;
	printItemDot();
	cout << "      MADE BY LYX IN 2019-11-16" << endl;
}
//ѡ�����
void printChooseMenu() {
	//ͷ�����
	printDividerStar();
	cout << endl;
	char chooseId;
	printLongStar();
	cout << endl;
	cout << "��ѡ�����ѡ��" << endl;
	printLongStar();
	cout << endl;
	//ѡ��ѡ��
	cout << endl;
	cout << "\t\t1 ����佫��Ϣ\t\t" << endl;
	cout << "\t\t2 ��ʾ�佫��Ϣ\t\t" << endl;
	cout << "\t\t3 �����佫��Ϣ\t\t" << endl;
	cout << "\t\t4 ��ѯ�佫��Ϣ \t\t" << endl;
	cout << "\t\t5 ɾ���佫��Ϣ\t\t" << endl;
	cout << "\t\t0 �˳�ϵͳ\t\t" << endl;
	printDividerStar();
	cout << endl;
	//�������
	printItemDot();
	cout << "����������ɵĲ���:";
	cin >> chooseId;
	printDividerStar();
	cout << endl;
	switchFunction(chooseId);
}

//С����
void printMiniMenu() {
	char chooseId;
	printDividerStar();
	cout << endl;
	printLongStar();
	cout << "��ѡ��ѡ��";
	printLongStar();
	cout << endl;

	//ѡ��ѡ��
	cout << "\t\t1 ����佫��Ϣ\t\t" << endl;
	cout << "\t\t2 ��ʾ�佫��Ϣ\t\t" << endl;
	cout << "\t\t3 �����佫��Ϣ\t\t" << endl;
	cout << "\t\t4 ��ѯ�佫��Ϣ \t\t" << endl;
	cout << "\t\t5 ɾ���佫��Ϣ\t\t" << endl;
	cout << "\t\t0 �˳�ϵͳ\t\t" << endl;
	printShortStar();
	cout << endl;
	printDividerStar();
	cout << endl;
	//�������
	printItemDot();
	cout << "����������ɵĲ���:";
	cin >> chooseId;
	switchFunction(chooseId);
}