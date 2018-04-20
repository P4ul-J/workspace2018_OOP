/**************************************************************************
    Beispiel zu Zeitmessung

    entnommen: Bjarne Stroustrup, "Die C++ Programmiersprache", 4. Auflage, Anhang D.4.4.1


    In Dev-C++ kann man unter Tools -> Compiler Options -> Code Generation / Opimization
    den Grad der Compiler-Optimierung einstellen. Dies wirkt sich direkt 
    auf die Zeitmessung aus. Das Programm muss dann natuerlich zunaechst neu uebersetzt werden.

 **************************************************************************/


#include <ctime>
#include <iostream>
#include <cstdlib>

using namespace std;

const long laenge = 10000000;

int main(){
	cout << "Projekt 18_Zeitmessung" << endl;

	clock_t t_start, t_stop;

	t_start = clock();
	if (t_start ==clock_t(-1)){ //clock_t(-1) bedeutet "clock funktioniert nicht"
		cerr << "Leider keine Zeitmessung möglich" << endl;
	}

	long a = 0;
	for (long i = 0; i < laenge; i++){
		a++;
	}

	t_stop = clock();
	if (t_stop ==clock_t(-1)){
		cerr << "Leider ist das Messintervall zu lang" << endl;
	}

	cout << "Diese Schleife benoetigt " <<
			double(t_stop - t_start) / CLOCKS_PER_SEC <<  " s" << endl;

	//    system ("pause");

	return EXIT_SUCCESS;


}
