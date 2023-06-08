#include "FamilyTreeWidget.h"


FamilyTreeWidget::FamilyTreeWidget(QWidget* parent)
    : QGraphicsView(parent)
{
    setRenderHint(QPainter::Antialiasing);
    setMinimumSize(800, 600);
    setStyleSheet("background-color: white;");

    QGraphicsScene* scene = new QGraphicsScene(this);
    setScene(scene);

    PersonNode* johnNode = new PersonNode("John");
    PersonNode* jw = new PersonNode("jw");

    PersonNode* maryNode = new PersonNode("Mary");
    PersonNode* aliceNode = new PersonNode("Alice");

    PersonNode* bobNode = new PersonNode("Bob");
    PersonNode* claireNode = new PersonNode("Claire");
    PersonNode* zzz = new PersonNode("zzz");
    PersonNode* xxx = new PersonNode("xxx");
    PersonNode* mmm = new PersonNode("mmm");

    PersonNode* s1 = new PersonNode("s1");
    PersonNode* s2 = new PersonNode("s2");

//        scene->addItem(johnNode);
//        scene->addItem(maryNode);
//        scene->addItem(aliceNode);
//        scene->addItem(bobNode);
//        scene->addItem(claireNode);
//        scene->addItem(zzz);
//        scene->addItem(xxx);
//        scene->addItem(mmm);

    johnNode->addChild(maryNode);
    johnNode->addSpouse(jw);
    johnNode->addChild(aliceNode);
    maryNode->addChild(bobNode);
    maryNode->addChild(claireNode);
    aliceNode->addChild(zzz);
    aliceNode->addChild(xxx);
    aliceNode->addChild(mmm);

    johnNode->setGeneration(0);
    jw->setGeneration(0);
    maryNode->setGeneration(1);
    aliceNode->setGeneration(1);
    bobNode->setGeneration(2);
    claireNode->setGeneration(2);
    zzz->setGeneration(2);
    xxx->setGeneration(2);
    mmm->setGeneration(2);

    QList<PersonNode*> family = {johnNode, maryNode, aliceNode, bobNode, claireNode, zzz, xxx, mmm};
    QMap<Generation, QList<PersonNode*>> familyByGen = familyByGenerations(family);
    drawTree(scene, familyByGen);
}

QMap<Generation, QList<PersonNode*>> FamilyTreeWidget::familyByGenerations(QList<PersonNode*>& family)
{
    QMap<Generation, QList<PersonNode*>> familyByGenerations;

    for (auto person : family)
    {
        if (familyByGenerations.contains(person->generation()))
        {
            familyByGenerations.find(person->generation()).value().append(person);
        }
        else
        {
            familyByGenerations.insert(person->generation(), QList<PersonNode*>() << person);
        }
    }

    return familyByGenerations;
}

void FamilyTreeWidget::drawTree(QGraphicsScene* scene, QMap<Generation, QList<PersonNode*>>& family) const
{
    int firstGeneration = 0;
    int lastGeneration = 2;

    qreal posY = 0;
    qreal spacingY = 100;

    qreal startX = 50;
    qreal spacingX = 150;

    for (int i = lastGeneration; i >= firstGeneration; --i)
    {
        for (auto person : qAsConst(family.find(i).value()))
        {
            scene->addItem(person);

            if (i != lastGeneration)
            {
                if (!person->children().empty())
                {
                    qreal tempX = (person->children().constFirst()->x() + person->children().constLast()->x()) / 2;
                    person->setPos(QPointF(tempX, posY));

                    // Draw lines from parent to children
                    for (auto child : person->children())
                    {
                        QLineF line(person->pos(), child->pos());
                        scene->addLine(line);
                    }
                }
                else
                {
                    // here positioning parents with no chilren
                }
            }
            else
            {
                person->setPos(QPointF(startX + spacingX * family.find(i).value().indexOf(person), posY));
            }

            //scene->addItem(person);
        }

        posY += spacingY;
    }
}

