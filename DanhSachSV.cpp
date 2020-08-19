#include "DanhSachSV.h"

stack <char> st1 ;
// check ngay thang nam co dung ko ; 1 3 5 7 8 10 12 : 31 ngay , 2 co 28 hoac 29
// 4 6 9 11 co 30 ngay , co 12 thang ; nam tu 1975 - 2020 ;
bool Check(string a, int &z ){
	int j = 0 ;
	string b[10];
	int c[10] ;
	for(int i = 0 ; i < a.length() ; i ++ ){
		if( a[i] != '/' ){
			b[j] += a[i] ;
		}
		else if(a[i] == '/'){
			c[j] = atoi(b[j].c_str());
			j++;
		}
	}
	c[j] = atoi(b[j].c_str());
	// atoi(a.c_str()) -> string a = "20" -> int = 20 ; 
	// j > 3 :  ngay thang nam ko theo kieu dd/mm/yyyy;
	if(j > 2 ) return false ;
	else if(j <= 2 ){
		if(c[2] <= 2020 && c[2] >= 1975 ){
			// thang 1 3 5 7 8 10 12
			if( c[1] == 1 ||c[1] == 3 || c[1] == 5 || c[1] == 7 || c[1] == 8 || c[1] == 10 || c[1] == 12 ){
				if(  c[0] >= 1 && c[0] <= 31 ){
					return true ;
				}
				else{
					z = 1;
					return false ;
				}
			}
			// thang 2 
			else if( c[1] == 2 ){
				if( c[2] % 4 == 0  ){
					if( c[0] >= 1 && c[0] <= 29 ){
						return true ;
					}
					else{
						z = 1;
						return false ;
					}
				}
				else if( c[2] % 4 != 0 ){
					if( c[0] >= 1 && c[0] <= 28 ){
						return true ;
					}
					else{
						z = 1;
						return false ;
					}
				}
			}
			// ca thang con lai
			else if( c[1] == 4 || c[1] == 6 || c[1] == 9 || c[1] == 11 ){
				if( c[0] >= 1 && c[0] <= 30 ){
					return true ;
				}
				else{
					z = 1;
					return false ;
				}	
			}
			else {
				z = 2 ;
				return false ;
			}		
		}
		z = 3;
		return false ;
	}
}
void SuaNgaySinh( SinhVien sv , int x , int y ){
	int count ;
	while( Check( sv.GetNgaySinh() , count ) == false ){
		if( count == 1){
			GotoXY(x+5,y+10); cout <<" Nhap Sai Ngay ";
		}
		else if( count == 2){
			GotoXY(x+5,y+10);cout <<" Nhap Sai Thang ";
		}
		else if(count == 3){
			GotoXY(x+5,y+10);cout <<" Nhap Sai Nam ";
		}
		GotoXY( x + 14 , y + 5 );
		cout <<" dd/mm/yyyy ";
		GotoXY( x + 26 , y + 5 ); cout << " //VD: 04/08/2000 ";
		GotoXY( x + 1 , y + 5 );
		sv.NhapNgaySinh();
	}
}
void NhapThongTin(SinhVien &s , int x , int y ){
	GotoXY( x+1 , y+2 );
	s.NhapMaSV();
		
	GotoXY( x + 1 , y + 3 );
	s.NhapMaLop();
		
	GotoXY( x + 1 , y + 4 );
	s.NhapHoTen();	
	
	GotoXY( x + 14 , y + 5 );
	cout <<" dd/mm/yyyy ";
		
	GotoXY( x + 26 , y + 5 ); cout << " //VD: 04/08/2000 ";
	GotoXY( x + 1 , y + 5 );
		
	s.NhapNgaySinh();
	SuaNgaySinh(s,x,y);
		
	GotoXY( x + 1 , y + 6 );
	s.NhapDiemTB();
	GotoXY( x + 1 , y + 7 );
}
void NhapDS( list<SinhVien> &listSV , SinhVien sv , int x , int y ){
	for( int i = 0 ; i < sv.GetSLSinhVien()  ; i ++ ){
		KhungMenus(x , y, 50 , 10);
		GotoXY( x+5 , y +1 ); cout << " Thong Tin SV thu "<< i + 1;
		
		cin.ignore();
		NhapThongTin(sv,x,y);
		
		y += 13;
		if( listSV.empty() == 1 ){
			listSV.push_front(sv);	
		}
		else listSV.push_back(sv) ;	
	}	
}
void ShowDS( list<SinhVien> &listSV , int x , int y ) {
	int i = 0 ;
	SinhVien sv ;
	while( i < listSV.size() ){
		SinhVien s1 = listSV.front();
		KhungMenus(1,9+4*i,85,3); 
		GotoXY(2,10+4*i); cout << i+1;
		GotoXY(8,10+4*i); cout <<s1.GetMaSV();
		GotoXY(27,10+4*i); cout <<s1.GetMaLop();
		GotoXY(45,10+4*i); cout <<s1.GetHoTen();
		GotoXY(65,10+4*i); cout <<s1.GetNgaySinh();
		GotoXY(77,10+4*i); cout <<s1.GetDiemTB();
		KhungMenus2(9+4*i);	
		
		listSV.pop_front();
		listSV.push_back(s1);
		i++;
	}	
}
void ReadFile( list<SinhVien> &listSV){
	string MaLop ,MaSV , HoTen , NgaySinh , str ;
	double DiemTB;
	ifstream in ;
	
	in.open( "bai2.input.txt",ios :: in );
	if(!in){
		cout <<" khong nhan duoc du lieu tu File ";
	}
	int i = 0 ;
	while(!in.eof() ){
		// xoa bo cac khoang trang ko can thiet khi nhan du lieu la 1 chuoi
		getline(in,MaSV);
		
		getline(in,MaLop);
		
		getline(in,HoTen);
	
	 	getline(in,NgaySinh);
		in >> DiemTB ; 
		in.ignore();
		
		getline(in,str);
		
		SinhVien sv( MaSV , MaLop , HoTen , NgaySinh , DiemTB) ;
		if(in.eof()) return ;
		if( listSV.empty() == 1 ){
			
			listSV.push_front( sv );
		}
		else listSV.push_back( sv ); 
	}
	in.close();
}
void WriteFile(list<SinhVien> &listSV , char *fileName ){
	ofstream out ;
	out.open( fileName ,ios :: out );
	SinhVien sv;
	int i = 0 ;
	
	while( i < listSV.size() ){
		
		sv = listSV.front();
		
		out << " Thong Tin SV thu "<< i + 1 <<endl<<endl;
		
		out <<" Ma Sinh Vien : "<<sv.GetMaSV()  <<endl;
		
		out <<" Ma Lop : " <<sv.GetMaLop() <<endl;
		
		out <<" Ho Va Ten  : " <<sv.GetHoTen() <<endl;
		
		out <<" Ngay Sinh  : "<< sv.GetNgaySinh()  <<endl;
		
		out <<" Diem TB : "<< sv.GetDiemTB() <<endl;
		
		out <<"\n\n";
		listSV.push_back( sv );
		listSV.pop_front();
		i ++ ;	
	}
	out.close();
}




