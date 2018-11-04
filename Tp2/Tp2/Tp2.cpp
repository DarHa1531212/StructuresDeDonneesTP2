// Tp2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

template <class T>

class POSTFIX {
private:
	stack<T> Pile;
	vector<T> Tableau;

public:
	bool postfix(vector<T> tableau);// lit l’expression à évaluer, à partir du clavier, dans tableau et valide si l’expression ne contient que les caractères ci - dessus, à savoir les nombres entiers composés de caractères nombres, et les opérateurs ci - dessus.
	bool valider_expression(vector<T> tableau); // teste si l’expression lue contient un nombre valide de parenthèses
	int transformerennombres(vector <T> tableau); // transforme les nombres lus en caractères en valeurs numériques
	void transformerenpostfixe(stack<T> Pile, vector<T> tableau);// transforme l’expression lue en une expression postfixe.
	int evaluer_expression(stack<T> Pile, vector<T> tableau);
	// affiche la valeur de l’expression lue.
	void convertirStringEnVecteur(string expression);
	POSTFIX(string expression);
	~POSTFIX();
};


template <class T>
void POSTFIX<T>::convertirStringEnVecteur(string expression) {
	string elementActuel;
	int longueur = expression.length();
	for (int i = 0; i < longueur; i++) {
		elementActuel = expression.substr(i, 1);
		//std::vector<int> second(4, 100);                       // four ints with value 100
		Tableau.push_back(elementActuel);
	}
}
template<class T>
POSTFIX<T>::POSTFIX(string expression)
{
	cout << expression << endl;
	//convertirStringEnVecteur(expression);
}
template <class T>
bool POSTFIX<T>::postfix(vector<T> tableau) {

}
template <class T>
bool POSTFIX<T>::valider_expression(vector<T> tableau) {

}
template <class T>
int POSTFIX<T>::transformerennombres(vector <T> tableau) {

}
template <class T>
void POSTFIX<T>::transformerenpostfixe(stack<T> Pile, vector<T> tableau) {

}
template <class T>
int POSTFIX<T>::evaluer_expression(stack<T> Pile, vector<T> tableau) {

}
template <class T>
POSTFIX<T>::POSTFIX::~POSTFIX() {

}

int main()
{
	
	POSTFIX <string> monPostfix("ABC*+D+");
	monPostfix.convertirStringEnVecteur("ABC*+D+");
	std::cout << "Hello World!\n";
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Conseils pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
