#include <bits/stdc++.h>

using namespace std ;

typedef struct pathset{
  int r[9] ;
  int cou = 1 ;
} pathset ;

typedef struct g {

    int p[3][3] ;

} g ;



void read( g t ) {
  for ( int i = 0 ; i<3 ; i++ ) {
    for ( int j = 0 ; j < 3 ; j++ ) {
        cin >> t.p[i][j] ;
    }
  }

}
int findi( g t ) {
  for ( int i = 0 ; i<3 ; i++ ) {
    for ( int j = 0 ; j < 3 ; j++ ) {
        if ( t.p[i][j] == 0 ) return i ;
    }
  }

}

int print( g t) {
  for ( int i = 0 ; i<3 ; i++ ) {
    for ( int j = 0 ; j < 3 ; j++ ) {
        cout << t.p[i][j] ;
        if ( j != 2 ) cout << " " ;
    }
    if ( i != 2 ) cout << endl ;
  }
}

int findj( g t ) {
  for ( int i = 0 ; i<3 ; i++ ) {
    for ( int j = 0 ; j < 3 ; j++ ) {
        if ( t.p[i][j] == 0 ) return j ;
    }
  }

}
bool match( g a, g b ) {
  bool che = true ;
  for ( int i = 0 ; i<3 ; i++ ) {
    for ( int j = 0 ; j < 3 ; j++ ) {
      if ( a.p[i][j] != b.p[i][j] ) {
        che = false ;
        break ;
      }
    }
  }
  return che ;
}

void bfs(pathset path[3][3], g t, g target, int zi, int zj) {
  int tmp ;
  bool deal = false ;
  while( !match(t,target)) {
    if ( zi-1 >=0 && zi-1 <= 2 && pass(path[zi-1][zj],t.p[zi][zj])) {
        tmp = t.p[zi-1][zj] ;
        t.p[zi-1][zj] = t.p[zi][zj] ;
        t.p[zi][zj] = tmp ;
        path[zi][zj].r[path[zi][zj].cou] = t.p[zi][zj] ;
        path[zi][zj].cou++ ;
        path[zi-1][zj].r[path[zi-1][zj].cou] = t.p[zi-1][zj] ;
        path[zi-1][zj].cou++ ;
        zi = zi-1 ;
    }
    else if (zj+1 >=0 && zj+1 <= 2 && pass(path[zi][zj+1],t.p[zi][zj])) {
        tmp = t.p[zi][zj+1] ;
        t.p[zi][zj+1] = t.p[zi][zj] ;
        t.p[zi][zj] = tmp ;
        path[zi][zj].r[path[zi][zj].cou] = t.p[zi][zj] ;
        path[zi][zj].cou++ ;
        path.p[zi][zj+1].r[path.p[zi][zj+1].cou] = t.p[zi][zj+1] ;
        path.p[zi][zj+1].cou++ ;
        zj = zj+1 ;
    }
    else if (zi+1 >=0 && zi+1 <= 2 && pass(path[zi+1][zj],t.p[zi][zj])) {
        tmp = t.p[zi+1][zj] ;
        t.p[zi+1][zj] = t.p[zi][zj] ;
        t.p[zi][zj] = tmp ;
        path[zi][zj].r[path[zi][zj].cou] = t.p[zi][zj] ;
        path[zi][zj].cou++ ;
        path[zi+1][zj].r[path[zi+1][zj].cou] = t.p[zi+1][zj] ;
        path[zi+1][zj].cou++ ;
        zi = zi+1 ;
    }
    else if (zj-1 >=0 && zj-1 <= 2 && pass(path[zi][zj-1],t.p[zi][zj])) {
        tmp = t.p[zi][zj-1] ;
        t.p[zi][zj-1] = t.p[zi][zj] ;
        t.p[zi][zj] = tmp ;
        path[zi][zj].r[path[zi][zj].cou] = t.p[zi][zj] ;
        path[zi][zj].cou++ ;
        path.p[zi][zj-1].r[path.p[zi][zj-1].cou] = t.p[zi][zj-1] ;
        path.p[zi][zj-1].cou++ ;
        zj = zj-1 ;
  }


}


bool pass( pathset p, int n ) {
  for(int i = 0 ; i < 9 ; i++ ) {
    if (p.r[i] == n) return false ;
  }
  return true ;
}

int main() {
  pathset path[3][3] ;
  for ( int i = 0 ; i<3 ; i++ ) {
    for ( int j = 0 ; j < 3 ; j++ ) {
        memset( path[i][j].r,100,9) ;
    }
  }

  memset(path,100,9) ;
  queue<g> q ;
  g t ;
  g target ;
  int zi, zj ;
  for ( int i = 0 ; i<3 ; i++ ) {
    for ( int j = 0 ; j < 3 ; j++ ) {
        cin >> t.p[i][j] ;
    }
  }
  for ( int i = 0 ; i<3 ; i++ ) {
    for ( int j = 0 ; j < 3 ; j++ ) {
        cin >> target.p[i][j] ;
    }
  }
  for ( int i = 0 ; i<3 ; i++ ) {
    for ( int j = 0 ; j < 3 ; j++ ) {
        memset( path[i][j].r,100,9) ;
        path[i][j].r[0] = t.p[i][j] ;
    }
  }
  zi = findi(t) ;
  zj = findj(t) ;
  //cout << zi << " " << zj << endl ;
  //print(target) ;


}
