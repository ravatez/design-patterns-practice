# Command Design Pattern (C++)

## Overview

The **Command Pattern** is a **behavioral design pattern** that turns a request into a standalone object containing all information about the request.

This allows you to:

- Parameterize objects with operations
- Queue or log requests
- Support undo/redo operations
- Decouple the object that invokes the operation from the object that performs it

---

## Real World Example

Think of a **remote controller**.

- The **remote button** triggers an action
- The **device (Light/Fan)** performs the action
- The **command object** sits in between and knows what action to perform

### Button → Command → Device
- Remote Button → LightCommand → Light ON/OFF

---

## Structure of Command Pattern

There are **4 main components**:

### 1. Command Interface

Defines the execution method.

Example:
```cpp
class ICommand {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
};
```
### 2. Receiver

The object that performs the actual work.

Example:
```cpp
class Light {
public:
    void on();
    void off();
};
class Fan {
public:
    void on();
    void off();
};
```
### 3. Concrete Command

Implements the command interface and calls receiver methods.

Example:
```cpp
class LightCommand : public ICommand {
    Light* light;

public:
    LightCommand(Light* l) {
        light = l;
    }

    void execute() override {
        light->on();
    }

    void undo() override {
        light->off();
    }
};
```
### 4. Invoker

The object that triggers commands.

Example:
```
RemoteController

It stores commands and executes them when buttons are pressed.
```
## Implementation in This Project

| Component | Class |
|----------|------|
| Command Interface | `ICommand` |
| Receivers | `Light`, `Fan` |
| Concrete Commands | `LightCommand`, `FanCommand` |
| Invoker | `RemoteController` |
| Client | `main()` |


### Example Output
```
--- Toggling Light Button 0 ---
Light is ON
Light is OFF

--- Toggling Fan Button 1 ---
Fan is ON
Fan is OFF

--- Toggling Unassigned Button 2 ---
No command assigned at button2

```
### Advantages

Decouples sender and receiver

Easy to add new commands

Supports undo/redo

Supports command queues and logging

### Disadvantages

Can increase number of classes

Slightly more complex structure

### When to Use

Use Command Pattern when:
```

You want to parameterize objects with operations

You need undo functionality

You want to queue operations

You want to decouple invoker from receiver
```
### Learning Notes

Invoker should not know how the request is executed.
It only triggers the command.

This improves flexibility and extensibility.