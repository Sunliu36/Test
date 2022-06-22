#include <bits/stdc++.h>

using namespace std ;

typedef struct node {
  int x ;
  int y ;
} node ;

bool check( int **a, int ii, int jj ) {
  if ( a[ii][jj] == 0 ) return true ;
  else return false ;

}

int main() {

  int x ;
  cin >> x ;
  int n ;
  for ( ; x>0 ; x-- ) {

    cin >> n ;
    node p[n] ;
    for ( int i= 0 ;i<n;i++){
        cin >> p[i].x >> p[i].y ;
    }
    int **choose ;
    choose = new int*[n] ;
    for (int i = 0 ; i < n ; i++) choose[i] = new int [n] ;

    int cost[n][n] ;
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j<n;j++ ) {
            if (i==j) {
                    cost[i][j] = 0 ;
                    choose[i][j] = 3 ;
            }
            else {
                cost[i][j] = abs(p[i].x-p[j].x) + abs(p[i].y-p[j].y) ;
                choose[i][j] = 0 ;
            }
            //cout << cost[i][j] ;
            //cout << " " ;
        }
        //cout << endl ;
    }
    int sum = 0 ;
    int mini = 999999 ;
    int mi,mj = 0 ;
    for (int i = 0 ; i < n ; i++ ) {
        mini = 999999 ;
        for ( int j = 0 ; j < n ; j++ ) {
            //cout << check(choose,i,j) << endl ;
            //cout << i << " " << j << endl ;

            if ( cost[i][j] != 0 && mini>cost[i][j] && check(choose,i,j)) {
                mini = cost[i][j] ;
                mi = i ;
                mj = j ;
            }
        }
        //cout << mini << endl ;
        sum+=mini ;
        choose[mi][mj] = 1 ;
        choose[mj][mi] = 1 ;
    }

    cout << sum -cost[mi][mj] ;
    if ( x!= 1 ) cout << endl ;



  }
}

/*
  int t = n-1;
  int ttcost = 0;

  for ( ; x >0 x-- ) {
    vector <E> v;
    sort(v.begin(), v.end(), cmp);


    for (E edge:v){
      int g1 = find(edge.x);
      int g2 = find(edge.y);
      if (g1 == g2) continue;
      else {
        p[g2] = g1;
        t -= 1;
        ttcost += edge.cost;
      }
    }
    cout << ttcost ;
*/

#include <bits/stdc++.h>

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

  int x ;
  cin >> x ;
  int n ;
  for ( ; x>0 ; x-- ) {

    cin >> n ;
    node p[n] ;
    for ( int i= 0 ;i<n;i++){
        cin >> p[i].x >> p[i].y ;
    }

    int cost[n][n] ;
    for ( int i = 0 ; i < n ; i++ ) {
        for ( int j = 0 ; j<n;j++ ) {
            if (i==j) {
                    cost[i][j] = 0 ;
            }
            else {
                cost[i][j] = abs(p[i].x-p[j].x) + abs(p[i].y-p[j].y) ;

            }
            //cout << cost[i][j] ;
            //cout << " " ;
        }
        //cout << endl ;
    }
    int sum = 0 ;
    int mini = 999999 ;
    int mu,mj = 0 ;
    int u = 0 ;
    vector<int> path ;
    path.push_back(0) ;
    while ( path.size() < n ) {
        mini = 999999 ;
        for ( int k = 0 ; k < path.size() ; k++ ) {
            u = path[k] ;
            for ( int j = 0 ; j < n ; j++ ) {
                if ( !vfind(path,j ) && cost[u][j] != 0 && mini>cost[u][j] ) {
                    mini = cost[u][j] ;
                    mu = u ;
                    mj = j ;
                }
            }
        }
        cout << mini << endl ;
        sum+=mini ;
        path.push_back(mj) ;
    }

    cout << sum ;
    if ( x!= 1 ) cout << endl ;

  }
}
