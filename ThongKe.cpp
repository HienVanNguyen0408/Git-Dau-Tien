#include "ThongKe.h"

//void PushListThongKe();
void XepLoaiDiem(double diem , int a[] ){
	//yeu
	if( diem >= 0 && diem < 2.0 ) a[0] += 1;	
	// TB
	else if( diem >= 2.0 && diem < 2.5  ) a[1] += 1 ;
	//Kha
	else if( diem >= 2.5 && diem < 3.0 ) a[2] += 1 ;
	//Gioi		
	else if( diem >= 3.0 && diem < 3.6 ) a[3] += 1 ;
	//Xuat Sac
	else if(diem >= 3.6 && diem <= 4.0 ) a[4] += 1 ;
}
void ThongKe( list<SinhVien> &listSV1 , list<THONGKE> &thongKes  ,int x ){
	int n = listSV1.size() , n2 ;
	int i = 0 ;
	SinhVien s1,s2 ;
	THONGKE t;
	int a[5];
	double diem;
	while( i < n ){
		if( listSV1.empty() == 0 ){
			s1 = listSV1.front();
			int j = 0, dem = 0 ;
			for(int m = 0 ; m < 5 ; m ++ ) a[m] = 0;
			n2 = listSV1.size();
			while( j < n2 ){
				s2 = listSV1.front();
				diem = s2.GetDiemTB();
				if( s2.GetMaLop() != s1.GetMaLop() ){
					listSV1.push_back(s2);
				}
				else{
					dem ++;
					switch(x){
						case 1 :
							break;
						case 2 :
							XepLoaiDiem(diem,a);
							break;	
					}			
				}
				listSV1.pop_front();
				j++;
			}
			for(int m = 0 ; m < 5 ; m ++ ){
				t.d[m] = a[m];
			}
			t.str = s1.GetMaLop();
			t.sL = dem;								
			if(thongKes.empty() == 1) thongKes.push_front(t);
			else thongKes.push_back(t);
		
			i++;
		}
		else i = n;
	}
			
}
