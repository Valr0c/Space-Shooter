#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int score = 0, jumlah_e = 0, jumlah_l = 0;
    int px = 2, py = 9;
    int lx1 = -1, ly1 = -1;
    int lx2 = -1, ly2 = -1;
    int lx3 = -1, ly3 = -1;
    int ex1 = rand() % 4 + 2, ey1 = 2, ex2, ey2, ex3, ey3;
    bool e1 = 1, e2 = 0, e3 = 0;
    bool l1 = 0, l2 = 0, l3 = 0;
    bool status = true;
    char input;
    do{
        cout << "Space Shooter" << endl;
        cout << "Score: " << score << endl;
        for(int i = 1; i <= 10; i++){
            for(int j = 1; j <= 6; j++){
                if(i == py && j == px){
                    cout << "^ ";
                }else if(i == ey1 && j == ex1 && e1 || i == ey2 && j == ex2 && e2 || i == ey3 && j == ex3 && e3){
                    cout << "E ";
                }else if(i == ly1 && j == lx1 && l1 || i == ly2 && j == lx2 && l2 || i == ly3 && j == lx3 && l3){
                    cout << "| ";
                }else if(i == 1 || i == 10 || j == 1 || j == 6){
                    cout << "* ";
                }else{
                    cout << "  ";
                }
            }
            cout << endl;
        }
        cout << ">> "; cin >> input;
        cout << endl;

        if(input == 'a'){
            if(px != 2){px--;}
            if(e1){ey1++;}
            if(e2){ey2++;}
            if(e3){ey3++;}
            if(l1){ly1--;}
            if(l2){ly2--;}
            if(l3){ly3--;}
        }else if(input == 'd'){
            if(px != 5){px++;}
            if(e1){ey1++;}
            if(e2){ey2++;}
            if(e3){ey3++;}
            if(l1){ly1--;}
            if(l2){ly2--;}
            if(l3){ly3--;}
        }else if(input == 's'){
            if(e1){ey1++;}
            if(e2){ey2++;}
            if(e3){ey3++;}
            if(l1){ly1--;}
            if(l2){ly2--;}
            if(l3){ly3--;}
        }else if(input == 'w'){
            if(jumlah_l < 3 && !l1){
                lx1 = px;
                ly1 = py;
                l1 = 1;
                jumlah_l++;
            }else if(jumlah_l < 3 && !l2){
                lx2 = px;
                ly2 = py;
                l2 = 1;
                jumlah_l++;
            }else if(jumlah_l < 3 && !l3){
                lx3 = px;
                ly3 = py;
                l3 = 1;
                jumlah_l++;
            }
            if(e1){ey1++;}
            if(e2){ey2++;}
            if(e3){ey3++;}
            if(l1){ly1--;}
            if(l2){ly2--;}
            if(l3){ly3--;}
        }

        if((ey1 == py && ex1 == px) || (ey2 == py && ex2 == px) || (ey3 == py && ex3 == px)){
            status = false;
        }else{
            if(ey1 == 10){
                e1 = 0;
                jumlah_e--;
            }
            if(ey2 == 10){
                e2 = 0;
                jumlah_e--;
            }
            if(ey3 == 10){
                e3 = 0;
                jumlah_e--;
            }
        }

        if(ex1 == lx1 && (ey1 == ly1 || ey1-1 == ly1)){
                e1 = 0;
                jumlah_e--;
                ly1 = 1;
                score += 10;
        }else if(ex1 == lx2 && (ey1 == ly2 || ey1-1 == ly2)){
                e1 = 0;
                jumlah_e--;
                ly2 = 1;
                score += 10;
        }else if(ex1 == lx3 && (ey1 == ly3 || ey1-1 == ly3)){
                e1 = 0;
                jumlah_e--;
                ly3 = 1;
                score += 10;
        }
        if(ex2 == lx1 && (ey2 == ly1 || ey2-1 == ly1)){
                e2 = 0;
                jumlah_e--;
                ly1 = 1;
                score += 10;
        }else if(ex2 == lx2 && (ey2 == ly2 || ey2-1 == ly2)){
                e2 = 0;
                jumlah_e--;
                ly2 = 1;
                score += 10;
        }else if(ex2 == lx3 && (ey2 == ly3 || ey2-1 == ly3)){
                e2 = 0;
                jumlah_e--;
                ly3 = 1;
                score += 10;
        }
        if(ex3 == lx1 && (ey3 == ly1 || ey3-1 == ly1)){
                e3 = 0;
                jumlah_e--;
                ly1 = 1;
                score += 10;
        }else if(ex3 == lx2 && (ey3 == ly2 || ey3-1 == ly2)){
                e3 = 0;
                jumlah_e--;
                ly2 = 1;
                score += 10;
        }else if(ex3 == lx3 && (ey3 == ly3 || ey3-1 == ly3)){
                e3 = 0;
                jumlah_e--;
                ly3 = 1;
                score += 10;
        }

        if(jumlah_e < 3){
            if(!e1){
                ex1 = rand() % 4 + 2;
                ey1 = 2;
                e1 = 1;
                jumlah_e++;
            }else if(!e2){
                ex2 = rand() % 4 + 2;
                ey2 = 2;
                e2 = 1;
                jumlah_e++;
            }else if(!e3){
                ex3 = rand() % 4 + 2;
                ey3 = 2;
                e3 = 1;
                jumlah_e++;
            }
        }

        if(ly1 == 1){
            lx1 = -1;
            ly1 = -1;
            l1 = 0;
            jumlah_l--;
        }
        if(ly2 == 1){
            lx2 = -1;
            ly2 = -1;
            l2 = 0;
            jumlah_l--;
        }
        if(ly3 == 1){
            lx3 = -1;
            ly3 = -1;
            l3 = 0;
            jumlah_l--;
        }

    }while(status);
    cout << "Game Over! Your score is " << score << endl;
    return 0;
}
