// Tp2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "pch.h"
#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cctype>
#include "Tp2.h"

using namespace std;

template <class T>

class POSTFIX {
private:
	stack<T> Pile;
	//vector<T>;

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
	//	Tableau.push_back(elementActuel);
	}
}
template<class T>
POSTFIX<T>::POSTFIX(string expression)
{
	convertirStringEnVecteur(expression);
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


void ConvertirInfixEnPostfix(string expression)
{
	//initialiser pile et output à vide
	stack <char> pile;
	string outputPostfix;
	char x;

	//while ce n'est pas la fin de l'expression
	int longeur = expression.size();
	for (int i = 0; i < longeur; i++)
	{
		char a[100];
		strcpy_s(a, expression.c_str());
		
		//prendre le prochain élément infix
		if (a[i] >= '0' && a[i] <= '9')
		{
			//concaténer item à postfix
			outputPostfix += a[i];
		}
		else if (a [i] == '(')
		{
			//empiler item
			pile.push(a[i]);
		}
		else if (a[i] == ')')
		{
			//dépiler sur x
			while (pile.top() != '(')
			{
				outputPostfix += pile.top;
				pile.pop();
				//concaténer pile.top à postfix et dépiler pile.top
			}
		}
		else 
		{
			while (true)//precedence de stack.top >= item
			{
			}
			x = pile.top;
			outputPostfix += x;
			pile.pop();

			//dépiler sur x et concaténer x à postfix
			pile.push(a[i]);
			//empiler item
		}
	}
	while (true) //pile non vide
	{
		//dépiler sur X et concaténer x à postfix
	}
}

void TesterValiditeExpression(string entreeUtilisateur)
{
	bool erreurTrouvee = false;
	int longeurExpression = entreeUtilisateur.length();
	char a[100];
	strcpy_s(a, entreeUtilisateur.c_str());
	char tabValeursAcceptees[] = { '1', '2','3', '4', '5', '6', '7', '8', '9', '0', '+', '-', '*', '/', '%', '(', ')' };
	int nbreValeursAcceptees = sizeof(tabValeursAcceptees);

	for (int i = 0; i < longeurExpression; i++)
	{
		char *ptrTableau = std::find(std::begin(tabValeursAcceptees), std::end(tabValeursAcceptees), a[i]);
		if (ptrTableau == std::end(tabValeursAcceptees)) {
			erreurTrouvee = true;
			cout << "erreur Trouvée";
			return;
		}
	}
	ConvertirInfixEnPostfix(entreeUtilisateur);
}

int main()
{
	TesterValiditeExpression("1*2+3a");

	POSTFIX <string> monPostfix("ABC*+D+");
	string expression = "589*+4+";

	ConvertirInfixEnPostfix("2+5*9+6"); 
	return 0;
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
