#include "VParabola.h"
#include "VPoint.h"

/*
	Constructors
*/

VParabola::VParabola() {
	site = 0;
	isLeaf = false;
	cEvent = 0;
	edge = 0;
	parent = 0;
}

VParabola::VParabola(VPoint * s)
{
	site = s; 
	isLeaf = true;
	cEvent = 0;
	edge = 0;
	parent = 0;
}

VParabola* VParabola::getLeft() {
	return getLeftParent()->getLeftChild();
}


VParabola * VParabola::getRight() {
	return getRightParent()->getRightChild();
}

VParabola * VParabola::getLeftParent() {
	VParabola * par	= this->parent;
	VParabola * pLast = this;
	while(par->left() == pLast) { 
		if(!par->parent) 
			return 0;
		pLast = par; 
		par = par->parent; 
	}
	return par;
}

VParabola * VParabola::getRightParent() {
	VParabola * par	= this->parent;
	VParabola * pLast = this;
	while(par->right() == pLast) { 
		if(!par->parent) 
			return 0;
		pLast = par; 
		par = par->parent; 
	}
	return par;
}

VParabola* VParabola::getLeftChild() {
	VParabola * par = left();
	while(!par->isLeaf) 
		par = par->right();
	return par;
}

VParabola * VParabola::getRightChild() {
	VParabola * par = right();
	while(!par->isLeaf) 
		par = par->left();
	return par;
}
