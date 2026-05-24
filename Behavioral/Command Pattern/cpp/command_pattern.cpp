#include<iostream>
using namespace std;

//Command Interface
class ICommand {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~ICommand() {}
};

//Receiver
class Light {
public:
    void on() {
        cout << "Light is ON" << endl;
    }
    void off() {
        cout << "Light is OFF" << endl;
    }
};

class Fan {
public:
    void on() {         
        cout << "Fan is ON" << endl;
    }
    void off() {
        cout << "Fan is OFF" << endl;
    }
};

//Concrete Command for Light
class LightCommand : public ICommand {
private: 
Light* light;
public:
    LightCommand(Light* l){
        light = l;
    }
    void execute() override {
        light->on();
    }
    void undo() override {
        light->off();
    }
};

//Concrete Command for Fan
class FanCommand : public ICommand {
private:
Fan* fan;
public:
    FanCommand(Fan* f){
        fan = f;
    }
    void execute() override {
        fan->on();
    }
    void undo() override {
        fan->off();
    }
};  

// Invoker: Remote Controller with static 2D array of 6 buttons (3 rows, 2 cols)
class RemoteController {
private:
    static const int numButtons = 4;
    ICommand* buttons[numButtons];
    bool buttonPressed[numButtons];

public:
    RemoteController() {
        for (int i = 0; i < numButtons; i++) {
            buttons[i] = nullptr;
            buttonPressed[i] = false; //false = off, true = on;
        }
    }

    void setCommand(int idx, ICommand* cmd) {
        if(idx >= 0 && idx < numButtons)
        {
            if(buttons[idx] != nullptr)
                delete buttons[idx];
            buttons[idx] = cmd;
            buttonPressed[idx] = false;
        }
    }

    void pressButton(int idx){
        if(idx >= 0 && idx < numButtons && buttons[idx] != nullptr)
        {
            if(buttonPressed[idx] == false)
            {
                buttons[idx]->execute();
            }
            else
            {
                buttons[idx]->undo();
            }
            buttonPressed[idx] = !buttonPressed[idx];
        }
        else
        {
            cout<<"No command assigned at button" << idx << endl;
        }
    }

    ~RemoteController()
    {
        for(int i=0; i < numButtons; i++)
        {
            if(buttons[i] != NULL)
            {
                delete buttons[i];
            }
        }
    }
};

int main()
{
    Light* livingRoomLight = new Light();
    Fan* ceilingFan = new Fan();

    RemoteController* remote = new RemoteController();

    remote->setCommand(0, new LightCommand(livingRoomLight));
    remote->setCommand(1, new FanCommand(ceilingFan));

    //Simulate button presses (toggle behavior)
    cout << "--- Toggling Light Button 0 ---" << endl;
    remote->pressButton(0); //ON
    remote->pressButton(1); //OFF

    cout << "--- Toggling Fan Button 1 ---" << endl;
    remote->pressButton(1); //ON
    remote->pressButton(1); //OFF

    //Press unassigned button to show default message
    cout << "--- Toggling Unassigned Button 2 ---" << endl;
    remote->pressButton(2); //ON
    remote->pressButton(2); //OFF

    //Clearn up
    delete remote;
    delete livingRoomLight;
    delete ceilingFan;

    return 0;
}
