#include "Menus.h"

using namespace std;

	stri str1[7] = {" 1.Cap Nhat Ho So Sinh Vien  ", " 2.In danh sach ", " 3.Sap xep ", " 4.Tim kiem  ", " 5.Thong Ke  " ," 6.Huong Dan " , " 7.Thoat "};
	 
	stri str2[7] = {" 1.Them Ho So Sinh Vien " ," 2.Sua Ho So Sinh Vien " , " 3.Xoa Ho So Sinh Vien "  , " 4.Quay Lai "};
	
	stri str3[5] = { " 1.Sap Xep Chon " ," 2.Sap Xep Chen " ," 3.Sap Xep Noi Bot ", " 4.Sap Xep Nhanh " ," 5.Quay lai "};
	
	stri str4[3] = {" 1.Tim kiem tuan tu ", " 2.Tim kiem nhi phan ", " 3.Quay lai "}; 
	
	stri str5[3] = {" 1.Thong Ke Theo Lop " ," 2.Thong Ke Theo KQHT "," 3.Quay Lai "};
	
	stri str6[3] = {" 1.Them Thong Tin Tu Nhap "," 2.Them Thong Tin Lay Tu File " ," 3.Quay Lai "};
	
//	stri str7[3] = {" 1.In Thong Tin Tren Console"," 2.In Thong Tin Ra File " ," 3.Quay Lai "};
	
	stri str8[6] = { " 1.Sap Xep DS Theo Ma sinh vien " , " 2.Sap Xep DS Theo Ho Va Ten " ,
	" 3.Sap Xep DS Theo Ngay sinh ", " 4.Sap Xep DS Theo Diem TB "," 5.Quay Lai "};
	
	stri str9[6] = {" 1.Tim Kiem Theo Ma Sinh Vien " , " 2.Tim Kiem Theo Ma Lop " , " 3.Tim Kiem Theo Ho Va Ten " ,
	" 4.Tim Kiem Theo Ngay sinh "," 5.Tim Kiem Theo Diem TB", "6.Quay Lai " };
	
	stri str10[6] = {" Ty Le Sv xuat sac ", " Ty Le Sv gioi ", " Ty Le Sv kha",
	" Ty Le Sv TB " ," Ty Le Sv yeu"," Quay Lai " };
	
	
void KhungTieuDe(int x , int y , int w , int h , string a ){
	TextColor(1);
	KhungMenus(x,y,w,h);
	GotoXY(x+1,y+1); cout << a;
}	
void Menu( stri str[] , int soLuong , int &vt , string a ){	
	char key;
	do{
		system( "cls" );
		KhungTieuDe(25,0,40,3,a);
		for( int  i = 1 ; i <= soLuong ; i++ ){	
			if( i == vt ){
				TextColor(2);
				KhungMenus( 15 , 3 + 3 * i , 40 , 3 );
				GotoXY( 20 , 4 + 3 * i ) ; cout << str[i-1] ;
			}
			else {
				TextColor(1);
				KhungMenus( 15 , 3 + 3 * i , 40 , 3 );
				GotoXY(20 , 4+3*i) ; cout << str[i-1];	
			}
		}
		//--------------------------------------
		// de nhan cai gi do tu ban phim 
		key = getch();
		// nhan lenh tu ban phim la mui ten xuong
		if( key == 80 ){
			
			vt ++;
			if( vt > soLuong ) vt = 1; 
		}	
		// nhan lenh tu ban phim la mui ten len
		else if( key == 72 ){
			
			vt --;
			if( vt < 1) vt = soLuong;
		}
	}	
	// nhan lenh tu ban phim la enter hoac esc
	while(!( key == 224 || key == 13 || key == 27 ));
}
// Menu Chinh : M1,M2,M3,M4,M5,M6,M7
void Menus1( int &vt , list<SinhVien> &listSV ){
	vt = 1;
	Menu( str1 , 7 , vt , "	Quan Li Sinh Vien " );
	switch(vt){
		// M1 : cap nhat thong tin
		case 1 : 
			CapNhatSV( listSV , vt );			
			break;
			
		// M2 : in danh sach
		case 2: 
			InDanhSach( listSV , vt );
			break;
			
		//M3 : sap xep 	
		case 3 : 
			SapXepM1(vt , listSV );
			break; 
			
		//M4 :  tim kiem	
		case 4 :		
			TimKiemM1(vt , listSV );
			break;
			
		//M5 : thong ke
		case 5 : 
			ThongKeM1(vt , listSV);
			
			break;
			
		//M6 : huong dan cach dung	
		case 6 : 
			system("cls");
			//HuongDan();
			
			break;
				
		// M7	: thoat ung dung
		case 7 : 
			system("cls");
			cout <<" Ket Thuc ";
			break;		
	}
}
// M1 : cap nhat thong tin sinh vien
void CapNhatSV(list<SinhVien> &listSV , int &vt){
	char key;
	vt = 1 ;
	Menu(str2, 4 , vt , "Cap Nhat Thong Tin Sinh Vien ");
	
	switch(vt){
		case 1 : 
			ThemThongTinSV(listSV , vt);
			break;
			
		case 2 : 
			system("cls");
			// truy suat den ham sua thong tin
			SuaThongTin(listSV , 10 , 4);
			MenuMain(20,24);
			Menus1(vt, listSV);
			break;
			
		case 3 : 
			system("cls");
			Xoa(listSV);
			MenuMain(20,24);
			Menus1(vt , listSV);
			break;
			
		case 4 :
			Menus1(vt,listSV); 
			break;					
	}
}
void SuaThongTin( list<SinhVien> &listSV , int x , int y){
	
	int i = 0 ,dem = 0;
	string MSV;
	SinhVien sv;
	KhungTieuDe(15,1,50,3," Nhap Ma SV Cua SV Can Sua : ") ; cin >> MSV;
	
	while( i < listSV.size() ){
		sv = listSV.front();
		if( MSV == sv.GetMaSV() ){
			KhungTieuDe(x,y,50,10, " Thong Tin SV thu "); cout << i+ 1;
			// nhap tt sv
			cin.ignore();
			NhapThongTin(sv,x,y);
			
			GotoXY( x + 1 , y + 7 );
			y += 13;
		}
		else {
			dem ++;
		}
		listSV.push_back(sv);
		listSV.pop_front();
		i++;
	}
	system("cls");
	if( dem  == listSV.size() ){
		string a = "Khong Co MSV  : " + MSV + "  Trong D S ";
		KhungTieuDe(15,1,50,3, a);
	}
	else{
		string a = "Da Sua Xong  Sinh Vien Co MSV : " +  MSV ;
		KhungTieuDe(15,1,50,3,a);
	}	
}
void Xoa( list<SinhVien> &listSV  ){
	int i = 0 ,dem = 0;
	string MSV;
	SinhVien sv;
	KhungTieuDe(15,1,50,3," Nhap Ma SV Cua SV Can Xoa : ") ; cin >> MSV;
	
	while( i < listSV.size() ){
		sv = listSV.front();
		if( MSV == sv.GetMaSV() ){	
			listSV.pop_front();
			
			i = listSV.size();
		}
		else{
			listSV.push_back( sv );
			listSV.pop_front();
			dem ++;
		}		
		i++;	
	}
	system("cls");
	if( dem  == listSV.size()  ){
		string a = "Khong Co MSV  : " + MSV + "  Trong DS ";
		KhungTieuDe(15,1,50,3,a);
	}
	else if(dem  < listSV.size() ){	
		string a = "Da Xoa Sinh Vien Co MSV la "+ MSV + " Ra Khoi DS ";
		KhungTieuDe( 15 , 1 , 50 , 3 ,a);
		
	}
}
void MenuMain(int x , int y ){
	char key;
	KhungTieuDe(x,y,20,3," MainMenu ");
	key = getch();		
	while( key != 13 ){
		key = getch();
	}
}
// M1-1 : them thong tin sinh vien
void ThemThongTinSV( list<SinhVien> &listSV , int &vt ){
	
	char key;
	vt = 1 ;
	int soSV;
	SinhVien sv;
	string text = " Them Thong Tin Sinh Vien " ;
	
	Menu(str6 , 3 , vt , text);
	switch(vt){	
		case 1 :
			system("cls");
			// ve khung
			KhungTieuDe(10,0,30,3," So Sinh Vien Muon Them : ") ; cin >> soSV;
			sv.SetSLSinhVien(soSV);
			
			NhapDS(listSV , sv , 10 , 8);
			MenuMain(20,4);
			Menus1(vt,listSV);
			break;
			
		case 2 :
			system("cls");
			cout << " Ban da chon thong tin tu file ";
			ReadFile(listSV);
			
			MenuMain(20,5);
			Menus1(vt,listSV);
			break;
			
		case 3 : 
			CapNhatSV(listSV , vt);
			break;		
	}
}
void KhungInDanhSach(){
	KhungTieuDe(25,0,30,3," Danh Sach Tat Ca Sinh Vien");
					
	KhungMenus(1,5,85,3); 
	GotoXY(2,6); cout <<"STT";
	GotoXY(8,6); cout <<"Ma Sinh Vien";
	GotoXY(27,6); cout <<"Ma Lop";
	GotoXY(45,6); cout <<"Ho Va Ten";
	GotoXY(65,6); cout <<"Ngay Sinh";
	GotoXY(77,6); cout <<"Diem TB";
	KhungMenus2(5);
}
// M2 : In danh Sach 
void InDanhSach( list<SinhVien> &listSV , int &vt ){
	char key ;
	string text = " In Danh Sach " ;
	char fileName[300] = " DanhSach.txt ";
	system("cls");
	
	KhungInDanhSach();
	ShowDS(listSV , 10 , 8);
	WriteFile(listSV,fileName);	
	int n = listSV.size();
	
	// nhan mainMenu -> ve Menu chinh
	MenuMain(25 ,9+4*n);
	Menus1(vt , listSV); 
}
// M3 : sap xep 
void SapXepM1(int &vt , list<SinhVien> &listSV ){
	
	vt = 1; 
	string text = " Cac Thuat Toan Sap Xep " ;
	
	Menu(str3 , 5 , vt , text);
		switch(vt){
			// khi chon selection sort;
			case 1 :
				SapXepM2(vt , listSV);
				break ;	
				
			// khi chon Insert sort;
			case 2 :
				SapXepM2(vt , listSV);
				break ;
				
			// khi chon bubble sort;	
			case 3 : 
				SapXepM2(vt , listSV);
				break ;	
				
			// khi chon quick sort;	
			case 4 :
				SapXepM2(vt , listSV);
				break ;
				
			// quay lai
			case 5 :
				Menus1(vt , listSV);
				break ;		
	}
}
// M3-1 : cac kieu sap xep 
void SapXepM2(int &vt , list<SinhVien> &listSV ){
	int x = vt  ;
	vt = 1;
	char key ;
	
	SinhVien SV[100];
	
	Menu(str8 , 5 , vt , str3[x-1]);
	system("cls");
	
	int n = listSV.size();
	SaoChepDS1(listSV , SV );
	switch(x){
		case 1 :
			SapXepChon(SV,n,vt);
			system("cls");
			KhungTieuDe(15,0,40,3," Da Dung Thuat Toan Sap Xep Chon ");
			break;
		case 2 :
			SapXepChen(SV,n,vt);
			system("cls");
			KhungTieuDe(15,0,40,3," Da Dung Thuat Toan Sap Xep Chen ");
			break;
		case 3 :
			SapXepNoiBot(SV,n,vt);
			system("cls");
			KhungTieuDe(15,0,40,3," Da Dung Thuat Toan Sap Xep Noi Bot ");
			break;
		case 4 :
			SapXepNhanh(vt,SV,0,n-1);
			system("cls");
			KhungTieuDe(15,0,40,3," Da Dung Thuat Toan Sap Xep Nhanh ");
			break;			
	}
	SaoChepDS2(listSV , SV , n);
	MenuMain(20,4);
	Menus1(vt , listSV); 
}
// M4 : tim kiem
void TimKiemM1( int &vt , list<SinhVien> &listSV ){
	vt = 1 ;
	char text[100] = " Cac Loai Tim Kiem " ;
	Menu(str4 , 3 , vt , text);
	if( vt <= 2 ) TimKiemM2(vt,listSV);
	else Menus1(vt,listSV);
}
void KhungTimKiem(list<SinhVien> &listSV1 , int n){
	TextColor(2);
	KhungMenus(25,0,30,3); GotoXY(30,1);
	cout <<" Danh Sach Tim Kiem ";
	TextColor(11);				
	KhungMenus(1,5,85,3); 
	GotoXY(2,6); cout <<"STT";
	GotoXY(8,6); cout <<"Ma Sinh Vien";
	GotoXY(27,6); cout <<"Ma Lop";
	GotoXY(45,6); cout <<"Ho Va Ten";
	GotoXY(65,6); cout <<"Ngay Sinh";
	GotoXY(77,6); cout <<"Diem TB";
	KhungMenus2(5);

	for(int i = 0 ; i < n ; i ++ ){
		SinhVien s1 = listSV1.front();
		KhungMenus(1,9+4*i,85,3); 
		GotoXY(2,10+4*i); cout << i+1;
		GotoXY(8,10+4*i); cout <<s1.GetMaSV();
		GotoXY(27,10+4*i); cout <<s1.GetMaLop();
		GotoXY(45,10+4*i); cout <<s1.GetHoTen();
		GotoXY(65,10+4*i); cout <<s1.GetNgaySinh();
		GotoXY(77,10+4*i); cout <<s1.GetDiemTB();
		KhungMenus2(9+4*i);	
		listSV1.pop_front();
		listSV1.push_back(s1);
	}
}
void TimKiemTuanTu1( list<SinhVien> &listSV1, int n , string a , int x ){
	system("cls");
	SinhVien s;
	double diem;
	int dem;
	string str;
	if( x <= 4 ){
		KhungMenus(20,0,45,3); GotoXY(21,1);
		cout <<" Nhap " << a << " Can Tim : ";
		switch(x){
			case 1 : 
				getline(cin,str);
				s.SetMaSV(str);
				break;
			case 2 :
				getline(cin,str);
				s.SetMaLop(str);
				break;		
			case 3 : 
				getline(cin,str);
				s.SetHoTen(str);
				break;
			case 4 :
				getline(cin,str);
				s.SetNgaySinh(str);
				break;		
		}
		dem = TimKiemTuanTu(listSV1,s,x);
		if(dem == n ){
			system("cls");
			string str1 = " Khong Co " + a + " : "  + str + " Trong DS " ;
			KhungTieuDe(25,0,40,3,str1);
		}
		else{
			system("cls");
			GotoXY(25,4);
			cout <<a<< " : " << str << " (sequential search)";	
		}			
	}
	else{
		KhungMenus(20,0,45,3); GotoXY(21,1);
		cout <<" Nhap Diem TB Can Tim : ";
		cin >> diem;
		s.SetDiemTB(diem);
		dem = TimKiemTuanTu(listSV1,s,5);
		
		if(dem == n ){
			system("cls");
			KhungMenus(25,0,40,3); GotoXY(27,1);
			cout <<" Khong Co Diem TB : " << str <<" Trong DS ";
		}
		else{
			n = listSV1.size();	
			system("cls");
			GotoXY(25,4);
			cout <<" Diem TB: " << str << " (sequential search)";	
		}				
	}
}
void TimKiemNhiPhan1( list<SinhVien> &listSV1, int n , string a , int x ){
	system("cls");
	SinhVien s;
	string str;
	node *root = NULL;
	if(x <= 4 ){
		KhungMenus(20,0,45,3); GotoXY(21,1);
		cout <<" Nhap " << a <<" Can Tim : ";
		switch(x){
			case 1 :
				getline(cin,str);
				s.SetMaSV(str);
				break;
			case 2 :
				getline(cin,str);
				s.SetMaLop(str);
				break;
			case 3 :
				getline(cin,str);
				s.SetHoTen(str);
				break;
			case 4 :
				getline(cin,str);
				s.SetNgaySinh(str);
				break;			
		}			
		if( n != 0){
			root = Insert(root,listSV1.front(),x);
			listSV1.pop_front();
			PushTree(listSV1,root,x);
			TimKiemNhiPhan(listSV1,root,s,x);
						
			if( n == 0 ){
				system("cls");
				KhungMenus(25,0,40,3); GotoXY(27,1);
				cout <<" Khong Co " << a << " :  " << str <<" Trong DS ";
			}
			else{
				system("cls");
				n	= listSV1.size();	
				GotoXY(25,4);
				cout << a << " : " << str << " (Binary search)";
			}	
		}
		else{
			system("cls");
			KhungMenus(25,0,40,3); GotoXY(27,1);
			cout <<" Danh Sach  Rong ";
		}
	}			
}
// M4-1 : thong tin can tim kiem
void TimKiemM2(int &vt , list<SinhVien> &listSV ){
	// check xem chon : nhi phan hay tuan tu( x == 1 : tim kiem tuan tu , x == 2 : tim kiem nhi phan)
	int x = vt , n ;
	vt = 1;
	Menu(str9 , 6 , vt , " Thong Tin Can Tim Kiem ");

	list<SinhVien> listSV1;
	listSV1 = listSV;
	string a ;
	switch(vt){
		case 1 : 
			a = " MSV ";
			break;
		case 2 :
			a = " Ma  Lop ";
			break;
		case 3 :
			a = " Ho Ten ";
			break;
		case 4 : 
			a = " NgaySinh ";
			break;			
		case 5 :
			a = " Diem TB ";
			break;
		case 6 : 
			TimKiemM1(vt,listSV);
			break;		
	}
	switch(x){
		case 1 :
			TimKiemTuanTu1(listSV1,listSV.size(),a,vt);
			break;
		case 2 :
			TimKiemNhiPhan1(listSV1,listSV.size(),a,vt);
			break;
		case 3 :
			Menus1(vt,listSV);
			break;				
	}
	n = listSV1.size();
	if(listSV1.size() != 0){
		KhungTimKiem(listSV1, n);
	}
	char fileName[50] = "DSTimKiem.txt";
	WriteFile(listSV1,fileName);
			
	MenuMain(25,9+4*n);
	Menus1(vt,listSV);	
}
// M5 : cac kieu thong ke
void ThongKeM1(int &vt , list<SinhVien> &listSV){
	
	vt = 1;
	char text[100] = " Cac Kieu Thong Ke " ;
	
	Menu(str5 , 3 , vt , text);
	if( vt == 6 ) Menus1(vt,listSV);
	else ThongKeM2(vt,listSV);
	
}
void ThongKeLop(list<SinhVien> &listSV1 , list<THONGKE> &ThongKes  ){
	ThongKe(listSV1,ThongKes,2);	
	int n = ThongKes.size();
	KhungTieuDe(25,0,30,3," Danh Sach Thong Ke - Ma Lop");	
	KhungMenus(21,6,40,3); 
	GotoXY(24,7); cout <<"STT";
	GotoXY(30,7); cout <<"Ma Lop";
	GotoXY(49,7); cout <<" So Luong ";
	KhungMenus3(22,6); 
			
	for(int i = 0 ; i < n ; i ++ ){
		THONGKE t = ThongKes.front();
		KhungMenus(21,9+3*i,40,3); 
		GotoXY(24,10+3*i); cout << i+1;
		GotoXY(30,10+3*i); cout <<t.str;
		GotoXY(49,10+3*i); cout <<t.sL;
		KhungMenus3(22,9+3*i);	
		ThongKes.pop_front();
		ThongKes.push_back(t);
	}
	MenuMain(25 , 9+3*n);
}
void KhungThongKe(){
	TextColor(2);
	KhungMenus(25,0,35,3); GotoXY(27,1);
	cout <<" Thong Ke - KQHT ";
	TextColor(11);	
						
	KhungMenus(20,6,50,3); 
	KhungMenus4(20,6); 
			
	KhungMenus(10,9,60,3); 
	GotoXY(11,10); cout <<"Ma Lop";
			
	KhungMenus(71 , 9 ,10,3) ;
	GotoXY(72,10) ;  cout << "  Tong ";
			
	for(int i = 0 ; i < 5 ; i++ ){
		GotoXY(21+10*i,10); cout <<" SL ";
		GotoXY(26+10*i,10); cout <<" % ";
	}
	KhungMenus5(9);
}
void ThongKeKQHT(list<SinhVien> &listSV1 , list<THONGKE> &ThongKes , int a ){
	ThongKe(listSV1,ThongKes ,2);
	int n = ThongKes.size();
	double tong[5] ;
	int s = 0 ;
	for(int i = 0 ; i  < 5 ; i++ ) tong[i] = 0;
	for(int i = 0 ; i <= n ; i ++ ){
				
		THONGKE t = ThongKes.front();
		
		if( i < n ){
			KhungMenus(10,12+3*i,60,3); 
			GotoXY(11 , 12+3*i +1) ; cout << t.str;
				
			for(int j = 0 ; j < 5 ; j++){
				double tyLe = (double)t.d[4-j]/t.sL ;
				GotoXY(21 + 10*j , 12 + 3*i + 1) ; cout << t.d[4-j];
				GotoXY(26 + 10*j , 12 + 3*i + 1); cout <<  roundf(tyLe * 100) ;
				if( j <= 2 && j >= 1 ){
					 s += t.d[4-j];
				}
				tong[j] += t.d[j];
			}
			KhungMenus(71 , 12+3*i ,10,3) ;
			GotoXY(72,12+3*i+1) ;  cout << t.sL;
		}
		if( i == n ){
			KhungMenus(10,12+3*i,60,3); 
			GotoXY(11 , 12+3*i +1) ; cout << "Tong: "<<a ;
			for(int j = 0 ; j < 5 ; j++){
				double tyLe = (double)tong[4-j] / a ;
				GotoXY(21 + 10*j , 12 + 3*i + 1) ; cout << tong[4-j] ;
				GotoXY(26 + 10*j , 12 + 3*i + 1); cout <<  roundf(tyLe * 100) ;
			}
			KhungMenus(71 , 12+3*i ,10,3) ;
			GotoXY(72,12+3*i+1) ;  cout << a;
		}
	
		KhungMenus5(12+3*i);
		ThongKes.pop_front();
		ThongKes.push_back(t);
	}
	GotoXY(5,0);
	cout << "SL SV Gioi Va Kha : " << s;
	MenuMain(30 , 15+3*n);
}
// M5-2  : Thong Tin Can THong Ke`
void ThongKeM2(int &vt , list<SinhVien> &listSV){
	char text[100] = " Thong Tin Can Thong Ke " ;
	list<SinhVien> listSV1 ;
	list<THONGKE> ThongKes ;
	listSV1 = listSV ;
	switch(vt){
		// MSV
		case 1 :
			system("cls");	
			ThongKeLop(listSV1,ThongKes);
			Menus1(vt,listSV);
			break;
		case 2 :
			system("cls");
			KhungThongKe();
			ThongKeKQHT(listSV1,ThongKes,listSV.size());
			Menus1(vt,listSV);		
			break;		
		case 3 : 
			Menus1(vt , listSV);
			break;
	}
}
//M6 - Huong dan cach dung
void HuongDan(){
	
	TextColor(15);
			
			cout << "					 Cach Su Dung \n \n \n " ;
		
			cout <<"+> Dung mui ten len xuong tren ban phim de di chuyen len  xuong cac Menu .\n\n\n  " ;
			cout <<"+> Chon Menu thi nhan phim -> ' Enter ' tren bàn phim .\n\n\n\n\n\n    " ;
			
			cout <<"+>  Menu1 : cap nhat cac thong tin cua Sinh Vien .\n\n \n   ";
			cout <<"            1.Them thong tin Sinh Vien : Them du lieu tu ban phim hoac them du lieu tu file.\n\n\n    ";
			cout <<"            2.Sua thong tin sinh vien : Nhap ma Sinh Vien cua Sinh Vien can sua .\n\n\n  ";
			cout <<"            3.Xoa thong tin sinh vien : Nhap ma Sinh Vien cua Sinh Vien can Xoa .\n\n\n\n\n\n   ";
			
			
			cout <<"+>  Menu2 : In danh Sach Thong Tin Sinh Vien. \n\n \n ";
			cout <<" 			1.In danh sach thong tin da co trong danh sach tren man hinh console .\n\n \n   ";
			cout << " 			2.In danh sach thong tin da co trong danh sach ra 1 file .\n \n \n ";
			cout <<" 						He Thong Dang UpDate ......... (-.-) ........";
}

// M7 :  Thoat  
void thoat(){
	
}

