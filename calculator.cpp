#include <iostream>
#include <limits>

using namespace std;

// تابع برای گرفتن عدد از کاربر و جلوگیری از خطای ورودی
double getNumber(const string& prompt) {
    double num;
    cout << prompt;
    while (!(cin >> num)) {
        cout << "ورودی نامعتبر است! لطفاً یک عدد وارد کنید: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return num;
}

int main() {
    char op;
    double num1, num2;
    bool running = true;

    cout << "========================================\n";
    cout << "   ماشین حساب ساده C++ (CLI Calculator)   \n";
    cout << "========================================\n";

    while (running) {
        cout << "\nیک عملگر انتخاب کنید (+, -, *, /) یا q برای خروج: ";
        cin >> op;

        if (op == 'q' || op == 'Q') {
            running = false;
            break;
        }

        if (op == '+' || op == '-' || op == '*' || op == '/') {
            num1 = getNumber("عدد اول را وارد کنید: ");
            num2 = getNumber("عدد دوم را وارد کنید: ");

            double result;
            bool valid = true;

            switch (op) {
                case '+':
                    result = num1 + num2;
                    break;
                case '-':
                    result = num1 - num2;
                    break;
                case '*':
                    result = num1 * num2;
                    break;
                case '/':
                    if (num2 == 0) {
                        cout << "خطا: تقسیم بر صفر مجاز نیست!\n";
                        valid = false;
                    } else {
                        result = num1 / num2;
                    }
                    break;
            }

            if (valid) {
                cout << "----------------------------------------\n";
                cout << "نتیجه: " << num1 << " " << op << " " << num2 << " = " << result << "\n";
                cout << "----------------------------------------\n";
            }
        } else {
            cout << "عملگر نامعتبر است!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    cout << "\nاز استفاده شما متشکریم. خدانگهدار!\n";
    return 0;
}
