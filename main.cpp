#include <QApplication>
#include <QFile>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

#include <QtPlugin>
Q_IMPORT_PLUGIN (QWindowsIntegrationPlugin);

#ifdef HAS_SVG_PLUGIN
Q_IMPORT_PLUGIN (QSvgPlugin);
Q_IMPORT_PLUGIN (QSvgIconPlugin);
#endif

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    // Load an application style
    QFile styleFile( ":/stylesheet.qss" );
    styleFile.open( QFile::ReadOnly );

    // Apply the loaded stylesheet
    QString style( styleFile.readAll() );
    app.setStyleSheet( style );


    QWidget *window = new QWidget;
    window->setObjectName("window");

    QVBoxLayout *layout = new QVBoxLayout;


    QLabel *svglabel = new QLabel("SVG", window);
    QLabel *pnglabel = new QLabel("PNG", window);

    QPushButton *pngIcon = new QPushButton;
    pngIcon->setIcon(QIcon(":/sentiment_satisfied_FILL0_wght400_GRAD0_opsz24.png"));
    QPushButton *svgIcon = new QPushButton;
    svgIcon->setIcon(QIcon(":/sentiment_satisfied_FILL0_wght400_GRAD0_opsz24.svg"));

    QPushButton *svgIconQss = new QPushButton("svg");
    svgIconQss->setObjectName("svg");

    QPushButton *pngIconQss = new QPushButton("png");
    pngIconQss->setObjectName("png");

    layout->addWidget(svglabel);
    layout->addWidget(svgIcon);
    layout->addWidget(svgIconQss);
    layout->addWidget(pnglabel);
    layout->addWidget(pngIcon);
    layout->addWidget(pngIconQss);

    window->setLayout(layout);

    window->show();

    return app.exec();
}
