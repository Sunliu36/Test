#pragma optimize("", on)
#include <iostream>
#include <vector>

using namespace std ;

typedef struct node {
   int x ;
   int y ;
} node ;


bool vfind( vector<int> path, int index ) {
  for ( int i = 0 ; i < path.size() ; i ++ ) {
    if ( path[i] == index ) return true ;
  }
  return false ;
}

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  unsigned int x, n ;
  cin >> x ;

  for ( ; x>0 ; x-- ) {

    cin >> n ;
    node p[n] ;
    for ( int i= 0 ;i<n;i++){
        cin >> p[i].x >> p[i].y ;
    }

    unsigned int cost[n][n] ;
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j<n;j++ ) {
            if (i==j) {
                    cost[i][j] = 0 ;
            }
            else {
                cost[i][j] = abs(p[i].x-p[j].x) + abs(p[i].y-p[j].y) ;
                //cost[j][i] = abs(p[i].x-p[j].x) + abs(p[i].y-p[j].y) ;
            }
        }
    }
    unsigned int sum = 0, mini ;
    unsigned int mu,mj,u ;
    vector<int> path ;
    path.push_back(0) ;
    while ( path.size() < n ) {
        mini = 999999 ;
        for ( int k = 0 ; k < path.size() ; k++ ) {
            u = path[k] ;
            unsigned int j = 0 ;
            while ( j<n ) {
                if ( !vfind(path,j ) && cost[u][j] != 0 && mini>cost[u][j] ) {
                    mini = cost[u][j] ;
                    mu = u ;
                    mj = j ;
                }

                j++ ;
            }
        }
        cout << mini << endl ;
        sum+=mini ;
        ...........0v£¥£°
        path.push_back(mj) ;
    }

    cout << sum ;
    if ( x!= 1 ) cout << endl ;

  }
}
#pragma optimize("", off)

