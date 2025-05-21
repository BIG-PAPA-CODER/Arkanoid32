#pragma once

/*!
    \file
    \brief Header file that contains Singleton pattern.
    This class allows to use same data in a different parts of code.

*/

class SharedData {
public:
    static SharedData& getInstance() {
        static SharedData instance;
        return instance;
    }

    int x_acc;
    int y_acc;

private:
    SharedData() : x_acc(0), y_acc(0) {}
    SharedData(const SharedData&) = delete;
    SharedData& operator=(const SharedData&) = delete;
};
