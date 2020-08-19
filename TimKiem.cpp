#include "TimKiem.h"
int PushListTuanTu(list<SinhVien> &listSV2 , SinhVien s2 ,SinhVien s1 , int x ){
	switch(x){
		case 1 :
			if( s1.GetMaSV() == s2.GetMaSV() ){
				listSV2.push_back(s2);
			}
			break;
			
		case 2 : 
			if( s1.GetMaLop() == s2.GetMaLop() ){
				listSV2.push_back(s2);
			}
			break;	
		case 3 :
			if( s1.GetHoTen() == s2.GetHoTen() ){
				listSV2.push_back(s2);
			}
			break;
		case 4 :
			if( s1.GetNgaySinh() == s2.GetNgaySinh() ){
				listSV2.push_back(s2);
			}
			break;
		case 5 :
			if( s1.GetDiemTB() == s2.GetDiemTB() ){
				listSV2.push_back(s2);
			}
			break;			
	}
	listSV2.pop_front();
	return listSV2.size() ;	
}
void PushListNhiPhan(list<SinhVien> &listSV2 , SinhVien s2 ,SinhVien s1 , int x){
	switch(x){
		case 1 :
			if(s2.GetMaSV() == s1.GetMaSV() ){
				if(listSV2.empty() == 1 ) listSV2.push_front(s2);
				else listSV2.push_back(s2);
			}	
			break;
		case 2 :
			if(s2.GetMaLop() == s1.GetMaLop() ){
				if(listSV2.empty() == 1 ) listSV2.push_front(s2);
				else listSV2.push_back(s2);
				
			}
			break;
		case 3 :
			if(s2.GetHoTen() == s1.GetHoTen() ){
				if(listSV2.empty() == 1 ) listSV2.push_front(s2);
				else listSV2.push_back(s2);
			}
			break;
		case 4 :
			if(s2.GetNgaySinh() == s1.GetNgaySinh() ){
				if(listSV2.empty() == 1 ) listSV2.push_front(s2);
				else listSV2.push_back(s2);
			}
			break;
		case 5 :
			if(s2.GetDiemTB() == s1.GetDiemTB() ){
				if(listSV2.empty() == 1 ) listSV2.push_front(s2);
				else listSV2.push_back(s2);
			}
			break;				
	}
}
int TimKiemTuanTu(list<SinhVien> &listSV2 ,  SinhVien s1 , int x){
	SinhVien s2;
	int i = 0;
	int n = listSV2.size();
	int dem = 0;
	while(i < n ){
		s2 = listSV2.front();
		dem = PushListTuanTu(listSV2,s2,s1,x);
		i++;		
	}
	return dem;											
}
void PushTree( list<SinhVien> &listSV2 , node *root, int x ){
	int n = listSV2.size();
	for(int i = 0 ; i < n ; i ++ ){
		Insert(root,listSV2.front(),x);
		listSV2.pop_front();
	}
}
void TimKiemNhiPhan(list<SinhVien> &listSV2 , node *root , SinhVien s1 , int x  ){
	int dem = 0 ;
	if(root != NULL){
		TimKiemNhiPhan(listSV2,root->right,s1,x) ;
		SinhVien s2 = root->key ;
		PushListNhiPhan(listSV2,s2,s1,x);
		TimKiemNhiPhan(listSV2,root->left,s1,x) ;
	}
}
