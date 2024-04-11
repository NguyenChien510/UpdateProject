#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstring> 
#include <ctime>
#include <sstream>
#include <vector>
#include <conio.h>
using namespace std;
struct Date{
	int day;
	int month;
	int year; 
};
typedef struct Date DATE;
struct Distance{
	string tendiaphuong;
	string shipper;
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
	int mass;
	DATE time;
	int status;
	string shipperr;
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
void InsertLast(LIST &l, NODE x) {
	if (l.head == NULL) { 
        l.head = l.tail = x; 
    } else {
        l.tail->next = x; 
        l.tail = x;
    }
}
void DeleteSelect(LIST &l,int x){
	NODE prev = NULL;
	NODE temp = l.head;
	if(temp==NULL){
		cout << "Danh Sach Trong!"<<endl;return;
	}
	if (temp != NULL && temp->data.code == x) { //Kiem tra neu ma buu kien can xoa la node dau
		l.head = temp->next;
		delete temp;cout << "Xoa Thanh Cong!"<<endl;
		return;
	}
	while(temp!=NULL && temp->data.code != x){
		prev = temp;
		temp = temp->next;
	}
	if(temp==NULL) cout << "Khong tim thay ma buu kien can xoa!"<<endl;
	else{
	prev->next = temp->next;
	delete(temp);
	cout << "Xoa Thanh Cong!"<<endl;}
}
void Read_Distance(ifstream &filein,DISTANCE &x){
	getline(filein,x.tendiaphuong,',');
	getline(filein,x.shipper,',');
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

void DisplayOne(NODE temp){
    cout << right << setw(11) << temp->data.code << " | "
		 << setw(10) << temp->data.item << " | "
		 << setw(20) << temp->data.sender << " | "
		 << setw(20) << temp->data.receiver << " | "
		 << setw(18) << temp->data.address << " | "
		 << setw(15) << temp->data.price<<" VND" << " | "
 		 << setw(8) << temp->data.mass<<" kg" << " | "
		 << setfill('0') << setw(2) << temp->data.time.day << "/" << setw(2) << temp->data.time.month << "/" << temp->data.time.year << " | ";
         cout << setfill(' ');
         cout << setw(20) << temp->data.shipperr << " | ";
		if(temp->data.status==1)
			cout<< setw(9) << "Da Giao!" << endl;
		else if(temp->data.status==0) cout<< setw(9) << "Dang Giao!" << endl;
}

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
                    << setw(20) << "Shipper"<< " | "
                 	<< setw(10) << "Tinh Trang" << endl;
    cout << setfill('-') << setw(176) << "-" << setfill(' ') << endl;
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
         cout << setw(20) << temp->data.shipperr << " | ";
		if(temp->data.status==1)
			cout<< setw(9) << "Da Giao!" << endl;
		 else if(temp->data.status==0) cout<< setw(9) << "Dang Giao!" << endl;
		 temp = temp->next;
	}
 }
}

void out(){
	cout << endl;
	cout << "--------- QUAN LI BUU KIEN TAI BUU CUC --------"<<endl;
	cout << "              1.Nhap buu kien"<<endl;cout<<endl;
	cout << "              2.Xoa buu kien"<<endl;cout<<endl;
	cout << "              3.Xem buu kien"<<endl;cout<<endl;
	cout << "              4.Tim kiem buu kien"<<endl;cout<<endl;
	cout << "       	      5.Chinh sua buu kien"<<endl;cout<<endl;
	cout << "       	      6.Cap nhat trang thai buu kien"<<endl;cout<<endl;
	cout << "       	      7.Save"<<endl;cout<<endl;
	cout << "       	      0.Thoat"<<endl;cout<<endl;
	cout << "-----------------------------------------------"<<endl;
	cout << "Nhap lua chon : ";
}


string Address(BK x){int luachon;
	cout << "-------- Khu vuc giao hang --------"<<endl;
	cout << "              QUAN:            "<<endl;
	cout << "          1.Hai Chau"<<endl;
	cout << "          2.Lien Chieu"<<endl;
	cout << "          3.Thanh Khe"<<endl;
	cout << "          4.Cam Le"<<endl;
	cout << "          5.Son Tra"<<endl;
	cout << "          6.Ngu Hanh Son"<<endl;
	cout << "              HUYEN:        "<<endl;
	cout << "          7.Hoa Vang"<<endl;
	cout << "          8.Hoang Sa"<<endl;
	cout << "Chon khu vuc : ";cin>>luachon;
	switch(luachon){
		case 1: x.address="Hai Chau";break;
		case 2: x.address="Lien Chieu";break;
		case 3: x.address="Thanh Khe";break;
		case 4: x.address="Cam Le";break;
		case 5: x.address="Son Tra";break;
		case 6: x.address="Ngu Hanh Son";break;
		case 7: x.address="Hoa Vang";break;
		case 8: x.address="Hoang Sa";break;
		default:cout<<"Vui long nhap dung STT!"<<endl;x.address = Address(x);
	}
	return x.address;
}
string LoaiBoXuongDongODau(string &s) {
    while (!s.empty() && s.front() == '\n') {
        s.erase(0, 1); 
    }
    return s;
}
string NguoiGiao(BK &x,string s,LISTDISTANCE ld){
	ifstream filein;
	filein.open("danang.txt",ios::in);
	Read_All_Distance(filein,ld);
	NODEDISTANCE temp = ld.head;
	while(temp!=NULL){
		if(LoaiBoXuongDongODau(temp->data.tendiaphuong)==s){
			x.shipperr=temp->data.shipper;break;
		}
		temp=temp->next;
	}
	return x.shipperr;
}
BK INPUT(LIST &l,LISTDISTANCE &ld){
	time_t now = time(0);
	tm *ltm = localtime(&now);
	BK x;  //Ham nhap input tu nguoi dung
	cout << "Nhap ma buu kien   : ";cin >> x.code;cin.ignore();
	cout << "Nhap ten hang      : ";getline(cin,x.item);
	cout << "Nhap nguoi gui     : ";getline(cin,x.sender);
	cout << "Nhap nguoi nhan    : ";getline(cin,x.receiver);
	x.address = Address(x);
	cout << "Nhap khoi luong(kg): ";cin >> x.mass;
	x.price=x.mass*250;
	x.shipperr=NguoiGiao(x,x.address,ld);
	x.time.day = ltm->tm_mday;x.time.month=1+ltm->tm_mon;x.time.year=1900+ltm->tm_year;
	x.status = 0;
	return x;
}

void Nhap(LIST &l,LISTDISTANCE &ld){
	NODE newnode = create(INPUT(l,ld));
	InsertLast(l,newnode);
	cout << "Them thanh cong!" <<endl;
}

void Save(LIST &l){
	ofstream fileout; 
	fileout.open("output.txt", ios::out); 
	NODE temp = l.head;
	    		   fileout << setw(5) << "Ma Buu Kien" << " | "
                    << setw(10) << "Ten Hang" << " | "
                    << setw(20) << "Ten Nguoi Gui" << " | "
                    << setw(20) << "Ten Nguoi Nhan" << " | "
                    << setw(18) << "Dia Diem Giao Hang" << " | "
                    << setw(19) << "Thanh Tien" << " | "
                    << setw(11) << "Khoi Luong" << " | "
                    << setw(10) << "Ngay Gui" << " | "
                    << setw(20) << "Shipper" << " | "
                    << setw(10) << "Tinh Trang" << endl;
    fileout << setfill('-') << setw(176) << "-" << setfill(' ') << endl;
	while(temp != NULL){
 fileout << right << setw(11) << temp->data.code << " | "
		 << setw(10) << temp->data.item << " | "
		 << setw(20) << temp->data.sender << " | "
		 << setw(20) << temp->data.receiver << " | "
		 << setw(18) << temp->data.address << " | "
 		 << setw(15) << temp->data.price<<" VND" << " | "
		 << setw(8) << temp->data.mass<<" kg" << " | "
		 << setfill('0') << setw(2) << temp->data.time.day << "/" << setw(2) << temp->data.time.month << "/" << temp->data.time.year << " | ";
         fileout << setfill(' ');
         fileout << setw(20) << temp->data.shipperr << " | ";
		if(temp->data.status==1)
			fileout<< setw(9) << "Da Giao!" << endl;
	   	 else if(temp->data.status==0) fileout<< setw(9) << "Dang Giao!" << endl;
	temp = temp->next;
	}
	fileout.close();
}

bool CHECK(LIST &l){
	bool check = true;
	if(l.head==NULL){
		check = false;
	 cout << "DANH SANH RONG!"<<endl;}
}

void PhanLoai(LIST l, int x) {


    switch(x){
		case 1:
    		{NODE temp = l.head;bool find=false;
			while(temp!=NULL){
    			if(temp->data.status==1){cout << "                                                                         DANH SACH CAC BUU KIEN : DA GIAO "<<endl<<endl;
    			cout << setw(5) << "Ma Buu Kien" << " | "
                    << setw(10) << "Ten Hang" << " | "
                    << setw(20) << "Ten Nguoi Gui" << " | "
                    << setw(20) << "Ten Nguoi Nhan" << " | "
                    << setw(18) << "Dia Diem Giao Hang" << " | "
                    << setw(19) << "Thanh Tien" << " | "
                    << setw(11) << "Khoi Luong" << " | "
                    << setw(10) << "Ngay Gui" << " | "
                    << setw(20) << "Shipper"<< " | "
                    << setw(10) << "Tinh Trang" << endl;
    cout << setfill('-') << setw(176) << "-" << setfill(' ') << endl;
				DisplayOne(temp);find=true;}temp=temp->next;
    			}
			if(!find) cout << "Khong tim thay buu kien co TRANG THAI : Da Giao!"<<endl;}
			break;
		case 2:
    		{NODE temp = l.head;bool find=false;
			while(temp!=NULL){
    			if(temp->data.status==0){cout << "                                                                        DANH SACH CAC BUU KIEN : DANG GIAO "<<endl<<endl;
    			cout << setw(5) << "Ma Buu Kien" << " | "
                    << setw(10) << "Ten Hang" << " | "
                    << setw(20) << "Ten Nguoi Gui" << " | "
                    << setw(20) << "Ten Nguoi Nhan" << " | "
                    << setw(18) << "Dia Diem Giao Hang" << " | "
                    << setw(19) << "Thanh Tien" << " | "
                    << setw(11) << "Khoi Luong" << " | "
                    << setw(10) << "Ngay Gui" << " | "
                    << setw(20) << "Shipper"<< " | "
                    << setw(10) << "Tinh Trang" << endl;
    cout << setfill('-') << setw(176) << "-" << setfill(' ') << endl;
				DisplayOne(temp);find=true;}temp=temp->next;
    			}
			if(!find) cout << "Khong tim thay buu kien co TRANG THAI : Dang Giao!"<<endl;}
			break;
	}
}

void ChinhSua(LIST &l,int x){
	NODE temp=l.head;LISTDISTANCE ld;
	while(temp!=NULL && temp->data.code!=x){
		temp=temp->next;
	}
	if(temp==NULL) cout << "Khong tim thay ma buu kien can sua!"<<endl;
	else{
		int luaChon;
        cout << "Chon thong tin can chinh sua:" << endl;
        cout << "1. Ten hang" << endl;
        cout << "2. Nguoi gui" << endl;
        cout << "3. Nguoi nhan" << endl;
        cout << "4. Dia chi giao hang" << endl;
        cout << "5. Khoi luong" << endl;
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        cin.ignore(); 
        switch(luaChon){
            case 1:
                cout << "Nhap ten hang moi: ";
                getline(cin, temp->data.item);
                break;
            case 2:
                cout << "Nhap ten nguoi gui moi: ";
                getline(cin, temp->data.sender);
                break;
            case 3:
                cout << "Nhap ten nguoi nhan moi: ";
                getline(cin, temp->data.receiver);
                break;
            case 4:
                temp->data.address = Address(temp->data);
                break;
            case 5:
                cout << "Nhap khoi luong moi: ";
                cin >> temp->data.mass;
                temp->data.price = temp->data.mass * 250;
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
        }
       
		 cout << "Cap Nhat Thanh Cong!" << endl;
}

}
void ThayDoi(LIST &l,int xy){
	BK x;
	NODE temp=l.head;
	while(temp!=NULL && temp->data.code!=xy) temp = temp->next;
	if(temp == NULL ) cout << "Khong tim thay ma buu kien can thay doi!"<<endl;
	else{ 
		
		int thay;
		cout << "-----------Lua chon-----------"<<endl;
		cout << "         0.Dang Giao!"<<endl;
		cout << "         1.Da Giao!"<<endl;
		cout << "Nhap lua chon : ";cin>>thay;
		switch(thay){
			case 0:temp->data.status=0;cout<<"Cap Nhat Thanh Cong!"<<endl;break;
			case 1:temp->data.status=1;cout<<"Cap Nhat Thanh Cong!"<<endl;break;
			default:cout<<"Vui long nhap 0 hoac 1!"<<endl;break;
		}
}
}
void OPTION(){
	LIST l;InitListBK(l);
	LISTDISTANCE ld;InitListDistance(ld);
	int option;
	while(1){
		char cont = _getch();
    	system("cls");
		out();
		cin >> option;
		system("cls");
		switch(option){
			case 1:
				cout << "------- Nhap thong tin buu kien -------" <<endl;
				Nhap(l,ld);
				break;
			case 2:
				if(CHECK(l)==true){
				
				Display(l);
				int find;cout<<"Nhap ma buu kien can xoa : ";cin>>find;
				DeleteSelect(l,find);}
				break;
			case 3:
				int option3;
				cout << "--------------- Lua chon ------------"<<endl;
				cout << "     1 Xem toan bo danh sach. "<<endl;
				cout << "     2 Xem buu kien theo phan loai."<<endl;
				cout << "Nhap lua chon : ";cin>>option3;
				if(option3 == 1) Display(l);
				else if(option3==2){
				int option33;
				cout << "---------------- Lua chon ---------------------" <<endl;
				cout << "     1 Phan loai theo TINH TRANG: Da giao!"  << endl;
				cout << "     2 Phan loai theo TINH TRANG: Dang giao!"  << endl;
				cout << "-----------------------------------------------"<<endl;
				cout << "Nhap lua chon : ";cin>>option33;
				if(CHECK(l)==true) {
					
						
				PhanLoai(l,option33);}
				}
				break;
			case 4:
				int option4;
				cout << "----------- LUA CHON TIM KIEM THEO -----------"<<endl;
				cout << "              1.TEN NGUOI GUI."<<endl;
				cout << "              2.TEN NGUOI NHAN."<<endl;
				cout << "              3.MA BUU KIEN."<<endl;
				cout << "              4.Shipper"<<endl;
				cout<<  "Nhap lua chon : ";cin>>option4;
				break;
			case 5:
				if(CHECK(l)==true){
				
				Display(l);
				cout << "Nhap ma buu kien can chinh sua : ";int x;cin>>x;
				ChinhSua(l,x);}
				break;
			case 6:
				if(CHECK(l)==true) {
				
				Display(l);
				int xy;cout <<"Nhap ma buu kien can thay doi trang thai : ";cin>>xy;
				ThayDoi(l,xy);}
			
				break;
			case 7:
				if(l.head == NULL) cout << "DANH SACH CON TRONG!" <<endl;
				else {
				Save(l);
				cout << "Luu Thanh Cong!"<<endl;}
				break;
			
      		case 0:
      			exit(0);
			
			
				}
}
}









int main(){
	system("color 3");
	OPTION();
}


