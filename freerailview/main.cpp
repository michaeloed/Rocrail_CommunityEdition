#include <qsplashscreen.h>
#include <freerailview/freerailviewapp.h>
#include <freerailview/mainwindow.h>
#ifdef _WIN32
#include <windows.h>
#endif // _WIN32


int main(int argc, char** argv)
{
    FreeRailViewApp app(argc, argv);
    QPixmap logo(":/pictures/freerail-logo-net.xpm");
    QSplashScreen splash(logo);
    MainWindow mainwindow;

    splash.show();
    app.processEvents();
#ifdef _WIN32
    Sleep(5000);
#endif // _WIN32    

    splash.finish(&mainwindow);
    mainwindow.show();    

    return app.exec();
}