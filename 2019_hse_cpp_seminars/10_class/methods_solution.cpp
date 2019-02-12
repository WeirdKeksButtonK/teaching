#include <iostream>
#include <string>


class Chat {
public:
    Chat() = default;

    explicit Chat(const std::string& name)
        : name_{name}
    {}

    std::string GetName() const {
        return name_;
    }

    void SetName(const std::string& name) {
        name_ = name;
    }

private:
    std::string name_;
};


int main() {
    Chat a("BPMI186-2 OIMP");
    std::cout << a.GetName() << '\n';
    a.SetName("Bandits");
    std::cout << a.GetName() << '\n';

    return 0;
}
