#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include "worker.h"
#include <QThread>
#include "shared_data_container.h"
#include <QSlider>
#include "qcustomplot.h"
#include <QQuickWidget>
#include <QtNetwork>
#include <QtCore/QTextStream>
#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QtQuick/QQuickItem>
#include <QSslSocket>
#include <QNmeaPositionInfoSource>
#include <QQmlContext>
#include <QIODevice>
#include <QTimer>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:


    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setupDemo(int demoIndex);
    void setupQuadraticDemo(QCustomPlot *customPlot);
    void setupSimpleDemo(QCustomPlot *customPlot);
    void setupSincScatterDemo(QCustomPlot *customPlot);
    void setupScatterStyleDemo(QCustomPlot *customPlot);
    void setupLineStyleDemo(QCustomPlot *customPlot);
    void setupScatterPixmapDemo(QCustomPlot *customPlot);
    void setupDateDemo(QCustomPlot *customPlot);
    void setupTextureBrushDemo(QCustomPlot *customPlot);
    void setupMultiAxisDemo(QCustomPlot *customPlot);
    void setupLogarithmicDemo(QCustomPlot *customPlot);
    void setupRealtimeDataDemo(QCustomPlot *customPlot);
    void setupParametricCurveDemo(QCustomPlot *customPlot);
    void setupBarChartDemo(QCustomPlot *customPlot);
    void setupStatisticalDemo(QCustomPlot *customPlot);
    void setupSimpleItemDemo(QCustomPlot *customPlot);
    void setupItemDemo(QCustomPlot *customPlot);
    void setupStyledDemo(QCustomPlot *customPlot);
    void setupAdvancedAxesDemo(QCustomPlot *customPlot);
    void setupColorMapDemo(QCustomPlot *customPlot);
    void setupFinancialDemo(QCustomPlot *customPlot);

    void setupPlayground(QCustomPlot *customPlot);
private:
    Ui::MainWindow *ui;
    QPushButton *getDataButton;
    QPushButton *startWorkerButton;
    QPushButton *stopWorkerButton;
    QPushButton *quitButton;
    QLabel *xDataLabel;
    QLabel *yDataLabel;
    QSlider *ThrottleSlider;




    Worker worker; //Objekt der eigenen Klasse
    QThread thread_for_worker; // QThread-Objekt
    Shared_Data_Container theSharedDataContainer;


    QString demoName;
    QTimer dataTimer;
    QCPItemTracer *itemDemoPhaseTracer;
    int currentDemoIndex;


    QGeoPositionInfoSource *source;
    QTimer* timer;
    QNmeaPositionInfoSource *nmeaLocation;



private slots:

    //void setupGPS();
    //void errorPositioning(QGeoPositionInfoSource::Error er);
    //void positionUpdated(const QGeoPositionInfo &info);


    void getDataFromSharedDataObject();


    void realtimeDataSlot();
    void bracketDataSlot();
    void screenShot();
    void allScreenShots();

    void zahl_eingabe();
    void on_pushButton_dot_released();
    void on_pushButton_clear_released();
    void on_pushButton_exe_released();
    void binary_operation_pressed();





};
#endif // MAINWINDOW_H
