#include<iostream>
#include"KhungMenu.h"
#include<conio.h>

#include"Menus.h"
using namespace std;
typedef char stri[40];
struct ThongTinTaiKhoan{
	string useName;
	string pass;
};
void VeKhung(int );
void TaiKhoan( int  , int  );
void MatKhau(int  , int  );
void TaoTaiKhoan(int  , int );
void QuenMatKhau(int  , int );


void KhungDangNhap(int & , int );
void QuanLiDangNhap(int &);
