#include <iostream>
using namespace std;

class Television
{
public:
    void open()
    {
        cout << "open TV" << endl;
    }

    void close()
    {
        cout << "close TV" << endl;
    }

    void changeChannel()
    {
        cout << "change channel" << endl;
    }
};

class AbstractCommand
{
public:
    virtual void execute() = 0;
};

class TVOpenCommand : public AbstractCommand
{
    Television *tv;

public:
    TVOpenCommand(Television *_tv) : tv(_tv) {}
    void execute()
    {
        tv->open();
    }
};

class TVCloseCommand : public AbstractCommand
{
    Television *tv;

public:
    TVCloseCommand(Television *_tv) : tv(_tv) {}
    void execute()
    {
        tv->close();
    }
};

class TVChangeChannelCommand : public AbstractCommand
{
    Television *tv;

public:
    TVChangeChannelCommand(Television *_tv) : tv(_tv) {}
    void execute()
    {
        tv->changeChannel();
    }
};

class Controller
{
    AbstractCommand *openCommand;
    AbstractCommand *closeCommand;
    AbstractCommand *changeChannelCommand;

public:
    Controller(AbstractCommand *_openCommand, AbstractCommand *_closeCommand, AbstractCommand *_changeChannelCommand) : openCommand(_openCommand), closeCommand(_closeCommand), changeChannelCommand(_changeChannelCommand) {}

    void openTV()
    {
        openCommand->execute();
    }

    void closeTV()
    {
        closeCommand->execute();
    }

    void changeChannel()
    {
        changeChannelCommand->execute();
    }
};

int main()
{

    Television *tv = new Television();
    TVOpenCommand *openCommand = new TVOpenCommand(tv);
    TVCloseCommand *closeCommand = new TVCloseCommand(tv);
    TVChangeChannelCommand *changeChannelCommand = new TVChangeChannelCommand(tv);

    Controller *controller = new Controller(openCommand, closeCommand, changeChannelCommand);

    controller->openTV();
    controller->changeChannel();
    controller->closeTV();

    return 0;
}