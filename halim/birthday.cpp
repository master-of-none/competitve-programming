/* @JUDGE_ID: 1709779 12541 C++ "Birthday"*/

//
// Created by Shrikrishna Bhat on 05/10/25.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Person {
    string name;
    int day{};
    int month{};
    int year{};
};
bool isOlder(const Person &p1, const Person &p2) {
    if (p1.year != p2.year) return p1.year < p2.year;
    if (p1.month != p2.month) return p1.month < p2.month;
    return p1.day < p2.day;
}
int main() {
    int n;
    cin >> n;
    vector<Person> people(n);

    for (int i=0; i<n;i++) {
        cin >> people[i].name >> people[i].day >> people[i].month >> people[i].year;
    }

    Person oldest = people[0];
    Person youngest = people[0];

    for (int i=1; i<n;i++) {
        if (isOlder(people[i], oldest))
            oldest = people[i];

        if (isOlder(youngest, people[i]))
            youngest = people[i];
    }

    cout << youngest.name << "\n";
    cout << oldest.name << "\n";

    return 0;

}
