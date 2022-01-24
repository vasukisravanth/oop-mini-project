#include <bits/stdc++.h>
#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
int max_count = 0;
class bike;
class car
{
private:
    vector<vector<string>> vec{{"CAR1", "1000"},
                               {"CAR2", "1500"},
                               {"CAR3", "2000"},
                               {"CAR4", "2500"},
                               {"CAR5", "3000"}};

public:
    void display()
    {
        cout << "Car_NAME Cost" << endl;
        for (int i = 0; i < vec.size(); i++)
        {
            for (auto it = vec[i].begin(); it != vec[i].end(); it++)
                cout << *it << "     ";
            cout << endl;
        }
    }
    void car_del()
    {
        string x = vec[vec.size() - 1][0];
        cout << x << " The price is " << vec[vec.size() - 1][1];
        vec.pop_back();
    }
    int count1()
    {
        return vec.size();
    }
    friend int operator+(car, bike);
};
class bike
{
private:
    vector<vector<string>> v{{"BIKE1", "200"},
                             {"BIKE2", "250"},
                             {"BIKE3", "300"},
                             {"BIKE4", "350"},
                             {"BIKE5", "400"},
                             {"BIKE6", "600"}};

public:
    void display()
    {
        cout << "Bike_NAME Cost" << endl;
        for (int i = 0; i < v.size(); i++)
        {
            for (auto it = v[i].begin(); it != v[i].end(); it++)
                cout << *it << "     ";
            cout << endl;
        }
    }
    void bike_del()
    {
        string x = v[v.size() - 1][0];
        cout << x << " The price is " << v[v.size() - 1][1];
        v.pop_back();
    }
    int count2()
    {
        return v.size();
    }
    friend int operator+(car, bike);
};
class vehicle : private car, private bike
{
private:
    int count = 0;

public:
    int getCount()
    {
        count = count1() + count2();
        return count;
    }
    template <class X>
    void reply(X di)
    {
        cout << "The distace is = " << di << endl;
    }
};
int operator+(car c, bike b)
{
    return (c.count1() + b.count2());
}
int main()
{
    vehicle ve;
    auto dis = 0.000;
    car c;
    bike b;
    int ch;
    int option;
    max_count = ve.getCount();
    string choice;
    cout << "\t\t\t\t\t\t\t\t\tWelcome to Veichle Managment Project\t\t\t\t\n";
    do
    {
        cout << "Please choose from the following" << endl;
        cout << "1.Show Total No of avaliable veichles" << endl;
        cout << "2.Show No of Cars avaliable" << endl;
        cout << "3.Show No of Bikes available" << endl;
        cout << "4.Select the Type of veichle you want to Rent" << endl;
        cout << "5.exit" << endl;
        cout << "Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "The total no of available veichles are = " << (c.count1() + b.count2()) << endl;
            c.display();
            b.display();
            break;
        case 2:
            cout << "The No of cars availabe are :" << c.count1() << endl;
            c.display();
            break;
        case 3:
            cout << "The No of Bikes avaialble are : " << b.count2() << endl;
            b.display();
            break;
        case 4:
            cout << "Enter the Distance you want to travel : " << endl;
            cin >> dis;
            cout << "Select the veichle you want to rent" << endl;
            cout << "1.Car" << endl;
            cout << "2.Bike" << endl;
            cout << "Enter your choice : ";
            cin >> option;
            switch (option)
            {
            case 1:
                cout << "Thank you for choosing our rental agency" << endl;
                cout << "The type of car is ";
                c.car_del();
                ve.reply(dis);
                cout << "\nThe remaining cars are = " << c.count1() << endl;
                c.display();
                break;
            case 2:
                cout << "Thank you for choosing our rental agency" << endl;
                cout << "The type of Bike is ";
                b.bike_del();
                ve.reply(dis);
                cout << "\nThe remaining Bikes are" << b.count2() << endl;
                b.display();
                break;
            default:
                cout << "Invalid choice Please Try again";
                break;
            }
            break;
        case 5:
            cout << "--------------------------------Exiting-------------------------";
            break;
        default:
            cout << "Enter a valid choice from(1 to 5)" << endl;
            break;
        }
        if (ch == 5)
        {
            break;
        }
        cout << "Do you want to continue(Yes/No) :";
        cin >> choice;
    } while (choice == "Yes" || choice == "yes");
    cout << endl;
    int d = c + b;
    cout << "The total number of veichles rented is " << max_count - d;
}
