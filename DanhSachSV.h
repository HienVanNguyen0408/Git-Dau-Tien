#include"SinhVien.h"
#include<conio.h>
#include<fstream>
#include<stack>
using namespace std;


//	SinhVien SV[] ;
	bool Check(string , int & );		
	bool CheckNgay(int , int , int );	
		
		
	void ReadFile(list<SinhVien> & );
	void WriteFile(list<SinhVien> & , char * );
		
	void NhapThongTin(SinhVien &, int , int );	
	void NhapDS(  list<SinhVien> & , SinhVien  , int  , int  );
	void SuaNgaySinh(SinhVien , int , int );
	
	void ShowDS( list<SinhVien> & ,int  , int  );	
	
		

