/*
 * tamagotchi.h
 *
 * Created: 29/03/2018 10:42:25
 *  Author: Maarten

 */


#ifndef TAMAGOTCHI_H_
#define TAMAGOTCHI_H_

void tamagotchi_init(void);
void tamagotchi_feed(void);
void tamagotchi_play(void);
void tamagotchi_medicin(void);
void tamagotchi_clean(void);
void tamagotchi_update(void);

int tamagotchi_getHealth(void);
int tamagotchi_getHappynes(void);
int tamagotchi_getHunger(void);

#endif /* TAMAGOTCHI_H_ */