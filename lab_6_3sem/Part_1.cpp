#include "Part_1.h"

void output(const vector<Fraction>& many_number) {
    for (auto i : many_number) {
        cout << i << endl;
    }
}

void check() {
    if (cin.fail()) {
        cin.clear();
        cout << "Inncorrect input!!!\n\n";
        exit(1);
    }
}

int check_input_1_num(const vector<Fraction>& many_number) {
    cout << "What?\nInput number first number : ";

    int k;
    cin >> k;
    check();

    if (k - 1 >= many_number.size()) {
        cout << "Number no correct!";
        exit(1);
    }
    return k - 1;
}

int check_input_2_num(const vector<Fraction>& many_number) {
    int m;
    cout << "Input number second number : ";
    cin >> m;
    check();

    if (m - 1 >= many_number.size()) {
        cout << "Number no correct!";
        exit(1);
    }
    return m - 1;
}

void menu_patr_1() {
    int choise = 0;
    vector<Fraction> many_number;

    Fraction number(Numerator(7), Denominator(23));
    many_number.push_back(number);

    number.set(Numerator(3), Denominator(23));
    many_number.push_back(number);

    cout << "Enter your own values (1) or use the program (2)?\n";
    cin >> choise;
    check();

    if (choise == 1) {
        cout << "How many?\n";
        choise = 0;
        cin >> choise;
        check();
        while (choise)
        {
            cin >> number;
            many_number.push_back(number);
            choise--;
        }
    }

    while (true) {
        cout << "\nWhat kind operation would you like?\n"
            << "1) Output (text)\n"
            << "2) Input (values)\n"
            << "3) Add (+)\n"
            << "4) Submition (-)\n"
            << "5) maximize (^)\n"
            << "6) Compare for more (>)\n"
            << "7) Compare by less (<)\n"
            << "8) Compare equal (==)\n"
            << "9) Compare NOT equal (!=)\n"
            << "10) Compare on more or equal (>=)\n"
            << "11) Compare on less or equal (<=)\n"
            << "12) Input log\n"
            << "13) Exit\n";

        choise = 0;
        cin >> choise;

        switch (choise)
        {
        case OUTPUT:
            output(many_number);
            break;
        case INPUT:
            cout << "How many?\n";
            choise = 0;
            cin >> choise;
            check();
            while (choise)
            {
                cin >> number;
                many_number.push_back(number);
                choise--;
            }
            break;
        case ADD:
            output(many_number);

            int k, m;
            k = check_input_1_num(many_number);
            m = check_input_2_num(many_number);

            number = many_number[k] + many_number[m];
            cout << number;
            many_number.push_back(number);
            break;
        case SUB:
            output(many_number);

            k = check_input_1_num(many_number);
            m = check_input_2_num(many_number);

            number = many_number[k] - many_number[m];
            cout << number;
            many_number.push_back(number);
            break;
        case MAXIMAZE:
            output(many_number);

            cout << "What?\nInput number : ";
            k = 0;
            m = 0;
            cin >> k;
            check();

            cout << "Degree : ";
            cin >> m;
            check();

            if (k - 1 >= many_number.size()) {
                cout << "Number no correct!";
                exit(1);
            }
            number = number.pow(many_number[k - 1], m);
            cout << number;
            many_number.push_back(number);
            break;
        case MORE:
            output(many_number);

            k = check_input_1_num(many_number);
            m = check_input_2_num(many_number);

            if (many_number[k] > many_number[m]) {
                cout << many_number[k] << " number more, then " << many_number[m] << endl;
            }
            else cout << many_number[k] << " number less, then " << many_number[m] << endl;

            break;
        case LESS:
            output(many_number);

            k = check_input_1_num(many_number);
            m = check_input_2_num(many_number);

            if (many_number[k] < many_number[m]) {
                cout << many_number[k] << " number more, then " << many_number[m] << endl;
            }
            else cout << many_number[k] << " number less, then " << many_number[m] << endl;
            break;
        case EQUAL:
            output(many_number);

            k = check_input_1_num(many_number);
            m = check_input_2_num(many_number);

            if (many_number[k] > many_number[m]) {
                cout << many_number[k] << " number equal number " << many_number[m] << endl;
            }
            else cout << many_number[k] << " number not equal number " << many_number[m] << endl;

            break;
        case NEQUAL:
            output(many_number);

            k = check_input_1_num(many_number);
            m = check_input_2_num(many_number);

            if (many_number[k] > many_number[m]) {
                cout << many_number[k] << " number equal number " << many_number[m] << endl;
            }
            else cout << many_number[k] << " number not equal number " << many_number[m] << endl;

            break;
        case MEQUAL:
            output(many_number);

            k = check_input_1_num(many_number);
            m = check_input_2_num(many_number);

            if (many_number[k] > many_number[m]) {
                cout << many_number[k] << " number more or equal, then " << many_number[m] << endl;
            }
            else cout << many_number[k] << " number less or equal, then " << many_number[m] << endl;
            break;
        case LEQUAL:
            output(many_number);

            k = check_input_1_num(many_number);
            m = check_input_2_num(many_number);

            if (many_number[k] > many_number[m]) {
                cout << many_number[k] << " number more or equal, then " << many_number[m] << endl;
            }
            else cout << many_number[k] << " number less or equal, then " << many_number[m] << endl;
            break;
        case LOG:

            for (size_t i = 0; i < many_number.size(); i++)
            {
                cout << "Number " << i + 1 << ") " << many_number[i] << "\n" << many_number[i].get_log() << endl;
            }
            break;

        case EXIT:
            cout << "Bay!";
            exit(1);
        default:
            cout << "You enter somthings bad)";
            exit(1);
        }
    }
}