#include "BinaryTree.h"

// node moi 
node* NewNode(  node *root, Data s  ){ 

	root = new node;
	root->key = s ;
	root->left = root->right = NULL;
	return root;	
} 

node *MSV(node *root , SinhVien &s , int x){
	if (root == NULL) return NewNode(root,s);
  	else{
  		if (s.GetMaSV() <= root->key.GetMaSV() ) 
	 		root->left  = Insert(root->left, s,x); 
	  		
    	else if (s.GetMaSV() > root->key.GetMaSV() )
        	root->right  = Insert(root->right, s,x ) ; 
        return root;		
	}  
}
node *MaLop(node *root , SinhVien &s , int x){
	if (root == NULL) return NewNode(root,s);
  	else{
  		if (s.GetMaLop() <= root->key.GetMaLop() ) 
			root->left  = Insert(root->left, s,x ); 
	  		
    	else if (s.GetMaLop() > root->key.GetMaLop() )
        	root->right  = Insert(root->right, s,x ) ; 
		return root;	
					
	}
}
node *HoTen(node *root , SinhVien &s , int x){
	if (root == NULL) return NewNode(root,s);
  	else{
  		if (s.GetHoTen() <= root->key.GetHoTen() ) 
			root->left  = Insert(root->left, s,x ); 
	  		
    	else if (s.GetHoTen() > root->key.GetHoTen() )
        	root->right  = Insert(root->right, s,x ) ; 
		return root;	
					
	}
}
node *NgaySinh(node *root , SinhVien &s , int x){
	if (root == NULL) return NewNode(root,s);
  	else{
  		if (s.GetNgaySinh() <= root->key.GetNgaySinh() ) 
			root->left  = Insert(root->left, s,x ); 
	  		
    	else if (s.GetNgaySinh() > root->key.GetNgaySinh() )
        	root->right  = Insert(root->right, s,x ) ; 
		return root;	
					
	}
}
node *DiemTB(node *root , SinhVien &s , int x){
	if (root == NULL) return NewNode(root,s);
  	else{
  		if (s.GetDiemTB() <= root->key.GetDiemTB() ) 
			root->left  = Insert(root->left, s,x ); 
	  		
    	else if (s.GetDiemTB() > root->key.GetDiemTB() )
        	root->right  = Insert(root->right, s,x ) ; 
		return root;				
	}
}
// them 1 node vao cay  
node* Insert(node *root, SinhVien s , int x ) { 
    switch(x){
    	case 1 :
    		MSV(root,s,x);
			break;
			// // Cay Nhi Phan Tim Kiem : Ma Lop
		case 2 :
			MaLop(root,s,x);
			break;
			// Cay Nhi Phan Tim Kiem : Ho Va Ten
		case 3 :
			HoTen(root,s,x);
			break;
			// Cay Nhi Phan Tim Kiem : Ngay SInh
		case 4 :
			NgaySinh(root,s,x);
			break;
		// Cay Nhi Phan Tim Kiem : Diem Trung Binh
		case 5 :
			DiemTB(root,s,x);	
	}
} 
   

