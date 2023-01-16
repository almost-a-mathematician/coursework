#include <iostream>
#include <string>
#include <fstream>
 
int chooseUserOrAdmin();
 
void showGreeting();
 
void showUserText();
 
int completeAdminAction();
 
void showZeroOptionsText();
 
int performDoctorsTimetableAction(int x);
 
int performPricesAction(int x);

int performDoctorsEducation(int x);

int performSpravka(int x);

void writeToFile(const std::string &fileName);

void readFile(const std::string &fileName);
 
 
using namespace std;
 
int main() {
    setlocale(LC_ALL, "Russian");
 
    showGreeting();
 
    while (true) {
        int x = chooseUserOrAdmin();
 
        switch (x) { // свич для админ/юзер
            case 1:
                //user
                showUserText();
                cin >> x;
                cout << "\n";
                break;
            case 2:
                //admin
                x = completeAdminAction();
                break;
 
            case 3:
                exit(3);
 
        } // конец свича для админ/юзер
        switch (x) { // свич для админа и юзера: все возможные действия из первого списка
            case 0:
                do {
                    x = chooseUserOrAdmin();
 
                    switch (x) {
                        case 1:
                            showUserText();
                            cin >> x;
                            cout << "\n";
                            switch (x) {
                                case 0:
                                    break;
 
                                case 1:
                                    cout << "1. Расписание работы врачей\n";
                                    showZeroOptionsText();
                                    cin >> x;
                                    x = performDoctorsTimetableAction(x);
                                    break; // конец свича для файла с рассписанием работы врачей
 
                                    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                case 2:
                                    cout << "Цены на услуги специалистов\n"; // тут файл со списком специалистов
                                    showZeroOptionsText();
                                    cin >> x;
                                    x = performPricesAction(x);
                                    break;// конец свича для файла с ценами на услуги специалистов

                                case 3:
                                    cout << "Образование специалистов центра ментального здоровья INFINITY\n"; // тут файл со списком специалистов
                                    showZeroOptionsText();
                                    cin >> x;
                                    x = performDoctorsEducation(x);
                                    break;// конец свича для файла с образованием специалистов центра ментального здоровья INFINITY
                                
                
                                    break;
 
                            }
                            break;
 
                        case 2:
                            x = completeAdminAction();
                            break;
 
                        case 3:
                            exit(3);
 
                    }
                } while (x == 0);
                break;
 
            case 1:
                cout << "1. Расписание работы врачей\n";
                readFile("/Users/coffin_filling/Desktop/cw/файлы/1.txt");
                showZeroOptionsText();
                cin >> x;
                x = performDoctorsTimetableAction(x);
                break; // конец свича для файла с рассписанием работы врачей
 
                //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
            case 2:
                cout << "Цены на услуги специалистов\n"; // тут файл со списком специалистов
                readFile("/Users/coffin_filling/Desktop/cw/файлы/1.txt");
                showZeroOptionsText();
                cin >> x;
                x = performPricesAction(x);
                break;// конец свича для файла с ценами на услуги специалистов
            
            case 3:
                cout << "Образование специалистов центра ментального здоровья INFINITY\n"; // тут файл со списком специалистов
                readFile("/Users/coffin_filling/Desktop/cw/файлы/12.txt");
                showZeroOptionsText();
                cin >> x;
                x = performPricesAction(x);
                break;

            case 4: 
                cout << "Добавить специалистов и их образование\n";
                writeToFile("/Users/coffin_filling/Desktop/cw/файлы/12.txt");
                showZeroOptionsText();
                cin >> x;
                break;

            case 9:
                cout << "9. Справка\n";
                cout << "\n";
                readFile("/Users/coffin_filling/Desktop/cw/файлы/Spravka.txt");//read
                cout << "\n";
                showZeroOptionsText();
                cin >> x;
                x = performSpravka(x);
                break;
                
                break;

 
        }//коннц свича для админа и юзера: все возможные действия из первого списка
    }
}
 
int completeAdminAction() {
    int tmp;
    cout << endl << " Введите пароль:\n ";
    cin >> tmp;
    cout << "\n";
    if (tmp == 123) {
        cout << "Выберите \n";
        cout << "\n";
        cout << "4. Добавить специалиста и его образование\n";
        showZeroOptionsText();
        cin >> tmp;
        cout << "\n";
    } else {
        cout << "\n";
        cout << "Неверный пароль\n";
        cout << "\n";
        showZeroOptionsText();
        cin >> tmp;
    }
    return tmp;
}
 
void showGreeting() {
    cout << "         Добро пожаловать на сайт центра ментального здоровья INFINITY!\n";
    cout << "                                                                        \n";
    cout << "                                           Адрес: ул. Можжевельника 25-87\n";
    cout << "                                           Контактный телефон: 80(44)592-54-91\n";
    cout << "                                           Почта: infinity.med@gmail.com\n";
    cout << "\n";
    cout << "                               Продолжить как\n";
    cout << "\n";
}
 
int chooseUserOrAdmin() {//шапка
    int x = 0;
    cout << "1. User\n";
    cout << "2. Admin\n";
    cout << "3. Exit\n";
    cout << "9. Справка\n";
    cout << "\n";
    cin >> x;
    cout << "\n";
    return x;
}
 
void showUserText() {
    cout << "Выберите\n";
    cout << "\n";
    cout << "1. Расписание работы врачей\n";
    cout << "2. Цены на услуги специалистов\n";
    cout << "3. Образование специалистов центра ментального здоровья INFINITY\n";
    
    showZeroOptionsText();
}
 
void showZeroOptionsText() {
    cout << "0. В главное меню\n";
    cout << "9. Справка\n";
    cout << "\n";
}
 
int performDoctorsTimetableAction(int x) {
    switch (x) { //свич для файла с расписанием работы врачей
        case 1:
            cout << "психиатры\n";// здесь открывается файл с фамилиями  и расписанием психиатров
            readFile("/Users/coffin_filling/Desktop/cw/файлы/2.txt");//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
            showZeroOptionsText();
            cin >> x;
            break;
 
        case 2:
            cout << "наркологи\n";// здесь открывается файл с фамилиями и расписанием наркологов
            readFile("/Users/coffin_filling/Desktop/cw/файлы/3.txt");
            showZeroOptionsText();
            cin >> x;
            break;
 
        case 3:
            cout << "психотерапевты\n";// здесь открывается файл с фамилиями и расписанием психотерапевтов
            readFile("/Users/coffin_filling/Desktop/cw/файлы/4.txt");
            showZeroOptionsText();
            cin >> x;
            break;
 
        case 4:
            cout << "психологи\n";// здесь открывается файл с фамилиями и расписанием детских психологов
            readFile("/Users/coffin_filling/Desktop/cw/файлы/5.txt");
            showZeroOptionsText();
            cin >> x;
            break;
 
        case 5:
            cout << "массажисты\n";// здесь открывается файл с фамилиями и расписанием массажистов
            readFile("/Users/coffin_filling/Desktop/cw/файлы/6.txt");
            showZeroOptionsText();
            cin >> x;
            break;
    }
    return x;
}
 
int performPricesAction(int x) {
    switch (x) { // свич для файла с ценами на услуги специалистов
        case 1:
            cout << "Психиатры\n";
            readFile("/Users/coffin_filling/Desktop/cw/файлы/7.txt");
            showZeroOptionsText();
            cin >> x;
            break;
 
        case 2:
            cout << "Наркологи\n";
            readFile("/Users/coffin_filling/Desktop/cw/файлы/8.txt");
            showZeroOptionsText();
            cin >> x;
            break;
 
        case 3:
            cout << "Психотерапевты\n";
            readFile("/Users/coffin_filling/Desktop/cw/файлы/9.txt");
            showZeroOptionsText();
            cin >> x;
            break;
 
        case 4:
            cout << "Психологи\n";
            readFile("/Users/coffin_filling/Desktop/cw/файлы/10.txt");
            showZeroOptionsText();
            cin >> x;
            break;
 
        case 5:
            cout << "Массажисты\n";// для проверки админа услуги 
            readFile("/Users/coffin_filling/Desktop/cw/файлы/11.txt");
            showZeroOptionsText();
            cin >> x;
            break;
    
    }
    return x;
}


// выводим файл с образованием
int performDoctorsEducation(int x) {
    readFile("/Users/coffin_filling/Desktop/cw/файлы/12.txt");
    cin >> x;
}

int performSpravka(int x){
    readFile("/Users/coffin_filling/Desktop/cw/файлы/Spravka.txt");
    showZeroOptionsText();
    cin >> x;
}

void readFile(const std::string &fileName) {
string line;
ifstream myfile(fileName);
if (myfile.is_open()) {
    while (getline(myfile, line)) {
        cout << line << '\n';
    }
myfile.close();
    }
}



void writeToFile(const std::string &fileName) {
    ofstream foutput;
    ifstream finput;
    finput.open(fileName);
    foutput.open(fileName, ios::app);

    string str;
    cout << "Введите данные: " << endl;
    cin.ignore(1000, '\n');
    std::getline(std::cin, str);
    if (finput.is_open()) {
        foutput << "\n";
        foutput << str;
    }

    cout << "\nГотово!\n";

    finput.close();
    foutput.close();
}



