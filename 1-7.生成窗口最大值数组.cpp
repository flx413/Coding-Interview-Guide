#include <iostream>
#include <deque>
#include <vector>

using namespace std;

vector<int> getMaxWindow( vector<int> &v, int w ) {
	vector<int> ans;
	
	if( v.empty() || w < 1 || v.size() < w ) {
		return ans;
	}
	
	deque<int> q;
	for( int i = 0; i < v.size(); i++ ) {
		while( !q.empty() && v[q.back()] <= v[i] ) {
			q.pop_back();
		}  
		q.push_back( i );
		if( q.front() == i - w ) {
			q.pop_front();
		}
		if( i >= w - 1 ) {
			ans.push_back( v[q.front()] );
		}
	}
	
	return ans;
}

int main() {
	vector<int> vec;
	vec.push_back( 4 );
	vec.push_back( 3 );
	vec.push_back( 5 );
	vec.push_back( 4 );
	vec.push_back( 3 );
	vec.push_back( 3 );
	vec.push_back( 6 );
	vec.push_back( 7 );
	
	vector<int> ans = getMaxWindow( vec, 3 );

	for( int i = 0; i < ans.size(); i++ ) {
		printf( "%d ", ans[i] );
	}
	
	return 0;
}
