#include"Login.h"


void VeKhung( int a , string str ){
	switch(a){
		case 1 :
			KhungMenus(24,3,40,3);
			GotoXY(12,4); cout << "Tai Khoan " ;
			GotoXY(26,4);cout << str; 
			break;
		case 2 :
			KhungMenus(24,7,40,3);
			GotoXY(12,8); cout << "Mat Khau  " ;
			GotoXY(26,8);cout << str; 
			break;
		case 3 : 
			KhungMenus(30,11,20,3);
			GotoXY(35,12); cout << " Dang Nhap " ;						
			break;
		case 4 :
			GotoXY(20,14); cout << " Tao Tai Khoan ";
			break;	
		case 5 :
			GotoXY(40,14); cout << " Quen Mat Khau ";
			break;			
	}
}
void NhapDuLieu( int x ){
	string str ;
	switch(x){
		case 1 :
			GotoXY(26,4);getline(cin,str); 
			break;
		case 2 :
			GotoXY(26,8);getline(cin,str); 
			break;	
	}
}
void TaiKhoan(){
	
	list<SinhVien> listSV;
	string pass;
	string useName;
	char key ;
	int vt = 1;
	KhungMenus(20,3,35,3); GotoXY(21,4) ; cout << " Tai Khoan ";
	KhungMenus(20,7,35,3); GotoXY(21,8) ; cout << " Mat Khau ";
	KhungMenus(30,11,20,3); GotoXY(32,12); cout << "Dang Nhap ";
	
	
	GotoXY(32,4) ; getline(cin,useName);
	
	GotoXY(32,8) ; getline(cin,pass);
	
	GotoXY(45,12);
	key = getchar();
	
//	while ( key == 13 ){
//		
//	}

	
	Menus1(vt,listSV);
}
void MatKhau(int x , int y ){
	
}
void TaoTaiKhoan(){
	string pass;
	string useName;
	char key ;
	int vt = 1;
	KhungMenus(20,3,35,3); GotoXY(21,4) ; cout << " Tai Khoan ";
	KhungMenus(20,7,35,3); GotoXY(21,8) ; cout << " Mat Khau ";
	KhungMenus(30,11,20,3); GotoXY(32,12); cout << "Dang Nhap ";
	
	GotoXY(32,4) ; getline(cin,useName);
	
	GotoXY(32,8) ; getline(cin,pass);
	
}
void QuenMatKhau(int x , int y){
	
}
void DangNhap(){
	
	
}
void KhungDangNhap(int &vt, int soLuong){
	stri str[5] = {" Dang Nhap " , " Tao Tai Khoan " , " Quen Mat Khau ", " Thoat "};
	char key;
	
	
	Menu(str,soLuong,vt," Dang Nhap Tai Khoan ");
//	do{
//		system( "cls" );
//		
//		for( int  i = 1 ; i <= soLuong ; i++ ){	
//			if( i == vt ){
//				TextColor(2);
//				VeKhung(i,str);
//			}
//			else {
//				TextColor(3);
//				VeKhung(i,str);
//			}
//		}
//		
//		
//		
//		//--------------------------------------
//		// de nhan cai gi do tu ban phim 
//		key = getch();
//		// nhan lenh tu ban phim la mui ten xuong
//		if( key == 80 ){
//			vt ++;
//			if( vt > soLuong ) vt = 1; 
//		}	
//		// nhan lenh tu ban phim la mui ten len
//		else if( key == 72 ){
//			vt --;
//			if( vt < 1) vt = soLuong;
//		}
////		switch(vt){
////			case 1 : 
////				GotoXY(26,4);getline(cin,str);
////				break;
////			case 2 :
////				GotoXY(26,8);getline(cin,str);
////				break;	
////		}
//	}
//	// nhan lenh tu ban phim la enter hoac esc
//	while(!( key == 224 || key == 13 || key == 27 ));
}
void QuanLiDangNhap(int &vt){
	KhungDangNhap(vt,4);
	
	switch(vt){
		case 1 :
			system("cls");
			TaiKhoan();
			break;
		case 2 :
			
			break;	
		case 3 :
			
			break;
		case 4 :
			
			break;	
	}

}
