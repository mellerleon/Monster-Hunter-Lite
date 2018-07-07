#include "monsterbook.h"
#include "hunterbook.h"
#include "palicobook.h"
#include "monster.h"
#include "hunter.h"
#include "palico.h"
#include "item.h"
#include "bmplib.h"
#include <cmath>
#include <time.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <iterator>
#include <thread>
#include <functional>

using namespace std;

unsigned char image[SIZE][SIZE][RGB];


void draw_square(int top, int left, int R, int G, int B) {
  for(int i = top; i < top+32; i++){
    for(int j = left; j < left+32; j++){
      image[i][j][0] = R;
      image[i][j][1] = G;
      image[i][j][1] = B;
    }
  }
}

void draw_triangle(int leftx, int lefty,int R, int G, int B){
  for(int i = 0 ; i <32 ; i++){
    for(int j = 0; j <(32*i/32); j++){
      image[leftx+i][lefty + 32*(32-i)/32/2 + j][0] = R; 
      image[leftx+i][lefty + 32*(32-i)/32/2 + j][1] = G;
      image[leftx+i][lefty + 32*(32-i)/32/2 + j][2] = B; 
    }
  }
}

void draw_circle(int center_x, int center_y,int R, int G, int B){
   for (double theta=0.0; theta < 2*M_PI; theta += .01) {
    for(double r=0; r<16; r++){
      double x = r*cos(theta);
      double y = r*sin(theta);
      x += center_x;
      y += center_y;
      image[(int)y][(int)x][0] = R;
      image[(int)y][(int)x][1] = G;
      image[(int)y][(int)x][2] = B;
    }
   }
}

// hunter vs. monster thread function
void hunterMonster(hunter* hun,vector<monster*> mon,int& hunt,int& mons){
	for(int i=0;i<mon.size();i++){
		if(hun->h_x-16 == mon[i]->m_x && hun->h_y-16 == mon[i]->m_y){
			cout << "\nHunter " << hun->first_name << " has encountered " 
			<< mon[i]->first_name << endl;
			cin.ignore();
			cout<<"Commence the battle!"<<endl;
			cin.ignore();

			while(1){
				hun->attackMonster(mon[i]);
				cout << "\n" << hun->first_name << " attacked!" <<endl;
				if(mon[i]->m_hp >= 0){
					cout << "Monster's HP is now " << mon[i]->m_hp<<endl;
					cin.ignore();
				}
				else{
					cout << "Monster's HP is now 0";
					cin.ignore();
				}

				mon[i]->attackHunter(hun);
				cout << "\n"<<mon[i]->first_name << " attacked!" <<endl;
				if(hun->h_hp >= 0){
					cout << "Hunter's HP is now " << hun->h_hp<<endl;
					cin.ignore();
				}
				else{
					cout << "Hunters's HP is now 0";
					cin.ignore();
				}

				if(hun->checkDead()){
					cout << "\nHunter " << hun->first_name << " has been slain..."
					<< endl;
					cin.ignore();
					hunt++;	// counter for hunter death
					break;
				}
				else if(mon[i]->checkDead()){
					cout << "\nHunter " << hun->first_name << " slayed the monster!"
					<< endl;
					cin.ignore();
					mons++; // counter for monster death
					break;
				}
			}
		}
	}		
}

// palico vs. monster thread function
void palicoMonster(vector<palico*> pal,vector<monster*> mon, int& pali, int& mons){
	for(int i=0; i<pal.size(); i++){
		for(int j=0;j<mon.size();j++){
			if(pal[i]->p_x == mon[j]->m_x && pal[i]->p_y == mon[j]->m_y){
				cout << "\nPalico " << pal[i]->first_name << " has encountered " 
				<< mon[j]->first_name << endl;
				cin.ignore();
				cout<<"Commence the battle!"<<endl;
				cin.ignore();

				while(1){
					pal[i]->attackMonster(mon[j]);
					cout << pal[i]->first_name << " attacked!" <<endl;
					if(mon[j]->m_hp >= 0){
						cout << "Monster's HP is now " << mon[j]->m_hp<<endl;
						cin.ignore();
					}
					else{
						cout << "Monster's HP is now 0";
						cin.ignore();
					}
						
					mon[j]->attackPalico(pal[i]);
					cout << mon[j]->first_name << " attacked!" << endl;
					if(pal[i]->p_hp >= 0){
						cout << "Palico's HP is now " << pal[i]->p_hp<<endl;
						cin.ignore();
					}
					else{
						cout << "Palico's HP is now 0";
						cin.ignore();
					}
					
					if(pal[i]->checkDead()){
						cout << "\nPalico " << pal[i]->first_name << " has been slain..."
						<< endl;
						cin.ignore();
						pali++; // counter for palico death
						break;
					}
					else if(mon[j]->checkDead()){
						cout << "\nPalico " << pal[i]->first_name << " slayed the monster!"
						<< endl;
						cin.ignore();
						mons++; // counter for monster death
						break;
					}
				}
			}
		}
	}
}

// hunter encountering palico thread function
void hunterPalico(hunter* hun, vector<palico*> pal){
	string response;
	for(int i=0;i<pal.size();i++){
		if(hun->h_x-16 == pal[i]->p_x && hun->h_y-16 == pal[i]->p_y){
		cout << "\nHunter " << hun->first_name << " has encountered " 
		"Palico " << pal[i]->first_name << endl;
		cin.ignore();

		cout << "Would you like " << pal[i]->first_name << " to heal Hunter "
		<< hun->first_name << "? (y/n): ";
		cin >> response;
			if(response == "y"){
				pal[i]->cure(hun);
				cout << pal[i]->first_name << " cured Hunter " << hun->first_name<<endl;
				cout << "Hunter's HP is now " << hun->h_hp << endl;
				cin.ignore();
			}
			else if(response == "n"){
				cout << pal[i]->first_name << " just stared at the Hunter..." << endl;
				cin.ignore();
			}			
		}
			
	}
}


int main(){

	srand(time(NULL));

	sword *s = new sword;
	equipment *e = new equipment;
	hunterbook *h = new hunterbook;
	monsterbook *m = new monsterbook;
	palicobook *p = new palicobook;
	vector<hunter*> hun;
	vector<monster*> mon;
	vector<palico*> pal;

	// double pointer iterator (dereference the iterator when usuig it i.e. *(iterator)-> )
	vector<hunter*> :: iterator hunt;
	vector<monster*> :: iterator mons;
	vector<palico*> :: iterator pali;

	// counter for hunter, monster, and palico
	int x = 0;
	int y = 0; 
	int z = 0;

	// monster names
	string m_f_name [] = {"Rathalos","Rathian","Kirin","Kushala Daora","Fatalis"
						  ,"UKalos", "Talonis", "Chamaleonis","Usugi","Dalamadur"};
	string m_l_name[] = {"King","Queen","Adult","Juvenile","Hatchiling"};

	// palico names
	string p_f_name [] = {"Kitty","Kush","Doki","Meowth","Violet"};
	string p_l_name[] = {"Paw","420","Doki","Poke","Evergarden"};

	// gender & age for monsters and palicos
	string sex[] = {"Male","Female","Non-binary"};
	int num[] = {18,23,45,77,100};


	// intro welcome!
	cout << "\nPress Enter to proceed with the game";
	cin.ignore();
	cout << "\nWelcome to the world of Monster Hunter!";
	cin.ignore();
	cout << "Let's get the hunt started";
	cin.ignore();


// Initalizing Hunters' stats and adding to the hunterbook
	int j=3;
	for(int i=0; i<3; i++){
		hun.push_back(new hunter(100,100,12,2,s->sword_name[j],
					  s->attack[j],e->equip_name[i],e->defense[i]));
		h->add(hun[i]);
		cout << endl;
		j+=3;
	}


	// initializing monsters' stats and adding to the monsterbook
	for(int i=0; i<10; i++){
		int j = rand()%5;
		int k = rand()%3;
		int l = rand()%5;
		mon.push_back(new monster(100,rand()%101,rand()%101, m_f_name[i],m_l_name[j],sex[k],num[l]));
		m->add(mon[i]); 
	}


	// initializing palicos; stats and adding to the palicobook
	for(int i=0; i<6; i++){
		int j = rand()%3;
		pal.push_back(new palico(50,3,p_f_name[i],p_l_name[i], sex[j], num[i]
						,s->sword_name[i],s->attack[i]));
		p->add(pal[i]);
	}


   // initialize the image to a grid
   for (int i=0; i < SIZE; i++) {
      for (int j=0; j < SIZE; j++) {
        if(i%32==0 || j%32==0)
          continue;
        for (int k=0; k < RGB; k++) {
         image[i][j][k] = 255;
         }
      }
   }

	// RGB set-up
	for(int i=0;i<3;i++){
		hun[i]->R = rand()%256;
		hun[i]->G = rand()%256;
		hun[i]->B = rand()%256;
	}

	for(int i=0;i<10;i++){
		mon[i]->R = rand()%256;
		mon[i]->G = rand()%256;
		mon[i]->B = rand()%256;
	}
	for(int i=0;i<5;i++){
		pal[i]->R = rand()%256;
		pal[i]->G = rand()%256;
		pal[i]->B = rand()%256;
	}


////////////////////////// Beginning of the game loop //////////////////////////////////

	int flag = 1;
	while(flag){
		
		// GUI may not update when any character is eliminated
		// hunter coordinate and shape set-up (circle)
		for(int i=0; i<hun.size(); i++){
			hun[i]->h_x = 16 + 32*(rand()%16);
			hun[i]->h_y = 16 + 32*(rand()%16);
			draw_circle(hun[i]->h_x,hun[i]->h_y,hun[i]->R,hun[i]->G,hun[i]->B);
		}

		// monster coordinate and shape set-up (triangle)
		for(int i=0; i<mon.size(); i++){
			mon[i]->m_x = 32*(rand()%16);
			mon[i]->m_y = 32*(rand()%16);
			draw_triangle(mon[i]->m_x,mon[i]->m_y,mon[i]->R,mon[i]->G,mon[i]->B);
		}

		// palico coordinate and shape set-up (square)
		for(int i=0; i<pal.size(); i++){
			pal[i]->p_x = 32*(rand()%16);
			pal[i]->p_y = 32*(rand()%16);
			draw_square(pal[i]->p_x,pal[i]->p_y,pal[i]->R,pal[i]->G,pal[i]->B);
		}

		
		/* Multi-threading section */

		// hunter vs. monster thread initialization and interaction commences
		thread hunter1VSmonster(hunterMonster,hun[0],mon,ref(x),ref(y));
		thread hunter2VSmonster(hunterMonster,hun[1],mon,ref(x),ref(y));
		thread hunter3VSmonster(hunterMonster,hun[2],mon,ref(x),ref(y));	

		// palico vs. monster
		thread palicoVSmonster(palicoMonster,pal,mon,ref(z),ref(y));

		// hunter meeting palico
		thread hunter1Meetpalico(hunterPalico,hun[0],pal);
		thread hunter2Meetpalico(hunterPalico,hun[1],pal);
		thread hunter3Meetpalico(hunterPalico,hun[2],pal);

		// enable a thread to finish executing while others finish. Without join functions, error occurs
		hunter1VSmonster.join();
		hunter2VSmonster.join();
		hunter3VSmonster.join();
		palicoVSmonster.join();
		hunter1Meetpalico.join();
		hunter2Meetpalico.join();
		hunter3Meetpalico.join();


		if(x>0){
			for(int i=0; i<x; i++){
				hun.erase(hun.begin()+i);
			}
		}
		if(y>0){
			for(int i=0;i<y;i++){
				mon.erase(mon.begin()+i);
			}
		}
		if(z>0){
			for(int i=0;i<y;i++){
				pal.erase(pal.begin()+i);
			}
		}

		// reset counter for hunter, monster, and palico
		x=0;
		y=0;
		z=0;

		cout << "\n# of hunters: " << hun.size() << endl;
		cout << "# of monsters: " << mon.size() << endl;
		cout << "# of palicos: " << pal.size() << endl;
		cout << endl;

		// displaying the GUI image
		showRGBBMP(image);
		// saving the GUI image
		writeRGBBMP("output.bmp", image);

		// save the remaining players
		h->save();
		m->save();
		p->save();

		// Prompting user to continue to next round if hunters are
		// alive or all monsters are dead
		if(hun.size()>0){
			
			cout << "Next round? (press 1 to continue and 0 to quit): ";
			cin >> flag;
		
			while(flag > 1 || flag<0){
				cout << "Enter correct choice: ";
				cin.clear();
				cin.ignore(100, '\n');
				cin >> flag;
			}

			// Refresh the image (set a clean 2D coordinate)
			for (int i=0; i < SIZE; i++){
		   		for (int j=0; j < SIZE; j++){
		        	for (int k=0; k < RGB; k++){
		         		image[i][j][k] = 255;
		         		if(i%32==0 || j%32==0){
		         			image[i][j][k] = 0;
		         		}
		         	}
		    	}
			}
		}

		// Game end condition when all monsters have been slayed
		else if(hun.size() > 0 && mon.size() == 0){
			cout << "\nAll Monsters have been hunted! " << endl;
			cin.ignore();
			cout << "Quest cleared!" << endl;
			cout << "Loading to the end screen........" << endl;
			cin.ignore();
		}

		// Game end condition when all hunters have been slayed
		else if(hun.size() == 0){
			cout << "\nAll Hunters are dead... GAME OVER." << endl;
			cin.ignore();
			cout << "Loading to the end screen........" << endl;
			cin.ignore();
			break;
		}
	}

	cout << "Great hunting sesh!" << endl;
	cin.ignore();
	cout << "\nWhether your hunt went well or not, we hope you comeback to play again!" << endl;
	cin.ignore();
	cout << "Until next time, Hunter!" << endl;
	cin.ignore();
	return 0;
}