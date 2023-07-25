#include<Windows.h>
#include <iostream>
#include <string>

class CLAS1 {
public:
    CLAS1(const std::string& symbol) : укр_буква(symbol) {}

    std::string getsymbol() const {
        return укр_буква;
    }

    void показати_букву() {
        std::cout << укр_буква << std::endl;
    }

private:
    std::string укр_буква;
};

class CLAS2 {
public:
    CLAS2() {};
    CLAS2(int num) : цифра(num) {}

    int getnumber() const {
        return цифра;
    }

    void показати_цифру() {
        std::cout << цифра << std::endl;
    }

private:
    int цифра;
};

class CLAS3 {
public:
    CLAS3(const std::string& symbol) : eng_letter(symbol) {}

    std::string getsymbol() const {
        return eng_letter;
    }

    void показати_букву() {
        std::cout << eng_letter << std::endl;
    }

private:
    std::string eng_letter;
};

class Passport {
private:
    CLAS1 first{"PМ"};
    CLAS2 second[6];
    //CLAS3 number{ "X" };
    std::string iban;
    std::string car_number;

public:
    Passport() {};

    void setNumber(int index, int num) {
        if (index >= 0 && index < 6) {
            second[index] = CLAS2(num);
        }
    }

    void setIBAN(const std::string& iban) {
        this->iban = iban;
    }

    void setCarNumber(const std::string& carNumber) {
        this->car_number = carNumber;
    }

    std::string toString() const {
        std::string result = first.getsymbol();// + number.getsymbol()
        for (int i = 0; i < 6; i++) {
            result += std::to_string(second[i].getnumber());
        }

        return result;
    }

    std::string getIBAN() const {
        return iban;
    }

    std::string getCarNumber() const {
        return car_number;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Passport  passport;
    passport.setNumber(0, 1);
    passport.setNumber(1, 2);
    passport.setNumber(2, 3);
    passport.setNumber(3, 4);
    passport.setNumber(4, 5);
    passport.setNumber(5, 6);

    std::string passportString = passport.toString();
    std::cout << "Український паспорт: " << passportString << std::endl;

    std::string iban = "UA123456789012345678999191919";
    passport.setIBAN(iban);

    std::string accountIBAN = passport.getIBAN();
    std::cout << "IBAN рахунку: " << accountIBAN << std::endl;

    std::string carNumber = "AA1234BB";
    passport.setCarNumber(carNumber);

    std::string carNum = passport.getCarNumber();
    std::cout << "Номерний знак автомобіля: " << carNum << std::endl;

    return 0;
}










