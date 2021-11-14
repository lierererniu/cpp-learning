#include<iostream>
#include<string>
using namespace std;
#define MAX 1000 //最大人数

struct Person
{
	string m_name;
	int m_Sex;//1男，2女
	int m_Age;
	string m_Phone;
	string m_Addr;
};
struct Addressbooks
{
	struct Person personArray[MAX];
	int m_size; //通讯录人员个数
};


void showmenu()
{	
	
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}
void addPerson(Addressbooks * abs)
{
	if (abs->m_size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_name = name;
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "输入有误请重新输入:"<<endl;
			}
		}
		int age = 0;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[abs->m_size].m_Age = age;
		
		string phone;
		cout << "请输入电话：" << endl;
		cin >> phone;
		abs->personArray[abs->m_size].m_Phone = phone;

		string address;
		cout << "请输入家庭住址：" << endl;
		cin >> address;
		abs->personArray[abs->m_size].m_Addr = address;

		//更新通讯录人数
		abs->m_size++;
		cout << "添加成功" << endl;
		system("pause");//请按任意键继续
		system("cls");
	}
}

void showPerson(Addressbooks * abs)
{
	if (abs->m_size == 0)
	{
		cout << "当前的通讯录为空。" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++) {
			
			cout << "姓名：" << abs->personArray[i].m_name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex == 1? "男":"女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "地址：" << abs->personArray[i].m_Addr << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << endl;
		}
	}
	system("pause");//请按任意键继续
	system("cls");
}

int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_size; i++) {
		if (abs->personArray[i].m_name == name) {
			return i;
		}
	}
	return -1;
}

void delPerson(Addressbooks * abs)
{
	cout << "请输入您要删除的联系人：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//删除李四，将李四后的数据向前移动，并且让通讯录中记录的人员个数-1.
		for (int i = ret; i < abs->m_size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
			abs->m_size--;
		}
		cout << "删除成功" << endl;
	}

	else
	{
		cout<<"查无此人。"<<endl;
	}
	system("pause");//请按任意键继续
	system("cls");
}

void findPerson(Addressbooks* abs)
{
	cout << "请输入您要查找的联系人:" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].m_name << "\t";
		cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "地址：" << abs->personArray[ret].m_Addr << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << endl;
	}
	else
	{
		cout << "查无此人,请重新查询。" << endl;
	}
	system("pause");//请按任意键继续
	system("cls");
}

void modifyPerson(Addressbooks * abs)
{
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_name = name;
		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else
			{
				cout << "输入有误请重新输入:" << endl;
			}
		}
		int age = 0;
		cout << "请输入年龄：" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		string phone;
		cout << "请输入电话：" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		string address;
		cout << "请输入家庭住址：" << endl;
		cin >> address;
		abs->personArray[ret].m_Addr = address;

		cout << "修改成功" << endl;
		system("pause");//请按任意键继续
		system("cls");
	}
}


void cleanPerson(Addressbooks* abs)
{
	abs->m_size = 0;
	cout << "联系人已经清空。" << endl;
	system("pause");//请按任意键继续
	system("cls");
}


int main()
{
	Addressbooks abs;
	//初始化通讯录中当前人员个数
	abs.m_size = 0;
	int select = 0;
	while (true)
	{
		showmenu();
		cin >> select;
		switch (select)
		{
		case 1://添加联系人
			addPerson(&abs);

			break;
		case 2://2、显示联系人
			showPerson(&abs);
			break;
		case 3://3、删除联系人
		{
			delPerson(&abs);
		}
			break;
		case 4://查找联系人
			findPerson(&abs);
			break;
		case 5://修改联系人
			modifyPerson(&abs);
			break;
		case 6://清空联系人
			cleanPerson(&abs);
			break;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
		case 0:
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	}
	showmenu();
	system("pause");
	return 0;
}