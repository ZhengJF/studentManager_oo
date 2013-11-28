#include "iostream"
#include <cstring>
using namespace std;
int studentCount = 0;
class Student{
    public:
	char sname[20];
	long sid;
	long score;
}students[100];
class Manager{
    public:
    void enterScore();
    void showStuInfo();
    void addStudent();
    void delectStudent();
    void input(Student &student);
    int search(char* sname,long sid);
};

int main()
{
	char action;
	do{
		cout<<"-----------�˵�-----------"<<endl;
		cout<<"1)�鿴ѧ����������������Ϣ��"<<endl;
		cout<<"2)���ѧ��"<<endl;
		cout<<"3)ɾ��ѧ��"<<endl;
		cout<<"4)¼��ѧ���ɼ�"<<endl;
		cout<<"5)�˳�����"<<endl;
		cin>>action;
		Manager m1;
		switch(action){
		case '1':
            m1.showStuInfo();
			break;
		case '2':
			m1.addStudent();
			break;
		case '3':
			m1.delectStudent();
			break;
		case '5':
			return 0;
        case '4':
            m1.enterScore();
            break;
		default:
			cout<<"�������˴���Ĳ˵��������ѡ��";
		}
	}while(1);
}

void Manager::showStuInfo(){
	cout<<"-------ѧ����Ϣ-------"<<endl;
	cout<<"����\t"<<"ѧ��"<<"\tC++�ɼ�"<<endl;
	for(int i=0;i<studentCount;i++){
		cout<<students[i].sname<<"\t"<<students[i].sid<<"\t"<<students[i].score<<endl;
	}
}
void Manager::addStudent(){
	Student student;
	this->input(student);
    int a = studentCount;
    strcpy(students[a].sname,student.sname);
	students[a].sid = student.sid;
	studentCount++;

}
void Manager::enterScore(){
    Student student;
	this->input(student);
    int i = this->search(student.sname,student.sid);
	if (i<-1||i>studentCount) {
		cout<<"���Ҵ��󣬲����ڴ�ͬѧ��"<<endl;

	}else{

		cout<<"�������õĳɼ���"<<endl;
		cin>>students[i].score;
		cout<<"�Ƿ����¼���¸�ͬѧ�ĳɼ�?"<<endl;
		cout<<"1.�ǵģ�����¼�롣\t 2.�񣬷����ϲ㡣"<<endl;

		int action;
		cin>>action;
		switch(action){
        case 1:
            Manager m1;
            m1.enterScore();
            break;
        case 2:
            break;
		default:

			cout<<"�������˴���Ĳ˵��������ѡ��";

		}
	}

}
void Manager::delectStudent(){
	Student student;
	this->input(student);
	int i = search(student.sname,student.sid);
	if (i<-1||i>studentCount) {
		cout<<"**************************"<<endl;
		cout<<"���Ҵ��󣬲����ڴ�ͬѧ��"<<endl;
	}else{
            for(int j=i;j<=studentCount;j++)
            {
            students[j]=students[j+1];/*ɾ��Ԫ��*/
            }
            studentCount--;
			cout<<"ɾ���ɹ���"<<endl;
	}
}

void Manager::input(Student &student){
	cout<<"������";
	cin>>student.sname;

	cout<<"ѧ�ţ�";
	cin>>student.sid;
}

int Manager::search(char* sname,long sid){
	int i;
	for(i=0;i<=studentCount;i++){
		if(strcmp(students[i].sname,sname) == 0&&sid==students[i].sid){
			break;
		}
	}
	return i;
}
