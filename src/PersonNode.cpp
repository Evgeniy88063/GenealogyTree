#include <QBrush>

#include "PersonNode.h"


PersonNode::PersonNode(const QString& name, QGraphicsItem* parent)
    : QObject(), QGraphicsRectItem(parent), m_name(name)
{
    setRect(-50, -15, 100, 30);
    setBrush(QBrush(Qt::black));

    QGraphicsTextItem* textItem = new QGraphicsTextItem(name, this);
    textItem->setDefaultTextColor(Qt::white);
    textItem->setPos(-textItem->boundingRect().width() / 2, -textItem->boundingRect().height() / 2);
}

void PersonNode::addChild(PersonNode* child)
{
    m_children.append(child);
}

QList<PersonNode*> PersonNode::children() const
{
    return m_children;
}

void PersonNode::addSpouse(PersonNode* spouse)
{
    m_spouse = spouse;
}

PersonNode* PersonNode::spouse() const
{
    return m_spouse;
}

void PersonNode::setGeneration(Generation generation)
{
    m_generation = generation;
}

Generation PersonNode::generation() const
{
    return m_generation;
}

void PersonNode::setName(QString name)
{
    m_name = name;
}


QString PersonNode::name() const
{
    return m_name;
}
