#pragma once

#include <QQmlApplicationEngine>
#include <QtQml>
#include <QUrl>

typedef struct kountdown {
	Q_GADGET
	Q_PROPERTY(int index MEMBER index);
	Q_PROPERTY(QString name MEMBER name);
	Q_PROPERTY(QString description MEMBER description);
	Q_PROPERTY(QString date MEMBER date);
	
	public:
		int index;
		QString name;
		QString description;
		QString date;
} kountdown;

class ImportExport : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariantList Kountdowns READ kountdownPopulator)

public:
    explicit ImportExport(QObject *parent = nullptr);
	QVariantList Kountdowns;
	QVariantList kountdownPopulator();
	
private:	
	QVector<kountdown> _kountdownArray;
	
	void _fetchKountdowns();
};