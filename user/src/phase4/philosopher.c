#include "philosopher.h"

// TODO: define some sem if you need
int sem_id[PHI_NUM],mutex;

void init() {
  // init some sem if you need
  //TODO();
  for(int i=0;i<PHI_NUM;++i)
    sem_id[i]=sem_open(1);
  mutex=sem_open(4);
}

void philosopher(int id) {
  // implement philosopher, remember to call `eat` and `think`
  while (1) {
    //TODO();
    P(mutex);
    P(sem_id[id]);
    P(sem_id[(id+1)%PHI_NUM]);
    eat(id);
    V(sem_id[id]);
    V(sem_id[(id+1)%PHI_NUM]);
    V(mutex);
    think(id);
  }
}
