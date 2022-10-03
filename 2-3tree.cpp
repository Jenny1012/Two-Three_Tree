// 10827245 桑怡蓁 
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include <conio.h>
#include <complex>
#include <math.h>


using namespace std;

typedef struct cT{
	string rawR;
	string cnum ;
	string cname;
	string dnum;
	string dname;
	string category;
	string level ;
	int sNO;
	int tNO;
	int gNO;
	string county ;
	string department ;
	int total; // 序號

} collegeType ;

typedef struct cT2{
	int total;
	string dname;
} collegeItem ;

typedef struct cT3{
	int total;
	string cname;
} collegeItemB ;

class collegeList {

	public :
		int turnnum( string line )	;
		string token( int &first , int &i , string line ) ;
		void savefile( collegeType &content ) ;
		void Swap( int i , int j ) ;
		vector<collegeType> list;
		vector<collegeItem> list2;
} ;

collegeList CList ;
vector<collegeType> list;
vector<collegeItem> list2;
vector<collegeItemB> list3;
vector<collegeType> templist;

typedef struct Twothree{
	collegeItemB nodeitem;
	vector<collegeItemB> itemsA;
	vector<collegeItemB> itemsB;
	vector<collegeItemB> itemsC;
	bool isLeaf;
	int count;
	int type;
	struct Twothree *leftPtr;
	struct Twothree *middle;
	struct Twothree *rightPtr;
	struct Twothree *ptr4;  // 3-node
	struct Twothree *parent;
}nodeTypeA;

typedef struct AVL{
		collegeItem nodeitem;
		vector<collegeItem> items;
		int height;
		struct AVL *leftPtr;
		struct AVL *rightPtr;
} nodeType;

typedef nodeTypeA* twothreetree;
typedef nodeType* tree ;

class AVLTree{

	public :
		void insertnode( tree &root, collegeItem nodeitem );
		tree createAVLtree( char* file );
		int treeheight( tree root );
		tree checkBalanced( tree node );
		tree LL( tree x );
		tree RR( tree x );
		tree LR( tree x );
		tree RL( tree x );
		void print( tree root );
		void search2( string &name, tree root );
};

class Tree23{

	public :
		twothreetree insertnode2( twothreetree root23, collegeItemB nodeitem  ) ;
		twothreetree create23tree( char* file );
		int treeheight2( twothreetree root );
		twothreetree split( twothreetree root23 ) ;
		twothreetree Swap( twothreetree node );
		twothreetree Swap2( twothreetree node );
		void print2( twothreetree root );
		void search1( string &name, twothreetree root23 );
};

class Mission3 {
	public :
		void print( string schoolname, string departmentname );
};

void Mission3 :: print( string schoolname, string departmentname ) { 
	bool same = false;
	int type = 0;
		
	string all = "*";
	string none = "X";
	if ( strcmp( (char*)schoolname.c_str(), (char*)none.c_str() ) == 0 ) {
		;
	} // if
	else if ( strcmp( (char*)departmentname.c_str(), (char*)none.c_str() ) == 0 ) {
		;
	} // else if
	else if ( strcmp( (char*)schoolname.c_str(), (char*)all.c_str() ) == 0 && strcmp( (char*)departmentname.c_str(), (char*)all.c_str() ) == 0 ) { // all *
		for ( int i = 0 ; i < templist.size() ; i++ ) {
			int temp = i+1;
			cout << temp << "." << setw(8) << "[" << temp <<  "]" << setw(15) << templist[i].cname << setw(15) << templist[i].dname
			<< setw(15) << templist[i].category << setw(15) << templist[i].level << setw(15) << templist[i].sNO << endl;
		} // for
	} // if
	else if ( strcmp( (char*)schoolname.c_str(), (char*)all.c_str() ) == 0 ) {   // school is *
		int temp = 0;
		for ( int i = 0 ; i < templist.size() ; i++ ) {
			if ( strcmp( (char*)departmentname.c_str(), (char*)templist[i].dname.c_str() ) == 0 ) {
				temp++;
				cout << temp << "." << setw(8) << "[" << temp <<  "]" << setw(15) << templist[i].cname << setw(15) << templist[i].dname
			<< setw(15) << templist[i].category << setw(15) << templist[i].level << setw(15) << templist[i].sNO << endl;
			} // if
		} // for
	} // else if
	else if ( strcmp( (char*)departmentname.c_str(), (char*)all.c_str() ) == 0 ) {   // department is *
		int temp = 0;
		for ( int i = 0 ; i < templist.size() ; i++ ) {
			if ( strcmp( (char*)schoolname.c_str(), (char*)templist[i].cname.c_str() ) == 0 ) {
				temp++;
				cout << temp << "." << setw(8) << "[" << temp <<  "]" << setw(15) << templist[i].cname << setw(15) << templist[i].dname
			<< setw(15) << templist[i].category << setw(15) << templist[i].level << setw(15) << templist[i].sNO << endl;
			} // if
		} // for
	} // else if
	else {
		int temp = 0;
		for ( int i = 0 ; i < templist.size() ; i++ ) {
			if ( strcmp( (char*)schoolname.c_str(), (char*)templist[i].cname.c_str() ) == 0 ) {
				if ( strcmp( (char*)departmentname.c_str(), (char*)templist[i].dname.c_str() ) == 0 ) {
					temp++;
					cout << temp << "." << setw(8) << "[" << templist[i].total <<  "]" << setw(15) << templist[i].cname << setw(15) << templist[i].dname
				<< setw(15) << templist[i].category << setw(15) << templist[i].level << setw(15) << templist[i].sNO << endl;
				} // if
				else {
					;
				} // else
			} // if
		} // for
	} // else
	templist.clear();
} // print()

string collegeList :: token ( int &first , int &i , string line ) {
		if ( i == 0 )
			first = 0 ; // 從頭開始
		else
			first = i ; // 從被切過的地方繼續(尚未換行)

		int num = 0 ;

		while (  line[i] != '\t' &&  line[i] != '\0' ) {
			num++ ;
			i++ ;
		} // while

		if( line[i] == '\0')
			 ;
		else
			i++ ;

		return line.substr( first, num ) ; // 切token
} // token

int collegeList :: turnnum ( string line ) {
    int total = 0;
    char temp;
    int num = 0;
    int i = 0;
    int finish = 0;
    if ( line[0] == '\"' ) {
    	while ( line[i] != '\0' ) {
			if ( line[i] == '\"' || line[i] == ',' ) {
				;
			} // if
			else {
				temp = (char)line[i];
				num = (int)temp;
				num = num - 48;
				total = total * 10 + num;
			} // else

			i = i + 1;
		} // while
	} // if
	else {
		total = atoi( line.c_str() );
	} // else

	return total;
} // turnnum

void collegeList :: savefile ( collegeType &content ) {
    string line  ;
	int num = 0 ;
	int first = 0 ;
	int totalnum = 0;

	content.cnum = CList.token( first, num, content.rawR ) ; // college code

	content.cname = CList.token( first, num, content.rawR ) ; // college name

	content.dnum = CList.token( first, num, content.rawR ) ; // department code

	content.dname = CList.token( first, num, content.rawR ) ; // department name

	content.category = CList.token( first, num, content.rawR ) ; // 日間∕進修別

	content.level = CList.token( first, num, content.rawR ) ; // 等級別

	line = CList.token( first, num, content.rawR ) ; // number of students
	content.sNO = turnnum( line );


	line = CList.token( first, num, content.rawR ) ;	// number of teachers
	content.tNO = turnnum( line );


	line = CList.token( first, num, content.rawR ) ;	// number of graduates
	content.gNO = turnnum( line );


	content.county = CList.token( first, num, content.rawR ) ; // county name

	content.department = CList.token( first, num, content.rawR ) ;
} //savefile

tree AVLTree :: LL( tree x ) {
	tree y = x->leftPtr;
	x->leftPtr = y->rightPtr;
	y->rightPtr = x;
	return y;
} // LL()

tree AVLTree :: RR( tree x ) {
	tree y = x->rightPtr;
	x->rightPtr = y->leftPtr;
	y->leftPtr = x;
	return y;
} // RR()

tree AVLTree :: LR( tree x ) {
	x->leftPtr = RR( x->leftPtr );
	return LL( x );
} // LR()

tree AVLTree :: RL( tree x ) {
	x->rightPtr = LL( x->rightPtr );
	return RR( x );
} // RL()

int AVLTree :: treeheight( tree root ) {
	if ( root == NULL ) {
		return 0;
	} // if
	else {
		int rDepth = treeheight( root->rightPtr );
		int lDepth = treeheight( root->leftPtr );

		if ( lDepth > rDepth ) {
			return( lDepth+1 );
		} // if
		else {
			return( rDepth+1 );
		} // else
	} // else
} // treeheight()

int Tree23 :: treeheight2( twothreetree root23 ) {
	if ( root23 == NULL ) {
		return 0;
	} // if
	else {
		int rDepth = treeheight2( root23->rightPtr );
		int lDepth = treeheight2( root23->leftPtr );

		if ( lDepth > rDepth ) {
			return( lDepth+1 );
		} // if
		else {
			return( rDepth+1 );
		} // else
	} // else
} // treeheight2()

void AVLTree :: insertnode( tree &root, collegeItem nodeitem ) {
	tree newnode;

    newnode = new nodeType;
	newnode->nodeitem = nodeitem;
	newnode->leftPtr = NULL;
	newnode->rightPtr = NULL;

    if ( root == NULL ) { // 第一筆
    	root = newnode;
    	root->items.push_back( newnode->nodeitem );
    	return;
   	} // if
	else if ( strcmp( (char*)root->nodeitem.dname.c_str(), (char*)newnode->nodeitem.dname.c_str() ) > 0 ) {

		insertnode( root->leftPtr, nodeitem );

		if ( treeheight( root->leftPtr ) - treeheight( root->rightPtr ) > 1 ) {
			if ( strcmp( (char*)root->leftPtr->items[0].dname.c_str(), (char*)newnode->nodeitem.dname.c_str() ) > 0 ) {
				root = LL( root );
			} // if
			else {
				root = LR( root );
			} // else
		} // if
	}  // else if
	else if( strcmp( (char*)root->nodeitem.dname.c_str(), (char*)newnode->nodeitem.dname.c_str() ) < 0 ) {

		insertnode( root->rightPtr, nodeitem );

		if ( treeheight( root->leftPtr ) - treeheight( root->rightPtr ) < -1 ) {
			if ( strcmp( (char*)root->rightPtr->items[0].dname.c_str(), (char*)newnode->nodeitem.dname.c_str() ) < 0 ) {
				root = RR( root );
			} // if
			else {
				root = RL( root );
			} // else
		} // if
	} // else if
	else if ( strcmp( (char*)root->nodeitem.dname.c_str(), (char*)newnode->nodeitem.dname.c_str() ) == 0 ) {
		root->items.push_back( newnode->nodeitem );
		return ;
	} // else if
} // insertnode()

twothreetree Tree23 :: Swap( twothreetree node ) {
	vector <collegeItemB> temp;

	if ( strcmp( (char*)node->itemsA[0].cname.c_str(), (char*)node->itemsB[0].cname.c_str() ) > 0  ) {  // A > B
		for ( int i = 0 ; i < node->itemsA.size() ; i++ ) {
			temp.push_back( node->itemsA[i] );
		} // for

		node->itemsA.clear();
		for ( int j = 0 ; j < node->itemsB.size() ; j++ ) {
			node->itemsA.push_back( node->itemsB[j] );
		} // for

		node->itemsB.clear();
		for ( int k = 0 ; k < temp.size() ; k++ ) {
			node->itemsB.push_back( temp[k] );
		} // for

		temp.clear();
	} // if

	return node;
} // Swap()

twothreetree Tree23 :: Swap2( twothreetree node ) {
	vector <collegeItemB> temp;
	if ( strcmp( (char*)node->itemsB[0].cname.c_str(), (char*)node->itemsC[0].cname.c_str() ) < 0 ) {		// B < C
		;
	} // if
	else {																					  // B > C
		if ( strcmp( (char*)node->itemsA[0].cname.c_str(), (char*)node->itemsC[0].cname.c_str() ) > 0 ) {		// A > C ( C <-> A --> A <-> B )
			/*****************************ABC->CBA-->CAB*********************************/
			for ( int i = 0 ; i < node->itemsC.size() ; i++ ) {
				temp.push_back( node->itemsC[i] );
			} // for
			node->itemsC.clear();

			for ( int i = 0 ; i < node->itemsA.size() ; i++ ) {
				node->itemsC.push_back( node->itemsA[i] );
			} // for
			node->itemsA.clear();

			for ( int i = 0 ; i < temp.size() ; i++ ) {\
				node->itemsA.push_back( temp[i] );
			} // for
			temp.clear();

			/****************************CBA->CAB**********************************/
			for ( int i = 0 ; i < node->itemsC.size() ; i++ ) {
				temp.push_back( node->itemsC[i] );
			} // for
			node->itemsC.clear();

			for ( int i = 0 ; i < node->itemsB.size() ; i++ ) {
				node->itemsC.push_back( node->itemsB[i] );
			} // for
			node->itemsB.clear();

			for ( int i = 0 ; i < temp.size() ; i++ ) {
				node->itemsB.push_back( temp[i] );
			} // for
			temp.clear();
		} // if
		else { 		// C > A  ( B <-> C )
			/***********************ABC->ACB******************************************/
			for ( int i = 0 ; i < node->itemsB.size() ; i++ ) {
				temp.push_back( node->itemsB[i] );
			} // for
			node->itemsB.clear();

			for ( int i = 0 ; i < node->itemsC.size() ; i++ ) {
				node->itemsB.push_back( node->itemsC[i] );
			} // for
			node->itemsC.clear();

			for ( int i = 0 ; i < temp.size() ; i++ ) {
				node->itemsC.push_back( temp[i] );
			} // for
			temp.clear();
		} // else
	} // else

	return node;
} // Swap2()

twothreetree Tree23 :: split( twothreetree root23 ) {
	// leftPtr
	// ptr4
	// middle
	// rightPtr
	
	root23 = Swap( root23 );
	root23 = Swap2( root23 );
	twothreetree newnodeP;

	if ( root23->parent == NULL ) { // if n is a root
		newnodeP = new nodeTypeA;
		newnodeP->count = 0;
		newnodeP->isLeaf = false;
		newnodeP->leftPtr = NULL;
		newnodeP->middle = NULL;
		newnodeP->rightPtr = NULL;
		newnodeP->ptr4 = NULL;
		newnodeP->parent = NULL;
	} // if
	else {    // let p be the parent of n
		newnodeP = root23->parent;
	} // else

	twothreetree n1 = new nodeTypeA;
	twothreetree n2 = new nodeTypeA;

	for ( int i = 0 ; i < root23->itemsA.size() ; i++ ) {		// smallest
		n1->itemsA.push_back( root23->itemsA[i] );
	} // for
	n1->count = 1;
	n1->leftPtr = NULL;
	n1->middle = NULL;
	n1->rightPtr = NULL;
	n1->ptr4 = NULL;
	n1->itemsB.clear();
	n1->itemsC.clear();

	for ( int i = 0 ; i < root23->itemsC.size() ; i++ ) {			// largest
		n2->itemsA.push_back( root23->itemsC[i] );
	} // for
	n2->count = 1;
	n2->leftPtr = NULL;
	n2->middle = NULL;
	n2->rightPtr = NULL;
	n2->ptr4 = NULL;
	n2->itemsB.clear();
	n2->itemsC.clear();

	if ( root23->isLeaf == false ) {  // if n is not a leaf, it means it has 4 children
        n1->leftPtr = root23->leftPtr;  // b
        n1->rightPtr = root23->ptr4;    // c
        n2->leftPtr = root23->middle;   // d
        n2->rightPtr = root23->rightPtr; // e

		n1->leftPtr->parent = n1;
		n1->rightPtr->parent = n1;
		n2->leftPtr->parent = n2;
		n2->rightPtr->parent = n2;

		n1->isLeaf = false;
		n2->isLeaf = false;
		
		if ( newnodeP->count == 0 || ( newnodeP->count == 1 && newnodeP->leftPtr == NULL && newnodeP->rightPtr == NULL ) ) {
			newnodeP->leftPtr = n1;
			newnodeP->rightPtr = n2;
		} // if
		else if ( newnodeP->count == 1 && newnodeP->rightPtr->count == 3 ) {
			//newnodeP->count == 1 && newnodeP->leftPtr != NULL
			newnodeP->middle = n1;
			newnodeP->rightPtr = n2;
		} // else if
		else if ( newnodeP->count == 1 && newnodeP->leftPtr->count == 3 ) { 
			//newnodeP->count == 1 && newnodeP->rightPtr != NULL
			newnodeP->leftPtr = n1;
			newnodeP->middle = n2;
		} // else if
		else if ( newnodeP->count == 2 ) {
			if ( newnodeP->type == 1 ) { // left
				newnodeP->leftPtr = n1;
				newnodeP->ptr4 = n2;
			} // if
			else if ( newnodeP->type == 2 ) { // middle
				newnodeP->ptr4 = n1;
				newnodeP->middle = n2;
			} // else if
			else if ( newnodeP->type == 3 ) { // right
				newnodeP->ptr4 = newnodeP->middle;
				newnodeP->middle = n1;
				newnodeP->rightPtr = n2;
			} // else if
		} // else if
		newnodeP->type = 0;
		n1->parent = newnodeP;
		n2->parent = newnodeP;
	} // if

	vector<collegeItemB> temp;
	for ( int i = 0 ; i < root23->itemsB.size() ; i++ ) {  // 將中間要往上移的值先存起來
		temp.push_back( root23->itemsB[i] );
	} // for

	if ( newnodeP->count == 0 ) {   // is a root
		for ( int i = 0 ; i < temp.size() ; i++ ) {
			newnodeP->itemsA.push_back( temp[i] );
		} // for
		newnodeP->parent = NULL;
		newnodeP->count = 1;
		newnodeP->leftPtr = n1;
		newnodeP->rightPtr = n2;
		newnodeP->isLeaf = false;
		n1->parent = newnodeP;
		n2->parent = newnodeP;
		temp.clear();
	} // if
	else if ( newnodeP->count == 1 ) {
		for ( int i = 0 ; i < temp.size(); i++ ) {
			newnodeP->itemsB.push_back( temp[i] );
		} // for

		newnodeP = Swap( newnodeP );
		newnodeP->count = 2;
		newnodeP->isLeaf = false;

		if ( strcmp( (char*)root23->itemsA[0].cname.c_str(), (char*)newnodeP->leftPtr->itemsA[0].cname.c_str() ) == 0 ) { // left
			n1->parent = newnodeP;
			n2->parent = newnodeP;
			newnodeP->leftPtr = n1;
			newnodeP->middle = n2;
			temp.clear();
		} // if
		else if ( strcmp( (char*)root23->itemsA[0].cname.c_str(), (char*)newnodeP->rightPtr->itemsA[0].cname.c_str() ) == 0 ) { // right
			n1->parent = newnodeP;
			n2->parent = newnodeP;
			newnodeP->middle = n1;
			newnodeP->rightPtr = n2;
			temp.clear();
		} // else if
	} // else if
	else if ( newnodeP->count == 2 ) {
		for ( int i = 0 ; i < temp.size() ; i++ ) {
			newnodeP->itemsC.push_back( temp[i] );
		} // for
		newnodeP = Swap( newnodeP );
		newnodeP = Swap2( newnodeP );
		newnodeP->count = 3;
		newnodeP->isLeaf = false;

		if ( strcmp( (char*)root23->itemsA[0].cname.c_str(), (char*)newnodeP->leftPtr->itemsA[0].cname.c_str() ) == 0 ) { // left
			newnodeP->type = 1;
			newnodeP->leftPtr = n1;
			newnodeP->ptr4 = n2;
		} // if
		else if ( strcmp( (char*)root23->itemsA[0].cname.c_str(), (char*)newnodeP->middle->itemsA[0].cname.c_str() ) == 0 ) { // middle
			newnodeP->type = 2;
			newnodeP->ptr4 = n1;
			newnodeP->middle = n2;
		} // else if
		else if ( strcmp( (char*)root23->itemsA[0].cname.c_str(), (char*)newnodeP->rightPtr->itemsA[0].cname.c_str() ) == 0 ) { // right
			newnodeP->type = 3;
			newnodeP->ptr4 = newnodeP->middle;
			newnodeP->middle = n1;
			newnodeP->rightPtr = n2;
		} // else if

		n1->parent = newnodeP;
		n2->parent = newnodeP;
		temp.clear();
	} // else if

	if ( newnodeP->count == 3 ) {
		newnodeP = split( newnodeP );
	} // if
	
	return newnodeP;
} // split()

twothreetree Tree23 :: insertnode2( twothreetree root23, collegeItemB nodeitem  ) {
	twothreetree current;
	twothreetree temp;
	twothreetree newnode;
	bool equal = false;

	newnode = new nodeTypeA;
	newnode->nodeitem = nodeitem;
	newnode->leftPtr = NULL;
	newnode->middle = NULL;
	newnode->rightPtr = NULL;
	newnode->ptr4 = NULL;
	newnode->parent = NULL;

	if ( root23 == NULL ) {
		root23 = newnode;
		root23->itemsA.push_back( newnode->nodeitem );
		root23->isLeaf = true;
		root23->count = 1;
	} // if
	else {
		current = root23;
		while ( current != NULL && equal == false ) {
			if ( strcmp( (char*)current->itemsA[0].cname.c_str(), (char*)newnode->nodeitem.cname.c_str() ) == 0 ) {
				current->itemsA.push_back( newnode->nodeitem );
				equal = true;
			} // if
			else if ( current->count == 1 ) {
				if ( current->leftPtr != NULL || current->rightPtr != NULL ) {
					if ( strcmp( (char*)current->itemsA[0].cname.c_str(), (char*)newnode->nodeitem.cname.c_str() ) > 0 ) {
						current = current->leftPtr;
					} // if
					else if ( strcmp( (char*)current->itemsA[0].cname.c_str(), (char*)newnode->nodeitem.cname.c_str() ) < 0 ) {
						current = current->rightPtr;
					} // else if
				} // if
				else {
					current->count = 2;
					current->itemsB.push_back( newnode->nodeitem );
					current = Swap( current );
					current->isLeaf = true;
					equal = true;
				} // else
			} // else if
			else if ( strcmp( (char*)current->itemsB[0].cname.c_str(), (char*)newnode->nodeitem.cname.c_str() ) == 0 ) {
				current->itemsB.push_back( newnode->nodeitem );
				equal = true;
			} // else if
			else if ( current->count == 2 ) {
				if ( current->leftPtr != NULL || current->middle != NULL || current->rightPtr != NULL ) {
					if ( strcmp( (char*)current->itemsA[0].cname.c_str(), (char*)newnode->nodeitem.cname.c_str() ) > 0 ) {
						current = current->leftPtr;
					} // else if
					else if ( strcmp( (char*)current->itemsA[0].cname.c_str(), (char*)newnode->nodeitem.cname.c_str() ) < 0 &&
							strcmp( (char*)current->itemsB[0].cname.c_str(), (char*)newnode->nodeitem.cname.c_str() ) > 0 ) {
						current = current->middle;
					} // else if
					else if ( strcmp( (char*)current->itemsB[0].cname.c_str(), (char*)newnode->nodeitem.cname.c_str() ) < 0 ) {
						current = current->rightPtr;
					} // else if
				} // if
				else {
					current->count = 3;
					current = Swap( current );
					current->itemsC.push_back( newnode->nodeitem );
					current = Swap2( current );
					current->isLeaf = true;
					equal = true;
				} // else
			} // else if
			else  { 
				equal = true;
			} // else if
		} // while

		if ( current->count == 3 ) {
			current = split( current );
		} // if
		while ( current->parent != NULL ) {
			current = current->parent;
		} // while
		return current;
	} // else
} // insertnode2()

void AVLTree :: print( tree root ) {

	cout << "< AVLTree height > : ";
	int height = treeheight( root );
	cout << height << endl;

	cout << endl;

	for ( int i = 0 ; i < root->items.size() ; i++ ) {
		int total = root->items[i].total;
		int temp = i+1;
		cout << temp << "." << setw(8) << "[" << total <<  "]" << setw(15) << list[total-1].cname << setw(15) << list[total-1].dname
		<< setw(15) << list[total-1].category << setw(15) << list[total-1].level << setw(15) << list[total-1].sNO << endl;
	} // for

	cout << endl;
} // print()

void Tree23 :: print2( twothreetree root23 ) {

	cout << "< 2-3Tree height > : ";
	int height = treeheight2( root23 );
	cout << height << endl;

	cout << endl;
	int compare = root23->itemsA[0].total;
	int compare2 = 0;
	if ( root23->itemsB.size() != 0 ) {
		compare2 = root23->itemsB[0].total;
	} // if
	
	int temp, temp2;
	if ( compare > compare2 ) {
		for ( int j = 0 ; j < root23->itemsB.size() ; j++ ) {
			int total2 = root23->itemsB[j].total;
			temp2 = j+1;
			cout << temp2 << "." << setw(8) << "[" << total2 <<  "]" << setw(15) << list[total2-1].cname << setw(15) << list[total2-1].dname
			<< setw(15) << list[total2-1].category << setw(15) << list[total2-1].level << setw(15) << list[total2-1].sNO << endl;
		} // for
		temp = temp2;
		for ( int i = 0 ; i < root23->itemsA.size() ; i++ ) {
			int total = root23->itemsA[i].total;
			temp++;
			cout << temp << "." << setw(8) << "[" << total <<  "]" << setw(15) << list[total-1].cname << setw(15) << list[total-1].dname
			<< setw(15) << list[total-1].category << setw(15) << list[total-1].level << setw(15) << list[total-1].sNO << endl;
		} // for
	} // if
	else if ( compare2 > compare ) {
		for ( int i = 0 ; i < root23->itemsA.size() ; i++ ) {
			int total = root23->itemsA[i].total;
			temp = i+1;
			cout << temp << "." << setw(8) << "[" << total <<  "]" << setw(15) << list[total-1].cname << setw(15) << list[total-1].dname
			<< setw(15) << list[total-1].category << setw(15) << list[total-1].level << setw(15) << list[total-1].sNO << endl;
		} // for
		temp2 = temp;
		for ( int j = 0 ; j < root23->itemsB.size() ; j++ ) {
			int total2 = root23->itemsB[j].total;
			temp2++;
			cout << temp2 << "." << setw(8) << "[" << total2 <<  "]" << setw(15) << list[total2-1].cname << setw(15) << list[total2-1].dname
			<< setw(15) << list[total2-1].category << setw(15) << list[total2-1].level << setw(15) << list[total2-1].sNO << endl;
		} // for
	} // else if
	else {
		for ( int i = 0 ; i < root23->itemsA.size() ; i++ ) {
			int total = root23->itemsA[i].total;
			temp = i+1;
			cout << temp << "." << setw(8) << "[" << total <<  "]" << setw(15) << list[total-1].cname << setw(15) << list[total-1].dname
			<< setw(15) << list[total-1].category << setw(15) << list[total-1].level << setw(15) << list[total-1].sNO << endl;
		} // for
	} // else 
	cout << endl;
} // print2()

twothreetree Tree23 :: create23tree( char* file ) {
	twothreetree root23 = NULL;
	collegeType content;
	int total = 1;
	string line;
	ifstream infile ; // 讀檔案
	infile.open( file ) ;

	getline( infile , line ) ;
	getline( infile , line ) ;
	getline( infile , line ) ;

	while ( getline( infile , line ) ) {
		content.rawR = line ;
		CList.savefile( content ) ;
		content.total = total;
		total++;
		list.push_back( content ) ;  // put the new item at the end of the heap
		templist.push_back( content );
	} // while()

	infile.close();

	int now = 0;
	int num = 1;
	collegeType newitem;
	collegeItemB nodeitemB;

	for ( int i = 0 ; i < list.size() ; i++ ) {   // store a new list for avl tree node
		newitem = list[i];
		nodeitemB.cname = newitem.cname;
		nodeitemB.total = newitem.total;
		list3.push_back( nodeitemB );
	} // for

	while ( now < list3.size() ) {
		nodeitemB = list3[now];
		root23 = insertnode2( root23, nodeitemB );
		now++;
	} // while

	print2( root23 );
    list.clear();
    list3.clear();

	return root23;
} // create23tree()

void Tree23 :: search1( string &name, twothreetree root23 ) {
	string all = "*";
	bool same = false;
	bool same2 = false;
	while ( ( root23->leftPtr != NULL || root23->middle != NULL || root23->rightPtr != NULL ) && same == false && same2 == false ) {
		if ( root23->count == 1 ) {
			if ( strcmp( (char*)root23->itemsA[0].cname.c_str(), (char*)name.c_str() ) > 0 ) {
				root23 = root23->leftPtr;
			} // if
			else if ( strcmp( (char*)root23->itemsA[0].cname.c_str(), (char*)name.c_str() ) == 0 ) { 
				same = true;
			} // else if
			else if ( strcmp( (char*)root23->itemsA[0].cname.c_str(), (char*)name.c_str() ) < 0 ) {
				root23 = root23->rightPtr;
			} // else if
		} // if
		else if ( root23->count == 2 ) {
			if ( strcmp( (char*)root23->itemsA[0].cname.c_str(), (char*)name.c_str() ) > 0 ) {
				root23 = root23->leftPtr;
			} // if
			else if ( strcmp( (char*)root23->itemsA[0].cname.c_str(), (char*)name.c_str() ) == 0 ) { 
				same = true;
			} // else if
			else if ( strcmp( (char*)root23->itemsA[0].cname.c_str(), (char*)name.c_str() ) < 0 &&
					strcmp( (char*)root23->itemsB[0].cname.c_str(), (char*)name.c_str() ) > 0 ) {
				root23 = root23->middle;
			} // else if
			else if ( strcmp( (char*)root23->itemsB[0].cname.c_str(), (char*)name.c_str() ) == 0 ) {
				same2 = true;
			} // else if
			else if ( strcmp( (char*)root23->itemsB[0].cname.c_str(), (char*)name.c_str() ) < 0 ) {
				root23 = root23->rightPtr;
			} // else if
		} // else if
	} // while
	
	if ( strcmp( (char*)name.c_str(), (char*)all.c_str() ) == 0 ) {  // *
		name = "*";
	} // if
	
	if ( same == true ) {   // same A
		name = root23->itemsA[0].cname;
	} // if
	else if ( same2 == true ) {  // same B
		name = root23->itemsB[0].cname;
	} // else if
	
	same = false;
	same2 = false;
} // search()

void AVLTree :: search2( string &name, tree root ) {
	string all = "*";
	bool same = false;
	bool bottom = false;
	while ( ( root->leftPtr != NULL || root->rightPtr != NULL ) && same == false && bottom == false ) {
		if ( strcmp( (char*)root->items[0].dname.c_str(), (char*)name.c_str() ) > 0 ) {
			root = root->leftPtr;
		} // if
		else if ( strcmp( (char*)root->items[0].dname.c_str(), (char*)name.c_str() ) < 0 ) {
			root = root->rightPtr;
		} // else if
		else if ( strcmp( (char*)root->items[0].dname.c_str(), (char*)name.c_str() ) == 0 ) {
			same = true;
		} // else if
		else  {
			bottom = true;
		} // else 
	} // while
	
	if ( strcmp( (char*)name.c_str(), (char*)all.c_str() ) == 0 ) {  // *
		name = "*";
	} // if
	
	same = false;
	
} // search()

tree AVLTree :: createAVLtree( char* file ) {
	tree root = NULL;
	collegeType content;
	int total = 1;
	string line;
	ifstream infile ; // 讀檔案
	infile.open( file ) ;

	getline( infile , line ) ;
	getline( infile , line ) ;
	getline( infile , line ) ;

	while ( getline( infile , line ) ) {
		content.rawR = line ;
		CList.savefile( content ) ;
		content.total = total;
		total++;
		list.push_back( content ) ;  // put the new item at the end of the heap
	} // while()

	infile.close();

	int now = 0;
	int num = 1;
	collegeType newitem;
	collegeItem nodeitem;

	for ( int i = 0 ; i < list.size() ; i++ ) {   // store a new list for avl tree node
		newitem = list[i];
		nodeitem.dname = newitem.dname;
		nodeitem.total = newitem.total;
		list2.push_back( nodeitem );
	} // for

	while ( now < list2.size() ) {
		nodeitem = list2[now];
		insertnode( root, nodeitem );
		now++;
	} // while

	print( root );

    list.clear();
    list2.clear();

	return root;
} // createAVLtree()

int main() {
	Mission3 mission;
	AVLTree atree ;
	Tree23 tree23;
	twothreetree root23 = NULL;
	tree root = NULL;
	string schoolname;
	string departmentname;
	vector<collegeItemB> temp;
	vector<collegeItem> temp2;
	
	char* filename ;
	char* filename2;
	string middlename;
	string name;
	string name2;
	bool mission1 = false;
	bool mission2 = false;
	int num = 0; // 題號
	cout << "*****	Search Tree Utilities	*****" << endl;
	cout << "*****	離開	*****: 0" << endl;
	cout << "*****	任務一	*****: 1" << endl;
	cout << "*****	任務二	*****: 2" << endl;
	cout << "請選擇離開或任務一或任務二(請輸入0或1或2) -> ";
	while ( scanf( "%d", &num ) != 1 ){
	   	while( getchar() != '\n' ) ; // 讀掉緩衝區的字元
	   		cout << "輸入格式錯誤!!!請重新輸入" << endl;
			cout << "請選擇離開或任務一或任務二(請輸入0或1或2或3) -> ";
    } // while

    while ( num != 0 ) {
       	if ( num == 1 ) {  // mission one
     	  	cout << "請輸入要讀取的檔案名稱( ex.201,202...... ): " ;
       			cin >> middlename;
       			string input ;
       			input = "input" + middlename + ".txt" ;
       			char* name1 = (char*)input.c_str();

       			ifstream infile ; // 讀檔案
				infile.open( name1 ) ;
				while ( !infile ) { // 無此檔案
					if ( strcmp ( middlename.c_str(), "0") == 0  )
						break  ;
					else {
						cout << "查無此檔案!!!!請重新輸入!!!!"<< endl ;
						cout << "請輸入要讀取的檔案名稱( ex.201,202...... (0 為離開) ): ";
						cin >> middlename;
						input = "input" + middlename + ".txt" ;
						name1 = (char*)input.c_str();
						infile.open( name1 ) ;
					} // else
   				} // while
			root23 = tree23.create23tree( name1 );
			mission1 = true;
		} // if
		else if ( num == 2) {  // mission two
			if ( mission1 == true ) {
				string input;
       			input = "input" + middlename + ".txt" ;
       			char* name1 = (char*)input.c_str();

       			ifstream infile ; // 讀檔案
				infile.open( name1 ) ;
				while ( !infile ) { // 無此檔案
					if ( strcmp ( middlename.c_str(), "0") == 0  )
						break  ;
					else {
						cout << "查無此檔案!!!!請重新輸入!!!!"<< endl ;
						cout << "請輸入要讀取的檔案名稱( ex.201,202...... (0 為離開) ): ";
						cin >> middlename;
						input = "input" + middlename + ".txt" ;
						name1 = (char*)input.c_str();
						infile.open( name1 ) ;
					} // else
   				} // while
			root = atree.createAVLtree( name1 );
			mission1 = false;
			mission2 = true;
		} // if
		else {
			if ( mission1 == false ) {
				cout << "請先執行任務一" << endl;
			} // if
		}
		} // else if
		else if ( num == 3 ) {
			if ( mission2 == true ) {
				cout << "請輸入要搜尋的學校名稱 : ";
				cin >> schoolname;
				cout << "請輸入要搜尋的系名稱 : " ;
				cin >> departmentname;
				tree23.search1( schoolname, root23 );
				atree.search2( departmentname, root );
				mission.print( schoolname, departmentname );
			} // if
			else {
				if ( mission2 == false ) {
					cout << "請先執行任務二" << endl;
				} // if
			} // else 
			
			mission1 = false;
			mission2 = false;
		} // else if
		else {
			cout << "輸入格式錯誤!!!請重新輸入" << endl;
		} // else
	
	cout << "請選擇離開或任務一或任務二(請輸入0或1或2) -> ";
	while ( scanf( "%d", &num ) != 1 ){
	   	while( getchar() != '\n' ) ; // 讀掉緩衝區的字元
	   		cout << "輸入格式錯誤!!!請重新輸入" << endl;
			cout << "請選擇離開或任務一或任務二(請輸入0或1或2) -> " ;
    } // while

	}
}


