#include "Player.hh"
#include <map>
#include <queue>
#include <limits>

/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME LOLITOIOor
#define INFINIT numeric_limits<int>::max()


struct PLAYER_NAME : public Player {

  /**
   * Factory: returns a new instance of this class.
   * Do not modify this function.
   */
  static Player* factory () {
    return new PLAYER_NAME;
  }


  /**
   * Types and attributes for your player can be defined here.
   */
  multimap <pair<int,pair<int,int>>,pair<int,Dir> > priocomandos; //prio,dist, id, Dir
   map<Pos,int> gemas2;
  vector<bool> comandosg;
  vector<bool> comandosp;
  vector<bool> comandosf;//i (P)   //añadir actualizacion vector?
  map<int,int> tradp;
  map<int,int> tradf; //id i (P)
  int nf,np;
  vector<int> Fu;
  vector<int> Pi;
  set<Pos> movimientos;
  int rival,rival2,rival3;
  /**
   * Play method, invoked once per each round.
   */
    Dir contrary(Dir df) {
    if(df==Bottom) return Top;
    else if(df==BR) return TL;
    else if(df==Right) return Left;
    else if(df==RT) return LB;
    else if(df==Top) return Bottom;
    else if(df==TL) return BR;
    else if(df==Left) return Right;
    else if(df==LB) return RT;
    else if(df==Bottom) return Top;
    else return None;

  }
bool demonio(Pos o){
  if(pos_ok(o)) {
  Cell c0=cell(o);
  int id0=c0.id;
          if(id0!=-1 ) {
          Unit ene= unit(id0);
            if(ene.player==-1) return true;
          }
  }

    for(int b=0;b<=7;++b){ //randomizar orden de checkeo, no hacer asi
          Dir d=Dir(b);
          if(pos_ok(o+d)){
          Cell c=cell(o+d);
          int id=c.id;

          if(id!=-1 ) {
          Unit ene= unit(id);
            if(ene.player==-1){
              return true;
                }
          }
         }
    }
         return false;

  }
  bool enemy(Pos o) {
    if(pos_ok(o)) {
  Cell c0=cell(o);
  int id0=c0.id;
          if(id0!=-1 ) {
          Unit ene= unit(id0);
            if(ene.player!=-1 and ene.player!=me() and ene.type==Furyan) return true;
          }
  }

    for(int b=0;b<=7;++b){ //randomizar orden de checkeo, no hacer asi
          Dir d=Dir(b);
          if(pos_ok(o+d)){
          Cell c=cell(o+d);
          int id=c.id;

          if(id!=-1 ) {
          Unit ene= unit(id);
            if(ene.player!=-1 and ene.player!=me() and ene.type==Furyan){
              return true;
                }
          }
         }
    }
         return false;
  }


  bool gemmy(Pos o) {
    if(pos_ok(o)) {
  Cell c0=cell(o);
            if(c0.gem) return true;
  }

    for(int b=0;b<=7;++b){ //randomizar orden de checkeo, no hacer asi
          Dir d=Dir(b);
          if(pos_ok(o+d)){
          Cell c=cell(o+d);
            if(c.gem){
              return true;
                }
          }
         }
         return false;
  }


  bool ascensory(Pos o) {
    if(pos_ok(o)) {
  Cell c0=cell(o);
            if(c0.type==Elevator) return true;
  }

    for(int b=0;b<=7;++b){ //randomizar orden de checkeo, no hacer asi
          Dir d=Dir(b);
          if(pos_ok(o+d)){
          Cell c=cell(o+d);
            if(c.type==Elevator){
              return true;
                }
          }
         }
         return false;
  }


  bool demonio16(Pos o) {
    if(demonio(o)) return true;
    else {
      Pos o1=(o+TL+TL);
      if(pos_ok(o1)) {
     Cell c=cell(o1);
          int id=c.id;
     if(id!=-1 ) {
          Unit ene= unit(id);
            if(ene.player==-1){
              return true;
                }
          }
      }
        o1=(o+TL+Top);
      if(pos_ok(o1)) {
         Cell c=cell(o1);
          int id=c.id;
     if(id!=-1 ) {
          Unit ene= unit(id);
            if(ene.player==-1){
              return true;
                }}
          }
           o1=(o+Top+Top);
      if(pos_ok(o1)) {
               Cell c=cell(o1);
          int id=c.id;
     if(id!=-1 ) {
          Unit ene= unit(id);
            if(ene.player==-1){
              return true;
                }
          }}
           o1=(o+RT+Top);
      if(pos_ok(o1)) {
               Cell c=cell(o1);
          int id=c.id;
     if(id!=-1 ) {
          Unit ene= unit(id);
            if(ene.player==-1){
              return true;
                }}
          }
           o1=(o+RT+RT);
      if(pos_ok(o1)) {
               Cell c=cell(o1);
          int id=c.id;
     if(id!=-1 ) {
          Unit ene= unit(id);
            if(ene.player==-1){
              return true;
                }}
          }
           o1=(o+TL+Left);
      if(pos_ok(o1)) {
               Cell c=cell(o1);
          int id=c.id;
     if(id!=-1 ) {
          Unit ene= unit(id);
            if(ene.player==-1){
              return true;
                }}
          }
           o1=(o+Left+Left);
      if(pos_ok(o1)) {
               Cell c=cell(o1);
          int id=c.id;
     if(id!=-1 ) {
          Unit ene= unit(id);
            if(ene.player==-1){
              return true;
                }}
          }
      o1=(o+Left+LB);
      if(pos_ok(o1)) {
               Cell c=cell(o1);
          int id=c.id;
     if(id!=-1 ) {
          Unit ene= unit(id);
            if(ene.player==-1){
              return true;
                }}
          }
      o1=(o+LB+LB);
      if(pos_ok(o1)) {
               Cell c=cell(o1);
          int id=c.id;
     if(id!=-1 ) {
          Unit ene= unit(id);
            if(ene.player==-1){
              return true;
                }}
          }
      o1=(o+Bottom+LB);
      if(pos_ok(o1)) {
               Cell c=cell(o1);
          int id=c.id;
     if(id!=-1 ) {
          Unit ene= unit(id);
            if(ene.player==-1){
              return true;
                }}
          }
      o1=(o+Bottom+Bottom);
      if(pos_ok(o1)) {
               Cell c=cell(o1);
          int id=c.id;
     if(id!=-1 ) {
          Unit ene= unit(id);
            if(ene.player==-1){
              return true;
                }}
          }
      o1=(o+Bottom+BR);
      if(pos_ok(o1)) {
               Cell c=cell(o1);
          int id=c.id;
     if(id!=-1 ) {
          Unit ene= unit(id);
            if(ene.player==-1){
              return true;
                }}
          }
      o1=(o+BR+BR);
      if(pos_ok(o1)) {
               Cell c=cell(o1);
          int id=c.id;
     if(id!=-1 ) {
          Unit ene= unit(id);
            if(ene.player==-1){
              return true;
                }}
          }
        o1=(o+BR+Right);
      if(pos_ok(o1)) {
               Cell c=cell(o1);
          int id=c.id;
     if(id!=-1 ) {
          Unit ene= unit(id);
            if(ene.player==-1){
              return true;
                }}
          }
       o1=(o+Right+Right);
      if(pos_ok(o1)) {
               Cell c=cell(o1);
          int id=c.id;
     if(id!=-1 ) {
          Unit ene= unit(id);
            if(ene.player==-1){
              return true;
                }}
          }
      o1=(o+Right+RT);
      if(pos_ok(o1)) {
               Cell c=cell(o1);
          int id=c.id;
     if(id!=-1 ) {
          Unit ene= unit(id);
            if(ene.player==-1){
              return true;
                }}
          }

    return false;
    }
}

 Pos bfsataquecueva(Pos o, int &d, Dir &di){ //algoritmo de busqueda de enemigos de otros equipos en subsuelo evitando pasar por casillas que a su alrededor tienen a un monstruo y evivtando pisar a unidades en el primer paso para llegar al enemigo.
    int n=40;
    d=-1;
    int m=80;
    vector <vector <int> > dist(n,vector<int>(m,INFINIT));
    vector <vector <Dir> > pre(n,vector<Dir>(m));
    vector<bool> casillas(8,false);
    queue<Pos> S;
    S.push(o);
    dist[o.i][o.j] = 0;
    pre[o.i][o.j]=None;
    while(not S.empty()){
        Pos v=S.front();
        S.pop();
        Cell c=cell(v);
        if(c.id!=-1  and unit(c.id).player!=me() and not demonio16(v)) {
          d=dist[v.i][v.j];
          di=pre[v.i][v.j];
          Pos v2=v;
          while(v2!=o) {
            v2=v2+contrary(di);
          if(v2!=o)  di=pre[v2.i][v2.j];
          }
            return v;
        }
        else if(c.type==Cave and not demonio(v)){ //añadir caso de 9 primeros checkear si hay gente
                       Pos v1=v+Bottom;
            if(pos_ok(v1) and dist[v1.i][v1.j]==INFINIT and (casillas[0] or ( ( cell(v1).id==-1 or unit(cell(v1).id).player!=me() ) and not demonio16(v1)))){
                     S.push(v1);
                    dist[v1.i][v1.j]=dist[v.i][v.j]+1;
                      pre[v1.i][v1.j]=Bottom;

                 }
                 casillas[0]=true;
            v1=v+BR;
            if(pos_ok(v1) and dist[v1.i][v1.j]==INFINIT and (casillas[1] or ( ( cell(v1).id==-1 or unit(cell(v1).id).player!=me() ) and not demonio16(v1)))){
                     S.push(v1);
                    dist[v1.i][v1.j]=dist[v.i][v.j]+1;
                   pre[v1.i][v1.j]=BR;
                 }
            casillas[1]=true;
            v1=v+Right;
            if(dist[v1.i][v1.j]==INFINIT and (casillas[2] or  ( ( cell(v1).id==-1 or unit(cell(v1).id).player!=me() ) and not demonio16(v1)))){
                     S.push(v1);
                    dist[v1.i][v1.j]=dist[v.i][v.j]+1;
                    pre[v1.i][v1.j]=Right;
                 }
            casillas[2]=true;
            v1=v+RT;
            if(pos_ok(v1) and dist[v1.i][v1.j]==INFINIT and (casillas[3] or ( ( cell(v1).id==-1 or unit(cell(v1).id).player!=me() ) and not demonio16(v1)))){
                     S.push(v1);
                    dist[v1.i][v1.j]=dist[v.i][v.j]+1;
                    pre[v1.i][v1.j]=RT;
                 }
            casillas[3]=true;
           v1=v+Top;
            if(pos_ok(v1) and dist[v1.i][v1.j]==INFINIT and (casillas[4] or ( ( cell(v1).id==-1 or unit(cell(v1).id).player!=me() ) and not demonio16(v1)))){
                     S.push(v1);
                    dist[v1.i][v1.j]=dist[v.i][v.j]+1;
                    pre[v1.i][v1.j]=Top;
            }
            casillas[4]=true;
            v1=v+TL;
            if(pos_ok(v1) and dist[v1.i][v1.j]==INFINIT and (casillas[5] or ( ( cell(v1).id==-1 or unit(cell(v1).id).player!=me() ) and not demonio16(v1)))){
                     S.push(v1);
                    dist[v1.i][v1.j]=dist[v.i][v.j]+1;
                    pre[v1.i][v1.j]=TL;
            }
            casillas[5]=true;
            v1=v+Left;
            if(dist[v1.i][v1.j]==INFINIT and (casillas[6] or ( ( cell(v1).id==-1 or unit(cell(v1).id).player!=me() ) and not demonio16(v1)))){
                     S.push(v1);
                    dist[v1.i][v1.j]=dist[v.i][v.j]+1;
                     pre[v1.i][v1.j]=Left;
                 }
            casillas[6]=true;
            v1=v+LB;
            if(pos_ok(v1) and dist[v1.i][v1.j]==INFINIT and (casillas[7] or ( ( cell(v1).id==-1 or unit(cell(v1).id).player!=me() ) and not demonio16(v1)))){
                     S.push(v1);
                    dist[v1.i][v1.j]=dist[v.i][v.j]+1;
                     pre[v1.i][v1.j]=LB;
                 }
            casillas[7]=true;

                }


    }
    return o;
    }



 Pos bfsataquecuevarival(Pos o, int &d, Dir &di){ //algoritmo de busqueda de enemigos de otros equipos en subsuelo evitando pasar por casillas que a su alrededor tienen a un monstruo y evivtando pisar a unidades en el primer paso para llegar al enemigo.
   d=-1;
    int n=40;
    int m=80;
    vector <vector <int> > dist(n,vector<int>(m,INFINIT));
    vector <vector <Dir> > pre(n,vector<Dir>(m));
    vector<bool> casillas(8,false);
    queue<Pos> S;
    S.push(o);
    dist[o.i][o.j] = 0;
    pre[o.i][o.j]=None;
    while(not S.empty()){
        Pos v=S.front();
        S.pop();
        Cell c=cell(v);
        if(c.id!=-1  and unit(c.id).player==rival and not demonio16(v)) {
          d=dist[v.i][v.j];
          di=pre[v.i][v.j];
          Pos v2=v;
          while(v2!=o) {
            v2=v2+contrary(di);
          if(v2!=o)  di=pre[v2.i][v2.j];
          }
            return v;
        }
        else if(c.type==Cave and not demonio(v)){ //añadir caso de 9 primeros checkear si hay gente
                       Pos v1=v+Bottom;
            if(pos_ok(v1) and dist[v1.i][v1.j]==INFINIT and (casillas[0] or ( ( cell(v1).id==-1 or unit(cell(v1).id).player!=me() ) and not demonio16(v1)))){
                     S.push(v1);
                    dist[v1.i][v1.j]=dist[v.i][v.j]+1;
                      pre[v1.i][v1.j]=Bottom;

                 }
                 casillas[0]=true;
            v1=v+BR;
            if(pos_ok(v1) and dist[v1.i][v1.j]==INFINIT and (casillas[1] or ( ( cell(v1).id==-1 or unit(cell(v1).id).player!=me() ) and not demonio16(v1)))){
                     S.push(v1);
                    dist[v1.i][v1.j]=dist[v.i][v.j]+1;
                   pre[v1.i][v1.j]=BR;
                 }
            casillas[1]=true;
            v1=v+Right;
            if(dist[v1.i][v1.j]==INFINIT and (casillas[2] or  ( ( cell(v1).id==-1 or unit(cell(v1).id).player!=me() ) and not demonio16(v1)))){
                     S.push(v1);
                    dist[v1.i][v1.j]=dist[v.i][v.j]+1;
                    pre[v1.i][v1.j]=Right;
                 }
            casillas[2]=true;
            v1=v+RT;
            if(pos_ok(v1) and dist[v1.i][v1.j]==INFINIT and (casillas[3] or ( ( cell(v1).id==-1 or unit(cell(v1).id).player!=me() ) and not demonio16(v1)))){
                     S.push(v1);
                    dist[v1.i][v1.j]=dist[v.i][v.j]+1;
                    pre[v1.i][v1.j]=RT;
                 }
            casillas[3]=true;
           v1=v+Top;
            if(pos_ok(v1) and dist[v1.i][v1.j]==INFINIT and (casillas[4] or ( ( cell(v1).id==-1 or unit(cell(v1).id).player!=me() ) and not demonio16(v1)))){
                     S.push(v1);
                    dist[v1.i][v1.j]=dist[v.i][v.j]+1;
                    pre[v1.i][v1.j]=Top;
            }
            casillas[4]=true;
            v1=v+TL;
            if(pos_ok(v1) and dist[v1.i][v1.j]==INFINIT and (casillas[5] or ( ( cell(v1).id==-1 or unit(cell(v1).id).player!=me() ) and not demonio16(v1)))){
                     S.push(v1);
                    dist[v1.i][v1.j]=dist[v.i][v.j]+1;
                    pre[v1.i][v1.j]=TL;
            }
            casillas[5]=true;
            v1=v+Left;
            if(dist[v1.i][v1.j]==INFINIT and (casillas[6] or ( ( cell(v1).id==-1 or unit(cell(v1).id).player!=me() ) and not demonio16(v1)))){
                     S.push(v1);
                    dist[v1.i][v1.j]=dist[v.i][v.j]+1;
                     pre[v1.i][v1.j]=Left;
                 }
            casillas[6]=true;
            v1=v+LB;
            if(pos_ok(v1) and dist[v1.i][v1.j]==INFINIT and (casillas[7] or ( ( cell(v1).id==-1 or unit(cell(v1).id).player!=me() ) and not demonio16(v1)))){
                     S.push(v1);
                    dist[v1.i][v1.j]=dist[v.i][v.j]+1;
                     pre[v1.i][v1.j]=LB;
                 }
            casillas[7]=true;

                }


    }
    return o;
    }


    Pos bfsataquecuevarival2(Pos o, int &d, Dir &di){ //algoritmo de busqueda de enemigos de otros equipos en subsuelo evitando pasar por casillas que a su alrededor tienen a un monstruo y evivtando pisar a unidades en el primer paso para llegar al enemigo.
   d=-1;
    int n=40;
    int m=80;
    vector <vector <int> > dist(n,vector<int>(m,INFINIT));
    vector <vector <Dir> > pre(n,vector<Dir>(m));
    vector<bool> casillas(8,false);
    queue<Pos> S;
    S.push(o);
    dist[o.i][o.j] = 0;
    pre[o.i][o.j]=None;
    while(not S.empty()){
        Pos v=S.front();
        S.pop();
        Cell c=cell(v);
        if(c.id!=-1  and unit(c.id).player==rival2 and not demonio(v)) {
          d=dist[v.i][v.j];
          di=pre[v.i][v.j];
          Pos v2=v;
          while(v2!=o) {
            v2=v2+contrary(di);
          if(v2!=o)  di=pre[v2.i][v2.j];
          }
            return v;
        }
        else if(c.type==Cave and not demonio(v)){ //añadir caso de 9 primeros checkear si hay gente
                       Pos v1=v+Bottom;
            if(pos_ok(v1) and dist[v1.i][v1.j]==INFINIT and (casillas[0] or ( ( cell(v1).id==-1 or unit(cell(v1).id).player!=me() ) and not demonio16(v1)))){
                     S.push(v1);
                    dist[v1.i][v1.j]=dist[v.i][v.j]+1;
                      pre[v1.i][v1.j]=Bottom;

                 }
                 casillas[0]=true;
            v1=v+BR;
            if(pos_ok(v1) and dist[v1.i][v1.j]==INFINIT and (casillas[1] or ( ( cell(v1).id==-1 or unit(cell(v1).id).player!=me() ) and not demonio16(v1)))){
                     S.push(v1);
                    dist[v1.i][v1.j]=dist[v.i][v.j]+1;
                   pre[v1.i][v1.j]=BR;
                 }
            casillas[1]=true;
            v1=v+Right;
            if(dist[v1.i][v1.j]==INFINIT and (casillas[2] or  ( ( cell(v1).id==-1 or unit(cell(v1).id).player!=me() ) and not demonio16(v1)))){
                     S.push(v1);
                    dist[v1.i][v1.j]=dist[v.i][v.j]+1;
                    pre[v1.i][v1.j]=Right;
                 }
            casillas[2]=true;
            v1=v+RT;
            if(pos_ok(v1) and dist[v1.i][v1.j]==INFINIT and (casillas[3] or ( ( cell(v1).id==-1 or unit(cell(v1).id).player!=me() ) and not demonio16(v1)))){
                     S.push(v1);
                    dist[v1.i][v1.j]=dist[v.i][v.j]+1;
                    pre[v1.i][v1.j]=RT;
                 }
            casillas[3]=true;
           v1=v+Top;
            if(pos_ok(v1) and dist[v1.i][v1.j]==INFINIT and (casillas[4] or ( ( cell(v1).id==-1 or unit(cell(v1).id).player!=me() ) and not demonio16(v1)))){
                     S.push(v1);
                    dist[v1.i][v1.j]=dist[v.i][v.j]+1;
                    pre[v1.i][v1.j]=Top;
            }
            casillas[4]=true;
            v1=v+TL;
            if(pos_ok(v1) and dist[v1.i][v1.j]==INFINIT and (casillas[5] or ( ( cell(v1).id==-1 or unit(cell(v1).id).player!=me() ) and not demonio16(v1)))){
                     S.push(v1);
                    dist[v1.i][v1.j]=dist[v.i][v.j]+1;
                    pre[v1.i][v1.j]=TL;
            }
            casillas[5]=true;
            v1=v+Left;
            if(dist[v1.i][v1.j]==INFINIT and (casillas[6] or ( ( cell(v1).id==-1 or unit(cell(v1).id).player!=me() ) and not demonio16(v1)))){
                     S.push(v1);
                    dist[v1.i][v1.j]=dist[v.i][v.j]+1;
                     pre[v1.i][v1.j]=Left;
                 }
            casillas[6]=true;
            v1=v+LB;
            if(pos_ok(v1) and dist[v1.i][v1.j]==INFINIT and (casillas[7] or ( ( cell(v1).id==-1 or unit(cell(v1).id).player!=me() ) and not demonio16(v1)))){
                     S.push(v1);
                    dist[v1.i][v1.j]=dist[v.i][v.j]+1;
                     pre[v1.i][v1.j]=LB;
                 }
            casillas[7]=true;

                }


    }
    return o;
    }
 Pos bfspintar(Pos o, int &d, Dir &di){ //algoritmo de busqueda cuadrados por pintar evitando pasar por casillas que a su alrededor tienen a un monstruo y por las que tienen un enemigo y evivtando pisar a unidades en el primer paso para llegar a la casilla.
   d=-1;
    int n=40;
    int m=80;
    vector <vector <int> > dist(n,vector<int>(m,INFINIT));
    queue<Pos> S;
    vector <vector <Dir> > pre(n,vector<Dir>(m));
    vector<bool> casillas(8,false);
    S.push(o);
    dist[o.i][o.j] = 0;
    pre[o.i][o.j]=None;
    while(not S.empty()){
        Pos v=S.front();
        S.pop();
        Cell c=cell(v);
        if(c.type==Cave and c.owner!=me() and (c.id==-1 or unit(c.id).type==Pioneer) and not demonio(v)){
          d=dist[v.i][v.j];
          di=pre[v.i][v.j];
          Pos v2=v;
          while(v2!=o) {
            v2=v2+contrary(di);
          if(v2!=o)  di=pre[v2.i][v2.j];
          }
            return v;
        }
        else if(c.type!=Rock and (c.id==-1 or unit(c.id).type==Pioneer) and not demonio(v)){
          vector<int> orden(8);
          if (random(0, 2) == 0) {
            orden[0]=5;
            orden[1]=7;
          }
          else {
            orden[0]=7;
            orden[1]=5;
          }
          orden[2]=6;
          if (random(0, 2) == 0) {
            orden[3]=0;
            orden[4]=4;
          }
          else {
            orden[3]=4;
            orden[4]=0;
          }
          if (random(0, 2) == 0) {
            orden[5]=1;
            orden[6]=3;
          }
          else {
            orden[5]=3;
            orden[6]=1;
          }
          orden[7]=2;
          for(int i=0;i<=7;++i) {
           Pos v1=v+Dir(orden[i]);
            if(pos_ok(v1) and dist[v1.i][v1.j]==INFINIT and (casillas[orden[i]] or (cell(v1).id==-1 and not enemy(v1) and not demonio16(v1) ))){
                     S.push(v1);
                    dist[v1.i][v1.j]=dist[v.i][v.j]+1;
                      pre[v1.i][v1.j]=Dir(orden[i]);

                 }
                 casillas[orden[i]] =true;
          }
                }


    }
    return o;
    }

    Pos bfspintarrival(Pos o, int &d, Dir &di){ //algoritmo de busqueda cuadrados por pintar evitando pasar por casillas que a su alrededor tienen a un monstruo y por las que tienen un enemigo y evivtando pisar a unidades en el primer paso para llegar a la casilla.
   d=-1;
    int n=40;
    int m=80;
    vector <vector <int> > dist(n,vector<int>(m,INFINIT));
    queue<Pos> S;
    vector <vector <Dir> > pre(n,vector<Dir>(m));
    vector<bool> casillas(8,false);
    S.push(o);
    dist[o.i][o.j] = 0;
    pre[o.i][o.j]=None;
    while(not S.empty()){
        Pos v=S.front();
        S.pop();
        Cell c=cell(v);
        if(c.type==Cave and c.owner==rival and (c.id==-1 or unit(c.id).type==Pioneer) and not demonio(v)){
          d=dist[v.i][v.j];
          di=pre[v.i][v.j];
          Pos v2=v;
          while(v2!=o) {
            v2=v2+contrary(di);
          if(v2!=o)  di=pre[v2.i][v2.j];
          }
            return v;
        }
        else if(c.type!=Rock and (c.id==-1 or unit(c.id).type==Pioneer) and not demonio(v)){
            vector<int> orden(8);
          if (random(0, 2) == 0) {
            orden[0]=5;
            orden[1]=7;
          }
          else {
            orden[0]=7;
            orden[1]=5;
          }
          orden[2]=6;
          if (random(0, 2) == 0) {
            orden[3]=0;
            orden[4]=4;
          }
          else {
            orden[3]=4;
            orden[4]=0;
          }
          if (random(0, 2) == 0) {
            orden[5]=1;
            orden[6]=3;
          }
          else {
            orden[5]=3;
            orden[6]=1;
          }
          orden[7]=2;
          for(int i=0;i<=7;++i) {
           Pos v1=v+Dir(orden[i]);
            if(pos_ok(v1) and dist[v1.i][v1.j]==INFINIT and (casillas[orden[i]] or (cell(v1).id==-1 and not enemy(v1) and not demonio16(v1) ))){
                     S.push(v1);
                    dist[v1.i][v1.j]=dist[v.i][v.j]+1;
                      pre[v1.i][v1.j]=Dir(orden[i]);

                 }
                 casillas[orden[i]] =true;
          }
                }


    }
    return o;
    }

  Pos bfspintarrival2(Pos o, int &d, Dir &di){ //algoritmo de busqueda cuadrados por pintar evitando pasar por casillas que a su alrededor tienen a un monstruo y por las que tienen un enemigo y evivtando pisar a unidades en el primer paso para llegar a la casilla.
   d=-1;
    int n=40;
    int m=80;
    vector <vector <int> > dist(n,vector<int>(m,INFINIT));
    queue<Pos> S;
    vector <vector <Dir> > pre(n,vector<Dir>(m));
    vector<bool> casillas(8,false);
    S.push(o);
    dist[o.i][o.j] = 0;
    pre[o.i][o.j]=None;
    while(not S.empty()){
        Pos v=S.front();
        S.pop();
        Cell c=cell(v);
        if(c.type==Cave and c.owner==rival2 and (c.id==-1 or unit(c.id).type==Pioneer) and not demonio(v)){
          d=dist[v.i][v.j];
          di=pre[v.i][v.j];
          Pos v2=v;
          while(v2!=o) {
            v2=v2+contrary(di);
          if(v2!=o)  di=pre[v2.i][v2.j];
          }
            return v;
        }
        else if(c.type!=Rock and (c.id==-1 or unit(c.id).type==Pioneer) and not demonio(v)){
           vector<int> orden(8);
          if (random(0, 2) == 0) {
            orden[0]=5;
            orden[1]=7;
          }
          else {
            orden[0]=7;
            orden[1]=5;
          }
          orden[2]=6;
          if (random(0, 2) == 0) {
            orden[3]=0;
            orden[4]=4;
          }
          else {
            orden[3]=4;
            orden[4]=0;
          }
          if (random(0, 2) == 0) {
            orden[5]=1;
            orden[6]=3;
          }
          else {
            orden[5]=3;
            orden[6]=1;
          }
          orden[7]=2;
          for(int i=0;i<=7;++i) {
           Pos v1=v+Dir(orden[i]);
            if(pos_ok(v1) and dist[v1.i][v1.j]==INFINIT and (casillas[orden[i]] or (cell(v1).id==-1 and not enemy(v1) and not demonio16(v1) ))){
                     S.push(v1);
                    dist[v1.i][v1.j]=dist[v.i][v.j]+1;
                      pre[v1.i][v1.j]=Dir(orden[i]);

                 }
                 casillas[orden[i]] =true;
          }
                }


    }
    return o;
    }

    Pos bfspintarrival3(Pos o, int &d, Dir &di){ //algoritmo de busqueda cuadrados por pintar evitando pasar por casillas que a su alrededor tienen a un monstruo y por las que tienen un enemigo y evivtando pisar a unidades en el primer paso para llegar a la casilla.
   d=-1;
    int n=40;
    int m=80;
    vector <vector <int> > dist(n,vector<int>(m,INFINIT));
    queue<Pos> S;
    vector <vector <Dir> > pre(n,vector<Dir>(m));
    vector<bool> casillas(8,false);
    S.push(o);
    dist[o.i][o.j] = 0;
    pre[o.i][o.j]=None;
    while(not S.empty()){
        Pos v=S.front();
        S.pop();
        Cell c=cell(v);
        if(c.type==Cave and c.owner==rival3 and (c.id==-1 or unit(c.id).type==Pioneer) and not demonio(v)){
          d=dist[v.i][v.j];
          di=pre[v.i][v.j];
          Pos v2=v;
          while(v2!=o) {
            v2=v2+contrary(di);
          if(v2!=o)  di=pre[v2.i][v2.j];
          }
            return v;
        }
        else if(c.type!=Rock and (c.id==-1 or unit(c.id).type==Pioneer) and not demonio(v)){
            vector<int> orden(8);
          if (random(0, 2) == 0) {
            orden[0]=5;
            orden[1]=7;
          }
          else {
            orden[0]=7;
            orden[1]=5;
          }
          orden[2]=6;
          if (random(0, 2) == 0) {
            orden[3]=0;
            orden[4]=4;
          }
          else {
            orden[3]=4;
            orden[4]=0;
          }
          if (random(0, 2) == 0) {
            orden[5]=1;
            orden[6]=3;
          }
          else {
            orden[5]=3;
            orden[6]=1;
          }
          orden[7]=2;
          for(int i=0;i<=7;++i) {
           Pos v1=v+Dir(orden[i]);
            if(pos_ok(v1) and dist[v1.i][v1.j]==INFINIT and (casillas[orden[i]] or (cell(v1).id==-1 and not enemy(v1) and not demonio16(v1) ))){
                     S.push(v1);
                    dist[v1.i][v1.j]=dist[v.i][v.j]+1;
                      pre[v1.i][v1.j]=Dir(orden[i]);

                 }
                 casillas[orden[i]] =true;
          }
                }


    }
    return o;
    }



    Pos bfshellhound(Pos o, int &d, Dir &di){ //algoritmo de busqueda cuadrados por pintar evitando pasar por casillas que a su alrededor tienen a un monstruo y por las que tienen un enemigo y evivtando pisar a unidades en el primer paso para llegar a la casilla.
    d=-1;
    int n=40;
    int m=80;
    vector <vector <int> > dist(n,vector<int>(m,INFINIT));
    queue<Pos> S;
    vector <vector <Dir> > pre(n,vector<Dir>(m));
    vector<bool> casillas(8,false);
    S.push(o);
    dist[o.i][o.j] = 0;
    pre[o.i][o.j]=None;
    while(not S.empty()){
        Pos v=S.front();
        S.pop();
        Cell c=cell(v);
        if(c.type!=Rock and (c.id!=-1 and unit(c.id).player==-1)){
          d=dist[v.i][v.j];
          di=pre[v.i][v.j];
          Pos v2=v;
          while(v2!=o) {
            v2=v2+contrary(di);
          if(v2!=o)  di=pre[v2.i][v2.j];
          }
            return v;
        }
        else if(c.type!=Rock){
          for(int i=0;i<=7;++i) {
           Pos v1=v+Dir(i);
            if(pos_ok(v1) and dist[v1.i][v1.j]==INFINIT and (casillas[i] or cell(v1).id==-1)){
                     S.push(v1);
                    dist[v1.i][v1.j]=dist[v.i][v.j]+1;
                      pre[v1.i][v1.j]=Dir(i);

                 }
                 casillas[i] =true;
          }
                }


    }
    return o;
    }



    Pos bfsasc(Pos o, int &d, Dir &di){ //algoritmo de busqueda cuadrados por pintar evitando pasar por casillas que a su alrededor tienen a un monstruo y por las que tienen un enemigo y evivtando pisar a unidades en el primer paso para llegar a la casilla.
    d=-1;
    int n=40;
    int m=80;
    vector <vector <int> > dist(n,vector<int>(m,INFINIT));
    queue<Pos> S;
    vector <vector <Dir> > pre(n,vector<Dir>(m));
    vector<bool> casillas(8,false);
    S.push(o);
    dist[o.i][o.j] = 0;
    while(not S.empty()){
        Pos v=S.front();
        S.pop();
        Cell c=cell(v);
        if(c.type==Elevator and not demonio(v)){
          d=dist[v.i][v.j];
          di=pre[v.i][v.j];
          Pos v2=v;
          while(v2!=o) {
            v2=v2+contrary(di);
          if(v2!=o)  di=pre[v2.i][v2.j];
          }
            return v;
        }
        else if(c.type==Cave and (c.id==-1 or  unit(c.id).type==Pioneer) and not demonio(v)){
            vector<int> orden(8);
          if (random(0, 2) == 0) {
            orden[0]=5;
            orden[1]=7;
          }
          else {
            orden[0]=7;
            orden[1]=5;
          }
          orden[2]=6;
          if (random(0, 2) == 0) {
            orden[3]=0;
            orden[4]=4;
          }
          else {
            orden[3]=4;
            orden[4]=0;
          }
          if (random(0, 2) == 0) {
            orden[5]=1;
            orden[6]=3;
          }
          else {
            orden[5]=3;
            orden[6]=1;
          }
          orden[7]=2;
           for(int i=0;i<=7;++i) {
           Pos v1=v+Dir(orden[i]);
            if(pos_ok(v1) and dist[v1.i][v1.j]==INFINIT and (casillas[orden[i]] or (cell(v1).id==-1 and not enemy(v1) and not demonio16(v1) ))){
                     S.push(v1);
                    dist[v1.i][v1.j]=dist[v.i][v.j]+1;
                      pre[v1.i][v1.j]=Dir(orden[i]);

                 }
                 casillas[orden[i]] =true;
          }
        }


    }
    return o;
    }


bool sol(Pos v,int ronda){
  if(ronda>120) return true;
  int coli=(40+2*ronda)%80;
  int colf=(79+2*ronda)%80;
  if(coli<colf){
    if(v.j<coli or v.j>colf) return false;
  else return true;
  }
  else {
    if(v.j<coli and v.j>colf) return false;
    else return true;
  }

}

Pos bfsgema(Pos o,int &d, Dir &di, int ronda, int &pr){
    int n=40;
    int m=80;
    vector <vector <int> > dist(n,vector<int>(m,INFINIT));
    queue<Pos> S;
    vector <vector <Dir> > pre(n,vector<Dir>(m));
    vector<bool> casillas(8,false);
    S.push(o);
    dist[o.i][o.j] = 0;
    while(not S.empty()){
        Pos v=S.front();
        S.pop();
        Cell c=cell(v);
        if(not sol(v,ronda+dist[v.i][v.j]) and c.gem){
          auto it=gemas2.find(v);
          if(it==gemas2.end()){
            pr=gemas2.size();
            gemas2[v]=pr;
          }
          else pr=it->second;
          d=dist[v.i][v.j];
          di=pre[v.i][v.j];
          Pos v2=v;
          while(v2!=o) {
            v2=v2+contrary(di);
          if(v2!=o)  di=pre[v2.i][v2.j];
          }
            return v;
        }
        else if(not sol(v,ronda+dist[v.i][v.j]) and (c.id==-1 or unit(c.id).type==Pioneer)){
         for(int i=0;i<=7;++i) {
           Pos v1=v+Dir(i);
            if(pos_ok(v1) and dist[v1.i][v1.j]==INFINIT and (casillas[i] or (cell(v1).id==-1 and (not demonio(v1) or gemmy(v1) )))){
                     S.push(v1);
                    dist[v1.i][v1.j]=dist[v.i][v.j]+1;
                      pre[v1.i][v1.j]=Dir(i);

                 }
                 casillas[i] =true;
          }

        }


    }
    return o;
    }


Pos bfsgema2(Pos o,int &d, Dir &di, int ronda, int &pr){
    int n=40;
    int m=80;
    int k=0;
    vector <vector <int> > dist(n,vector<int>(m,INFINIT));
    queue<Pos> S;
    vector <vector <Dir> > pre(n,vector<Dir>(m));
    vector<bool> casillas(8,false);
    S.push(o);
    dist[o.i][o.j] = 0;
    while(not S.empty()){
        Pos v=S.front();
        S.pop();
        Cell c=cell(v);
        if(not sol(v,ronda+dist[v.i][v.j]) and c.gem and k==1){
          auto it=gemas2.find(v);
          if(it==gemas2.end()){
            pr=gemas2.size();
            gemas2[v]=pr;
          }
          else pr=it->second;
          d=dist[v.i][v.j];
          di=pre[v.i][v.j];
          Pos v2=v;
          while(v2!=o) {
            v2=v2+contrary(di);
          if(v2!=o)  di=pre[v2.i][v2.j];
          }
            return v;
        }
        else if(not sol(v,ronda+dist[v.i][v.j]) and c.gem) ++k;
        else if(not sol(v,ronda+dist[v.i][v.j]) and (c.id==-1 or unit(c.id).type==Pioneer)){
         for(int i=0;i<=7;++i) {
           Pos v1=v+Dir(i);
            if(pos_ok(v1) and dist[v1.i][v1.j]==INFINIT and (casillas[i] or (cell(v1).id==-1 and (not demonio(v1) or gemmy(v1) )))){
                     S.push(v1);
                    dist[v1.i][v1.j]=dist[v.i][v.j]+1;
                      pre[v1.i][v1.j]=Dir(i);

                 }
                 casillas[i] =true;
          }

        }


    }
    return o;
    }





    Pos bfsascensorvivo(Pos o, int &d, Dir &di){ //algoritmo de busqueda cuadrados por pintar evitando pasar por casillas que a su alrededor tienen a un monstruo y por las que tienen un enemigo y evivtando pisar a unidades en el primer paso para llegar a la casilla.
    d=-1;
    int n=40;
    int m=80;
    int ronda=round();
    vector <vector <int> > dist(n,vector<int>(m,INFINIT));
    queue<Pos> S;
    vector <vector <Dir> > pre(n,vector<Dir>(m));
    vector<bool> casillas(8,false);
    S.push(o);
    dist[o.i][o.j] = 0;
    pre[o.i][o.j]=None;
    while(not S.empty()){
        Pos v=S.front();
        S.pop();
      if(ronda+dist[v.i][v.j]>120) return o;
        Cell c=cell(v);
        if(not sol(v,ronda+dist[v.i][v.j]) and c.type==Elevator){
          d=dist[v.i][v.j];
          di=pre[v.i][v.j];
          Pos v2=v;
          while(v2!=o) {
            v2=v2+contrary(di);
          if(v2!=o)  di=pre[v2.i][v2.j];
          }
            return v;
        }
        else if(not sol(v,ronda+dist[v.i][v.j]) and (c.id==-1 or unit(c.id).type==Pioneer)){
            for(int i=0;i<=7;++i) {
           Pos v1=v+Dir(i);
            if(pos_ok(v1) and dist[v1.i][v1.j]==INFINIT and (casillas[i] or (cell(v1).id==-1 and (not demonio(v1) or ascensory(v1))))){ //
                     S.push(v1);
                    dist[v1.i][v1.j]=dist[v.i][v.j]+1;
                      pre[v1.i][v1.j]=Dir(i);

                 }
                 casillas[i] =true;
          }

                }


    }
    return o;
    }

  Dir huir(Pos pp){
    vector <int> cas(8);
    if (random(0, 2) == 0) {
            cas[0]=5;
            cas[1]=7;
          }
          else {
            cas[0]=7;
            cas[1]=5;
          }
          cas[2]=6;
          if (random(0, 2) == 0) {
            cas[3]=0;
            cas[4]=4;
          }
          else {
            cas[3]=4;
            cas[4]=0;
          }
          if (random(0, 2) == 0) {
            cas[5]=1;
            cas[6]=3;
          }
          else {
            cas[5]=3;
            cas[6]=1;
          }
          cas[7]=2;
    for(int b=0;b<=7;++b) {
        Dir dp=Dir(cas[b]);
        Cell cp=cell(pp+dp);
        int idp=cp.id;
        if(idp!=-1 ) {
          Unit ene= unit(idp);
          if(ene.player!=-1 and ene.player!=me() and ene.type==Furyan ){ //añadir caso de si no es pared ir al menos parecido posible??
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(dc!=dp and cc.type==Cave and cc.owner==rival and not enemy(pp+dc) and not demonio16(pp+dc)) return  dc;
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(dc!=dp and cc.type==Cave and cc.owner!=me() and not enemy(pp+dc) and not demonio16(pp+dc)) return  dc;
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(dc!=dp and cc.type!=Rock and not enemy(pp+dc) and not demonio16(pp+dc) ) return  dc;
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(dc!=dp and cc.type==Cave and cc.owner==rival and cc.id==-1 and not demonio16(pp+dc)) return  dc;
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(dc!=dp and cc.type==Cave and cc.owner!=me() and cc.id==-1 and not demonio16(pp+dc)) return  dc;
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(dc!=dp and cc.type!=Rock and cc.id==-1 and not demonio16(pp+dc)) return  dc;
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(dc!=dp and cc.type==Cave and cc.owner==rival and cc.id==-1 ) return  dc;
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(dc!=dp and cc.type==Cave and cc.owner!=me() and cc.id==-1 ) return  dc;
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(dc!=dp and cc.type!=Rock and cc.id==-1 ) return  dc;
            }


                }
              }
            }
return None;
                }

Dir huirp(Pos pp){
    vector <int> cas(8);
   if (random(0, 2) == 0) {
            cas[0]=5;
            cas[1]=7;
          }
          else {
            cas[0]=7;
            cas[1]=5;
          }
          cas[2]=6;
          if (random(0, 2) == 0) {
            cas[3]=0;
            cas[4]=4;
          }
          else {
            cas[3]=4;
            cas[4]=0;
          }
          if (random(0, 2) == 0) {
            cas[5]=1;
            cas[6]=3;
          }
          else {
            cas[5]=3;
            cas[6]=1;
          }
          cas[7]=2;
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner==rival and idc==-1 and not enemy(pp+dc) and not demonio16(pp+dc)) return  dc;
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner!=me() and idc==-1 and not enemy(pp+dc) and not demonio16(pp+dc)) return  dc;
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type!=Rock and idc==-1 and not enemy(pp+dc) and not demonio16(pp+dc) ) return  dc;
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner==rival and cc.id==-1 and not demonio16(pp+dc)) return  dc;
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner!=me() and cc.id==-1 and not demonio16(pp+dc)) return  dc;
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type!=Rock and cc.id==-1 and not demonio16(pp+dc)) return  dc;
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner==rival and cc.id==-1 ) return  dc;
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if( cc.type==Cave and cc.owner!=me() and cc.id==-1 ) return  dc;
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type!=Rock and cc.id==-1 ) return  dc;
            }



return None;
                }



    void priospio(){
      vector<int> P= random_permutation(np);
    //añadir randomizacion de orden de comandos si no añadimos el orden nosotros
    for(int a=0;a<np;++a) {
      Unit u = unit(Pi[P[a]]);
      Pos pp=u.pos;
      if(pp.k==0) { //pensar and (not comandos[trad[P[a]]] or trad[P[a]]>=comandos.size())
      int dist,dist2,dist3,dist4,pr,pr4,disrr,disss,dist5;
      dist=dist2=-1;
      Dir di,di2,di3,di4,dirr,diss,di5;
   //   Dir dih=huir(pp);
      Pos b=bfspintar(pp,dist,di);
      Pos b2=bfspintarrival(pp,disrr,dirr);
      Pos b3=bfspintarrival2(pp,disss,diss);
      Pos b5=bfspintarrival3(pp,dist5,di5);
      Pos c=bfsasc(pp,dist2,di2);
      Pos d,d2;
      if(dist2!=-1 and (round()+dist2)<=120){ //+1
        d=bfsgema(c+Up,dist3,di3,round()+dist2,pr); //+1
        d2=bfsgema2(c+Up,dist4,di4,round()+dist2,pr4);
      }


      // if(dih!=None){
      //   priocomandos.emplace(make_pair(0,make_pair(1,(-2600+u.health))),make_pair(Pi[P[a]],dih));
      // }
      if(dist2!=-1 and d!=c+Up) {
        if(pp==c) priocomandos.emplace(make_pair(1,make_pair(dist3,pr)),make_pair(Pi[P[a]],Up));
   //     else if(pp==c) priocomandos.emplace(make_pair(0,make_pair(1,-2600+u.health)),make_pair(Pi[P[a]],Up));
        else priocomandos.emplace(make_pair(1,make_pair(dist2+dist3,pr)),make_pair(Pi[P[a]],di2));
     //   else priocomandos.emplace(make_pair(0,make_pair(1,-2600+u.health)),make_pair(Pi[P[a]],di2));
      }
      if(dist4!=-1 and d2!=c+Up) {
        if(pp==c) priocomandos.emplace(make_pair(1,make_pair(dist4,pr4)),make_pair(Pi[P[a]],Up));
        else priocomandos.emplace(make_pair(1,make_pair(dist2+dist4,pr4)),make_pair(Pi[P[a]],di4));
      }

      if(b!=pp) {
        if(b2!=pp and (dist==-1 or disrr<=dist) and not enemy(pp)) priocomandos.emplace(make_pair(4,make_pair(disrr,0)),make_pair(Pi[P[a]],dirr));
        else if(b2!=pp and (dist==-1 or disrr<=dist)) priocomandos.emplace(make_pair(0,make_pair(1,-2600+u.health)),make_pair(Pi[P[a]],dirr));
        if(b3!=pp and (dist==-1 or disss<=dist) and not enemy(pp)) priocomandos.emplace(make_pair(4,make_pair(disss,0)),make_pair(Pi[P[a]],diss));
        else if(b3!=pp and (dist==-1 or disss<=dist)) priocomandos.emplace(make_pair(0,make_pair(1,-2600+u.health)),make_pair(Pi[P[a]],diss));
        if(b5!=pp and (dist==-1 or dist5<=dist) and not enemy(pp)) priocomandos.emplace(make_pair(4,make_pair(dist5,0)),make_pair(Pi[P[a]],di5));
        else if(b5!=pp and (dist==-1 or dist5<=dist)) priocomandos.emplace(make_pair(0,make_pair(1,-2600+u.health)),make_pair(Pi[P[a]],di5));
        if(not enemy(pp)) priocomandos.emplace(make_pair(4,make_pair(dist,0)),make_pair(Pi[P[a]],di));
        else priocomandos.emplace(make_pair(0,make_pair(1,-2600+u.health)),make_pair(Pi[P[a]],di));
       }
       if(b==pp and d==c+Up and d2==c+Up) {
          vector <int> cas(8);
            if (random(0, 2) == 0) {
            cas[0]=5;
            cas[1]=7;
          }
          else {
            cas[0]=7;
            cas[1]=5;
          }
          cas[2]=6;
          if (random(0, 2) == 0) {
            cas[3]=0;
            cas[4]=4;
          }
          else {
            cas[3]=4;
            cas[4]=0;
          }
          if (random(0, 2) == 0) {
            cas[5]=1;
            cas[6]=3;
          }
          else {
            cas[5]=3;
            cas[6]=1;
          }
          cas[7]=2;
        if(enemy(pp)){
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner==rival and not enemy(pp+dc) and not demonio16(pp+dc)) priocomandos.emplace(make_pair(0,make_pair(1,(-2600+u.health))),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner==rival2 and not enemy(pp+dc) and not demonio16(pp+dc)) priocomandos.emplace(make_pair(0,make_pair(1,(-2600+u.health))),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner==rival3 and not enemy(pp+dc) and not demonio16(pp+dc)) priocomandos.emplace(make_pair(0,make_pair(1,(-2600+u.health))),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner!=me() and not enemy(pp+dc) and not demonio16(pp+dc)) priocomandos.emplace(make_pair(0,make_pair(1,(-2600+u.health))),make_pair(Pi[P[a]],dc));
            }

            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner==me() and not enemy(pp+dc) and not demonio16(pp+dc)) priocomandos.emplace(make_pair(0,make_pair(1,(-2600+u.health))),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type!=Rock and not enemy(pp+dc) and not demonio16(pp+dc) ) priocomandos.emplace(make_pair(0,make_pair(1,(-2600+u.health))),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner==rival and cc.id==-1 and not demonio16(pp+dc)) priocomandos.emplace(make_pair(0,make_pair(1,(-2600+u.health))),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner==rival2 and cc.id==-1 and not demonio16(pp+dc)) priocomandos.emplace(make_pair(0,make_pair(1,(-2600+u.health))),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner==rival3 and cc.id==-1 and not demonio16(pp+dc)) priocomandos.emplace(make_pair(0,make_pair(1,(-2600+u.health))),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner!=me() and cc.id==-1 and not demonio16(pp+dc)) priocomandos.emplace(make_pair(0,make_pair(1,(-2600+u.health))),make_pair(Pi[P[a]],dc));
            }

            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner==me() and cc.id==-1 and not demonio16(pp+dc)) priocomandos.emplace(make_pair(0,make_pair(1,(-2600+u.health))),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type!=Rock and cc.id==-1 and not demonio16(pp+dc)) priocomandos.emplace(make_pair(0,make_pair(1,(-2600+u.health))),make_pair(Pi[P[a]],dc));
            }

            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner==rival and cc.id==-1 and not demonio(pp+dc)) priocomandos.emplace(make_pair(0,make_pair(1,(-2600+u.health))),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner==rival2 and cc.id==-1 and not demonio(pp+dc)) priocomandos.emplace(make_pair(0,make_pair(1,(-2600+u.health))),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner==rival3 and cc.id==-1 and not demonio(pp+dc)) priocomandos.emplace(make_pair(0,make_pair(1,(-2600+u.health))),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner!=me() and cc.id==-1 and not demonio(pp+dc)) priocomandos.emplace(make_pair(0,make_pair(1,(-2600+u.health))),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner==me() and cc.id==-1 and not demonio(pp+dc)) priocomandos.emplace(make_pair(0,make_pair(1,(-2600+u.health))),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type!=Rock and cc.id==-1 and not demonio(pp+dc)) priocomandos.emplace(make_pair(0,make_pair(1,(-2600+u.health))),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner==rival and cc.id==-1 ) priocomandos.emplace(make_pair(0,make_pair(1,(-2600+u.health))),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner==rival2 and cc.id==-1 ) priocomandos.emplace(make_pair(0,make_pair(1,(-2600+u.health))),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner==rival3 and cc.id==-1 ) priocomandos.emplace(make_pair(0,make_pair(1,(-2600+u.health))),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner!=me() and cc.id==-1 ) priocomandos.emplace(make_pair(0,make_pair(1,(-2600+u.health))),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner==me() and cc.id==-1 ) priocomandos.emplace(make_pair(0,make_pair(1,(-2600+u.health))),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type!=Rock and cc.id==-1 ) priocomandos.emplace(make_pair(0,make_pair(1,(-2600+u.health))),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type!=Rock and idc!=-1 and unit(idc).type==Pioneer) priocomandos.emplace(make_pair(0,make_pair(1,(-2600+u.health))),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type!=Rock) priocomandos.emplace(make_pair(0,make_pair(1,(-2600+u.health))),make_pair(Pi[P[a]],dc));
            }


              }
            }


      Pos e=bfshellhound(pp,dist,di);
      if(e!=pp) {
        vector <int> cas(8);
       if (random(0, 2) == 0) {
            cas[0]=5;
            cas[1]=7;
          }
          else {
            cas[0]=7;
            cas[1]=5;
          }
          cas[2]=6;
          if (random(0, 2) == 0) {
            cas[3]=0;
            cas[4]=4;
          }
          else {
            cas[3]=4;
            cas[4]=0;
          }
          if (random(0, 2) == 0) {
            cas[5]=1;
            cas[6]=3;
          }
          else {
            cas[5]=3;
            cas[6]=1;
          }
          cas[7]=2;
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner==rival and idc==-1 and not enemy(pp+dc) and not demonio16(pp+dc))  priocomandos.emplace(make_pair(5,make_pair(dist,0)),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner==rival2 and idc==-1 and not enemy(pp+dc) and not demonio16(pp+dc))  priocomandos.emplace(make_pair(5,make_pair(dist,0)),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner==rival3 and idc==-1 and not enemy(pp+dc) and not demonio16(pp+dc))  priocomandos.emplace(make_pair(5,make_pair(dist,0)),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner!=me() and idc==-1 and not enemy(pp+dc) and not demonio16(pp+dc)) priocomandos.emplace(make_pair(5,make_pair(dist,0)),make_pair(Pi[P[a]],dc));
            }
              for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner==me() and idc==-1 and not enemy(pp+dc) and not demonio16(pp+dc)) priocomandos.emplace(make_pair(5,make_pair(dist,0)),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type!=Rock and idc==-1 and not enemy(pp+dc) and not demonio16(pp+dc) ) priocomandos.emplace(make_pair(5,make_pair(dist,0)),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner==rival and cc.id==-1 and not demonio16(pp+dc)) priocomandos.emplace(make_pair(5,make_pair(dist,0)),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner==rival2 and cc.id==-1 and not demonio16(pp+dc)) priocomandos.emplace(make_pair(5,make_pair(dist,0)),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner==rival3 and cc.id==-1 and not demonio16(pp+dc)) priocomandos.emplace(make_pair(5,make_pair(dist,0)),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner!=me() and cc.id==-1 and not demonio16(pp+dc)) priocomandos.emplace(make_pair(5,make_pair(dist,0)),make_pair(Pi[P[a]],dc));
            }

            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner==me() and cc.id==-1 and not demonio16(pp+dc)) priocomandos.emplace(make_pair(5,make_pair(dist,0)),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type!=Rock and cc.id==-1 and not demonio16(pp+dc)) priocomandos.emplace(make_pair(5,make_pair(dist,0)),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner==rival and cc.id==-1 and not demonio(pp+dc)) priocomandos.emplace(make_pair(5,make_pair(dist,0)),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner==rival2 and cc.id==-1 and not demonio(pp+dc)) priocomandos.emplace(make_pair(5,make_pair(dist,0)),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner==rival3 and cc.id==-1 and not demonio(pp+dc)) priocomandos.emplace(make_pair(5,make_pair(dist,0)),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner!=me() and cc.id==-1 and not demonio(pp+dc)) priocomandos.emplace(make_pair(5,make_pair(dist,0)),make_pair(Pi[P[a]],dc));
            }

            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner==me() and cc.id==-1 and not demonio(pp+dc)) priocomandos.emplace(make_pair(5,make_pair(dist,0)),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type!=Rock and cc.id==-1 and not demonio(pp+dc)) priocomandos.emplace(make_pair(5,make_pair(dist,0)),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner==rival and cc.id==-1 ) priocomandos.emplace(make_pair(5,make_pair(dist,0)),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner==rival2 and cc.id==-1 ) priocomandos.emplace(make_pair(5,make_pair(dist,0)),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type==Cave and cc.owner==rival3 and cc.id==-1 ) priocomandos.emplace(make_pair(5,make_pair(dist,0)),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if( cc.type==Cave and cc.owner!=me() and cc.id==-1 ) priocomandos.emplace(make_pair(5,make_pair(dist,0)),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if( cc.type==Cave and cc.owner==me() and cc.id==-1 ) priocomandos.emplace(make_pair(5,make_pair(dist,0)),make_pair(Pi[P[a]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type!=Rock and cc.id==-1 ) priocomandos.emplace(make_pair(5,make_pair(dist,0)),make_pair(Pi[P[a]],dc));
            }
          for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type!=Rock and idc!=-1 and unit(idc).type==Pioneer) priocomandos.emplace(make_pair(5,make_pair(dist,0)),make_pair(Pi[P[a]],dc));
            }
           for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pp+dc);
               int idc=cc.id;
              if(cc.type!=Rock) priocomandos.emplace(make_pair(5,make_pair(dist,0)),make_pair(Pi[P[a]],dc));
            }
      }

/*
        Dir dih=huirp(pp);
        priocomandos.emplace(make_pair(5,make_pair(dist,0)),make_pair(Pi[P[a]],dih));*/
      }
    else {
      int dist,dist2,pr,pr2;
      Dir di,di2;
      Pos b=bfsgema(pp,dist,di,round(),pr);
      Pos b2=bfsgema2(pp,dist2,di2,round(),pr2);
      if(b!=pp) {
        priocomandos.emplace(make_pair(1,make_pair(dist,pr)),make_pair(Pi[P[a]],di));
      }
      if(b2!=pp) {
        priocomandos.emplace(make_pair(1,make_pair(dist2,pr2)),make_pair(Pi[P[a]],di2));
      }
      else {
        b=bfsascensorvivo(pp,dist,di);
        if(b!=pp) priocomandos.emplace(make_pair(3,make_pair(dist,0)),make_pair(Pi[P[a]],di));
        else if(dist!=-1) priocomandos.emplace(make_pair(3,make_pair(dist,0)),make_pair(Pi[P[a]],Down));
        else {
                if(cell(pp+Right).id==-1) priocomandos.emplace(make_pair(5,make_pair(3,0)),make_pair(Pi[P[a]],Right)); //quitados else
                 if(cell(pp+BR).id==-1) priocomandos.emplace(make_pair(5,make_pair(3,0)),make_pair(Pi[P[a]],BR));
                 if(cell(pp+RT).id==-1) priocomandos.emplace(make_pair(5,make_pair(3,0)),make_pair(Pi[P[a]],RT));
        }
      }

     }
    }}

    void cargarataques(){
      //separar entre pionero y furyano.
      vector<int> F = random_permutation(nf);
      for (int i = 0; i < nf; ++i) {
        Unit u = unit(Fu[F[i]]);
        Pos pf=u.pos;
        int dist,dist2,dist3,disth;
        Dir di,di2,di3,dih;
        Pos b=bfsataquecueva(pf,dist,di);
        Pos b2=bfsataquecuevarival(pf,dist2,di2);
     //   Pos b3=bfsataquecuevarival2(pf,dist3,di3);

        Pos e=bfshellhound(pf,disth,dih);
        if(pf!=b2 and (dist==-1 or dist2<=dist) and disth!=2) {
          Unit u2=unit(cell(b).id);
          if(dist2==2 and u2.type==Furyan) priocomandos.emplace(make_pair(5,make_pair(dist2,(-1*u.health))),make_pair(Fu[F[i]],di2));
          else if(u2.type==Furyan and u2.health<=25 and u.health<=25) priocomandos.emplace(make_pair(0,make_pair(dist2,(-3500+u.health+u2.health))),make_pair(Fu[F[i]],di2));
          else if(u2.type==Furyan and ((u2.health<=25 and u.health<=50) or (u2.health<=50 and u.health<=25))) priocomandos.emplace(make_pair(0,make_pair(dist2,(-3200+u.health+u2.health))),make_pair(Fu[F[i]],di2));
          else if(u2.type==Furyan and u2.health<=50 and u.health<=50) priocomandos.emplace(make_pair(0,make_pair(dist2,(-2900+u.health+u2.health))),make_pair(Fu[F[i]],di2));
          else if(u2.type==Furyan and u2.health<=25) priocomandos.emplace(make_pair(0,make_pair(dist2,(-2400+u.health+u2.health))),make_pair(Fu[F[i]],di2));
          else if(u2.type==Furyan and u2.health<=50) priocomandos.emplace(make_pair(0,make_pair(dist2,(-2150+u.health+u2.health))),make_pair(Fu[F[i]],di2));
          else if(u2.type==Furyan and u.health<=50) priocomandos.emplace(make_pair(0,make_pair(dist2,(-1950+u.health+u2.health))),make_pair(Fu[F[i]],di2));
          else if(u2.type==Furyan and u.health<=25) priocomandos.emplace(make_pair(0,make_pair(dist2,(-1800+u.health+u2.health))),make_pair(Fu[F[i]],di2));
          else if(u2.type==Pioneer) priocomandos.emplace(make_pair(0,make_pair(dist2,(-1650+u2.health))),make_pair(Fu[F[i]],di2));
          else if(u2.type==Furyan) priocomandos.emplace(make_pair(0,make_pair(dist2,(-1550+u.health+u2.health))),make_pair(Fu[F[i]],di2));

        }
        // else if(pf!=b3 and (dist==-1 or dist3<=dist)) {
        //    Unit u2=unit(cell(b).id);
        //   if(dist3==2 and u2.type==Furyan) priocomandos.emplace(make_pair(5,make_pair(dist3,(-1*u.health))),make_pair(Fu[F[i]],di3));
        //   else if(u2.type==Furyan and u2.health<=25 and u.health<=25) priocomandos.emplace(make_pair(0,make_pair(dist3,(-3500+u.health+u2.health))),make_pair(Fu[F[i]],di3));
        //   else if(u2.type==Furyan and ((u2.health<=25 and u.health<=50) or (u2.health<=50 and u.health<=25))) priocomandos.emplace(make_pair(0,make_pair(dist3,(-3200+u.health+u2.health))),make_pair(Fu[F[i]],di3));
        //   else if(u2.type==Furyan and u2.health<=50 and u.health<=50) priocomandos.emplace(make_pair(0,make_pair(dist3,(-2900+u.health+u2.health))),make_pair(Fu[F[i]],di3));
        //   else if(u2.type==Furyan and u2.health<=25) priocomandos.emplace(make_pair(0,make_pair(dist3,(-2400+u.health+u2.health))),make_pair(Fu[F[i]],di3));
        //   else if(u2.type==Furyan and u2.health<=50) priocomandos.emplace(make_pair(0,make_pair(dist3,(-2150+u.health+u2.health))),make_pair(Fu[F[i]],di3));
        //   else if(u2.type==Furyan and u.health<=50) priocomandos.emplace(make_pair(0,make_pair(dist3,(-1950+u.health+u2.health))),make_pair(Fu[F[i]],di3));
        //   else if(u2.type==Furyan and u.health<=25) priocomandos.emplace(make_pair(0,make_pair(dist3,(-1800+u.health+u2.health))),make_pair(Fu[F[i]],di3));
        //   else if(u2.type==Pioneer) priocomandos.emplace(make_pair(0,make_pair(dist3,(-1650+u2.health))),make_pair(Fu[F[i]],di3));
        //   else if(u2.type==Furyan) priocomandos.emplace(make_pair(0,make_pair(dist3,(-1550+u.health+u2.health))),make_pair(Fu[F[i]],di3));
        // }
        else if(pf!=b and disth!=2){ //quitar if??
          Unit u2=unit(cell(b).id);
          if(dist==2 and u2.type==Furyan) priocomandos.emplace(make_pair(5,make_pair(dist,(-1*u.health))),make_pair(Fu[F[i]],di));
          else if(u2.type==Furyan and u2.health<=25 and u.health<=25) priocomandos.emplace(make_pair(0,make_pair(dist,(-3500+u.health+u2.health))),make_pair(Fu[F[i]],di));
          else if(u2.type==Furyan and ((u2.health<=25 and u.health<=50) or (u2.health<=50 and u.health<=25))) priocomandos.emplace(make_pair(0,make_pair(dist,(-3200+u.health+u2.health))),make_pair(Fu[F[i]],di));
          else if(u2.type==Furyan and u2.health<=50 and u.health<=50) priocomandos.emplace(make_pair(0,make_pair(dist,(-2900+u.health+u2.health))),make_pair(Fu[F[i]],di));
          else if(u2.type==Furyan and u2.health<=25) priocomandos.emplace(make_pair(0,make_pair(dist,(-2400+u.health+u2.health))),make_pair(Fu[F[i]],di));
          else if(u2.type==Furyan and u2.health<=50) priocomandos.emplace(make_pair(0,make_pair(dist,(-2150+u.health+u2.health))),make_pair(Fu[F[i]],di));
          else if(u2.type==Furyan and u.health<=50) priocomandos.emplace(make_pair(0,make_pair(dist,(-1950+u.health+u2.health))),make_pair(Fu[F[i]],di));
          else if(u2.type==Furyan and u.health<=25) priocomandos.emplace(make_pair(0,make_pair(dist,(-1800+u.health+u2.health))),make_pair(Fu[F[i]],di));
          else if(u2.type==Pioneer) priocomandos.emplace(make_pair(0,make_pair(dist,(-1650+u2.health))),make_pair(Fu[F[i]],di));
          else if(u2.type==Furyan) priocomandos.emplace(make_pair(0,make_pair(dist,(-1550+u.health+u2.health))),make_pair(Fu[F[i]],di));

        }

        if(e!=pf){
          if(disth==2){
             vector <int> cas(8);
    cas=random_permutation(8);
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pf+dc);
               int idc=cc.id;
              if(cc.type!=Rock and not enemy(pf+dc) and not demonio16(pf+dc)) priocomandos.emplace(make_pair(4,make_pair(2,0)),make_pair(Fu[F[i]],dc));
            }

            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pf+dc);
               int idc=cc.id;
              if(cc.type!=Rock and cc.id==-1 and not demonio16(pf+dc)) priocomandos.emplace(make_pair(4,make_pair(2,0)),make_pair(Fu[F[i]],dc));
            }

            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pf+dc);
               int idc=cc.id;
              if(cc.type!=Rock and cc.id==-1 and not demonio(pf+dc)) priocomandos.emplace(make_pair(4,make_pair(2,0)),make_pair(Fu[F[i]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pf+dc);
               int idc=cc.id;
              if(cc.type!=Rock and cc.id==-1 ) priocomandos.emplace(make_pair(4,make_pair(2,0)),make_pair(Fu[F[i]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pf+dc);
               int idc=cc.id;
              if(cc.type!=Rock and idc!=-1 and unit(idc).type==Pioneer) priocomandos.emplace(make_pair(4,make_pair(2,0)),make_pair(Fu[F[i]],dc));
            }
            for(int f=0;f<=7;++f) {
              Dir dc=Dir(cas[f]);
               Cell cc=cell(pf+dc);
               int idc=cc.id;
              if(cc.type!=Rock) priocomandos.emplace(make_pair(4,make_pair(2,0)),make_pair(Fu[F[i]],dc));
            }

          }
          Cell c=cell(pf+contrary(dih));
        if(c.type!=Rock and c.id==-1) priocomandos.emplace(make_pair(4,make_pair(disth,0)),make_pair(Fu[F[i]],contrary(dih)));
        else {
          int a=contrary(dih);
           c=cell(pf+Dir(a+1));
           if(c.type!=Rock and c.id==-1) priocomandos.emplace(make_pair(4,make_pair(disth,0)),make_pair(Fu[F[i]],Dir(a+1)));
           else {
             c=cell(pf+Dir(a-1));
           if(c.type!=Rock and c.id==-1) priocomandos.emplace(make_pair(4,make_pair(disth,0)),make_pair(Fu[F[i]],Dir(a-1)));
          }
        }
        }
    }}
    void inicialitzar(){
        Fu=furyans(me());
        Pi=pioneers(me());
        nf=Fu.size();
        np=Pi.size();
        vector<bool> cp(np,false);
        comandosp=cp;
        vector<bool> cf(nf,false);
        comandosf=cf;
        multimap <pair<int,pair<int,int>>,pair<int,Dir> > m;
        priocomandos=m;
        map<int,int> t;
        tradp=t;
        tradf=t;
         map<Pos,int> g2;
         gemas2=g2;
          set<Pos> mov;
          movimientos=mov;
          int pmios=nb_cells(me())+30*nb_gems(me());
          int pmax,p2max,p3max,p4max;
          pmax=p2max=p3max=p4max=0;
          int posmia=1;
          int primero,segundo,tercero,cuarto;
          primero=segundo=tercero=cuarto=me();
          for(int i=0;i<=3;++i) {
              int psuyos=nb_cells(i)+30*nb_gems(i);
              if(psuyos>pmios and i!=me()) ++posmia;
              if(psuyos>pmax){
                p4max=p3max;
                p3max=p2max;
                p2max=pmax;
                pmax=psuyos;
                cuarto=tercero;
                tercero=segundo;
                segundo=primero;
                primero=i;

            }
            else if(psuyos>p2max){
                p4max=p3max;
                p3max=p2max;
                p2max=psuyos;
                cuarto=tercero;
                tercero=segundo;
                segundo=i;
            }
             else if(psuyos>p3max){
                p4max=p3max;
                p3max=psuyos;
                cuarto=tercero;
                tercero=i;
            }
             else if(psuyos>p4max){
                p4max=psuyos;
                cuarto=i;
            }
          }

          if(posmia==1){
            rival=segundo;
            rival2=tercero;
            rival3=cuarto;
          }
          else if(posmia==4){
            rival=tercero;
            rival2=segundo;
            rival3=primero;
          }
          else if(posmia==2) {
            if(abs(p2max-pmax)<=abs(p2max-p3max)){
              rival=primero;
              rival2=tercero;
              rival3=cuarto;
            }
            else{
              rival=tercero;
              rival2=primero;
              rival3=cuarto;
            }}
          else if(posmia==3) {
            if(abs(p3max-p2max)<=abs(p3max-p4max)){
              rival=segundo;
              rival2=cuarto;
              rival3=primero;
            }
            else{
              rival=cuarto;
              rival2=segundo;
              rival3=primero;
            }
          }
    }

    void comandar(){

        vector<bool> cg(gemas2.size(),false);
        cerr<<gemas2.size()<<endl;
        comandosg=cg;
      for(int i=0;i<np;++i) {
        tradp[Pi[i]]=i;
      }
      for(int i=0;i<nf;++i){
        tradf[Fu[i]]=i;
      }
      for (auto it = priocomandos.cbegin(); it != priocomandos.cend(); ++it){
        pair <int,Dir>a =it->second;
        pair<int,pair<int,int>> d=it->first;
        Unit b= unit(a.first);
        Pos po=b.pos+a.second;
        int e=d.second.second;
        auto its=movimientos.find(po);
        int f=gemas2.size();
        if(b.type==Pioneer and d.first==1 and not comandosp[tradp[a.first]] and its==movimientos.end() and e>=0 and e<f and not comandosg[e]) {

          comandosg[e]=true;
          comandosp[tradp[a.first]]=true;
          movimientos.insert(po);
          command(a.first,a.second);

        }
        if(b.type==Pioneer and d.first!=1 and not comandosp[tradp[a.first]] and its==movimientos.end()) {
          comandosp[tradp[a.first]]=true;
          movimientos.insert(po);
          command(a.first,a.second);

        }
        else if(b.type==Furyan and not comandosf[tradf[a.first]] and its==movimientos.end()){
          comandosf[tradf[a.first]]=true;
          movimientos.insert(po);
          command(a.first,a.second);

        }
      }
    }
    void rivalatq(){
      int pmios=nb_cells(me())+30*nb_gems(me());
          int pmax=pmios;
          int p2max=0;
          int posmia=1;
          int primero,segundo;
          primero=segundo=me();
          for(int i=0;i<=3;++i) {
            if(i!=me()) {
              int psuyos=nb_cells(i)+30*nb_gems(i);
              if(psuyos>pmios) ++posmia;
              if(psuyos>pmax){
                pmax=psuyos;
                primero=i;
            }
            else if(psuyos>p2max){
                p2max=psuyos;
                segundo=i;
            }
          }}
          if(posmia==2) rival=primero;
          else rival=segundo;
    }

  virtual void play () {
    inicialitzar();
    priospio();
    rivalatq();
    cargarataques();
    comandar();
  }

};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
