/********************************************
* Titre: Travail pratique #4 - transfert.h
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#ifndef TRANSFERT_H
#define TRANSFERT_H

#include <iostream>
#include <stdio.h>

#include "utilisateur.h"
#include "utilisateurPremium.h"

using namespace std;
					
class Transfert {	
public:
	// Constructeurs
	Transfert();
	Transfert(double montant, Utilisateur* expediteur, Utilisateur* receveur_);

	// M�thodes d'acc�s
	Utilisateur* getExpediteur() const;
	Utilisateur* getReceveur() const;
	double getMontant() const;

	// getFraisTransfert() devient une fonction virtuelle pure pour que Transfert devienne une classe abstraite
	virtual double getFraisTransfert() const = 0;

	// M�thodes de modifications
	void setMontant(double montant);
	void setExpediteur(Utilisateur* expediteur);
	void setReceveur(Utilisateur* receveur);

	void effectuerTransfert();

	// Methode d'affichage
	friend ostream& operator<<(ostream& os, const Transfert& transfert);

protected:
	double montant_;
	Utilisateur* expediteur_;
	Utilisateur* receveur_;
};

#endif
