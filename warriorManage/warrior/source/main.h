#pragma once
#ifndef SANGUO_MAIN_H
#define SANGUO_MAIN_H
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
//�˵�����
void printDividerStar();
void printShortStar();
void printLongStar();
void printItemDot();
void printMainMenu();
void printChooseMenu();
void printMiniMenu();
//���ܺ���
void switchFunction(char chooseId);
//�佫��
class warrior {
	//��Ԫ��
	friend class warriorList;
private:
	string name;
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
	//ɾ������һ���佫��Ϣ
	void remove();
	//ɾ������佫��Ϣ
	void moreRemove();
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
	//��Χģ������
	void coverFuzzySearch();
	//ҳ����ӡ
	void pageNum();
};
//�ⲿ��������
extern warriorList war;
//�����佫
void createWarrior();
//ɾ��һ���佫
void deleteWarrior();
//Ѱ���佫
void searchWarrior();
//�佫����
void sortWarrior();
//Ѱ�ҷ�ʽ
void switchSearchFun(char chooseId);
//����ʽ
void switchSortFun(char chooseId);
//������ʽ
void switchCreateFun(char chooseId);
//ɾ����ʽ
void switchDeleteFun(char chooseId);
//��ʾ�佫
void showWarrior();
//��ӡ�佫��ͷ
void printWarriorTitle();
void printWarriorTableFoot();
//�����ͣ
void pause();
#endif
