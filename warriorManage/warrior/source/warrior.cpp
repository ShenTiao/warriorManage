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
	cout << name << " " << age << " " << phy << " " << intel << " " << str << endl;
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
			}
		}
		//删除空节点
		war.removeLast();
		in.close();
		cout << "读取武将信息成功";
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
			cout << "武将已存在";
			return;
		}
		p = p->next;
	}
	num++;
	if (first == NULL)
	{
		first = last = t;
		cout << "武将创建成功";
		printShortStar();
		cout << endl;
		printWarriorTitle();
		last->display();
		printWarriorTableFoot();
	}
	else {
		last->next = t;
		last = last->next;
		cout << "武将创建成功";
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
		printWarriorTableFoot();
		for (int i = 0; i < foundCount; i++) {
			p[i]->display();
		}
		printWarriorTableFoot();
	}
}

//模糊搜索
void warriorList::fuzzySearch() {
	string tempKey;
	warrior* t = first;
	warrior* p[] = { NULL };
	int foundCount = 0;
	printDividerStar();
	cout << endl;
	cout << "请输入需要查找武将的关键字" << endl;
	cout << "将输出符合首部开始2个字符相同及以上的武将" << endl;
	cin >> tempKey;
	unsigned int keyLength = tempKey.size();
	while (t) {
		if (t->name[0] == tempKey[0]&&t->name[1]==tempKey[1]) {
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
		printWarriorTableFoot();
		for (int i = 0; i < foundCount; i++) {
			p[i]->display();
		}
		printWarriorTableFoot();
	}
}

//通过年龄排序
void warriorList::sortByAge() {
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

	cout << "已按年龄排序";
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

	cout << "已按体力排序";
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

	cout << "已按智力排序";
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

		cout << "已按力量排序";
		printShortStar();
		cout << endl;
		war.show();
	}
}

//显示所有武将
void warriorList::show() {
	printWarriorTableFoot();
	warrior* t = first;
	if (t) {
		for(int count=0;t!=NULL;count++){
			t->display();
			t = t->next;
			if (count % 10 == 0) {
				pause();
				printShortStar();
				cout << endl;
			}
		}
		/*while (t) {
			t->display();
			t = t->next;
		}*/
	}
	else {
		printItemDot();
		cout << "目前无武将信息";
	}
	printWarriorTableFoot();
}

//文件流保存武将
void warriorList::save() {
	warrior* t = first;
	out.open("warData.txt");
	for (; t != NULL; t = t->next)
		out << t->name << " " << t->age << " " << t->phy << " " << t->intel << " " << t->str<<'\n';
	out.close();
}

warriorList::~warriorList()
{
	save();
}

//输出暂停
void pause() {
	system("pause");
	cout << "敲击任意键将继续输出" << endl;
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
	war.remove();
}

//显示相关
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
	cout << "名字" << " " << "年龄" << " " << "体力" << " " << "智力" << " " << "力量" << endl;
}

void printWarriorTableFoot() {
	cout << "--------------------------输出结束-------------------------";
	cout << endl;
}

