#include "main.h"
//�����л�����
//chooseId
void switchFunction(char chooseId) {
	switch (chooseId)
	{
	case '1':
		//�����佫��Ϣ
		createWarrior();
		break;
	case '2':
		//��ʾ�佫��Ϣ
		showWarrior();
	case '3':
		//�����佫��Ϣ
		sortWarrior();
		break;
	case '4':
		//��ѯ�佫��Ϣ
		searchWarrior();
		break;
	case '5':	
		//ɾ���佫��Ϣ
		deleteWarrior();
		break;
	case '0': {
		//�����佫��Ϣ
		war.save();
		//�˳�ϵͳ
		printItemDot(); cout << "��лʹ��" << endl;
		exit(0);
	}
	default:
		//����Ƿ�
		cout << endl;
		printDividerStar();
		cout << endl;
		cout << endl;
		printItemDot();
		cout << "�޴�ѡ�����������:";
		cin >> chooseId;
		switchFunction(chooseId);
			break;
	}
}
