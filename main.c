#include <stdio.h>

int main(void) {
	double minWid = 0, minLen = 0, tileIn = 0, jointIn = 0;
  int tile[128] = {0}, joint[128] = {0};
  long long int realLen = 0, realWid = 0, lastLen = 0, lastWid = 0;
  int count = 1, lastGCD = 1, GCD = 1;
  int test = 0;

  printf("Minimalni velikost:\n");
  if(scanf("%lf %lf", &minWid, &minLen) != 2
  || minWid == 0
  || minLen == 0
  || minWid > 10000000
  || minLen > 10000000
  || (minWid*10) - (int)(minWid*10) != 0
  || (minLen*10) - (int)(minLen*10) != 0
  ){
		printf("Nespravny vstup.\n");
		return 0;
	}
  minWid *= 10;
  minLen *= 10;

  printf("Dlazdicky:\n");

  while (getchar() != EOF){


    if((scanf("%lf %lf", &tileIn, &jointIn) != 2 && tileIn != 0)
    || tileIn <= 0
    || jointIn < 0
    || tileIn > 10000000
    || jointIn > 10000000
    || (tileIn*10) - (int)(tileIn*10) != 0
    || (jointIn*10) - (int)(jointIn*10) != 0
    ){
      if (getchar() != EOF || count == 1){
        printf("Nespravny vstup.\n");
        return 0;
      }

  	}else{
      tile[count] = 10*tileIn;
      joint[count] = 10*jointIn;
      realWid = tile[count]+joint[count]+joint[count];
      realLen = tile[count]+joint[count]+joint[count];
      if (count == 1){
        lastWid = realWid;
        lastLen = realLen;
        lastGCD = tile[count] + joint[count];
      }
      else{
        for (int i = 1; i <= count; ++i){
          GCD = tile[count] + joint[count];
          lastGCD = tile[i] + joint[i];
          while (GCD != lastGCD){
            if (GCD > lastGCD)
              GCD -= lastGCD;
            else
              lastGCD -= GCD;
          }
          if ((joint[count]-joint[i]) % GCD){
            printf("Reseni neexistuje.\n");
            return 0;
          }
        }
      }

      while (lastWid % (tile[count]+joint[count]) != joint[count] || minWid > lastWid){
        if (count == 1){
          realWid += tile[count]+joint[count];
          lastWid = realWid;
        }
        else{
          for (int i = 1; i <= count; ++i){
            if (realWid % (tile[i]+joint[i]) != joint[i] || lastWid > realWid){
              ++test;
            }

          }
          if (test > 0){
            realWid += tile[count]+joint[count];
            test = 0;
          }
          else
            lastWid = realWid;
        }
      }

      while (lastLen % (tile[count]+joint[count]) != joint[count] || minLen > lastLen){
        if (count == 1){
          realLen += tile[count]+joint[count];
          lastLen = realLen;
        }
        else{
          for (int i = 1; i <= count; ++i){
            if (realLen % (tile[i]+joint[i]) != joint[i] || lastLen > realLen){
              ++test;
            }
          }
          if (test > 0){

            realLen += tile[count]+joint[count];
            test = 0;
          }
          else
            lastLen = realLen;
        }
      }
      ++count;
    }


  }
  printf("Velikost: %.1f x %.1f\n", lastWid*0.1, lastLen*0.1 );

	return 0;
}
