#include "SinhVien.h"
#include"SapXep.h"

using namespace std;

// khai bao  1 danh sach lien ket (kieu sinhVien );	

list <SinhVien> listSV;

SinhVien::SinhVien(){
	 diemTB = 0;
	 
	maSV = maLop = hoTen = ngaySinh = "";
	sLSinhVien = 0 ;
}

SinhVien::SinhVien( string maSV_ , string maLop_ ,string hoTen_ , string ngaySinh_, double diemTB_ ){
	
	maSV = maSV_ ;
	maLop = maLop_ ;
	diemTB = diemTB_ ;
	hoTen = hoTen_ ;
	ngaySinh = ngaySinh_;
	
}

void SinhVien::SetMaSV( string maSV_ ){
	
	maSV = maSV_;
}
void SinhVien::SetMaLop( string maLop_ ){
	
	maLop = maLop_ ;
}

void SinhVien::SetHoTen( string hoTen_ ){
	
	hoTen = hoTen_ ;
}

void SinhVien::SetNgaySinh( string ngaySinh_ ){
	
	ngaySinh = ngaySinh_;	
}

void SinhVien::SetDiemTB( double diemTB_ ){
	
	diemTB = diemTB_ ;
}

void SinhVien::SetSLSinhVien( int sLSinhVien_ ){
	
	sLSinhVien = sLSinhVien_ ; 
}


string SinhVien::GetMaSV(){

	return maSV ;
}

string SinhVien::GetMaLop(){

	return maLop ;
}

string SinhVien::GetHoTen(){
	
	return hoTen ;	
}

string SinhVien::GetNgaySinh(){
	
	return ngaySinh ;
}

double SinhVien::GetDiemTB(){
	
	return diemTB ;
}

int SinhVien::GetSLSinhVien(){
	
	return sLSinhVien ;
}


void SinhVien::NhapMaSV(){
	cout << "  Ma Sinh Vien : " ;
	getline(cin,maSV);
}

void SinhVien::NhapMaLop(){
	cout << " Ma Lop : " ;
	getline(cin,maLop);
}

void SinhVien::NhapHoTen(){
	cout << " Ho Ten : ";
	getline(cin,hoTen);
}

void SinhVien::NhapNgaySinh(){
	cout << " Ngay Sinh  : ";
	getline(cin,ngaySinh);
}

void SinhVien::NhapDiemTB(){
	cout << " Diem TB  : ";
	cin >> diemTB ;
}

void SinhVien::Show(SinhVien sv, int x , int y){
	
		GotoXY( x + 1 , y + 2 );
		cout <<" Ma Sinh Vien : " << sv.GetMaSV() <<endl;
		
		GotoXY( x + 1 , y + 3 );
		cout <<" Ma Lop : " << sv.GetMaLop() <<endl;
		
		GotoXY( x + 1 , y + 4 );
		cout <<" Ho Va Ten  : " << sv.GetHoTen() <<endl;
		
		GotoXY( x + 1 , y + 5 );
		cout <<" Ngay Sinh  : " << sv.GetNgaySinh() <<endl;
		
		GotoXY( x + 1 , y + 6 );
		cout <<" Diem TB : " << sv.GetDiemTB() <<endl;
		
}

bool operator > (SinhVien s1 , SinhVien s2 ){
	if(s1.GetMaSV() > s2.GetMaSV() ) return true ;
	else return false ; 
}

bool operator < (SinhVien s1 , SinhVien s2 ){
	if(s1.GetMaSV() < s2.GetMaSV() ) return true ;
	else return false ; 
}
//
//void SinhVien::operator = (SinhVien s1 ){
//	diemTB = s1.diemTB;
//	maSV = s1.maSV;
//	maLop = s1.maLop;
//	hoTen = s1.hoTen;
//	ngaySinh = s1.ngaySinh;
//}
ostream & operator << (ostream &out , SinhVien &sv ){
	out << "\nMa Sinh Vien : "<<sv.GetMaSV()<<"\nMa Lop : "<< sv.GetMaLop()<<"\nHo Ten : "<<sv.GetHoTen()<<"\nNgay Sinh : "<<sv.GetNgaySinh()
	<< "\nDiem TB : "<<sv.GetDiemTB();
	return out ;
	
}

