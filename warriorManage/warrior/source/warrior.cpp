#include "main.h"
//武将添加函数
void warrior::add() {
	printItemDot();
	cout << "输入武将名字:";
	cin >> name;
	//年龄处理
	int tempAge = 0;
	int tempData = 0;
	printItemDot();
	cout << "请输入年龄:";
	cin >> tempAge;
	while (tempAge < 0) {
		printLongStar();
		cout << endl;
		printItemDot();
		cout << "年龄输入有误，应大于0,请再次输入:";
		cin >> tempAge;
	}
	age = tempAge;
	//体力处理
	printItemDot();
	cout << "请输入体力值:";
	cin >> tempData;
	while (tempData < 0) {
		printLongStar();
		cout << endl;
		printItemDot();
		cout << "体力输入有误，请重新输入:";
		cin >> tempData;
	}
	phy = tempData;
	//智力处理
	printItemDot();
	cout << "请输入智力值:";
	cin >> tempData;
	while (tempData < 0) {
		printLongStar();
		cout << endl;
		printItemDot();
		cout << "智力输入有误，请重新输入:";
		cin >> tempData;
	}
	intel = tempData;
	//力量处理
	printItemDot();
	cout << "请输入力量值:";
	cin >> tempData;
	while (tempData < 0) {
		printLongStar();
		cout << endl;
		printItemDot();
		cout << "力量输入有误，请重新输入:";
		cin >> tempData;
	}
	str = tempData;
	next = NULL;
}

//武将类定义

//输入读取
void warrior::readFile(istream& in){
	in >> name >> age >> phy >> intel >> str;
}

//输出
void warrior::display() {
	cout << name << "\t" << age << "\t" << phy << "\t" << intel << "\t" << str << endl;
}

//与传入对象交换信息 用于简单排序法时交换
void warrior::swap(warrior* toExchange) {
	string tempName;
	int tempAge, tempPhy, tempIntel, tempStr;
	tempName = name; name = toExchange->name; toExchange->name = tempName;
	tempAge = age; age = toExchange->age; toExchange->age = tempAge;
	tempPhy = phy; phy = toExchange->phy; toExchange->phy = tempPhy;
	tempIntel = intel; intel = toExchange->intel; toExchange->intel = tempIntel;
	tempStr = str; str = toExchange->str; toExchange->str = tempStr;
}

//武将链表构造
warriorList::warriorList() {
	//打开武将储存文件
	in.open("warData.txt");
	//若无文件
	if (!in) {
		cout << "目前无武将信息，请输入武将信息后使用";
		printShortStar();
		cout << endl;
		first = NULL;
		last = NULL;
		num = 0;
	}
	else {
		//若有武将数据
		first = new warrior;
		last = first;
		num = 0;
		//数据读取
		while (!in.eof()) {
			last->readFile(in);
			//数据读取结束 剩余一个空节点
			if (last->name[0] != NULL) {
				last->next = new warrior;
				last = last->next;
				num++;
			}
		}
		//删除空节点
		war.removeLast();
		in.close();
		cout << "读取武将信息成功";
		cout << endl;
		printShortStar();
		cout << endl;
	}
}

//通过名字添加武将信息
void warriorList::add() {
	warrior* t = new warrior;
	t->add();
	warrior* p = first;
	while (p) {
		if (p->name == t->name) {
			printItemDot();
			cout << "武将已存在" << endl;
			return;
		}
		p = p->next;
	}
	num++;
	if (first == NULL)
	{
		first = last = t;
		cout << "武将创建成功" << endl;
		printShortStar();
		cout << endl;
		printWarriorTitle();
		last->display();
		printWarriorTableFoot();
	}
	else {
		last->next = t;
		last = last->next;
		cout << "武将创建成功" << endl;
		printShortStar();
		cout << endl;
		printWarriorTitle();
		last->display();
		printWarriorTableFoot();
	}
}

//删除最后一个节点
void warriorList::removeLast() {
	//删除空节点
	warrior* p = first;
	
	while (p->next->next != NULL) {
		p = p->next;
	}
	free(p->next);
	p->next = NULL;
	last = p;
}

//通过名字删除武将
void warriorList::remove() {
	string tempName;
	printItemDot();
	cout << "请输入要删除的武将姓名";
	cin >> tempName;
	warrior* t = first;
	warrior* p = NULL;
	while (t) {
		if (t->name == tempName)
			break;
		p = t;
		t = t->next;
	}
	//t最后为空
	if (!t) {
		printItemDot();
		cout << "未找到应删除的武将";
		cout << endl;
		return;
	}
	//第一个是要删除的武将
	if (!p) {
		first = first->next;
		printItemDot();
		cout << "成功删除" << tempName << endl;
		delete t;
	}
	else {
		//把t的下一个地址给p继续查找
		p->next = t->next;
		printItemDot();
		cout << "成功删除" <<tempName<< endl;
		delete t;
	}
	num--;//总武将个数减少
}

//批量删除
void warriorList::moreRemove() {
	printDividerStar();
	cout << endl;
	cout << "当前为批量删除" << endl;
	int numDelet;
	cout << "请输入要删除的武将数量" << endl;
	cin >> numDelet;
	while (numDelet != 0) {
		string tempName;
		cout << "请输入武将姓名:";
		cin >> tempName;
		warrior* t = first;
		warrior* p = NULL;
		while (t) {
			if (t->name == tempName)
				break;
			p = t;
			t = t->next;
		}
		//t最后为空
		if (!t) {
			printItemDot();
			cout << "未找到应删除的武将";
			cout << endl;
			return;
		}
//第一个是要删除的武将
if (!p) {
	first = first->next;
	printItemDot();
	cout << "成功删除" << tempName << endl;
	delete t;
}
else {
	//把t的下一个地址给p继续查找
	p->next = t->next;
	printItemDot();
	cout << "成功删除" << tempName << endl;
	delete t;
}
num--;//总武将个数减少
numDelet--;//要删除总数减少
	}
}

//通过名字搜索武将
void warriorList::searchByName() {
	string tempName;
	warrior* t = first;
	warrior* p[] = { NULL };
	int foundCount = 0;
	printDividerStar();
	cout << endl;
	printItemDot();
	cout << "输入要查找的武将姓名:";
	cin >> tempName;
	while (t) {
		if (t->name == tempName) {
			p[foundCount] = t;
			foundCount++;
		}
		t = t->next;
	}

	//t到最后为空
	if (!p[0]) {
		printItemDot();
		cout << "未能找到武将" << endl;
		return;
	}
	else {
		cout << "已查询到武将";
		printShortStar();
		cout << endl;
		printWarriorTitle();
		for (int i = 0; i < foundCount; i++) {
			p[i]->display();
		}
		printWarriorTableFoot();
	}
}

//模糊搜索
void warriorList::fuzzySearch() {
	warrior* t = first;
	warrior* p[9999] = { NULL };
	int foundCount = 0;
	cout << "请输入需要模糊查找的方式" << endl;
	cout << "1.通过智力查找" << endl;
	cout << "2.通过体力查找" << endl;
	cout << "3.通过年龄查找" << endl;
	cout << "4.通过力量查找" << endl;
	int chooseWay; cin >> chooseWay;
	int max, min = 0;
	if (chooseWay == 1) {
		int foundCount = 0;
		cout << "请输入范围最大与最小值" << endl;
		cout << "最大值:"; cin >> max;
		cout << "最小值:"; cin >> min;
		printDividerStar();
		cout << endl;
		while (t) {
			if ((t->intel) <=max &&( t->intel) >= min) {
				p[foundCount] = t;
				foundCount++;
				t = t->next;
			}
			else {
				t = t->next;
			}
		}

		//t到最后为空
		if (!p[0]) {
			printItemDot();
			cout << "未能找到武将" << endl;
			return;
		}
		else {
			cout << "已查询到武将"<<endl;
			printShortStar();
			cout << endl;
			printWarriorTitle();
			for (int i = 0; i < foundCount; i++) {
				p[i]->display();
			}
			printWarriorTableFoot();
		}
	}
	else if (chooseWay == 2) {
		int foundCount = 0;
		cout << "请输入范围最大与最小值" << endl;
		cout << "最大值:"; cin >> max;
		cout << "最小值:"; cin >> min;
		printDividerStar();
		cout << endl;
		while (t) {
			if ((t->phy) <= max &&( t->phy) >= min) {
				p[foundCount] = t;
				foundCount++;
				t = t->next;
			}
			else {
				t = t->next;
			}
		}

		//t到最后为空
		if (!p[0]) {
			printItemDot();
			cout << "未能找到武将" << endl;
			return;
		}
		else {
			cout << "已查询到武将"<<endl;
			printShortStar();
			cout << endl;
			printWarriorTitle();
			for (int i = 0; i < foundCount; i++) {
				p[i]->display();
			}
			printWarriorTableFoot();
		}
	}
	else if (chooseWay == 3) {
		int foundCount = 0;
		cout << "请输入范围最大与最小值" << endl;
		cout << "最大值:"; cin >> max;
		cout << "最小值:"; cin >> min;
		printDividerStar();
		cout << endl;
		while (t) {
			if ((t->age )<= max &&( t->age) >= min) {
				p[foundCount] = t;
				foundCount++;
				t = t->next;
			}
			else {
				t = t->next;
			}
		}

		//t到最后为空
		if (!p[0]) {
			printItemDot();
			cout << "未能找到武将" << endl;
			return;
		}
		else {
			cout << "已查询到武将" << endl;
			printShortStar();
			cout << endl;
			printWarriorTitle();
			for (int i = 0; i < foundCount; i++) {
				p[i]->display();
			}
			printWarriorTableFoot();

		}
	}
	else if (chooseWay == 4) {
	int foundCount = 0;
		cout << "请输入范围最大与最小值" << endl;
		cout << "最大值:"; cin >> max;
		cout << "最小值:"; cin >> min;
		printDividerStar();
		cout << endl;
		while (t) {
			if ((t->str)<= max &&( t->str) >= min) {
				p[foundCount] = t;
				foundCount++;
				t = t->next;
			}
			else
			{
				t = t->next;
			}
		}

		//t到最后为空
		if (!p[0]) {
			printItemDot();
			cout << "未能找到武将" << endl;
			return;
		}
		else {
			cout << "已查询到武将";
			printShortStar();
			cout << endl;
			printWarriorTitle();
			for (int i = 0; i < foundCount; i++) {
				p[i]->display();
			}
			printWarriorTableFoot();
		}
	}
}

//通过年龄排序
void warriorList::sortByAge(){
	warrior* t = first;
	warrior* p = NULL;

	//无数据后的退出
	if (t == NULL) {
		printItemDot();
		cout << "无武将数据" << endl;
		return;
	}

	//链表 简单选择排序法
	for (; t->next != NULL; t = t->next) {
		for (p = t->next; p != NULL; p = p->next) {
			if (p->age > t->age) {
				p->swap(t);
			}
		}
	}

	cout << "已按年龄排序"<<endl;
	printShortStar();
	cout << endl;
	war.show();
}

//通过体力排序
void warriorList::sortByPhy() {
	warrior* t = first;
	warrior* p = NULL;

	//无数据后的退出
	if (t == NULL) {
		printItemDot();
		cout << "无武将数据" << endl;
		return;
	}

	//链表 简单选择排序法
	for (; t->next != NULL; t = t->next) {
		for (p = t->next; p != NULL; p = p->next) {
			if (p->phy > t->phy) {
				p->swap(t);
			}
		}
	}

	cout << "已按体力排序"<<endl;
	printShortStar();
	cout << endl;
	war.show();
}

//通过智力排序
void warriorList::sortByIntel() {
	warrior* t = first;
	warrior* p = NULL;

	//无数据后的退出
	if (t == NULL) {
		printItemDot();
		cout << "无武将数据" << endl;
		return;
	}

	//链表 简单选择排序法
	for (; t->next != NULL; t = t->next) {
		for (p = t->next; p != NULL; p = p->next) {
			if (p->intel > t->intel) {
				p->swap(t);
			}
		}
	}

	cout << "已按智力排序"<<endl;
	printShortStar();
	cout << endl;
	war.show();
}

//通过力量排序
void warriorList::sortByStr() {
	warrior* t = first;
	warrior* p = NULL;

	//无数据后的退出
	if (t == NULL) {
		printItemDot();
		cout << "无武将数据" << endl;
		return;
	}

	//链表 简单选择排序法
	for (; t->next != NULL; t = t->next) {
		for (p = t->next; p != NULL; p = p->next) {
			if (p->str > t->str) {
				p->swap(t);
			}
		}
	}
		cout << "已按力量排序" << endl;
		printShortStar();
		cout << endl;
		war.show();
}

//显示所有武将
void warriorList::show() {
	printWarriorTableFoot();
	LASTSTEP:
	warrior* t = first;
	int conut_loop = 0;
	if (t) {
		pageNum();
		cout << "目前武将数量:" << num << endl;
		int chooseWay;
		cout << "请输入您要浏览的页码:";
		cin >> chooseWay;
		printLongStar();
		cout << endl;
		cout << "您正在浏览第" << chooseWay << "页武将信息" << endl;
		printWarriorTitle();
		cout << endl;
		int count_choose = (chooseWay-1 )* 10;
		while (count_choose != 0) {
			t = t->next;
			count_choose--;
		}
		for (int count = 1; count<=10; count++) {
			if (t != NULL) {
				t->display();
				t = t->next;
			}
			if (count == 10)
			{
				pause();
				int chooseID;
				printLongStar();
				cout << endl;
				cout << "请选择选项" << endl;
				cout << "1.继续输出武将" << endl;
				cout << "2.退出" << endl;
				cout << "输入："; 
				cin >> chooseID;
				if (chooseID == 1) {
					goto LASTSTEP;
				}
				if (chooseID == 2) {
					break;
				}
				else {
					cout << "非法输入" << endl;
					break;
				}
				}
			}
	}
	else {
		printItemDot();
		cout << "目前无武将信息";
	}
	printWarriorTableFoot();
	cout << endl;
	printChooseMenu();
}

//文件流保存武将
void warriorList::save() {
	warrior* t = first;
	out.open("warData.txt");
	for (; t != NULL; t = t->next)
		out << t->name << "\t" << t->age << "\t" << t->phy << "\t" << t->intel << "\t" << t->str<<'\n';
	out.close();
}

//页数打印
void warriorList::pageNum() {
	int pageNum;
	pageNum = num / 10+1;
	cout << "当前共" << pageNum << "页" << endl;
}

warriorList::~warriorList()
{
	save();
}

//输出暂停
void pause() {
	system("pause");
}

//添加武将相关
void createWarrior() {
	cout << "正在添加";
	printShortStar();
	cout << endl;
	war.add();
}

//删除相关
void deleteWarrior() {
	char chooseId;
	printShortStar();
	cout << endl;
	cout << "请选择删除方式" << endl;
	printShortStar();
	cout << endl;
	cout << "1.精准删除" << endl;
	cout << "2.批量删除" << endl;
	cin >> chooseId;
	switchDeleteFun(chooseId);
}

//显示相关(gai
void showWarrior() {
	cout << "显示所有武将信息";
	printShortStar();
	cout << endl;
	war.show();
}

//排序逻辑
void sortWarrior() {
	char chooseId;
	cout << "选择如何排序";
	cout << endl;
	printShortStar();
	cout << endl;
	cout << "1.通过年龄排序" << endl;
	cout << "2.通过体力排序" << endl;
	cout << "3.通过智力排序" << endl;
	cout << "4.通过力量排序" << endl;
	printLongStar();
	cout << endl;
	cout << "请选择排序方式" << endl;
	cin >> chooseId;
	switchSortFun(chooseId);
}

//寻找逻辑
void searchWarrior() {
	printShortStar();
	cout << "选择如何查找" << endl;
	char chooseId;
	cout << "1.精准查找" << endl;
	cout << "2.模糊查找" << endl;
	printLongStar();
	cout << endl;
	cout << "请选择" << endl;
	cin >> chooseId;
	switchSearchFun(chooseId);
}

//删除排序
void switchDeleteFun(char choosId) {
	switch (choosId)
	{
	case '1':
		//名字删除
		war.remove();
		break;
	case '2':
		//批量删除
		war.moreRemove();
		break;
	default:
		cout << "错误输入" << endl;
		cout << "请重新输入" << endl;
		cin >> choosId;
		switchDeleteFun(choosId);
	}
}

//寻找排序
void switchSearchFun(char chooseId)
{
	switch (chooseId)
	{
	case '1':
		//按名字查找
		war.searchByName();
		break;
	case '2':
		//关键字模糊搜索
		war.fuzzySearch();
		break;
	default:
		printItemDot();
		cout << "未完成功能或未知选择";
		cin >> chooseId;
		switchSearchFun(chooseId);
	}
}

//切换排序
void switchSortFun(char chooseId) {
	switch (chooseId)
	{
	case '1':
		//按年龄
		war.sortByAge();
		break;
	case '2':
		//体力
		war.sortByPhy();
		break;
		//智力
	case '3':
		war.sortByIntel();
		break;
		//力量排序
	case '4':
		war.sortByStr();
		break;
	default:
		printItemDot();
		cout << "无选项" << endl;
		cin >> chooseId;
		switchSortFun(chooseId);
	}
}

void printWarriorTitle() {
	cout << endl;
	cout << "--------------------------武将列表-------------------------" << endl;
	cout << "名字" << "\t" << "年龄" << "\t" << "体力" << "\t" << "智力" << "\t" << "力量" << endl;
}

void printWarriorTableFoot() {
	cout << endl;
	cout << "--------------------------输出结束-------------------------";
	cout << endl;
}

