#pragma once
#ifndef SANGUO_MAIN_H
#define SANGUO_MAIN_H
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
//菜单布局
void printDividerStar();
void printShortStar();
void printLongStar();
void printItemDot();
void printMainMenu();
void printChooseMenu();
void printMiniMenu();
//功能函数
void switchFunction(char chooseId);
//武将类
class warrior {
	//友元类
	friend class warriorList;
private:
	string name;
	int age, phy, intel, str;
	//指向下一个武将的指针
	warrior* next;
public:
	void add();
	void readFile(istream& in);
	//打印武将信息
	void display();
	//传入对象交换信息
	void swap(warrior* toExchange);
};
//武将列表类
class warriorList {
private:
	warrior* first;
	warrior* last;
	int num;
	ifstream in;
	ofstream out;

public:
	//武将列表构造函数
	warriorList();
	//构析函数
	~warriorList();
	//添加武将信息
	void add();	
	//删除表中最后一个节点
	void removeLast();	
	//删除表中一个武将信息
	void remove();
	//删除多个武将信息
	void moreRemove();
	//人名搜索
	void searchByName();
	//模糊搜索
	void fuzzySearch();
	//年龄排序
	void sortByAge();
	//体力排序
	void sortByPhy();
	//智力排序
	void sortByIntel();
	//力量排序
	void sortByStr();
	//展示武将信息
	void show();
	//保存武将信息
	void save();
	//范围模糊搜索
	void coverFuzzySearch();
	//页数打印
	void pageNum();
};
//外部对象声明
extern warriorList war;
//创建武将
void createWarrior();
//删除一个武将
void deleteWarrior();
//寻找武将
void searchWarrior();
//武将排序
void sortWarrior();
//寻找方式
void switchSearchFun(char chooseId);
//排序方式
void switchSortFun(char chooseId);
//创建方式
void switchCreateFun(char chooseId);
//删除方式
void switchDeleteFun(char chooseId);
//显示武将
void showWarrior();
//打印武将表头
void printWarriorTitle();
void printWarriorTableFoot();
//输出暂停
void pause();
#endif
