class Boat;
class Car;

void getTotalWeight(Boat a,Car b);

class Boat{
    private:
    int weight;

    public:
    Boat(int a);
    friend void getTotalWeight(Boat a,Car b);

};

class Car{
    private:
    int weight;

    public:
    Car(int a);
    friend void getTotalWeight(Boat a,Car b);

};

