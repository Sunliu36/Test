
#include <iostream>
#include <algorithm>

using namespace std ;

typedef struct Gun {
  int shoot = -1 ;
  int w = 999999 ;
} Gun ;

typedef struct Node {
  int name ;
  int nf = 0 ;
  Gun gun[3] ;
  int stage = 0 ;
} Node ;

int mini = 999999 ;

int astar(struct Node *node, struct Node now, int target, int distance ) {
  int f = 0 ;
  if ( now.stage == target ) {
     f = distance + std::min({now.gun[0].w,now.gun[1].w,now.gun[2].w });
     mini = min(mini,f) ;
     //cout << "dis:" << distance << endl ;
     //cout << now.name << " " << f <<"reach" << endl ;
     return f ;
  }
  else {
    f = distance + std::min({now.gun[0].w, now.gun[1].w, now.gun[2].w});
    if ( f > mini ) return 999999 ;
    //cout << now.name << " " << f << endl ;
    //min(now.gun[0].w,now.gun[1].w,now.gun[2].w) ;
    //cout << "dise:" << distance << endl ;

    /*
    int a =  astar(node,node[now.gun[0].shoot], target, distance+now.gun[0].w );
    int b = astar(node,node[now.gun[1].shoot], target, distance+now.gun[1].w ) ;

    int c = astar(node,node[now.gun[2].shoot], target, distance+now.gun[2].w ) ;
    int minn = a ;
    if ( minn > b ) minn = b ;
    if ( minn > c ) minn = c ;
    */
    return std::min({astar(node,node[now.gun[0].shoot], target, distance+now.gun[0].w ),
                    astar(node,node[now.gun[1].shoot], target, distance+now.gun[1].w ),
                     astar(node,node[now.gun[2].shoot], target, distance+now.gun[2].w ) }) ;

  }
}


int main() {


    int x ;
    cin >> x ;
    for ( ; x>0 ; x-- ) {
      mini = 999999 ;
      Node node[11] ;
      node[10].name = 10 ;
      node[10].stage = 5 ;
      node[10].gun[0].w = 0 ;
      for ( int i = 0 ; i < 10 ; i++ ) {
        node[i].name = i ;


        if ( i == 0 ) {
            node[i].stage = 1 ;
            for ( int j = 0 ; j < 3 ; j++ ) {
              node[i].gun[j].shoot = j+1 ;
              cin >> node[i].gun[j].w ;
              //cout << "s1" << node[i].gun[j].w << endl ;
            }
        }
        else if ( 1 <= i && i <= 3 ) {
            node[i].stage = 2 ;
            for ( int j = 0 ; j < 3 ; j++ ) {
              node[i].gun[j].shoot = j+4 ;
              cin >> node[i].gun[j].w ;
              //cout << "s2" << node[i].gun[j].w << endl ;
            }
        }
        else if ( 4 <= i && i <= 6 ) {
            node[i].stage = 3 ;
            for ( int j = 0 ; j < 3 ; j++ ) {
              node[i].gun[j].shoot = j+7 ;
              cin >> node[i].gun[j].w ;
              //cout << "s3" << node[i].gun[j].w << endl ;
            }
        }
        else if ( 7 <= i && i < 10 ) {
            node[i].gun[0].shoot = 10 ;
            cin >> node[i].gun[0].w ;
            //cout << "s4" << node[i].gun[0].w << endl ;
        }
      }
      int target ;
      cin >> target ;
   /*
      for ( int i= 0 ;i < 11 ;i++ ) {
        for ( int j = 0 ; j < 3  ; j++ ) {
            cout << node[i].gun[j].w << endl ;
        }
      }
      */
      //if ( target == 4 ) target = 5 ;
      cout << astar(node,node[0],target,0) << endl ;
    }

    return 0 ;


}
