#ifndef FAMILYTREEWIDGET_H
#define FAMILYTREEWIDGET_H

#include <QGraphicsView>

#include "PersonNode.h"


class FamilyTreeWidget : public QGraphicsView
{
public:
    FamilyTreeWidget(QWidget* parent = nullptr);

private:
    QMap<Generation, QList<PersonNode*>> familyByGenerations(QList<PersonNode*>& family);
    void drawTree(QGraphicsScene* scene, QMap<Generation, QList<PersonNode*>>& family) const;
};

#endif // FAMILYTREEWIDGET_H
