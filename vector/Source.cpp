#include <vector>
#include <iostream>
using namespace std;
#include <string>
#include <string.h>
#include <fstream>

struct BOOK {
	string  MaSo;
	string TuaSach;
	string TenTacGia;
	string  TheLoai;
	int NamXuatBan;
	int XepHang;
};

void Nhap(vector<BOOK>& B)
{
	BOOK b;
	cout << "Nhap tua sach: ";
	cin.ignore();
	getline(cin, b.TuaSach);
	cout << "Nhap ma so: ";
	getline(cin, b.MaSo);
	cout << "Nhap ten tac gia: ";
	getline(cin, b.TenTacGia);
	cout << "Nhap the loai: ";
	getline(cin, b.TheLoai);
	cout << "Nhap nam xuat ban: ";
	cin >> b.NamXuatBan;
	cout << "Nhap xep hang cua sach: ";
	cin >> b.XepHang;
	while (!(b.XepHang >= 1 && b.XepHang <= 5))
	{
		cout << "Hang cua sach phai trong khoang tu 1 sao den 5 sao!\nNhap lai hang cua sach: ";
		cin >> b.XepHang;
	}
	cin.ignore();
	B.push_back(b);
}

void Xuat(vector<BOOK> B)
{
	for (int i = 0; i < B.size(); i++) {
		cout << "Tua sach: " << B.at(i).TuaSach << endl;
		cout << "Ma so: " << B.at(i).MaSo << endl;
		cout << "Ten tac gia: " << B.at(i).TenTacGia << endl;
		cout << "The loai: " << B.at(i).TheLoai << endl;
		cout << "Nam xuat ban: " << B.at(i).NamXuatBan << endl;
		cout << "Xep hang: " << B.at(i).XepHang << endl;
		cout << endl;
	}
}

void Xuat1(vector<BOOK> B, int x)
{
	cout << "Tua sach: " << B.at(x).TuaSach << endl;
	cout << "Ma so: " << B.at(x).MaSo << endl;
	cout << "Ten tac gia: " << B.at(x).TenTacGia << endl;
	cout << "The loai: " << B.at(x).TheLoai << endl;
	cout << "Nam xuat ban: " << B.at(x).NamXuatBan << endl;
	cout << "Xep hang: " << B.at(x).XepHang << endl;
	cout << endl;
}

void TimTheoTenTacGia(vector<BOOK> B, char name[50])
{
	int i, dem = 0;;
	for (i = 0; i < B.size(); i++)
	{
		if (name == B.at(i).TenTacGia) dem++;
	}
	if (dem == 0)
	{
		cout << "Khong ton tai sach co tac gia la: " << name << endl;
		return;
	}
	for (i = 0; i < B.size(); i++)
	{
		if (name == B.at(i).TenTacGia)
		{
			Xuat1(B, i);
		}
	}

}

void TimTheoTuaSach(vector<BOOK> B, char name[50])
{
	int i, dem = 0;;
	for (i = 0; i < B.size(); i++)
	{
		if (name == B.at(i).TuaSach) dem++;
	}
	if (dem == 0)
	{
		cout << "Khong ton tai sach co tua la: " << name << endl;
		return;
	}
	for (i = 0; i < B.size(); i++)
	{
		if (name == B.at(i).TuaSach)
		{
			Xuat1(B, i);
		}
	}

}

void TimTheoNamXuatBan(vector<BOOK> B, int y)
{
	int i, dem = 0;;
	for (i = 0; i < B.size(); i++)
	{
		if (y == B.at(i).NamXuatBan) dem++;
	}
	if (dem == 0) cout << "Khong ton tai sach nam xuat ban la: " << y << endl;
	for (i = 0; i < B.size(); i++)
	{
		if (y == B.at(i).NamXuatBan)
		{
			Xuat1(B, i);
		}
	}
}

void XoaTheoMaSo(vector<BOOK>& B, char name[50])
{
	int i, dem = 0;;
	for (i = 0; i < B.size(); i++)
	{
		if (name == B.at(i).MaSo) dem++;
	}
	if (dem == 0)
	{
		cout << "Khong ton tai sach ma so la: " << name << endl;
		return;
	}
	for (i = 0; i < B.size(); i++)
	{
		if (name == B.at(i).MaSo)
		{
			B.erase(B.begin() + i);
		}
	}
	cout << "Da xoa sach co ma so la " << name << "\n";
}

void DOCFILE(vector<BOOK>& A) {

	fstream  filein("inputnew.txt", ios::in);
	while (filein.eof() == false) {
		BOOK b;
		getline(filein, b.MaSo);
		getline(filein, b.TuaSach);
		if (b.TuaSach == "") {
			break;
		}
		getline(filein, b.TenTacGia);
		getline(filein, b.TheLoai);
		filein >> b.NamXuatBan;
		filein >> b.XepHang;
		filein.ignore();
		filein.ignore();
		A.push_back(b);

	}
	filein.close();
	cout << "Da doc xong file\n";
}

void XUATFILE(vector<BOOK>B) {
	fstream fileout("output.txt", ios::out);
	for (int i = 0; i < B.size(); i++) {
		fileout << "Tua sach: " << B.at(i).TuaSach << endl;
		fileout << "Ma so: " << B.at(i).MaSo << endl;
		fileout << "Ten tac gia: " << B.at(i).TenTacGia << endl;
		fileout << "The loai: " << B.at(i).TheLoai << endl;
		fileout << "Nam xuat ban: " << B.at(i).NamXuatBan << endl;
		fileout << "Xep hang: " << B.at(i).XepHang << "/5" << endl;
		fileout << endl;
	}
	cout << "Xuat xong. Mo file output de xem\n";
	fileout.close();
}

void MENU(vector<BOOK>& B) {
	int number, x;
	char name[50];
	while (true)
	{
		system("cls");
		cout << "			CHAO MUNG BAN DEN VOI CHUONG TRINH XU LI SACH			\n";
		cout << "Hay chon ra 1 so ung voi yeu cau ban muon thuc hien.\n";
		cout << "	<0>   Thoat khoi chuong trinh\n";
		cout << "	<1>   Nhap sach\n";
		cout << "	<2>   Xuat sach\n";
		cout << "	<3>   Tim sach theo ten tac gia\n";
		cout << "	<4>   Tim sach theo tua sach\n";
		cout << "	<5>   Tim sach theo nam xuat ban\n";
		cout << "	<6>   Xoa sach theo ma so\n";
		cout << "	<7>   Doc file tu dia\n";
		cout << "	<8>   Xuat file\n";
		cout << "Nhap vao yeu cau cua ban: ";
		cin >> number;
		switch (number)
		{
		case 0:
			cout << "Tam biet! Cam on ban da su dung chuong trinh!\n";
			return;
		case 1:
			Nhap(B);
			break;
		case 2:
			Xuat(B);
			system("pause");
			break;
		case 3:
			cout << "Nhap ten tac gia cua sach can tim: ";
			cin.ignore();
			cin.getline(name, 50);
			TimTheoTenTacGia(B, name);
			system("pause");
			break;
		case 4:
			cout << "Nhap tua sach can tim: ";
			cin.ignore();
			cin.getline(name, 50);
			TimTheoTuaSach(B, name);
			system("pause");
			break;
		case 5:
			cout << "Nhap nam xuat ban cua sach can tim: ";
			cin >> x;
			TimTheoNamXuatBan(B, x);
			system("pause");
			break;
		case 6:
			cout << "Nhap ma so sach can xoa: ";
			cin.ignore();
			cin.getline(name, 50);
			XoaTheoMaSo(B, name);
			system("pause");
			break;
		case 7:
			DOCFILE(B);
			system("pause");
			break;
		case 8:
			XUATFILE(B);
			system("pause");
			break;
		default:
			cout << "Yeu cau khong ton tai! Vui long nhap lai!\n";
			system("pause");
			break;

		}
	}
}

int main()
{
	vector<BOOK> B;
	MENU(B);
	return 0;
}