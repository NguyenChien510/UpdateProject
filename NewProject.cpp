#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;
struct Date{
	int day;
	int month;
	int year;
};
typedef struct Date DATE;
struct Distance{
	string tentinh;
	int khoangcach;
};
typedef struct Distance DISTANCE;

struct NodeDistance{
	DISTANCE data;
	NodeDistance* next;
};
typedef struct NodeDistance* NODEDISTANCE; 

struct ListDistance{
	NodeDistance* head;
	NodeDistance* tail;
};
typedef struct ListDistance LISTDISTANCE;

void InsertLastDistance(LISTDISTANCE &l, NODEDISTANCE x){
	if(l.head == NULL) l.head = l.tail = x;
	else{
		l.tail->next = x;
		l.tail = x;
	}
}

NODEDISTANCE createdistance(DISTANCE x){
	NODEDISTANCE newnode = new NodeDistance;
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

struct BuuKien{
	int code;
	string item;
	string receiver;
	string sender;
	string address;
	int price;
	float mass;
	DATE time;
	bool status;
};
typedef struct BuuKien BK;

struct Node{
	BK data;
	Node *next;
};
typedef struct Node* NODE;

struct list{
	NODE head;
	NODE tail;
};
typedef struct list LIST;

NODE create(BK x){
	NODE newnode = new Node;
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

void InitListBK(LIST &l){
	l.head = NULL;
	l.tail = NULL;
}

void InitListDistance(LISTDISTANCE &l){
	l.head = NULL;
	l.tail = NULL;
}

void InsertHead(LIST &l,NODE x){
	
	if (l.head == NULL){
		l.head = l.tail = x;
	}
	else{
		x->next = l.head;
		l.head = x;
	}
}
void InsertLast(LIST &l,NODE x){
	
	
	if(l.head == NULL){
		l.head = l.tail = x;
	}
	else{
		l.tail->next = x;
		l.tail = x;
	}
}
void InsertSelect(LIST &l,BK x,int y){
	NODE newnode = create(x);
	NODE temp = l.head;
	while(temp!=NULL && temp->data.code!=y){
		temp = temp->next;
	}
	temp->next = newnode;
	newnode->next = temp->next;
}
void DeleteFirst(LIST &l){
	NODE temp = l.head;
	l.head = l.head->next;
	delete(temp);
}
void DeleteLast(LIST &l){
	NODE prev = NULL;
	NODE temp = l.head;
	while(temp->next!=NULL){
		prev = temp;
		temp = temp->next;
	}
	prev->next = NULL;
	delete(temp);
}
void DeleteSelect(LIST &l,int x){
	NODE prev = NULL;
	NODE temp = l.head;
	while(temp!=NULL && temp->data.code != x){
		temp = temp->next;
	}
	prev->next = temp->next;
	delete(temp);
}
//void Read_Date(ifstream &filein,DATE &x){
//	filein >> x.day;filein.ignore();
//	filein >> x.month;filein.ignore();
//	filein >> x.year;
//}
//void Read_BK(ifstream &filein,BK &x){
//	filein >> x.code;filein.ignore();
//	getline(filein,x.item,',');
//	getline(filein,x.sender,',');
//	getline(filein,x.receiver,',');
//	getline(filein,x.address,',');
//	filein >> x.price;filein.ignore();
//	filein >> x.mass;filein.ignore();
//	filein >> x.time.day;filein.ignore();
//	filein >> x.time.month;filein.ignore();
//	filein >> x.time.year;filein.ignore();
//	filein >> x.status;
//}
void Read_Distance(ifstream &filein,DISTANCE &x){
	getline(filein,x.tentinh,',');
	filein >> x.khoangcach;
}
void Read_All_Distance(ifstream &filein,LISTDISTANCE &l){
	while(!filein.fail()){
		DISTANCE x;
		Read_Distance(filein,x);
		if (filein.fail())
        break;
		NODEDISTANCE newnode = createdistance(x);
		InsertLastDistance(l,newnode);
	}
}
//void Read_All(ifstream &filein,LIST &l){
//	while(!filein.fail()){
//		BK x;
//		Read_BK(filein,x);
//		if (filein.fail())
//        break;
//		NODE newnode = create(x);
//		InsertLast(l,newnode);
//	}
//}

void Display(LIST l){
	if (l.head == NULL) cout << "DANH SACH RONG!" <<endl;
	else{
	
    NODE temp = l.head;
    		   cout << setw(5) << "Ma Buu Kien" << " | "
                    << setw(10) << "Ten Hang" << " | "
                    << setw(20) << "Ten Nguoi Gui" << " | "
                    << setw(20) << "Ten Nguoi Nhan" << " | "
                    << setw(18) << "Dia Diem Giao Hang" << " | "
                    << setw(19) << "Thanh Tien" << " | "
                    << setw(11) << "Khoi Luong" << " | "
                    << setw(10) << "Ngay Gui" << " | "
                    << setw(10) << "Tinh Trang" << endl;
    cout << setfill('-') << setw(145) << "-" << setfill(' ') << endl;
    while (temp != NULL){
    cout << right << setw(11) << temp->data.code << " | "

         << setw(10) << temp->data.item << " | "

         << setw(20) << temp->data.sender << " | "

         << setw(20) << temp->data.receiver << " | "

         << setw(18) << temp->data.address << " | "

         << setw(15) << temp->data.price<<" VND" << " | "

         << setw(8) << temp->data.mass<<" kg" << " | "

         << setfill('0') << setw(2) << temp->data.time.day << "/" << setw(2) << temp->data.time.month << "/" << temp->data.time.year << " | ";
         cout << setfill(' ');

         if(temp->data.status==1)

            cout<< setw(9) << "Da Giao!" << endl;

         else if(temp->data.status==0) cout<< setw(9) << "Dang Giao!" << endl;

    temp = temp->next;

    }
}
}

void DisplayDistance(LISTDISTANCE l){
	NODEDISTANCE temp = l.head;
	while(temp!=NULL){
		cout << temp->data.tentinh << " " << temp->data.khoangcach;
		temp = temp->next;
	}
}
void out(){
	cout << endl;
	cout << "1.Nhap buu kien!"<<endl;
	cout << "2.Xuat buu kien!"<<endl;
	cout << "3.Xuat dia diem!"<<endl;
	cout << "4.Save!"<<endl;
	cout << "0.Thoat!"<<endl;
	cout << "Nhap lua chon : ";
}
void Nhap(LIST &l){
BK x;cin.ignore();
	cout << "Nhap ma buu kien  : ";cin >> x.code;cin.ignore();
	cout << "Nhap ten hang     : ";getline(cin,x.item);
	cout << "Nhap nguoi gui    : ";getline(cin,x.sender);
	cout << "Nhap nguoi nhan   : ";getline(cin,x.receiver);
	cout << "Nhap dia chi      : ";getline(cin,x.address);
	cout << "Nhap gia tien     : ";cin >> x.price;
	cout << "Nhap khoi luong   : ";cin >> x.mass;cin.ignore();
	cout << "Nhap thoi gian gui: "<<endl;cout << "Nhap ngay  : ";cin >> x.time.day;cout << "Nhap thang : ";cin>> x.time.month;cout <<"Nhap nam   : ";cin>>x.time.year;
	cout << "Nhap trang thai (1=Da Giao!    0=Dang Giao!)  : " ;cin >> x.status;
	NODE newnode = create(x);
	InsertLast(l,newnode);
}
void Save(LIST &l){
	ofstream fileout; 
	fileout.open("output.txt", ios::out); 
	NODE temp = l.head;
	while(temp != NULL){

        fileout << temp->data.code << ", "

                << temp->data.item << ", "

                << temp->data.sender << ", "

                << temp->data.receiver << ", "

                << temp->data.address << ", "

                << temp->data.price << ", "

                << temp->data.mass << ", "

                << temp->data.time.day << "/" << temp->data.time.month << "/" << temp->data.time.year << ", "

                << temp->data.status << endl;

        temp = temp->next;
	}
	fileout.close();
}

void OPTION(){
	LIST l;InitListBK(l);
	LISTDISTANCE ld;InitListDistance(ld);
	ifstream filein;
	filein.open("diadiem.txt",ios::in);
	ofstream fileout;
	fileout.open("output.txt",ios::out);
	Read_All_Distance(filein,ld);
	int option;
	while(1){
		out();
		cin >> option;
		switch(option){
			case 1:
				Nhap(l);
				system("cls");
				break;
			case 2:
				Display(l);
				break;
			case 3:
				DisplayDistance(ld);
				break;
			case 4:
				if(l.head == NULL) cout << "DANH SACH CON TRONG!" <<endl;
				else {
				Save(l);
				cout << "Luu Thanh Cong!"<<endl;
				}
				break;
			case 0:
				exit(0);
				
		
				
		}
	}
}









int main(){
	OPTION();

}



