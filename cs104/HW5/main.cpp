#include "multiwin.h"
#include <QApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  if (argc < 2) {
    cerr << "Please provide the twitter data file" << endl;
    return 1;
  }
  TwitEng twitEng;

  if (!twitEng.parseFeed(argv[1])) {
    cerr << "Could not parse " << argv[1] << endl;
    return 1;
  }

  Multiwin mw(&twitEng);
  mw.setWindowTitle("Twitter");
  mw.show();

  return app.exec();
}