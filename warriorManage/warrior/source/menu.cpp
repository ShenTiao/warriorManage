#include "main.h"
using namespace std;
//输出分离
void printDividerStar() {
	cout <<"************************************************************";
}
//输出短
void printShortStar() {
	cout <<"*****************";
}
//输出长
void printLongStar() {
	cout << "**********************";
}
//输出^并对齐
void printItemDot() {
	cout << "\t^";
}
//输出主界面
void printMainMenu() {
	printLongStar();
	cout << "欢迎进入武将系统";
	printLongStar();
	cout << endl;
	printItemDot();
	cout << "      MADE BY LYX IN 2019-11-16" << endl;
}
//选项界面
void printChooseMenu() {
	//头部输出
	printDividerStar();
	cout << endl;
	char chooseId;
	printLongStar();
	cout << endl;
	cout << "请选择操作选项" << endl;
	printLongStar();
	cout << endl;
	//选项选择
	cout << endl;
	cout << "\t\t1 添加武将信息\t\t" << endl;
	cout << "\t\t2 显示武将信息\t\t" << endl;
	cout << "\t\t3 排序武将信息\t\t" << endl;
	cout << "\t\t4 查询武将信息 \t\t" << endl;
	cout << "\t\t5 删除武将信息\t\t" << endl;
	cout << "\t\t0 退出系统\t\t" << endl;
	printDividerStar();
	cout << endl;
	//输入操作
	printItemDot();
	cout << "输入你想完成的操作:";
	cin >> chooseId;
	printDividerStar();
	cout << endl;
	switchFunction(chooseId);
}

//小界面
void printMiniMenu() {
	char chooseId;
	printDividerStar();
	cout << endl;
	printLongStar();
	cout << "请选择选项";
	printLongStar();
	cout << endl;

	//选项选择
	cout << "\t\t1 添加武将信息\t\t" << endl;
	cout << "\t\t2 显示武将信息\t\t" << endl;
	cout << "\t\t3 排序武将信息\t\t" << endl;
	cout << "\t\t4 查询武将信息 \t\t" << endl;
	cout << "\t\t5 删除武将信息\t\t" << endl;
	cout << "\t\t0 退出系统\t\t" << endl;
	printShortStar();
	cout << endl;
	printDividerStar();
	cout << endl;
	//输入操作
	printItemDot();
	cout << "输入你想完成的操作:";
	cin >> chooseId;
	switchFunction(chooseId);
}