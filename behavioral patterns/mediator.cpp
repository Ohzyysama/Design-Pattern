#include <iostream>
#include <string>
#include <vector>
using namespace std;

class AbstractChatroom;

class Member
{
protected:
    AbstractChatroom *chatroom;
    string name;

public:
    Member(string name) : name(name) {}
    string getName()
    {
        return name;
    }

    AbstractChatroom *getChatroom()
    {
        return chatroom;
    }

    void setName(string name)
    {
        this->name = name;
    }

    void setChatroom(AbstractChatroom *chatroom)
    {
        this->chatroom = chatroom;
    }

    virtual void sendText(string to, string message) = 0;
    virtual void sendImage(string to, string image) = 0;
    virtual void receiveText(string from, string message) = 0;
    virtual void receiveImage(string from, string image) = 0;
};

class AbstractChatroom
{
public:
    virtual void registerMember(Member *member) = 0;
    virtual void unregisterMember(Member *member) = 0;
    virtual void sendText(string from, string to, string message) = 0;
    virtual void sendImage(string from, string to, string image) = 0;
};

class Chatroom : public AbstractChatroom
{
    vector<Member *> members;

public:
    void registerMember(Member *member)
    {
        members.push_back(member);
        member->setChatroom(this);
    }

    void unregisterMember(Member *member)
    {
        for (int i = 0; i < members.size(); i++)
        {
            if (members[i] == member)
            {
                members.erase(members.begin() + i);
                break;
            }
        }
    }

    void sendText(string from, string to, string message)
    {
        for (auto member : members)
        {
            if (member->getName() == to)
            {
                member->receiveText(from, message);
                break;
            }
        }
    }

    void sendImage(string from, string to, string image)
    {
        for (auto member : members)
        {
            if (member->getName() == to)
            {
                member->receiveImage(from, image);
                break;
            }
        }
    }
};

class DiamondMember : public Member
{
public:
    DiamondMember(string name) : Member(name) {}

    void sendText(string to, string message)
    {
        cout << getName() << " is sending a text to " << to << ": " << message << endl;
        getChatroom()->sendText(getName(), to, message);
    }

    void sendImage(string to, string image)
    {
        cout << getName() << " is sending an image to " << to << ": " << image << endl;
        getChatroom()->sendImage(getName(), to, image);
    }

    void receiveText(string from, string message)
    {
        cout << getName() << " is receiving a text from " << from << ": " << message << endl;
    }

    void receiveImage(string from, string image)
    {
        cout << getName() << " is receiving an image from " << from << ": " << image << endl;
    }
};

class CommonMember : public Member
{
public:
    CommonMember(string name) : Member(name) {}

    void sendText(string to, string message)
    {
        cout << getName() << " is sending a text to " << to << ": " << message << endl;
        getChatroom()->sendText(getName(), to, message);
    }

    void sendImage(string to, string image)
    {
        cout << getName() << " is sending an image to " << to << ": " << image << endl;
        getChatroom()->sendImage(getName(), to, image);
    }

    void receiveText(string from, string message)
    {
        cout << getName() << " is receiving a text from " << from << ": " << message << endl;
    }

    void receiveImage(string from, string image)
    {
        cout << getName() << " is receiving an image from " << from << ": " << image << endl;
    }
};

int main()
{
    AbstractChatroom *chatroom = new Chatroom();

    Member *commonMember1 = new CommonMember("CommonMember1");
    Member *commonMember2 = new CommonMember("CommonMember2");
    Member *commonMember3 = new CommonMember("CommonMember3");
    Member *diamondMember1 = new DiamondMember("DiamondMember1");
    Member *diamondMember2 = new DiamondMember("DiamondMember2");

    chatroom->registerMember(commonMember1);
    chatroom->registerMember(commonMember2);
    chatroom->registerMember(commonMember3);
    chatroom->registerMember(diamondMember1);
    chatroom->registerMember(diamondMember2);

    commonMember1->sendText("DiamondMember1", "Hi DiamondMember1");
    commonMember1->sendImage("DiamondMember1", "image1.jpg");
    diamondMember1->sendText("CommonMember1", "Hi CommonMember1");
    diamondMember1->sendImage("CommonMember1", "image2.jpg");

    return 0;
}