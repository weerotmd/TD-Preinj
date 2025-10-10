#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

float randFloat(float min, float max, int seed){
  srand(time(NULL) + seed);
  int modulo = ((max-min)*100);
  int randInt = rand()%modulo;
  float randf = randInt;
  randf/=100;
  randf += min;
  return randf;
}

typedef struct {
  float atk;
  float def;
  float dodge;
  float hp;
  char *name;
} Ninja;
Ninja newNinja(float atk, float def, float dodge, float hp, char name[]){
  Ninja n;
  n.atk = atk;
  n.def = def;
  n.dodge = dodge;
  n.hp = hp;
  int i = 0;
  n.name = name;
  //printf("%s - %s\n", name, n.name);
  return n;
}
int combat(Ninja a, Ninja b){
  int turn = 0;
  while (a.hp > 0 && b.hp > 0) {
    Ninja attacker;
    Ninja defender;
    if (turn%2 == 1) {
      attacker = newNinja(a.atk, a.def, a.dodge, a.hp, a.name);
      defender = newNinja(b.atk, b.def, b.dodge, b.hp, b.name);
    } else {
      defender = newNinja(a.atk, a.def, a.dodge, a.hp, a.name);
      attacker = newNinja(b.atk, b.def, b.dodge, b.hp, b.name);
    }
    printf("Start of turn %d:\n", turn);
    printf("%s %f hp - %s %f hp\n", a.name, a.hp, b.name, b.hp);
    //float value = randFloat(0.0, 1.0, turn);
    //printf("%f - %f\n", value, defender.dodge);
    if (randFloat(0.0, 1.0, turn) > defender.dodge) {
      float damage = (attacker.atk-defender.def);
      if (damage < 0) damage = 0;
      defender.hp -= (attacker.atk-defender.def);
      printf("%s deals %f damage to %s\n", attacker.name, damage, defender.name);
    } else {
      printf("%s dodged %s's attack\n", defender.name, attacker.name);
    }
    if (turn%2 == 1) {
      a = newNinja(attacker.atk, attacker.def, attacker.dodge, attacker.hp, attacker.name);
      b = newNinja(defender.atk, defender.def, defender.dodge, defender.hp, defender.name);
    } else {
      b = newNinja(attacker.atk, attacker.def, attacker.dodge, attacker.hp, attacker.name);
      a = newNinja(defender.atk, defender.def, defender.dodge, defender.hp, defender.name);
    }
    turn += 1;
    /*if (turn > 10) {
      return;
    }*/
  }
  if (a.hp < 0) {
    return 1;
  } else {
    return 0;
  }
}
void bo5(Ninja a, Ninja b) {
  int ascore = 0;
  int bscore = 0;
  while (ascore < 3 && bscore < 3) {
    if (combat(a, b) == 0) {
      printf("%s wins a round score: a: %d - b: %d\n", a.name, ascore, bscore);
      ascore += 1;
    } else {
      printf("%s wins a round\n", b.name);
      bscore += 1;
    }
  }
  if (ascore >= 3) {
    printf("%s wins!!! score: a: %d - b: %d\n", a.name, ascore, bscore);
  } else {
    printf("%s wins!!! score: a: %d - b: %d\n", b.name, ascore, bscore);
  }
}

int main() {
  Ninja michael = newNinja(randFloat(5.0, 10.0, 1), randFloat(2.0, 4.0, 1), randFloat(0.1, 0.2, 1), randFloat(80.0, 100.0, 1), "emir");
  Ninja amorim = newNinja(randFloat(5.0, 10.0, 1), randFloat(2.0, 4.0, 1), randFloat(0.1, 0.2, 1), randFloat(80.0, 100.0, 1), "javascript");
  bo5(michael, amorim);
  //printf("%f\n", randFloat(0.1, 0.2));
  return 0;
}
