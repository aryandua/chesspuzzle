#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <stdlib.h>

#define lrand() (long long)(rand())

void printBinary(uint64_t value) {
  for(int i=0;i<64;i++) {
    printf("%d", __builtin_popcountll(value & (1ULL << i)));
    if(i%8 == 7) printf("\n");
  }
}

uint64_t flipBoard(uint64_t board, uint64_t key) {
  uint64_t currBoard = 0;
  for(uint64_t i=0;i<64;i++) currBoard ^= __builtin_popcountll(((1ULL<<i)) & board) ? i : 0;
  printf("Flipping coin %llu\n\n\n\n", currBoard ^ key);
  return board ^ (1ULL << (currBoard ^ key));
}

uint64_t decodeBoard(uint64_t board) {
  uint64_t currBoard = 0;
  for(uint64_t i=0;i<64;i++) currBoard ^= __builtin_popcountll(((1ULL<<i)) & board) ? i : 0;
  return currBoard;
}

void pause() { char dummy; scanf("%c", &dummy); }

int main() {
  srand(time(NULL));
  uint64_t initialBoard = lrand()*lrand()*lrand()*lrand()*lrand();
  uint64_t key = rand() % 64;  
  
  printBinary(initialBoard);
  printf("\n\nKey = %llu\n\n\nPress enter to continue.\n\n\n", key);
  pause();
  
  uint64_t newBoard = flipBoard(initialBoard, key);
  
  if(__builtin_popcountll(newBoard ^ initialBoard) != 1) {
    printf("Must flip a coin\n");
    exit(1);
  }

  printBinary(newBoard);

  printf("Press enter to continue.\n");
  pause();
  
  uint64_t decodedKey = decodeBoard(newBoard);

  printf("Guessed Key = %llu\n\n\n", decodedKey);
  
  if(decodedKey == key) printf("Puzzle solved!\n");
  else printf("Puzzle failed!");

}
