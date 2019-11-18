#include "main.h"
//功能切换函数
//chooseId
void switchFunction(char chooseId) {
	switch (chooseId)
	{
	case '1':
		//创建武将信息
		createWarrior();
		break;
	case '2':
		//显示武将信息
		showWarrior();
	case '3':
		//排序武将信息
		sortWarrior();
		break;
	case '4':
		//查询武将信息
		searchWarrior();
		break;
	case '5':	
		//删除武将信息
		deleteWarrior();
		break;
	case '0': {
		//保存武将信息
		war.save();
		//退出系统
		printItemDot(); cout << "感谢使用" << endl;
		exit(0);
	}
	default:
		//输入非法
		cout << endl;
		printDividerStar();
		cout << endl;
		cout << endl;
		printItemDot();
		cout << "无此选项，请重新输入:";
		cin >> chooseId;
		switchFunction(chooseId);
			break;
	}
}
