#ifndef PERSONNODE_H
#define PERSONNODE_H

#include <QGraphicsItem>


typedef int Generation;

class PersonNode : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    PersonNode(const QString& name, QGraphicsItem* parent = nullptr);

    void addChild(PersonNode* child);
    QList<PersonNode*> children() const;

    void addSpouse(PersonNode* spouse);
    PersonNode* spouse() const;

    void setGeneration(Generation generation);
    Generation generation() const;

    void setName(QString name);
    QString name() const;

private:
    QString m_name;
    Generation m_generation;
    PersonNode* m_spouse;
    QList<PersonNode*> m_children;
};


#endif // PERSONNODE_H
