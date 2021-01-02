//
// Created by Bill Bensing on 1/2/21.
//

#ifndef ESP32_CPP_RELAY_H
#define ESP32_CPP_RELAY_H

enum RelayState {
    Opened,
    Closed
};

class Relay {
    private:
        RelayState state;
        void updateState(RelayState state) {
            state = state;
        }
    protected:
        virtual void executeOpen() = 0;
        virtual void executeClose() = 0;
    public:
        Relay() {
            updateState(Closed);
        }

        void Open() {
            updateState(Opened);
            executeOpen();
        }

        void Close() {
            updateState(Closed);
            executeClose();
        }

        bool IsOpen() {
            return state == Opened;
        }

        bool IsClosed() {
            return state == Closed;
        }
};

#endif // ESP32_CPP_RELAY_H
