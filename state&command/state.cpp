#include <iostream>
using namespace std;

class State
{
public:
    virtual void book() {};
    virtual void cancel() {};
    virtual void check_in() {};
    virtual void check_out() {};
};

class Booked : public State
{
public:
    void book() override { cout << "Already booked" << endl; }
    void cancel() override { cout << "Cancelling booking" << endl; }
    void check_in() override { cout << "Checking in" << endl; }
    void check_out() override { cout << "Not checked in yet, can't check out" << endl; }
};

class Free : public State
{
public:
    void book() override { cout << "Booking" << endl; }
    void cancel() override { cout << "Not booked, can't cancel" << endl; }
    void check_in() override { cout << "Not booked, can't check in" << endl; }
    void check_out() override { cout << "Not booked, can't check out" << endl; }
};

class CheckedIn : public State
{
public:
    void book() override { cout << "Already checked in, can't book" << endl; }
    void cancel() override { cout << "Already checked in, can't cancel" << endl; }
    void check_in() override { cout << "Already checked in" << endl; }
    void check_out() override { cout << "Checking out" << endl; }
};

class Room
{
    State *state;

public:
    void SetState(State *s)
    {
        state = s;
    }
    void Book()
    {
        state->book();
        SetState(new Booked());
    }
    void Cancel()
    {
        state->cancel();
        SetState(new Free());
    }
    void CheckIn()
    {
        state->check_in();
        SetState(new CheckedIn());
    }
    void CheckOut()
    {
        state->check_out();
        SetState(new Free());
    }
};

int main()
{
    Room room;
    room.SetState(new Free());
    room.Book();
    room.CheckIn();
    room.CheckOut();
    room.Cancel();
    room.SetState(new Booked());
    room.CheckIn();
    room.CheckOut();
    room.Cancel();
    room.SetState(new CheckedIn());
    room.CheckIn();
    room.CheckOut();
}