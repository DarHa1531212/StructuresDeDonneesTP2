// Tp2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#pragma region include
#include "pch.h"
#include <iostream>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cctype>
#include "Tp2.h"  
#pragma endregion

using namespace std;

#pragma region Classe Postfix
#pragma region PrototypesPostfix
/// <summary>
/// Classe Postfix qui contient toutes les logiques de la modiffication vers le postfix et le calcul de l'équation
/// </summary>
template <class T>

class POSTFIX {
private:
	stack<T> Pile;
	vector<T> Tableau;
public:
	void CalculerPostFix(vector<T> tableau);
	int DeterminerPrecedence(char charactere);
	string ConvertirInfixEnPostfix(string expression);
	void ConvertirStringEnVecteur(string expression);
	POSTFIX(string expression);
};

#pragma endregion

/// <summary>
/// Convertis une string en un vecteur.
/// </summary>
/// <param name="expression">L'expression à convertir.</param>
template <class T>
void POSTFIX<T>::ConvertirStringEnVecteur(string expression) {
	string elementActuel;
	int longueur = expression.length();
	char tabExpression[15];

	for (int i = 0; i < longueur; i++) {
		strcpy_s(tabExpression, expression.c_str());
		char characterActuel = tabExpression[i];
		Tableau.push_back(characterActuel);
	}
}

/// <summary>
/// Initializes a new instance of the <see cref="POSTFIX"/> class.
/// </summary>
/// <param name="expression">L'expression infix entrée par l'utilisateur.</param>
template<class T>
POSTFIX<T>::POSTFIX(string expression)
{
	ConvertirStringEnVecteur(ConvertirInfixEnPostfix(expression));
	CalculerPostFix(Tableau);
}

/// <summary>
/// Calculer l'expression postfix et en donne le résultat
/// </summary>
/// <param name="tableau">TLe tableau de paramêtres.</param>
template <class T>
void POSTFIX<T>::CalculerPostFix(vector<T> tableau) {
	int longueur = tableau.size();

	for (int i = 0; i < longueur; i++) {

		char d = tableau[i];

		if (isdigit(d)) {
			Pile.push(d);
		}
		else {
			int premierPile;
			int deuxiemePile;
			int resultatOperation;
			char topPremier;
			char topDeuxieme;

			topPremier = Pile.top();
			premierPile = topPremier - '0';
			Pile.pop();

			topDeuxieme = Pile.top();
			deuxiemePile = topDeuxieme - '0';
			Pile.pop();

			switch (d) {
			case '*':
				resultatOperation = premierPile * deuxiemePile;
				break;

			case '/':
				resultatOperation = deuxiemePile / premierPile;
				break;

			case '%':
				resultatOperation = deuxiemePile % premierPile;
				break;

			case '+':
				resultatOperation = deuxiemePile + premierPile;
				break;

			case '-':
				resultatOperation = deuxiemePile - premierPile;
				break;

			default:
				cout << "une erreur" << endl;
				break;
			}

			Pile.push(resultatOperation + '0');
		}
	}
	cout << "Résultat:" << Pile.top() - '0' << endl;
}

/// <summary>
/// Détermine la précédence d'opérateurs 
/// </summary>
/// <param name="charactere">l'opérateur à valider.</param>
/// <returns>retourne la précédence de l'opérateur</returns>
template <class T>
int POSTFIX<T>::DeterminerPrecedence(char charactere)
{
	switch (charactere)
	{
	case '(':
		return 4;
	case '/':
		return 2;
	case'*':
		return 2;
	case '+':
		return 1;
	case '-':
		return 1;
	default:
		return 3;
	}
}

/// <summary>
/// Convertis l'expression infix en postfix
/// </summary>
/// <param name="expression">L'expression à convertir.</param>
/// <returns>Retourne l'expression postfix convertie</returns>
template <class T>
string POSTFIX<T>::ConvertirInfixEnPostfix(string expression)
{
	stack <char> pile;
	string outputPostfix;
	char x;
	char a[100];
	strcpy_s(a, expression.c_str());

	int longeur = expression.size();
	for (int i = 0; i < longeur; i++)
	{
		if (a[i] >= '0' && a[i] <= '9')
		{
			outputPostfix += a[i];
		}
		else if (a[i] == '(')
		{
			pile.push(a[i]);
		}
		else if (a[i] == ')')
		{
			while (pile.top() != '(')
			{
				outputPostfix += pile.top();
				pile.pop();
			}
			pile.pop();
		}

		else
		{
			if (pile.empty())
			{
				pile.push(a[i]);
			}
			else
			{
				while (!pile.empty())//precedence de stack.top >= item
				{
					if (DeterminerPrecedence(pile.top()) >= DeterminerPrecedence(a[i]))
					{
						x = pile.top();
						if (x == '(')
						{
							break;
						}
						outputPostfix += x;
						pile.pop();
					}
					else
					{
						break;
					}
				}
				pile.push(a[i]);
			}
		}
	}
	while (!pile.empty())
	{
		x = pile.top();
		outputPostfix += x;
		pile.pop();
	}
	cout << "expression postfixée: " << outputPostfix << endl;
	return outputPostfix;
}
#pragma endregion

/// <summary>
/// Teste la validité de l'expression entrée par l'utilisateur
/// </summary>
/// <param name="entreeUtilisateur">L'entrée utilisateur.</param>
/// <returns>Retourne true si l'expression est valide</returns>
bool TesterValiditeExpression(string entreeUtilisateur)
{
	int nbreParOuvrantes = 0;
	int nbreParFermantes = 0;
	bool erreurTrouvee = false;
	int longeurExpression = entreeUtilisateur.length();
	char a[100];
	strcpy_s(a, entreeUtilisateur.c_str());
	char tabValeursAcceptees[] = { '1', '2','3', '4', '5', '6', '7', '8', '9', '0', '+', '-', '*', '/', '%', '(', ')' };
	int nbreValeursAcceptees = sizeof(tabValeursAcceptees);

	for (int i = 0; i < longeurExpression; i++)
	{
		if (a[i] == '(')
			nbreParOuvrantes++;
		else if (a[i] == ')')
			nbreParFermantes++;

		char *ptrTableau = std::find(std::begin(tabValeursAcceptees), std::end(tabValeursAcceptees), a[i]);
		if (ptrTableau == std::end(tabValeursAcceptees)) {
			erreurTrouvee = true;
			cout << "erreur trouvée dans l'expression" << endl;
			return false;
		}
	}
	if (nbreParFermantes == nbreParOuvrantes) 
	{
		return true;
	}
	
	else
	{
		cout << "Invalidité des parenthèses" << endl;
		return false;
	}
}

/// <summary>
/// Mains this instance.
/// </summary>
/// <returns>retourne 0 dans le cas d'une execution normale du programme</returns>
int main()
{
	locale::global(locale(""));
	string entreeUtilisateur;
	cout << "Entrer l'expression infix:" << endl;        
	cin >> entreeUtilisateur;
	if (TesterValiditeExpression(entreeUtilisateur))
	{		
		POSTFIX <char> monPostfix(entreeUtilisateur);
	}
	system("pause");
	return 0;
}
