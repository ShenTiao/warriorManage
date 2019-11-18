#pragma once
#ifndef SANGUO_MAIN_H
#define SANGUO_MAIN_H
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <conio.h>
using namespace std;
//�˵�����
void printDividerStar();
void printShortStar();
void printLongStar();
void printItemDot();
void printMainMenu();
void printChoosMenu();
void printMiniMenu();
//���ܺ���
void switchFunction(char chooseId);
//�佫��
class warrior {
	//��Ԫ�����˽�б���
	friend class warriorList;
private:
	string name;
	string id;
	int age, phy, intel, str;
	//ָ����һ���佫��ָ��
	warrior* next;
public:
	void add();
	void readFile(istream& in);
	//��ӡ�佫��Ϣ
	void display();
	//������󽻻���Ϣ
	void swap(warrior* toExchange);
};
//�佫�б���
class warriorList {
private:
	warrior* first;
	warrior* last;
	int num;
	ifstream in;
	ofstream out;

public:
	//�佫�б��캯��
	warriorList();
	//��������
	~warriorList();
	//����佫��Ϣ
	void add();	
	//ɾ���������һ���ڵ�
	void removeLast();	
	//ɾ�������佫��Ϣ
	void remove();
	//��������
	void searchByName();
	//ģ������
	void fuzzySearch();
	//��������
	void sortByAge();
	//��������
	void sortByPhy();
	//��������
	void sortByIntel();
	//��������
	void sortByStr();
	//չʾ�佫��Ϣ
	void show();
	//�����佫��Ϣ
	void save();
};
//�ⲿ��������
extern warriorList war;
//�����佫
void createWarrior();
//ɾ���佫
void deleteWarrior();
//Ѱ���佫
void searchWarrior();
//�佫����
void sortWarrior();
//Ѱ�ҷ�ʽ
void switchSearchFun(char chooseWayId);
//����ʽ
void switchSortFun(char chooseWayId);
//��ʾ�佫
void showWarrior();
//��ӡ�佫��ͷ
void printWarriorTitle();
void printWarriorTableFoot();
//�����ͣ
void pause();
#endif
