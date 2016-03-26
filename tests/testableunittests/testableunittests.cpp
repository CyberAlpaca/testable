#include <QtCore>
#include <QTest>
#include <QQmlApplicationEngine>
#include "testableunittests.h"
#include "resourcegenerator.h"
#include "automator.h"

TestableUnitTests::TestableUnitTests(QObject *parent) : QObject(parent)
{

}

void TestableUnitTests::resourceGenerator()
{
    ResourceGenerator generator;
    QDir dir;
    generator.setRoot(dir.currentPath());
    generator.scan("/Testable", QString(SRCDIR) + "../testableunittests");
    generator.scan("/Testable2", QString(SRCDIR) + "../testableunittests");

    qDebug() << generator.text();

    QVERIFY(!generator.text().isEmpty());
    QVERIFY(generator.save("resource.qrc"));
}

void TestableUnitTests::automatorSearchWindow()
{

    QQmlApplicationEngine engine;
    engine.load(QUrl::fromLocalFile(QString(SRCDIR) + "/window.qml"));

    Automator automator(&engine);

    QObjectList list = automator.findObjects("Item1");
    QCOMPARE(list.count(), 1);

    list = automator.findObjects("Item2");
    QCOMPARE(list.count(), 1);

}
