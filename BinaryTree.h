#include<iostream>
#include<stdlib.h>
#include<string.h>
#include"SapXep.h"

using namespace std;

typedef SinhVien Data;

	struct node {
		Data  key ;
		node *left ;
		node *right ;
	};
	
	node* NewNode(  node * , SinhVien );
	node* Insert(node* , SinhVien , int x);
	
	// cay theo thu tu MSV 
	node* MSV(node* , SinhVien & , int x );
	// cay theo Thu Tu Ma lop
	node* MaLop(node* , SinhVien &, int x );	
	// cay theo Thu Tu Ho Ten
	node* HoTen(node* , SinhVien &, int x );
	// cay theo Thu Tu Ngay Sinh
	node* NgaySinh(node* , SinhVien &, int x );
	// cay theo Thu Tu DiemTB
	node* DiemTB(node* , SinhVien &, int x );
