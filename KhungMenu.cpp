#include "KhungMenu.h"
using namespace std;
void TextColor (int color){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , color);
}
void GotoXY (int x, int y){
    COORD coordinates;   
    coordinates.X = x;   
    coordinates.Y = y;     
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);       
}
void KhungMenus( int x , int y , int w , int h ){
	char vienGocTrenTrai = 218 , vienGocTrenPhai = 191,
	vienGocDuoiTrai = 192 , vienGocDuoiPhai = 217;
	char vienNgang = 196 , vienDoc = 179;// 2 vien ngang va doc cua Khung
	// in ra 4 goc cua Khung
	
	GotoXY( x , y ); cout << vienGocTrenTrai ;
	GotoXY( x + w - 1, y ) ; cout << vienGocTrenPhai;
	GotoXY( x, y + h -1 ) ; cout << vienGocDuoiTrai;
	GotoXY( x + w -1 , y + h -1 ) ; cout << vienGocDuoiPhai;
	
	
	// in ra 2 chieu ngang cua Khung
	for( int i = 0 ; i < w -2 ; i++ ){
		GotoXY( x + i + 1 ,y ); cout << vienNgang;
		GotoXY( x + i + 1 ,y + h -1 ); cout << vienNgang;
	}
	
	
	// in 2 chieu doc cua Khung
	for( int i = 0 ; i < h -2 ;i++ ){
		GotoXY( x , y + i + 1 ); cout << vienDoc;
		GotoXY( x + w - 1 ,y + i + 1 ); cout << vienDoc;
	}
	
	
}
void KhungMenus2( int y  ){
	
	GotoXY(6,y);cout << (char)194;
	GotoXY(6,y+1);cout << (char)179;
	GotoXY(6,y+2);cout << (char)193;
					
	GotoXY(25,y);cout << (char)194;
	GotoXY(25,y+1);cout << (char)179;
	GotoXY(25,y+2);cout << (char)193;
			
		
	GotoXY(35,y);cout << (char)194;
	GotoXY(35,y+1);cout << (char)179;
	GotoXY(35,y+2);cout << (char)193;
					
		
	GotoXY(63,y);cout << (char)194;
	GotoXY(63,y+1);cout << (char)179;
	GotoXY(63,y+2);cout << (char)193;
			
		
	GotoXY(76,y);cout << (char)194;
	GotoXY(76,y+1);cout << (char)179;
	GotoXY(76,y+2);cout << (char)193;
					
		
	
}
void KhungMenus3(int x , int y  ){
	
	GotoXY(x+6,y);cout << (char)194;
	GotoXY(x+6,y+1);cout << (char)179;
	GotoXY(x+6,y+2);cout << (char)193;
					
	GotoXY(x+25,y);cout << (char)194;
	GotoXY(x+25,y+1);cout << (char)179;
	GotoXY(x+25,y+2);cout << (char)193;
				
}
void KhungMenus4(int x, int y){

	GotoXY(x+1,y+1); cout <<"Xuat Sac";
	GotoXY(x+10,y);cout << (char)194;
	GotoXY(x+10,y+1);cout << (char)179;
	GotoXY(x+10,y+2);cout << (char)193;
	
	GotoXY(x+12,y+1); cout <<"Gioi";
	GotoXY(x+20,y);cout << (char)194;
	GotoXY(x+20,y+1);cout << (char)179;
	GotoXY(x+20,y+2);cout << (char)193;
	
	GotoXY(x+22,y+1); cout <<"Kha";
	GotoXY(x+30,y);cout << (char)194;
	GotoXY(x+30,y+1);cout << (char)179;
	GotoXY(x+30,y+2);cout << (char)193;
	
	GotoXY(x+32,y+1); cout <<"TB";
	GotoXY(x+40,y);cout << (char)194;
	GotoXY(x+40,y+1);cout << (char)179;
	GotoXY(x+40,y+2);cout << (char)193;
	
	GotoXY(x+42,y+1); cout << "Yeu";
}
void KhungMenus5( int y ){
		
	
	GotoXY(20,y);cout << (char)194;
	GotoXY(20,y+1);cout << (char)179;
	GotoXY(20,y+2);cout << (char)193;
	
	for(int i = 0 ; i < 5 ; i++ ){
			
		GotoXY(25+10*i,y);cout << (char)194;
		GotoXY(25+10*i,y+1);cout << (char)179;
		GotoXY(25+10*i,y+2);cout << (char)193;

		if( i < 4 ){
			GotoXY(30+10*i,y);cout << (char)194;
			GotoXY(30+10*i,y+1);cout << (char)179;
			GotoXY(30+10*i,y+2);cout << (char)193;
		}
		
	}
				
}
