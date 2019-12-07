#ifndef VParabola_h
#define VParabola_h

#include "VPoint.h"
#include "VEdge.h"


class VEvent;

class VParabola {
public:

	/*
		isLeaf	: flag whether the node is Leaf or internal node
		site	: pointer to the focus point of parabola (when it is parabola)
		edge	: pointer to the edge (when it is an edge)
		cEvent	: pointer to the event, when the arch disappears (circle event)
		parent	: pointer to the parent node in tree
	*/

	bool isLeaf;
	VPoint * site;
	VEdge *	edge;
	VEvent * cEvent;
	VParabola * parent;

	VParabola();
	VParabola(VPoint * s);


	void SetLeft (VParabola * p) {left_  = p; p->parent = this;}
	void SetRight(VParabola * p) {right_ = p; p->parent = this;}

	VParabola *	left() { return left_;  }
	VParabola * right() { return right_; }

	/*
		GetLeft			: returns the closest left leave of the tree
		GetRight		: returns the closest right leafe of the tree
		GetLeftParent	: returns the closest parent which is on the left
		GetLeftParent	: returns the closest parent which is on the right
		GetLeftChild	: returns the closest leave which is on the left of current node
		GetRightChild	: returns the closest leave which is on the right of current node
	*/

	VParabola* getLeft();
	VParabola* getRight();
	VParabola* getLeftParent();
	VParabola* getRightParent();
	VParabola* getLeftChild();
	VParabola* getRightChild();

private:

	VParabola * left_;
	VParabola * right_;
};

#endif
