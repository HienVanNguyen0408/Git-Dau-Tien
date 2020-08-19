#ifndef SINHVIEN_H
#define SINHVIEN_H

#include<iostream>
#include<list>
#include"KhungMenu.h"

using namespace std;
class SinhVien
{ 
	private:
		string maSV ;
		string maLop ;
		string ngaySinh , hoTen ;
		double diemTB ;
		int sLSinhVien ;
		
	public:
		
		// Get Set de cac bien private co the dc truy cap den o class khac 
		void SetMaSV(string ) ;
		void SetMaLop(string ) ;
		void SetHoTen(string ) ;
		void SetNgaySinh(string ) ;
		void SetDiemTB(double ) ;
		void SetSLSinhVien(int);
		
		string GetMaSV() ;
		string GetMaLop() ;
		string GetHoTen() ;
		string GetNgaySinh() ;
		double GetDiemTB() ; 
		int GetSLSinhVien();
		
		SinhVien();
		SinhVien( string  , string  , string , string, double   );
		
		
		void NhapMaSV();
		void NhapMaLop();
		void NhapHoTen();
		void NhapNgaySinh();
		void NhapDiemTB();
		// show tat ca cac tt cua sinh vien
		void Show(SinhVien , int , int);
		
		friend bool operator > (SinhVien , SinhVien ) ;
		friend bool operator < (SinhVien , SinhVien ) ;
		
//		void operator = ( SinhVien ) ;
		
		friend ostream & operator << (ostream & , SinhVien & );
		
	protected:
};

#endif
