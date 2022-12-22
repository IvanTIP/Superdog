#include <iostream>
#include <vector>

class Dog;

class Talent {
public:
    virtual std::string showTalent () = 0;

    virtual ~Talent() = default;
};

class Dog {
private:
    std::string name = "unknown";
    std::vector<Talent*> talent;
public:
    Dog (std::string inName) {
        name = inName;
    }

    void setTalent (Talent* talent) {
        this->talent.push_back(talent);
    }

    void show () {
        std::cout << "This is " << name << " and it has some talents:" << std::endl;
        for (int i = 0;i < talent.size();i++) {
            std::cout << "I can " << "\"" << talent[i]->showTalent() << "\"" << std::endl;
        }
    }
};

class Swimming : virtual public Talent {
  public:
    virtual std::string showTalent () override {
        return "swim";
    }
};

class Dancing : virtual public Talent {
  public:
    virtual std::string showTalent () override {
        return "dance";
    }
};

class Counting : virtual public Talent {
  public:
    virtual std::string showTalent () override {
        return "count";
    }
};

int main() {
    Talent *swim = new Swimming;
    Talent *dance = new Dancing;
    Talent *count = new Counting;
    Dog* dog = new Dog("Ivan");
    for (int i = 0;i < 3;i++) {
        std::string command;
        std::cout << "Choose command talents to add: \"swimming\", \"dancing\", \"counting\" or enter \"show\"" << std::endl;
        std::cin >> command;
        if (command == "swimming") {
            dog->setTalent(swim);
        } else if (command == "dancing") {
            dog->setTalent(dance);
        } else if (command == "counting") {
            dog->setTalent(count);
        } else {
            break;
        }
    }
    dog->show();
    delete swim;
    delete dance;
    delete count;
    delete dog;

    return 0;
}
