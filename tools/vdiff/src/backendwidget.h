#pragma once

#include <QWidget>

#include "tests.h"

class QLabel;
class QComboBox;

class ImageView;

class BackendWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BackendWidget(const Backend backend, QWidget *parent = nullptr);

    QString title() const;
    void setTitle(const QString &title);
    QImage image() const;
    void setImage(const QImage &img);
    void setDiffImage(const QImage &img);
    void setDiffVisible(bool flag);
    QImage diffImage() const;
    void setAnimationEnabled(bool flag);
    void setViewSize(const QSize &size);

    void resetImages();

    Backend backend() const { return m_backend; }

    TestState testState() const;
    void setTestState(const TestState state);
    void setTestStateVisible(bool flag);

signals:
    void testStateChanged();

private:
    const Backend m_backend;
    QLabel * const m_lblTitle;
    ImageView * const m_imageView;
    ImageView * const m_diffView;
    QComboBox * const m_cmbBoxState;
};
