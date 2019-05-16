#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

class Fiszka{
public:
    int wartosc;
    string angielski;
    string polski;
    Fiszka()
    {
     wartosc = 0;
    }

};

int main(){
    srand(time(NULL));
    int g=0;
    vector<Fiszka> fiszki;
    vector<Fiszka> znane;
    short wyborek;
    short wybor;
    short jezyk;
    int losowa;
    string txt_ang;
    string txt_pol;
    fstream plik;
    znane.clear();
    do{
        cout << "Dodajemy fiszki [0]" << endl << "Wyswietlamy liste fiszek [1]" << endl << "Przepytujemy [2]" << endl << "Zczytujemy slowka z pliku[3]" << endl;
        cin >> wybor;
        if(wybor==0)
        {
            plik.open("slowka.txt",ios::out | ios::in | ios::app);
            do{
            fiszki.push_back(Fiszka());
            cout <<"Dodajemy fiszke numer " << fiszki.size() << endl << "Podaj slowko w jezyku polskim: ";
            cin >> fiszki[fiszki.size()-1].polski;
            plik << fiszki[fiszki.size()-1].polski<<" ";
            cout << "Podaj slowka w jezyku angielskim: ";
            cin >> fiszki[fiszki.size()-1].angielski;
            plik << fiszki[fiszki.size()-1].angielski<<endl;
            cout << "Dodajemy kolejna fiszke [0]" << endl << "Wychodzimy do menu[1]" << endl;
            cin >> wyborek;
            if(wyborek == 1){
                plik.close();
                break;}
            }while(true);
        }else if(wybor==1)
        {
                plik.open("slowka.txt");
                if(plik.peek() != '\0'){
                cout << "Wyswietlam fiszki" << endl << "Polski" << "    " << "Angielski" << endl;
                while(plik >> txt_pol >> txt_ang)
                {
                    cout<< txt_pol << "    " << txt_ang << '\n';
                }
                plik.close();

            }
        }else if(wybor==2)
        {
            int p = 0;
            string odp;
            cout << "Zanim zaczniemy podaj styl przepytywania." << endl << "Wyswietlanie slowka po angielsku[0]" << endl<< "Wyswietlanie slowka po polsku[1]" << endl;
            cin >> jezyk;
            if(jezyk==0)
            {
                do{
                    for(int i=0;i<fiszki.size();i++){
                        if(i%4==0 && znane.size()!=g){
                        cout << znane[g].angielski << "    ";
                        cin >> odp;
                        if(odp==znane[g].polski)
                        {
                            znane[g].wartosc++;
                            cout << "dobrze!" << endl;
                            g++;
                        }else{
                        cout << "zle!" << endl;
                        }
                        }
                        cout << fiszki[i].angielski << "    ";
                        cin >> odp;
                        if(odp==fiszki[i].polski)
                        {
                            fiszki[i].wartosc++;
                            cout << "dobrze!" << endl;
                            if(fiszki[i].wartosc==3){
                                znane.push_back(fiszki[i]);
                                fiszki.erase(fiszki.begin()+i);
                            }
                        }else{
                        cout << "zle!" << endl;
                        }
                    }
                }while(fiszki.size()!=0);
                cout << "Gratulacje, poznales wszystkie slowka!" << endl;
            }
            if(jezyk==1)
            {
                 do{
                    for(int i=0;i<fiszki.size();i++){
                        if(i%4==0 && znane.size()!=g){
                        cout << znane[g].polski << "    ";
                        cin >> odp;
                        if(odp==znane[g].angielski)
                        {
                            znane[g].wartosc++;
                            cout << "dobrze!" << endl;
                            g++;
                        }else{
                        cout << "zle!" << endl;
                        }
                        }
                        cout << fiszki[i].polski << "    ";
                        cin >> odp;
                        if(odp==fiszki[i].angielski)
                        {
                            fiszki[i].wartosc++;
                            cout << "dobrze!" << endl;
                            if(fiszki[i].wartosc==3){
                                znane.push_back(fiszki[i]);
                                fiszki.erase(fiszki.begin()+i);
                            }
                        }else{
                        cout << "zle!" << endl;
                        }
                    }
                }while(fiszki.size()!=0);
                cout << "Gratulacje, poznales wszystkie slowka!" << endl;
            }
        }
        else if(wybor==3){
            plik.open("slowka.txt",ios::in);
            if(plik.good()==false){
                cout<<"Plik nie istnieje!";
                break;
            }
            while(plik.eof() == false){
            fiszki.push_back(Fiszka());
            plik >> fiszki[fiszki.size()-1].polski;
            plik >> fiszki[fiszki.size()-1].angielski;
            }
        }
    }while(true);
    fiszki.push_back(Fiszka());
    cin.get();
    cin.get();
}
