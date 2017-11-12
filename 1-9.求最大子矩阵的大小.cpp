#include <iostream>
#include <stack>
#include <string>

#define MAX 100

using namespace std;

int maxRecFromBottom( int height[], int n ) {
	int maxArea = 0;
	stack<int> s;
	
	for( int i = 0; i < n; i++ ) {
		while( !s.empty() && height[i] <= height[s.top()] ) {
			int j = s.top();
			s.pop();
			int k = s.empty() ? -1 : s.top();
			int curArea = ( i - k - 1 ) * height[j];
			maxArea = max( maxArea, curArea );
		}
		s.push( i );
	}
	
	while( !s.empty() ) {
		int j = s.top();
		s.pop();
		int k = s.empty() ? -1 : s.top();
		int curArea = ( n - k - 1 ) * height[j];
		maxArea = max( maxArea, curArea );
	}
	
	return maxArea;
}

int maxRecSize( int map[MAX][MAX], int n, int m ) {
	int height[MAX];
	int maxArea = 0;
	
	fill( height, height + m, 0 );
	
	for( int i = 0; i < n; i++ ) {
		for( int j = 0; j < m; j++ ) {
			height[j] = map[i][j] == 0 ? 0 : height[j] + 1;	
		}
		maxArea = max( maxRecFromBottom( height, m ), maxArea );		
	}
	
	return maxArea;
}

int main() {
	int map[MAX][MAX] = { { 1, 0, 1, 1 }, { 1, 1, 1, 1 }, { 1, 1, 1, 0 } };
	
	int maxArea = maxRecSize( map, 3, 4 );
	
	printf( "%d\n", maxArea);
	
	return 0;
}
