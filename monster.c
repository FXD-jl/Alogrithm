#include "monster.h"
#include <memory.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void initStatusStack(StackStatus *stackStatus) {
  stackStatus->peek = 0;
  stackStatus->count = 0;
  stackStatus->capacity = 0;
  stackStatus->stack = NULL;
}

void pushStatus(StackStatus *stackStatus, Status *status) {
  if (stackStatus->count + 1 >= stackStatus->capacity) {
    stackStatus->capacity = CAPACITY(stackStatus->capacity);
    stackStatus->stack = (Status *)realloc(
        stackStatus->stack, stackStatus->capacity * sizeof(Status));
    if (stackStatus->stack == NULL) {
      printf("StackStatus Memory allocation error\n");
      exit(1);
    }
  }
  memcpy(&stackStatus->stack[stackStatus->peek], status, sizeof(Status));
  stackStatus->count++;
  stackStatus->peek++;
}

Status popStatus(StackStatus *stackStatus) {
  if (stackStatus->count == 0) {
    printf("StackStatus pop error\n");
    exit(1);
  }
  stackStatus->count--;
  stackStatus->peek--;
  // 无需free因为通过栈的增减自然会占据内存，最后统一释放
  return stackStatus->stack[stackStatus->peek];
}

void freeStatusStack(StackStatus *stackStatus) {
  free(stackStatus->stack);
  initStatusStack(stackStatus);
}
void initActionStack(StackAction *stackAction) {
  stackAction->peek = 0;
  stackAction->count = 0;
  stackAction->capacity = 0;
  stackAction->stack = NULL;
}

void pushAction(StackAction *stackAction, Action action) {
  if (stackAction->count + 1 >= stackAction->capacity) {
    stackAction->capacity = CAPACITY(stackAction->capacity);
    stackAction->stack = (Action *)realloc(
        stackAction->stack, stackAction->capacity * sizeof(Action));
    if (stackAction->stack == NULL) {
      printf("StackAction Memory allocation error\n");
      exit(1);
    }
  }
  stackAction->stack[stackAction->peek] = action;
  stackAction->count++;
  stackAction->peek++;
}

Action popAction(StackAction *stackAction) {
  if (stackAction->count == 0) {
    printf("StackAction pop error\n");
    exit(1);
  }
  stackAction->count--;
  stackAction->peek--;
  // 无需free因为通过栈的增减自然会占据内存，最后统一释放
  return stackAction->stack[stackAction->peek];
}

void freeActionStack(StackAction *stackAction) {
  free(stackAction->stack);
  initActionStack(stackAction);
}

bool detectSite(Status *status, Boat_location boat_location) {
  // 排除不在本地出发的情况
  if (status->boat != boat_location) {
    return false;
  }
  return true;
}

bool detectStatus(Status *status) {
  // 排除不能出现的状态,并将该产生的新状态释放
  if (status->local_monk != 0) {
    if (status->local_monster > status->local_monk)
      return false;
  }
  if (status->remote_monk != 0) {
    if (status->remote_monster > status->remote_monk)
      return false;
  }
  // 不能为负值
  if (status->local_monster < 0 || status->remote_monster < 0 ||
      status->local_monk < 0 || status->remote_monk < 0) {
    return false;
  }

  return true;
}

bool isStatusEqual(Status *status1, Status *status2) {
  if (status1->local_monk == status2->local_monk &&
      status1->local_monster == status2->local_monster &&
      status1->boat == status2->boat)
    return true;
  return false;
}

char *getString(Action action) {
  char *s[] = {
      "ONE_MONK_GO",
      "ONE_MONSTER_GO",
      "ONE_MONSTER_ONE_MONK_GO",
      "TWO_MONK_GO",
      "TWO_MONSTER_GO",
      "ONE_MONK_BACK",
      "ONE_MONSTER_BACK",
      "ONE_MONSTER_ONE_MONK_BACK",
      "TWO_MONK_BACK",
      "TWO_MONSTER_BACK",
  };
  return s[action];
}

bool isRepeated(StackStatus *stackStatus, Status *newStatus) {
  // 获取栈顶元素
  for (int i = 0; i < stackStatus->peek - 1; i++) {
    if (isStatusEqual(&stackStatus->stack[i], newStatus)) {
      return true;
    }
  }
  return false;
}

void reslove(StackStatus *stackStatus, StackAction *stackAction,
             int action_effect[10][4], Status *endStatus) {
  // 设置递归的终止条件
  if (stackStatus->count == 0) {
    return;
  }
  // 第一步获取此时的状态
  Status status = stackStatus->stack[stackStatus->peek - 1];
  // 记录
  // 第二部开始往树的深处前进,由于有10种可能得路径所以
  for (int i = 0; i < 10; i++) {
    // 获取动作的影响
    ActionEffect actionEffect;
    actionEffect.action = action_effect[i][0];
    actionEffect.boatLocation = action_effect[i][1];
    actionEffect.monster = action_effect[i][2];
    actionEffect.monk = action_effect[i][3];

    // 先剔除船位与当前状态不对的可能
    if (!detectSite(&status, actionEffect.boatLocation)) {
      continue;
    }
    // 创建在该状态影响下的新状态
    Status newStatus;
    newStatus.boat = (status.boat + 1) % 2;
    newStatus.local_monk = status.local_monk + actionEffect.monk;
    newStatus.local_monster = status.local_monster + actionEffect.monster;
    newStatus.remote_monk = status.remote_monk - actionEffect.monk;
    newStatus.remote_monster = status.remote_monster - actionEffect.monster;
    if (!detectStatus(&newStatus)) {
      continue;
    }
    // 检查该状态是否达到终止态
    if (isStatusEqual(&newStatus, endStatus)) {
      // 打印路径
      for (int i = 0; i < stackAction->count; i++) {
        printf("%s->\n", getString(stackAction->stack[i]));
      }
      printf("____________\n");
      // 已经找到路径其他的可能无需再试，跳出循环
      break;
    }
    // 检查是否有路径重复
    if (isRepeated(stackStatus, &newStatus)) {
      continue;
    }
    // 该路径可行，则继续深入并记录该行动
    pushStatus(stackStatus, &newStatus);
    pushAction(stackAction, actionEffect.action);
    reslove(stackStatus, stackAction, action_effect, endStatus);
  }

  // 若每一种行动都无可能，说明该节点无意义，从栈中弹出继续回溯
  // 或者已经找到最终状态，从栈中弹出继续回溯
  popStatus(stackStatus);
  if (stackStatus->count == 0)
    return;
  popAction(stackAction);
}

int main(void) {
  // Local是检查函数用于筛选的条件之一。
  int action_effect[10][4] = {
      {ONE_MONK_GO, LOCAL, 0, -1},
      {ONE_MONSTER_GO, LOCAL, -1, 0},
      {ONE_MONSTER_ONE_MONK_GO, LOCAL, -1, -1},
      {TWO_MONK_GO, LOCAL, 0, -2},
      {TWO_MONSTER_GO, LOCAL, -2, 0},
      {ONE_MONK_BACK, REMOTE, 0, 1},
      {ONE_MONSTER_BACK, REMOTE, 1, 0},
      {ONE_MONSTER_ONE_MONK_BACK, REMOTE, 1, 1},
      {TWO_MONK_BACK, REMOTE, 0, 2},
      {TWO_MONSTER_BACK, REMOTE, 2, 0},
  };

  // 初始化问题
  Status init = {3, 3, 0, 0, LOCAL};
  Status endStatus = {0, 0, 3, 3, REMOTE};
  StackStatus stackStatus;
  StackStatus recordStackStatus;
  StackAction stackAction;
  initStatusStack(&stackStatus);
  initActionStack(&stackAction);

  pushStatus(&stackStatus, &init);
  reslove(&stackStatus, &stackAction, action_effect, &endStatus);
  freeActionStack(&stackAction);
  freeStatusStack(&stackStatus);

  return 0;
}
