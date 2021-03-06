/********************************************
* Titre: Travail pratique #4 - utilisateur.cpp
* Date: 19 octobre 2018
* Auteur: Wassim Khene & Ryan Hardie
*******************************************/

#include "utilisateur.h"

// Constructeurs
Utilisateur::Utilisateur() : nom_("") {
}

Utilisateur::Utilisateur(const string& nom, MethodePaiement methodePaiement, const string& courriel, const string& idPaypal) :
	nom_(nom), 
	courriel_(courriel), 
	idPaypal_(idPaypal), 
	methodePaiement_(methodePaiement),
	balanceFrais_(0),
	balanceTransferts_(0)
{}

// Destructeur
Utilisateur::~Utilisateur() {
	for (int i = 0; i < depenses_.size(); i++) {
		delete depenses_[i];
		depenses_[i] = nullptr;
	}
}

// Methodes d'acces
string Utilisateur::getNom() const {
	return nom_;
}

double Utilisateur::getTotalATransferer() const {
	return balanceTransferts_;
}

vector <Depense*> Utilisateur::getDepenses() const {
	return depenses_;
}

double Utilisateur::getBalanceFrais() const {
	return balanceFrais_;
}

string Utilisateur::getCourriel() const {
	return courriel_;
}

string Utilisateur::getIdPaypal() const {
	return idPaypal_;
}

MethodePaiement Utilisateur::getMethodePaiement() const {
	return methodePaiement_;
}

// Methodes de modifications
void Utilisateur::setNom(const string& nom) {
	nom_ = nom;
}

void Utilisateur::setCourriel(const string & courriel) {
	courriel_ = courriel;
}

void Utilisateur::setIdPaypal(const string idPaypal) {
	idPaypal_ = idPaypal;
}

void Utilisateur::setMethodePaiement(MethodePaiement methodePaiement) {
	methodePaiement_ = methodePaiement;
}

void Utilisateur::modifierBalanceFrais(double montant) {
	balanceFrais_ += montant;
}

void Utilisateur::modifierBalanceTransferts(double montant) {
	balanceTransferts_ += montant;
}

Utilisateur& Utilisateur::operator+=(Depense* depense) {
	depenses_.push_back(depense);
	return *this;
}

// Methode print
void Utilisateur::print(ostream& os) const {
	os << "\t\tListe des depenses : " << endl;
	for (size_t i = 0; i < depenses_.size(); i++) {
		os << "\t\t\t" << *depenses_[i];
	}
	os << endl;
}

// Methode d'affichage
ostream& operator<<(ostream& os, const Utilisateur& utilisateur) {
	utilisateur.print(os);
	return os;
}
