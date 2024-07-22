#pragma once

#include <QStackedLayout>
#include <QWidget>

#include "selfdrive/ui/qt/home.h"
#include "selfdrive/ui/qt/offroad/onboarding.h"
#include "selfdrive/ui/qt/offroad/settings.h"

class MainWindow : public QWidget {
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = nullptr) : MainWindow(parent, nullptr, nullptr, nullptr) {}

protected:
  explicit MainWindow(QWidget* parent, HomeWindow* hw = nullptr, SettingsWindow* sw = nullptr, OnboardingWindow* ow = nullptr);
  HomeWindow *homeWindow;
  SettingsWindow *settingsWindow;
  OnboardingWindow *onboardingWindow;
  virtual void closeSettings();

private:
  bool eventFilter(QObject *obj, QEvent *event) override;
  void openSettings(int index = 0, const QString &param = "");

  QStackedLayout *main_layout;
};