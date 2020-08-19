#include "sapXep.h"

using namespace std ;

stack <char> st ;
// list -> SV[]// giúp chuyen List -> SV[] de sap xep de dang hon
void SaoChepDS1( list<SinhVien> &listSV , SinhVien SV[]  ){
	int i = 0 ;
	int n = listSV.size() ;
	while(i < n ){
		SV[i] = listSV.front();
		listSV.pop_front();
		i++;	
	}
}
void SaoChepDS2(list<SinhVien> &listSV , SinhVien SV[] , int n ){
	for(int i = 0 ; i < n ; i ++ ){
		if(listSV.empty() == 1 ) listSV.push_front(SV[i]);
		else listSV.push_back(SV[i]);
	}	
}
void DoiCho(SinhVien &so1 , SinhVien &so2 ){
	SinhVien temp ;
	temp = so1 ;
	so1 = so2 ;
	so2 = temp ;	
}
// dao 1 cau chuoi : Nguyen Van Hien -> Hien Van Nguyen
string DaoCau(string str){
	//nguyen van hien
	string b = "";
	int k = 0 ;
	for(int i = str.length() - 1 ; i >= 0 ; i -- ){
		char ch = str[i] ;
		if(ch != ' '){
		// them vao stack
			st.push(ch);
		}
		else{
			k += 1;
			while(st.empty() == 0 ){
				// = ptu dau cua stack
				b += st.top() ;
				// bo phan tu tren dinh cua stack
				st.pop();
			}
			if( k == 1 ){
				b  += " ";
			}
		}	
	}
	b += " ";
	while(st.empty() == 0 ){
		b += st.top();
		st.pop();
	}
	return b;
}


void SapXepChon( SinhVien SV[] ,int n , int x ){
	for(int i = 0 ; i < n - 1 ; i ++ ){
		for(int j = i+1 ; j < n ; j++){
			switch(x){
				case 1 :
					if( SV[i].GetMaSV() > SV[j].GetMaSV() ) 
						DoiCho(SV[i], SV[j]) ;	
					break;
					
				case 2 :
					if( DaoCau( SV[i].GetHoTen() ) > DaoCau( SV[j].GetHoTen() ) ) 
						DoiCho(SV[i], SV[j]) ;
					break;
						
				case 3 :
					if( DaoCau( SV[i].GetNgaySinh() ) > DaoCau( SV[j].GetNgaySinh() ) ) 
						DoiCho(SV[i], SV[j]) ;
					break;
					
				case 4 :
					if( SV[i].GetDiemTB() > SV[j].GetDiemTB() ) 
						DoiCho(SV[i], SV[j]) ;
					break;	
			}	
		}	
	}
}
// bubble 
void SapXepNoiBot( SinhVien SV[] , int n , int x ){
	for(int k = 0 ; k < n ; k++ ){
		for(int i = 0 ; i < n -1  ; i ++ ){	
			int j = i + 1;
			switch(x){
				case 1 :
					if( SV[i].GetMaSV() > SV[j].GetMaSV() ) 
						DoiCho(SV[i], SV[j]) ;							
					break;
				
				case 2 :					
					if( DaoCau( SV[i].GetHoTen() ) > DaoCau( SV[j].GetHoTen() ) ) 
						DoiCho(SV[i], SV[j]) ;
					break;	
				case 3 :					
					if( DaoCau( SV[i].GetNgaySinh() ) > DaoCau( SV[j].GetNgaySinh() ) ) 
						DoiCho(SV[i], SV[j]) ;
					break;
				case 4 :					
					if( SV[i].GetDiemTB() > SV[j].GetDiemTB() ) 
						DoiCho(SV[i], SV[j]) ;
					break;	
				}
			}
		}
}
// sap xep chen
void SapXepChen(SinhVien SV[] , int n , int x){
	SinhVien key;
	for (int i = 1; i < n; i++){
   	
       	key = SV[i];
    	int j = i-1;
    	switch(x){
    		case 1 :
       			while (j >= 0 && SV[j].GetMaSV()> key.GetMaSV() ){
           			SV[j+1] = SV[j];
          			 j = j-1;         			 
       			}
       			SV[j+1] = key;
       				
				break;
			case 2 :
				while (j >= 0 && DaoCau( SV[j].GetHoTen() ) > DaoCau( key.GetHoTen() ) ){					
           			SV[j+1] = SV[j];
          			j = j-1;
       			}
       			SV[j+1] = key;
				break;
				
			case 3 :
       			while (j >= 0 && DaoCau( SV[j].GetNgaySinh() ) > DaoCau( key.GetNgaySinh() ) ){       				
           			SV[j+1] = SV[j];
          			j = j-1;	 
       			}
       			SV[j+1] = key;
				break;
				
			case 4 :
				while (j >= 0 && SV[j].GetDiemTB() > key.GetDiemTB() ){					
           			SV[j+1] = SV[j];
          			 j = j-1;
       			}	
       			SV[j+1] = key;
				break;	
		}		
	}
}
int ChiaDeTri(int x , SinhVien SV[] , int low, int high ){
    string pivot1 = SV[high].GetMaSV() ;
    double pivot4 = SV[high].GetDiemTB() ;
    
    string pivot2 = DaoCau( SV[high].GetHoTen() );
    string pivot3 = DaoCau( SV[high].GetNgaySinh() );
    
    int left = low;
    int right = high - 1;
    
    while(true){
    	switch(x){
    		case 1 :
    			while(left <= right && SV[left].GetMaSV() < pivot1) left++; 
        		while(right >= left && SV[right].GetMaSV() > pivot1) right--;
        		break;
        		
        	case 2 : 
				while(left <= right && DaoCau( SV[left].GetHoTen() ) < pivot2) left++; 
        		while(right >= left && DaoCau( SV[right].GetHoTen() ) > pivot2) right--;
				break;
				
			case 3 :
				
    			while(left <= right && DaoCau( SV[left].GetNgaySinh() ) < pivot3 ) left++; 
        		while(right >= left && DaoCau( SV[right].GetNgaySinh() ) > pivot3 ) right--;	
        		break;
        		
        	case 4 : 
				while(left <= right && SV[left].GetDiemTB() < pivot4) left++; 
        		while(right >= left && SV[right].GetDiemTB() > pivot4) right--;	
        		break;		
		}
        if (left >= right) break; 
        DoiCho(SV[left],SV[right]) ;
        
        left++; 
        right--; 
	}
    DoiCho(SV[left],SV[high]) ;
    return left; 
    
}
void SapXepNhanh( int x , SinhVien SV[] ,int low, int high ){
    if (low < high)
    {
        int pi = ChiaDeTri(x, SV, low, high);
        SapXepNhanh(x , SV, low, pi - 1);
        SapXepNhanh(x , SV ,pi + 1, high);
    }

}

