//# 封装函数显示通讯录界面；


#include <iostream>
#include <string>
using namespace std;

//显示菜单界面
void showMenu() {
    cout << "1.添加联系人" << endl;
    cout << "2.显示联系人" << endl;
    cout << "3.删除联系人" << endl;
    cout << "4.查找联系人" << endl;
    cout << "5.修改联系人" << endl;
    cout << "6.清空联系人" << endl;
    cout << "0.退出通讯录" << endl;
}

//功能1：添加联系人
//  设计联系人结构体
//  设计通讯录结构体
//  main函数中创建通讯录
//  封装添加联系人函数
//  测试添加联系人功能

//设计联系人结构体
typedef struct person {
    string name;
    int sex;//1.男，2女
    int age;
    string phone;
    string address;
}person;

//设计通讯录结构体
#define MAX 1000
typedef struct contact {
    person personArray[MAX];
    int size;
}contact;

//1.添加联系人
void addPerson(contact * book) {
    //添加联系人，创建联系人结构体变量
    person newPerson;
    if (book->size == MAX)
        cout << "通讯录已满，无法添加！" << endl;
    else {
        //添加联系人姓名
        cout << "请输入联系人姓名：";
        cin >> book->personArray[book->size].name;
        //添加联系人性别
        cout << "请输入联系人性别（1：男 2：女）：";
        cin >> book->personArray[book->size].sex;
        //添加联系人年龄
        cout << "请输入联系人年龄：";
        cin >> book->personArray[book->size].age;
        //添加联系人电话
        cout << "请输入联系人电话：";
        cin >> book->personArray[book->size].phone;
        //添加联系人地址
        cout << "请输入联系人地址：";
        cin >> book->personArray[book->size].address;
        //book->personArray[book->size] = newPerson;
        book->size++;
    }
    system("pause");
    system("cls");
}

//2.显示联系人
void showPerson(contact* book) {
    if (book->size == 0)
        cout << "联系人为空！" << endl;
    else
        for (int i = 0; i < book->size; i++) {
            //show(book->personArray[i]);
            cout << endl;
            cout << "姓名：" << book->personArray[i].name << "\t";
            cout << "性别：" << (book->personArray[i].sex == 1?"男":"女") << "\t";
            cout << "年龄：" << book->personArray[i].age << "\t";
            cout << "电话：" << book->personArray[i].phone << "\t";
            cout << "地址：" << book->personArray[i].address << endl;
        }
    system("pause");
    system("cls");
}

//3.删除联系人
void deletePerson(contact * book) {
    if (book->size == 0)
        cout << "通讯录为空！" << endl;
    else {
        string name;
        cout << "请输入要删除的联系人名字：";
        cin >> name;
        int i;
        for (i = 0; i < book->size; i++) {
            if(book->personArray[i].name == name)
                break;
        }
        for (int j = i;j < book->size - 1;j++)
            book->personArray[j] = book->personArray[j + 1];
        book->size--;
        cout << "联系人"<< name <<"删除成功！" << endl;
    }
    system("pause");
    system("cls");
}

//4.查找联系人
void findPerson(contact * book) {
    if (book->size == 0)
        cout << "通讯录为空！" << endl;
    else {
        string name;
        cout << "请输入要查找的联系人姓名：";
        cin >> name;
        int count=0;
        for (int i = 0;i < book->size;i++) {
            if (book->personArray[i].name == name) {
                cout << "姓名：" << book->personArray[i].name << "\t";
                cout << "性别：" << book->personArray[i].sex << "\t";
                cout << "年龄：" << book->personArray[i].age << "\t";
                cout << "电话：" << book->personArray[i].address << endl;
                count++;
            }
        }
        if (count == 0)
            cout << "抱歉，该联系人不存在！" << endl;
        else
            cout << "总共为您找到 " << count << " 位联系人!" << endl;
    }
    system("pause");
    system("cls");
}

//5,修改联系人
void modifyPerson(contact * book) {
    if (book->size == 0)
        cout << "通讯录为空！" << endl;
    else {
        string name;
        cout << "请输入要修改的联系人姓名：";
        cin >> name;
        int i;
        for (i = 0; i < book->size; i++) {
            if (book->personArray[i].name == name)
                break;
        }
        if (i < book->size) {
            int select;
            cout << "请选择要修改的信息(1,姓名，2,性别，3,年龄，4,电话，5,地址)：";
            cin >> select;
            switch (select) {
                case 1:
                    cout << "请输入修改后的姓名：";
                    cin >> book->personArray[i].name;
                    break;
                case 2:
                    cout << "请输入修改后的性别（1,男 2,女）：";
                    cin >> book->personArray[i].sex;
                    break;
                case 3:
                    cout << "请输入修改后的年龄：";
                    cin >> book->personArray[i].age;
                    break;
                case 4:
                    cout << "请输入修改后的电话：";
                    cin >> book->personArray[i].phone;
                    break;
                case 5:
                    cout << "请输入修改后的地址：";
                    cin >> book->personArray[i].address;
                    break;
                default:
                    cout << "对不起，输入有误！" << endl;
                    break;
            }
        }
        else
            cout << "对不起，该联系人不存在！" << endl;
    }
    system("pause");
    system("cls");
}

//6.清空联系人
void destoryBook(contact * book) {
    book->size = 0;
    cout << "通讯录已清空！" << endl;
    system("pause");
    system("cls");
}

int main()
{
    //创建通讯录
    contact book;
    //初始化通讯录人员个数size=0
    book.size = 0;

    //用户选择
    int select = 0;
    
    while (1) {

        showMenu();
        cout << "请选择：";
        cin >> select;
        switch (select) {
        case 1:
            //添加联系人
            addPerson(&book);
            break;
        case 2:
            //显示联系人
            showPerson(&book);
            break;
        case 3:
            //删除联系人
            deletePerson(&book);
            break;
        case 4:
            //查找联系人
            findPerson(&book);
            break;
        case 5:
            //修改联系人
            modifyPerson(&book);
            break;
        case 6:
            //清空联系人
            destoryBook(&book);
            break;
        case 0:
            //退出通讯录
            cout << "欢迎下次使用" << endl;
            system("pause");
            return 0;
            break;
        default:
            cout << "选择有误，请重新选择！" << endl << endl;
            break;
        }
    }
    return 0;
}

