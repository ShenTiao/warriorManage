#include "main.h"
//�佫��Ӻ���
void warrior::add() {
	printItemDot();
	cout << "�����佫����:";
	cin >> name;
	//���䴦��
	int tempAge = 0;
	int tempData = 0;
	printItemDot();
	cout << "����������:";
	cin >> tempAge;
	while (tempAge < 0) {
		printLongStar();
		cout << endl;
		printItemDot();
		cout << "������������Ӧ����0,���ٴ�����:";
		cin >> tempAge;
	}
	age = tempAge;
	//��������
	printItemDot();
	cout << "����������ֵ:";
	cin >> tempData;
	while (tempData < 0) {
		printLongStar();
		cout << endl;
		printItemDot();
		cout << "����������������������:";
		cin >> tempData;
	}
	phy = tempData;
	//��������
	printItemDot();
	cout << "����������ֵ:";
	cin >> tempData;
	while (tempData < 0) {
		printLongStar();
		cout << endl;
		printItemDot();
		cout << "����������������������:";
		cin >> tempData;
	}
	intel = tempData;
	//��������
	printItemDot();
	cout << "����������ֵ:";
	cin >> tempData;
	while (tempData < 0) {
		printLongStar();
		cout << endl;
		printItemDot();
		cout << "����������������������:";
		cin >> tempData;
	}
	str = tempData;
	next = NULL;
}

//�佫�ඨ��

//�����ȡ
void warrior::readFile(istream& in){
	in >> name >> age >> phy >> intel >> str;
}

//���
void warrior::display() {
	cout << name << " " << age << " " << phy << " " << intel << " " << str << endl;
}

//�봫����󽻻���Ϣ ���ڼ�����ʱ����
void warrior::swap(warrior* toExchange) {
	string tempName;
	int tempAge, tempPhy, tempIntel, tempStr;
	tempName = name; name = toExchange->name; toExchange->name = tempName;
	tempAge = age; age = toExchange->age; toExchange->age = tempAge;
	tempPhy = phy; phy = toExchange->phy; toExchange->phy = tempPhy;
	tempIntel = intel; intel = toExchange->intel; toExchange->intel = tempIntel;
	tempStr = str; str = toExchange->str; toExchange->str = tempStr;
}

//�佫������
warriorList::warriorList() {
	//���佫�����ļ�
	in.open("warData.txt");
	//�����ļ�
	if (!in) {
		cout << "Ŀǰ���佫��Ϣ���������佫��Ϣ��ʹ��";
		printShortStar();
		cout << endl;
		first = NULL;
		last = NULL;
		num = 0;
	}
	else {
		//�����佫����
		first = new warrior;
		last = first;
		num = 0;
		//���ݶ�ȡ
		while (!in.eof()) {
			last->readFile(in);
			//���ݶ�ȡ���� ʣ��һ���սڵ�
			if (last->name[0] != NULL) {
				last->next = new warrior;
				last = last->next;
			}
		}
		//ɾ���սڵ�
		war.removeLast();
		in.close();
		cout << "��ȡ�佫��Ϣ�ɹ�";
		printShortStar();
		cout << endl;
	}
}

//ͨ����������佫��Ϣ
void warriorList::add() {
	warrior* t = new warrior;
	t->add();
	warrior* p = first;
	while (p) {
		if (p->name == t->name) {
			printItemDot();
			cout << "�佫�Ѵ���";
			return;
		}
		p = p->next;
	}
	num++;
	if (first == NULL)
	{
		first = last = t;
		cout << "�佫�����ɹ�";
		printShortStar();
		cout << endl;
		printWarriorTitle();
		last->display();
		printWarriorTableFoot();
	}
	else {
		last->next = t;
		last = last->next;
		cout << "�佫�����ɹ�";
		printShortStar();
		cout << endl;
		printWarriorTitle();
		last->display();
		printWarriorTableFoot();
	}
}

//ɾ�����һ���ڵ�
void warriorList::removeLast() {
	//ɾ���սڵ�
	warrior* p = first;
	
	while (p->next->next != NULL) {
		p = p->next;
	}
	free(p->next);
	p->next = NULL;
	last = p;
}

//ͨ������ɾ���佫
void warriorList::remove() {
	string tempName;
	printItemDot();
	cout << "������Ҫɾ�����佫����";
	cin >> tempName;
	warrior* t = first;
	warrior* p = NULL;
	while (t) {
		if (t->name == tempName)
			break;
		p = t;
		t = t->next;
	}
	//t���Ϊ��
	if (!t) {
		printItemDot();
		cout << "δ�ҵ�Ӧɾ�����佫";
		return;
	}
	//��һ����Ҫɾ�����佫
	if (!p) {
		first = first->next;
		printItemDot();
		cout << "�ɹ�ɾ��" << tempName << endl;
		delete t;
	}
	else {
		//��t����һ����ַ��p��������
		p->next = t->next;
		printItemDot();
		cout << "�ɹ�ɾ��" <<tempName<< endl;
		delete t;
	}
	num--;//���佫��������
}

//ͨ�����������佫
void warriorList::searchByName() {
	string tempName;
	warrior* t = first;
	warrior* p[] = { NULL };
	int foundCount = 0;
	printDividerStar();
	cout << endl;
	printItemDot();
	cout << "����Ҫ���ҵ��佫����:";
	cin >> tempName;
	while (t) {
		if (t->name == tempName) {
			p[foundCount] = t;
			foundCount++;
		}
		t = t->next;
	}
	
	//t�����Ϊ��
	if (!p[0]) {
		printItemDot();
		cout << "δ���ҵ��佫" << endl;
		return;
	}
	else {
		cout << "�Ѳ�ѯ���佫";
		printShortStar();
		cout << endl;
		printWarriorTableFoot();
		for (int i = 0; i < foundCount; i++) {
			p[i]->display();
		}
		printWarriorTableFoot();
	}
}

//ģ������
void warriorList::fuzzySearch() {
	string tempKey;
	warrior* t = first;
	warrior* p[] = { NULL };
	int foundCount = 0;
	printDividerStar();
	cout << endl;
	cout << "��������Ҫ�����佫�Ĺؼ���" << endl;
	cout << "����������ײ���ʼ2���ַ���ͬ�����ϵ��佫" << endl;
	cin >> tempKey;
	unsigned int keyLength = tempKey.size();
	while (t) {
		if (t->name[0] == tempKey[0]&&t->name[1]==tempKey[1]) {
			p[foundCount] = t;
			foundCount++;
		}
		t = t->next;
	}

	//t�����Ϊ��
	if (!p[0]) {
		printItemDot();
		cout << "δ���ҵ��佫" << endl;
		return;
	}
	else {
		cout << "�Ѳ�ѯ���佫";
		printShortStar();
		cout << endl;
		printWarriorTableFoot();
		for (int i = 0; i < foundCount; i++) {
			p[i]->display();
		}
		printWarriorTableFoot();
	}
}

//ͨ����������
void warriorList::sortByAge() {
	warrior* t = first;
	warrior* p = NULL;

	//�����ݺ���˳�
	if (t == NULL) {
		printItemDot();
		cout << "���佫����" << endl;
		return;
	}

	//���� ��ѡ������
	for (; t->next != NULL; t = t->next) {
		for (p = t->next; p != NULL; p = p->next) {
			if (p->age > t->age) {
				p->swap(t);
			}
		}
	}

	cout << "�Ѱ���������";
	printShortStar();
	cout << endl;
	war.show();
}

//ͨ����������
void warriorList::sortByPhy() {
	warrior* t = first;
	warrior* p = NULL;

	//�����ݺ���˳�
	if (t == NULL) {
		printItemDot();
		cout << "���佫����" << endl;
		return;
	}

	//���� ��ѡ������
	for (; t->next != NULL; t = t->next) {
		for (p = t->next; p != NULL; p = p->next) {
			if (p->phy > t->phy) {
				p->swap(t);
			}
		}
	}

	cout << "�Ѱ���������";
	printShortStar();
	cout << endl;
	war.show();
}

//ͨ����������
void warriorList::sortByIntel() {
	warrior* t = first;
	warrior* p = NULL;

	//�����ݺ���˳�
	if (t == NULL) {
		printItemDot();
		cout << "���佫����" << endl;
		return;
	}

	//���� ��ѡ������
	for (; t->next != NULL; t = t->next) {
		for (p = t->next; p != NULL; p = p->next) {
			if (p->intel > t->intel) {
				p->swap(t);
			}
		}
	}

	cout << "�Ѱ���������";
	printShortStar();
	cout << endl;
	war.show();
}

//ͨ����������
void warriorList::sortByStr() {
	warrior* t = first;
	warrior* p = NULL;

	//�����ݺ���˳�
	if (t == NULL) {
		printItemDot();
		cout << "���佫����" << endl;
		return;
	}

	//���� ��ѡ������
	for (; t->next != NULL; t = t->next) {
		for (p = t->next; p != NULL; p = p->next) {
			if (p->str > t->str) {
				p->swap(t);
			}
		}

		cout << "�Ѱ���������";
		printShortStar();
		cout << endl;
		war.show();
	}
}

//��ʾ�����佫
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
		cout << "Ŀǰ���佫��Ϣ";
	}
	printWarriorTableFoot();
}

//�ļ��������佫
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

//�����ͣ
void pause() {
	system("pause");
	cout << "�û���������������" << endl;
}

//����佫���
void createWarrior() {
	cout << "�������";
	printShortStar();
	cout << endl;
	war.add();
}

//ɾ�����
void deleteWarrior() {
	war.remove();
}

//��ʾ���
void showWarrior() {
	cout << "��ʾ�����佫��Ϣ";
	printShortStar();
	cout << endl;
	war.show();
}

//�����߼�
void sortWarrior() {
	char chooseId;
	cout << "ѡ���������";
	cout << endl;
	printShortStar();
	cout << endl;
	cout << "1.ͨ����������" << endl;
	cout << "2.ͨ����������" << endl;
	cout << "3.ͨ����������" << endl;
	cout << "4.ͨ����������" << endl;
	printLongStar();
	cout << endl;
	cout << "��ѡ������ʽ" << endl;
	cin >> chooseId;
	switchSortFun(chooseId);
}

//Ѱ���߼�
void searchWarrior() {
	printShortStar();
	cout << "ѡ����β���" << endl;
	char chooseId;
	cout << "1.��׼����" << endl;
	cout << "2.ģ������" << endl;
	printLongStar();
	cout << endl;
	cout << "��ѡ��" << endl;
	cin >> chooseId;
	switchSearchFun(chooseId);
}

//Ѱ������
void switchSearchFun(char chooseId)
{
	switch (chooseId)
	{
	case '1':
		//�����ֲ���
		war.searchByName();
		break;
	case '2':
		war.fuzzySearch();
		break;
	default:
		printItemDot();
		cout << "δ��ɹ��ܻ�δ֪ѡ��";
		cin >> chooseId;
		switchSearchFun(chooseId);
	}
}
//�л�����
void switchSortFun(char chooseId) {
	switch (chooseId)
	{
	case '1':
		//������
		war.sortByAge();
		break;
	case '2':
		//����
		war.sortByPhy();
		break;
		//����
	case '3':
		war.sortByIntel();
		break;
		//��������
	case '4':
		war.sortByStr();
		break;
	default:
		printItemDot();
		cout << "��ѡ��" << endl;
		cin >> chooseId;
		switchSortFun(chooseId);
	}
}

void printWarriorTitle() {
	cout << endl;
	cout << "--------------------------�佫�б�-------------------------" << endl;
	cout << "����" << " " << "����" << " " << "����" << " " << "����" << " " << "����" << endl;
}

void printWarriorTableFoot() {
	cout << "--------------------------�������-------------------------";
	cout << endl;
}

