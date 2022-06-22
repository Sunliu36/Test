
#include <bits/stdc++.h>

using namespace std ;


map<char,int> lmap ;

int in(char ch ) {
  if (lmap.find(ch) == lmap.end() ) {
    int c = lmap.size() ;
    lmap[ch] = c ;

  }
  //cout << lmap[ch] << endl ;
  return lmap[ch] ;
}

int main() {

  int n, m ;
  cin >> n >> m ;

  int dp[n][n] ;
  if ( n == 0 ) cout << "INF" ;
  for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
          if (i == j) dp[i][j] = 0;
          else dp[i][j] = 999999;
      }
  }

  char base, ch1, ch2 ;
  int f, b, v ;
  base = 'a' ;
  /*
  char mm[5] ;
  for ( int i = 0 ; i < 5 i ++ ) mm[i] = ' ' ;
  while ( cin >> ch1 >> ch2 >> v ) {
    for ( int i = 0 ; i < 5 i ++ ) {
        if( mm[i] == ch1 )
    }
  }
  */
  /*
  cin >> ch1 >> ch2 >> v ;
  if ( ch1 < ch2 ) base = ch1 ;
  else base = ch2 ;
  f = ch1 - base ;
  b = ch2 - base ;
  dp[f][b] = v ;
  */
  for ( int i = 0 ; i < m ; i++ ) {
    cin >> ch1 >> ch2 >> v ;
    f = in(ch1) ;
    b = in(ch2) ;
    dp[f][b] = v ;
  }
  /*
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
        for (int k = 0; k < n; k++){
            if (dp[j][k] > dp[j][i] + dp[i][k]){
                dp[j][k] = dp[j][i] + dp[i][k];
            }
        }
    }
  }
  */
  for(int i=0 ; i<n ;i++){
    for(int j=0 ; j<n ;j++){
      for(int k=0 ; k<n ;k++){
        if (dp[j][i]==999999||dp[i][k]==999999) continue ;
        dp[j][k] = min(dp[j][k],dp[j][i]+dp[i][k]) ;
      }
    }
  }

  for ( int i = 0 ; i < n ; i ++ ) {
    for ( int j = 0 ; j < n ; j ++ ) {
        if ( dp[i][j] == 999999 ) cout << "INF" ;
        else cout << dp[i][j] ;

        if ( j != n-1 ) cout << " " ;
    }
    if ( i != n-1 ) cout << endl ;

  }

  return 0 ;
}
