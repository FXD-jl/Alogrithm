#ifndef __MONSTER__
#define __MONSTER__

typedef enum Boat_location_ {
  LOCAL = 0,
  REMOTE = 1,
} Boat_location;

typedef struct Status_ {
  int local_monster;
  int local_monk;
  int remote_monster;
  int remote_monk;
  Boat_location boat;
} Status;

typedef struct StackStatus_ {
  int count;
  int capacity;
  int peek;
  Status *stack;
} StackStatus;

// 标准化动作
typedef enum Action_ {
  ONE_MONK_GO,
  ONE_MONSTER_GO,
  ONE_MONSTER_ONE_MONK_GO,
  TWO_MONK_GO,
  TWO_MONSTER_GO,
  ONE_MONK_BACK,
  ONE_MONSTER_BACK,
  ONE_MONSTER_ONE_MONK_BACK,
  TWO_MONK_BACK,
  TWO_MONSTER_BACK,
} Action;

typedef struct StackAction_ {
  int count;
  int capacity;
  int peek;
  Action *stack;
} StackAction;

typedef struct ActionEffect_ {
  Action action;
  Boat_location boatLocation;
  int monster;
  int monk;
} ActionEffect;

#define CAPACITY(capcity) ((capcity == 0) ? 8 : 2 * (capcity))

#endif
