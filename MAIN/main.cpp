#include <iostream>
#include <fstream>

using namespace std;

void wyswietl_wzorzec(int arr[2])
{
    string plik;
    switch (arr[0])
    {
        case 1:
            switch(arr[1])
            {
                case 1: //Metoda wytworcza
                    cout << "1. Metoda wytworcza\n" ;
                    plik="11.cpp";
                    break;
                case 2: //Fabryka abstrakcyjna
                    cout << "2. Fabryka abstrakcyjna\n" ;
                    plik="12.cpp";
                    break;
                case 3: //Budowniczy
                    cout << "3. Budowniczy\n" ;
                    plik="13.cpp";
                    break;
                case 4: //Prototyp
                    cout << "4. Prototyp\n" ;
                    plik="14.cpp";
                    break;
                case 5: //Singleton
                    cout << "5. Singleton\n" ;
                    plik="15.cpp";
                    break;
                default:
                    cout << "ERROR!";
                    break;
            }
            break;
        case 2:
            switch(arr[1])
            {
                case 1: //Adapter
                    cout << "1. Adapter\n" ;
                    plik="21.cpp";
                    break;
                case 2: //Most
                    cout << "2. Most\n" ;
                    plik="22.cpp";
                    break;
                case 3: //Kompozyt
                    cout << "3. Kompozyt\n" ;
                    plik="23.cpp";
                    break;
                case 4: //Dekorator
                    cout << "4. Dekorator\n" ;
                    plik="24.cpp";
                    break;
                case 5: //Fasada
                    cout << "5. Fasada\n" ;
                    plik="25.cpp";
                    break;
                case 6: //Pylek
                    cout << "6. Pylek\n" ;
                    plik="26.cpp";
                    break;
                case 7: //Pelnomocnik
                    cout << "7. Pelnomocnik\n\n" ;
                    plik="27.cpp";
                    break;
                default:
                    cout << "ERROR!";
                    break;
            }
            break;
        case 3:
            switch(arr[1])
            {
                case 1: //Lancuch zobowiazan
                    cout << "1. Lancuch zobowiazan\n" ;
                    plik="31.cpp";
                    break;
                case 2: //Polecenie
                    cout << "2. Polecenie\n" ;
                    plik="32.cpp";
                    break;
                case 3: //Iterator
                    cout << "3. Iterator\n" ;
                    plik="33.cpp";
                    break;
                case 4: //Mediator
                    cout << "4. Mediator\n" ;
                    plik="34.cpp";
                    break;
                case 5: //Pamiatka
                    cout << "5. Pamiatka\n" ;
                    plik="35.cpp";
                    break;
                case 6: //Obserwator
                    cout << "6. Obserwator\n" ;
                    plik="36.cpp";
                    break;
                case 7: //Stan
                    cout << "7. Stan\n" ;
                    plik="37.cpp";
                    break;
                case 8: //Strategia
                    cout << "8. Strategia\n" ;
                    plik="38.cpp";
                    break;
                case 9: //Metoda szablonowa
                    cout << "9. Metoda szablonowa\n" ;
                    plik="39.cpp";
                    break;
                case 10: //Odwiedzajacy
                    cout << "10. Odwiedzajacy\n\n" ;
                    plik="310.cpp";
                    break;
                default:
                    cout << "ERROR!";
                    break;
            }
            break;
        default:
            cout << "Error\n";
            break;
    }
    ifstream is(plik);     // open file
    char c;
    while (is.get(c))          // loop getting single characters
    cout << c;
    is.close();                // close file

    //fstream myfile(plik, ios_base::in);
    //cout << plik << endl;
    //Tutaj "fopen bedzie"
    //myfile.close();
}

int wybierz_wzorzec(int i, int arr[2]);
int wyswietl_tabele(int i, int j, int arr[2])
{
    cout << "Wybierz kategorie wzorcow projektowych:\n\n" ;
    cout << "1. Wzorce kreacyjne\n" ;
    cout << "   (zrodlo roznych mechanizmow tworzenia obiektow, zwiekszajacych elastycznosc i ulatwiajacych ponowne uzycie kodu)\n\n";
    cout << "2. Wzorce strukturalne\n" ;
    cout << "   (wyjasniaja w jaki sposob mozna skladac obiekty i klasy w wieksze struktury zachowujac przy tym \n";
    cout << "     elastycznosc i efektywnosc tych struktur)\n\n";
    cout << "3. Wzorce behawioralne\n" ;
    cout << "   (dotycza algorytmow i rozdzielania odpowiedzialnosci pomiedzy obiektami)\n\n";
    cout << "0. Wyjscie\n" ;
    cin >> i;
    if(0<=i && i <=3)
        j = wybierz_wzorzec(i,arr);
    else
        cout << "Niepoprawny wybor\n";
    arr[0]=i;
    arr[1]=j;

    return i;
}

int wybierz_wzorzec(int i, int arr[2])
{
    int j;
    switch (i)
    {
        case 1:
            cout << "Wybierz wzorzec kreacyjny:\n\n" ;
            cout << "1. Metoda wytworcza\n" ;
            cout << "2. Fabryka abstrakcyjna\n" ;
            cout << "3. Budowniczy\n" ;
            cout << "4. Prototyp\n" ;
            cout << "5. Singleton\n\n" ;
            cout << "0. Wstecz\n" ;
            cin >> j;
            break;
        case 2:
            cout << "Wybierz wzorzec strukturalny:\n\n" ;
            cout << "1. Adapter\n" ;
            cout << "2. Most\n" ;
            cout << "3. Kompozyt\n" ;
            cout << "4. Dekorator\n" ;
            cout << "5. Fasada\n" ;
            cout << "6. Pylek\n" ;
            cout << "7. Pelnomocnik\n\n" ;
            cout << "0. Wstecz\n" ;
            cin >> j;
            break;
        case 3:
            cout << "Wybierz wzorzec behawioralny:\n\n" ;
            cout << "1. Lancuch zobowiazan\n" ;
            cout << "2. Polecenie\n" ;
            cout << "3. Iterator\n" ;
            cout << "4. Mediator\n" ;
            cout << "5. Pamiatka\n" ;
            cout << "6. Obserwator\n" ;
            cout << "7. Stan\n" ;
            cout << "8. Strategia\n" ;
            cout << "9. Metoda szablonowa\n" ;
            cout << "10. Odwiedzajacy\n\n" ;
            cout << "0. Wstecz\n" ;
            cin >> j;
            break;
        default:
            cout << "nieporawny wybor\n";
            break;
    }
    return j;
}
int main()
{
    int arr[2];
    int i=1;
    int j=1;
    while (i>0)
    {
        i=wyswietl_tabele(i,j,arr);
        cout << "i=" << arr[0] << " j=" << arr[1] ;
        wyswietl_wzorzec(arr);
    }


    return 0;
}
