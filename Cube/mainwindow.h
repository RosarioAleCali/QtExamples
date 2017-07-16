#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QOpenGLWindow>
#include <QTimer>
#include <QSurfaceFormat>
#include <QOpenGLFunctions>
#include <QtOpenGL>
#include <QGLWidget>
#include <GL/glu.h>

class MainWindow : public QOpenGLWindow
{
    Q_OBJECT
private:
    QOpenGLContext* context;
    QOpenGLFunctions* openGLFunctions;
    float rotation;
    GLuint texID[1];
    float moveX;
    float moveZ;
protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow() {}
    void keyPressEvent(QKeyEvent *event);
public slots:
    void updateAnimation();
};

#endif // MAINWINDOW_H
