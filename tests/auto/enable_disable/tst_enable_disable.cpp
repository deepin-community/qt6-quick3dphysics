// Copyright (C) 2023 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

#include <QtQuickTest/quicktest.h>
#include "../shared/util.h"
class test_enable_disable: public QObject
{
    Q_OBJECT
private slots:
    void skiptest() { QSKIP("This test will fail, skipping."); };
};
int main(int argc, char **argv)
{
    QString message = needSkip();
    if (!message.isEmpty()) {
        qWarning() << message;
        test_enable_disable skip;
        return QTest::qExec(&skip, argc, argv);
    }
    QTEST_SET_MAIN_SOURCE_PATH
    return quick_test_main(argc, argv, "test_enable_disable", QUICK_TEST_SOURCE_DIR);
}
#include "tst_enable_disable.moc"