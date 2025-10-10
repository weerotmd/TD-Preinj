#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>


typedef struct {
  char *lastName;
  char *firstName;
  int nb;
  float *notes;
} Etudiant;

Etudiant newEtudiant(char lastName, char firstName, int nb) {
  Etudiant a;
  a.lastName = lastName;
  a.firstName = firstName;
  a.nb = nb;
  srand(time(NULL)+nb);
  int nbNotes = rand()%12;
  a.notes = malloc((nbNotes+1)*sizeof(float*));
  for (size_t i = 0; i < nbNotes; i++) {
    srand(time(NULL)+i);
    *(a.notes + i) = rand()%20;
  }
  *(a.notes + nbNotes+1) = -1;
  return a;
}
void displayEtudiant(Etudiant a) {
  printf("WORKS\n");
  printf("Nom: %s | Prenom: %s | Numero: %d | Notes: ", a.lastName, a.firstName, a.nb);
  int i = 0;
  while (*(a.notes + i) != -1) {
    printf("%f", *(a.notes + i));
    if (*(a.notes + i+1) != -1) {
      printf(", ");
    }
    i++;
  }
  printf("\n");
}
float average(Etudiant groupe[], int nbEtudiants) {
  int nbNotes = 0;
  float average = 0;
  for (size_t i = 0; i < nbEtudiants; i++) {
    int j = 0;
    while (*(*(groupe+i)).notes + j) != -1) {
      nbNotes++;
      average += *(*(groupe+i)).notes + j);
      j++;
    }
  }
}

int main(int argc, char const *argv[]) {
  Etudiant a = newEtudiant("Jedusor", "Tom", 7236990);
  Etudiant b = newEtudiant("Potter", "Harry", 8888888);
  Etudiant c = newEtudiant("Granger", "Hermione", 4444444);
  Etudiant d = newEtudiant("Lucius", "Malfoy", 33333333);
  int nbEtudiants = 4;
  Etudiant groupe[nbEtudiants] = {a, b, c, d};
  float moyenne = average(groupe, nbEtudiants);
  displayEtudiant(tom);
  return 0;
}
