#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
#include <cstdlib>
#include <ctime>
#include<Windows.h>
#include <Mmsystem.h>
using namespace std;
HANDLE wHnd;
HANDLE rHnd;

#define For for(Node*p = l.head; p != NULL; p=p->p)
int DS[15];

struct Info
{
	unsigned int STT;
	string cauhoi;
	string a,b,c,d;
	int DapAn;
};

struct Node
{
	Info BoCauHoi; // bộ câu hỏi
	Node *p;
};

typedef struct List
{
	Node *head;
	Node *tail;
	int soluong;
};

int Stt = 0;

Node * TaoNode(string cauhoi, string a, string b, string c, string d, int DapAn)
{
	Node *P = new Node;
	P->BoCauHoi.cauhoi = cauhoi;
	P->BoCauHoi.a = a;
	P->BoCauHoi.b = b;
	P->BoCauHoi.c = c;
	P->BoCauHoi.d = d;
	P->BoCauHoi.STT = Stt;
	P->BoCauHoi.DapAn = DapAn;
	P->p = NULL;
	return P;
}

void addtail( Node *a,List &l)
{
	if(l.head==NULL)
	{
		l.head=a;
		l.tail=l.head;
	}
	else
	{
		l.tail-> p=a;
		l.tail =a;
	}
}

void file(List &l)// đưa câu hỏi, câu tra loi vào dslk
{
	string cauhoi, a ,b, c, d;
	int DapAn;
	int soluong;
	ifstream fin("cauhoi.txt");
	fin>>soluong;
	string temp;
	getline(fin, temp);
	for(int i = 0; i<soluong; i++)
	{
		Stt ++;
		getline(fin, cauhoi);
		getline(fin, a);
		getline(fin, b);
		getline(fin, c);
		getline(fin, d);
		fin>>DapAn;
		getline(fin, temp);
		Node *p = TaoNode(cauhoi, a, b, c, d, DapAn);
		addtail(p, l);
	}
}

void _HoiKhanGia(Node *p)
{
	int a, b, c, d;
	srand(time(NULL));
	int random = 60 +rand() %21; // random từ a->b: a+rand()%(b-a+1)
	char dapan = p->BoCauHoi.DapAn;
	switch(dapan)
	{
	case 1:
		{
			a = random;
			b = (100 - a)/3; c = (100-a-b)/4; d = 100 -a -b -c;
			break;
		}
	case 2:
		{
			b = random;
			a = (100 - b)/3; c = (100-a-b)/4; d = 100 -a -b -c;
			break;
		}
	case 3:
		{
			c = random;
			a = (100 - c)/3; b = (100-a-c)/4; d = 100 - a - b - c;
			break;
		}
	case 4:
		{
			d = random;
			a = (100 - d)/3; c = (100-a-d)/4; b = 100 -a -d -c;
			break;
		}
	}

	cout<<"";
	cout<<"1: "<<a<<"%"<<endl; // xuất tỉ lệ
	cout<<"2: "<<b<<"%"<<endl;
	cout<<"3: "<<c<<"%"<<endl;
	cout<<"4: "<<d<<"%"<<endl;
}

void _HoiYKienNguoiThan(Node *p)
{
	int dapan[2]; // random từ 0 -> 1; dapan[0]:đúng |dapan[1]:sai
	srand(time(NULL));
	int index = rand()% 2; // random index = 0 || 1    //0->n rand()%(n+1)
	dapan[0] = p->BoCauHoi.DapAn;
	if(index==0)
	{
		cout<<"Nguoi than ban chon cau: "<<dapan[0]<<endl;
	}
	else
	{
		if(dapan[index] + 1 >4)
		{
			dapan[1] = 1;
		}
		else
		{
			dapan[1] = dapan[0] + 1;
		}
		cout<<"Nguoi than ban chon cau: "<<dapan[1]<<endl;
	}

}

void _50_50(Node *p)
{
	int dapan[2]; // random từ 0 -> 1; dapan[0]:đúng |dapan[1]:sai
	/*srand(time(NULL));
	int index = rand()% 2; // random index = 0 || 1    //0->n rand()%(n+1)*/
	dapan[0] = p->BoCauHoi.DapAn;

	if(dapan[0] + 1 >4)
	{
		dapan[1] = rand()%2+2;
	}
	else
	{
		dapan[1] = dapan[0] + 1;
	}


	cout<<"May tinh da chon ra 2 phuong an co the dung la: "<<dapan[0]<<" va "<<dapan[1]<<endl;
}
 int j;
int xuat_cau_hoi_ngau_nhien(List l, int sttCau)
{
	int i = 1; // stt cau dau tien
	for(Node *p = l.head; p != NULL; p=p->p)
	{
		if(i == sttCau)
		{

			cout<<"Cau hoi:"<<endl<<"\t"<<p->BoCauHoi.cauhoi<<endl;
			cout<<"\t\t"<<p->BoCauHoi.a<<endl;
			cout<<"\t\t"<<p->BoCauHoi.b<<endl;
			cout<<"\t\t"<<p->BoCauHoi.c<<endl;
			cout<<"\t\t"<<p->BoCauHoi.d<<endl;
			/*switch(p->BoCauHoi.STT)
			{

			j++;*/
			return p->BoCauHoi.DapAn;
		}

		i++;
	}
}
void tienthuong()
{
    cout<<"\t\t\t|==========================|\n";
    cout<<"\t\t\t| SO TIEN QUA MOI CAU HOI  |\n";
    cout<<"\t\t\t|==========================|\n";
    cout<<"\t\t\t|==========================|\n";
    cout<<"\t\t\t|  Cau 15: 150,000 $       |\n";
    cout<<"\t\t\t|==========================|\n";
    cout<<"\t\t\t|  Cau 14: 85,000  $       |\n";
    cout<<"\t\t\t|==========================|\n";
    cout<<"\t\t\t|  Cau 13: 60,000  $       |\n";
    cout<<"\t\t\t|==========================|\n";
    cout<<"\t\t\t|  Cau 12: 40,000  $       |\n";
    cout<<"\t\t\t|==========================|\n";
    cout<<"\t\t\t|  Cau 11: 30,000  $       |\n";
    cout<<"\t\t\t|==========================|\n";
    cout<<"\t\t\t|  Cau 10: 22,000  $       |\n";
    cout<<"\t\t\t|==========================|\n";
    cout<<"\t\t\t|  Cau 9:  14,000  $       |\n";
    cout<<"\t\t\t|==========================|\n";
    cout<<"\t\t\t|  Cau 8:  10,000  $       |\n";
    cout<<"\t\t\t|==========================|\n";
    cout<<"\t\t\t|  Cau 7:  6,000   $       |\n";
    cout<<"\t\t\t|==========================|\n";
    cout<<"\t\t\t|  Cau 6:  3,000   $       |\n";
    cout<<"\t\t\t|==========================|\n";
    cout<<"\t\t\t|  Cau 5:  2,000   $       |\n";
    cout<<"\t\t\t|==========================|\n";
    cout<<"\t\t\t|  Cau 4:  1,000   $       |\n";
    cout<<"\t\t\t|==========================|\n";
    cout<<"\t\t\t|  Cau 3:    600   $       |\n";
    cout<<"\t\t\t|==========================|\n";
    cout<<"\t\t\t|  Cau 2:    400   $       |\n";
    cout<<"\t\t\t|==========================|\n";
    cout<<"\t\t\t|  Cau 1:    200   $       |\n";
    cout<<"\t\t\t|==========================|\n";
}
Node *laycauhoihientai( int stt ,List l)
{

	int i = 1; // stt cau dau tien
	for(Node *p = l.head; p != NULL; p=p->p)
	{
		if(i == stt)
		{
			return p;
		}
		i++;
	}
}
void trogiup( int b[] , int stt, List l)
{


    cout<<"\n\n";
    cout<<"|======================================|\n";
    cout<<"| 1.  GOI DIEN CHO NGUOI THAN          |\n";
    cout<<"|======================================|\n";
    cout<<"|======================================|\n";
    cout<<"| 2.  LOAI BO 50/100                   |\n";
    cout<<"|======================================|\n";
    cout<<"|======================================|\n";
    cout<<"| 3.  HOI Y KIEN KHAN GIA TRUONG QUAY  |\n";
    cout<<"|======================================|\n";

	int a;
	do{
	cin>>a;
	}while(a!=1 && a!=2 && a!=3 );
	 if(b[1]==0&&a==1||b[2]==0&&a==2||b[3]==0&&a==3)
            {
                cout<<"\n\n Quyen tro giup nay da duoc su dung roi :\n";
               _getch();

            }
            if(a==b[1])
            {
				_HoiYKienNguoiThan(laycauhoihientai(stt,l));
				 b[1]=0;
				 _getch();


            }
            if(a==b[2])
            {
               _50_50(laycauhoihientai(stt,l));
                b[2]=0;
				_getch();


            }
            if(a==b[3])
            {

              _HoiKhanGia(laycauhoihientai(stt,l));
                b[3]=0;
				_getch();


            }
}

	int flag=1;



int  main()
{
	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    rHnd = GetStdHandle(STD_INPUT_HANDLE);
    SetConsoleTitle("GAME AI LA TRIEU PHU");
    SMALL_RECT windowSize = {0, 0, 80, 40};
    SetConsoleWindowInfo(wHnd, 1, &windowSize);
    COORD bufferSize = {10, 10};
    SetConsoleScreenBufferSize(wHnd, bufferSize);
    system("color b9");//mau` xanh
    SetConsoleOutputCP(65001);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    char ten[50];
	int chon;
	srand(time(NULL));
quaylai :
    do
    {

  cout<<"\n\n\n                   |==============================================================================|\n";
        cout<<"                   |                   CHAO MUNG BAN DEN GAME AI LA TRIEU PHU                     |\n";
        cout<<"                   |==============================================================================|\n";
        cout<<"                   |==============================================================================|\n";
        cout<<"                   |                               1. BAT DAU                                     |\n";
        cout<<"                   |==============================================================================|\n";
        cout<<"                   |==============================================================================|\n";
        cout<<"                   |                               2. Huong Dan                                   |\n";
        cout<<"                   |==============================================================================|\n";
		cout<<"                   |                               3. THOAT                                       |\n";
        cout<<"                   |==============================================================================|\n";
		//PlaySound(TEXT("wav/AiLaTrieuPhu.wav"),NULL,SND_SYNC);
        do
        {
            cout<<"\nChon muc muon chon: ";
            cin>>chon;
            if(chon==1)
                system("cls");
            if(chon<1||chon>3)
                cout<<" Chon khong hop le xin vui long chon lai \n";
        } while(chon<1||chon>3);

	switch(chon)
        {
        case 1:
        {
			int b[4]= {0,1,2,3};
			 b[1]=1;
             b[2]=2;
             b[3]=3;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);// color
            srand(time(NULL));
            cout<<"\n\n Nhap ten Nguoi choi : ";
            cin>>ten;
            strupr(ten);
            SetConsoleOutputCP(65001);
            char chuoi1[50]="NEU BAN TRA LOI DUNG CAU HOI SE NGHE 2 TIENG";
            char chuoi2[50]="NEU BAN TRA LOI SAI  CAU HOI SE NGHE 2 TIENG";
            int g=strlen(chuoi1);
            int h=strlen(chuoi2);
            cout<"\n\n\n\n";
            for(int i=0; i<g; i++) // chạy chữ
            {
                cout<<chuoi1[i];
                Sleep(50);
            }
            Beep(3000,200);// am thanh phat tieng bip dung.
            Beep(3000,200);
            Beep(00,1100);
            cout<<"\n\n";
            for(int i=0; i<h; i++)
            {
                cout<<chuoi2[i];
                Sleep(50);
            }

            Beep(748,200);// am thanh phat tieng bup sai.
            Beep(748,200);
		 Beep(00,1100);
             system("cls");
            tienthuong();
            Sleep(2000);
			//PlaySound(TEXT("wav/AiLaTrieuPhu.wav"),NULL,SND_SYNC);
            system("cls");
			 cout<<"\n\n\t\t\tBAT DAU CHOI\n";
          //PlaySound(TEXT("wav/AiLaTrieuPhu.wav"),NULL,SND_SYNC);
		int random = 1+rand()% 50;// random từ a->b: a+rand()%(b-a+1)
			string data;
			List l;
		l.head= l.tail=NULL;
		file(l);
		int dem=0;//tien
		int i=0;// cau hoi
		do{
			system("cls");
			i++;
			cout<<"So tien hien tai cua ban la : "<<dem<<"$"<<endl;
			 cout<<"Cau hoi hien tai cua ban la :"<<" cau "<<i<<endl;
              /*  cout<<dem<<" VND \n";*/
			int random = 1+rand()% 50;// random từ a->b: a+rand()%(b-a+1)
			/*bool canAdd = true;
			for( int i=0;i<15;i++)
			{
				if(random==DS[i])
				{
					canAdd = false; return;
				}
			}*/
		int DapAn;
		/*if(canAdd)*/
			DapAn=xuat_cau_hoi_ngau_nhien(l,random);

		int nhap;
		int phuongan;
tieptuc :
		cout<<"1. Tro Giup - 2.Tra Loi - 3.Dung Cuoc Choi :";
		do{
		cin>>phuongan;
		}while(phuongan != 1 && phuongan != 2 && phuongan != 3 );

		switch(phuongan)
		{
		case 1 :
			{
				trogiup(b,random,l);
				goto tieptuc;
			};
		case 2 :
			{

			do{
				cout<<"Chon 1->4 de tra loi :";
				cin>>nhap;
				if(nhap<0||nhap>4)
                cout<<"Chon khong hop le ,xin vui long chon lai :\n";
				} while(nhap<0||nhap>4);
			if(DapAn==nhap)
			{
			Beep(3000,200);// am thanh phat tieng bip dung.
            Beep(3000,200);

			if(i==1)
				dem=dem+200;

                        if(i==2)
                            dem=dem+200;
                        if(i==3)
                            dem=dem+200;
                        if(i==4)
                            dem=dem+400;
                        if(i==5)
                            dem=dem+1000;
                        if(i==6)
                            dem=dem+1000;
                        if(i==7)
                            dem=dem+3000;
                        if(i==8)
                            dem=dem+4000;
                        if(i==9)
                            dem=dem+4000;
                        if(i==10)
                            dem=dem+8000;
                        if(i==11)
                            dem=dem+8000;
                        if(i==12)
                            dem=dem+10000;
                        if(i==13)
                            dem=dem+20000;
                        if(i==14)
                            dem=dem+25000;
                        if(i==15)
                            dem=dem+65000;

						system("cls");
                            cout<<"\nSo tien hien tai cua ";
                            cout<<ten;
                            cout<<" khi ban da qua cau ";
                            cout<<i-1<<" la: ";
                            cout<<dem<<" $ \n";

                        if(i==15)
                        {
                            system("cls");
                            system("color 47");
                            cout<<"\n\n\t\t RAT TUYET VOI \n";
                            cout<<"\t CHUC MUNG ";
                            cout<<ten;
                            cout<<" BAN LA NGUOI CHIEN THANG \n\n";
                            cout<<"\tSO PHAN THUONG BAN NHAN DUOC LA: ";
                            cout<<dem<<" VND \n";
                            cout<<"\t|===============================|\n";
                            cout<<"\t|  Nhap 1 Quay lai Chuong Trinh |\n";
                            cout<<"\t|===============================|\n";
                            cout<<"\t|===============================|\n";
                            cout<<"\t|  Nhap Bat ky De Thoat         |\n";
                            cout<<"\t|===============================|\n";
							i++;
                            int u;
                            cin>>u;
                            if(u==1)
                            {
                                system("cls");

                                goto quaylai;
                            }


                        }
                    }
			else
			{
			// am thanh phat tieng bip sai
			 Beep(748,200);
			 Beep(748,200);
			flag=0;
			}
			if(flag==0)
			{
				    int i = 1;
				    cout<<"Dap an dung la : "<<DapAn<<endl;
				    for (i=1;i<10;i++)
				    {
                            system("color 3e");

                            system("color 2e");


					 //PlaySound(TEXT("wav/dapandungla.wav"),NULL,SND_SYNC);

					cout<<"\n\n\t\t \n\n\n\n\n\n";
					cout << "                                     GAME OVER ";

					system("cls");
					}
                    cout<<"\n\n\t\t \n\n";
                    cout<<"Dap an dung la : "<<DapAn<<endl;
                    char chuoi3[50]="                             GAME OVER ";
                    int l=strlen(chuoi3);
                    for(int i=0; i<l; i++)
                    {
                       cout<<chuoi3[i];
                        Sleep(50);
                    }

                    cout<<"\n\n\t\tSO TIEN THUONG ";
                    cout<<ten;

                    cout<<" NHAN DUOC LA: ";
                    cout<<dem<<" $ \n";
                    cout<<"\t\t|===============================|\n";
                    cout<<"\t\t|  Nhap 1 Quay lai Chuong Trinh |\n";
                    cout<<"\t\t|===============================|\n";
                    cout<<"\t\t|===============================|\n";
                    cout<<"\t\t|  Nhap Bat ky De thoat         |\n";
                    cout<<"\t\t|===============================|\n";

					 int u;
                     cin>>u;
                     if(u==1)
					{
						system("cls");
						goto quaylai;
					}
					else
						break;
			}

	}break;
				case 3 :
			{
					int i = 1;
					for (i=1;i<10;i++)
                    {system("color 2e");
					Sleep(50);
					system("color 3e");}
					Beep(748,200);
                    cout<<"\n\t\t \n\n";
					 //PlaySound(TEXT("wav/dapandungla.wav"),NULL,SND_SYNC);
					cout<<"Dap An dung la :"<<DapAn<<endl;
                    /*char chuoi3[50]="                            END GAME ";
                    int l=strlen(chuoi3);
                    for(int i=0; i<l; i++)
                    {
                       cout<<chuoi3[i];
                        Sleep(50);
                    }*/
                    cout<<"\n\n\t\tSO TIEN THUONG ";
                    cout<<ten;
                    cout<<" NHAN DUOC LA: ";
                    cout<<dem<<" $ \n";
                    cout<<"\t\t|===============================|\n";
                    cout<<"\t\t|  Nhap 1 Quay lai Chuong Trinh |\n";
                    cout<<"\t\t|===============================|\n";
                    cout<<"\t\t|===============================|\n";
                    cout<<"\t\t|  Nhap Bat ky De thoat         |\n";
                    cout<<"\t\t|===============================|\n";

					int u;
                            cin>>u;
                            if(u==1)
								{
									system("cls");
						goto quaylai;
							}
					else
					break;

			}break;
	}

		}while(flag==1);
		}break;



	case 2:
		{

		 system("cls");
            cout<<"\t\t|============================================|\n";
            cout<<"\t\t|\t\t HUONG DAN                   |\n";
            cout<<"\t\t|============================================|\n\n";
            cout<<"Vuot qua 15 cau hoi cua chuong trinh ban se danh duoc 150 trieu dong \n";
            cout<<"Ta co cac quyen tro giup: \n";
            cout<<"\n\n|=====================================================|\n";
            cout<<"|1. GOI DIEN CHO NGUOI THAN                           |\n";
            cout<<"|  Ban co quyen goi dien cho 1 nguoi than de tro giup |\n|  ve cau hoi trong khoang thoi gian 30 giay          |\n";
            cout<<"|=====================================================|\n";
            cout<<"\n|==============================================================|\n";
            cout<<"|2.TRO GIUP 50/50: may tinh se lay 2 dap an gan chinh xac nhat |\n";
            cout<<"|==============================================================|\n";
            cout<<"\n|=====================================================|\n";
            cout<<"|3. HOI Y KIEN KHAN GIA: Khan gia trong truong quay   |\n|  se dua ra dap an ma cho ho la chinh xac.           |\n";
            cout<<"|=====================================================|\n\n\n";
            Beep(00,2500);
            cout<<"\t\t|===============================|\n";
            cout<<"\t\t|  Nhap 1 Quay lai Chuong Trinh |\n";
            cout<<"\t\t|===============================|\n";
            cout<<"\t\t|===============================|\n";
            cout<<"\t\t|  Nhap bat ky de thoat         |\n";
            cout<<"\t\t|===============================|\n";
          int u;
                            cin>>u;
                            if(u==1)
								{
									system("cls");
						goto quaylai;
							}
					else
					break;
		}

           case 3:
        {
            exit (0);
            break;
        }
        }
    }
    while(chon<0||chon>3);
    return 0;
}
