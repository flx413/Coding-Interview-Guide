#include <iostream>
#include <stack>
#include <vector>
#include <map>

using namespace std;

// 二叉树节点定义 
typedef struct node {
	struct node* left;
	struct node* right;
	int val;
	node( int data ) {
		val = data;
		left = NULL;
		right = NULL;
	}
} Node;

// 将弹栈元素存入map，记录映射关系 
// 当栈为空时存入NULL 
void popStackSetMap( stack<Node*> &s, map<Node*, Node*> &mp ) {
	Node* curNode = s.top();
	s.pop();
	if( s.empty() ) {
		mp.insert( map<Node*, Node*>::value_type( curNode, NULL ) );
	}
	else {
		mp.insert( map<Node*, Node*>::value_type( curNode, s.top() ) );
	}
}

// 建立 getMaxTree 
Node* getMaxTree( vector<int> &vec ) {
	vector<Node*> v;
	for( int i = 0; i < vec.size(); i++ ) {
		v.push_back( new Node( vec[i] ) );
	}
	
	stack<Node*> s;
	map<Node*, Node*> mpLeft;
	map<Node*, Node*> mpRight;
	
	// 找左边第一个比当前元素大的值 
	for( int i = 0; i < v.size(); i++ ) {
		Node* curNode = v[i];
		while( !s.empty() && s.top()->val < curNode->val ) {
			popStackSetMap( s, mpLeft );
		}
		s.push( curNode );
	}
	
	while( !s.empty() ) {
		popStackSetMap( s, mpLeft );
	}
	
	// 找右边第一个比当前元素大的值 
	for( int i = vec.size() - 1; i >= 0; i-- ) {
		Node* curNode = v[i];
		while( !s.empty() && s.top()->val < curNode->val ) {
			popStackSetMap( s, mpRight );
		}
		s.push( curNode );
	}
	
	while( !s.empty() ) {
		popStackSetMap( s, mpRight );
	}
	
	// 建树，返回根节点 
	Node* head = NULL;
	
	for( int i = 0; i < v.size(); i++ ) {
		Node* curNode = v[i];
		Node* curNodeLeft = mpLeft[curNode];
		Node* curNodeRight = mpRight[curNode];
		
		printf( "%d ", curNode->val );
		if( curNodeLeft == NULL ) {
			printf( "null " );
		}
		else {
			printf( "%d ", curNodeLeft->val );
		}
		
		if( curNodeRight == NULL ) {
			printf( "null\n" );
		}
		else {
			printf( "%d\n", curNodeRight->val );
		}
		
		if( curNodeLeft == NULL && curNodeRight == NULL ) {
			head = curNode;	
		}
		else if( curNodeLeft == NULL ) {
			if( curNodeRight->left == NULL ) curNodeRight->left = curNode;
			else if( curNodeRight->right == NULL ) curNodeRight->right = curNode;
		}
		else if( curNodeRight == NULL ) {
			if( curNodeLeft->left == NULL ) curNodeLeft->left = curNode;
			else if( curNodeLeft->right == NULL ) curNodeLeft->right = curNode;
		}
		else {
			Node* curMaxNode = curNodeLeft->val < curNodeRight->val ? curNodeLeft : curNodeRight;
			if( curMaxNode->left == NULL ) curMaxNode->left = curNode;
			else if( curMaxNode->right == NULL ) curMaxNode->right = curNode;
		}
	}
	
	return head;
}

void printPre( Node* root ) {
	if( root == NULL ) {
		return;
	}
	printf( "%d\n", root->val );
	printPre( root->left );
	printPre( root->right );
}

int main() {
	vector<int> vec;
	vec.push_back( 3 );
	vec.push_back( 5 );
	vec.push_back( 4 );
	vec.push_back( 1 );
	vec.push_back( 2 );
	
	Node* root = getMaxTree( vec );
	
	printPre( root );
	
	return 0;
}
