
#include"SapXep.h"
#include"ThongKe.h"
#include"SinhVien.h"
#include <math.h>
typedef char stri[40];
void KhungTieuDe(int , int , int , int , string );

void Menu( stri [] , int  , int & , string  );
void Menus1( int & , list<SinhVien> & );


void CapNhatSV( list<SinhVien> & , int & );
void ThemThongTinSV( list<SinhVien> & , int & );


void KhungInDanhSach();
void InDanhSach(list<SinhVien> & , int &);
void SuaThongTin(  list<SinhVien> &listSV , int x  , int y );
void Xoa( list<SinhVien> &listSV  );
void MenuMain(int , int );

void SapXepM1( int & , list<SinhVien> & );
void SapXepM2(int &, list<SinhVien> &);

void TimKiemM1( int & , list<SinhVien> & );
void TimKiemM2( int & , list<SinhVien> & );
void TimKiemTuanTu1(list<SinhVien> &, int  , string  , int  );
void TimKiemNhiPhan1(list<SinhVien> &, int  , string  , int  );
void KhungTimKiem(list<SinhVien> & , int );

void KhungThongKe();
void ThongKeM1( int & , list<SinhVien> & );
void ThongKeM2( int & , list<SinhVien>  & );
void ThongKeLop(list<SinhVien> & , list<THONGKE> &  );
void ThongKeKQHT(list<SinhVien> & , list<THONGKE> &  , int a);


void huongDan() ;
void thoat() ;


