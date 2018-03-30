/*
 * tamagotchi.c
 *
 * Created: 29/03/2018 10:09:16
 *  Author: Maarten
 */ 

 #include "Images.h"
 #include "GLCD.h"
 #include "tamagotchi.h"
 #include <stdlib.h>

 #define tamagotchi_maxhealth 30
 #define tamagotchi_maxhappynes 30
 #define tamagotchi_maxHunger 30

 
 int health;
 int happynes;
 int hunger;

 int isDirty;
 int isSleeping;
 int isSick;

  int amountTimesUpdated;


 #define maxStateNumber 2
 int stateCode; //0 = egg //1 is smallbird //2 is bigbird //3

  static void drawState(void){
	  GLCD_CLR();
	  GLCD_DisplayImage(buttondisplay);
	  switch(stateCode){
		  case 0:
		  GLCD_DisplayImage(egg);
		  break;
		  case 1:
		  GLCD_DisplayImage(smallbird);
		  break;
		  case 2:
		  GLCD_DisplayImage(biggbird);
		  case 3:
		  GLCD_CLR();
		  GLCD_DisplayImage(death);
		  break;
	  }
  }

  static void updateStatusDraw(void){
	  GLCD_CLR();
	  drawState();
	  if(isSick){
		  GLCD_DisplayImage(sick);
	  }
	  if(isDirty){
		  GLCD_DisplayImage(poop);
	  }
	  if(isSleeping){
		  GLCD_DisplayImage(sleeping);
	  }
  }

 void tamagotchi_init(){
	health = 15;
	happynes = 15;
	hunger = 15;
	isDirty = 0;
	isSleeping = 0;
	isSick =0;
	stateCode = 0;
	amountTimesUpdated = 0;
	drawState();
 }

 int tamagotchi_getHealth(){ return health;}
 int tamagotchi_getHappynes(){ return happynes;}
 int tamagotchi_getHunger() { return hunger;}

 void tamagotchi_feed(){
 	if(stateCode == 3) return;
	if(hunger < 30){
		hunger += 5;
		if(hunger > 30){
			hunger = 30;
		}
	}else {
		health -=3;
		if(health < 0){
			health = 0;
		}
	}
 }

 void tamagotchi_play(){
 	if(stateCode == 3) return;
	if(happynes >= 30){
		happynes -= 5;
	}else {
		happynes += 3;
		if(happynes > 30){
			happynes = 30;
		}
	}
 }

 void tamagotchi_medicin(){
 	if(stateCode == 3) return;
	if(isSick){
		health++;
		if(health > 30){
			health = 30;
		}
		isSick = 0;
		updateStatusDraw();
	}else {
		happynes-= 3;
		health -=3;
		if(health < 0){
			health = 0;
		}
		if(happynes < 0){
			happynes = 0;
		}
	}
 }

 void tamagotchi_clean(){
	if(stateCode == 3){
		tamagotchi_init();
		return;
	}
	if(isDirty){
		isDirty = 0;
		happynes += 3;
		updateStatusDraw();
		if(happynes > 30) happynes = 30;
	}else {
		happynes -= 3;
		if(happynes < 0) happynes =0;
	}
 }

 void tamagotchi_update(){
	if(stateCode == 3) return;
 	amountTimesUpdated++;
	if(amountTimesUpdated % 10 == 0 || amountTimesUpdated == 1){
		stateCode++;
		updateStatusDraw();
	}

	if(isDirty) {
		happynes -= 5;
		if(happynes < 0) happynes = 0;
	}

	if(happynes < 10){
		health -= 5;
		if(health < 0) health =0;
	}else if(happynes < 15) {
		health -= 3;
		if(health < 0) health =0;
	}else if(happynes > 20){
		health += 3;
		if(health > 30) health = 30;
	}

	if(hunger < 10){
		health -= 5;
		if(health < 0) health = 0;
	}else if(hunger < 15) {
		health -= 3;
		if(health < 0) health = 0;
	}else if(hunger > 20){
		health += 3;
		if(health > 30) health = 30;
	}
	hunger -= 5;
	if(hunger < 0) hunger = 0;

	happynes -= 5;
	if(happynes < 0) happynes = 0;

	if(isSick){
		health -= 10;
		if(health < 0) health = 0;
	}

	if(health == 0){
		stateCode = 3;
		drawState();
	}else {
		int randSick = rand() % 10;
		if(randSick == 0){
			isSick = 1;
			updateStatusDraw();
		}
		int randDirty = rand() % 10;
		if(randDirty == 0){
			isDirty = 1;
			updateStatusDraw();
		}

		int randSleep = rand() % 10;
		if(randSleep == 1){
			isSleeping = 1;
			updateStatusDraw();
		}else if(randSleep > 4 && isSleeping){
			isSleeping = 0;
			updateStatusDraw();
		}
	}
 }



